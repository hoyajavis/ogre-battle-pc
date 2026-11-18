# Gate 3 Architectural Specification: 4:3 to 16:9 Widescreen Display & Area 1 Telemetry Wing Integration

> **Status:** Certified & Merged (Gate 3 — Tag `v0.3.0-gate3-wide`)  
> **Related Documents:** [plan.md](../archive/plan.md) | [roadmap.md](../archive/roadmap.md) | [ogre_battle_modernization_areas.md](../archive/ogre_battle_modernization_areas.md) | [mouse_architecture_deprecation_and_redesign.md](../archive/mouse_architecture_deprecation_and_redesign.md)

---

## 1. Executive Summary & Architectural Alignment

Transitioning *Ogre Battle: The March of the Black Queen* from **4:3 (`256 × 224` internal / `1024 × 896` window)** to **16:9 (`400 × 224` internal / `800 × 448` `2×` master compositor / `1600 × 896` window)** unifies three core subsystems:

1. **7-Screen Widescreen PPU & Background Layer (`400 × 224` Logical Grid)**:
   - Every game screen utilizes the `400 × 224` (`50 × 28` 8×8 tiles) widescreen viewport across two user-toggleable (`[F10]`) modes:
     - **Mode 1 — Vanilla Widescreen (`OB_DISPLAY_16_9_VANILLA_HORIZON`)**: Fills the extra `+144 px` (`+72 px` / `9` tile columns per side) with extended Mode-7 affine terrain, scrolling BG1/BG2/BG3 VRAM tilemaps, or seamless Zenobian stone/parchment borders.
     - **Mode 2 — Tactician Wing HUD (`OB_DISPLAY_16_9_TACTICIAN_WINGS`)**: Populates the **Left Wing** and **Right Wing** with context-sensitive Area 1 telemetry and Area 2/3/4 controls rendered using the authentic **Area 1 SNES UI Software Rasterizer** (`include/ob_snes_ui_theme.h` & `src/engine/snes_ui_rasterizer.c`).
2. **Master `800 × 448` (`2×` Integer Tile Grid) Post-PPU Compositor**:
   - At `1×` native resolution (`400 × 224`), each `72 px` wing is only `9` tiles wide—leaving just `56 px` (`7` characters of an `8×8` font) inside an `8×8` 9-slice gold border.
   - Upscaling the `400 × 224` PPU output by `2×` nearest-neighbor into an **`800 × 448` (`100 × 56` `8×8` tiles) master canvas** before running the SNES UI rasterizer gives each wing **`144 × 448 px` (`18 × 56` `8×8` tiles)** (`128 px` interior width = **`16` characters of `8×8` SNES font** or **`21` characters of `6×8` compact shadowed font**).
3. **Migration of Area 1 Telemetry from a Separate `640 × 480` Window into Context-Switched 16:9 Wings**:
   - 9 of the 12 Area 1 telemetry modules migrate directly into vertical `144 × 448 px` Wing Cards that switch automatically based on the active screen (`Screen 1..7`) and hovered mouse target (`OB_SNAP_CITY`, `OB_SNAP_SQUAD`, or terrain).
   - Full-campaign reference tables (all 18 Special Heroes, all 12 Zodiac Stones, Promotion Trees, and the 2,344-bit Event Diff stream) are accessible in-window at any time via the **`[Tab]` Zenobian Grimoire Overlay**, while retaining `--companion-window` as an optional dual-monitor purist mode.

---

## 2. Master Compositor Geometry (`800 × 448` / `2×` Tile Grid)

| Metric | Native `1×` SNES Grid (`400 × 224`) | Post-PPU `2×` Master Canvas (`800 × 448`) | Window Output (`1600 × 896` @ `4×`) |
| :--- | :--- | :--- | :--- |
| **Left Wing Span** | `X: 0..71` (`72 × 224 px` / `9 × 28` tiles) | **`X: 0..143` (`144 × 448 px` / `18 × 56` tiles)** | `288 × 896 px` |
| **Center Core Span** | `X: 72..327` (`256 × 224 px` / `32 × 28` tiles) | **`X: 144..655` (`512 × 448 px` / `64 × 56` tiles)** | `1024 × 896 px` |
| **Right Wing Span** | `X: 328..399` (`72 × 224 px` / `9 × 28` tiles) | **`X: 656..799` (`144 × 448 px` / `18 × 56` tiles)** | `288 × 896 px` |
| **Interior Wing Width** | `56 px` (`7` chars @ `8×8`) | **`128 px` (`16` chars @ `8×8` / `21` chars @ `6×8`)** | Scaled 2× cleanly |

---

## 3. Screen-by-Screen Wing Allocation & Telemetry Migration

