#include "input.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* --- Little-Endian 16-bit WRAM Access Helpers --- */
static inline uint16_t wram_read_u16(const uint8_t *wram, uint32_t addr) {
    return (uint16_t)((uint16_t)wram[addr] | ((uint16_t)wram[addr + 1u] << 8u));
}

static inline int16_t wram_read_i16(const uint8_t *wram, uint32_t addr) {
    return (int16_t)wram_read_u16(wram, addr);
}

static inline void wram_write_u16(uint8_t *wram, uint32_t addr, uint16_t val) {
    wram[addr]      = (uint8_t)(val & 0xFFu);
    wram[addr + 1u] = (uint8_t)((val >> 8u) & 0xFFu);
}

static inline int clamp_int(int val, int lo, int hi) {
    if (val < lo) return lo;
    if (val > hi) return hi;
    return val;
}

void ob_input_init(ObMouseState *state, int viewport_width, int viewport_height) {
    if (state == NULL) {
        return;
    }
    memset(state, 0, sizeof(*state));
    state->viewport_w       = (viewport_width > 0) ? viewport_width : OB_VIEWPORT_WIDTH_4_3;
    state->viewport_h       = (viewport_height > 0) ? viewport_height : OB_VIEWPORT_HEIGHT;
    state->edge_pan_enabled = true;
    state->edge_pan_speed   = OB_EDGE_SCROLL_SPEED;
    state->snes_x           = state->viewport_w / 2;
    state->snes_y           = state->viewport_h / 2;
    state->prev_snes_x      = state->snes_x;
    state->prev_snes_y      = state->snes_y;
    state->mouse_active     = false;
    state->has_prev_pos     = true;
    state->active_mode      = OB_MOUSE_MODE_PASSIVE;
    state->snapped_type     = OB_SNAP_NONE;
    state->snapped_index    = -1;
    state->hovered_slot     = -1;
}

bool ob_input_map_window_to_snes(
    int win_x,
    int win_y,
    int win_w,
    int win_h,
    int viewport_w,
    int viewport_h,
    int *out_snes_x,
    int *out_snes_y
) {
    if (win_w <= 0 || win_h <= 0 || viewport_w <= 0 || viewport_h <= 0) {
        return false;
    }

    /* Compute aspect-correct letterbox / pillarbox active drawing rectangle */
    int active_w = win_w;
    int active_h = (win_w * viewport_h) / viewport_w;
    int offset_x = 0;
    int offset_y = 0;

    if (active_h > win_h) {
        active_h = win_h;
        active_w = (win_h * viewport_w) / viewport_h;
        offset_x = (win_w - active_w) / 2;
    } else {
        offset_y = (win_h - active_h) / 2;
    }

    if (active_w <= 0 || active_h <= 0) {
        return false;
    }

    int rel_x = win_x - offset_x;
    int rel_y = win_y - offset_y;
    bool inside = (rel_x >= 0 && rel_x < active_w && rel_y >= 0 && rel_y < active_h);

    int mapped_x = (rel_x * viewport_w) / active_w;
    int mapped_y = (rel_y * viewport_h) / active_h;

    mapped_x = clamp_int(mapped_x, 0, viewport_w - 1);
    mapped_y = clamp_int(mapped_y, 0, viewport_h - 1);

    if (out_snes_x != NULL) {
        *out_snes_x = mapped_x;
    }
    if (out_snes_y != NULL) {
        *out_snes_y = mapped_y;
    }
    return inside;
}

void ob_input_on_keyboard_activity(ObMouseState *state, uint32_t current_frame) {
    if (state == NULL) {
        return;
    }
    /* Immediate hybrid handoff: keyboard/gamepad takes exclusive control */
    state->mouse_active        = false;
    state->drag_active         = false;
    state->drag_moved          = false;
    state->left_pulse_frames   = 0u;
    state->right_pulse_frames  = 0u;
    state->last_keyboard_frame = current_frame;
    state->active_mode         = OB_MOUSE_MODE_PASSIVE;
}

void ob_input_on_mouse_move(
    ObMouseState *state,
    int win_x,
    int win_y,
    int win_w,
    int win_h,
    uint32_t current_frame
) {
    if (state == NULL) {
        return;
    }

    int new_x = state->snes_x;
    int new_y = state->snes_y;
    ob_input_map_window_to_snes(
        win_x,
        win_y,
        win_w,
        win_h,
        state->viewport_w,
        state->viewport_h,
        &new_x,
        &new_y
    );

    if (!state->has_prev_pos) {
        state->prev_snes_x  = new_x;
        state->prev_snes_y  = new_y;
        state->has_prev_pos = true;
    }

    int dx = abs(new_x - state->prev_snes_x);
    int dy = abs(new_y - state->prev_snes_y);

    state->snes_x = new_x;
    state->snes_y = new_y;

    bool cooldown_expired =
        (state->last_keyboard_frame == 0u) ||
        (current_frame >= state->last_keyboard_frame + OB_KEYBOARD_COOLDOWN_FRAMES);

    if ((dx + dy) >= OB_MOUSE_WAKE_DELTA_PX && cooldown_expired) {
        state->mouse_active = true;
        state->prev_snes_x  = new_x;
        state->prev_snes_y  = new_y;
    } else if (state->mouse_active) {
        state->prev_snes_x  = new_x;
        state->prev_snes_y  = new_y;
    }
}

void ob_input_on_mouse_button(
    ObMouseState *state,
    bool left_down,
    bool right_down,
    bool middle_down,
    uint32_t current_frame
) {
    if (state == NULL) {
        return;
    }
    (void)current_frame;

    state->left_pressed   = (left_down && !state->left_down);
    state->right_pressed  = (right_down && !state->right_down);
    state->right_released = (!right_down && state->right_down);

    state->left_down   = left_down;
    state->right_down  = right_down;
    state->middle_down = middle_down;

    if (left_down || right_down || middle_down) {
        state->mouse_active = true;
    }

    /* Right-click or Middle-click initiates camera grab-drag in Pillar 1 & 3 */
    bool pan_button_down = (right_down || middle_down);
    if (pan_button_down && !state->drag_active) {
        state->drag_active = true;
        state->drag_moved  = false;
        state->drag_last_x = state->snes_x;
        state->drag_last_y = state->snes_y;
    } else if (!pan_button_down && state->drag_active) {
        state->drag_active = false;
    }
}

