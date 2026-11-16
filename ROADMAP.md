# Roadmap

## Current Status
Gates 1–4 and cross-platform CI/packaging are complete:
- **Gate 1 (Bit-Exact 4:3 Baseline):** 0-byte drift across 83,450 canonical frames (`traces/trace_01`–`trace_08`).
- **Area 1 & Gate 3 (16:9 Widescreen & Telemetry):** `800×448` software compositor, BGR555 9-slice UI rasterizer, context-switched telemetry wings, `[Tab]` Campaign Grimoire, and `0x55` WRAM initialization guards.
- **Gate 2 (Three-Pillar Mouse):** Direct-state Tactical Map cursor (`$14DE/$14E0`), decoupled camera pan (`$00BD/$00BF`), menu hit-boxes, World Map stage node hit-testing, and instant keyboard handoff.
- **Area 4 (Boot-Time Decoupling):** JSON manifests (`data/vanilla/*.json`), layered mod overlays (`mods/*.json`), `ConflictValidator`, and pre-reset ROM assembly.
- **Cross-Platform CI:** Automated Linux, macOS, and Windows builds with release artifact uploads.
- **Lessons Learned Retrospective:** Full engineering post-mortem covering 65816 lifting, `0x55` WRAM hygiene, mouse/widescreen designs, boot-time modding, and hybrid oracles ([`docs/LESSONS_LEARNED.md`](docs/LESSONS_LEARNED.md)).

## Next
- **v1.0 Release Polish:** End-to-end playthrough verification across all 13 endings on Windows/Linux/macOS release packages.
- **Upstream `snesrecomp` Contribution:** Propose/upstream a headless `snesrecomp_core` CMake split (optional SDL2) to `sp00nznet/snesrecomp`.

## Deferred
- **Reusable SNES-to-PC Kit Extraction:** Spin off the game-agnostic `snes_ui_rasterizer`, `800×448` widescreen compositor, and pre-boot launcher into a standalone template/library for other SNES ports.

## Out of Scope
- Distributing copyrighted ROM images (`.sfc`/`.smc`), extracted audio samples, or decompressed game assets (see Rule 4 in [`CONTRIBUTING.md`](CONTRIBUTING.md)).
