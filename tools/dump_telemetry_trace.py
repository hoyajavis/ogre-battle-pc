#!/usr/bin/env python3
"""
Ogre Battle: The March of the Black Queen — Native PC Port
Modernization Area 1: Headless Telemetry Trace Extractor (Phase 1)

Compiles (if needed) and runs `build/telemetry_trace_runner` against the clean
USA ROM (`ogre_battle.sfc`, SHA1 cfc45162b91791a61d4260e348ad43cb3b2eca0f),
emitting structured Tier 1 + Tier 2 JSONL snapshots and bitflag diffs.
"""

import argparse
import hashlib
import os
import subprocess
import sys
from pathlib import Path

EXPECTED_SHA1 = "cfc45162b91791a61d4260e348ad43cb3b2eca0f"


def verify_rom_sha1(rom_path: Path) -> str:
    h = hashlib.sha1()
    with rom_path.open("rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest()


def ensure_runner_built(repo_root: Path) -> Path:
    build_dir = repo_root / "build"
    build_dir.mkdir(parents=True, exist_ok=True)
    runner_bin = build_dir / "telemetry_trace_runner"

    snes_sources = [str(p) for p in sorted((repo_root / "third_party/LakeSnes/snes").glob("*.c"))]
    cmd = [
        "gcc",
        "-O2",
        "-Wall",
        "-Wextra",
        f"-I{repo_root / 'include'}",
        f"-I{repo_root / 'third_party/LakeSnes/snes'}",
        str(repo_root / "src/engine/telemetry.c"),
        str(repo_root / "src/engine/telemetry_math.c"),
        str(repo_root / "src/engine/telemetry_window.c"),
        str(repo_root / "src/tools/telemetry_trace_runner.c"),
        *snes_sources,
        "-lm",
        "-o",
        str(runner_bin),
    ]
    subprocess.run(cmd, check=True)
    return runner_bin


def main() -> int:
    parser = argparse.ArgumentParser(description="Extract Tier 1 + Tier 2 WRAM telemetry trace (.jsonl)")
    parser.add_argument(
        "--rom",
        type=Path,
        default=Path("/home/antigravity/ogre_battle.sfc"),
        help="Path to clean USA Ogre Battle ROM",
    )
    parser.add_argument(
        "--out",
        type=Path,
        default=Path("/home/antigravity/build/telemetry_trace.jsonl"),
        help="Output JSONL trace path",
    )
    parser.add_argument(
        "--ppm",
        type=Path,
        default=Path("/tmp/companion_window_preview.ppm"),
        help="Output PPM snapshot of Secondary Companion Window",
    )
    args = parser.parse_args()

    if not args.rom.exists():
        print(f"[ERROR] ROM not found: {args.rom}", file=sys.stderr)
        return 1

    rom_sha1 = verify_rom_sha1(args.rom)
    if rom_sha1 != EXPECTED_SHA1:
        print(f"[WARN] ROM SHA1 {rom_sha1} differs from canonical USA SHA1 {EXPECTED_SHA1} (Modded ROM active)")
    else:
        print(f"[OK] Verified clean USA ROM SHA1: {rom_sha1}")

    repo_root = Path(__file__).resolve().parent.parent
    runner_bin = ensure_runner_built(repo_root)

    args.out.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([str(runner_bin), str(args.rom), str(args.out), str(args.ppm)], check=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
