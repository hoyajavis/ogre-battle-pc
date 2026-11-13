#!/usr/bin/env python3
"""
tools/extract_rom_tables.py
Extracts data tables from clean Ogre Battle: The March of the Black Queen (USA) ROM
and outputs canonical, human-readable JSON manifests into data/vanilla/.

Part of Area 4 (Boot-Time Decoupling): Modular JSON builders.
"""

import os
import sys
import json
import hashlib

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

CLEAN_SHA1 = "cfc45162b91791a61d4260e348ad43cb3b2eca0f"
CLEAN_CHECKSUM = 0xD316
NUM_CLASSES = 125
NUM_STANDARD_CLASSES = 101
NUM_ITEMS = 196
NUM_EQUIPMENT_ITEMS = 100
NUM_STAGES = 30

STAGE_NAMES = [
    "Castle of Warren",
    "Borders of Sharom",
    "Sharom District",
    "Pogrom Forest",
    "Lake Jansenia",
    "Deneb's Garden",
    "Slums of Zenobia",
    "Island Avalon",
    "Kastolatian Sea",
    "Diaspola",
    "Kalbian Peninsula",
    "Valley of Kastro",
    "Balmorian Ruins",
    "City of Malano",
    "The Tundra",
    "Antalia",
    "Shangrila",
    "Fort Allamoot",
    "Dalmuhd Desert",
    "Ryhan Sea",
    "Fort Shulamana",
    "Shrine of Kulyn",
    "Xanadu",
    "Zeteginea",
    "Temple Shalina",
    "Muspelm",
    "Organa",
    "Shiguld",
    "Antanyl",
    "Dragon's Haven"
]

MOVE_TYPES = [
    "High Sky",    # 00
    "Low Sky",     # 01
    "Plains",      # 02
    "Forest",      # 03
    "Mountain",    # 04
    "Snow",        # 05
    "Marsh",       # 06
    "Shallows",    # 07
    "Water",       # 08
    "Slow"         # 09
]

def verify_rom(rom_data: bytes) -> bool:
    if len(rom_data) != 1572864:
        print(f"Error: ROM size is {len(rom_data)}, expected 1,572,864 bytes.")
        return False
    h = hashlib.sha1(rom_data).hexdigest()
    if h != CLEAN_SHA1:
        print(f"Warning: ROM SHA1 is {h}, expected {CLEAN_SHA1}")
    return True

def extract_attacks(rom: bytes) -> list:
    attacks = []
    pos = 0x8BF4A
    end_bound = 0x8C0CB
    idx = 0
    while pos < end_bound:
        end = rom.find(b'\x00', pos)
        if end == -1 or end > end_bound:
            break
        raw_name = rom[pos:end].decode('latin1', errors='replace')
        attacks.append({
            "id": idx,
            "hex_id": f"0x{idx:02X}",
            "name": raw_name
        })
        pos = end + 1
        idx += 1
    return attacks

