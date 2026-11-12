# Ogre Battle PC Port: Windows Preview Executable & Testing Guide

**Executable Target**: `ogre_battle.exe` (or `bin/ogre_battle.exe`)  
**Version**: Milestone 4 Build — **Rev 9 (Gate 2: Three-Pillar Direct-State & Hit-Box Mouse Architecture)**  
**Binary Architecture**: x86-64 PE32+ Windows GUI Subsystem (`-Wl,--subsystem,windows`)  
**Dependencies**: **0 external DLLs** (pure Win32 GDI, `waveOut` 32,040 Hz stereo audio, multimedia timer)  
**ROM Payload**: Embedded clean certified ROM (auto-fallback to external `ogre_battle.sfc` if placed alongside)  
**Binary MD5**: `26d083b07ab6d7e33268b856bcefd9da`  
**Binary SHA1**: `6e62fb02cadee188fecd2df95e00ee31ca8c8c94`  
**Deprecated Legacy Builds**: `Rev 5` (`c944bd95fa981705b5c51d92833a2ff9`) and `Rev 8` (`73658652c2429cf553cfbd40de2aedc5`) — retired due to synthetic D-Pad feedback loops (see [`docs/mouse_architecture_deprecation_and_redesign.md`](file:///home/antigravity/hoyajavis/ogre-battle-pc/docs/mouse_architecture_deprecation_and_redesign.md)).

> [!IMPORTANT]
> **Rev 9 Architectural Upgrade — Three-Pillar Direct-State & Hit-Box Mouse Control**:
> Legacy builds (`Rev 1`–`Rev 8`) attempted to steer the cursor by injecting synthetic D-Pad button presses (`BTN_UP/DOWN/LEFT/RIGHT`), which caused runaway camera scrolling outside the center rectangle on the Tactical Map and wrap-around spinning in the 7-icon command bar. **Rev 9 completely eliminates synthetic D-Pad position steering** and introduces three context-aware pillars:
> 1. **Pillar 1 — Tactical Battlefield Map (1:1 Direct-State Cursor & Decoupled Camera)**:
>    - Moving the mouse moves the battlefield gauntlet cursor **1:1 across the entire `256 × 224` viewport** (`WRAM $14DE / $14E0`) and synchronizes world raycast coordinates (`WRAM $14E2 / $14E4`) on the same frame.
>    - **Magnetic Entity Snapping ($\pm 8\text{px}$)**: Hovering within 8 pixels of a Deployed Squad (`$7E:18AF / $7E:18D9`) or City/Temple (`$7E:1A95 / $7E:1B0D`) magnetically snaps the cursor onto the target.
>    - **Decoupled Camera Panning (`WRAM $00BD / $00BF`)**: Moving the mouse inside the screen **never** triggers runaway camera scrolling. Pan the camera intentionally via **Right-Click Drag**, **Middle-Click Drag**, holding the pointer in the **narrow 10px window edge margin**, or pressing keyboard **Arrow / WASD** keys.
> 2. **Pillar 2 — Popup Menus, 7-Icon Bar & 3×2 Formation Grid (Deterministic Hit-Box Indexing)**:
>    - **7-Icon Horizontal Command Strip (`X = 71..183, Y = 107..131`)**: Hovering directly over any of the 7 command icons immediately highlights that exact slot (`WRAM $0474 = 0..6`). Moving the mouse outside the icon strip preserves your selection with **zero wrap-around spinning**.
>    - **3×2 Unit Formation Grid (`X = 4..72, Y = 40..88`)**: Hovering over any of the 6 unit slots in the formation box selects that cell directly.
> 3. **Pillar 3 — Continental World Map (Stage Node Hit-Testing & Panning)**:
>    - Hovering over stage banners on the Zenobian continental map selects the hovered stage node directly; Right-Click drag or 10px edge margins pan the continent view.

---

## 1. Quick Start

1. Download `ogre_battle.exe` directly to your Windows PC.
2. Double-click **`ogre_battle.exe`** to launch.
3. The game starts in a clean 4:3 native 1024x896 window (resizable).
4. Progress automatically persists to `ogre_battle.srm` in the same directory every 5 seconds and on exit.

---

## 2. Controls & Input Mapping

### Mouse Controls (Gate 2 Three-Pillar Architecture)

| Mouse Action | Context / Pillar | In-Engine Behavior |
| :--- | :--- | :--- |
| **Mouse Move (Interior)** | **Pillar 1: Tactical Map** | Moves battlefield cursor 1:1 (`$14DE/$14E0`) with $\pm 8\text{px}$ snap to squads/cities; camera stays still |
| **Right-Click Drag / Middle-Click Drag** | **Pillar 1 & 3: Tactical / World Map** | Pans Mode-7 camera (`$00BD/$00BF`) 1:1 with mouse drag delta |
| **Mouse at Window Edge (10px margin)** | **Pillar 1 & 3: Tactical / World Map** | Smoothly pans camera toward the hovered screen border |
| **Mouse Hover over Icon / Cell** | **Pillar 2: 7-Icon Bar / 3×2 Grid** | Directly indexes hovered icon (`0..6` in `$0474`) or formation slot (`0..5`); no wrap-around when outside |
| **Mouse Hover over Stage Banner** | **Pillar 3: Continental World Map** | Highlights hovered stage node banner |
| **Left Click** | **All Screens** | **Button A** (`X`) — Confirm selection, deploy unit, advance dialogue, inspect target |
| **Right Click (Tap without Drag)** | **All Screens** | **Button B** (`Z`) — Cancel / back out of menus, close command ring |

### Canonical ZSNES Keyboard Layout (Joypad 1)

| SNES Button | Windows Key | Role in Ogre Battle |
| :--- | :--- | :--- |
| **D-Pad Up** | **Up Arrow** ($\uparrow$) / **Numpad 8** | Move cursor up / select menu option |
| **D-Pad Down** | **Down Arrow** ($\downarrow$) / **Numpad 2** | Move cursor down / select menu option |
| **D-Pad Left** | **Left Arrow** ($\leftarrow$) / **Numpad 4** | Move cursor left / decrease value |
| **D-Pad Right** | **Right Arrow** ($\rightarrow$) / **Numpad 6** | Move cursor right / increase value |
| **A Button** | **X** | Confirm selection / deploy unit / inspect town |
| **B Button** | **Z** | Cancel / close menu / back out |
| **X Button** | **S** | Camp / tactical overview menu |
| **Y Button** | **A** | Unit card details / character stat inspection (hold + D-Pad for camera pan) |
| **L Shoulder** | **D** | Fast scroll tactical map left / page up |
| **R Shoulder** | **C** | Fast scroll tactical map right / page down |
| **Start** | **Enter** | Advance dialogue / pause / stage briefing |
| **Select** | **Space** or **Shift** | Toggle card info / view help text |
| **Quit** | **Escape** | Clean exit with immediate SRAM battery commit |

---

## 3. Three-Pillar Verification Checklist

1. **Pillar 1 — Tactical Map 1:1 Cursor & Decoupled Camera**:
   - Move the mouse across the entire tactical battlefield (`X = 8..247, Y = 8..215`) and verify the cursor tracks 1:1 without getting trapped in an inner rectangle or causing runaway camera scrolling.
   - Hover near a deployed squad or town and verify the cursor snaps cleanly ($\pm 8\text{px}$).
   - Right-click and drag (or move within 10px of the screen edge) to verify smooth, intentional camera panning.
2. **Pillar 2 — 7-Icon Command Strip & 3×2 Formation Grid**:
   - Open the 7-icon horizontal command bar (`Y = 111..127`) and sweep across icons `0..6` (`X = 71..183`). Move the mouse outside the bar (e.g., top-right corner) and verify the cursor stays on the last hovered icon with **zero wrap-around spinning**.
   - In the Army Camp / Edit Units screen, hover over each of the 6 cells in the 3×2 formation box (`Cols {6, 38} × Rows {48, 64, 72}`) and verify instant slot selection.
3. **Pillar 3 — Continental World Map & Hybrid Handoff**:
   - On the World Map between stages, hover over stage banners to select nodes and Right-drag to pan.
   - Press any keyboard arrow key at any time to verify instant keyboard takeover, and move the mouse (`> 2px`) to resume pointer control.
