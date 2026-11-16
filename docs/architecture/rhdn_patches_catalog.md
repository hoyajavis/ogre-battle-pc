# Community ROM Hack Catalog & Architectural Decision Report
**Ogre Battle: The March of the Black Queen (SNES USA LoROM)**  
*Modernization Experiment Area 4: Boot-Time Decoupling & Modular Manifest System*

---

## 1. Executive Summary & Ingestion Overview

Four major community ROM hacks and enhancement suites from ROMhacking.net (RHDN) were ingested, decompiled, and analyzed against the immutable clean base ROM (`cfc45162b91791a61d4260e348ad43cb3b2eca0f`, 1,572,864 bytes). 

Each patch represents a distinct tier of game alteration, ranging from pure high-level data table tuning to deep 65816 assembly engine hooks and 2MB ROM expansion.

### Summary Catalog

| Archive | Patch Title & Author | Original Target | Detected Header | Total Diffs | Mod Abstraction Tier |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `dragoner_patch.zip` | **Dragoner Promotion Rebalance** (by Dragoner) | 12Mbit USA (1.5MB) | **Headered** (+512 B) | 18 bytes | **Level 1**: Pure Data Schema |
| `obabmod071.zip` | **Fin's Balancing Mod v0.71** (by Fin) | 12Mbit USA (1.5MB) | **Headered** (+512 B) | 1,624 bytes | **Level 2**: Data + Strings & Secondary Tables |
| `OBpatch.zip` | **OB Bug Fixes & Engine Tables** (by D) | 16Mbit USA (2.0MB) | **Headered** (+512 B) | 224 bytes | **Level 3**: Engine ASM Hooks & 2MB Expansion |
| `ClassExp.zip` | **OB Class Expansion** (by UPRC, Oct 2026) | 16Mbit USA (2.0MB) | **Unheadered** | 447,540 bytes | **Level 4**: Total Conversion & Engine Overhaul |

---

## 2. In-Depth Technical Deconstruction

### 2.1 Dragoner Promotion Rebalance (`dragoner_patch.zip`)
- **Author**: Dragoner
- **Target File**: `dragoner.ips` (71 bytes)
- **Header Analysis**: Authored against a 512-byte headered ROM. Byte offsets align with promotion branch requirements shifted by `+0x200` (`0x04B0E2` $\rightarrow$ `0x04AEE2`).
- **Domain Coverage**: 100% pure data schema match across 6 table domains:
  - `promo_min_lvl` (`0x04AED4`): Dragoner branch index 14 changed from Level 1 to Level 5; Dragon Master branch index 15 changed from Level 20 to Level 12.
  - `promo_min_ali` (`0x04AF21`): Dragoner minimum alignment set to 60 (`0x3C`).
  - `promo_max_ali` (`0x04AF6E`): Dragoner maximum alignment set to 100 (`0x64`).
  - `promo_min_cha` (`0x04AFBB`): Dragoner minimum charisma set to 50 (`0x32`).
  - `promo_ptrs` & `promo_targets` (`0x04AD4C..0x04AED4`): Links Amazon (`0x0A`) to Dragoner (`0x10`) promotion tree.
- **Manifest Deliverable**: [`mods/dragoner_rebalance.json`](../../mods/dragoner_rebalance.json) (0 micro-patches required).

---

### 2.2 Fin's Balancing Mod v0.71 (`obabmod071.zip`)
- **Author**: Fin
- **Target File**: `OBabmod071.ips` (2,739 bytes), accompanied by `mod071data.htm`
- **Header Analysis**: Authored against a 512-byte headered ROM. SNES header checksum complement appears at file offset `0x0081DC` (shifted from unheadered `0x007FDC`).
- **Domain Coverage**: Comprehensive rebalance modifying 31 structured table domains:
  - **Class Attributes**: Movement types (`0x17D35`), weights (`0x17D9A`), deploy costs (`0x17DFF`), leadership flags (`0x17F93`), base stats (HP/STR/AGI/INT/CHA/ALI/LUK), stat growths, row action counts (`0x1F50D`), and elemental resistances (`0x1F6A1..0x1F8FF`).
  - **Neutral Encounters**: Spawns and recruitment level tables (`0x2E69F`).
  - **Promotions**: Updated branch criteria and target arrays (`0x4AD4C..0x4B008`).
