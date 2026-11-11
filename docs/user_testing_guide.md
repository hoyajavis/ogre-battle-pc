# Ogre Battle PC Port: Windows Preview Executable & Testing Guide

**Executable Target**: `ogre_battle.exe` (or `bin/ogre_battle.exe`)  
**Version**: Milestone 4 Build — Rev 5 (Gate 2: Direct-State Mouse Control & Hybrid Input Integration)  
**Binary Architecture**: x86-64 PE32+ Windows GUI Subsystem (`-Wl,--subsystem,windows`)  
**Dependencies**: **0 external DLLs** (pure Win32 GDI, `waveOut` 32,040 Hz stereo audio, multimedia timer)  
**ROM Payload**: Embedded clean certified ROM (auto-fallback to external `ogre_battle.sfc` if placed alongside)  
**Binary MD5**: `c944bd95fa981705b5c51d92833a2ff9`

> [!NOTE]
> **Rev 5 Updates (Gate 2: Direct-State Mouse Control & Hybrid Input Layer)**:
> 1. **Screen-to-SNES Coordinate Mapping**:
>    - Window mouse coordinates $(x, y)$ are accurately converted to SNES viewport coordinates $[0..255, 0..223]$ across all window sizes, aspect-ratio letterboxing, and pillarboxing.
> 2. **Direct-State Tactical Cursor Steering**:
>    - When on the tactical map (tracked via in-engine cursor state `$14E7` and coordinates `0x7E:00BD` / `0x7E:00BF`), moving the mouse automatically steers the in-game gauntlet cursor directly toward the host pointer at full hardware speed.
> 3. **Click Injection**:
>    - **Left Click**: Dispatches **Joypad Button A** (Confirm selection, advance dialogue, deploy unit, inspect town/unit).
>    - **Right Click**: Dispatches **Joypad Button B** (Cancel, close menu, back out, open tactical camp menu).
> 4. **Seamless Hybrid Input Priority**:
>    - Gamepad and keyboard arrow keys take immediate exclusive priority the instant any movement key is pressed.
>    - Moving the mouse smoothly resumes mouse navigation with zero input collisions or sticky state.

---

## 1. Quick Start

1. Download `ogre_battle.exe` directly to your Windows PC.
2. Double-click **`ogre_battle.exe`** to launch.
3. The game starts in a clean 4:3 native 1024x896 window (resizable).
4. Progress automatically persists to `ogre_battle.srm` in the same directory every 5 seconds and on exit.

---

## 2. Controls & Input Mapping

### Mouse Controls (Gate 2 Active Integration)

| Mouse Action | In-Engine Action | Functionality |
| :--- | :--- | :--- |
| **Mouse Move** | Tactical Cursor Steering | Steers the tactical gauntlet cursor directly to target map positions |
| **Left Click** | **Button A** (`X`) | Confirm selection, deploy unit, advance dialogue, inspect target |
| **Right Click** | **Button B** (`Z`) | Cancel / back out of menus, open tactical overview |

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
| **Y Button** | **A** | Unit card details / character stat inspection |
| **L Shoulder** | **D** | Fast scroll tactical map left / page up |
| **R Shoulder** | **C** | Fast scroll tactical map right / page down |
| **Start** | **Enter** | Advance dialogue / pause / stage briefing |
| **Select** | **Space** or **Shift** | Toggle card info / view help text |
| **Quit** | **Escape** | Clean exit with immediate SRAM battery commit |

---

## 3. Feedback & Evaluation Checklist

1. **Tactical Cursor Navigation**:
   - On the tactical map and in menus, test pointing and clicking with the mouse to move units and confirm orders.
2. **Hybrid Swapping**:
   - Alternate freely between Arrow keys and mouse movement to verify smooth, instant handoff between devices.
3. **Audio & Color Integrity**:
   - Confirm colors remain 100% faithful and audio remains clean and glitch-free.
