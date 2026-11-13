#include "input.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* --- Little-Endian 16-bit WRAM Access Helpers --- */
static inline uint16_t wram_read_u16(const uint8_t *wram, uint32_t addr) {
    return (uint16_t)((uint16_t)wram[addr] | ((uint16_t)wram[addr + 1u] << 8u));
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
    state->viewport_w   = (viewport_width > 0) ? viewport_width : OB_VIEWPORT_WIDTH_4_3;
    state->viewport_h   = (viewport_height > 0) ? viewport_height : OB_VIEWPORT_HEIGHT;
    state->snes_x       = state->viewport_w / 2;
    state->snes_y       = state->viewport_h / 2;
    state->prev_snes_x  = state->snes_x;
    state->prev_snes_y  = state->snes_y;
    state->mouse_active = false;
    state->has_prev_pos = true;
    state->active_mode  = OB_MOUSE_MODE_PASSIVE;
    state->snapped_type = OB_SNAP_NONE;
    state->snapped_index = -1;
    state->hovered_slot  = -1;
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

static inline int get_core_x(const ObMouseState *state) {
    if (state->wings_enabled && state->viewport_w >= OB_VIEWPORT_WIDTH_16_9) {
        return state->snes_x - 72;
    }
    return state->snes_x;
}

ObMouseMode ob_input_detect_mode(
    const ObMouseState *state,
    const uint8_t *wram,
    const uint8_t *ppu_oam
) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return OB_MOUSE_MODE_PASSIVE;
    }

    /* Gate 3 Widescreen Wing Docks (Left Wing X: 0..71, Right Wing X: 328..399) */
    if (state->wings_enabled && state->viewport_w >= OB_VIEWPORT_WIDTH_16_9 && !state->drag_active) {
        if (state->snes_x < 72) {
            return OB_MOUSE_MODE_LEFT_WING;
        }
        if (state->snes_x >= 328) {
            return OB_MOUSE_MODE_RIGHT_WING;
        }
    }

    uint8_t oam1_y    = wram[OB_WRAM_OAM1_Y];
    uint8_t oam1_tile = wram[OB_WRAM_OAM1_TILE];

    /* 1. Pillar 2A: 7-Icon Horizontal Command Strip (tile 0xCE at Y=119) */
    if (oam1_tile == OB_TILE_ICON_BAR_FINGER && oam1_y == OB_ICON_BAR_FINGER_Y) {
        return OB_MOUSE_MODE_ICON_BAR;
    }

    /* 2. Pillar 2B: 3x2 Unit Formation Grid (tile 0xCC with active Y < 224) */
    if (oam1_tile == OB_TILE_FORMATION_FINGER && oam1_y < OB_OAM_OFFSCREEN_Y) {
        return OB_MOUSE_MODE_FORMATION_GRID;
    }

    /* 3. Pillar 3: Continental World Map (OAM shadow Y=0xE0 sentinel + PPU stage banners) */
    uint8_t tac_flags = wram[OB_WRAM_CUR_SPRITE_FLAGS];
    if (oam1_y == OB_OAM_OFFSCREEN_Y && (tac_flags & 0xC0u) == 0u && ppu_oam != NULL) {
        for (int i = 24; i < 36; ++i) {
            uint8_t spr_y    = ppu_oam[i * 4 + 1];
            uint8_t spr_attr = ppu_oam[i * 4 + 3];
            if (spr_y < OB_OAM_OFFSCREEN_Y && (spr_attr & 0x38u) == 0x38u) {
                return OB_MOUSE_MODE_WORLD_MAP;
            }
        }
    }

    /* 4. Pillar 1: Tactical Battlefield Map ($14E6 active & $00CE camera state == 0) */
    if ((tac_flags & 0xC0u) != 0u && wram[OB_WRAM_CAM_STATE] == 0u) {
        return OB_MOUSE_MODE_TACTICAL_MAP;
    }

    return OB_MOUSE_MODE_PASSIVE;
}

