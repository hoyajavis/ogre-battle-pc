#!/usr/bin/env python3
"""
tools/ips_importer.py
Legacy ROM Hack Importer (Diff-to-JSON Decompiler) for Ogre Battle.

Decodes monolithic .ips and .bps patches applied against the clean USA ROM,
maps modified byte ranges to high-level game entities (classes, items, shops, stages),
and exports portable, modular JSON mod manifests.

Part of Area 4 (Boot-Time Decoupling): Modular JSON builders.
"""

import os
import sys
import json
import argparse
from typing import List, Tuple, Dict, Any

NUM_STANDARD_CLASSES = 101

TABLE_RANGES = [
    ("movement_type", 0x17D35, 0x17D9A, "class_move_type"),
    ("weight", 0x17D9A, 0x17DFF, "class_weight"),
    ("base_cost", 0x17DFF, 0x17EC9, "class_base_cost"),
    ("cost_per_lvl", 0x17EC9, 0x17F93, "class_cost_per_lvl"),
    ("leadership", 0x17F93, 0x17FF8, "class_leadership"),
    ("base_hp", 0x1EF91, 0x1F08B, "class_base_hp"),
    ("hp_growth", 0x1F08B, 0x1F0F0, "class_hp_growth"),
    ("base_str", 0x1F0F0, 0x1F16D, "class_base_str"),
    ("str_growth", 0x1F16D, 0x1F1D2, "class_str_growth"),
    ("base_agi", 0x1F1D2, 0x1F24F, "class_base_agi"),
    ("agi_growth", 0x1F24F, 0x1F2B4, "class_agi_growth"),
    ("base_int", 0x1F2B4, 0x1F331, "class_base_int"),
    ("int_growth", 0x1F331, 0x1F396, "class_int_growth"),
    ("base_cha", 0x1F396, 0x1F413, "class_base_cha"),
    ("base_ali", 0x1F413, 0x1F490, "class_base_ali"),
    ("base_luk", 0x1F490, 0x1F50D, "class_base_luk"),
    ("attacks", 0x1F50D, 0x1F572, "class_attacks"),
    ("front_atk_id", 0x1F572, 0x1F5D7, "class_front_atk"),
    ("back_atk_id", 0x1F5D7, 0x1F63C, "class_back_atk"),
    ("phys_res", 0x1F6A1, 0x1F706, "class_phys_res"),
    ("fire_res", 0x1F706, 0x1F76B, "class_fire_res"),
    ("cold_res", 0x1F76B, 0x1F7D0, "class_cold_res"),
    ("elec_res", 0x1F7D0, 0x1F835, "class_elec_res"),
    ("black_res", 0x1F835, 0x1F89A, "class_black_res"),
    ("white_res", 0x1F89A, 0x1F8FF, "class_white_res"),
    ("item_value_div_5", 0x3C612, 0x3C7A3, "item_price"),
    ("item_str", 0x3C7A3, 0x3C808, "item_str"),
    ("item_int", 0x3C808, 0x3C86D, "item_int"),
    ("item_phys", 0x3C86D, 0x3C8D2, "item_phys"),
    ("item_fire", 0x3C8D2, 0x3C937, "item_fire"),
    ("item_ice", 0x3C937, 0x3C99C, "item_ice"),
    ("item_elec", 0x3C99C, 0x3CA01, "item_elec"),
    ("item_black", 0x3CA01, 0x3CA66, "item_black"),
    ("item_white", 0x3CA66, 0x3CACA, "item_white"),
    ("shop_inventory", 0x3CACA, 0x3CB60, "shop_items"),
    ("stage_goal", 0x2D173, 0x2D1AF, "stage_goals"),
    ("neutral_encounters", 0x2E69F, 0x2E7AD, "neutral_encounters"),
    ("promo_ptrs", 0x4AD4C, 0x4AE46, "promotions"),
    ("promo_targets", 0x4AE46, 0x4AED4, "promotions"),
    ("promo_min_lvl", 0x4AED4, 0x4AF21, "promotions"),
    ("promo_min_ali", 0x4AF21, 0x4AF6E, "promotions"),
    ("promo_max_ali", 0x4AF6E, 0x4AFBB, "promotions"),
    ("promo_min_cha", 0x4AFBB, 0x4B008, "promotions"),
    ("relic_promos", 0x317A0, 0x31820, "promotions"),
    ("spell_params", 0x052800, 0x053300, "spells"),
    ("item_names", 0x03DC80, 0x03DEB0, "items"),
    ("class_names", 0x08BA00, 0x08BD00, "classes"),
    ("attack_names", 0x08BF40, 0x08C100, "attacks"),
    ("snes_header", 0x007FC0, 0x008000, "snes_header")
]

def parse_ips(patch_data: bytes) -> List[Tuple[int, bytes]]:
    if not patch_data.startswith(b"PATCH"):
        raise ValueError("Invalid IPS header: missing 'PATCH' magic.")
    
    records = []
    idx = 5
    while idx < len(patch_data):
        if patch_data[idx:idx+3] == b"EOF":
            break
        offset = (patch_data[idx] << 16) | (patch_data[idx+1] << 8) | patch_data[idx+2]
        size = (patch_data[idx+3] << 8) | patch_data[idx+4]
        idx += 5
        if size == 0:
            # RLE record
            rle_len = (patch_data[idx] << 8) | patch_data[idx+1]
            rle_byte = patch_data[idx+2:idx+3]
            idx += 3
            records.append((offset, rle_byte * rle_len))
        else:
            data = patch_data[idx:idx+size]
            idx += size
            records.append((offset, data))
    return records