| Screen (`ObSceneId`) | Base Layer (`400 × 224` PPU / Fill) | Left Wing (`144 × 448 px` / `18 × 56` Tiles) | Right Wing (`144 × 448 px` / `18 × 56` Tiles) |
| :--- | :--- | :--- | :--- |
| **1. `OB_SCENE_WARREN_QUIZ`** | Extended Seer's Sanctum starry sky & candlelit tapestry | **Boot-Time Mod, Rule & Seed Card** (`Area 4` + `[Re-Draw 6 Cards]` button) | **Lord Archetype Decoder** (`Area 1` Pg3 Q3: live `STR/INT/ALI/CHA/CF` & class preview) |
| **2. `OB_SCENE_WORLD_MAP`** | Panoramic Continental Map of Zenobia (+56% width) | **Campaign Readiness & 12 Zodiac Stones** (`Area 1` Pg3 Q2: `4×3` gem socket grid + Brunhild status) | **Stage Recon & 18-Hero Dossier** (`Area 1` Pg3 Q1: stage boss level, PoIs, Tristan/Rauny/Deneb/Galf alerts) |
| **3. `OB_SCENE_TACTICAL_MAP`** | Extended Mode-7 affine scanlines (`X: 0..399`), looped HDMA sky, widened OAM clip | **Interactive Deployed Squad Dock** (`Area 1` Pg1 Q4 + `Area 2`: up to 10 squad plates with HP, AI order, Mobility badge, 1-click camera jump) | **Tactical Telemetry Stack**:<br/>• *Top*: **CF Gauge, Noon Goth & Solar Clock** (Pg1 Q1)<br/>• *Mid*: **Dynamic Target Inspector** (Town Compat Pg1 Q3 / Pre-Clash Drift Pg2 Q3 / Neutral Matrix Pg2 Q4)<br/>• *Bot*: **2D Spatial Radar & `-5 CF` Recapture Alert** (Pg1 Q2) |
| **4. `OB_SCENE_COMBAT_STAGE`** | Extended BG2 parallax background (`64×32` VRAM) + 3-metatile BG1 platform edges | **Clash Telemetry & Drift Stack**:<br/>• *Top*: **Clash Tug-of-War Bar** (Pg2 Q2)<br/>• *Mid*: **Live Morality Kill Drift** (Pg2 Q3)<br/>• *Bot*: **AGI Initiative Queue** | **Tactic Stance & Tarot Guard Dock**:<br/>• *Top*: 4 Tactic Stance pills (`[Q]LDR [W]STR [E]WEK [R]BST`)<br/>• *Main*: **Interactive Tarot Hand** (Pg2 Q1) with `16×24` cards & **`! LORD OVERLEVEL !`** warnings |
| **5. `OB_SCENE_CAMP_ROSTER`** | Zenobian Stone & Parchment tapestry border (Vanilla) or 3-Column Workbench | **Barracks & Squad Mobility Advisor** (`Area 3` + `Area 1` Pg1 Q4 flyer upgrade calculator) | **Mod-Aware Bank `$09` Promotion & Relic Inspector** (`Area 1` Pg3 Q4 + `Area 3` equipment diffs) |
| **6. `OB_SCENE_SHOP_TEMPLE`** | Extended town/temple backdrop & outward-shifted portraits | **Shop Bulk Restock & Inventory Card** (`Area 2` `x1 / x5 / Restock Kit`) | **Equipment Compatibility & Tarot Dual-Outcome Card** (`Area 1` absorb stat vs. battle effect) |
| **7. `OB_SCENE_EPILOGUE`** | Uncropped `400 × 224` Mode-7 credits horizon & Tarot tableau | **13-Ending Condition Audit** (`Area 1`: exact WRAM flags & nearest alternate ending) | **Campaign Hall of Fame & Seed Verification Stamp** (`Area 1` + `Area 4` manifest hash) |

---

## 4. Scene State Machine & Tactical Wing Hysteresis (`Gate 3E` & `Gate 3F`)

To prevent false-positive frame-to-frame scene switches and rapid side-wing card flickering during live gameplay, [`src/engine/widescreen.c`](../../src/engine/widescreen.c) and [`src/engine/input.c`](../../src/engine/input.c) enforce two layers of hardware-verified filtering:

### 4.1 Persistent Hardware Scene Discriminators (`ob_widescreen_detect_scene`)
Rather than reading volatile Direct-Page scratch bytes (`$7E:0010`) or VBlank NMI transfer command indices (`$7E:00CA`, which pulses between `0x03`, `0x04`, and `0x0C` during VBlank DMA transfers), live scene classification is anchored on three persistent WRAM domains verified across all `83,450` canonical trace frames:

1. **Pre-Campaign Boot, Intro Demo & Title Menu (`OB_SCENE_TITLE_BOOT`)**:
   - In LakeSnes, `$7E:07BA` (Opinion Leader roster slot `0` template ID) remains `0x55` from cold reset through the entire intro cinematic and title menu (`Frames 0..3,466` of `trace_02`), even after `$7E:1578` (`Goth`) is preset to `30,000` (`0x00007530`) at Frame `3,097`. Any frame with `$7E:07BA == 0x55` unconditionally resolves to `OB_SCENE_TITLE_BOOT`.
2. **Warren's Seer Tent & Tarot Creation (`OB_SCENE_WARREN_QUIZ`)**:
   - At Frame `3,467`, entering Warren's Tent clears the 100-unit roster template table (`$7E:07BA..$7E:081D`) to `0xFF`.
   - While `$7E:07BA == 0xFF`, Master Module `$7E:00CB == 0x02` (Name & Birthday Entry) or `$7E:00CB == 0x03` with sub-step `$7E:00CC < 0x0B` (`0x00..0x0A`, the 6 Tarot Questions and Lord Archetype Summary) resolves to `OB_SCENE_WARREN_QUIZ`.
3. **Continental World Map & Save Menus (`OB_SCENE_WORLD_MAP`)**:
   - When Warren's Quiz transitions to the Continental Map of Zenobia (`Frame 7,801`), `$7E:00CB == 0x03` advances to `$7E:00CC >= 0x0B` (`0x0B..0x10`).
   - Once the Opinion Leader is written into `$7E:07BA` (`0x4F`) on the World Map (`Frame 8,546+`), any World Map module state—`$7E:00CB` in `{0x02 (Command Bar), 0x03 (Stage Select), 0x05 (Data Menu), 0x06 (Save Slot Menu)}` or `($00CB == 0x00 && $00CC == 0x10)`—with inactive Deployed Squad 0 (`$7E:18AF` in `{0x5555, 0xFFFF, 0x7FFF, 0x0000}`) resolves to `OB_SCENE_WORLD_MAP`.
4. **Combat Stage (`OB_SCENE_COMBAT_STAGE`) vs. Tactical Overland Map (`OB_SCENE_TACTICAL_MAP`)**:
   - Cumulative clash damage registers (`$7E:F942` player, `$7E:F944` enemy) **persist in WRAM after a battle ends** and execution returns to the Tactical Map.
   - Consequently, live `OB_SCENE_COMBAT_STAGE` detection requires either combat module `$7E:00CB` in `{0x07, 0x0C}` or an active combat phase flag (`$7E:F92B != 0 && $7E:F92B != 0x55`) paired with **remaining actions in the current round (`$7E:F941` in `1..20`)**.
   - All stage frames with `$7E:00CB == 0x01` or active deployed Squad 0 coordinates (`$7E:18AF <= 4096`) resolve cleanly to `OB_SCENE_TACTICAL_MAP` regardless of camera-pan state (`$7E:00CE == 3`) or marching cursor suppression (`$7E:14E6 == 0`).

### 4.2 Schmitt-Trigger Spatial & Temporal Widget Hysteresis (`ob_widescreen_extract_telemetry`)
On the Tactical Map, three independent hysteresis mechanisms keep side-wing cards steady during live marches and camera movement:
- **Magnetic Target Snap Hysteresis (`src/engine/input.c`)**: Enters squad/city magnetic snap at **`±8 px`** (`OB_MAGNETIC_SNAP_RADIUS_PX`) and retains the currently snapped target up to **`±12 px`** (`OB_MAGNETIC_KEEP_RADIUS_PX`), preventing boundary jitter when the cursor rests on the edge of a city or moving squad.
- **45-Frame (`0.75s`) Sticky Target Inspector Hold**: When the cursor snaps to a city (`OB_INSPECT_CITY_LIBERATION`) or enemy squad (`OB_INSPECT_ENEMY_PRECLASH`), `ObWidescreenState` latches `sticky_inspector_mode`, `sticky_city_id`, and `sticky_enemy_slot` with `inspector_hold_frames = 45`. Moving the cursor across open terrain holds the inspected card for 45 frames before returning to `OB_INSPECT_MOBILITY_NEUTRAL` (*Terrain & March*), while hovering a different city or enemy switches immediately.
- **Debounced `-5 CF` Recapture Threat Alert**: Filters out un-deployed entity coordinates (`0x7FFF`, `0xFFFF`, `0x5555`, `> 4096`), requires an enemy squad (`slots 10..20`) to remain within **`180 px`** Manhattan distance of a liberated city for **`15` consecutive frames** (`threat_on_frames >= 15`) before raising the red alert card, and holds the alert active until the enemy moves beyond **`210 px`** (or is defeated) for **`15` consecutive frames**.