void ob_input_set_wings_enabled(ObMouseState *state, bool wings_enabled) {
    if (state == NULL) {
        return;
    }
    state->wings_enabled = wings_enabled;
}

void ob_input_set_edge_pan(ObMouseState *state, bool enabled, int speed) {
    if (state == NULL) {
        return;
    }
    state->edge_pan_enabled = enabled;
    state->edge_pan_speed   = (speed > 0) ? clamp_int(speed, 1, 16) : OB_EDGE_SCROLL_SPEED;
}

static inline int get_core_x(const ObMouseState *state) {
    if (state->viewport_w >= OB_VIEWPORT_WIDTH_16_9) {
        return state->snes_x - 72;
    }
    return state->snes_x;
}

static inline bool is_uninit_or_sentinel_u16(uint16_t raw) {
    return (raw == 0xFFFFu || raw == 0x5555u || raw == 0x7FFFu);
}

/* Decode a squad or city coordinate from $18AF/$18D9 or $1A95/$1B0D into world pixels.
 * In live Bank $00 ($00:B7E8-$00:B7F4, $00:BA3D-$00:BB05), entity coordinates are stored
 * as 12.4 fixed-point subpixels (world_px = raw >> 4) when map_tiles ($14D3/$14D5) matches
 * the live stage dimensions (e.g., 32..64 tiles -> 256..512 world px, while raw subpixels
 * are 2560..6144). In synthetic unit tests, coordinates are small 1:1 world pixels (<= 1024). */
static inline bool decode_entity_world_xy(
    const uint8_t *wram,
    uint16_t raw_x,
    uint16_t raw_y,
    int max_world_x,
    int max_world_y,
    int *out_wx,
    int *out_wy
) {
    if (is_uninit_or_sentinel_u16(raw_x) || is_uninit_or_sentinel_u16(raw_y) ||
        (raw_x == 0u && raw_y == 0u)) {
        return false;
    }

    /* Live Bank $00 populates $00CB == 0x01 and 12.4 subpixels (or raw values exceeding max_world) */
    bool live_subpixel = (wram[0x00CBu] == 0x01u && (raw_x > 1024u || raw_y > 1024u)) ||
                         ((int)raw_x > max_world_x || (int)raw_y > max_world_y);
    if (live_subpixel) {
        int wx = (int)(raw_x >> 4u);
        int wy = (int)(raw_y >> 4u);
        if (wx <= 0 && wy <= 0) {
            return false;
        }
        if (wx > 4096 || wy > 4096) {
            return false;
        }
        *out_wx = wx;
        *out_wy = wy;
        return true;
    }

    if (raw_x > 4096u || raw_y > 4096u) {
        return false;
    }
    *out_wx = (int)raw_x;
    *out_wy = (int)raw_y;
    return true;
}

/* Hit-test the live Bank $02 menu slot table ($0424 count, $0426 X, $0446 Y, $04B2 type).
 * Executed at $02:EC90-$02:F190 for all Battle Map & Camp command bars, 3x2 formation grids,
 * and 2-button prompts. Returns the matched slot index (0..$0424-1) or -1 if outside all slots. */
static int apply_live_bank02_menu_slots(ObMouseState *state, uint8_t *wram, int core_x) {
    uint8_t count = wram[OB_WRAM_MENU_SLOT_COUNT];
    if (count == 0u || count == 0x55u || count > OB_MAX_MENU_SLOTS) {
        return -1;
    }

    int best_slot = -1;
    int best_dist = 1000000;

    for (uint8_t i = 0; i < count; ++i) {
        uint8_t sx   = wram[OB_WRAM_MENU_SLOT_X_BASE + i];
        uint8_t sy   = wram[OB_WRAM_MENU_SLOT_Y_BASE + i];
        uint8_t type = wram[OB_WRAM_MENU_SLOT_TYPE_BASE + i];
        if (sx == 0xFFu || sy == 0xFFu || sy >= OB_OAM_OFFSCREEN_Y) {
            continue;
        }

        int x0, x1, y0, y1, cx, cy;
        if (type < 0x80u) {
            /* Command Strip / Popup Icon ($02:ECB0: finger at sx+4, sy+10; 16x24 hit-box) */
            x0 = (int)sx - 2;
            x1 = (int)sx + 16;
            y0 = (int)sy - 2;
            y1 = (int)sy + 22;
            cx = (int)sx + 8;
            cy = (int)sy + 10;
        } else if (type == 0x80u) {
            /* Squad Header Banner Slot ($02:803A: sx=88, sy=38) */
            x0 = (int)sx - 12;
            x1 = (int)sx + 64;
            y0 = (int)sy - 8;
            y1 = (int)sy + 12;
            cx = (int)sx + 16;
            cy = (int)sy;
        } else {
            /* 3x2 Unit Formation Grid Slot ($02:ED00: type >= 0x81 / 0xFF, finger at sx-10, sy) */
            x0 = (int)sx - 14;
            x1 = (int)sx + 22;
            y0 = (int)sy - 8;
            y1 = (int)sy + 10;
            cx = (int)sx + 4;
            cy = (int)sy;
        }

        if (core_x >= x0 && core_x < x1 && state->snes_y >= y0 && state->snes_y < y1) {
            int d = abs(core_x - cx) + abs(state->snes_y - cy);
            if (d < best_dist) {
                best_dist = d;
                best_slot = (int)i;
            }
        }
    }

    if (best_slot >= 0) {
        uint8_t slot = (uint8_t)best_slot;
        uint8_t sx   = wram[OB_WRAM_MENU_SLOT_X_BASE + slot];
        uint8_t sy   = wram[OB_WRAM_MENU_SLOT_Y_BASE + slot];
        uint8_t type = wram[OB_WRAM_MENU_SLOT_TYPE_BASE + slot];
        bool is_camp = (wram[0x04E0u] == 0x03u);

        wram[OB_WRAM_ICON_BAR_INDEX] = slot;
        wram[OB_WRAM_ICON_BAR_X]     = sx;
        wram[OB_WRAM_ICON_BAR_Y]     = sy;

        if (type < 0x80u) {
            wram[OB_WRAM_MENU_SAVED_ICON] = slot;
            wram[OB_WRAM_OAM1_X]          = (uint8_t)(sx + OB_ICON_BAR_FINGER_OFFSET);
            wram[OB_WRAM_OAM1_Y]          = (uint8_t)(sy + OB_ICON_BAR_FINGER_Y_OFF);
            wram[OB_WRAM_OAM1_TILE]       = is_camp ? OB_TILE_ICON_BAR_FINGER : OB_TILE_LIVE_ICON_BAR_FINGER;
        } else {
            if (type >= 0x81u) {
                wram[OB_WRAM_MENU_SAVED_GRID]  = slot;
                wram[OB_WRAM_FORMATION_INDEX] = slot;
            }
            wram[OB_WRAM_OAM1_X]    = (sx >= (uint8_t)OB_GRID_FINGER_X_OFF)
                                      ? (uint8_t)(sx - (uint8_t)OB_GRID_FINGER_X_OFF)
                                      : 0u;
            wram[OB_WRAM_OAM1_Y]    = sy;
            wram[OB_WRAM_OAM1_TILE] = is_camp ? OB_TILE_FORMATION_FINGER : OB_TILE_LIVE_FORMATION_FINGER;
        }

        state->hovered_slot = best_slot;
        return best_slot;
    }

    return -1;
}