static void apply_decoupled_camera_pan(ObMouseState *state, uint8_t *wram) {
    int cam_x = (int)wram_read_u16(wram, OB_WRAM_CAM_X);
    int cam_y = (int)wram_read_u16(wram, OB_WRAM_CAM_Y);

    int min_x = (int)wram_read_u16(wram, OB_WRAM_CAM_MIN_X);
    int min_y = (int)wram_read_u16(wram, OB_WRAM_CAM_MIN_Y);
    int max_x = (int)wram_read_u16(wram, OB_WRAM_CAM_MAX_X);
    int max_y = (int)wram_read_u16(wram, OB_WRAM_CAM_MAX_Y);

    if (max_x <= min_x) {
        min_x = 0;
        max_x = 1024;
    }
    if (max_y <= min_y) {
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
    } else {
        /* Narrow 10px viewport edge-scroll margins */
        if (state->snes_x < OB_EDGE_SCROLL_MARGIN) {
            pan_dx = -OB_EDGE_SCROLL_SPEED;
        } else if (state->snes_x >= state->viewport_w - OB_EDGE_SCROLL_MARGIN) {
            pan_dx = OB_EDGE_SCROLL_SPEED;
        }

        if (state->snes_y < OB_EDGE_SCROLL_MARGIN) {
            pan_dy = -OB_EDGE_SCROLL_SPEED;
        } else if (state->snes_y >= state->viewport_h - OB_EDGE_SCROLL_MARGIN) {
            pan_dy = OB_EDGE_SCROLL_SPEED;
        }
    }

    if (pan_dx != 0 || pan_dy != 0) {
        int new_cam_x = clamp_int(cam_x + pan_dx, min_x, max_x);
        int new_cam_y = clamp_int(cam_y + pan_dy, min_y, max_y);
        wram_write_u16(wram, OB_WRAM_CAM_X, (uint16_t)new_cam_x);
        wram_write_u16(wram, OB_WRAM_CAM_Y, (uint16_t)new_cam_y);
        wram_write_u16(wram, OB_WRAM_CAM_WORLD_X, (uint16_t)new_cam_x);
        wram_write_u16(wram, OB_WRAM_CAM_WORLD_Y, (uint16_t)new_cam_y);
    }
}

