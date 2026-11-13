#!/usr/bin/env python3
"""
tools/boot_pipeline.py
Layered Boot Pipeline with Conflict Resolution & Dynamic Memory Expansion.

Orchestrates boot-time compilation of modular JSON manifests, community overhaul presets,
and engine machine code feature toggles into an in-memory ROM buffer prior to CPU reset.

Part of Area 4 (Boot-Time Decoupling): Modular JSON builders.
"""

import os
import sys
import json
import hashlib
from typing import Dict, List, Any, Optional, Tuple

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from rom_builder import (
    compute_snes_checksum,
    inject_classes,
    inject_items,
    inject_shops,
    inject_stages,
    inject_promotions,
    inject_micro_patches
)
from randomizer import randomize_classes, randomize_shops, randomize_stages
import random

TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.dirname(TOOLS_DIR)
DEFAULT_MANIFESTS_DIR = os.path.join(REPO_ROOT, "data", "vanilla")
DEFAULT_MODS_DIR = os.path.join(REPO_ROOT, "mods")

CLEAN_SHA1 = "cfc45162b91791a61d4260e348ad43cb3b2eca0f"
CLEAN_CHECKSUM = 0xD316
ROM_SIZE_1_5MB = 1572864
ROM_SIZE_2_0MB = 2097152

PRESET_MANIFEST_MAP = {
    "vanilla": None,
    "dragoner": os.path.join(DEFAULT_MODS_DIR, "dragoner_rebalance.json"),
    "fin_071": os.path.join(DEFAULT_MODS_DIR, "fin_balancing_071.json"),
    "class_expansion": os.path.join(DEFAULT_MODS_DIR, "class_expansion.json")
}

FEATURE_MANIFEST_MAP = {
    "magic_ai_elemental_fix": os.path.join(DEFAULT_MODS_DIR, "ob_magic_fix.json"),
    "prevent_random_crown_drops": os.path.join(DEFAULT_MODS_DIR, "ob_ran_drops.json"),
    "extensible_size_tables": os.path.join(DEFAULT_MODS_DIR, "ob_size_tables.json")
}

class BootConflictError(Exception):
    """Raised when mutually incompatible boot presets or engine features are requested."""
    pass

class BootConfig:
    def __init__(self, data: Dict[str, Any], config_dir: Optional[str] = None):
        if config_dir is None:
            config_dir = REPO_ROOT
        self.profile_name = data.get("profile_name", "Custom Boot Configuration")
        self.description = data.get("description", "")
        self.base_preset = data.get("base_preset", "vanilla").lower()
        self.memory_size = data.get("memory_size", "auto").upper()
        self.recalculate_checksum = data.get("recalculate_checksum", True if "recalculate_checksum" not in data else data["recalculate_checksum"])
        
        # Resolve overlay paths
        raw_overlays = data.get("overlays", [])
        self.overlays = []
        for ov in raw_overlays:
            if not os.path.isabs(ov):
                full_path = os.path.join(config_dir, ov)
                if not os.path.exists(full_path):
                    alt_path = os.path.join(REPO_ROOT, ov)
                    full_path = alt_path if os.path.exists(alt_path) else full_path
                self.overlays.append(full_path)
            else:
                self.overlays.append(ov)

        # Engine feature flags
        features = data.get("engine_features", {})
        self.magic_ai_elemental_fix = bool(features.get("magic_ai_elemental_fix", False))
        self.prevent_random_crown_drops = bool(features.get("prevent_random_crown_drops", False))
        self.extensible_size_tables = bool(features.get("extensible_size_tables", False))

        # Randomizer
        rnd = data.get("randomizer", {})
        self.randomizer_enabled = bool(rnd.get("enabled", False))
        self.randomizer_seed = rnd.get("seed", None)
        self.randomize_classes = bool(rnd.get("randomize_classes", True))
        self.randomize_shops = bool(rnd.get("randomize_shops", True))
        self.randomize_stages = bool(rnd.get("randomize_stages", True))

    @classmethod
    def from_file(cls, path: str) -> "BootConfig":
        if not os.path.exists(path):
            raise FileNotFoundError(f"Boot configuration file not found: {path}")
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
        return cls(data, config_dir=os.path.dirname(path))

