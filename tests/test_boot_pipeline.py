#!/usr/bin/env python3
"""
tests/test_boot_pipeline.py
Quality Gate & Regression Suite for Layered Boot Pipeline.

Verifies:
1. Gate 4A 0-Byte Drift preservation for Vanilla Purist preset.
2. Dynamic 2MB memory expansion for community enhancement profiles.
3. Conflict resolution engine enforcement (rejects incompatible overhauls & features).
4. Layered overlay ordering and priority.
5. End-to-end C boot loader pre-reset interface execution.
"""

import os
import sys
import json
import hashlib
import unittest
import subprocess

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO_ROOT, "tools"))
from boot_pipeline import (
    BootConfig,
    LayeredBootPipeline,
    ConflictValidator,
    BootConflictError,
    ROM_SIZE_1_5MB,
    ROM_SIZE_2_0MB,
    CLEAN_SHA1,
    CLEAN_CHECKSUM
)

CLEAN_ROM_PATH = next((p for p in [os.environ.get("OB_ROM_PATH"), os.path.join(REPO_ROOT, "rom", "ogre_battle.sfc"), "/tmp/ogre_battle.sfc"] if p and os.path.exists(p)), None)
PROFILES_DIR = os.path.join(REPO_ROOT, "data", "profiles")
MANIFESTS_DIR = os.path.join(REPO_ROOT, "data", "vanilla")