ObMouseMode ob_input_detect_mode(
    const ObMouseState *state,
    const uint8_t *wram,
    const uint8_t *ppu_oam
) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return OB_MOUSE_MODE_PASSIVE;
    }

    uint8_t cb = wram[0x00CBu];
    uint8_t cc = wram[0x00CCu];
    bool uninit_55 = (wram[0x07BAu] == 0x55u);

    /* Gate 3 Widescreen Wing Docks (Left Wing X: 0..71, Right Wing X: 328..399) */
    if (!uninit_55 && state->wings_enabled && state->viewport_w >= OB_VIEWPORT_WIDTH_16_9 && !state->drag_active) {
        if (state->snes_x < 72) {
            return OB_MOUSE_MODE_LEFT_WING;
        }
        if (state->snes_x >= 328) {
            return OB_MOUSE_MODE_RIGHT_WING;
        }
    }

    uint8_t oam1_y    = wram[OB_WRAM_OAM1_Y];
    uint8_t oam1_tile = wram[OB_WRAM_OAM1_TILE];
    uint8_t slot_cnt  = wram[OB_WRAM_MENU_SLOT_COUNT];
    bool has_live_menu_table = (!uninit_55 && slot_cnt > 0u && slot_cnt != 0x55u && slot_cnt <= OB_MAX_MENU_SLOTS);

    /* 1. Pillar 2A: Horizontal Command Strip / Icon Bar
     *    - Synthetic/Camp: tile 0xCE at Y=119
     *    - Live Battle Map ($02:ECDE): tile 0x6A (or 0xCE) with active Bank $02 slot table ($0424 > 0) */
    if (oam1_y < OB_OAM_OFFSCREEN_Y) {
        if (oam1_tile == OB_TILE_ICON_BAR_FINGER && (oam1_y == OB_ICON_BAR_FINGER_Y || has_live_menu_table)) {
            return OB_MOUSE_MODE_ICON_BAR;
        }
        if (oam1_tile == OB_TILE_LIVE_ICON_BAR_FINGER &&
            (has_live_menu_table || oam1_y == OB_ICON_BAR_FINGER_Y || oam1_y == OB_ICON_BAR_POPUP_FINGER_Y)) {
            return OB_MOUSE_MODE_ICON_BAR;
        }
    }

    /* 2. Pillar 2B: 3x2 Unit Formation Grid
     *    - Synthetic/Camp: tile 0xCC with active Y < 224
     *    - Live Battle Map ($02:ED25): tile 0x68 with active Bank $02 slot table ($0424 > 0) */
    if (oam1_y < OB_OAM_OFFSCREEN_Y) {
        if (oam1_tile == OB_TILE_FORMATION_FINGER) {
            return OB_MOUSE_MODE_FORMATION_GRID;
        }
        if (oam1_tile == OB_TILE_LIVE_FORMATION_FINGER && has_live_menu_table) {
            return OB_MOUSE_MODE_FORMATION_GRID;
        }
    }

    /* 2.5. Pillar 3 (Live): Continental World Map Sword Cursor in OAM[0]
     *      Verified live: OAM[0] ($0100..$0103) draws sword tile 0x6E at Y < 224
     *      while $00CB == 0x01, $00CC == 0x10, and battlefield cursor is inactive ($14E6 & 0x80).
     *      Must be checked BEFORE Tactical Map so $00CB == 0x01 does not misclassify it. */
    uint8_t oam0_y    = wram[OB_WRAM_OAM0_Y];
    uint8_t oam0_tile = wram[OB_WRAM_OAM0_TILE];
    uint8_t tac_flags = wram[OB_WRAM_CUR_SPRITE_FLAGS];
    if (!uninit_55 && oam0_y < OB_OAM_OFFSCREEN_Y && oam0_tile == OB_TILE_WORLD_MAP_SWORD &&
        ((tac_flags & 0x80u) != 0u || tac_flags == 0x55u)) {
        return OB_MOUSE_MODE_WORLD_MAP;
    }

    /* 3. Pillar 1: Tactical Battlefield Map (checked BEFORE OAM World Map scan so battlefield sprites don't collide!)
     * Real game: $00CB==0x01, $00CC==0x10, $07BA!=0x55.
     * Mock/test compat: ($14E6 & 0xC0) != 0 and != 0x55 (LakeSnes uninit) with $00CE == 0. */
    if (cb == 0x01u && cc == 0x10u &&
        wram[OB_WRAM_CAM_STATE] == 0x00u && wram[0x07BAu] != 0x55u) {
        return OB_MOUSE_MODE_TACTICAL_MAP;
    }
    if ((tac_flags & 0xC0u) != 0u && tac_flags != 0x55u && wram[OB_WRAM_CAM_STATE] == 0u) {
        return OB_MOUSE_MODE_TACTICAL_MAP;
    }

    /* 4. Pillar 3: Continental World Map (real WRAM state or OAM stage banners) */
    uint16_t world_flag = (uint16_t)(wram[0x07A2u] | ((uint16_t)wram[0x07A3u] << 8u));
    if (((cb == 0x03u && cc >= 0x0Bu) || cb == 0x05u || cb == 0x06u || (cb == 0x00u && cc == 0x10u)) &&
        world_flag != 0x0000u && world_flag != 0x5555u && ppu_oam != NULL) {
        return OB_MOUSE_MODE_WORLD_MAP;
    }
    if ((cb == 0x05u || cb == 0x06u || (cb == 0u && cc == 0u)) &&
        oam1_y == OB_OAM_OFFSCREEN_Y && (tac_flags & 0xC0u) == 0u && ppu_oam != NULL) {
        for (int i = 1; i < 36; ++i) {
            uint8_t spr_y    = ppu_oam[i * 4 + 1];
            uint8_t spr_attr = ppu_oam[i * 4 + 3];
            if (spr_y < OB_OAM_OFFSCREEN_Y && (spr_attr & 0x38u) == 0x38u) {
                return OB_MOUSE_MODE_WORLD_MAP;
            }
        }
    }

    return OB_MOUSE_MODE_PASSIVE;
}

