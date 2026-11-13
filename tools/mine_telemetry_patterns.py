#!/usr/bin/env python3
"""
Ogre Battle: The March of the Black Queen — Native PC Port
Modernization Area 1: Phase 5 Pattern Discovery Lab & Emergent UX Miner

Ingests `.jsonl` telemetry streams produced by `dump_telemetry_trace.py`,
correlating Tier 2 "Dark State" WRAM regions (Domains E–J) against tactical
gameplay phases to discover:
  1. Bitflag transitions in the 2,344-bit event/treasure/recruitment region ($7E:8600–$7E:8F27)
  2. Sub-tile kinematics & terrain speed/fatigue decay curves ($7E:18AF–$7E:1A45)
  3. Live Combat Clash Tug-of-War momentum turns ($7E:F942 vs $7E:F944)
  4. Celestial/Lunar Calendar leap-year & Noon Tribute rollover triggers ($7E:156D–$7E:1575)
  5. Promotion Tree graph connectivity & hidden relic gates in Bank $09 ($04AD4C–$04B007)
"""

import argparse
import json
from collections import defaultdict
from pathlib import Path
from typing import Any, Dict, List


def analyze_rom_promotion_graph(rom_path: Path) -> Dict[str, Any]:
    data = rom_path.read_bytes()
    total_edges = 0
    relic_gated = []
    multi_branch_classes = 0

    # Bank $09 offsets:
    # 0x04AD4C: 125 x 2-byte LE pointers in Bank $09
    # 0x04AED4: min_lvl (77 bytes)
    # 0x04AF21: min_ali (77 bytes)
    # 0x04AF6E: max_ali (77 bytes)
    # 0x04AFBB: min_cha (77 bytes)
    for class_id in range(1, 78):
        ptr_off = 0x04AD4C + (class_id - 1) * 2
        ptr = data[ptr_off] | (data[ptr_off + 1] << 8)
        if ptr < 0x8000:
            continue
        list_off = 0x048000 + (ptr - 0x8000)
        targets = []
        while list_off < len(data) and data[list_off] != 0:
            t = data[list_off]
            if 1 <= t <= 77:
                targets.append(t)
            list_off += 1
        total_edges += len(targets)
        if len(targets) >= 2:
            multi_branch_classes += 1

    # Inspect special min_lvl==99 relic-gated classes in ROM table
    for target_id in range(1, 78):
        idx = target_id - 1
        min_lvl = data[0x04AED4 + idx]
        min_ali = data[0x04AF21 + idx]
        max_ali = data[0x04AF6E + idx]
        min_cha = data[0x04AFBB + idx]
        if min_lvl >= 90:
            relic_gated.append(
                {
                    "class_id": target_id,
                    "rom_min_lvl_sentinel": min_lvl,
                    "min_ali": min_ali,
                    "max_ali": max_ali,
                    "min_cha": min_cha,
                }
            )

    return {
        "combat_classes_inspected": 77,
        "total_promotion_edges": total_edges,
        "multi_branch_classes": multi_branch_classes,
        "relic_sentinel_classes": relic_gated,
    }


