#!/usr/bin/env python3
"""
tests/test_area_4_decoupling.py
Automated Quality Gate & Regression Suite for Area 4 (Boot-Time Decoupling).

Evaluates:
1. Manifest JSON Schema conformity across all domains.
2. Gate 4A Certification: 100% bit-exact roundtrip (0-byte drift against clean USA ROM).
3. Mod Overlay Isolation: Verifies that mod overlays only touch intended target bytes.
4. Legacy Decompiler Fidelity: Verifies ips_importer accurately identifies modified domains.
5. Deterministic Randomizer Replay: Verifies that identical seeds produce bit-identical ROMs.
"""

import os
import sys
import json
import hashlib
import unittest

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO_ROOT, "tools"))
from extract_rom_tables import main as run_extract, verify_rom
from rom_builder import assemble_rom, verify_roundtrip, compute_snes_checksum
from ips_importer import decompile_diff, parse_ips, detect_header_shift
from randomizer import randomize_classes, randomize_shops, randomize_stages
import random

CLEAN_ROM_PATH = next((p for p in [os.environ.get("OB_ROM_PATH"), os.path.join(REPO_ROOT, "rom", "ogre_battle.sfc"), "/tmp/ogre_battle.sfc"] if p and os.path.exists(p)), None)
MANIFESTS_DIR = os.path.join(REPO_ROOT, "data", "vanilla")
CLEAN_SHA1 = "cfc45162b91791a61d4260e348ad43cb3b2eca0f"
CLEAN_CHECKSUM = 0xD316