static void apply_decoupled_camera_pan(ObMouseState *state, uint8_t *wram) {
    uint16_t cam_x_raw = wram_read_u16(wram, OB_WRAM_CAM_X);
    uint16_t cam_y_raw = wram_read_u16(wram, OB_WRAM_CAM_Y);
    if (cam_x_raw == 0x5555u && cam_y_raw == 0x5555u) {
        return;
    }

    int cam_x = (int)(int16_t)cam_x_raw;
    int cam_y = (int)(int16_t)cam_y_raw;

    uint16_t min_x_raw = wram_read_u16(wram, OB_WRAM_CAM_MIN_X);
    uint16_t min_y_raw = wram_read_u16(wram, OB_WRAM_CAM_MIN_Y);
    uint16_t max_x_raw = wram_read_u16(wram, OB_WRAM_CAM_MAX_X);
    uint16_t max_y_raw = wram_read_u16(wram, OB_WRAM_CAM_MAX_Y);

    int min_x = (int)(int16_t)min_x_raw;
    int min_y = (int)(int16_t)min_y_raw;
    int max_x = (int)(int16_t)max_x_raw;
    int max_y = (int)(int16_t)max_y_raw;

    if (min_x_raw == 0x5555u || max_x_raw == 0x5555u || max_x <= min_x) {
        min_x = 0;
        max_x = 1024;
    }
    if (min_y_raw == 0x5555u || max_y_raw == 0x5555u || max_y <= min_y) {
        min_y = 0;
        max_y = 1024;
    }

    int pan_dx = 0;
    int pan_dy = 0;

    if (state->drag_active) {
        int dx = state->drag_last_x - state->snes_x;
        int dy = state->drag_last_y - state->snes_y;
        if (abs(dx) + abs(dy) >= OB_DRAG_THRESHOLD_PX || state->drag_moved) {
            state->drag_moved  = true;
            pan_dx             = dx;
            pan_dy             = dy;
            state->drag_last_x = state->snes_x;
            state->drag_last_y = state->snes_y;
        }
    } else if (state->edge_pan_enabled) {
        int edge_speed = (state->edge_pan_speed > 0) ? state->edge_pan_speed : OB_EDGE_SCROLL_SPEED;
        /* Narrow 10px viewport edge-scroll margins */
        if (state->snes_x < OB_EDGE_SCROLL_MARGIN) {
            pan_dx = -edge_speed;
        } else if (state->snes_x >= state->viewport_w - OB_EDGE_SCROLL_MARGIN) {
            pan_dx = edge_speed;
        }

        if (state->snes_y < OB_EDGE_SCROLL_MARGIN) {
            pan_dy = -edge_speed;
        } else if (state->snes_y >= state->viewport_h - OB_EDGE_SCROLL_MARGIN) {
            pan_dy = edge_speed;
        }
    }

    if (pan_dx != 0 || pan_dy != 0) {
        int new_cam_x = clamp_int(cam_x + pan_dx, min_x, max_x);
        int new_cam_y = clamp_int(cam_y + pan_dy, min_y, max_y);
        wram_write_u16(wram, OB_WRAM_CAM_X, (uint16_t)(int16_t)new_cam_x);
        wram_write_u16(wram, OB_WRAM_CAM_Y, (uint16_t)(int16_t)new_cam_y);
        wram_write_u16(wram, OB_WRAM_CAM_WORLD_X, (uint16_t)(int16_t)new_cam_x);
        wram_write_u16(wram, OB_WRAM_CAM_WORLD_Y, (uint16_t)(int16_t)new_cam_y);
    }
}