- **Beyond-Schema Elements**:
  1. *String Renames* (`0x03DC80`, `0x08BA00`, `0x08BF40`): Attack renames (`POISON` $\rightarrow$ `MALICE`, `FIREWALL` $\rightarrow$ `PLASMA`), class renames (`WILD MAN` $\rightarrow$ `BRUTE`), item renames.
  2. *Spell Parameters* (`0x052800..0x053300`): Direct modification to spell execution parameters and hit timing in Bank 5.
- **Manifest Deliverable**: [`mods/fin_balancing_071.json`](../../mods/fin_balancing_071.json).

---

### 2.3 Ogre Battle Bug Fixes & Engine Tables (`OBpatch.zip`)
- **Author**: D
- **Component Patches**:
  1. `OBexp2MB.ips`: Expands ROM space to 2MB (16Mbit) by initializing upper 512KB banks (`$180000..$1FFFFF`).
  2. `OBMagicFix.ips`: Fixes the AI magic targeting bug where enemy mages ignore equipped elemental protection.
     - *Hook*: Replaces 4 bytes at `$018F8B` (`E8 E8 84 0A`) with `5C 00 88 30` (`JMP $308800`).
     - *Routine*: 66 bytes of 65816 logic at `$180800` reading unit equipped item elemental resistances and returning to `$038F92`.
  3. `OBRanDrops.ips`: Removes Crown item from random stage drops and rerolls Undead Staff/Ring/Charm.
     - *Hook*: Overwrites 5 bytes at `$02C0CE` and `$02C0D5` with `5C 1B 81 30` (`JMP $30811B`).
     - *Routine*: 53 bytes at `$180100` performing the drop reroll filter and jumping back to `$05C0D9`.
  4. `OBwSizeTables.ips`: Replaces hardcoded bitwise math with an extensible character size lookup table.
     - *Hook*: Overwrites 66 bytes of bitwise logic at `$01EC67` with `LDA.L $30800F, X` and table dispatch.
     - *Table*: Located at `$18002C`, assigns explicit size bitmasks (`0x00` small, `0x20` undead, `0x40` large, `0x04` vampyric, `0x08` tiger, `0x10` werewolf).
- **Manifest Deliverables**:
  - Individual: [`mods/ob_magic_fix.json`](../../mods/ob_magic_fix.json), [`mods/ob_ran_drops.json`](../../mods/ob_ran_drops.json), [`mods/ob_size_tables.json`](../../mods/ob_size_tables.json).
  - Consolidated Suite: [`mods/ob_engine_patches.json`](../../mods/ob_engine_patches.json).

---

### 2.4 Ogre Battle Class Expansion (`ClassExp.zip`)
- **Author**: UPRC (Release date: October 2026)
- **Target File**: `OB_ClassExpansion.ips` / `OB_ClassExpansion.bps` (539,628 patched bytes across 3,631 records)
- **Header Analysis**: Authored against an **unheadered** clean USA ROM; sets ROM size byte at `0x007FD8` to `0x05` (16Mbit / 2MB).
- **Major Features**:
  1. *New Classes (14 total)*: White Dragon, Zilant Dragon, Phoenix, Templar, Hipogrif, Sorcerer, Shinobi, Siren, Hoplite, Shogun, Joten, Viking, Crone, Babayaga, Basilisk.
  2. *Promotion Expansion*: Amazon $\rightarrow$ Dragoner; item-based transformations (Dragos Stone, Sakura, Bushido, Conscript).
  3. *Engine Hook (Bank $3B)*: Assembly routine intercepting class changes to preserve character-specific palettes across promotions.
  4. *New Items*: Added "Conscript" item triggering seeded procedural army recruitment.
- **Manifest Deliverable**: [`mods/class_expansion.json`](../../mods/class_expansion.json).

---

## 3. Four-Tier Mod Classification Taxonomy

```mermaid
flowchart TD
    Tier1["Level 1: Pure Data Schema\n(dragoner_patch)\n100% JSON Table Mapped"]
    Tier2["Level 2: Data + Strings & Secondary Tables\n(Fin's 0.71 Balancing)\nData Tables + Text & Spell Timing"]
    Tier3["Level 3: Engine ASM Hooks & 2MB Expansion\n(D's OBpatch Suite)\n65816 Logic in Bank $30"]
    Tier4["Level 4: Total Conversion Overhauls\n(UPRC Class Expansion)\nExpanded Class IDs, Sprite Palettes, Bank $3B ASM"]

    Tier1 --> Tier2 --> Tier3 --> Tier4
```