def extract_classes(rom: bytes, attacks_map: dict) -> list:
    pos = 0x8BB29
    class_names = []
    for i in range(NUM_CLASSES):
        end = rom.find(b'\x00', pos)
        if end == -1 or end > pos + 32:
            class_names.append(f"CLASS_{i+1:02X}")
        else:
            class_names.append(rom[pos:end].decode('latin1', errors='replace').strip())
            pos = end + 1

    classes = []
    for i in range(NUM_CLASSES):
        cid = i + 1
        name = class_names[i]
        is_standard = (i < NUM_STANDARD_CLASSES)
        
        # Movement & costs (101 standard classes)
        if is_standard:
            move_type_code = rom[0x17D35 + i]
            move_type_name = MOVE_TYPES[move_type_code] if move_type_code < len(MOVE_TYPES) else f"Unknown ({move_type_code})"
            weight = rom[0x17D9A + i]
            base_cost = int.from_bytes(rom[0x17DFF + i*2 : 0x17DFF + i*2 + 2], 'little')
            cost_per_lvl = int.from_bytes(rom[0x17EC9 + i*2 : 0x17EC9 + i*2 + 2], 'little')
            leadership = bool(rom[0x17F93 + i])
            hp_growth = rom[0x1F08B + i]
            str_growth = rom[0x1F16D + i]
            agi_growth = rom[0x1F24F + i]
            int_growth = rom[0x1F331 + i]
            atk_packed = rom[0x1F50D + i]
            front_attacks = (atk_packed >> 4) & 0x0F
            back_attacks = atk_packed & 0x0F
            front_atk_id = rom[0x1F572 + i]
            back_atk_id = rom[0x1F5D7 + i]
            front_atk_name = attacks_map.get(front_atk_id, f"Attack 0x{front_atk_id:02X}")
            back_atk_name = attacks_map.get(back_atk_id, f"Attack 0x{back_atk_id:02X}")
            res_phys = rom[0x1F6A1 + i]
            res_fire = rom[0x1F706 + i]
            res_cold = rom[0x1F76B + i]
            res_elec = rom[0x1F7D0 + i]
            res_black = rom[0x1F835 + i]
            res_white = rom[0x1F89A + i]
        else:
            move_type_code = 0
            move_type_name = "Special"
            weight = 0
            base_cost = 0
            cost_per_lvl = 0
            leadership = True
            hp_growth = 0
            str_growth = 0
            agi_growth = 0
            int_growth = 0
            front_attacks = 0
            back_attacks = 0
            front_atk_id = 0
            back_atk_id = 0
            front_atk_name = "N/A"
            back_atk_name = "N/A"
            res_phys = 0
            res_fire = 0
            res_cold = 0
            res_elec = 0
            res_black = 0
            res_white = 0

        # All 125 classes have base HP, STR, AGI, INT, CHA, ALI, LUK
        base_hp = int.from_bytes(rom[0x1EF91 + i*2 : 0x1EF91 + i*2 + 2], 'little')
        base_str = rom[0x1F0F0 + i]
        base_agi = rom[0x1F1D2 + i]
        base_int = rom[0x1F2B4 + i]
        base_cha = rom[0x1F396 + i]
        base_ali = rom[0x1F413 + i]
        base_luk = rom[0x1F490 + i]

        classes.append({
            "id": cid,
            "hex_id": f"0x{cid:02X}",
            "name": name,
            "is_standard_class": is_standard,
            "movement": {
                "type_code": move_type_code,
                "type_name": move_type_name,
                "weight": weight
            },
            "costs": {
                "base_deploy_goth": base_cost,
                "daily_upkeep_per_level": cost_per_lvl,
                "can_lead_squad": leadership
            },
            "stats": {
                "base_hp": base_hp,
                "hp_growth": hp_growth,
                "base_str": base_str,
                "str_growth": str_growth,
                "base_agi": base_agi,
                "agi_growth": agi_growth,
                "base_int": base_int,
                "int_growth": int_growth,
                "base_cha": base_cha,
                "base_ali": base_ali,
                "base_luk": base_luk
            },
            "combat": {
                "front_row_actions": front_attacks,
                "back_row_actions": back_attacks,
                "front_attack": {
                    "id": front_atk_id,
                    "hex_id": f"0x{front_atk_id:02X}",
                    "name": front_atk_name
                },
                "back_attack": {
                    "id": back_atk_id,
                    "hex_id": f"0x{back_atk_id:02X}",
                    "name": back_atk_name
                }
            },
            "resistances": {
                "physical": res_phys,
                "fire": res_fire,
                "cold": res_cold,
                "lightning": res_elec,
                "black": res_black,
                "white": res_white
            }
        })
    return classes