void ob_input_apply_tactical_map(ObMouseState *state, uint8_t *wram) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return;
    }

    /* When a modal tutorial/dialogue/deployment box has hidden the tactical cursor ($14E6 bit 7 set)
     * in the live 65816 engine ($00CB == 0x01), do not mutate cursor or camera registers behind it. */
    if (wram[0x00CBu] == 0x01u && (wram[OB_WRAM_CUR_SPRITE_FLAGS] & 0x80u) != 0u) {
        return;
    }

    /* Step 1: Update decoupled Mode-7 camera ONLY on Right/Middle-drag or 10px edge margin */
    apply_decoupled_camera_pan(state, wram);

    /* Step 2: Compute 1:1 viewport screen coordinates across the active core viewport */
    int active_core_w = (state->viewport_w >= OB_VIEWPORT_WIDTH_16_9)
                        ? OB_VIEWPORT_WIDTH_4_3
                        : state->viewport_w;
    int core_x        = get_core_x(state);
    int max_screen_x  = active_core_w - 1 - OB_TACTICAL_MARGIN;
    int max_screen_y  = state->viewport_h - 1 - OB_TACTICAL_MARGIN;
    int screen_x      = clamp_int(core_x, OB_TACTICAL_MIN_X, max_screen_x);
    int screen_y      = clamp_int(state->snes_y, OB_TACTICAL_MIN_Y, max_screen_y);

    /* Step 3: Synchronize cursor world coordinates ($14E2, $14E4) from signed camera + screen offset */
    int cam_x = (int)wram_read_i16(wram, OB_WRAM_CAM_X);
    int cam_y = (int)wram_read_i16(wram, OB_WRAM_CAM_Y);

    int map_tiles_x = (int)wram_read_u16(wram, OB_WRAM_MAP_TILES_X);
    int map_tiles_y = (int)wram_read_u16(wram, OB_WRAM_MAP_TILES_Y);
    int max_world_x = (map_tiles_x > 0 && map_tiles_x != 0x5555) ? ((map_tiles_x << 3) - 1) : 2047;
    int max_world_y = (map_tiles_y > 0 && map_tiles_y != 0x5555) ? ((map_tiles_y << 3) - 1) : 2047;

    int raw_world_x = clamp_int(cam_x + screen_x, 0, max_world_x);
    int raw_world_y = clamp_int(cam_y + screen_y, 0, max_world_y);
    int world_x     = raw_world_x;
    int world_y     = raw_world_y;

    /* Step 4: Magnetic Entity Snapping (+-8px entry, +-12px keep hysteresis) to Deployed Squads & Cities.
     * In live Bank $00 ($00:B40C-$00:B453), squad hit-testing compares ($14DE, $14E0) against the
     * Mode-7 projected screen coordinates ($14ED + 2*i, $1517 + 2*i) computed by $00:B7C0, while
     * $18AF/$18D9 and $1A95/$1B0D store 12.4 fixed-point subpixels (world_px = raw >> 4). */
    ObSnapTargetType prev_type = state->snapped_type;
    int prev_index             = state->snapped_index;
    state->snapped_type        = OB_SNAP_NONE;
    state->snapped_index       = -1;
    int best_dist_sq           = (12 * 12) * 2 + 1;

    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        uint16_t sx_raw = wram_read_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2));
        uint16_t sy_raw = wram_read_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2));
        int sq_wx = 0, sq_wy = 0;
        if (!decode_entity_world_xy(wram, sx_raw, sy_raw, max_world_x, max_world_y, &sq_wx, &sq_wy)) {
            continue;
        }
        int radius = (prev_type == OB_SNAP_SQUAD && prev_index == i) ? 12 : OB_ENTITY_SNAP_RADIUS;

        /* Check if live Bank $00 projected screen coordinates ($14ED, $1517) are valid on screen */
        int16_t proj_sx = (int16_t)wram_read_u16(wram, OB_WRAM_SQUAD_SCREEN_X_BASE + (uint32_t)(i * 2));
        int16_t proj_sy = (int16_t)wram_read_u16(wram, OB_WRAM_SQUAD_SCREEN_Y_BASE + (uint32_t)(i * 2));
        bool has_proj = (wram[0x00CBu] == 0x01u &&
                         proj_sx >= OB_TACTICAL_MIN_X && proj_sx <= max_screen_x &&
                         proj_sy >= OB_TACTICAL_MIN_Y && proj_sy <= max_screen_y);

        /* In $00:B376-$00:B445, hit-box is [$14DE-16..$14DE, $14E0-16..$14E0] around ($14ED, $1517),
         * so centering the cursor at (proj_sx + 7, proj_sy + 11) aligns with both $00:B810 and $00:B410. */
        int target_sx = has_proj ? clamp_int((int)proj_sx + 7, OB_TACTICAL_MIN_X, max_screen_x)
                                 : clamp_int(sq_wx - cam_x, OB_TACTICAL_MIN_X, max_screen_x);
        int target_sy = has_proj ? clamp_int((int)proj_sy + 11, OB_TACTICAL_MIN_Y, max_screen_y)
                                 : clamp_int(sq_wy - cam_y, OB_TACTICAL_MIN_Y, max_screen_y);

        int dx = has_proj ? (target_sx - screen_x) : (sq_wx - raw_world_x);
        int dy = has_proj ? (target_sy - screen_y) : (sq_wy - raw_world_y);
        if (abs(dx) <= radius && abs(dy) <= radius) {
            int d2 = dx * dx + dy * dy;
            if (d2 < best_dist_sq) {
                best_dist_sq         = d2;
                world_x              = sq_wx;
                world_y              = sq_wy;
                screen_x             = target_sx;
                screen_y             = target_sy;
                state->snapped_type  = OB_SNAP_SQUAD;
                state->snapped_index = i;
            }
        }
    }

    if (state->snapped_type == OB_SNAP_NONE) {
        for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
            uint16_t cx_raw = wram_read_u16(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2));
            uint16_t cy_raw = wram_read_u16(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2));
            int city_wx = 0, city_wy = 0;
            if (!decode_entity_world_xy(wram, cx_raw, cy_raw, max_world_x, max_world_y, &city_wx, &city_wy)) {
                continue;
            }
            int radius = (prev_type == OB_SNAP_CITY && prev_index == j) ? 12 : OB_ENTITY_SNAP_RADIUS;
            int dx = city_wx - raw_world_x;
            int dy = city_wy - raw_world_y;
            if (abs(dx) <= radius && abs(dy) <= radius) {
                int d2 = dx * dx + dy * dy;
                if (d2 < best_dist_sq) {
                    best_dist_sq         = d2;
                    world_x              = city_wx;
                    world_y              = city_wy;
                    screen_x             = clamp_int(world_x - cam_x, OB_TACTICAL_MIN_X, max_screen_x);
                    screen_y             = clamp_int(world_y - cam_y, OB_TACTICAL_MIN_Y, max_screen_y);
                    state->snapped_type  = OB_SNAP_CITY;
                    state->snapped_index = j;
                }
            }
        }
    }

    /* Step 5: Commit 1:1 screen & world coordinates and clear $14E7 edge-scroll trigger */
    wram_write_u16(wram, OB_WRAM_CUR_SCREEN_X, (uint16_t)screen_x);
    wram_write_u16(wram, OB_WRAM_CUR_SCREEN_Y, (uint16_t)screen_y);
    wram_write_u16(wram, OB_WRAM_CUR_WORLD_X, (uint16_t)world_x);
    wram_write_u16(wram, OB_WRAM_CUR_WORLD_Y, (uint16_t)world_y);

    /* Keep OAM[1] shadow ($0104, $0105) synchronized on the same frame when the cursor sprite
     * ($14E6 == 0x00 or 0x01) is visible, matching $00:B542 offsets (+0,-4 for 0x00; -4,-11 for 0x01). */
    uint8_t cur_flags = wram[OB_WRAM_CUR_SPRITE_FLAGS];
    if ((cur_flags & 0x80u) == 0u && cur_flags != 0x55u) {
        int oam_dx = ((cur_flags & 0x3Fu) == 1u) ? -4 : 0;
        int oam_dy = ((cur_flags & 0x3Fu) == 1u) ? -11 : -4;
        wram[OB_WRAM_OAM1_X] = (uint8_t)clamp_int(screen_x + oam_dx, 0, 255);
        wram[OB_WRAM_OAM1_Y] = (uint8_t)clamp_int(screen_y + oam_dy, 0, 223);
    }

    /* Clear $14E7 so $00:B590 never fires runaway camera scrolling */
    wram_write_u16(wram, OB_WRAM_CUR_EDGE_MASK, 0x0000u);
    wram[OB_WRAM_CUR_DIR_X] = 0u;
    wram[OB_WRAM_CUR_DIR_Y] = 0u;
    wram[OB_WRAM_CUR_ACCEL] = 1u;
}

