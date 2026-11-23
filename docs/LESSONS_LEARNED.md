# Lessons Learned & Retro Porting Post-Mortem: *Ogre Battle: The March of the Black Queen*

This document synthesizes the engineering, reverse-engineering, UX modernization, testing, and workflow lessons learned while building a native 1:1 PC port of Quest's 1993 Super Nintendo classic, ***Ogre Battle: The March of the Black Queen*** (`LoROM 12Mbit / 1.5MB`, SHA-1 `cfc45162b91791a61d4260e348ad43cb3b2eca0f`).

It is written for four overlapping audiences:
1. **SNES Curious & Modders** who want to understand how *Ogre Battle (1993)* actually works under the hood (Part 2).
2. **Retro PC Porting Engineers** comparing static recompilation, decompilation, and hybrid runtime architectures (Parts 1 & 3).
3. **UX & Engine Modernization Designers** adding 16:9 widescreen, mouse controls, read-only telemetry, or mod loaders to retro games without breaking deterministic simulation (Part 4).
4. **AI-Assisted & Agentic Development Teams** using version control gates, worktrees, headless trace oracles, and multi-session handoffs on complex systems projects (Parts 5 & 6).

---

## Table of Contents

- [Part 1: The Three Attempts & Overcoming the "Zelda Illusion"](#part-1-the-three-attempts--overcoming-the-zelda-illusion)
- [Part 2: Inside *Ogre Battle (1993)* — How the SNES Game Actually Works](#part-2-inside-ogre-battle-1993--how-the-snes-game-actually-works)
- [Part 3: Static Recompilation, Tiered Execution & Headless Trace Oracles](#part-3-static-recompilation-tiered-execution--headless-trace-oracles)
- [Part 4: Planning & Implementing Retro Modernizations Without Breaking the Game](#part-4-planning--implementing-retro-modernizations-without-breaking-the-game)
- [Part 5: Version Control, Sequential Gates & Agentic Development](#part-5-version-control-sequential-gates--agentic-development)
- [Part 6: The 10-Point Blueprint for Future Retro PC Ports](#part-6-the-10-point-blueprint-for-future-retro-pc-ports)

---

## Part 1: The Three Attempts & Overcoming the "Zelda Illusion"

### 1.1 Why It Took Three Attempts
This repository is the **third** distinct attempt to bring *Ogre Battle: The March of the Black Queen* natively to PC. Each failed attempt exposed a fundamental trap in retro game porting:

| Attempt | Approach | What Worked | Why It Hit a Wall |
| :--- | :--- | :--- | :--- |
| **Attempt 1** | **Disassembly & Static Recompilation into Rust (`romatlas`)** | Mechanical disassembly and initial control-flow lifting of 65816 banks. | Pure ahead-of-time 65816 lifting into standalone Rust without an embedded cycle-accurate hardware runtime hit a wall on dynamic `REP`/`SEP` register-width (`M`/`X`) switches across branches, indirect jump tables (`JMP ($xxxx,X)`), hardware MMIO math (`$4202 * $4203`), and NMI-driven main-loop timing. |
| **Attempt 2** | **Pygame Reimplementation from Community Documentation** | Core RPG/RTS game logic (unit stats, squad movement, combat formulas) worked notionally. | Graphics rendering was completely defeated. Reimplementing the SNES PPU from scratch—specifically Mode-7 affine perspective horizons, per-scanline HDMA sky gradients, color-math window masks, and OAM sprite priority layering—proved unsustainable. |
| **Attempt 3 (This Repo)** | **Hybrid `snesrecomp` + `snesrev` Oracle + Custom 16:9 Engine** | Combines cycle-accurate silicon emulation (LakeSnes PPU/APU/DMA) with 723 statically lifted C subroutines (`libob_recomp.a`), selective interpreter fallback for NMI-heavy banks, a frame-by-frame `memcmp` lockstep oracle (`runner/`), and a custom `800×448` 16:9 SDL2 compositor. | **Succeeded** with 0-byte memory drift across 83,450 canonical frames. |

### 1.2 The "Zelda Illusion" (Decompiling Famous Games vs. Undocumented Games)
When developers look at landmark SNES ports like [`snesrev/zelda3`](https://github.com/snesrev/zelda3) (*A Link to the Past*) or [`snesrev/smw`](https://github.com/snesrev/smw) (*Super Mario World*), it is easy to assume they were built by reverse-engineering a raw `.sfc` ROM into clean C from scratch.

In reality, those projects stood on **20+ years of exhaustive community disassemblies** where ~90% of WRAM variables, state machines, and subroutines were already named and documented. When we surveyed the public *Ogre Battle* reverse-engineering ecosystem at the start of this project ([`docs/archive/gap_analysis.md`](archive/gap_analysis.md)), we found the opposite:
- The only public disassembly repo (`BacteriaMage/ogre-battle-disassembly`) had labeled **only 1 vector** (the `$00:8000` Reset vector) and contained zero WRAM maps.
- *Ogre Battle* is a 1.5 MB LoROM cartridge with ~1,500–2,500 subroutines. Attempting to manually decompile unnamed 65816 assembly (`g_ram[0x1842] = g_ram[0x05F2] + 4;`) into idiomatic C function-by-function would have stalled indefinitely.

> **Lesson 1:** Never confuse **porting/execution** with **human-readable decompilation**. For a game without an existing community disassembly, mechanically lift the ROM into opcode-level C (`src/gen/ob_bank_*.c`) first so the game boots on Day 1, build an automated lockstep test oracle, and only reverse-engineer the specific high-value memory structures and subroutines required for your modernizations.

---

## Part 2: Inside *Ogre Battle (1993)* — How the SNES Game Actually Works

Reverse-engineering *Ogre Battle* for telemetry, mouse input, widescreen, and modding revealed how Quest engineered a real-time strategy game on a 3.58 MHz 16-bit CPU.

### 2.1 How the Whole Campaign Fits in 128 KB of WRAM (`$7E:0000`–`$7F:FFFF`)
Unlike modern RPGs that store characters as arrays of structs (`AoS`), *Ogre Battle* heavily uses **Structure-of-Arrays (`SoA`)** and parallel byte tables in Bank `$7E` so 8-bit/16-bit index registers (`X` and `Y`) can step through rosters without multiplication ([`docs/architecture/developer_guide_area_1_telemetry.md`](architecture/developer_guide_area_1_telemetry.md)):
- **100-Character Army Roster (`$7E:1F07`–`$7E:3220`):** Parallel arrays indexed by roster slot `0..99` store Class ID, Level, current/max HP, `STR`, `AGI`, `INT`, `CHA` (`0–100`), `ALI` (`0–100`), `LUK`, equipment slots, and squad assignment.
- **25 Deployed & Reserve Squads:** Parallel coordinate tables store Deployed Squad World X (`$7E:18AF + 2*i`) and World Y (`$7E:18D9 + 2*i`) in **12.4 fixed-point subpixels** (`world_px = raw >> 4`; e.g., Stage 1 Squad 0 at world `(244, 360)` is stored as `(3904, 5760)`), alongside Bank `$00`'s Mode-7 perspective-projected screen coordinates at `$7E:14ED + 2*i` (Screen X) and `$7E:1517 + 2*i` (Screen Y), with `0x7FFF` and `0xFFFF` (plus cold-boot `0x5555`) marking inactive/undeployed slots.
- **20 Stage Cities & Temples:** Stored in parallel 12.4 fixed-point subpixel coordinate arrays at `$7E:1A95 + 2*j` (World X) and `$7E:1B0D + 2*j` (World Y) (`world_px = raw >> 4`) using `0x7FFF`/`0xFFFF` for unused stage slots, paired with ROM table records at `0x2E8C2` (`9 bytes/city`: name pointer, population, morale/alignment compatibility, shop ID, and base flag).
- **2,344-Bit Story & Liberation Event Stream:** Quest packed campaign progression—which of the 18 Special Heroes were recruited, which of the 12 Zodiac Stones were collected, which cities are liberated, and which hidden triggers fired—into dense bitfields across WRAM.
- **Battle Clash Tug-of-War (`$7E:F942` vs. `$7E:F944`, gated by `$7E:F92B` & `$7E:F941`):** Combat outcomes are not decided purely by "who loses more HP%"—the engine maintains explicit 16-bit offensive/defensive damage accumulators (`$7E:F942`/`$7E:F944`) in high Bank `$7E` during each clash. Because those accumulators are not cleared when returning to the tactical map, active combat must be gated by the combat state flag (`$7E:F92B`) and remaining round actions counter (`$7E:F941` in `1..20`).

### 2.2 The Mode-7 Tactical Map & Cursor-Camera Coupling (`$00:B1E0`–`$00:B6A6`)
Disassembling Bank `$00` ([`docs/archive/mouse_architecture_deprecation_and_redesign.md`](archive/mouse_architecture_deprecation_and_redesign.md)) revealed why the overland map feels unique—and why naive mouse injection breaks it:
1. **Screen Offset vs. World Position:** The cursor does not move directly in world space. Joypad D-Pad bits (`$A8`) accelerate (`1..5 px/frame` via `$14DD`) a **Screen-Space Offset** (`WRAM $14DE` X, `$14E0` Y).
2. **The Inner Clamp Box (`[8..231, 8..199]`):** At `$00:B283`, the game clamps `$14DE` to `[8, 231]` and `$14E0` to `[8, 199]`. The moment the cursor touches that inner box border, the CPU executes `TSB $14E7` (`0C E7 14`), setting bit 0 (X edge) or bit 1 (Y edge).
3. **Mode-7 Raycast (`$00:B2FC` -> `JSR $CBAE`):** The engine combines the screen offset (`$14DE`, `$14E0`) with the Mode-7 camera scroll registers (`WRAM $00BD` X, `$00BF` Y) and zoom factor (`$14BB`) to compute **Cursor World Coordinates** (`WRAM $14E2` X, `$14E4` Y), then builds a `16×16 px` hit-box (`$18..$1E`) to test squads (`$14ED`/`$1517` screen projections at `$00:B376`–`$00:B445`) and cities.
4. **Camera Scroll Trigger (`$00:B590`–`$00:B6A6`):** Only when `$14E7 != 0` *and* a D-Pad bit is held in `$A7` does `$00:B64A` add `±6` (scaled by zoom `$14BB`) to the Mode-7 camera (`$00BD`/`$00BF`).

### 2.3 Three Completely Different UI Physics Models
Across a single play session, *Ogre Battle* switches between three incompatible cursor architectures:
1. **Tactical Battlefield Map:** Continuous 2D viewport cursor (`$14DE`/`$14E0`, `OAM[1]` tile `0x64` sword or `0x66` waypoint flag) coupled to a Mode-7 affine camera (`$00BD`/`$00BF`).
2. **Popup Command Bars & Formation Grids (`$02:EC90`–`$02:F190`):** Discrete 1D/2D slot indexers driven by `OAM[1]` (`WRAM $0104..$0107`) and dynamic slot tables at `WRAM $0424` (slot count), `$0426 + i` (slot X), `$0446 + i` (slot Y), and `$04B2 + i` (slot type: `< 0x80` command icon, `0x80` header, `0xFF` formation grid cell).
   - At `$02:ECD2` and `$02:ED1C`, Bank `$02` inspects `$04E0`: on the **Camp screen (`$04E0 == 3`)**, `OAM[1]` uses tiles `0xCE` (icon bar) and `0xCC` (formation grid); on the **Battle Map (`$04E0 != 3`)**, `OAM[1]` uses tiles **`0x6A`** (icon bar finger, offset `(+4, +10)` from `$0426`/`$0446`) and **`0x68`** (formation grid finger, offset `(-10, 0)` from `$0426`/`$0446`).
   - Battle-map menus dynamically populate `$0424` with anywhere from 2 slots (tutorial confirm/cancel prompt at `X = {112, 128}, Y = 112`) to 9 combined slots (5 formation units + 3 command icons at `X = {103, 119, 135}, Y = 109` + 1 header). Moreover, because the idle menu loop at `$02:ED75 -> $02:EC9A` calls `JSR $F9B2` (VBlank wait) *before* reading `LDY $0474` at `$02:EC9D`, host mouse hover must update `$0474`, `$0476`/`$0477`, `$04F0`/`$04F1`, and `OAM[1]` (`$0104`–`$0106`) together before `snes_runFrame()` for zero-latency visual response.
3. **Continental World Map (Between Stages):** Fills the shadow OAM slice `WRAM $0100..$013F` with off-screen sentinels (`01 E0 01 E0`, `Y = 224`) while DMA-transferring stage node banners (`tiles 0x80..0x8C`) into hardware OAM (`OAM[25..30]`).

### 2.4 Hidden 1993 Engine Quirks & ROM Data Architecture
Decompiling the ROM tables and community patches ([`docs/architecture/rhdn_patches_catalog.md`](architecture/rhdn_patches_catalog.md), [`docs/verification/gate_4a_certification.md`](verification/gate_4a_certification.md)) uncovered fascinating details about the original 1993 code:
- **The Vanilla Enemy Magic AI Bug (`$01:8F8B`):** When an enemy spellcaster (e.g., Doll Mage or Liches) evaluates which player unit to target with elemental magic, the 1993 code accidentally indexes the player's **Physical** armor resistance (`$7E:F174,X`) instead of the spell's **Elemental** resistance. (Community hacker *D* fixed this with a 66-byte hook into Bank `$30`, now available as a built-in toggle in our Pre-Boot Launcher.)
- **Bitwise Class Size Hardcoding (`$01:EC67`):** Rather than storing unit size (1-slot Small vs. 2-slot Large Beast/Dragon) in a clean table byte, the vanilla engine used hardcoded class-ID range checks and bitshifts at `$01:EC67`—which is why adding new monster classes required rewriting `$01:EC67` to read a lookup table in Bank `$30`.
- **Directed-Graph Promotions (`0x04AD4C`):** Class promotions in Bank `$09` are encoded as 125 16-bit pointers to null-terminated target class arrays, paired with 77 branch threshold records (`Min Level`, `Min ALI`, `Max ALI`, `Min CHA` at `0x4AED4`–`0x4AFF2`) and 6 special relic overrides (`0x317A6` for *Undead Ring*, *Royal Crown*, *Blood Kiss*, *Rotten Pumpkin*, *Stone of Dragos*, *Undead Staff*).
- **12Mbit (1.5 MB) LoROM Checksum Mirroring:** Because 1.5 MB (`12 Mbit`) is not a power of two, the SNES internal header checksum (`$D316` at `0x7FDE`) is computed as `sum(first_1MB) + 2 * sum(last_512KB)`. When expanding the ROM buffer in memory to `2.0 MB` (`16 Mbit`, header byte `0x7FD7 = 0x05`) for Bank `$30`/`$3B` mods, the checksum formula must dynamically switch to a linear 2.0 MB sum.
- **Asymmetric Table Bounds (`101` vs. `125` Classes; `100` vs. `196` Items):** While the game defines 125 class IDs (`0x01` Fighter through `0x7D` Galf), only the first **101** standard army/monster classes (`0x01`–`0x65` Fogel) have entries in Bank `$02`/`$03` movement, weight, cost, leadership, growth, action-count, and elemental resistance tables. Special boss/NPC classes (`0x66`–`0x7D`) have base stats only, and executable 65816 assembly begins immediately at `0x17FF8`. Likewise, only the first **100** of **196** items have signed 8-bit stat bonus tables (`0x3C7A3`–`0x3CACA`). Writing 125 entries across Bank `$02` silently corrupts live code—a bug caught immediately by our 0-byte `Gate 4A` roundtrip assertion.

---

## Part 3: Static Recompilation, Tiered Execution & Headless Trace Oracles

### 3.1 Why Hybrid Tiered Execution Beats "All-or-Nothing" Static Lifting
In Attempt 1 (`romatlas`), any subroutine that could not be statically proven at compile time became a showstopper. In Attempt 3, adopting the **`snesrecomp` + LakeSnes** hybrid model ([`docs/architecture/snes_rom_transpilation_research_plan.md`](architecture/snes_rom_transpilation_research_plan.md)) solved this via **Tiered Execution**:
- **723 Subroutines Statically Lifted (`src/gen/ob_bank_01.c` .. `ob_bank_2f.c`):** Compiled into `libob_recomp.a` and registered in a O(1) 24-bit address dispatch table (`src/gen/ob_recomp_stubs.c`).
- **Cycle-Sensitive Banks Kept on Interpreter (`Bank $00` & `Bank $02`):** Bank `$00` contains NMI/IRQ interrupt handlers, DMA queues, and stack-manipulating coroutine trampolines (`PEA ... RTS`) where mid-routine interrupt timing matters. Keeping Banks `$00` and `$02` on the cycle-accurate interpreter while running gameplay/math banks natively gave us both **100% hardware compatibility** and **native C hooks**.

### 3.2 Case Study: Bisecting a 1-Byte Desync at Frame 8,547 (`$05:8299`)
Why build a headless lockstep oracle (`RM_BOTH`) instead of just playing the game and checking if it "looks right"?

During Gate 1 verification ([`docs/verification/gate_1_certification.md`](verification/gate_1_certification.md)), `trace_02_tarot_creation.obrec` (Warren's opening Tarot quiz) looked visually fine—cards drew, text printed, and the map loaded. However, the `RM_BOTH` lockstep comparator halted at **Frame 8,547** with a single-byte mismatch at Direct Page `WRAM $7E:0007` (`Reference: 0x02`, `Candidate: 0xFF`).
- **Root Cause:** Subroutine `$05:8299` calculates initial character creation stats by indexing personality tables in Bank `$7F` using the SNES hardware unsigned multiplier MMIO registers (`write $4202`, `write $4203`, read 16-bit product at `$4216`).
- **Why Human Testing Would Have Missed It:** A 1-byte error in `$7E:0007` during character creation silently shifts the Opinion Leader's starting stat/alignment seed without crashing the game. Only a frame-by-frame `memcmp` across all 128 KB of WRAM caught it at the exact instruction boundary.

### 3.3 Transient Stack Boundary Normalization in Lockstep Testing
When a recompiled C function (`gen_058299()`) calls a helper or runs natively, it uses the **host x86_64/ARM64 C stack** rather than pushing synthetic 16-bit return addresses onto the SNES hardware stack in low WRAM (`$7E:0100`–`$7E:01FF`).
- **Lesson:** If your lockstep harness blindly runs `memcmp` on the unused bytes below the SNES stack pointer `S` (or while one core is mid-subroutine), it will report false-positive stack-residue diffs. Always synchronize comparisons at VBlank/frame boundaries and normalize inactive stack scratch space (`recomp_interp.c`).

### 3.4 The Emulator Cold-Boot Trap (`0x55` Uninitialized WRAM Pattern)
One of the subtlest bugs encountered late in development occurred when wiring the 16:9 widescreen scene detector and mouse layer into the live LakeSnes core (`src/main.c`):
- **The Symptom:** On cold boot (Frames `0..118`), before the Atlus/Quest logo even appeared, the widescreen compositor thought the player was on the **Tactical Battlefield Map** (`OB_SCENE_TACTICAL_MAP`) and the telemetry parser thought **100/100 army units** were deployed.
- **The Cause:** Most unit tests allocate fake WRAM with `calloc()` (`0x00`). Real SNES emulators (including LakeSnes inside `snes_reset()`) initialize all 128 KB of WRAM (`$7E:0000`–`$7F:FFFF`) to **`0x55`** (`01010101b`) to simulate uninitialized static RAM power-on state!
  - Until the game's Reset routine finishes its DMA zero-fill of WRAM around Frame 118, every byte in WRAM reads `0x55`.
  - Any host C check written as `if ((wram[0x14E6] & 0xC0) != 0)` evaluates to `true` because `0x55 & 0xC0 == 0x40`!
  - Even after the game clears low WRAM (`$0000`–`$1FFF`), high WRAM (`$F942` combat accumulators) stays `0x5555` until the first battle occurs.
  - **Sprite-Visibility vs. Scene-Mode Flags (`$14E6` vs. `$00CB/$00CC`):** In live gameplay, `$14E6` is a cursor-visibility flag (`0x00`/`0x01` when drawn, `0x80`/`0xC0` when suppressed) rather than a scene ID. Anchoring `ob_input_detect_mode` on primary game-mode bytes (`$00CB == 0x01`, `$00CC == 0x10`, `$00CE == 0x00`, `$07BA != 0x55`) prevented false positives on boot while fixing live Tactical Map detection.
  - **Direct-Page Scratch, VBlank Commands & Post-Combat Stale WRAM vs. Hysteresis (`widescreen.c`):** Using a Direct-Page scratch byte (`$7E:0010 == 1`) or VBlank NMI transfer command (`$7E:00CA`) as an unconditional scene trigger caused rapid frame-to-frame wing flickering during live play whenever the 65816 engine wrote `0x01` to `$10` or pulsed `$00CA` during VBlank. Likewise, cumulative clash damage (`$7E:F942`/`$7E:F944`) persists in WRAM after a battle ends, and un-deployed entity coordinates use `0x7FFF` in addition to `0xFFFF`/`0x5555`. Eliminating live widget flicker required: (1) anchoring scene detection on `$7E:07BA` (`0x55` pre-boot, `0xFF` character creation, populated ID in campaign) and Master Module `$7E:00CB`/`$7E:00CC`, (2) gating `OB_SCENE_COMBAT_STAGE` on active round state (`$7E:F92B != 0` with remaining actions `$7E:F941 > 0`), and (3) adding Schmitt-trigger spatial/temporal hysteresis (`45`-frame sticky inspector hold, `8 px` entry / `12 px` keep magnetic snap, and `180 px` entry / `210 px` exit + `15`-frame debounce on town recapture alerts).

> **Lesson 2 (The `0x55` Cold-Boot & Hysteresis Rule):** Never assume uninitialized emulator RAM is zeroed, and never drive HUD mode switches from un-debounced scratch registers or single-threshold distance checks! Anchor scene detectors on persistent module state (`$00CB`/`$00CC`/`$07BA`) and apply Schmitt-trigger hysteresis to contextual UI cards.

---

## Part 4: Planning & Implementing Retro Modernizations Without Breaking the Game

### 4.1 Post-Mortem: Why Synthetic D-Pad Mouse Steering Failed (`Rev 1–8` vs. `Rev 9+`)
When adding mouse support to a console game that never supported the SNES Mouse, the most tempting approach is a **closed-loop synthetic D-Pad injector**:
```c
// ANTI-PATTERN (Deprecated Rev 1-8):
if (mouse_x > cursor_x + deadband) joypad |= BTN_RIGHT;
if (mouse_x < cursor_x - deadband) joypad |= BTN_LEFT;
```
We iterated through **eight revisions (`Rev 1`–`Rev 8`)** of synthetic D-Pad steering on `gate/2-mouse-input` before proving via disassembly why it can *never* work in *Ogre Battle* ([`docs/archive/mouse_architecture_deprecation_and_redesign.md`](archive/mouse_architecture_deprecation_and_redesign.md)):
1. **The "Center Rectangle Joystick Bug" (Tactical Map):** Because `$00:B283` clamps the cursor to `[8..231, 8..199]` and sets `$14E7`, moving the host mouse anywhere near the edge of the screen caused the closed-loop injector to hold `BTN_RIGHT`/`BTN_DOWN` indefinitely—sending the Mode-7 camera flying across the map uncontrollably.
2. **60 Hz Menu Wrap-Around Spinning (7-Icon Command Bar):** On the 1D horizontal command bar (`OAM[1]` tile `0xCE` at `X = 75..171, Y = 119`), moving the mouse to `X = 200` caused `Rev 8` to hold `BTN_RIGHT` every frame. Because the menu wraps from slot 6 (`X = 171`) back to slot 0 (`X = 75`), the cursor spun in an infinite 60 Hz loop!
3. **The Fix (`Rev 9+` Three-Pillar Direct-State Architecture):**
   - **Never emit continuous synthetic D-Pad bits on mouse hover.**
   - **Pillar 1 (Tactical Map):** Write screen coordinates (`$14DE`/`$14E0`) and world coordinates (`$14E2`/`$14E4`) **directly to WRAM** *before* the frame's 65816 step so `$00:B2FC -> JSR $CBAE` remains authoritative for Mode-7 zoom (`$14BB`) raycasting. Force `$14E7 = 0` so hover never scrolls the camera, snap ±8 px to squads/cities, and pan the Mode-7 camera (`$00BD`/`$00BF`) *only* on Right/Middle-drag or a 10 px screen-edge zone.
   - **Pillar 2 (Menus & Grids):** Use deterministic 2D bounding-box hit-tests (`slot = (mouse_x - 71) / 16`) and write the slot index (`WRAM $0474`) directly. If the mouse is outside the menu box, do nothing.
   - **Pillar 3 (World Map & Keyboard Coexistence):** Scan hardware `ppu_oam` in two passes (`OAM[24..35]` then `OAM[1..23]` for `attr & 0x38 == 0x38` stage banners) while updating `$14DE`/`$14E0` over open ocean so the pointer stays responsive. Track `last_mouse_win_x/y` (initializing `has_prev_pos = true` at center so the first motion event wakes the cursor immediately), map window coordinates through aspect-correct letterbox/pillarbox clamping (`ob_input_map_window_to_snes`), and yield 100% of control back to the keyboard/gamepad whenever the mouse is stationary.

### 4.2 The 16:9 Widescreen Evolution: Companion Window $\rightarrow$ `400×224` $\rightarrow$ `800×448` Dual-Layer Canvas
Our widescreen and UI architecture evolved through three distinct phases ([`docs/architecture/widescreen_16_9_architecture.md`](architecture/widescreen_16_9_architecture.md)):
1. **Phase 1 (Separate 640×480 Companion Window):** Originally, Area 1 Telemetry was built as a second OS window (`telemetry_window.c`). While functionally complete, playtesting showed that forcing players to look back and forth between two windows broke immersion.
2. **Phase 2 (Native `1×` `400×224` Widescreen):** Expanding the `256×224` (`4:3`) SNES PPU output horizontally to 16:9 at `1×` resolution yields `400×224` (`+72 px` / `9` tiles of `8×8` text per side wing). However, **9 characters of horizontal width is far too narrow** to display readable RPG telemetry (unit names, alignment deltas, class promotion requirements).
3. **Phase 3 (The `2×` `800×448` Dual-Layer Master Canvas):**
   - By integer-scaling the `256×224` PPU output by **`2×` to `512×448`** in the center of an **`800×448` (16:9)** master canvas, each side wing becomes **`144×448 px`** (`18 columns × 56 rows` of `8×8` tiles, or `24 columns` using our compact `6×8` glyph font).
   - This doubled the horizontal information density while keeping 100% integer-scaled pixel art, allowing us to retire the separate companion window and embed context-switched **Left/Right Tactician Wings** plus a **`[Tab]` Campaign Grimoire** modal inside a single window.
   - **Modal vs. Wing Clearance (`480×384` Inside `512×448` Core):** Rather than filling the entire `512×448` center viewport, the `[Tab]` Zenobian Campaign Grimoire is sized to **`480×384 px` (`x = 160..639, y = 32..415`)**, leaving a `16 px` (`2`-tile) breathing margin on both sides so it never collides with the `144 px` Left/Right Wings—allowing players to cross-reference the 18-Hero Audit against live Stage Recon and Zodiac Wings simultaneously.

```
                     800 × 448 MASTER 16:9 COMPOSITOR CANVAS
┌────────────────────┬───────────────────────────────────────┬────────────────────┐
│     LEFT WING      │       2× INTEGER-SCALED PPU CORE      │     RIGHT WING     │
│    144 × 448 px    │             512 × 448 px              │    144 × 448 px    │
│  (18 × 56 Tiles)   │      (256 × 224 Native @ 2× Scale)    │  (18 × 56 Tiles)   │
└────────────────────┴───────────────────────────────────────┴────────────────────┘
```

### 4.3 Authentic 1993 SNES UI Aesthetics (`BGR555`, 2-Pass Shadowed Fonts & Visual QA)
Nothing ruins a retro PC port faster than slapping modern flat floating ImGui/TTF text over 1993 pixel art. To make the 16:9 Tactician Wings, Pre-Boot Launcher, and `[Esc]` Settings Overlay look like Quest built them in 1993 (`src/engine/snes_ui_rasterizer.c`):
- **Strict 15-Bit `BGR555` Color Quantization:** Every UI color is quantized via `OB_BGR555_RGBA(r, g, b)` (5 bits per channel, steps of 8) so no 24-bit gradients clash with the SNES palette.
- **8-Step Vertical HDMA Window Fills:** Panels replicate the SNES PPU's per-scanline HDMA backdrop color writes (`Royal Blue`, `Crimson Alert`, `Emerald Safe`, `Obsidian Ledger`).
- **Beveled Gold 9-Slice Borders & 2-Pass Shadowed Bitmap Fonts:** Every glyph renders a `1px` bottom-right drop shadow in `OB_COLOR_TEXT_SHADOW` before drawing the foreground glyph, ensuring crisp legibility against any background.
- **Contrast Separation & ROM 2BPP Decoding Quirks (`telemetry_window.c`):** An early pass that filled both the screen backdrop and panel interiors with dark charcoal slate (`#14141C`) next to dark bronze borders (`#281808`) looked like thin yellow wireframes floating on void black. Authentic 1993 Quest contrast requires separating a patterned Mode 1 diamond tapestry backdrop (`#080810` / `#101820`) from luminous **Royal Blue** scanline-dithered interiors (`#182868` $\rightarrow$ `#080830`) using 4-color `$14EEE7` 9-slice borders where index `1` (`#0A122A`) acts as an inner bevel. Likewise, in *Ogre Battle*'s `$090000` 2BPP font sheet, **pixel index `1` is transparent** (not `0`), index `3` is the glyph face, and index `2` is the top-left anti-aliasing highlight—requiring a **2-pass blitter** (all `(+1, +1)` drop shadows first, then foreground faces) so adjacent glyphs never overwrite each other's shadows.
- **Closed-Loop Visual Verification Beyond Byte Assertions:** In Gate 3 (`test_widescreen_16_9.c`), our automated C tests verified 0-byte WRAM drift and 100% `BGR555` palette quantization across all `358,400` pixels per `800×448` frame. Yet exporting `.ppm` $\rightarrow$ `.png` frames and inspecting the rendered images caught layout bugs that numerical assertions could not see:
  1. Missing `'&'` and `'$'` glyphs in the `5×7` bitmap font table (`REPUTATION & CLK`, `($45)`).
  2. Multi-byte UTF-8 checkmarks (`✓`) splitting into 3 blank spaces in a byte-by-byte C font blitter (resolved by mapping a dedicated `5×7` checkmark glyph to ASCII `'*'`).
  3. `[PLN]` mobility badges at `x = 108` touching the right `8×8` gold 9-slice border at `x = 136` (fixed by shifting to `x = 102`).
  4. A 1-indexed vs. 0-indexed Tarot ID mismatch on `I. MAGICIAN` in the Tarot Guard Dock.
  5. **Roman Numeral Spillover & Non-Human Promotion Fallbacks (`telemetry_window.c`):** A `28 px` Tarot card caused 3-character numerals (`"VII"` = `24 px`) to spill into the label column (`VII. CHARIOT`, fixed by widening to `32 px` and shifting labels to `+52 px`), while monster/special units like `Werewolf` (slot `0`) have `0` branches in human promotion tables and rendered a blank Promotion Tree box until an explicit nocturnal/battle fallback card was added.
  Always pair headless framebuffer assertions with exported PNG visual inspection when building custom software rasterizers.

### 4.4 The "Zero-Invasion" Telemetry Rule (`const uint8_t *`) & Walkthrough-Driven Design
When adding complex predictive calculators (such as pre-clash Alignment/Charisma drift, `-5 CF` enemy town recapture warnings, and Bank `$09` promotion tree inspection), there is a real danger of accidentally mutating emulator state and breaking deterministic replays.
- **Walkthrough-Driven Feature Discovery:** Researching SNES *Ogre Battle* walkthroughs *before* locking the telemetry schema surfaced high-value, non-obvious player traps—Tarot overlevel `-ALI` penalties, `-5 CF` enemy town/temple recapture ETAs, `Sky` (`+2 Flyers`) mobility thresholds, and Neutral Beast/Dragon persuasion readiness—that would not have been obvious from raw WRAM offsets alone.
- **Enforced C Invariant:** Every function in the telemetry pipeline (`telemetry.c`, `telemetry_math.c`, `widescreen.c`) accepts emulator memory exclusively as **`const uint8_t *wram`** and **`const uint8_t *rom`**.
- **Automated Verification (`test_area_1_telemetry.c`, `test_widescreen_16_9.c`):** Unit tests cryptographic-hash or `memcmp` all 128 KB of WRAM before and after running 600 frames of telemetry extraction and 16:9 compositing, asserting **0 bytes of mutation**.

### 4.5 Boot-Time Data Decoupling Over Monolithic `.ips` Patches
Traditional SNES modding relies on binary `.ips`/`.bps` patches that overwrite hardcoded ROM offsets—making it impossible to combine two mods that touch adjacent tables or mix headered (`+512 B` copier header) and unheadered patches.
- **Our Solution (Area 4 Boot-Time ROM Builder):**
  1. Extract canonical vanilla tables (`classes.json`, `promotions.json`, `items.json`, `shops.json`, `stages.json`, `attacks.json`) and certify a **0-byte roundtrip (`Gate 4A`)** where `reconstruct(extract(ROM)) == ROM`.
  2. Decompile legacy `.ips` hacks (`tools/ips_importer.py`) with automatic **512-byte copier header detection** (`detect_header_shift()` scores record offsets against the SNES internal header `0x7FC0..0x7FFF` vs. `0x81C0..0x81FF` and promotion tables—essential because older 2010 patches like `dragoner.ips` and `OBabmod071.ips` are `+0x200` headered while modern patches like `OB_ClassExpansion.ips` are unheadered).
  3. Classify mods into a **4-Tier Abstraction Taxonomy** ([`docs/architecture/rhdn_patches_catalog.md`](architecture/rhdn_patches_catalog.md)) so `ConflictValidator` can enforce safe stacking:
     - **Level 1 (Pure Data Schema):** E.g., `dragoner_rebalance.json` (100% mapped to `promotions.json`).
     - **Level 2 (Data + Text/Spell Tables):** E.g., `fin_balancing_071.json` (31 structured domains + string/spell timing tables).
     - **Level 3 (Bank `$30` ASM Hooks + 2.0 MB Expansion):** E.g., D's `OBMagicFix`, `OBRanDrops`, `OBwSizeTables`.
     - **Level 4 (Total Conversion Overhaul):** E.g., UPRC `ClassExpansion` (14 new classes, Bank `$3B` palette persistence, mutually exclusive with Level 3 Bank `$30` hooks).
  4. Assemble selected JSON overlays and dynamic `1.5 MB -> 2.0 MB` Bank `$30` expansions into the in-memory ROM buffer **once before `snes_reset()`** (`src/engine/boot_loader.c`).
- **Static Recompilation vs. Binary ASM Hooks:** In a hybrid lifted engine (`snesrecomp` + LakeSnes), pure data-table mods (`Level 1`/`2`) work transparently with statically lifted C banks because lifted functions still read `rom_buffer` via `snes_read()`. However, **executable 65816 code hooks** (`Level 3`/`4`, such as `JMP $308800` patched at `$01:8F8B`) will be bypassed if `$01:8F8B` is dispatched to a pre-compiled C function in `func_table`. Any binary code patch targeting a lifted bank must either unregister that subroutine from `func_table` (falling back to the interpreter, which executes the patched 65816 bytes and Bank `$30` routines) or mirror the fix as a native `RECOMP_PATCH`.
- **Result:** Zero runtime CPU overhead for data tables, 100% compatibility across both interpreted and lifted execution paths, and deterministic conflict detection (`ConflictValidator`) before launch.

---

## Part 5: Version Control, Sequential Gates & Agentic Development

### 5.1 The Early Cloud Environment Recovery Lesson
During the earliest phase of this project, the initial Gate 1 work was not tracked under strict branch/handoff discipline and became locked inside a separate cloud environment. Recovering and reconstructing the salvageable pieces from that environment taught a painful lesson: **uncommitted or poorly documented agent context is an existential risk.**

That experience directly shaped the governance rules in [`docs/agents.md`](agents.md):
- Every milestone is gated by an explicit Git tag/branch (`v0.1.0-gate1-certified`, `gate/2-mouse-input`, `gate/3-widescreen`).
- Every multi-step session records a structured handoff log ([`docs/archive/handoffs/`](archive/handoffs)) containing the active branch, `HEAD` commit SHA, certified gate status, and exact test commands.

### 5.2 Outer Sequential Gates vs. Inner Iterative Feedback Loops
A common failure mode in retro porting projects (documented in *Mega Man X Recomp* and our own [`docs/archive/gap_analysis.md`](archive/gap_analysis.md)) is **Premature Modernization**—trying to build 16:9 widescreen or mouse controls while the underlying 4:3 game still has CPU desyncs. Conversely, rigid waterfall planning stalls when a late trace uncovers a new jump table in an early bank.

We solved this by separating **Outer Gates** from the **Inner Loop** ([`docs/archive/plan.md`](archive/plan.md)):
- **Outer Progression Gates (Strictly Sequential):**
  - `Gate 1` (4:3 Bit-Exact Parity across 83,450 frames) **must** pass with 0-byte drift before `Gate 2` (Mouse Input) or `Gate 3` (16:9 Widescreen) can merge.
- **Inner Engineering Pipeline (Bidirectional Feedback Loop):**
  - Whenever the Lockstep QA Harness (`Role C`) hits a frame divergence, it drops a snapshot and triggers a tight loop with the Disassembly/CDL Specialist (`Role A`) and Lifter (`Role B`) to update `config/jumptables.ini` or fix flag widths, then re-verifies all 8 traces.

### 5.3 Guardrails Against AI Agent Failure Modes
Working with AI coding agents on low-level 65816 assembly and emulator internals requires explicit guardrails ([`docs/agents.md`](agents.md)):
1. **No Mocked/Synthesized Execution Results (Rule 1):** An AI agent left unchecked may try to make a failing test pass by hardcoding a return value or stubbing an assertion. `RM_BOTH` lockstep `memcmp` across 128 KB WRAM makes faking parity impossible.
2. **Trace `REP`/`SEP` Instead of Guessing Register Widths (Rule 3):** On the 65816, guessing whether Accumulator `A` is 8-bit (`M=1`) or 16-bit (`M=0`) corrupts adjacent WRAM bytes (`STA $07` overwriting `$08`). Agents must trace every path from the nearest `REP`/`SEP`/`PLP`.
3. **Automated Legal Hygiene (Rule 4 + Pre-Commit Hook):** When working with local `.sfc` ROMs and `.obsav` memory dumps for testing, a single careless `git add .` can contaminate the git history with copyrighted assets. Installing a hard blocker in [`tools/git-hooks/pre-commit`](../tools/git-hooks/pre-commit) that aborts on `.sfc`, `.smc`, `.rom`, `.bin`, and `.obsav` files prevents accidents before they happen.
4. **Git Worktrees for Heavy QA (`../ob-qa-worktree`):** Running an 83,450-frame headless trace suite or cross-compiling Windows MinGW binaries while simultaneously editing C code in the same directory causes CMake cache thrashing and dirty worktree errors. Dedicating separate `git worktree` checkouts keeps active development fast and clean.

### 5.4 Parallel Agent PRs, Header Divergence & Hook Drift
Integrating PRs #1–#4 in parallel surfaced four practical multi-branch lessons:
1. **Define Shared Interface Headers on `main` First:** PR #1 (`feat/telemetry-overlays`) and PR #3 (`gate/3-widescreen`) were developed concurrently and both independently created `include/ob_snes_ui_theme.h` with incompatible types and constants (`ObSnesPalette` vs. `ObSnesPaletteId`, raw `0xAARRGGBB` hex vs. `OB_BGR555_RGBA`, `OB_COLOR_TEXT_SKY` vs. `OB_COLOR_TEXT_CYAN`), causing an add/add merge conflict. Establish shared UI/engine headers on `main` before branching parallel work, or land the shared primitive PR first.
2. **Respect PR Dependency Order & Rebase Stale Bases:** PR #3 branched off PR #2 (`gate/2-mouse-input`), whereas PR #4 (`gate/4-boot-decoupling`) was authored against an older `main` predating PRs #1–#3. Merge foundational gate branches before dependent ones, and rebase or merge `main` into older branches before review so `CMakeLists.txt` and header drift are caught early.
3. **Keep Git Hooks & CI Aligned with Real Targets:** [`tools/git-hooks/pre-push`](../tools/git-hooks/pre-push) checked for a legacy `./build/test_trace` binary and exited `0` when absent—silently skipping verification instead of running the actual `ctest` targets (`Gate2*`–`Gate5*` / `OracleHarnessTest`). Similarly, [`.github/workflows/ci.yml`](../.github/workflows/ci.yml) required fixes for inline Python formatting and ROM-check edge cases during early PR runs.
4. **Workspace & Public URI Hygiene:** When initializing Git in a shared workspace or `$HOME`, enforce `.gitignore` exclusions for local agent/editor directories (e.g. `.gemini/`, `.local/`) and scrub machine-local `file:///` links from markdown before publishing.
5. **Verify Repository Root Before Branching (`git rev-parse --show-toplevel`):** In VM workspaces where `$HOME` and a cloned project subdirectory coexist, confirm `git rev-parse --show-toplevel` and `git remote -v` before creating a feature branch so commits don't land in a parent `$HOME` repo requiring manual cherry-picking later.

---

## Part 6: The 10-Point Blueprint for Future Retro PC Ports

If you are starting a new SNES (or 16-bit console) PC port or modernization project, follow this distilled sequence:

1. **Audit Community Symbols First (Avoid the "Zelda Illusion"):** If a complete, labeled disassembly doesn't already exist, do **not** attempt manual line-by-line idiomatic C decompilation.
2. **Embed Proven Silicon on Day 1:** Pair an automated static lifter (`snesrecomp`) with a cycle-accurate hardware runtime (`LakeSnes`) for PPU, SPC700 audio, and DMA so the game boots immediately.
3. **Use Tiered Execution:** Statically lift gameplay/math banks into C, and let NMI/IRQ/timing-critical banks fall back to the interpreter until needed.
4. **Record Canonical Replay Traces Early (`.obrec`):** Record 5–10 headless input traces covering boot, menus, movement, combat, bosses, and saving. Run them in `RM_BOTH` lockstep (`memcmp` on WRAM/VRAM/CGRAM/OAM every frame).
5. **Enforce Gate 1 (4:3 Parity) Before Modernizing:** Never touch widescreen or mouse injection until baseline 4:3 execution passes with 0-byte memory drift.
6. **Guard Against `0x55` Cold-Boot WRAM & Transient NMI Scratchpad Bytes:** Remember that hardware emulators initialize RAM to `0x55` on reset, and zero-page bytes like `$0010`/`$00CA` often hold transient VBlank DMA command indices rather than scene IDs. Anchor scene detection on persistent campaign/module state (`$07BA`, `$00CB`, `$00CC`) and apply Schmitt-trigger spatial/temporal hysteresis to contextual HUD widgets so single-frame movements never flicker.
7. **Use Direct-State & Hit-Boxes for Mouse Input (Never Synthetic D-Pad):** Map out the game's cursor/camera WRAM variables and menu slot indices via disassembly. Write coordinates/slots directly and decouple camera panning from cursor hover.
8. **Render Widescreen UI Wings at `2×` Post-PPU Resolution (`800×448`):** Native `1×` 16:9 (`400×224`) only gives `72 px` (`9` tiles) per side wing. Upscaling the PPU core by `2×` (`512×448`) inside an `800×448` canvas gives `144×448 px` (`18×56` tiles) per wing for readable, authentic `BGR555` pixel-art HUDs.
9. **Keep Telemetry Strictly Read-Only (`const uint8_t *`):** Pass emulator memory as `const` pointers into all HUD/telemetry extractors and assert 0-byte WRAM drift in unit tests.
10. **Decouple Mod Tables at Boot Time:** Extract hardcoded ROM tables into JSON schemas verified by a 0-byte roundtrip test (`reconstruct(extract(ROM)) == ROM`), and assemble mod overlays into RAM *before* CPU reset for zero-overhead modding.

---

## Further Reading in This Repository

- **Architecture & Reusable Components:** [`docs/architecture/README.md`](architecture/README.md)
  - [`widescreen_16_9_architecture.md`](architecture/widescreen_16_9_architecture.md) — `800×448` compositor, 7-screen Wing layouts & `BGR555` rasterizer.
  - [`developer_guide_area_1_telemetry.md`](architecture/developer_guide_area_1_telemetry.md) — WRAM memory map, SoA layouts & predictive math formulas.
  - [`rhdn_patches_catalog.md`](architecture/rhdn_patches_catalog.md) — Technical breakdown of community `.ips` hacks and 2.0 MB Bank `$30`/`$3B` expansion.
  - [`snes_rom_transpilation_research_plan.md`](architecture/snes_rom_transpilation_research_plan.md) — Survey of `snesrecomp`, `snesrev`, and `gilgamesh`.
- **Verification & Certification Reports:** [`docs/verification/`](verification)
  - [`gate_1_certification.md`](verification/gate_1_certification.md) — 83,450-frame lockstep parity & Frame 8,547 `$05:8299` bisection.
  - [`gate_4a_certification.md`](verification/gate_4a_certification.md) — 0-byte ROM table extraction & reconstruction roundtrip.
  - [`boot_pipeline_certification.md`](verification/boot_pipeline_certification.md) — Layered boot profiles & conflict resolution.
- **Agentic Governance & Historical Archive:** [`docs/agents.md`](agents.md) & [`docs/archive/`](archive/README.md)
  - [`mouse_architecture_deprecation_and_redesign.md`](archive/mouse_architecture_deprecation_and_redesign.md) — Full disassembly post-mortem of `Rev 1–8` vs. `Rev 9+` Three-Pillar mouse architecture.
  - [`gap_analysis.md`](archive/gap_analysis.md) — Original 5-gap comparison against `zelda3` and `MegaManX`.
