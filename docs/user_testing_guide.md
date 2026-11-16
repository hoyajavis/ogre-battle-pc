# Ogre Battle PC Port: Player & Desktop Testing Guide

**Executable:** `ogre_battle_pc` (`ogre_battle_pc.exe` on Windows)  
**Display Resolution:** `800×448` logical (`1600×896` default at `2×` scale, resizable, fullscreen supported)  
**ROM Requirement:** Supply your own clean *Ogre Battle: The March of the Black Queen (USA)* `.sfc` file (SHA-1 `cfc45162b91791a61d4260e348ad43cb3b2eca0f`), placed alongside the executable as `ogre_battle.sfc` or passed via `--rom=path/to/rom.sfc`.  
**Config Persistence:** Automatically saved to `ogre_battle.ini` in the working directory.

---

## 1. Quick Start & Pre-Boot Launcher

1. Place your verified `ogre_battle.sfc` in the same folder as `ogre_battle_pc` (or pass `--rom=<path>`).
2. Launch `ogre_battle_pc`. Unless `auto_boot = true` is enabled, you will start in the **Pre-Boot Launcher**:

### Pre-Boot Launcher Options
- **Left Column — Boot Profile (Area 4):**
  - **Vanilla Purist:** 100% bit-exact clean USA LoROM (`1.5 MB`).
  - **Community Fixes:** Clean base + Bank `$30` engine fixes (`2.0 MB`).
  - **Fin 0.71 Overhaul:** Fin's v0.71 balance & promotion overhaul (`2.0 MB`).
  - **Class Expansion:** UPRC Class Expansion with 14 additional classes (`2.0 MB`).
- **Right Column — Engine Toggles & Boot Behavior:**
  - **Magic AI Fix / Crown Drop Fix / Extensible Size Table:** Individual Bank `$30` community fixes *(automatically disabled when `Class Expansion` is selected to prevent conflicts)*.
  - **Auto-Boot:** Skip the launcher on future startups when a valid ROM is found.
- **Bottom Buttons:** `LAUNCH GAME`, `SETTINGS`, `QUIT`.

### Launcher Controls
| Input | Action |
| :--- | :--- |
| **Arrow Keys** (`↑`/`↓`/`←`/`→`) | Navigate profiles and toggles |
| **`Tab`** | Toggle the highlighted option |
| **`Enter`** | Select & Launch Game |
| **`Esc`** | Quit |
| **Mouse Click** | Click any profile, toggle, or button directly |

---

## 2. In-Game `[Esc]` Settings Overlay

Press **`Esc`** at any time during gameplay (or click **SETTINGS** on the launcher) to open the 4-tab Settings Overlay. All changes are saved immediately to `ogre_battle.ini`.

- **`VIDEO` Tab:** Display Mode (`16:9 Tactician Wings`, `16:9 Vanilla Horizon`, `4:3 Classic`), Fullscreen, Window Scale (`1×`–`4×`), CRT Scanlines, VSync.
- **`AUDIO` Tab:** Master Volume (`0%`–`100%`), Mute.
- **`CONTROLS` Tab:** Mouse Enabled, Edge Pan Enabled, Edge Pan Speed (`2`–`8`), PoI Radar Enabled.
- **`SYSTEM` Tab:** Reset Defaults (preserves ROM path), Return to Launcher, Quit.

*Navigation:* **`Tab`** cycles tabs, **`↑`/`↓`** selects rows, **`←`/`→`** adjusts values, **`Esc`** or clicking **RESUME** closes the overlay.

---

## 3. Controls & Hotkeys

### Desktop Hotkeys
| Key | Action |
| :--- | :--- |
| **`F10`** | Cycle Display Mode (`16:9 Tactician Wings` → `16:9 Vanilla Horizon` → `4:3 Classic`) |
| **`Tab`** | Toggle centered **Campaign Grimoire** overlay (18 Heroes, 12 Zodiac Stones, Promotion Tree) |
| **`P`** | Toggle **Hidden Points of Interest (PoI)** radar |
| **`Esc`** | Toggle **Settings Overlay** |

### Mouse Controls (Three-Pillar Architecture)
| Mouse Action | Context | Behavior |
| :--- | :--- | :--- |
| **Move Mouse (Core Viewport)** | **Tactical Map** | Moves battlefield cursor 1:1 with ±8 px snap to squads & cities; camera stays still |
| **Right-Click / Middle-Click Drag** | **Tactical & World Map** | Pans Mode-7 camera 1:1 with drag delta |
| **Hold at Window Edge (10 px)** | **Tactical & World Map** | Smoothly pans camera toward that border (when Edge Pan is enabled) |
| **Hover Icon / Formation Cell** | **7-Icon Bar / 3×2 Grid** | Selects hovered slot directly with zero wrap-around |
| **Hover Stage Banner** | **World Map** | Highlights hovered stage node |
| **Click Left / Right Wing** | **16:9 Tactician Wings** | Click deployed squad plates (Left Wing) to jump camera to that squad |
| **Left Click** | **All Screens** | **SNES A** (Confirm / Deploy / Inspect) |
| **Right Click (Tap)** | **All Screens** | **SNES B** (Cancel / Close Menu) |

*Hybrid Priority:* Pressing any keyboard D-Pad key immediately hands control back to the keyboard; moving the mouse again after the short cooldown restores pointer control.

### Keyboard Mapping (SNES Joypad 1)
| SNES Button | Key(s) |
| :--- | :--- |
| **D-Pad** | Arrow Keys (`↑` `↓` `←` `→`) |
| **A (Confirm)** | `X` or `K` |
| **B (Cancel)** | `Z` or `J` |
| **X (Menu)** | `S` or `I` |
| **Y (Details)** | `A` or `U` |
| **L / R** | `Q` / `W` |
| **Start** | `Enter` |
| **Select** | `Right Shift` or `Backspace` |

---

## 4. Quick Verification Checklist

1. **Pre-Boot Launcher & `[Esc]` Settings:** Verify `ogre_battle.sfc` is detected, toggle profiles/settings, and confirm `ogre_battle.ini` persists across restarts.
2. **16:9 Wings Context Switching (`[F10]`):** Verify Title/Menus show clean tapestry borders, Warren's Quiz shows Mod/Seed & Lord Archetype, World Map shows Zodiac & 18-Hero Auditor, Tactical Map shows Deployed Squads & Reputation/Inspector/Radar, and Combat shows Clash Tug-of-War & Tarot Guard Dock.
3. **Mouse Control:** Verify 1:1 cursor tracking on the Tactical Map, stage banner highlighting on the World Map, direct slot selection in the 7-icon bar / 3×2 formation grid, and instant keyboard handoff.
