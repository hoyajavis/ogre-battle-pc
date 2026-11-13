# Ogre Battle: The March of the Black Queen (PC Port)
## Official Player Manual: The Tactical Companion Window

> [!TIP]
> **What is the Companion Window?**
> The Companion Window is a second screen for the native PC port of *Ogre Battle: The March of the Black Queen*. It functions as your strategic advisor and tactical radar. It does **not** alter the original 1993 SNES gameplay or change game balance. Instead, it reads live memory to illuminate the notoriously hidden mechanics ("Guide Dang It" moments) that previously required constantly cross-referencing printed game guides or FAQs.

---

## 1. Why You Need the Companion Window: The Hidden Rules of Ogre Battle

The original Super Nintendo release of *Ogre Battle* is one of the deepest strategy RPGs ever created, but many of its most critical mechanics are completely invisible during play:

### 1.1 The Chaos Frame (`CF`) & The Reputation Trap
- **What it is**: Your reputation with the people of the Zenobian continent, tracked on a hidden scale of `0` to `100`.
- **How it changes**:
  - Liberating a city with a squad whose **average Alignment closely matches the city's compatibility** increases your Chaos Frame (`+1` to `+3 CF`).
  - Liberating a Temple always gives `+0 CF` (temples are neutral ground).
  - Liberating a city with an incompatible squad (e.g., evil undead squad liberating a holy church city) counts as a **Ransack**, damaging your reputation (`-1` to `-3 CF`).
  - Drawing negative Tarot cards from liberated temples can lower Chaos Frame.
- **Why it matters**: Your Chaos Frame determines which of the **13 distinct endings** you receive, and whether noble heroes like Rauny, Tristan, and Slust will join your rebellion or refuse to speak to you.

### 1.2 The Catastrophic `-5 CF` Recapture Penalty
- When you liberate a town or temple, the Empire will attempt to take it back.
- While liberating a town only gives you `+1` or `+2 CF`, **allowing an enemy squad to recapture any liberated town or temple instantly inflicts a massive `-5 CF` penalty**.
- Losing just 3 or 4 towns across a campaign will permanently destroy your chances of getting the legendary high-alignment endings (*The World*, *The Sun*, *The Justice*).

### 1.3 The Opinion Leader Overlevel Trap
- **The Secret Rule**: When you play an offensive Tarot card in battle (such as *The Magician*, *The Sun*, *The Tower*, or *The Judgement*), any damage dealt and any enemies killed do not grant EXP to the squad in combat.
- Instead, **100% of the EXP and morality changes are awarded directly to Unit #00: Your Opinion Leader**.
- **The Consequence**: If your Opinion Leader uses offensive Tarot cards to wipe out lower-level enemy squads, their level will skyrocket while their Alignment plummets toward `0` (Chaos). A high-level, low-alignment Lord cannot recruit legendary knights and will receive evil or tragic endings.

---

## 2. Companion Window Overview & Screen Navigation

The Companion Window renders in a dedicated `640 × 480` secondary window alongside your main game. It is divided into **three tactical pages**, which you can switch between at any time:

- **Hotkey `[Tab]` or `[PageUp] / [PageDown]`**: Cycle between Page 1, Page 2, and Page 3.
- **Hotkey `[P]`**: Toggle **Hidden Points of Interest (PoI)** on the tactical radar.
- **Hotkey `[1] - [9]`**: Inspect unit promotion requirements for any member of the active squad.

---

## 3. Page 1: Tactical Radar & Threat Vectors

Page 1 is your macro-level command center while maneuvering squads across the overland map.

```
+-------------------------------------------------------------------------------+
| PAGE 1: TACTICAL RADAR & THREAT VECTORS                                       |
+---------------------------------------+---------------------------------------+
| 1. REPUTATION & NOON TRIBUTE          | 2. SPATIAL RADAR & INTERCEPT VECTORS  |
|                                       |                                       |
| - Chaos Frame Bar: 72 / 100           | - 2D Map of all Towns & Squads        |
| - Daily Net Goth: +25,390 G           | - Player Squads: Green Squares        |
| - Clock: 12:00 (Solar Noon)           | - Enemy Squads: Red Squares           |
| - Ending Path: World / Sun            | - Movement Vectors & Intercept TTC   |
+---------------------------------------+---------------------------------------+
| 3. RECAPTURE THREAT RADAR             | 4. TOWN LIBERATION ADVISOR            |
|                                       |                                       |
| [!] ALERT: Enemy #10 -> Temple #00    | - Target: City #01 (Compat: 72 ALI)   |
|     Distance: 48px | ETA: 16 ticks    | - Best Squad: Squad #01 (Avg ALI: 74) |
|     PENALTY WARNING: -5 CF            | - Expected Result: +2 CF LIBERATION   |
+---------------------------------------+---------------------------------------+
```