void ob_input_apply_tactical_map(ObMouseState *state, uint8_t *wram) {
    if (state == NULL || wram == NULL || !state->mouse_active) {
        return;
    }

    /* Step 1: Update decoupled Mode-7 camera ONLY on Right/Middle-drag or 10px edge margin */
    apply_decoupled_camera_pan(state, wram);

    /* Step 2: Compute 1:1 viewport screen coordinates across the active core viewport */
    int active_core_w = (state->wings_enabled && state->viewport_w >= OB_VIEWPORT_WIDTH_16_9)
                        ? OB_VIEWPORT_WIDTH_4_3
                        : state->viewport_w;
    int core_x        = get_core_x(state);
    int max_screen_x  = active_core_w - 1 - OB_TACTICAL_MARGIN;
    int max_screen_y  = state->viewport_h - 1 - OB_TACTICAL_MARGIN;
    int screen_x      = clamp_int(core_x, OB_TACTICAL_MIN_X, max_screen_x);
    int screen_y      = clamp_int(state->snes_y, OB_TACTICAL_MIN_Y, max_screen_y);

    /* Step 3: Synchronize cursor world coordinates ($14E2, $14E4) from camera + screen offset */
    int cam_x = (int)wram_read_u16(wram, OB_WRAM_CAM_X);
    int cam_y = (int)wram_read_u16(wram, OB_WRAM_CAM_Y);

    int map_tiles_x = (int)wram_read_u16(wram, OB_WRAM_MAP_TILES_X);
    int map_tiles_y = (int)wram_read_u16(wram, OB_WRAM_MAP_TILES_Y);
    int max_world_x = (map_tiles_x > 0) ? ((map_tiles_x << 3) - 1) : 2047;
    int max_world_y = (map_tiles_y > 0) ? ((map_tiles_y << 3) - 1) : 2047;

    int world_x = clamp_int(cam_x + screen_x, 0, max_world_x);
    int world_y = clamp_int(cam_y + screen_y, 0, max_world_y);

    /* Step 4: Magnetic Entity Snapping (+-8px radius) to Deployed Squads & Cities */
    state->snapped_type  = OB_SNAP_NONE;
    state->snapped_index = -1;
    int best_dist_sq     = (OB_ENTITY_SNAP_RADIUS * OB_ENTITY_SNAP_RADIUS) + 1;

    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        uint16_t sx_raw = wram_read_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2));
        uint16_t sy_raw = wram_read_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2));
        if (sx_raw == 0xFFFFu || sy_raw == 0xFFFFu || (sx_raw == 0u && sy_raw == 0u)) {
            continue;
        }
        int dx = (int)sx_raw - world_x;
        int dy = (int)sy_raw - world_y;
        if (abs(dx) <= OB_ENTITY_SNAP_RADIUS && abs(dy) <= OB_ENTITY_SNAP_RADIUS) {
            int d2 = dx * dx + dy * dy;
            if (d2 < best_dist_sq) {
                best_dist_sq         = d2;
                world_x              = (int)sx_raw;
                world_y              = (int)sy_raw;
                screen_x             = clamp_int(world_x - cam_x, OB_TACTICAL_MIN_X, max_screen_x);
                screen_y             = clamp_int(world_y - cam_y, OB_TACTICAL_MIN_Y, max_screen_y);
                state->snapped_type  = OB_SNAP_SQUAD;
                state->snapped_index = i;
            }
        }
    }

    if (state->snapped_type == OB_SNAP_NONE) {
        for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
            uint16_t cx_raw = wram_read_u16(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2));
            uint16_t cy_raw = wram_read_u16(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2));
            if (cx_raw == 0xFFFFu || cy_raw == 0xFFFFu || (cx_raw == 0u && cy_raw == 0u)) {
                continue;
            }
            int dx = (int)cx_raw - world_x;
            int dy = (int)cy_raw - world_y;
            if (abs(dx) <= OB_ENTITY_SNAP_RADIUS && abs(dy) <= OB_ENTITY_SNAP_RADIUS) {
                int d2 = dx * dx + dy * dy;
                if (d2 < best_dist_sq) {
                    best_dist_sq         = d2;
                    world_x              = (int)cx_raw;
                    world_y              = (int)cy_raw;
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

    /* Support Right/Middle-click drag and 10px edge camera panning on the continent map */
    apply_decoupled_camera_pan(state, wram);

    if (ppu_oam == NULL) {
        state->hovered_slot = -1;
        return -1;
    }

    int core_x = get_core_x(state);

    /* Hit-test active stage banner sprites (16x16 bounding boxes in OAM[24..35]) */
    for (int i = 24; i < 36; ++i) {
        uint8_t spr_x    = ppu_oam[i * 4 + 0];
        uint8_t spr_y    = ppu_oam[i * 4 + 1];
        uint8_t spr_attr = ppu_oam[i * 4 + 3];

        if (spr_y >= OB_OAM_OFFSCREEN_Y || (spr_attr & 0x38u) != 0x38u) {
            continue;
        }

        if (core_x >= (int)spr_x && core_x < (int)spr_x + 16 &&
            state->snes_y >= (int)spr_y && state->snes_y < (int)spr_y + 16) {
            int node_idx = i - 24;
            wram[OB_WRAM_WORLD_NODE_INDEX] = (uint8_t)node_idx;
            wram_write_u16(wram, OB_WRAM_CUR_SCREEN_X, (uint16_t)(spr_x + 8u));
            wram_write_u16(wram, OB_WRAM_CUR_SCREEN_Y, (uint16_t)(spr_y + 8u));
            state->hovered_slot = node_idx;
            return node_idx;
        }
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
                uint16_t sx = wram_read_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(sq_slot * 2));
                uint16_t sy = wram_read_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(sq_slot * 2));
                if (sx != 0xFFFFu && sy != 0xFFFFu && (sx != 0u || sy != 0u)) {
                    int min_x = (int)wram_read_u16(wram, OB_WRAM_CAM_MIN_X);
                    int min_y = (int)wram_read_u16(wram, OB_WRAM_CAM_MIN_Y);
                    int max_x = (int)wram_read_u16(wram, OB_WRAM_CAM_MAX_X);
                    int max_y = (int)wram_read_u16(wram, OB_WRAM_CAM_MAX_Y);
                    if (max_x <= min_x) { min_x = 0; max_x = 1024; }
                    if (max_y <= min_y) { min_y = 0; max_y = 1024; }

                    int cam_x = clamp_int((int)sx - 128, min_x, max_x);
                    int cam_y = clamp_int((int)sy - 112, min_y, max_y);
                    wram_write_u16(wram, OB_WRAM_CAM_X, (uint16_t)cam_x);
                    wram_write_u16(wram, OB_WRAM_CAM_Y, (uint16_t)cam_y);
                    wram_write_u16(wram, OB_WRAM_CAM_WORLD_X, (uint16_t)cam_x);
                    wram_write_u16(wram, OB_WRAM_CAM_WORLD_Y, (uint16_t)cam_y);
                    wram_write_u16(wram, OB_WRAM_CUR_WORLD_X, sx);
                    wram_write_u16(wram, OB_WRAM_CUR_WORLD_Y, sy);
                    wram_write_u16(wram, OB_WRAM_CUR_SCREEN_X, (uint16_t)((int)sx - cam_x));
                    wram_write_u16(wram, OB_WRAM_CUR_SCREEN_Y, (uint16_t)((int)sy - cam_y));
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

    /* Left Click -> Confirm (Joypad A) */
    if (state->left_pressed) {
        out_mask |= OB_BTN_A;
        state->left_pressed = false;
    }

    /* Right Click release without drag -> Cancel / Menu (Joypad B) */
    if (state->right_released) {
        if (!state->drag_moved) {
            out_mask |= OB_BTN_B;
        }
        state->right_released = false;
        state->drag_moved     = false;
    }

    /* Guarantee: NEVER inject synthetic directional D-Pad bits (OB_BTN_DPAD_MASK) */
    return out_mask;
}
