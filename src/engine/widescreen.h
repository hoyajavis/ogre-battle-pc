#ifndef OB_ENGINE_WIDESCREEN_H
#define OB_ENGINE_WIDESCREEN_H

#include <stdbool.h>
#include <stdint.h>
#include "input.h"
#include "snes_ui_rasterizer.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Native 1x and Post-PPU 2x Master Canvas Dimensions */
#define OB_WIDE_NATIVE_W         400
#define OB_WIDE_NATIVE_H         224
#define OB_WIDE_CORE_X0          72
#define OB_WIDE_CORE_W           256
#define OB_WIDE_WING_W           72

#define OB_WIDE_2X_W             800
#define OB_WIDE_2X_H             448
#define OB_WIDE_2X_WING_W        144
#define OB_WIDE_2X_CORE_X0       144
#define OB_WIDE_2X_CORE_W        512
#define OB_WIDE_2X_RIGHT_X0      656

/* User-Toggleable Display Modes ([F10] Hotkey) */
typedef enum ObDisplayMode {
    OB_DISPLAY_16_9_TACTICIAN_WINGS = 0, /* 800x448 with 144x448 Area 1/2/3/4 SNES Wing Docks */
    OB_DISPLAY_16_9_VANILLA_HORIZON = 1, /* 800x448 full-bleed extended Mode-7 / BG / Tapestry */
    OB_DISPLAY_4_3_CLASSIC          = 2  /* 512x448 centered 4:3 with clean black pillarboxing */
} ObDisplayMode;

/* 7 Canonical Screen Contexts (from docs/ogre_battle_modernization_areas.md) */
typedef enum ObSceneId {
    OB_SCENE_TACTICAL_MAP = 0, /* Screen 3: Mode 7 Strategic Overland Map */
    OB_SCENE_COMBAT_STAGE = 1, /* Screen 4: Mode 1 Isometric Autobattle Clash */
    OB_SCENE_WORLD_MAP    = 2, /* Screen 2: Continental Map of Zenobia */
    OB_SCENE_WARREN_QUIZ  = 3, /* Screen 1: Opening Seer Tent & Tarot Quiz */
    OB_SCENE_CAMP_ROSTER  = 4, /* Screen 5: Army Organization & Promotion Workbench */
    OB_SCENE_SHOP_TEMPLE  = 5, /* Screen 6: Town Merchant / Temple Tarot Draw */
    OB_SCENE_EPILOGUE     = 6  /* Screen 7: 13-Ending Tableau & Roll Call */
} ObSceneId;

/* Right-Wing Middle Card Context Mode on Tactical Map */
typedef enum ObTacticalInspectorMode {
    OB_INSPECT_MOBILITY_NEUTRAL = 0, /* Default / Friendly Squad: Mobility & Neutral Spawn */
    OB_INSPECT_CITY_LIBERATION  = 1, /* Hovered City: Compatibility & CF Delta Advisor */
    OB_INSPECT_ENEMY_PRECLASH   = 2  /* Hovered Enemy: Pre-Clash Morality Kill Drift */
} ObTacticalInspectorMode;

/* Zero-Invasion Extracted Telemetry Snapshot for 16:9 Wing Cards */
typedef struct ObWidescreenTelemetry {
    /* Macro & Celestial State */
    uint8_t chaos_frame;
    uint32_t goth_treasury;
    int32_t noon_net_goth;
    uint8_t clock_hour;
    uint8_t clock_minute;
    bool is_daytime;

    /* Squads & Cities */
    uint8_t deployed_player_count;
    uint8_t deployed_enemy_count;
    uint8_t liberated_cities;
    uint8_t total_cities;
    uint8_t hidden_poi_count;

    /* -5 CF Recapture Threat */
    bool recapture_threat_active;
    uint8_t threat_enemy_slot;
    uint8_t threat_city_slot;
    uint16_t threat_eta_ticks;

    /* Hovered City Compatibility */
    uint8_t inspected_city_id;
    uint8_t inspected_city_ali;
    uint8_t best_squad_id;
    uint8_t best_squad_ali;
    int8_t predicted_cf_delta;

    /* Combat Stage State */
    uint16_t player_clash_dmg;
    uint16_t enemy_clash_dmg;
    uint8_t tactic_stance; /* 0=LDR, 1=STR, 2=WEK, 3=BST */
    uint8_t tarot_hand[14];
    uint8_t tarot_count;
    uint8_t lord_level;
    uint8_t lord_ali;

    /* Campaign & Zodiac Progress */
    uint16_t zodiac_mask;  /* Bitmask of 12 Zodiac Stones (0x50..0x5B) */
    uint8_t zodiac_count;
    bool has_quicksilver;
    bool has_tablet_of_yaru;
    bool brunhild_ready;
} ObWidescreenTelemetry;

/* Master Widescreen Compositor State */
typedef struct ObWidescreenState {
    ObDisplayMode display_mode;
    ObSceneId active_scene;
    ObTacticalInspectorMode inspector_mode;
    bool grimoire_open;       /* [Tab] In-Window Campaign Grimoire Overlay */
    bool poi_radar_enabled;   /* [P] Hidden PoI Radar toggle */
    uint8_t selected_squad;   /* Active squad index (0..9) */
    ObWidescreenTelemetry telemetry;
} ObWidescreenState;

/* Initialize widescreen compositor state (defaults to 16:9 Tactician Wings) */
void ob_widescreen_init(ObWidescreenState *state);

/* Cycle display mode ([F10]: 16:9 Tactician Wings -> 16:9 Vanilla Horizon -> 4:3 Classic) */
void ob_widescreen_cycle_display_mode(ObWidescreenState *state);

/* Toggle in-window [Tab] Campaign Grimoire Overlay */
void ob_widescreen_toggle_grimoire(ObWidescreenState *state);

/* Detect active screen context from authoritative WRAM and OAM state (strictly const) */
ObSceneId ob_widescreen_detect_scene(const uint8_t *wram, const uint8_t *ppu_oam);

/* Extract live Area 1 telemetry from const WRAM (Zero-Invasion: 0 bytes written to WRAM) */
void ob_widescreen_extract_telemetry(
    ObWidescreenState *state,
    const uint8_t *wram,
    const ObMouseState *mouse
);

/* Render complete 800x448 (2x of 400x224) 16:9 frame into out_rgba_800x448 */
void ob_widescreen_render_frame(
    const ObWidescreenState *state,
    const uint8_t *wram,
    const uint32_t *core_256x224_rgba, /* Optional native 256x224 PPU frame (NULL = procedural preview) */
    uint32_t *out_rgba_800x448
);

#ifdef __cplusplus
}
#endif

#endif /* OB_ENGINE_WIDESCREEN_H */