def extract_promotions(rom: bytes) -> list:
    promos = []
    for cid in range(1, NUM_CLASSES + 1):
        ptr_offset = 0x4AD4C + (cid - 1) * 2
        snes_ptr = int.from_bytes(rom[ptr_offset:ptr_offset+2], 'little')
        rom_target = 0x40000 + (snes_ptr - 0x8000)
        
        targets = []
        if 0 <= rom_target < len(rom):
            curr = rom_target
            while curr < len(rom) and rom[curr] != 0:
                targets.append(rom[curr])
                curr += 1

        promos.append({
            "source_class_id": cid,
            "hex_id": f"0x{cid:02X}",
            "snes_pointer": f"0x{snes_ptr:04X}",
            "valid_promotions": targets
        })

    req_count = 77
    branch_reqs = []
    for i in range(req_count):
        branch_reqs.append({
            "branch_index": i,
            "min_level": rom[0x4AED4 + i],
            "min_ali": rom[0x4AF21 + i],
            "max_ali": rom[0x4AF6E + i],
            "min_cha": rom[0x4AFBB + i]
        })

    special_relics = [
        {
            "relic_name": "Stone of Dragos",
            "required_class_id": rom[0x317A6],
            "promoted_class_id": rom[0x317AD],
            "description": "Beast Master -> Dragoner"
        },
        {
            "relic_name": "Undead Staff",
            "required_class_id": rom[0x317B9],
            "promoted_class_id": rom[0x317C0],
            "description": "Mage -> Sorcerer / Lich staff"
        },
        {
            "relic_name": "Undead Ring (Primary)",
            "required_class_id": rom[0x317CC],
            "promoted_class_id": rom[0x317D7],
            "description": "Wizard / Mage -> Lich"
        },
        {
            "relic_name": "Undead Ring (Secondary)",
            "required_class_id": rom[0x317D0],
            "promoted_class_id": rom[0x317E0],
            "description": "Secondary class check for Lich"
        },
        {
            "relic_name": "Blood Kiss",
            "required_class_1": rom[0x317EC],
            "required_class_2": rom[0x317F0],
            "promoted_class_id": rom[0x317F7],
            "description": "Knight -> Vampyre"
        },
        {
            "relic_name": "Royal Crown",
            "required_class_id": rom[0x31803],
            "promoted_class_id": rom[0x3180A],
            "description": "Amazon / Valkyrie -> Princess"
        },
        {
            "relic_name": "Rotten Pumpkin",
            "required_class_id": rom[0x31813],
            "promoted_class_id": rom[0x3181A],
            "description": "Pumpkin -> Halloween"
        }
    ]

    return {
        "class_promotions": promos,
        "branch_requirements": branch_reqs,
        "special_relic_promotions": special_relics
    }

def extract_items(rom: bytes) -> list:
    pos = 0x3BED6
    item_names = []
    for i in range(NUM_ITEMS):
        end = rom.find(b'\x00', pos)
        if end == -1 or end > pos + 32:
            item_names.append(f"ITEM_{i+1:02X}")
        else:
            raw = rom[pos:end].decode('latin1', errors='replace').strip()
            cleaned = raw.replace('\x95', ' [Sword]')
            item_names.append(cleaned)
            pos = end + 1

    items = []
    for i in range(NUM_ITEMS):
        iid = i + 1
        name = item_names[i]
        is_equip = (i < NUM_EQUIPMENT_ITEMS)

        val_div_5 = rom[0x3C612 + i]
        price = val_div_5 * 5

        if is_equip:
            str_bonus = int.from_bytes(rom[0x3C7A3 + i : 0x3C7A3 + i + 1], 'little', signed=True)
            int_bonus = int.from_bytes(rom[0x3C808 + i : 0x3C808 + i + 1], 'little', signed=True)
            phys_bonus = int.from_bytes(rom[0x3C86D + i : 0x3C86D + i + 1], 'little', signed=True)
            fire_bonus = int.from_bytes(rom[0x3C8D2 + i : 0x3C8D2 + i + 1], 'little', signed=True)
            ice_bonus = int.from_bytes(rom[0x3C937 + i : 0x3C937 + i + 1], 'little', signed=True)
            elec_bonus = int.from_bytes(rom[0x3C99C + i : 0x3C99C + i + 1], 'little', signed=True)
            black_bonus = int.from_bytes(rom[0x3CA01 + i : 0x3CA01 + i + 1], 'little', signed=True)
            white_bonus = int.from_bytes(rom[0x3CA66 + i : 0x3CA66 + i + 1], 'little', signed=True)
        else:
            str_bonus = 0
            int_bonus = 0
            phys_bonus = 0
            fire_bonus = 0
            ice_bonus = 0
            elec_bonus = 0
            black_bonus = 0
            white_bonus = 0

        items.append({
            "id": iid,
            "hex_id": f"0x{iid:02X}",
            "name": name,
            "is_equipment": is_equip,
            "price_goth": price,
            "bonuses": {
                "strength": str_bonus,
                "intelligence": int_bonus,
                "physical_defense": phys_bonus,
                "fire_defense": fire_bonus,
                "ice_defense": ice_bonus,
                "lightning_defense": elec_bonus,
                "black_defense": black_bonus,
                "white_defense": white_bonus
            }
        })
    return items