def detect_header_shift(records: List[Tuple[int, bytes]]) -> bool:
    score_unheadered = 0
    score_headered = 0
    for off, data in records:
        if 0x7FC0 <= off < 0x8000:
            score_unheadered += 10
        if 0x81C0 <= off < 0x8200:
            score_headered += 10
        if 0x4AED4 <= off < 0x4B008:
            score_unheadered += 5
        if 0x4B0D4 <= off < 0x4B208:
            score_headered += 5
        if off in (0x180200, 0x18022C, 0x180300, 0x180A00, 0x01918B, 0x02C2CE, 0x01EE67):
            score_headered += 5
        if (off - 0x200) in (0x180000, 0x18002C, 0x180100, 0x180800, 0x018F8B, 0x02C0CE, 0x01EC67):
            score_headered += 5
    return score_headered > score_unheadered

def decompile_diff(clean_rom: bytes, patched_rom: bytes, title: str = "Imported Mod") -> Dict[str, Any]:
    max_len = max(len(clean_rom), len(patched_rom))
    diff_bytes = {}
    for i in range(max_len):
        c_byte = clean_rom[i] if i < len(clean_rom) else 0x00
        p_byte = patched_rom[i] if i < len(patched_rom) else 0x00
        if c_byte != p_byte:
            diff_bytes[i] = (c_byte, p_byte)

    print(f"Total modified bytes detected: {len(diff_bytes):,}")

    mod_manifest = {
        "mod_title": title,
        "format_version": "1.0",
        "description": "Decompiled from legacy binary patch",
        "rom_size_bytes": len(patched_rom),
        "modified_domains": [],
        "micro_patches": []
    }

    # Track which byte offsets have been mapped to structured tables
    handled_offsets = set()

    # Check for table changes
    for tbl_name, start, end, domain_tag in TABLE_RANGES:
        tbl_diffs = [off for off in range(start, end) if off in diff_bytes]
        if tbl_diffs:
            handled_offsets.update(tbl_diffs)
            mod_manifest["modified_domains"].append({
                "table": tbl_name,
                "domain": domain_tag,
                "range": f"0x{start:05X}..0x{end:05X}",
                "modified_byte_count": len(tbl_diffs)
            })

    # All diffs are grouped into contiguous executable micro-patches
    all_diffs = sorted(list(diff_bytes.keys()))
    if all_diffs:
        blocks = []
        cur_block = [all_diffs[0]]
        for o in all_diffs[1:]:
            if o == cur_block[-1] + 1:
                cur_block.append(o)
            else:
                blocks.append(cur_block)
                cur_block = [o]
        if cur_block:
            blocks.append(cur_block)

        for b in blocks:
            b_start = b[0]
            b_len = len(b)
            old_b = bytes([diff_bytes[o][0] for o in b])
            new_b = bytes([diff_bytes[o][1] for o in b])
            mod_manifest["micro_patches"].append({
                "rom_offset": f"0x{b_start:06X}",
                "length": b_len,
                "vanilla_bytes": old_b.hex().upper(),
                "patched_bytes": new_b.hex().upper()
            })

    return mod_manifest

def main():
    parser = argparse.ArgumentParser(description="Ogre Battle IPS/BPS Legacy Patch Importer")
    parser.add_argument("--rom", default="/tmp/ogre_battle.sfc", help="Clean base ROM")
    parser.add_argument("--patch", required=True, help="Input .ips or patched .sfc file")
    parser.add_argument("--out", required=True, help="Output mod manifest JSON path")
    parser.add_argument("--name", default="Imported Community Mod", help="Mod title")
    parser.add_argument("--header", choices=["auto", "yes", "no"], default="auto",
                        help="Specify if source patch was built against 512-byte headered ROM")
    args = parser.parse_args()

    with open(args.rom, "rb") as f:
        clean_rom = f.read()

    with open(args.patch, "rb") as f:
        patch_file = f.read()

    if patch_file.startswith(b"PATCH"):
        print("Parsing IPS patch...")
        records = parse_ips(patch_file)
        if args.header == "auto":
            is_headered = detect_header_shift(records)
            print(f"Auto-detected patch header status: {'HEADERED (+512 bytes)' if is_headered else 'UNHEADERED'}")
        else:
            is_headered = (args.header == "yes")

        shift = 0x200 if is_headered else 0
        max_target = max(r[0] + len(r[1]) - shift for r in records)
        target_size = max(len(clean_rom), max_target)
        if target_size > len(clean_rom):
            # Align to 2MB if expanding
            target_size = max(target_size, 2097152)

        patched_buf = bytearray(clean_rom)
        if target_size > len(patched_buf):
            patched_buf.extend(b"\x00" * (target_size - len(patched_buf)))

        for offset, data in records:
            dest = offset - shift
            if dest < 0:
                print(f"Warning: Negative offset 0x{dest:X} encountered; skipping.")
                continue
            patched_buf[dest:dest+len(data)] = data
        patched_rom = bytes(patched_buf)
    elif len(patch_file) >= len(clean_rom):
        print("Input is already a patched SFC ROM binary...")
        patched_rom = patch_file
    else:
        print("Error: Unrecognized patch format.")
        sys.exit(1)

    manifest = decompile_diff(clean_rom, patched_rom, title=args.name)
    with open(args.out, "w", encoding="utf-8") as out:
        json.dump(manifest, out, indent=2)

    print(f"Mod manifest successfully emitted to: {args.out}")

if __name__ == "__main__":
    main()
