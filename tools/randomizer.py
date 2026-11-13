#!/usr/bin/env python3
"""
tools/randomizer.py
Deterministic Seeded Pre-Boot Randomizer for Ogre Battle.

Mutates decoupled JSON manifests (classes, stats, attacks, shops, neutral encounters)
based on a user-provided seed string, outputting either a shareable mod manifest
or an assembled randomized ROM.

Part of Area 4 (Boot-Time Decoupling): Modular JSON builders.
"""

import os
import sys
import json
import random
import argparse
from rom_builder import assemble_rom

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def randomize_classes(classes: list, rng: random.Random, mutate_stats: bool = True, shuffle_attacks: bool = True) -> list:
    mutated = json.loads(json.dumps(classes)) # Deep copy

    for c in mutated:
        if not c.get("is_standard_class", True):
            continue

        stats = c["stats"]
        combat = c["combat"]

        if mutate_stats:
            # Jitter base stats within +/- 15%
            delta_str = rng.randint(-4, 6)
            stats["base_str"] = max(10, min(100, stats["base_str"] + delta_str))
            
            delta_agi = rng.randint(-4, 6)
            stats["base_agi"] = max(10, min(100, stats["base_agi"] + delta_agi))

            delta_int = rng.randint(-4, 6)
            stats["base_int"] = max(10, min(100, stats["base_int"] + delta_int))

            # Growths +/- 1
            stats["str_growth"] = max(1, min(5, stats["str_growth"] + rng.choice([-1, 0, 1])))
            stats["agi_growth"] = max(1, min(5, stats["agi_growth"] + rng.choice([-1, 0, 1])))
            stats["int_growth"] = max(1, min(5, stats["int_growth"] + rng.choice([-1, 0, 1])))

        if shuffle_attacks:
            # 10% chance to grant an extra attack to back row
            if rng.random() < 0.15:
                combat["back_row_actions"] = min(3, combat["back_row_actions"] + 1)
            # 5% chance for front row
            if rng.random() < 0.10:
                combat["front_row_actions"] = min(3, combat["front_row_actions"] + 1)

    return mutated

def randomize_shops(shops: list, items: list, rng: random.Random) -> list:
    mutated = json.loads(json.dumps(shops))
    all_item_ids = [it["id"] for it in items]

    for s in mutated:
        # Guarantee at least 1 healing item (Cure Potion 0xA5 or Cure Stone 0xA6 or Cure Ankh 0xA9)
        heal_id = rng.choice([0xA5, 0xA6, 0xA9])
        # Pick 4 random items from pool
        rand_pool = rng.sample(all_item_ids, 4)
        new_inv = [heal_id] + rand_pool
        rng.shuffle(new_inv)

        s["inventory"] = [{"item_id": iid, "hex_id": f"0x{iid:02X}"} for iid in new_inv]
    return mutated

def randomize_stages(stages: list, rng: random.Random) -> list:
    mutated = json.loads(json.dumps(stages))
    valid_monster_classes = [
        0x1B, 0x1D, 0x1E, 0x23, 0x25, 0x28, 0x2C, 0x2E, 0x30, 0x31, 0x32, 0x3E, 0x41, 0x44, 0x47, 0x4A, 0x4B, 0x4C
    ]

    for s in mutated:
        for enc in s.get("neutral_encounters", []):
            enc["unit_class_id"] = rng.choice(valid_monster_classes)
            enc["unit_class_hex"] = f"0x{enc['unit_class_id']:02X}"
            # Level scaled slightly around stage ID
            base_lvl = max(1, min(25, s["stage_id"] + rng.randint(-1, 2)))
            enc["unit_level"] = base_lvl

    return mutated

def main():
    parser = argparse.ArgumentParser(description="Ogre Battle Seeded Randomizer")
    parser.add_argument("--seed", default=None, help="Randomizer seed string (default: random)")
    parser.add_argument("--manifests", default=os.path.join(REPO_ROOT, "data", "vanilla"), help="Base manifests directory")
    parser.add_argument("--rom", default="/tmp/ogre_battle.sfc", help="Base clean ROM")
    parser.add_argument("--out-manifest", default=None, help="Output randomized mod manifest JSON path")
    parser.add_argument("--out-rom", default=None, help="Output randomized .sfc ROM path")
    parser.add_argument("--shuffle-stats", action="store_true", default=True, help="Randomize base stats and growths")
    parser.add_argument("--shuffle-shops", action="store_true", default=True, help="Randomize stage shop stock")
    parser.add_argument("--shuffle-recruits", action="store_true", default=True, help="Randomize neutral encounters")
    args = parser.parse_args()

    seed = args.seed if args.seed else hex(random.randint(0, 0xFFFFFFFF))[2:]
    print(f"=== Ogre Battle Randomizer Engine ===")
    print(f"Seed: {seed}")

    rng = random.Random(seed)

    # Load vanilla manifests
    with open(os.path.join(args.manifests, "classes.json"), "r") as f:
        classes = json.load(f)
    with open(os.path.join(args.manifests, "items.json"), "r") as f:
        items = json.load(f)
    with open(os.path.join(args.manifests, "shops.json"), "r") as f:
        shops = json.load(f)
    with open(os.path.join(args.manifests, "stages.json"), "r") as f:
        stages = json.load(f)

    mod_pack = {
        "mod_title": f"Randomizer Seed {seed}",
        "seed": seed,
        "format_version": "1.0",
        "description": "Seeded procedural Ogre Battle balance & layout pass"
    }

    if args.shuffle_stats:
        print("Randomizing classes & combat stats...")
        mod_pack["classes"] = randomize_classes(classes, rng)

    if args.shuffle_shops:
        print("Randomizing shop stocks...")
        mod_pack["shops"] = randomize_shops(shops, items, rng)

    if args.shuffle_recruits:
        print("Randomizing stage neutral recruit encounters...")
        mod_pack["stages"] = randomize_stages(stages, rng)

    if args.out_manifest:
        with open(args.out_manifest, "w", encoding="utf-8") as out:
            json.dump(mod_pack, out, indent=2)
        print(f"Randomized manifest written to: {args.out_manifest}")

    if args.out_rom:
        print(f"Assembling randomized ROM: {args.out_rom}...")
        with open(args.rom, "rb") as f:
            base_rom = f.read()
        
        # Save temp manifest to disk if not saved
        tmp_mod = "/tmp/temp_randomizer_mod.json"
        with open(tmp_mod, "w") as out:
            json.dump(mod_pack, out)

        rand_rom = assemble_rom(base_rom, args.manifests, overlays=[tmp_mod])
        with open(args.out_rom, "wb") as f:
            f.write(rand_rom)
        chk = int.from_bytes(rand_rom[0x7FDE:0x7FE0], 'little')
        print(f"Randomized ROM emitted successfully! Checksum: 0x{chk:04X} ({len(rand_rom):,} bytes)")

if __name__ == "__main__":
    main()