class ConflictValidator:
    @staticmethod
    def validate(config: BootConfig) -> List[str]:
        """Validates configuration against conflict matrix. Raises BootConflictError on fatal incompatibility."""
        warnings = []

        if config.base_preset not in PRESET_MANIFEST_MAP:
            raise BootConflictError(
                f"Unknown base preset '{config.base_preset}'. Supported presets: {list(PRESET_MANIFEST_MAP.keys())}"
            )

        # Conflict 1: Class Expansion overhaul vs. D's Bank 30 engine features
        # Class Expansion is a total conversion that occupies Bank $30 ($180000..$1FFFFF) for its own routines.
        if config.base_preset == "class_expansion":
            conflicting_toggles = []
            if config.magic_ai_elemental_fix:
                conflicting_toggles.append("magic_ai_elemental_fix ($180800)")
            if config.prevent_random_crown_drops:
                conflicting_toggles.append("prevent_random_crown_drops ($180100)")
            if config.extensible_size_tables:
                conflicting_toggles.append("extensible_size_tables ($18002C)")
            if conflicting_toggles:
                raise BootConflictError(
                    f"Conflict Detected: 'class_expansion' preset cannot be combined with: {', '.join(conflicting_toggles)}. "
                    "UPRC's Class Expansion is a total conversion that occupies the Bank $30 space ($180000+)."
                )

        # Conflict 2: Memory size contraction constraint
        if config.memory_size == "1.5MB":
            if config.base_preset == "class_expansion":
                raise BootConflictError(
                    "Conflict Detected: 'class_expansion' preset requires 2.0MB memory space, but '1.5MB' was forced."
                )
            if config.magic_ai_elemental_fix or config.prevent_random_crown_drops or config.extensible_size_tables:
                raise BootConflictError(
                    "Conflict Detected: Engine feature toggles inject routines into Bank $30 ($180000+), "
                    "which requires 2.0MB ROM space, but memory_size was forced to '1.5MB'."
                )

        # Check overlay collisions
        overlay_tables = {}
        for ov_path in config.overlays:
            if not os.path.exists(ov_path):
                warnings.append(f"Overlay manifest not found on disk: {ov_path}")
                continue
            try:
                with open(ov_path, "r", encoding="utf-8") as f:
                    ov_data = json.load(f)
                doms = [d["table"] for d in ov_data.get("modified_domains", [])]
                for d in doms:
                    if d in overlay_tables:
                        warnings.append(
                            f"Table collision on '{d}': overlay '{os.path.basename(ov_path)}' will override '{os.path.basename(overlay_tables[d])}'."
                        )
                    overlay_tables[d] = ov_path
            except Exception as e:
                warnings.append(f"Could not inspect overlay {ov_path}: {e}")

        return warnings

class DynamicMemoryAllocator:
    @staticmethod
    def determine_size(config: BootConfig) -> int:
        if config.memory_size == "2.0MB":
            return ROM_SIZE_2_0MB
        if config.memory_size == "1.5MB":
            return ROM_SIZE_1_5MB

        # 'auto' sizing logic:
        # Check if preset requires 2MB
        if config.base_preset == "class_expansion":
            return ROM_SIZE_2_0MB
        # Check if any feature toggle requires Bank 30 (2MB)
        if (config.magic_ai_elemental_fix or 
            config.prevent_random_crown_drops or 
            config.extensible_size_tables):
            return ROM_SIZE_2_0MB
        # Check if any overlay requests 2MB
        for ov in config.overlays:
            if os.path.exists(ov):
                try:
                    with open(ov, "r", encoding="utf-8") as f:
                        data = json.load(f)
                    if data.get("rom_size_bytes", 0) >= ROM_SIZE_2_0MB:
                        return ROM_SIZE_2_0MB
                except Exception:
                    pass
        return ROM_SIZE_1_5MB

    @staticmethod
    def allocate_and_configure(base_rom: bytes, target_size: int) -> bytearray:
        buf = bytearray(base_rom)
        if target_size > len(buf):
            buf.extend(b"\x00" * (target_size - len(buf)))
            # Update SNES header ROM size byte at 0x7FD7 to 16Mbit (0x05)
            buf[0x7FD7] = 0x05
        return buf

