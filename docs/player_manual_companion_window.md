# Ogre Battle: The March of the Black Queen (PC Port)
## Official Player Manual: 16:9 Tactician Wings & Campaign Grimoire

> [!TIP]
> **What are the 16:9 Tactician Wings?**
> Instead of a separate external window, the PC port integrates your strategic advisor directly into the `144×448` Left and Right sidebars flanking the centered SNES screen (`800×448` master canvas). They do **not** alter the original 1993 SNES gameplay or balance—they read live memory to surface hidden mechanics in real time based on the active game screen.

---

## 1. The Hidden Rules of Ogre Battle

### 1.1 The Chaos Frame (`CF`) & The Reputation Trap
- **What it is:** Your reputation with the people of Zenobia on a hidden `0–100` scale.
- **How it changes:**
  - Liberating a city with a squad whose **average Alignment closely matches the city's compatibility** increases Chaos Frame (`+1` to `+3 CF`).
  - Liberating a Temple always gives `+0 CF` (neutral ground).
  - Liberating a city with an incompatible squad counts as a **Ransack** (`-1` to `-3 CF`).
- **Why it matters:** Your Chaos Frame determines which of the **13 endings** you receive and which legendary heroes (Rauny, Tristan, Slust, etc.) will join you.

### 1.2 The `-5 CF` Recapture Penalty
- Allowing an enemy squad to recapture any liberated town or temple **instantly inflicts a `-5 CF` penalty**, which can permanently lock you out of top endings (*The World*, *The Sun*, *The Justice*).

### 1.3 The Opinion Leader Overlevel Trap
- Playing an offensive Tarot card in combat (*The Magician*, *The Sun*, *The Tower*, *The Judgement*, etc.) awards **100% of the EXP and Alignment changes directly to Unit #00 (your Opinion Leader)**, rather than the fighting squad—rapidly overleveling your Lord and tanking their Alignment if used recklessly.

---

## 2. Display Modes & Hotkeys

- **`[F10]` — Cycle Display Mode:**
  1. **16:9 Tactician Wings (Default):** Centered 2× SNES core (`512×448`) flanked by context-switched `144×448` Left & Right Telemetry Wings.
  2. **16:9 Vanilla Horizon:** Extended 16:9 backdrops with Zenobian Stone & Parchment tapestry pillars on fixed menus.
  3. **4:3 Classic:** Centered `512×448` SNES core with clean borders and no sidebars.
- **`[Tab]` — Toggle Campaign Grimoire:** Opens or closes the centered `480×384` **Zenobian Campaign Grimoire** modal over the viewport.
- **`[P]` — Toggle PoI Radar:** Enables or disables Hidden Points of Interest tracking.
- **`[Esc]` — Settings Overlay:** Opens the 4-tab Video/Audio/Controls/System menu (saved to `ogre_battle.ini`).

---

## 3. Context-Switched 16:9 Wings by Game Screen

The Left and Right wings automatically switch to match your current screen:

### 3.1 Title, Camp, Shop & Epilogue
- Displays clean **Zenobian Stone & Parchment tapestry pillars** so fixed 32-tile SNES menus remain uncluttered.

### 3.2 Warren's Character Creation Quiz
- **Left Wing (`MOD & SEED CONFIG`):** Active Area 4 profile, widescreen/telemetry flags, and randomizer seed.
- **Right Wing (`LORD ARCHETYPE`):** Live projected Lord class, front/back row attacks, and starting stats (`STR`, `INT`, `AGI`, `ALI`, `CHA`, starting Chaos Frame).

### 3.3 Continental World Map
- **Left Wing (`ZODIAC & BRUNHILD` + `ARMY READINESS`):** Live count and socket grid for the 12 Zodiac Stones, key relics (*Quicksilver*, *Tablet of Yaru*, *Brunhild*), and army readiness.
- **Right Wing (`STAGE RECON` + `18-HERO AUDITOR`):** Current stage recon and recruitment status for the 18 Special Heroes, including **Deneb (`CF <= 35`)** and **Galf (`CF <= 20`)** ending tradeoff warnings.

### 3.4 Tactical Overland Map (Primary Command View)
- **Left Wing (`DEPLOYED SQUADS`):** Interactive squad plates (`1–6`) showing mobility type (`PLN`, `SKY`, `FOR`, `MTN`), HP bar, and flight upgrade hints. **Left-clicking a squad plate** jumps the tactical camera directly to that squad.
- **Right Wing (3 Stacked Cards):**
  1. **Reputation & Clock:** `Chaos Frame` (`0–100`), `Goth` treasury, projected `Noon Net Goth` (`Tribute - Upkeep`), 24-hour clock (`DAY`/`NIGHT`), and projected Ending Path.
  2. **Context-Switched Target Inspector (with `0.75s` Sticky Hold & Magnetic Snap):**
     - *Hovering a City:* **City Liberation Advisor** showing city morale, best-matching squad, and predicted `+CF` or `-CF` Ransack warning.
     - *Hovering an Enemy Squad:* **Pre-Clash Morality Drift** showing Alignment/Chaos impact per unit.
     - *Open Terrain:* **Neutral & Mobility** info and PoI Radar status (inspector holds your last hovered city or enemy squad for `0.75s` / `45` frames when your cursor glides across open terrain so stats remain readable).
  3. **Spatial Radar & `-5 CF` Recapture Alert:** 2D tactical radar with a debounced red alert box (`180 px` entry / `210 px` clear threshold) whenever an enemy squad threatens a liberated town (`ENM# -> CITY#` and intercept `ETA`).

### 3.5 Combat Stage
- **Left Wing:** **Clash Tug-of-War** (`PLY vs ENM` damage gauge & margin), **Morality Drift** per unit, and **Turn Initiative** queue.
- **Right Wing:** **Tactic Stance** pills (`[Q] LDR`, `[W] STR`, `[E] WEK`, `[R] BST`) and **Tarot Guard Dock** (`HAND: X/14`, `LORD LV`) flagging offensive cards with **`! OVERLEVEL TRAP !`** when your Lord is at risk of absorbing EXP/negative Alignment.

---

## 4. `[Tab]` Zenobian Campaign Grimoire

Press **`[Tab]`** at any time to open the full-screen modal containing:
- **Left Column (`18 SPECIAL HEROES AUDIT`):** Complete recruitment checklist and Chaos Frame / Alignment / relic prerequisites for all 18 special characters.
- **Right Top (`12 ZODIAC STONES & RELICS`):** Full 12-gem grid, *Quicksilver* (`$45`), *Tablet of Yaru* (`$49`), *Brunhild* status, and ending forecast.
- **Right Bottom (`MOD-AWARE PROMOTION TREE`):** Live promotion eligibility and stat deltas (respecting any active Area 4 mod overlays).
