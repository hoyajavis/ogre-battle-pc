#!/usr/bin/env python3
"""
tools/rom_builder.py
Modular In-Memory ROM Buffer Assembler for Ogre Battle: The March of the Black Queen.

Compiles decoupled JSON manifests (classes, promotions, items, shops, stages, mechanics)
into an in-memory 1.5MB ROM buffer.

Supports overlay patch manifests and verifies bit-exact roundtrip against clean ROM.
Part of Area 4 (Boot-Time Decoupling): Modular JSON builders.
"""

import os
import sys
import json
import hashlib
import argparse

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

CLEAN_SHA1 = "cfc45162b91791a61d4260e348ad43cb3b2eca0f"
CLEAN_CHECKSUM = 0xD316
ROM_SIZE = 1572864
NUM_STANDARD_CLASSES = 101
NUM_EQUIPMENT_ITEMS = 100

def compute_snes_checksum(rom_data: bytes) -> tuple:
    buf = bytearray(rom_data)
    buf[0x7FDC:0x7FE0] = b'\xFF\xFF\x00\x00'
    if len(buf) == 1572864:
        part1 = buf[:1048576]
        part2 = buf[1048576:]
        chk = (sum(part1) + sum(part2) * 2) & 0xFFFF
    else:
        chk = sum(buf) & 0xFFFF
    inv = chk ^ 0xFFFF
    return chk, inv

def inject_classes(buf: bytearray, classes: list):
    for c in classes:
        cid = c["id"]
        idx = cid - 1

        # All 125 classes have base stats
        stats = c["stats"]
        buf[0x1EF91 + idx*2 : 0x1EF91 + idx*2 + 2] = stats["base_hp"].to_bytes(2, 'little')
        buf[0x1F0F0 + idx] = stats["base_str"] & 0xFF
        buf[0x1F1D2 + idx] = stats["base_agi"] & 0xFF
        buf[0x1F2B4 + idx] = stats["base_int"] & 0xFF
        buf[0x1F396 + idx] = stats["base_cha"] & 0xFF
        buf[0x1F413 + idx] = stats["base_ali"] & 0xFF
        buf[0x1F490 + idx] = stats["base_luk"] & 0xFF

        # Only standard classes (0..100) have growth, movement, cost, attacks, and resistances
        if idx < NUM_STANDARD_CLASSES:
            buf[0x17D35 + idx] = c["movement"]["type_code"] & 0xFF
            buf[0x17D9A + idx] = c["movement"]["weight"] & 0xFF
            
            base_cost = c["costs"]["base_deploy_goth"]
            buf[0x17DFF + idx*2 : 0x17DFF + idx*2 + 2] = base_cost.to_bytes(2, 'little')

            cost_lvl = c["costs"]["daily_upkeep_per_level"]
            buf[0x17EC9 + idx*2 : 0x17EC9 + idx*2 + 2] = cost_lvl.to_bytes(2, 'little')

            buf[0x17F93 + idx] = 1 if c["costs"]["can_lead_squad"] else 0

            buf[0x1F08B + idx] = stats["hp_growth"] & 0xFF
            buf[0x1F16D + idx] = stats["str_growth"] & 0xFF
            buf[0x1F24F + idx] = stats["agi_growth"] & 0xFF
            buf[0x1F331 + idx] = stats["int_growth"] & 0xFF

            combat = c["combat"]
            f_acts = combat["front_row_actions"] & 0x0F
            b_acts = combat["back_row_actions"] & 0x0F
            buf[0x1F50D + idx] = (f_acts << 4) | b_acts

            buf[0x1F572 + idx] = combat["front_attack"]["id"] & 0xFF
            buf[0x1F5D7 + idx] = combat["back_attack"]["id"] & 0xFF

            res = c["resistances"]
            buf[0x1F6A1 + idx] = res["physical"] & 0xFF
            buf[0x1F706 + idx] = res["fire"] & 0xFF
            buf[0x1F76B + idx] = res["cold"] & 0xFF
            buf[0x1F7D0 + idx] = res["lightning"] & 0xFF
            buf[0x1F835 + idx] = res["black"] & 0xFF
            buf[0x1F89A + idx] = res["white"] & 0xFF