class LayeredBootPipeline:
    def __init__(self, manifests_dir: Optional[str] = None):
        self.manifests_dir = manifests_dir if manifests_dir is not None else DEFAULT_MANIFESTS_DIR

    def assemble(self, clean_rom: bytes, config: BootConfig) -> Tuple[bytes, Dict[str, Any]]:
        # Step 1: Conflict Resolution Check
        warnings = ConflictValidator.validate(config)

        # Step 2: Dynamic Memory Allocation
        target_size = DynamicMemoryAllocator.determine_size(config)
        buf = DynamicMemoryAllocator.allocate_and_configure(clean_rom, target_size)

        report = {
            "profile_name": config.profile_name,
            "base_preset": config.base_preset,
            "allocated_size": target_size,
            "warnings": warnings,
            "applied_stages": []
        }

        # Step 3: Base Domain Data Injection (Canonical Vanilla Tables)
        def load_vanilla(name):
            p = os.path.join(self.manifests_dir, name)
            if os.path.exists(p):
                with open(p, "r", encoding="utf-8") as f:
                    return json.load(f)
            return None

        classes = load_vanilla("classes.json")
        if classes:
            inject_classes(buf, classes)
        promos = load_vanilla("promotions.json")
        if promos:
            inject_promotions(buf, promos)
        items = load_vanilla("items.json")
        if items:
            inject_items(buf, items)
        shops = load_vanilla("shops.json")
        if shops:
            inject_shops(buf, shops)
        stages = load_vanilla("stages.json")
        if stages:
            inject_stages(buf, stages)

        report["applied_stages"].append({
            "stage": "base_manifests",
            "source": self.manifests_dir,
            "domains": ["classes", "promotions", "items", "shops", "stages"]
        })

        # Step 4: Apply Base Preset Overlay (if non-vanilla)
        preset_file = PRESET_MANIFEST_MAP.get(config.base_preset)
        if preset_file and os.path.exists(preset_file):
            self._apply_overlay_file(buf, preset_file)
            report["applied_stages"].append({
                "stage": "base_preset_overlay",
                "preset": config.base_preset,
                "file": preset_file
            })

        # Step 5: Apply Layered User Overlays (in declared sequence)
        for ov_path in config.overlays:
            if os.path.exists(ov_path):
                self._apply_overlay_file(buf, ov_path)
                report["applied_stages"].append({
                    "stage": "user_overlay",
                    "file": ov_path
                })

        # Step 6: Apply Engine Feature Toggles
        active_features = []
        if config.magic_ai_elemental_fix:
            self._apply_overlay_file(buf, FEATURE_MANIFEST_MAP["magic_ai_elemental_fix"])
            active_features.append("magic_ai_elemental_fix")
        if config.prevent_random_crown_drops:
            self._apply_overlay_file(buf, FEATURE_MANIFEST_MAP["prevent_random_crown_drops"])
            active_features.append("prevent_random_crown_drops")
        if config.extensible_size_tables:
            self._apply_overlay_file(buf, FEATURE_MANIFEST_MAP["extensible_size_tables"])
            active_features.append("extensible_size_tables")

        if active_features:
            report["applied_stages"].append({
                "stage": "engine_features",
                "active_features": active_features
            })

        # Step 7: Optional Seeded Randomization Pass
        if config.randomizer_enabled and config.randomizer_seed:
            rng = random.Random(config.randomizer_seed)
            if config.randomize_classes and classes:
                mut_classes = randomize_classes(classes, rng)
                inject_classes(buf, mut_classes)
            if config.randomize_shops and shops:
                mut_shops = randomize_shops(shops, rng)
                inject_shops(buf, mut_shops)
            if config.randomize_stages and stages:
                mut_stages = randomize_stages(stages, rng)
                inject_stages(buf, mut_stages)

            report["applied_stages"].append({
                "stage": "seeded_randomizer",
                "seed": config.randomizer_seed
            })

        # Step 8: Recalculate SNES Internal Checksum
        if config.recalculate_checksum:
            chk, inv = compute_snes_checksum(buf)
            buf[0x7FDC:0x7FDE] = inv.to_bytes(2, 'little')
            buf[0x7FDE:0x7FE0] = chk.to_bytes(2, 'little')
            report["snes_checksum"] = f"0x{chk:04X}"
            report["snes_complement"] = f"0x{inv:04X}"

        final_bytes = bytes(buf)
        report["final_sha1"] = hashlib.sha1(final_bytes).hexdigest()
        report["final_size_bytes"] = len(final_bytes)

        return final_bytes, report

    def _apply_overlay_file(self, buf: bytearray, file_path: str):
        with open(file_path, "r", encoding="utf-8") as f:
            mod_data = json.load(f)

        if isinstance(mod_data, dict):
            # Expand buffer if mod targets higher address
            req_size = mod_data.get("rom_size_bytes", len(buf))
            if "micro_patches" in mod_data:
                for mp in mod_data["micro_patches"]:
                    off = int(mp["rom_offset"], 16) if isinstance(mp["rom_offset"], str) else mp["rom_offset"]
                    req_size = max(req_size, off + mp["length"])
            if req_size > len(buf):
                req_size = max(req_size, ROM_SIZE_2_0MB)
                buf.extend(b"\x00" * (req_size - len(buf)))
                buf[0x7FD7] = 0x05

            if "classes" in mod_data:
                inject_classes(buf, mod_data["classes"])
            if "promotions" in mod_data:
                inject_promotions(buf, mod_data["promotions"])
            if "items" in mod_data:
                inject_items(buf, mod_data["items"])
            if "shops" in mod_data:
                inject_shops(buf, mod_data["shops"])
            if "stages" in mod_data:
                inject_stages(buf, mod_data["stages"])
            if "micro_patches" in mod_data:
                inject_micro_patches(buf, mod_data["micro_patches"])
        elif isinstance(mod_data, list):
            inject_classes(buf, mod_data)

