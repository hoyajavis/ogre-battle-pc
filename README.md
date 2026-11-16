# Ogre Battle: The March of the Black Queen — Native PC Port

A native desktop PC port (Windows, Linux, macOS) of Quest's 1993 Super Nintendo tactical RPG, powered by **65816 static recompilation** (`sp00nznet/snesrecomp`), the **LakeSnes** hardware runtime, and a custom **16:9 SDL2 desktop engine**.

> [!IMPORTANT]
> **Legal Notice (Rule 4):** This repository contains **no copyrighted ROMs, graphics, or audio assets**. You must supply your own clean copy of *Ogre Battle: The March of the Black Queen (USA)* (`.sfc`, SHA-1 `cfc45162b91791a61d4260e348ad43cb3b2eca0f`).

---

## Features

- **Bit-Exact Core Simulation:** Lifted 65816 C routines verified with 0-byte memory drift across 83,450 canonical gameplay frames (`docs/verification/gate_1_certification.md`).
- **Pre-Boot Launcher & `[Esc]` Settings Overlay:** Choose mod profiles, toggle community bug fixes, configure video/audio/mouse settings, and persist preferences to `ogre_battle.ini`.
- **16:9 Widescreen & Tactician Wings (`[F10]`):** Context-switched `144×448` sidebars displaying live Chaos Frame, Noon Tribute, City Liberation compatibility, `-5 CF` recapture alerts, Clash Tug-of-War, and Tarot Overlevel warnings—plus a **`[Tab]` Campaign Grimoire** modal.
- **Direct-State Mouse + Keyboard Handoff:** 1:1 Tactical Map cursor with ±8 px squad/city snapping, Right/Middle-drag camera panning, direct menu hit-boxes, World Map stage node selection, and instant keyboard takeover.
- **Boot-Time JSON Modding:** Vanilla tables (`data/vanilla/*.json`) and community overlays (`mods/*.json`) are validated and assembled in memory before reset with zero runtime CPU overhead.

---

## Quick Start

1. Download a release build (or build from source below) and place your verified `ogre_battle.sfc` next to `ogre_battle_pc` (or pass `--rom=path/to/ogre_battle.sfc`).
2. Launch **`ogre_battle_pc`** to open the **Pre-Boot Launcher**, select a profile (*Vanilla Purist*, *Community Fixes*, *Fin 0.71 Overhaul*, or *Class Expansion*), and click **LAUNCH GAME**.
3. Key hotkeys in-game:
   - **`[F10]`** — Cycle display mode (`16:9 Tactician Wings` / `16:9 Vanilla Horizon` / `4:3 Classic`)
   - **`[Tab]`** — Toggle the **Campaign Grimoire**
   - **`[P]`** — Toggle Hidden PoI Radar
   - **`[Esc]`** — Open Settings Overlay

For full controls and sidebar details, see the **[Player & Testing Guide](docs/user_testing_guide.md)** and **[16:9 Tactician Wings Manual](docs/player_manual_companion_window.md)**.

---

## Building from Source

```bash
# 1. Fetch snesrecomp & LakeSnes (requires git, CMake >= 3.16, C17/C++17, SDL2)
git clone --recursive https://github.com/sp00nznet/snesrecomp.git third_party/snesrecomp
git -C third_party/snesrecomp checkout 03bf617

# 2. Configure & Build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j

# 3. Run ROM-independent C & Python verification suites
ctest --test-dir build -R "Gate2MouseThreePillarTest|Gate3Widescreen16x9Test|Gate4TelemetryTest|Gate5ConfigGuiTest" --output-on-failure
PYTHONPATH=tools python3 -m unittest discover -s tests -p "*.py" -v
```

---

## Documentation

| Document | Purpose |
| :--- | :--- |
| [`docs/user_testing_guide.md`](docs/user_testing_guide.md) | Pre-Boot Launcher, `[Esc]` Settings, controls & testing checklist |
| [`docs/player_manual_companion_window.md`](docs/player_manual_companion_window.md) | 16:9 Tactician Wings, Campaign Grimoire & hidden mechanics guide |
| [`docs/LESSONS_LEARNED.md`](docs/LESSONS_LEARNED.md) | Engineering post-mortem: how SNES *Ogre Battle* works, porting lessons, modernizations, traces & agentic workflows |
| [`docs/architecture/README.md`](docs/architecture/README.md) | Developer guide for adopting the 16:9 UI, mouse layer, modding pipeline & hybrid oracle |
| [`docs/verification/`](docs/verification) | Certification reports for Gate 1, Gate 4A, and the Boot Pipeline |
| [`ROADMAP.md`](ROADMAP.md) | Current status, upcoming release polish & deferred items |
| [`CHANGELOG.md`](CHANGELOG.md) | Milestone and fix history |
| [`CONTRIBUTING.md`](CONTRIBUTING.md) | Contribution rules, Rule 4 compliance & git hooks |
| [`NOTICE`](NOTICE) | Third-party attributions (`snesrecomp`, `LakeSnes`, `SDL2`, community modders) |
| [`docs/agents.md`](docs/agents.md) | Agentic maintenance rules & git workflow |
| [`docs/archive/`](docs/archive) | Historical planning specs, gap analyses & session handoffs |
