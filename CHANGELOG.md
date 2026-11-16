# Changelog

All notable milestones and fixes in **Ogre Battle: The March of the Black Queen (PC)** are documented here.

## Unreleased (v1.0.0-rc)
### Fixed
- **Scene Detection & Telemetry (`0x55` LakeSnes WRAM Guard):** Fixed sidebars locking onto `COMBAT STAGE` (`PLY:21845 VS ENM:21845`, `LORD LV85`) by guarding against LakeSnes's `0x55` uninitialized WRAM fill and using verified WRAM/OAM discriminators (`$1578`, `$07BA`, `$00CB`, `$00CC`, `$07A2`, `$18AF`, `$14E6`, `$F92B`).
- **Tactical & World Map Mouse Control:** Fixed inverted `$14E6` cursor-visibility check on the Tactical Map, added `OAM[1..23]` stage-banner hit-testing and `$07A2`/`$07BA` detection on the World Map, and locked mouse viewport mapping in `src/main.c` to the `800×448` (`400×224` 1×) logical canvas.
- **Cross-Platform CI:** Added `sp00nznet/snesrecomp` (`03bf617`) recursive checkout in `.github/workflows/ci.yml` and compatibility shims (`runner/src/recomp_compat.c`) for Linux, macOS, and Windows (MSYS2 UCRT64) builds.

### Changed
- **Documentation Reorganization:** Adopted `ROADMAP.md`, `CHANGELOG.md`, and `NOTICE` at repository root; grouped certification reports under `docs/verification/`, developer adoption guides under `docs/architecture/`, and archived historical build-time docs under `docs/archive/`.

## Certified Milestones
- **COA 3 (`3b24854`):** Added SNES-styled pre-boot launcher, `[Esc]` settings overlay, and `ogre_battle.ini` persistence.
- **Gate 4A / Area 4 (`PR #4`):** Decoupled 6 gameplay data domains into `data/vanilla/*.json` with 0-byte roundtrip drift, layered mod overlays, `ConflictValidator`, and 1.5 MB/2.0 MB ROM assembly.
- **Gate 3 (`v0.3.0-gate3-wide`):** Implemented `800×448` 16:9 compositor, `144×448` Left/Right Area 1 Telemetry Wings, `[Tab]` Campaign Grimoire, and `[F10]` display mode cycling.
- **Gate 2 (`v0.2.0-gate2-mouse`):** Implemented Three-Pillar direct-state mouse control (`$14DE/$14E0`), decoupled camera panning (`$00BD/$00BF`), menu hit-boxes, World Map nodes, and hybrid keyboard handoff.
- **Area 1 (`PR #1`):** Implemented `const`-only WRAM/ROM telemetry engine and BGR555 9-slice SNES UI software rasterizer.
- **Gate 1 (`v0.1.0-gate1-certified`):** Certified 0-byte memory drift across 83,450 frames (8 canonical `.obrec` traces) using automated 65816 static lifting + LakeSnes + dual-execution lockstep oracle (`RM_BOTH`).
