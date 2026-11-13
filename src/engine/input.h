#ifndef OB_ENGINE_INPUT_H
#define OB_ENGINE_INPUT_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ==========================================================================
 * Gate 2 (Rev 9+): Three-Pillar Direct-State & Hit-Box Mouse Architecture
 *
 * DEPRECATION NOTICE (Rev 1 - Rev 8):
 * Closed-loop synthetic D-Pad button injection (comparing mouse_x/mouse_y to
 * cursor registers and ORing BTN_UP/DOWN/LEFT/RIGHT into joypad state) is
 * strictly forbidden. It triggered runaway Mode-7 camera scrolling via $14E7
 * ($00:B283 -> $00:B590) and 60Hz wrap-around spinning in the 7-icon bar.
 * ========================================================================== */

/* --- SNES Standard 16-bit Joypad Bitmasks ($A7 / LakeSnes format) --- */
#define OB_BTN_B      0x8000u
#define OB_BTN_Y      0x4000u
#define OB_BTN_SELECT 0x2000u
#define OB_BTN_START  0x1000u
#define OB_BTN_UP     0x0800u
#define OB_BTN_DOWN   0x0400u
#define OB_BTN_LEFT   0x0200u
#define OB_BTN_RIGHT  0x0100u
#define OB_BTN_A      0x0080u
#define OB_BTN_X      0x0040u
#define OB_BTN_L      0x0020u
#define OB_BTN_R      0x0010u

#define OB_BTN_DPAD_MASK (OB_BTN_UP | OB_BTN_DOWN | OB_BTN_LEFT | OB_BTN_RIGHT)

/* --- Viewport & Ergonomic Constants --- */
#define OB_VIEWPORT_WIDTH_4_3   256
#define OB_VIEWPORT_WIDTH_16_9  400
#define OB_VIEWPORT_HEIGHT      224

#define OB_TACTICAL_MIN_X       8
#define OB_TACTICAL_MIN_Y       8
#define OB_TACTICAL_MARGIN      8

#define OB_EDGE_SCROLL_MARGIN   10
#define OB_EDGE_SCROLL_SPEED    4
#define OB_ENTITY_SNAP_RADIUS   8
#define OB_MOUSE_WAKE_DELTA_PX  2
#define OB_DRAG_THRESHOLD_PX    3
#define OB_KEYBOARD_COOLDOWN_FRAMES 18 /* 300ms at 60Hz */

/* --- Verified Bank $00 / $7E WRAM Addresses ($00:B1E0 - $00:B6A6) --- */
#define OB_WRAM_SIZE               0x20000u
#define OB_PPU_OAM_SIZE            544u

/* Mode-7 Camera Scroll & Zoom Registers */
#define OB_WRAM_CAM_X              0x00BDu /* 16-bit Mode-7 camera X ($00:B64A) */
#define OB_WRAM_CAM_Y              0x00BFu /* 16-bit Mode-7 camera Y ($00:B64A) */
#define OB_WRAM_CAM_STATE          0x00CEu /* 8-bit camera transition state (0=free) */
#define OB_WRAM_ZOOM               0x14BBu /* 16-bit Mode-7 zoom factor */
#define OB_WRAM_CAM_MIN_X          0x14CBu /* 16-bit camera min X bound */
#define OB_WRAM_CAM_MIN_Y          0x14CDu /* 16-bit camera min Y bound */
#define OB_WRAM_CAM_MAX_X          0x14CFu /* 16-bit camera max X bound */
#define OB_WRAM_CAM_MAX_Y          0x14D1u /* 16-bit camera max Y bound */
#define OB_WRAM_MAP_TILES_X        0x14D3u /* 16-bit map width in 8px tiles */
#define OB_WRAM_MAP_TILES_Y        0x14D5u /* 16-bit map height in 8px tiles */
#define OB_WRAM_CAM_WORLD_X        0x14D7u /* 16-bit camera world X origin */
#define OB_WRAM_CAM_WORLD_Y        0x14D9u /* 16-bit camera world Y origin */