def main():
    import argparse
    parser = argparse.ArgumentParser(description="Ogre Battle Layered Boot Pipeline")
    parser.add_argument("--rom", default=None, help="Base clean USA ROM path")
    parser.add_argument("--config", help="Path to boot_config.json")
    parser.add_argument("--preset", choices=["vanilla", "dragoner", "fin_071", "class_expansion"], default="vanilla")
    parser.add_argument("--overlay", action="append", default=[], help="Overlay manifest path (repeatable)")
    parser.add_argument("--enable-magic-fix", action="store_true", help="Enable Magic AI elemental check fix")
    parser.add_argument("--enable-crown-fix", action="store_true", help="Enable crown random drop removal & reroll")
    parser.add_argument("--enable-size-table", action="store_true", help="Enable extensible size table in Bank 30")
    parser.add_argument("--size", choices=["auto", "1.5MB", "2.0MB"], default="auto")
    parser.add_argument("--manifests", default=DEFAULT_MANIFESTS_DIR, help="Vanilla manifest directory")
    parser.add_argument("--out", required=True, help="Output assembled SFC ROM path")
    args = parser.parse_args()

    # Load clean ROM
    rom_path = args.rom
    if not rom_path or not os.path.exists(rom_path):
        candidates = [
            os.environ.get("OB_ROM_PATH"),
            os.path.join(REPO_ROOT, "rom", "ogre_battle.sfc"),
            "/tmp/ogre_battle.sfc"
        ]
        for c in candidates:
            if c and os.path.exists(c):
                rom_path = c
                break

    if not rom_path or not os.path.exists(rom_path):
        print("Error: Clean base ROM not found. Provide --rom or set OB_ROM_PATH.", file=sys.stderr)
        sys.exit(1)

    with open(rom_path, "rb") as f:
        clean_rom = f.read()

    if args.config:
        cfg = BootConfig.from_file(args.config)
    else:
        cfg_dict = {
            "profile_name": f"CLI Custom ({args.preset})",
            "base_preset": args.preset,
            "memory_size": args.size,
            "overlays": args.overlay,
            "engine_features": {
                "magic_ai_elemental_fix": args.enable_magic_fix,
                "prevent_random_crown_drops": args.enable_crown_fix,
                "extensible_size_tables": args.enable_size_table
            }
        }
        cfg = BootConfig(cfg_dict)

    pipeline = LayeredBootPipeline(manifests_dir=args.manifests)
    try:
        final_rom, report = pipeline.assemble(clean_rom, cfg)
        with open(args.out, "wb") as f:
            f.write(final_rom)
        print(f"[BootPipeline] Successfully assembled ROM ({len(final_rom):,} bytes) -> {args.out}")
        print(f"  Profile:   {report['profile_name']}")
        print(f"  Preset:    {report['base_preset']}")
        print(f"  Checksum:  {report.get('snes_checksum', 'N/A')}")
        print(f"  SHA1:      {report['final_sha1']}")
        if report["warnings"]:
            print("  Warnings:")
            for w in report["warnings"]:
                print(f"    - {w}")
    except BootConflictError as e:
        print(f"[BootPipeline] ABORTED due to configuration conflict:\n  {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