int ob_input_apply_icon_bar(ObMouseState *state, uint8_t *wram) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return -1;
    }

    int core_x = get_core_x(state);

    /* If the live Bank $02 menu slot table ($0424 > 0) is populated, hit-test actual active slots
     * (supporting 2-icon yes/no prompts, 3-icon/7-icon command strips, and jumping into the 3x2 grid). */
    uint8_t slot_cnt = wram[OB_WRAM_MENU_SLOT_COUNT];
    if (wram[0x07BAu] != 0x55u && slot_cnt > 0u && slot_cnt != 0x55u && slot_cnt <= OB_MAX_MENU_SLOTS) {
        int live_slot = apply_live_bank02_menu_slots(state, wram, core_x);
        if (live_slot >= 0) {
            return live_slot;
        }
        state->hovered_slot = -1;
        return -1;
    }

    /* Synthetic / Canonical 7-Icon Bar Hit-Box (X: 71..183, Y: 107..131) */
    int x_max  = OB_ICON_BAR_X0 + (OB_ICON_BAR_COUNT * OB_ICON_BAR_STRIDE);
    if (core_x >= OB_ICON_BAR_X0 && core_x < x_max &&
        state->snes_y >= OB_ICON_BAR_Y_MIN && state->snes_y <= OB_ICON_BAR_Y_MAX) {
        int slot        = (core_x - OB_ICON_BAR_X0) / OB_ICON_BAR_STRIDE;
        slot            = clamp_int(slot, 0, OB_ICON_BAR_COUNT - 1);
        uint16_t icon_x = (uint16_t)(OB_ICON_BAR_X0 + slot * OB_ICON_BAR_STRIDE);

        wram[OB_WRAM_ICON_BAR_INDEX] = (uint8_t)slot;
        wram_write_u16(wram, OB_WRAM_ICON_BAR_X, icon_x);
        wram[OB_WRAM_OAM1_X] = (uint8_t)(icon_x + OB_ICON_BAR_FINGER_OFFSET);
        wram[OB_WRAM_OAM1_Y] = (uint8_t)OB_ICON_BAR_FINGER_Y;

        state->hovered_slot = slot;
        return slot;
    }

    /* Outside the 7-icon strip: preserve existing selection, zero wrap-around */
    state->hovered_slot = -1;
    return -1;
}