/* Tactical Map Cursor Registers ($00:B1E0 - $00:B56A) */
#define OB_WRAM_CUR_DIR_X          0x14DBu /* 8-bit last D-Pad X direction */
#define OB_WRAM_CUR_DIR_Y          0x14DCu /* 8-bit last D-Pad Y direction */
#define OB_WRAM_CUR_ACCEL          0x14DDu /* 8-bit D-Pad acceleration counter (1..0x50) */
#define OB_WRAM_CUR_SCREEN_X       0x14DEu /* 16-bit cursor screen X offset */
#define OB_WRAM_CUR_SCREEN_Y       0x14E0u /* 16-bit cursor screen Y offset */
#define OB_WRAM_CUR_WORLD_X        0x14E2u /* 16-bit cursor world X coordinate */
#define OB_WRAM_CUR_WORLD_Y        0x14E4u /* 16-bit cursor world Y coordinate */
#define OB_WRAM_CUR_SPRITE_FLAGS   0x14E6u /* 8-bit cursor active & animation flags */
#define OB_WRAM_CUR_EDGE_MASK      0x14E7u /* 16-bit edge-scroll trigger mask (bit0=X, bit1=Y) */

/* Deployed Squads & Cities Coordinate Tables (for +-8px Magnetic Snap) */
#define OB_WRAM_SQUAD_X_BASE       0x18AFu /* 21 x uint16_t deployed squad world X */
#define OB_WRAM_SQUAD_Y_BASE       0x18D9u /* 21 x uint16_t deployed squad world Y */
#define OB_MAX_DEPLOYED_SQUADS     21

#define OB_WRAM_CITY_X_BASE        0x1A95u /* 20 x uint16_t stage city/temple world X */
#define OB_WRAM_CITY_Y_BASE        0x1B0Du /* 20 x uint16_t stage city/temple world Y */
#define OB_MAX_STAGE_CITIES        20

/* OAM Shadow & Menu Slot Registers */
#define OB_WRAM_OAM_SHADOW         0x0100u /* Low OAM shadow ($0100..$013F) */
#define OB_WRAM_OAM1_X             0x0104u /* OAM[1] X coordinate */
#define OB_WRAM_OAM1_Y             0x0105u /* OAM[1] Y coordinate */
#define OB_WRAM_OAM1_TILE          0x0106u /* OAM[1] tile ID (0xCE=icon bar, 0xCC=grid) */
#define OB_WRAM_OAM1_ATTR          0x0107u /* OAM[1] attribute byte */

#define OB_TILE_FORMATION_FINGER   0xCCu
#define OB_TILE_ICON_BAR_FINGER    0xCEu
#define OB_OAM_OFFSCREEN_Y         0xE0u   /* 224 = off-screen Y sentinel */

#define OB_WRAM_ICON_BAR_INDEX     0x0474u /* 8-bit 7-icon command strip index (0..6) */
#define OB_WRAM_ICON_BAR_X         0x0476u /* 16-bit 7-icon command strip X (71 + 16*i) */
#define OB_WRAM_FORMATION_INDEX    0x0478u /* 8-bit 3x2 formation grid slot index (0..5) */
#define OB_WRAM_WORLD_NODE_INDEX   0x047Au /* 8-bit Continental World Map stage node index */

/* Pillar 2 Hit-Box Geometry Constants */
#define OB_ICON_BAR_COUNT          7
#define OB_ICON_BAR_X0             71
#define OB_ICON_BAR_STRIDE         16
#define OB_ICON_BAR_FINGER_OFFSET  4       /* Finger OAM[1].x = 75 + 16*slot */
#define OB_ICON_BAR_Y_MIN          107
#define OB_ICON_BAR_Y_MAX          131
#define OB_ICON_BAR_FINGER_Y       119

#define OB_FORMATION_COLS          2
#define OB_FORMATION_ROWS          3
#define OB_FORMATION_X_MIN         4
#define OB_FORMATION_X_MID         36
#define OB_FORMATION_X_MAX         72
#define OB_FORMATION_Y_ROW0_MIN    40
#define OB_FORMATION_Y_ROW0_MAX    56
#define OB_FORMATION_Y_ROW1_MAX    70
#define OB_FORMATION_Y_ROW2_MAX    88