def inject_items(buf: bytearray, items: list):
    for it in items:
        iid = it["id"]
        idx = iid - 1

        val_div_5 = (it["price_goth"] // 5) & 0xFF
        buf[0x3C612 + idx] = val_div_5

        if idx < NUM_EQUIPMENT_ITEMS:
            bonuses = it["bonuses"]
            buf[0x3C7A3 + idx] = bonuses["strength"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3C808 + idx] = bonuses["intelligence"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3C86D + idx] = bonuses["physical_defense"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3C8D2 + idx] = bonuses["fire_defense"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3C937 + idx] = bonuses["ice_defense"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3C99C + idx] = bonuses["lightning_defense"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3CA01 + idx] = bonuses["black_defense"].to_bytes(1, 'little', signed=True)[0]
            buf[0x3CA66 + idx] = bonuses["white_defense"].to_bytes(1, 'little', signed=True)[0]

def inject_shops(buf: bytearray, shops: list):
    pos = 0x3CACA
    for s in shops:
        s_idx = s["stage_id"] - 1
        for item_idx, it in enumerate(s["inventory"]):
            buf[pos + s_idx*5 + item_idx] = it["item_id"] & 0xFF

def inject_stages(buf: bytearray, stages: list):
    goal_pos = 0x2D173
    encounter_pos = 0x2E69F

    for s in stages:
        s_idx = s["stage_id"] - 1
        goal_code = s["goal_code"]
        buf[goal_pos + s_idx*2 : goal_pos + s_idx*2 + 2] = goal_code.to_bytes(2, 'little')

        encs = s.get("neutral_encounters", [])
        for enc in encs:
            slot_idx = enc["slot"] - 1
            enc_offset = encounter_pos + s_idx*9 + slot_idx*3
            buf[enc_offset] = enc["location_code"] & 0xFF
            buf[enc_offset + 1] = enc["unit_level"] & 0xFF
            buf[enc_offset + 2] = enc["unit_class_id"] & 0xFF

def inject_promotions(buf: bytearray, promo_data: dict):
    branch_reqs = promo_data.get("branch_requirements", [])
    for b in branch_reqs:
        idx = b["branch_index"]
        buf[0x4AED4 + idx] = b["min_level"] & 0xFF
        buf[0x4AF21 + idx] = b["min_ali"] & 0xFF
        buf[0x4AF6E + idx] = b["max_ali"] & 0xFF
        buf[0x4AFBB + idx] = b["min_cha"] & 0xFF

    relics = promo_data.get("special_relic_promotions", [])
    for r in relics:
        name = r["relic_name"]
        if name == "Stone of Dragos":
            buf[0x317A6] = r["required_class_id"] & 0xFF
            buf[0x317AD] = r["promoted_class_id"] & 0xFF
        elif name == "Undead Staff":
            buf[0x317B9] = r["required_class_id"] & 0xFF
            buf[0x317C0] = r["promoted_class_id"] & 0xFF
        elif name == "Undead Ring (Primary)":
            buf[0x317CC] = r["required_class_id"] & 0xFF
            buf[0x317D7] = r["promoted_class_id"] & 0xFF
        elif name == "Undead Ring (Secondary)":
            buf[0x317D0] = r["required_class_id"] & 0xFF
            buf[0x317E0] = r["promoted_class_id"] & 0xFF
        elif name == "Blood Kiss":
            buf[0x317EC] = r["required_class_1"] & 0xFF
            buf[0x317F0] = r["required_class_2"] & 0xFF
            buf[0x317F7] = r["promoted_class_id"] & 0xFF
        elif name == "Royal Crown":
            buf[0x31803] = r["required_class_id"] & 0xFF
            buf[0x3180A] = r["promoted_class_id"] & 0xFF
        elif name == "Rotten Pumpkin":
            buf[0x31813] = r["required_class_id"] & 0xFF
            buf[0x3181A] = r["promoted_class_id"] & 0xFF

def inject_micro_patches(buf: bytearray, patches: list):
    for p in patches:
        offset = int(p["rom_offset"], 16) if isinstance(p["rom_offset"], str) else p["rom_offset"]
        patched_bytes = bytes.fromhex(p["patched_bytes"])
        if "vanilla_bytes" in p:
            expected = bytes.fromhex(p["vanilla_bytes"])
            current = bytes(buf[offset:offset+len(expected)])
            if current != expected:
                print(f"Warning: Micro-patch {p.get('id', 'unknown')} expected {expected.hex()} at 0x{offset:X}, got {current.hex()}")
        buf[offset:offset+len(patched_bytes)] = patched_bytes

def assemble_rom(base_rom: bytes, manifests_dir: str, overlays: list = None) -> bytes:
    buf = bytearray(base_rom)

    def load_json(name):
        p = os.path.join(manifests_dir, name)
        if os.path.exists(p):
            with open(p, "r", encoding="utf-8") as f:
                return json.load(f)
        return None

    classes = load_json("classes.json")
    if classes:
        inject_classes(buf, classes)

    promotions = load_json("promotions.json")
    if promotions:
        inject_promotions(buf, promotions)

    items = load_json("items.json")
    if items:
        inject_items(buf, items)

    shops = load_json("shops.json")
    if shops:
        inject_shops(buf, shops)

    stages = load_json("stages.json")
    if stages:
        inject_stages(buf, stages)

    if overlays:
        for ov_path in overlays:
            if not os.path.exists(ov_path):
                print(f"Warning: Overlay file {ov_path} not found")
                continue
            with open(ov_path, "r", encoding="utf-8") as f:
                mod_data = json.load(f)
            
            if isinstance(mod_data, dict):
                target_size = mod_data.get("rom_size_bytes", len(buf))
                if "micro_patches" in mod_data:
                    for mp in mod_data["micro_patches"]:
                        off = int(mp["rom_offset"], 16) if isinstance(mp["rom_offset"], str) else mp["rom_offset"]
                        target_size = max(target_size, off + mp["length"])
                if target_size > len(buf):
                    target_size = max(target_size, 2097152)
                    buf.extend(b"\x00" * (target_size - len(buf)))

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

    chk, inv = compute_snes_checksum(buf)
    buf[0x7FDC:0x7FDE] = inv.to_bytes(2, 'little')
    buf[0x7FDE:0x7FE0] = chk.to_bytes(2, 'little')

    return bytes(buf)

def verify_roundtrip(base_rom_path: str, manifests_dir: str) -> bool:
    print(f"Loading clean base ROM from {base_rom_path}...")
    with open(base_rom_path, "rb") as f:
        clean_rom = f.read()

    print(f"Compiling in-memory ROM buffer from {manifests_dir}...")
    reconstructed = assemble_rom(clean_rom, manifests_dir)

    print("\n--- Gate 4A Verification Results ---")
    print(f"Base ROM length:          {len(clean_rom):,} bytes")
    print(f"Reconstructed length:     {len(reconstructed):,} bytes")

    diff_indices = [i for i in range(len(clean_rom)) if clean_rom[i] != reconstructed[i]]
    diff_count = len(diff_indices)

    base_sha1 = hashlib.sha1(clean_rom).hexdigest()
    rec_sha1 = hashlib.sha1(reconstructed).hexdigest()

    base_chk = int.from_bytes(clean_rom[0x7FDE:0x7FE0], 'little')
    rec_chk = int.from_bytes(reconstructed[0x7FDE:0x7FE0], 'little')

    print(f"Base SHA1:                {base_sha1}")
    print(f"Reconstructed SHA1:       {rec_sha1}")
    print(f"Base Checksum:            0x{base_chk:04X}")
    print(f"Reconstructed Checksum:   0x{rec_chk:04X}")
    print(f"Total Byte Drift:         {diff_count} bytes")

    if diff_count == 0:
        print("\n[PASS] Gate 4A Certified: 100% BIT-EXACT ROUNDTRIP IDENTICAL (0-Byte Drift)!")
        return True
    else:
        print(f"\n[FAIL] Mismatches detected across {diff_count} bytes:")
        for idx in diff_indices[:20]:
            print(f"  Offset 0x{idx:05X}: Base=0x{clean_rom[idx]:02X}, Rec=0x{reconstructed[idx]:02X}")
        if len(diff_indices) > 20:
            print(f"  ... and {len(diff_indices) - 20} more.")
        return False

def main():
    parser = argparse.ArgumentParser(description="Ogre Battle Modular In-Memory ROM Assembler")
    subparsers = parser.add_subparsers(dest="command")

    p_verify = subparsers.add_parser("verify-roundtrip", help="Assert bit-exact identity against clean ROM")
    p_verify.add_argument("--rom", default="/tmp/ogre_battle.sfc", help="Path to clean ROM")
    p_verify.add_argument("--manifests", default=os.path.join(REPO_ROOT, "data", "vanilla"), help="Manifest directory")

    p_build = subparsers.add_parser("build", help="Assemble patched ROM with optional mod overlays or boot config")
    p_build.add_argument("--rom", default="/tmp/ogre_battle.sfc", help="Path to base ROM")
    p_build.add_argument("--manifests", default=os.path.join(REPO_ROOT, "data", "vanilla"), help="Base manifest directory")
    p_build.add_argument("--mod", action="append", default=[], help="Overlay mod manifest file(s)")
    p_build.add_argument("--config", help="Path to boot_config.json profile")
    p_build.add_argument("--preset", choices=["vanilla", "dragoner", "fin_071", "class_expansion"], help="Base game preset")
    p_build.add_argument("--enable-magic-fix", action="store_true", help="Enable enemy AI elemental resistance check fix")
    p_build.add_argument("--enable-crown-fix", action="store_true", help="Prevent Crown map drops and reroll undead items")
    p_build.add_argument("--enable-size-table", action="store_true", help="Enable extensible size table in Bank 30")
    p_build.add_argument("--out", required=True, help="Output patched .sfc path")

    args = parser.parse_args()

    if args.command == "verify-roundtrip":
        success = verify_roundtrip(args.rom, args.manifests)
        sys.exit(0 if success else 1)
    elif args.command == "build":
        rom_path = args.rom if os.path.exists(args.rom) else os.environ.get("OB_ROM_PATH", os.path.join(REPO_ROOT, "rom", "ogre_battle.sfc"))
        with open(rom_path, "rb") as f:
            base_rom = f.read()

        if args.config or args.preset or args.enable_magic_fix or args.enable_crown_fix or args.enable_size_table:
            from boot_pipeline import BootConfig, LayeredBootPipeline, BootConflictError
            if args.config:
                cfg = BootConfig.from_file(args.config)
            else:
                cfg = BootConfig({
                    "profile_name": f"CLI Build ({args.preset or 'vanilla'})",
                    "base_preset": args.preset or "vanilla",
                    "overlays": args.mod,
                    "engine_features": {
                        "magic_ai_elemental_fix": args.enable_magic_fix,
                        "prevent_random_crown_drops": args.enable_crown_fix,
                        "extensible_size_tables": args.enable_size_table
                    }
                })
            pipeline = LayeredBootPipeline(manifests_dir=args.manifests)
            try:
                out_rom, report = pipeline.assemble(base_rom, cfg)
            except BootConflictError as e:
                print(f"[rom_builder] Configuration conflict error:\n  {e}", file=sys.stderr)
                sys.exit(1)
        else:
            out_rom = assemble_rom(base_rom, args.manifests, args.mod)

        with open(args.out, "wb") as f:
            f.write(out_rom)
        print(f"Successfully assembled {args.out} ({len(out_rom):,} bytes)")
        chk = int.from_bytes(out_rom[0x7FDE:0x7FE0], 'little')
        print(f"New Checksum: 0x{chk:04X}, SHA1: {hashlib.sha1(out_rom).hexdigest()}")
    else:
        parser.print_help()

if __name__ == "__main__":
    main()