def extract_shops(rom: bytes, items_map: dict) -> list:
    shops = []
    pos = 0x3CACA
    for s in range(NUM_STAGES):
        stage_id = s + 1
        stage_name = STAGE_NAMES[s] if s < len(STAGE_NAMES) else f"Stage {stage_id}"
        chunk = rom[pos + s*5 : pos + (s+1)*5]
        item_list = []
        for it in chunk:
            item_list.append({
                "item_id": it,
                "hex_id": f"0x{it:02X}",
                "name": items_map.get(it, f"Item 0x{it:02X}")
            })
        shops.append({
            "stage_id": stage_id,
            "stage_name": stage_name,
            "inventory": item_list
        })
    return shops

def extract_stages(rom: bytes, classes_map: dict) -> list:
    stages = []
    goal_pos = 0x2D173
    encounter_pos = 0x2E69F

    for s in range(NUM_STAGES):
        stage_id = s + 1
        stage_name = STAGE_NAMES[s] if s < len(STAGE_NAMES) else f"Stage {stage_id}"
        goal_code = int.from_bytes(rom[goal_pos + s*2 : goal_pos + (s+1)*2], 'little')

        enc_chunk = rom[encounter_pos + s*9 : encounter_pos + (s+1)*9]
        encounters = []
        for slot in range(3):
            loc_code, lvl, cls_id = enc_chunk[slot*3 : (slot+1)*3]
            cls_name = classes_map.get(cls_id, f"Class 0x{cls_id:02X}")
            encounters.append({
                "slot": slot + 1,
                "location_code": loc_code,
                "location_hex": f"0x{loc_code:02X}",
                "unit_level": lvl,
                "unit_class_id": cls_id,
                "unit_class_hex": f"0x{cls_id:02X}",
                "unit_class_name": cls_name
            })

        stages.append({
            "stage_id": stage_id,
            "stage_name": stage_name,
            "goal_code": goal_code,
            "goal_hex": f"0x{goal_code:04X}",
            "neutral_encounters": encounters
        })
    return stages

def main():
    rom_path = sys.argv[1] if len(sys.argv) > 1 else "/tmp/ogre_battle.sfc"
    out_dir = sys.argv[2] if len(sys.argv) > 2 else os.path.join(REPO_ROOT, "data", "vanilla")

    if not os.path.exists(rom_path):
        print(f"Error: ROM not found at '{rom_path}'.")
        sys.exit(1)

    with open(rom_path, "rb") as f:
        rom = f.read()

    verify_rom(rom)
    os.makedirs(out_dir, exist_ok=True)

    print("Extracting attacks...")
    attacks = extract_attacks(rom)
    attacks_map = {a["id"]: a["name"] for a in attacks}

    print("Extracting classes...")
    classes = extract_classes(rom, attacks_map)
    classes_map = {c["id"]: c["name"] for c in classes}

    print("Extracting promotions...")
    promotions = extract_promotions(rom)

    print("Extracting items...")
    items = extract_items(rom)
    items_map = {it["id"]: it["name"] for it in items}

    print("Extracting shops...")
    shops = extract_shops(rom, items_map)

    print("Extracting stages & encounters...")
    stages = extract_stages(rom, classes_map)

    targets = [
        ("attacks.json", attacks),
        ("classes.json", classes),
        ("promotions.json", promotions),
        ("items.json", items),
        ("shops.json", shops),
        ("stages.json", stages)
    ]

    for fname, data in targets:
        fpath = os.path.join(out_dir, fname)
        with open(fpath, "w", encoding="utf-8") as out:
            json.dump(data, out, indent=2)
        print(f"  -> Wrote {fpath} ({os.path.getsize(fpath):,} bytes)")

    print("\nExtraction complete! All canonical vanilla manifests emitted to:", out_dir)

if __name__ == "__main__":
    main()