int ob_input_apply_formation_grid(ObMouseState *state, uint8_t *wram) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return -1;
    }

    int core_x = get_core_x(state);

    /* If the live Bank $02 menu slot table ($0424 > 0) is populated, hit-test actual active slots
     * (supporting both the 3x2 unit formation grid and jumping back to the command icon strip). */
    uint8_t slot_cnt = wram[OB_WRAM_MENU_SLOT_COUNT];
    if (wram[0x07BAu] != 0x55u && slot_cnt > 0u && slot_cnt != 0x55u && slot_cnt <= OB_MAX_MENU_SLOTS) {
        int live_slot = apply_live_bank02_menu_slots(state, wram, core_x);
        if (live_slot >= 0) {
            return live_slot;
        }
        state->hovered_slot = -1;
        return -1;
    }

    if (core_x >= OB_FORMATION_X_MIN && core_x < OB_FORMATION_X_MAX &&
        state->snes_y >= OB_FORMATION_Y_ROW0_MIN && state->snes_y < OB_FORMATION_Y_ROW2_MAX) {
        int col = (core_x >= OB_FORMATION_X_MID) ? 1 : 0;
        int row = 0;
        if (state->snes_y >= OB_FORMATION_Y_ROW1_MAX) {
            row = 2;
        } else if (state->snes_y >= OB_FORMATION_Y_ROW0_MAX) {
            row = 1;
        }

        int slot            = row * OB_FORMATION_COLS + col;
        uint8_t finger_x    = (col == 0) ? 6u : 38u;
        uint8_t finger_y    = (row == 0) ? 48u : ((row == 1) ? 64u : 72u);

        wram[OB_WRAM_FORMATION_INDEX] = (uint8_t)slot;
        wram[OB_WRAM_OAM1_X]          = finger_x;
        wram[OB_WRAM_OAM1_Y]          = finger_y;

        state->hovered_slot = slot;
        return slot;
    }

    state->hovered_slot = -1;
    return -1;
}

int ob_input_apply_world_map(ObMouseState *state, uint8_t *wram, const uint8_t *ppu_oam) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return -1;
    }

    int core_x = get_core_x(state);
    bool live_world_sword = (wram[OB_WRAM_OAM0_Y] < OB_OAM_OFFSCREEN_Y &&
                             wram[OB_WRAM_OAM0_TILE] == OB_TILE_WORLD_MAP_SWORD);

    if (live_world_sword) {
        /* Live Continental World Map sword cursor: 8-bit WRAM $0441 (X), $04A1 (Y),
         * rendered via OAM[0] ($0100/$0101, tile 0x6E) clamped to [50..204, 32..184]. */
        int wx = clamp_int(core_x, OB_WORLD_MAP_MIN_X, OB_WORLD_MAP_MAX_X);
        int wy = clamp_int(state->snes_y, OB_WORLD_MAP_MIN_Y, OB_WORLD_MAP_MAX_Y);
        wram[OB_WRAM_WORLD_CUR_X] = (uint8_t)wx;
        wram[OB_WRAM_WORLD_CUR_Y] = (uint8_t)wy;
        wram[OB_WRAM_OAM0_X]      = (uint8_t)wx;
        wram[OB_WRAM_OAM0_Y]      = (uint8_t)wy;
        wram[OB_WRAM_CUR_ACCEL]   = 1u;
        state->hovered_slot       = -1;
        return -1;
    }

    /* Synthetic / Legacy World Map fallback: camera pan + OAM stage banner hit-testing */
    apply_decoupled_camera_pan(state, wram);

    if (ppu_oam == NULL) {
        state->hovered_slot = -1;
        return -1;
    }

    /* Hit-test active stage banner sprites (16x16 bounding boxes in OAM[24..35], then OAM[1..23]) */
    for (int pass = 0; pass < 2; ++pass) {
        int start = (pass == 0) ? 24 : 1;
        int end   = (pass == 0) ? 36 : 24;
        for (int i = start; i < end; ++i) {
            uint8_t spr_x    = ppu_oam[i * 4 + 0];
            uint8_t spr_y    = ppu_oam[i * 4 + 1];
            uint8_t spr_attr = ppu_oam[i * 4 + 3];

            if (spr_y >= OB_OAM_OFFSCREEN_Y || (spr_attr & 0x38u) != 0x38u) {
                continue;
            }

            if (core_x >= (int)spr_x && core_x < (int)spr_x + 16 &&
                state->snes_y >= (int)spr_y && state->snes_y < (int)spr_y + 16) {
                int node_idx = (i >= 24) ? (i - 24) : (i - 1);
                wram[OB_WRAM_WORLD_NODE_INDEX] = (uint8_t)node_idx;
                wram_write_u16(wram, OB_WRAM_CUR_SCREEN_X, (uint16_t)(spr_x + 8u));
                wram_write_u16(wram, OB_WRAM_CUR_SCREEN_Y, (uint16_t)(spr_y + 8u));
                state->hovered_slot = node_idx;
                return node_idx;
            }
        }
    }

    if (core_x >= 0 && core_x < OB_VIEWPORT_WIDTH_4_3) {
        wram_write_u16(wram, OB_WRAM_CUR_SCREEN_X, (uint16_t)core_x);
        wram_write_u16(wram, OB_WRAM_CUR_SCREEN_Y, (uint16_t)clamp_int(state->snes_y, 0, OB_VIEWPORT_HEIGHT - 1));
    }

    state->hovered_slot = -1;
    return -1;
}

