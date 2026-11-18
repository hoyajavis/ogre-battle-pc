# Changelog

All notable milestones and fixes in **Ogre Battle: The March of the Black Queen (PC)** are documented here.

## Unreleased (v1.0.0-rc)
### Fixed
- **Tactical Wing Hysteresis & Scene Detection Immunity (`Gate 3F`):** Eliminated rapid side-wing widget flickering during live gameplay by anchoring `ob_widescreen_detect_scene`, `classify_screen_mode`, and `ob_input_detect_mode` on verified persistent hardware state (`$7E:07BA` roster slot 0 lifecycle `0x55`/`0xFF`/populated ID, `$7E:00CB` master module ID, and `$7E:00CC` sub-step) instead of Direct-Page scratch `$7E:0010 == 1` or VBlank transfer command `$7E:00CA`. Gated live `OB_SCENE_COMBAT_STAGE` detection on active combat round state (`$7E:F92B != 0` with remaining round actions `$7E:F941 > 0`) so post-battle cumulative damage (`$7E:F942`/`$7E:F944`) never overrides the Tactical Map, prioritized Pillar 1 Tactical Map ahead of Pillar 3 OAM World Map scans, fixed live Solar Clock `$7E:1571` Hour / `$7E:1572` Minute extraction, filtered `0x7FFF` inactive entity coordinates, and added Schmitt-trigger spatial/temporal hysteresis (`45`-frame sticky inspector hold, `8 px` entry / `12 px` keep magnetic snap, and `180 px` entry / `210 px` exit + `15`-frame debounce on `-5 CF` recapture alerts).
- **Scene Detection & Telemetry (`0x55` LakeSnes WRAM Guard):** Fixed sidebars locking onto `COMBAT STAGE` (`PLY:21845 VS ENM:21845`, `LORD LV85`) on cold boot by guarding against LakeSnes's `0x55` uninitialized WRAM fill.
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