class TestBootPipeline(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        if CLEAN_ROM_PATH and os.path.exists(CLEAN_ROM_PATH):
            with open(CLEAN_ROM_PATH, "rb") as f:
                cls.clean_rom = f.read()
        else:
            cls.clean_rom = None
        cls.pipeline = LayeredBootPipeline(manifests_dir=MANIFESTS_DIR)

    def test_01_vanilla_purist_bit_exact(self):
        """Assert Vanilla Purist profile produces 100% bit-exact clean USA LoROM (0 byte drift)."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        cfg_path = os.path.join(PROFILES_DIR, "vanilla_purist.json")
        cfg = BootConfig.from_file(cfg_path)
        out_rom, report = self.pipeline.assemble(self.clean_rom or b'', cfg)

        self.assertEqual(len(out_rom), ROM_SIZE_1_5MB)
        self.assertEqual(hashlib.sha1(out_rom).hexdigest(), CLEAN_SHA1)
        chk = int.from_bytes(out_rom[0x7FDE:0x7FE0], 'little')
        self.assertEqual(chk, CLEAN_CHECKSUM)
        self.assertEqual(out_rom, self.clean_rom)

    def test_02_dynamic_memory_expansion_community_fixes(self):
        """Assert Community Enhancements profile expands to 2MB, updates SNES header, and injects Bank 30 code."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        cfg_path = os.path.join(PROFILES_DIR, "community_enhancements.json")
        cfg = BootConfig.from_file(cfg_path)
        out_rom, report = self.pipeline.assemble(self.clean_rom or b'', cfg)

        # Size & header
        self.assertEqual(len(out_rom), ROM_SIZE_2_0MB)
        self.assertEqual(out_rom[0x7FD7], 0x05) # 16Mbit header byte

        # Check Bank 30 code injections
        # 1. MagicFix hook at 0x018F8B and routine at 0x180800
        self.assertEqual(out_rom[0x018F8B:0x018F8F], bytes.fromhex("5C008830"))
        self.assertEqual(out_rom[0x180800], 0xDA)
        
        # 2. CrownDrop hook at 0x02C0D5 and routine at 0x180100
        self.assertEqual(out_rom[0x02C0D5:0x02C0D9], bytes.fromhex("5C1B8130"))
        self.assertEqual(out_rom[0x180100:0x180102], bytes.fromhex("C06A"))

        # 3. Size table at 0x18002C
        self.assertEqual(out_rom[0x01EC67:0x01EC6D], bytes.fromhex("DAAABF0F8030"))

        # 4. Dragoner branch requirements
        # Dragoner (branch 14) min LV 5, min ALI 60, max ALI 100, min CHA 50
        self.assertEqual(out_rom[0x4AED4 + 14], 5)
        self.assertEqual(out_rom[0x4AF21 + 14], 60)
        self.assertEqual(out_rom[0x4AF6E + 14], 100)
        self.assertEqual(out_rom[0x4AFBB + 14], 50)

    def test_03_conflict_detection_class_expansion_and_features(self):
        """Assert ConflictValidator strictly rejects combining Class Expansion with D's Bank 30 engine fixes."""
        bad_cfg_dict = {
            "profile_name": "Illegal Overhaul Combination",
            "base_preset": "class_expansion",
            "engine_features": {
                "magic_ai_elemental_fix": True
            }
        }
        cfg = BootConfig(bad_cfg_dict)
        with self.assertRaises(BootConflictError) as ctx:
            self.pipeline.assemble(self.clean_rom or b'', cfg)
        self.assertIn("class_expansion", str(ctx.exception))
        self.assertIn("magic_ai_elemental_fix", str(ctx.exception))

    def test_04_conflict_detection_memory_constraint(self):
        """Assert ConflictValidator strictly rejects 1.5MB constraint on 2MB profiles."""
        bad_cfg_dict = {
            "profile_name": "Contradictory Memory Sizing",
            "base_preset": "vanilla",
            "memory_size": "1.5MB",
            "engine_features": {
                "extensible_size_tables": True
            }
        }
        cfg = BootConfig(bad_cfg_dict)
        with self.assertRaises(BootConflictError) as ctx:
            self.pipeline.assemble(self.clean_rom or b'', cfg)
        self.assertIn("1.5MB", str(ctx.exception))

    def test_05_fin_balancing_dragoner_layering(self):
        """Assert Fin Balancing mod correctly loads and overlays Dragoner promotion requirements."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        cfg_path = os.path.join(PROFILES_DIR, "fin_balanced_dragoner.json")
        cfg = BootConfig.from_file(cfg_path)
        out_rom, report = self.pipeline.assemble(self.clean_rom or b'', cfg)

        self.assertEqual(len(out_rom), ROM_SIZE_2_0MB)
        # Check Dragoner rebalance applied on top
        self.assertEqual(out_rom[0x4AED4 + 14], 5)
        # Check Fin's class stat adjustments (e.g. movement types at 0x17D35)
        self.assertNotEqual(out_rom[0x17D35:0x17D9A], self.clean_rom[0x17D35:0x17D9A])

    def test_06_c_boot_loader_roundtrip(self):
        """Assert C boot loader interface (src/engine/boot_loader.c) compiles and runs end-to-end."""
        if self.clean_rom is None:
            self.skipTest("Clean USA ROM not supplied (Rule 4)")
        test_c_source = """
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "boot_loader.h"

int main() {
    FILE *f = fopen("%s", "rb");
    if (!f) return 1;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    uint8_t *rom = (uint8_t *)calloc(1, OB_ROM_SIZE_2_0MB);
    fread(rom, 1, size, f);
    fclose(f);

    ob_boot_config_t config;
    memset(&config, 0, sizeof(config));
    config.base_preset = "vanilla";
    config.enable_magic_ai_fix = true;
    config.enable_crown_drop_fix = true;

    size_t out_final_size = 0;
    bool ok = ob_boot_loader_apply(rom, size, OB_ROM_SIZE_2_0MB, &out_final_size, &config);
    if (!ok) return 2;
    if (out_final_size != OB_ROM_SIZE_2_0MB) return 3;

    /* Verify Magic AI hook */
    if (rom[0x018F8B] != 0x5C || rom[0x018F8C] != 0x00 || rom[0x018F8D] != 0x88 || rom[0x018F8E] != 0x30) return 4;

    free(rom);
    printf("C Boot Loader Test Passed!\\n");
    return 0;
}
""" % CLEAN_ROM_PATH

        test_c_path = "/tmp/test_boot_loader.c"
        with open(test_c_path, "w") as f:
            f.write(test_c_source)

        bin_path = "/tmp/test_boot_loader_bin"
        compile_cmd = [
            "gcc", "-Wall", "-Wextra", "-I" + os.path.join(REPO_ROOT, "include"),
            test_c_path, os.path.join(REPO_ROOT, "src", "engine", "boot_loader.c"),
            "-o", bin_path
        ]
        res = subprocess.run(compile_cmd, capture_output=True, text=True)
        self.assertEqual(res.returncode, 0, f"Compilation failed: {res.stderr}")

        env = dict(os.environ, OB_TOOLS_DIR=os.path.join(REPO_ROOT, "tools"))
        run_res = subprocess.run([bin_path], capture_output=True, text=True, env=env)
        self.assertEqual(run_res.returncode, 0, f"C execution failed: {run_res.stderr}")
        self.assertIn("C Boot Loader Test Passed!", run_res.stdout)

if __name__ == "__main__":
    unittest.main()