### Key Readouts on Page 1:
1. **Chaos Frame Progress Bar**:
   - Shows your exact Chaos Frame score (`0..100`).
   - Displays your current projected ending based on your current CF, Leader Alignment, and quest item status.
2. **Daily Noon Tribute Net Forecast**:
   - Every day at 12:00 Noon, liberated towns pay tribute into your Goth treasury, while deployed squads deduct upkeep costs.
   - The Companion Window displays your projected net payout (`Tribute - Upkeep`) in real time so you never run out of Goth.
3. **`-5 CF` Recapture Alert (Red Box)**:
   - When an enemy squad turns toward any liberated town or temple, a red alert banner triggers immediately.
   - Shows the enemy squad number, target town, distance in pixels, and ticks until arrival (`ETA`).
   - **Action**: Immediately dispatch a fast flying squad to intercept the enemy before they set foot on the node!
4. **Town Liberation Compatibility Advisor**:
   - Compares the alignment of all your squads against the selected city.
   - Tells you exactly which squad to use to guarantee a positive Chaos Frame reward (`+1..+3 CF`) instead of an accidental ransack.
5. **Hidden PoI Radar (Optional Toggle)**:
   - *Ogre Battle* contains dozens of hidden cities and temples tucked away in remote forests and mountain valleys.
   - Pressing **`[P]`** reveals these hidden locations on the radar so you don't miss essential shops, Tarot cards, or storyline triggers.

---

## 4. Page 2: Combat & Tarot Guard

Page 2 activates whenever your units enter battle or when planning tactical squad setups.

```
+-------------------------------------------------------------------------------+
| PAGE 2: COMBAT & TAROT OVERLEVEL GUARD                                        |
+---------------------------------------+---------------------------------------+
| 3. COMBAT CLASH TUG-OF-WAR            | 4. TAROT HAND & LEADER OVERLEVEL GUARD|
|                                       |                                       |
| - Player Dmg: 178 | Enemy Dmg: 79     | - Card #00 (Magician): [!] OVERLEVEL  |
| - Clash Margin: +99 (Player Winning)  |   Warning: Kills give 100% EXP to Lord|
| - Status: Enemy will be pushed back   | - Card #05 (Lovers): SAFE / CF +2     |
+---------------------------------------+---------------------------------------+
| 5. PRE-CLASH MORALITY DRIFT TABLE     | 6. SQUAD MOBILITY & NEUTRAL MATRIX    |
|                                       |                                       |
| - Ashe (Knight L5): vs Undead +4A/+2C | - Squad #00 Mobility: Normal (Ground) |
|   vs Low-Level: -3A / -2C             | - Fly Upgrade: Need +2 High Sky units |
| - Lyon (Beast Tamer L4): Ready        | - Terrain: Forest -> Ghost Spawn      |
|   Persuade Dragon / Cerberus          | - Persuasion: Cleric Ready (+ALI Farm)|
+---------------------------------------+---------------------------------------+
```

### Key Readouts on Page 2:
1. **Clash Tug-of-War Bar**:
   - In *Ogre Battle*, whichever side deals more total damage during a skirmish wins the clash and pushes the loser backward.
   - The real-time gauge tracks cumulative damage dealt by your squad vs. the enemy squad, showing who holds the advantage before the battle ends.
2. **Tarot Hand & Overlevel Risk Alerts**:
   - Lists every card in your active hand.
   - Cards that deal direct damage (*Magician*, *Chariot*, *Sun*, *Death*, *Tower*) are flagged with an **`[!] OVERLEVEL TRAP ALERT`**.
   - **Rule of Thumb**: Only use offensive cards when facing bosses or higher-level squads. If facing weaker enemies, use benign cards like *The Lovers*, *The World*, or *The Emperor*.
3. **Pre-Clash Morality Drift**:
   - Shows how your units' Alignment and Charisma will shift if they kill an enemy in the current battle.
   - Killing lower-level enemies decreases Alignment; killing higher-level evil units (or Undead with Holy attacks) increases Alignment.
4. **Neutral Encounter & Persuasion Matrix**:
   - Identifies the terrain beneath your squad and displays what wild monsters can appear.
   - Confirms whether you have the proper recruiter in your squad:
     - **Beast Master / Beast Tamer**: Recruits Dragons, Cerberus, Cockatrices, Griffons, Wyrms, Octopi.
     - **Cleric / Shaman**: Purifies and recruits Ghosts, Skeletons, Wraiths (fantastic for farming Alignment).
     - **Witch + Glass Pumpkin**: Recruits Halloween Pumpkins.
