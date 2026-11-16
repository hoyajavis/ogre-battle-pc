# Layered Boot Pipeline Certification Report
**Ogre Battle: The March of the Black Queen (SNES LoROM USA)**  
*Area 4: Boot-Time Decoupling — Modular In-Memory ROM Pipeline*

---

## 1. Executive Summary

The **Layered Boot Pipeline with Conflict Resolution and Dynamic Memory Expansion** has been implemented, validated, and certified. 

The pipeline enables community ROM hacks, overhaul presets, and individual engine feature toggles to be dynamically selected and compiled directly into an in-memory ROM buffer prior to 65816 CPU reset, achieving **zero runtime CPU overhead** and maintaining **100% bit-exact vanilla roundtrip preservation** (Gate 4A 0-byte drift guarantee).

---

## 2. Core Architectural Components

### 2.1 Boot Configuration Specification ([`data/schemas/boot_config.schema.json`](../../data/schemas/boot_config.schema.json))
Defines formal schema validation for boot profiles:
- **Base Presets**: `vanilla`, `dragoner`, `fin_071`, `class_expansion`.
- **Engine Feature Toggles**:
  - `magic_ai_elemental_fix`: Patches enemy AI to check player equipped elemental defenses.
  - `prevent_random_crown_drops`: Removes Crown drops from maps and rerolls rare relics.
  - `extensible_size_tables`: Decouples hardcoded bitwise size math to read extensible tables in Bank `$30`.
- **Memory Sizing**: `auto`, `1.5MB`, `2.0MB`.
- **Overlay Manifests**: Ordered array of paths to JSON mod overlays.

### 2.2 Conflict Resolution Engine (`ConflictValidator`)
Strictly enforces compatibility constraints before modifying any memory:
1. **Total Overhaul Exclusivity**: Rejects combining UPRC's `class_expansion` with D's Bank `$30` feature toggles (`magic_ai_elemental_fix`, `prevent_random_crown_drops`, `extensible_size_tables`), as Class Expansion allocates proprietary routines and sprite/palette tables in `$180000..$1FFFFF`.
2. **Memory Contraction Protection**: Rejects forced `1.5MB` memory limits when an active preset (`class_expansion`) or feature toggle requires 2.0MB space.
3. **Table Collision Warning**: Automatically detects overlapping modifications across overlays and orders them with deterministic priority (later overlays take precedence).

### 2.3 Dynamic Memory Allocator (`DynamicMemoryAllocator`)
- Determines buffer size dynamically (`1,572,864` vs. `2,097,152` bytes).
- Automatically updates the SNES internal header ROM size byte at `0x7FD7` to `0x05` (16Mbit) when expanding.
- Computes SNES LoROM hardware checksums dynamically using either the 12Mbit mirrored summation formula (`part1 + part2 * 2`) or the 16Mbit linear sum.

### 2.4 C Pre-Reset Interface ([`include/boot_loader.h`](../../include/boot_loader.h) & [`src/engine/boot_loader.c`](../../src/engine/boot_loader.c))
- Exposes `ob_boot_loader_apply()` accepting an allocated buffer, maximum capacity, preset, and feature flags.
- Supports both direct JSON config file loading (`config.boot_config_path`) and programmatic flag toggles.
- Fully verified via native C integration testing.

---

## 3. Sample Boot Profiles

The following ready-to-run boot profiles are installed in [`data/profiles/`](../../data/profiles/):

| Profile File | Base Preset | Memory | Active Overlays & Engine Toggles | Checksum | SHA1 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| [`vanilla_purist.json`](../../data/profiles/vanilla_purist.json) | `vanilla` | 1.5MB | None (100% clean USA LoROM baseline) | `$D316` | `cfc45162b91791a61d4260e348ad43cb3b2eca0f` |
| [`community_enhancements.json`](../../data/profiles/community_enhancements.json) | `vanilla` | 2.0MB | Dragoner Rebalance + Magic AI Fix + Crown Drop Fix + Size Tables | `$DD11` | `0f3dac9897ef17f9fcd78a2cec10b794e3df45b7` |
| [`fin_balanced_dragoner.json`](../../data/profiles/fin_balanced_dragoner.json) | `fin_071` | 2.0MB | Fin's 0.71 Overhaul + Dragoner Rebalance + Magic AI Fix + Crown Fix | `$B420` | `5115e48644eedb72887c25b9a98c5aacb27bec8d` |
| [`class_expansion_overhaul.json`](../../data/profiles/class_expansion_overhaul.json) | `class_expansion` | 2.0MB | UPRC Class Expansion (14 new classes, Bank $3B palette persistence) | `$0205` | `7091de476e0586341ee564b53a3011a94358a07a` |

---

## 4. Test Verification Suite (15/15 Tests Passing)

Automated testing covers both the core Area 4 decoupling suite and the layered boot pipeline:

```bash
PYTHONPATH=tools python3 -m unittest discover -s tests -p "*.py"
```

```
...............
----------------------------------------------------------------------
Ran 15 tests in 0.329s

OK
```

### Breakdown of Test Cases
1. `test_01_rom_integrity`: Validates clean USA ROM size, SHA1, and $D316 checksum.
2. `test_02_canonical_manifest_existence`: Validates existence and schema conformity of 6 domain manifests.
3. `test_03_gate_4a_bit_exact_roundtrip`: Asserts 0-byte roundtrip drift against base ROM.
4. `test_04_mod_overlay_isolation`: Confirms mod manifests selectively touch intended records.
5. `test_05_ips_decompiler_mapping`: Confirms legacy diff-to-domain mapping.
6. `test_06_seeded_randomizer_determinism`: Asserts PRNG seed reproducibility.
7. `test_07_legacy_patch_header_detection`: Validates 512-byte header auto-detection across all 4 RHDN archives.
8. `test_08_dragoner_promotion_decompile_fidelity`: Confirms Dragoner patch decompiles to structured promotion tables.
9. `test_09_expanded_2mb_rom_builder_assembly`: Confirms 2MB ROM expansion and Bank `$30` code injection.
10. `test_01_vanilla_purist_bit_exact`: Asserts `vanilla_purist.json` produces identical clean ROM.
11. `test_02_dynamic_memory_expansion_community_fixes`: Verifies `community_enhancements.json` 2MB expansion, `$05` header byte, Bank `$30` hooks, and Dragoner promotion values.
12. `test_03_conflict_detection_class_expansion_and_features`: Confirms `ConflictValidator` blocks `class_expansion` combined with conflicting Bank `$30` toggles.
13. `test_04_conflict_detection_memory_constraint`: Confirms `ConflictValidator` blocks 1.5MB constraint on 2MB profiles.
14. `test_05_fin_balancing_dragoner_layering`: Verifies Fin's stats with Dragoner promotions layered on top.
15. `test_06_c_boot_loader_roundtrip`: Verifies native C compilation and execution of `ob_boot_loader_apply()`.