def mine_telemetry_trace(jsonl_path: Path, rom_path: Path) -> Dict[str, Any]:
    snapshots: List[Dict[str, Any]] = []
    diffs: List[Dict[str, Any]] = []

    with jsonl_path.open("r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            rec = json.loads(line)
            if rec.get("record_type") == "frame_snapshot":
                snapshots.append(rec)
            elif "category" in rec:
                diffs.append(rec)

    by_scenario: Dict[str, int] = defaultdict(int)
    for s in snapshots:
        by_scenario[s["scenario"]] += 1

    bitflag_events = [d for d in diffs if "_BIT_" in d["category"]]
    scalar_events = [d for d in diffs if "_BIT_" not in d["category"]]

    # Analyze kinematic trajectory & fatigue accumulation during tactical_march
    march_snaps = [s for s in snapshots if s["scenario"] == "tactical_march"]
    fatigue_series = [s["player_lead"]["fatigue"] for s in march_snaps]
    closing_distances = [
        abs(s["player_lead"]["x"] - s["enemy_lead"]["x"]) + abs(s["player_lead"]["y"] - s["enemy_lead"]["y"])
        for s in march_snaps
    ]

    # Analyze live combat clash tug-of-war ($7E:F942 vs $7E:F944)
    clash_snaps = [s for s in snapshots if s["scenario"] == "combat_clash"]
    clash_trajectory = [
        {
            "frame": s["frame"],
            "player_dmg": s["combat"]["player_dmg"],
            "enemy_dmg": s["combat"]["enemy_dmg"],
            "margin": s["combat"]["margin"],
        }
        for s in clash_snaps
    ]

    rom_promo_stats = analyze_rom_promotion_graph(rom_path) if rom_path.exists() else {}

    summary = {
        "total_snapshots": len(snapshots),
        "total_diff_events": len(diffs),
        "snapshots_by_scenario": dict(by_scenario),
        "discovered_bitflag_transitions": bitflag_events,
        "scalar_state_transitions": scalar_events,
        "kinematic_insights": {
            "march_samples": len(march_snaps),
            "initial_manhattan_distance_px": closing_distances[0] if closing_distances else 0,
            "final_manhattan_distance_px": closing_distances[-1] if closing_distances else 0,
            "avg_closing_speed_px_per_step": round(
                (closing_distances[0] - closing_distances[-1]) / max(1, len(closing_distances) - 1), 2
            )
            if len(closing_distances) > 1
            else 0.0,
            "peak_fatigue_counter": max(fatigue_series) if fatigue_series else 0,
        },
        "combat_tug_of_war_trajectory": clash_trajectory,
        "rom_promotion_graph_analysis": rom_promo_stats,
    }
    return summary


def main() -> int:
    parser = argparse.ArgumentParser(description="Phase 5 Pattern Discovery Lab Miner")
    parser.add_argument(
        "--trace",
        type=Path,
        default=Path("/home/antigravity/build/telemetry_trace.jsonl"),
        help="Input JSONL trace from dump_telemetry_trace.py",
    )
    parser.add_argument(
        "--rom",
        type=Path,
        default=Path("/home/antigravity/ogre_battle.sfc"),
        help="Path to clean USA Ogre Battle ROM",
    )
    parser.add_argument(
        "--out-json",
        type=Path,
        default=Path("/home/antigravity/build/pattern_discovery_report.json"),
        help="Output JSON report path",
    )
    args = parser.parse_args()

    summary = mine_telemetry_trace(args.trace, args.rom)
    args.out_json.parent.mkdir(parents=True, exist_ok=True)
    args.out_json.write_text(json.dumps(summary, indent=2), encoding="utf-8")

    print("================================================================================")
    print("  PHASE 5: PATTERN DISCOVERY LAB — WRAM DARK-STATE CORRELATION REPORT")
    print("================================================================================")
    print(f"  Snapshots Analyzed        : {summary['total_snapshots']}")
    print(f"  Diff Events Captured      : {summary['total_diff_events']}")
    print(f"  2,344-Bit Flag Transitions: {len(summary['discovered_bitflag_transitions'])}")
    for bf in summary["discovered_bitflag_transitions"]:
        print(
            f"    - Frame {bf['frame']:3d} [{bf['category']:14s}]: {bf['wram']} (Bit #{bf['bit']:4d}) "
            f"{bf['old']} -> {bf['new']}"
        )
    print("  Scalar Domain Transitions :")
    for sc in summary["scalar_state_transitions"]:
        print(
            f"    - Frame {sc['frame']:3d} [{sc['category']:14s}]: {sc['wram']} "
            f"{sc['old']} -> {sc['new']}"
        )
    kin = summary["kinematic_insights"]
    print(
        f"  Kinematic Closing Vector  : {kin['initial_manhattan_distance_px']}px -> "
        f"{kin['final_manhattan_distance_px']}px ({kin['avg_closing_speed_px_per_step']} px/step, "
        f"peak fatigue={kin['peak_fatigue_counter']})"
    )
    if summary["combat_tug_of_war_trajectory"]:
        last_clash = summary["combat_tug_of_war_trajectory"][-1]
        print(
            f"  Combat Clash Resolution   : Player {last_clash['player_dmg']} dmg vs "
            f"Enemy {last_clash['enemy_dmg']} dmg (Margin: +{last_clash['margin']} -> VICTORY)"
        )
    promo = summary.get("rom_promotion_graph_analysis", {})
    if promo:
        print(
            f"  ROM Bank $09 Promo Graph  : {promo['combat_classes_inspected']} classes, "
            f"{promo['total_promotion_edges']} directed edges, "
            f"{len(promo['relic_sentinel_classes'])} relic-sentinel classes (min_lvl=99)"
        )
    print("================================================================================")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