5. **Squad Mobility Advisor**:
   - Classifies your squad's movement type (Normal, Forest, Mountain, Low Sky, High Sky).
   - Informs you how many flying units (Griffons, Cockatrices, Eaglemen) are required to grant the squad flight capability, allowing them to ignore terrain movement penalties.

---

## 5. Page 3: Campaign & Zodiac Guide

Page 3 tracks your overarching progression through Zenobia, ensuring you never miss a recruitable hero or Zodiac artifact.

```
+-------------------------------------------------------------------------------+
| PAGE 3: CAMPAIGN GUIDE & ZODIAC STONES                                        |
+---------------------------------------+---------------------------------------+
| 5. 18 SPECIAL CHARACTER AUDITOR       | 6. 12 ZODIAC STONES & BRUNHILD QUEST  |
|                                       |                                       |
| [X] Lans (Joined)                     | - Zodiac Stones Collected: 2 / 12     |
| [X] Warren (Joined)                   | - Stones: [Garnet] [Amethyst]         |
| [ ] Rauny: Req CF >= 50, ALI >= 65    | - Quicksilver ($45): [IN INVENTORY]   |
| [ ] Slust: Req CF >= 67, ALI >= 70    | - Tablet of Yaru ($49): [IN INVENTORY]|
| [!] DENEB WARNING: Forfeits Halloween | - Status: Quest on schedule           |
| [!] GALF WARNING: Forfeits Top Endings|                                       |
+---------------------------------------+---------------------------------------+
| 7. PROMOTION INSPECTOR (SELECTED UNIT)| 8. WARREN QUIZ & LORD ARCHETYPE       |
|                                       |                                       |
| - Unit: Ashe · Fighter (Lv 6)         | - Lord Archetype: Offensive Magician  |
|   -> Knight: Eligible NOW!            | - Element Affinity: Fire / Thunder    |
|   -> Samurai: ALI Too High (-21 needed| - Starting Stats: STR 68 · INT 74     |
|   -> Dragoner: Relic Required ($49)   |                                       |
+---------------------------------------+---------------------------------------+
```

### Key Readouts on Page 3:
1. **18 Special Character Recruitment Auditor**:
   - Tracks every unique character in the game and checks your current status against their recruitment conditions.
   - Displays real-time green checkmarks when your Chaos Frame and Leader Alignment meet the threshold.
   - **Critical Tradeoff Warnings**:
     - **Deneb**: Shows a warning that recruiting Deneb requires letting your Chaos Frame drop below `35`, which forfeits the Halloween Ending and makes recruiting lawful heroes much harder.
     - **Galf**: Shows a high-priority caution that recruiting the demon Galf requires lowering your CF below `20` and permanently forfeits the top 3 endings (*The World*, *The Sun*, *The Justice*).
2. **12 Zodiac Stones Tracker**:
   - Checkboxes for all 12 mystical gemstones (Garnet, Amethyst, Aquamarine, Diamond, Emerald, Pearl, Ruby, Peridot, Sapphire, Opal, Topaz, Turquoise).
   - Verifies whether you have acquired the key quest items (**Quicksilver** and **Tablet of Yaru**) needed to unlock the legendary holy sword **Brunhild**.
3. **Mod-Aware Promotion Inspector**:
   - Select any unit in your army to see their full promotion tree.
   - Shows exact requirements for every class branch: Level, Alignment range, Charisma, and required relics (such as Undead Ring for Lich or Royal Crown for Princess).
   - If you are playing with a balance mod (e.g. Dragoner Rebalance Mod), requirements update automatically to match your patched game files!
4. **Warren Quiz Archetype Decoder**:
   - Summarizes your answers to Warren's opening Tarot quiz questions and explains your Opinion Leader's natural stat growth and magic specializations.

---

## 6. Pro Tips for Achieving the Legendary Ending (*The World*)

To achieve Ending #1 (*The World*), follow this strategic checklist using the Companion Window:

1. **Keep Chaos Frame Above 75**: Use Page 1's Liberation Advisor to ensure every town is liberated by a squad with matching alignment.
2. **Never Let a Town Get Recaptured**: Keep a fast Low-Sky or High-Sky squad positioned near key liberated nodes. When the red Recapture Alert sounds on Page 1, intercept immediately.
3. **Guard Your Opinion Leader's Alignment**: Keep your Lord's Alignment between `70` and `100`. Avoid using offensive Tarot cards in easy battles (consult Page 2).
4. **Gather All 12 Zodiac Stones**: Monitor Page 3 to ensure you pick up the hidden stone on each stage before defeating the stage boss.
5. **Recruit Tristan and Rauny**: Check Page 3 to confirm your CF and Lord Alignment meet their requirements before entering their respective stages.