int ob_input_apply_wing_dock(ObMouseState *state, uint8_t *wram) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return -1;
    }

    /* Left Wing (snes_x in [0, 71]): Deployed Squad Plates 0..5 (Y: 12..197, stride 31px) */
    if (state->snes_x < 72) {
        if (state->snes_y >= 12 && state->snes_y < 198) {
            int sq_slot = (state->snes_y - 12) / 31;
            sq_slot     = clamp_int(sq_slot, 0, 5);
            state->hovered_slot = sq_slot;

            /* Left-clicking a squad plate jumps camera ($00BD/$00BF) to that squad's world pos */
            if (state->left_pressed) {
                uint16_t sx_raw = wram_read_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(sq_slot * 2));
                uint16_t sy_raw = wram_read_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(sq_slot * 2));
                int map_tiles_x = (int)wram_read_u16(wram, OB_WRAM_MAP_TILES_X);
                int map_tiles_y = (int)wram_read_u16(wram, OB_WRAM_MAP_TILES_Y);
                int max_world_x = (map_tiles_x > 0 && map_tiles_x != 0x5555) ? ((map_tiles_x << 3) - 1) : 2047;
                int max_world_y = (map_tiles_y > 0 && map_tiles_y != 0x5555) ? ((map_tiles_y << 3) - 1) : 2047;
                int sx = 0, sy = 0;
                if (decode_entity_world_xy(wram, sx_raw, sy_raw, max_world_x, max_world_y, &sx, &sy)) {
                    uint16_t min_x_raw = wram_read_u16(wram, OB_WRAM_CAM_MIN_X);
                    uint16_t min_y_raw = wram_read_u16(wram, OB_WRAM_CAM_MIN_Y);
                    uint16_t max_x_raw = wram_read_u16(wram, OB_WRAM_CAM_MAX_X);
                    uint16_t max_y_raw = wram_read_u16(wram, OB_WRAM_CAM_MAX_Y);
                    int min_x = (int)(int16_t)min_x_raw;
                    int min_y = (int)(int16_t)min_y_raw;
                    int max_x = (int)(int16_t)max_x_raw;
                    int max_y = (int)(int16_t)max_y_raw;
                    if (min_x_raw == 0x5555u || max_x_raw == 0x5555u || max_x <= min_x) { min_x = 0; max_x = 1024; }
                    if (min_y_raw == 0x5555u || max_y_raw == 0x5555u || max_y <= min_y) { min_y = 0; max_y = 1024; }

                    int cam_x = clamp_int(sx - 128, min_x, max_x);
                    int cam_y = clamp_int(sy - 112, min_y, max_y);
                    wram_write_u16(wram, OB_WRAM_CAM_X, (uint16_t)(int16_t)cam_x);
                    wram_write_u16(wram, OB_WRAM_CAM_Y, (uint16_t)(int16_t)cam_y);
                    wram_write_u16(wram, OB_WRAM_CAM_WORLD_X, (uint16_t)(int16_t)cam_x);
                    wram_write_u16(wram, OB_WRAM_CAM_WORLD_Y, (uint16_t)(int16_t)cam_y);
                    wram_write_u16(wram, OB_WRAM_CUR_WORLD_X, (uint16_t)sx);
                    wram_write_u16(wram, OB_WRAM_CUR_WORLD_Y, (uint16_t)sy);
                    wram_write_u16(wram, OB_WRAM_CUR_SCREEN_X, (uint16_t)(sx - cam_x));
                    wram_write_u16(wram, OB_WRAM_CUR_SCREEN_Y, (uint16_t)(sy - cam_y));
                    state->snapped_type  = OB_SNAP_SQUAD;
                    state->snapped_index = sq_slot;
                }
                state->left_pressed = false;
            }
            return sq_slot;
        }
        state->hovered_slot = -1;
        return -1;
    }

    /* Right Wing (snes_x in [328, 399]): Tarot Cards (Y: 70..198) or Spatial Radar (Y: 159..194) */
    if (state->snes_x >= 328) {
        if (state->snes_y >= 70 && state->snes_y < 199) {
            int card_slot = (state->snes_y - 70) / 43;
            card_slot     = clamp_int(card_slot, 0, 2);
            state->hovered_slot = card_slot;
            return card_slot;
        }
        state->hovered_slot = -1;
        return -1;
    }

    state->hovered_slot = -1;
    return -1;
}

uint16_t ob_input_step_frame(
    ObMouseState *state,
    uint8_t *wram,
    const uint8_t *ppu_oam,
    uint16_t base_joypad_mask,
    uint32_t current_frame
) {
    if (state == NULL || wram == NULL) {
        return base_joypad_mask;
    }

    /* If physical keyboard/gamepad D-Pad is pressed on this frame, yield immediately */
    if ((base_joypad_mask & OB_BTN_DPAD_MASK) != 0u) {
        ob_input_on_keyboard_activity(state, current_frame);
        return base_joypad_mask;
    }

    /* Zero-Invasion Lockstep Invariant: 0-byte WRAM mutation when mouse_active is false */
    if (!state->mouse_active) {
        state->active_mode = OB_MOUSE_MODE_PASSIVE;
        return base_joypad_mask;
    }

    ObMouseMode mode   = ob_input_detect_mode(state, wram, ppu_oam);
    state->active_mode = mode;

    switch (mode) {
        case OB_MOUSE_MODE_TACTICAL_MAP:
            ob_input_apply_tactical_map(state, wram);
            break;
        case OB_MOUSE_MODE_ICON_BAR:
            ob_input_apply_icon_bar(state, wram);
            break;
        case OB_MOUSE_MODE_FORMATION_GRID:
            ob_input_apply_formation_grid(state, wram);
            break;
        case OB_MOUSE_MODE_WORLD_MAP:
            ob_input_apply_world_map(state, wram, ppu_oam);
            break;
        case OB_MOUSE_MODE_LEFT_WING:
        case OB_MOUSE_MODE_RIGHT_WING:
            ob_input_apply_wing_dock(state, wram);
            break;
        case OB_MOUSE_MODE_MENU_LIST:
        case OB_MOUSE_MODE_PASSIVE:
        default:
            break;
    }

    uint16_t out_mask = base_joypad_mask;

    /* Left Click -> Confirm (Joypad A), pulsed for 3 frames so 30Hz SNES loops never drop clicks */
    if (state->left_pressed) {
        state->left_pulse_frames = OB_CLICK_PULSE_FRAMES;
        state->left_pressed      = false;
    }
    if (state->left_pulse_frames > 0u) {
        out_mask |= OB_BTN_A;
        state->left_pulse_frames--;
    }

    /* Right Click release without drag -> Cancel / Menu (Joypad B) */
    if (state->right_released) {
        if (!state->drag_moved) {
            state->right_pulse_frames = OB_CLICK_PULSE_FRAMES;
        }
        state->right_released = false;
        state->drag_moved     = false;
    }
    if (state->right_pulse_frames > 0u) {
        out_mask |= OB_BTN_B;
        state->right_pulse_frames--;
    }

    /* Guarantee: NEVER inject synthetic directional D-Pad bits (OB_BTN_DPAD_MASK) */
    return out_mask;
}