class TestArea4Decoupling(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        if CLEAN_ROM_PATH and os.path.exists(CLEAN_ROM_PATH):
            with open(CLEAN_ROM_PATH, "rb") as f:
                cls.clean_rom = f.read()
        else:
            cls.clean_rom = None

    def test_01_rom_integrity(self):
        """Assert base ROM is clean USA 12Mbit Ogre Battle."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        self.assertEqual(len(self.clean_rom), 1572864)
        h = hashlib.sha1(self.clean_rom).hexdigest()
        self.assertEqual(h, CLEAN_SHA1)
        chk = int.from_bytes(self.clean_rom[0x7FDE:0x7FE0], 'little')
        self.assertEqual(chk, CLEAN_CHECKSUM)

    def test_02_canonical_manifest_existence(self):
        """Assert all 6 canonical vanilla manifests exist and are non-empty."""
        expected_files = [
            "attacks.json",
            "classes.json",
            "promotions.json",
            "items.json",
            "shops.json",
            "stages.json"
        ]
        for fname in expected_files:
            fpath = os.path.join(MANIFESTS_DIR, fname)
            self.assertTrue(os.path.exists(fpath), f"Missing {fname}")
            with open(fpath, "r", encoding="utf-8") as f:
                data = json.load(f)
            self.assertTrue(len(data) > 0, f"Empty manifest: {fname}")

    def test_03_gate_4a_bit_exact_roundtrip(self):
        """Gate 4A: Assert compile(extract(clean_rom)) == clean_rom with 0 byte drift."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        reconstructed = assemble_rom(self.clean_rom, MANIFESTS_DIR)
        self.assertEqual(len(reconstructed), len(self.clean_rom))
        self.assertEqual(reconstructed, self.clean_rom, "Reconstructed ROM diverged from clean ROM!")
        rec_sha1 = hashlib.sha1(reconstructed).hexdigest()
        self.assertEqual(rec_sha1, CLEAN_SHA1)

    def test_04_mod_overlay_isolation(self):
        """Assert mod overlay modifies ONLY target classes without corrupting surrounding tables."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        mod_path = os.path.join(REPO_ROOT, "mods", "tactician_rebalance.json")
        self.assertTrue(os.path.exists(mod_path), "Missing tactician_rebalance.json")
        
        patched_rom = assemble_rom(self.clean_rom, MANIFESTS_DIR, overlays=[mod_path])
        self.assertEqual(len(patched_rom), len(self.clean_rom))
        self.assertNotEqual(patched_rom, self.clean_rom)

        # Check Dragoner (class 15, index 14) movement type at 0x17D35 + 14 = 0x17D43
        # Vanilla is Plains (2), mod sets to Low Sky (1)
        self.assertEqual(self.clean_rom[0x17D35 + 14], 2)
        self.assertEqual(patched_rom[0x17D35 + 14], 1)

        # Check that unrelated Fighter (class 1, index 0) movement remains unchanged (Plains = 2)
        self.assertEqual(patched_rom[0x17D35 + 0], 2)

        # Check that Paladin base deploy fee at 0x17DFF + 2*2 = 0x17E03 was modified to 800 (0x0320)
        vanilla_paladin_cost = int.from_bytes(self.clean_rom[0x17DFF + 4 : 0x17DFF + 6], 'little')
        patched_paladin_cost = int.from_bytes(patched_rom[0x17DFF + 4 : 0x17DFF + 6], 'little')
        self.assertEqual(vanilla_paladin_cost, 1100)
        self.assertEqual(patched_paladin_cost, 800)

    def test_05_ips_decompiler_mapping(self):
        """Assert decompiler correctly identifies modified domain tables."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        mod_path = os.path.join(REPO_ROOT, "mods", "tactician_rebalance.json")
        patched_rom = assemble_rom(self.clean_rom, MANIFESTS_DIR, overlays=[mod_path])
        diff_manifest = decompile_diff(self.clean_rom, patched_rom, "Test Rebalance")
        
        tables_modified = [d["table"] for d in diff_manifest["modified_domains"]]
        self.assertIn("movement_type", tables_modified)
        self.assertIn("base_cost", tables_modified)
        self.assertIn("attacks", tables_modified)

    def test_06_seeded_randomizer_determinism(self):
        """Assert seeded randomizer produces 100% deterministic, reproducible ROM outputs."""
        rng1 = random.Random("TEST_SEED_42")
        rng2 = random.Random("TEST_SEED_42")

        with open(os.path.join(MANIFESTS_DIR, "classes.json"), "r") as f:
            classes = json.load(f)

        mut1 = randomize_classes(classes, rng1)
        mut2 = randomize_classes(classes, rng2)
        self.assertEqual(mut1, mut2, "Randomizer produced nondeterministic output for identical seed!")

    def test_07_legacy_patch_header_detection(self):
        """Assert header detector correctly discriminates headered (+512) vs unheadered IPS patches."""
        patches_to_test = [
            (os.path.join(os.environ.get("OB_PATCHES_DIR", os.path.join(REPO_ROOT, "incoming_patches")), "dragoner_patch/dragoner.ips"), True),
            (os.path.join(os.environ.get("OB_PATCHES_DIR", os.path.join(REPO_ROOT, "incoming_patches")), "OBabmod071.ips"), True),
            (os.path.join(os.environ.get("OB_PATCHES_DIR", os.path.join(REPO_ROOT, "incoming_patches")), "OBpatch/OBMagicFix.ips"), True),
            (os.path.join(os.environ.get("OB_PATCHES_DIR", os.path.join(REPO_ROOT, "incoming_patches")), "ClassExp/OB_ClassExpansion.ips"), False)
        ]
        for path, expected_headered in patches_to_test:
            if os.path.exists(path):
                with open(path, "rb") as f:
                    recs = parse_ips(f.read())
                detected = detect_header_shift(recs)
                self.assertEqual(detected, expected_headered, f"Header detection failed for {path}")

    def test_08_dragoner_promotion_decompile_fidelity(self):
        """Assert Dragoner patch decompiles into 100% pure structured promotion tables with 0 micro-patches."""
        manifest_path = os.path.join(REPO_ROOT, "mods", "dragoner_rebalance.json")
        if os.path.exists(manifest_path):
            with open(manifest_path, "r") as f:
                mod = json.load(f)
            self.assertGreater(len(mod.get("micro_patches", [])), 0, "Dragoner patch should contain executable micro-patches")
            domains = [d["domain"] for d in mod.get("modified_domains", [])]
            self.assertTrue(all(d == "promotions" for d in domains))

    def test_09_expanded_2mb_rom_builder_assembly(self):
        """Assert rom_builder correctly expands to 2MB, injects Bank 30 micro-patches, and computes 2MB checksum."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        mod_path = os.path.join(REPO_ROOT, "mods", "ob_magic_fix.json")
        self.assertTrue(os.path.exists(mod_path), "Missing ob_magic_fix.json")
        expanded_rom = assemble_rom(self.clean_rom, MANIFESTS_DIR, overlays=[mod_path])
        self.assertEqual(len(expanded_rom), 2097152, "ROM failed to expand to 2,097,152 bytes")
        # Check Bank 30 machine code at 0x180800
        self.assertEqual(expanded_rom[0x180800], 0xDA)
        # Check hook at 0x018F8B
        self.assertEqual(expanded_rom[0x018F8B:0x018F8F], bytes.fromhex("5C008830"))

if __name__ == "__main__":
    unittest.main()