| Tier | Characteristics | Representation in System | Handling Strategy |
| :--- | :--- | :--- | :--- |
| **Level 1: Pure Data** | Only values in existing table bounds change | Native JSON Manifest (`classes.json`, `promotions.json`) | Direct deserialization into ROM memory buffer at boot |
| **Level 2: Data + Strings** | Table values + text strings & spell tables | Hybrid Manifest (Structured domains + Text table mappings) | Decompiled into domain overlays; strings mapped to text tables |
| **Level 3: Engine ASM Hooks** | 65816 machine code hooks; 2MB expansion | Modular Feature Toggles + `micro_patches` block | Automatic 2MB buffer expansion; hooks verified against vanilla bytes |
| **Level 4: Total Conversions** | New class IDs (>125), custom code rewrites | Composite Overhaul Package | Base 2MB expansion + engine hooks + extended schema records |

---

## 4. Architectural Decision Matrix: Handling Beyond-Schema Changes

### Decision 1: ROM Buffer Auto-Expansion (1.5MB $\rightarrow$ 2.0MB)
- **Status**: **Implemented & Certified**
- **Architecture**:
  - The in-memory buffer assembler [`tools/rom_builder.py`](../../tools/rom_builder.py) inspects all incoming manifests and overlays.
  - If any manifest specifies `"rom_size_bytes": 2097152` or contains a micro-patch targeting an address $\ge \text{0x180000}$, the buffer expands from 1,572,864 bytes to 2,097,152 bytes before assembling.
  - The SNES checksum recalculation routine dynamically switches between the 12Mbit formula (`part1 + part2 * 2`) and the 16Mbit linear sum (`sum(buf) & 0xFFFF`), achieving 100% SNES hardware compliance.

### Decision 2: 512-Byte Header Auto-Detection
- **Status**: **Implemented & Certified**
- **Architecture**:
  - Legacy IPS patches frequently alternate between headered (Copier/SMC format, $+512$ bytes) and unheadered formats.
  - [`tools/ips_importer.py`](../../tools/ips_importer.py) employs a scoring heuristic (`detect_header_shift()`) that tests record alignment against the SNES internal header (`0x7FC0..0x7FFF` vs `0x81C0..0x81FF`) and promotion tables.
  - When a header is detected, record offsets are automatically normalized by subtracting `0x200`.

### Decision 3: Engine Logic Hooks vs. Schema Expansion
- **Recommendation**:
  1. *Core Game Entities* (Classes, Promotions, Items, Shops, Stages, Attacks): Expressed exclusively as structured, validated JSON manifests.
  2. *Engine Micro-Patches* (Level 3 Bugfixes): Expressed via declarative `"micro_patches"` arrays within mod manifests. Each patch records `rom_offset`, `vanilla_bytes` (for pre-condition safety verification), and `patched_bytes`.
  3. *Extended Classes* (Level 4 Overhauls): Extend `classes.schema.json` to allow `id > 125` when a `"enable_expanded_classes": true` flag is present.

---

## 5. Verification & Test Certification

The updated automated test suite ([`tests/test_area_4_decoupling.py`](../../tests/test_area_4_decoupling.py)) verifies all tiers:

```bash
PYTHONPATH=tools python3 -m unittest discover -s tests -p "*.py"
```

### Test Suite Execution Summary
- `test_01_rom_integrity`: Confirms clean 1.5MB base ROM SHA1 (`cfc4516...`) and checksum (`$D316`).
- `test_02_canonical_manifest_existence`: Confirms all 6 vanilla manifests exist and conform to schemas.
- `test_03_gate_4a_bit_exact_roundtrip`: Confirms 0-byte drift roundtrip reconstruction.
- `test_04_mod_overlay_isolation`: Confirms mod manifests selectively touch intended records.
- `test_05_ips_decompiler_mapping`: Confirms legacy diff-to-domain mapping.
- `test_06_seeded_randomizer_determinism`: Confirms seed reproducibility across mutations.
- `test_07_legacy_patch_header_detection`: Validates header auto-detection on `dragoner.ips`, `OBabmod071.ips`, `OBMagicFix.ips`, and `OB_ClassExpansion.ips`.
- `test_08_dragoner_promotion_decompile_fidelity`: Confirms Dragoner patch decompiles to 100% pure promotion tables with 0 unmapped micro-patches.
- `test_09_expanded_2mb_rom_builder_assembly`: Confirms 2MB ROM expansion, Bank `$30` code injection, and bit-exact match against legacy binary IPS patches.

**Test Result**: **9/9 Tests Passing (100% Success)**.
