# Developer & Architecture Guide

This directory documents the reusable engineering patterns and architecture of **Ogre Battle PC** for developers looking to adopt its features or hybrid porting methodology in other SNES-to-PC projects.

## Guides in This Directory
- **[16:9 Widescreen Architecture](widescreen_16_9_architecture.md)** — Dual-layer `400×224` (`800×448` 2×) compositor, BGR555 9-slice software rasterizer (`src/engine/snes_ui_rasterizer.c`), and context-switched side wings without altering the 4:3 simulation core.
- **[Area 1 Zero-Invasion Telemetry Developer Guide](developer_guide_area_1_telemetry.md)** — `const`-only WRAM/ROM telemetry extraction, predictive models, and scene classification (`src/engine/widescreen.c`, `src/engine/telemetry.c`).
- **[SNES ROM Transpilation Research Plan](snes_rom_transpilation_research_plan.md)** — Comparative analysis of `snesrecomp`, `snesrev` (`zelda3`/`smw`/`sm`), and `gilgamesh`, plus 65816 static lifting challenges (`REP`/`SEP` $M/X$ widths, jump tables).
- **[RHDN Patch & Modding Catalog](rhdn_patches_catalog.md)** — How legacy `.ips` community patches are decompiled into structured JSON overlays and assembled pre-reset (`tools/boot_pipeline.py`, `tools/rom_builder.py`, `src/engine/boot_loader.c`).

## Origin & Design History (3 Attempts)
This port is the third attempt at bringing *Ogre Battle: The March of the Black Queen* natively to PC, and its hybrid architecture reflects the lessons of the first two:
1. **Attempt 1 — Disassembly & Static Recompilation into Rust (`romatlas`):** Ahead-of-time 65816 lifting into Rust hit a wall on dynamic `REP`/`SEP` register-width (`M`/`X`) switches, indirect jump tables, hardware MMIO multipliers (`$4202 * $4203`), and NMI-sensitive routines.
2. **Attempt 2 — Pygame Reimplementation from Community Documentation:** Reimplementing the game logic from community docs worked notionally, but faithfully reproducing the SNES graphics rendering (Mode-7 tactical maps, HDMA horizon effects, window masks, color math) in Pygame proved unsustainable.
3. **Attempt 3 — Hybrid `snesrecomp` + `snesrev` + Custom 16:9 Engine (This Repo):** Uses `sp00nznet/snesrecomp` + LakeSnes for cycle-accurate PPU/APU/DMA silicon and tiered interpreter fallback, paired with a `snesrev`-style frame-by-frame `memcmp` lockstep oracle (`runner/`) and a custom SDL2 `800×448` compositor (`src/main.c`).

## Adopting Features in Another SNES Port

| Feature | Key Source Files | Portability Notes |
| :--- | :--- | :--- |
| **BGR555 9-Slice UI Rasterizer** | `src/engine/snes_ui_rasterizer.c/.h`, `include/ob_snes_ui_theme.h` | **Game-agnostic.** Drop into any 32-bit RGBA framebuffer port to render authentic 1993 SNES windows, gauges, and shadowed bitmap fonts. |
| **16:9 Side-Wing Compositor** | `src/engine/widescreen.c/.h` | Compositor loop and tapestry/wing framing are reusable; replace `ob_widescreen_detect_scene` and wing card layouts with your game's WRAM/OAM state. |
| **Hybrid Mouse + Keyboard Handoff** | `src/engine/input.c/.h` | Coordinate mapping (`ob_input_map_window_to_snes`), cooldown handoff, and zero-invasion idle lockstep are reusable; swap WRAM cursor/OAM hit-test rules per game. |
| **Pre-Boot Launcher & `.ini` Config** | `src/engine/gui_menu.c/.h`, `src/engine/config.c/.h` | Reusable ROM picker, display-mode selector, and settings overlay. |
| **Hybrid `snesrecomp` + Lockstep Oracle** | `runner/`, `runner/src/recomp_compat.c` | Combines `sp00nznet/snesrecomp` + LakeSnes silicon runtime with a `snesrev`-style full-subsystem `memcmp` oracle across `.obrec` traces. |