/* Active Mouse Pillar / Context Mode */
typedef enum ObMouseMode {
    OB_MOUSE_MODE_PASSIVE = 0,        /* Idle / Cutscene / Keyboard priority (0 WRAM writes) */
    OB_MOUSE_MODE_TACTICAL_MAP = 1,   /* Pillar 1: 1:1 Direct-State + Decoupled Camera */
    OB_MOUSE_MODE_ICON_BAR = 2,       /* Pillar 2A: 7-Icon Horizontal Command Strip */
    OB_MOUSE_MODE_FORMATION_GRID = 3, /* Pillar 2B: 3x2 Unit Formation Grid */
    OB_MOUSE_MODE_WORLD_MAP = 4,      /* Pillar 3: Continental World Map Stage Nodes */
    OB_MOUSE_MODE_MENU_LIST = 5       /* Pillar 2C: Vertical Command / Tarot List */
} ObMouseMode;

/* Snap Target Classification on Tactical Map */
typedef enum ObSnapTargetType {
    OB_SNAP_NONE = 0,
    OB_SNAP_SQUAD = 1,
    OB_SNAP_CITY = 2
} ObSnapTargetType;

/* Host Mouse & Hybrid Input State Machine */
typedef struct ObMouseState {
    int viewport_w;                   /* 256 (Gate 2 4:3) or 400 (Gate 3 16:9) */
    int viewport_h;                   /* 224 */

    int snes_x;                       /* Mapped SNES X in [0, viewport_w - 1] */
    int snes_y;                       /* Mapped SNES Y in [0, viewport_h - 1] */
    int prev_snes_x;
    int prev_snes_y;

    bool mouse_active;                /* False at boot & on keyboard takeover; Zero-Invasion when false */
    bool has_prev_pos;
    uint32_t last_keyboard_frame;

    /* Button & Drag State */
    bool left_down;
    bool left_pressed;
    bool right_down;
    bool right_pressed;
    bool right_released;
    bool middle_down;

    bool drag_active;
    bool drag_moved;
    int drag_last_x;
    int drag_last_y;

    /* Telemetry & Diagnostic Outputs */
    ObMouseMode active_mode;
    ObSnapTargetType snapped_type;
    int snapped_index;
    int hovered_slot;
} ObMouseState;

/* Initialize the Three-Pillar mouse state machine (starts in passive/idle mode) */
void ob_input_init(ObMouseState *state, int viewport_width, int viewport_height);

/* Convert host window (win_x, win_y) into aspect-correct SNES viewport coordinates */
bool ob_input_map_window_to_snes(
    int win_x,
    int win_y,
    int win_w,
    int win_h,
    int viewport_w,
    int viewport_h,
    int *out_snes_x,
    int *out_snes_y
);

/* Notify input system that a physical keyboard/gamepad directional key was pressed */
void ob_input_on_keyboard_activity(ObMouseState *state, uint32_t current_frame);

/* Process host mouse movement event */
void ob_input_on_mouse_move(
    ObMouseState *state,
    int win_x,
    int win_y,
    int win_w,
    int win_h,
    uint32_t current_frame
);

/* Process host mouse button transitions */
void ob_input_on_mouse_button(
    ObMouseState *state,
    bool left_down,
    bool right_down,
    bool middle_down,
    uint32_t current_frame
);

/* Classify active screen context into one of the Three Pillars */
ObMouseMode ob_input_detect_mode(
    const ObMouseState *state,
    const uint8_t *wram,
    const uint8_t *ppu_oam
);

/* Pillar 1: Apply 1:1 Tactical Map cursor, world sync, +-8px entity snap & decoupled camera */
void ob_input_apply_tactical_map(ObMouseState *state, uint8_t *wram);

/* Pillar 2A: Apply deterministic hit-box indexing for the 7-icon horizontal command strip */
int ob_input_apply_icon_bar(ObMouseState *state, uint8_t *wram);

/* Pillar 2B: Apply deterministic hit-box indexing for the 3x2 unit formation grid */
int ob_input_apply_formation_grid(ObMouseState *state, uint8_t *wram);

/* Pillar 3: Apply Continental World Map stage node hit-testing and camera drag/edge panning */
int ob_input_apply_world_map(ObMouseState *state, uint8_t *wram, const uint8_t *ppu_oam);

/* Execute one frame of the Three-Pillar mouse architecture and return final 16-bit joypad mask */
uint16_t ob_input_step_frame(
    ObMouseState *state,
    uint8_t *wram,
    const uint8_t *ppu_oam,
    uint16_t base_joypad_mask,
    uint32_t current_frame
);

#ifdef __cplusplus
}
#endif

#endif /* OB_ENGINE_INPUT_H */
