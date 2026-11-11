#include "telemetry_window.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Compact 5x7 ASCII Bitmap Font (0x20 Space .. 0x5F Underscore) */
static const uint8_t kFont5x7[64][5] = {
    {0x00,0x00,0x00,0x00,0x00}, /* ' ' */
    {0x00,0x00,0x5F,0x00,0x00}, /* '!' */
    {0x00,0x07,0x00,0x07,0x00}, /* '"' */
    {0x14,0x7F,0x14,0x7F,0x14}, /* '#' */
    {0x24,0x2A,0x7F,0x2A,0x12}, /* '$' */
    {0x23,0x13,0x08,0x64,0x62}, /* '%' */
    {0x36,0x49,0x55,0x22,0x50}, /* '&' */
    {0x00,0x05,0x03,0x00,0x00}, /* '\'' */
    {0x00,0x1C,0x22,0x41,0x00}, /* '(' */
    {0x00,0x41,0x22,0x1C,0x00}, /* ')' */
    {0x14,0x08,0x3E,0x08,0x14}, /* '*' */
    {0x08,0x08,0x3E,0x08,0x08}, /* '+' */
    {0x00,0x50,0x30,0x00,0x00}, /* ',' */
    {0x08,0x08,0x08,0x08,0x08}, /* '-' */
    {0x00,0x60,0x60,0x00,0x00}, /* '.' */
    {0x20,0x10,0x08,0x04,0x02}, /* '/' */
    {0x3E,0x51,0x49,0x45,0x3E}, /* '0' */
    {0x00,0x42,0x7F,0x40,0x00}, /* '1' */
    {0x42,0x61,0x51,0x49,0x46}, /* '2' */
    {0x21,0x41,0x45,0x4B,0x31}, /* '3' */
    {0x18,0x14,0x12,0x7F,0x10}, /* '4' */
    {0x27,0x45,0x45,0x45,0x39}, /* '5' */
    {0x3C,0x4A,0x49,0x49,0x30}, /* '6' */
    {0x01,0x71,0x09,0x05,0x03}, /* '7' */
    {0x36,0x49,0x49,0x49,0x36}, /* '8' */
    {0x06,0x49,0x49,0x29,0x1E}, /* '9' */
    {0x00,0x36,0x36,0x00,0x00}, /* ':' */
    {0x00,0x56,0x36,0x00,0x00}, /* ';' */
    {0x08,0x14,0x22,0x41,0x00}, /* '<' */
    {0x14,0x14,0x14,0x14,0x14}, /* '=' */
    {0x00,0x41,0x22,0x14,0x08}, /* '>' */
    {0x02,0x01,0x51,0x09,0x06}, /* '?' */
    {0x32,0x49,0x79,0x41,0x3E}, /* '@' */
    {0x7E,0x11,0x11,0x11,0x7E}, /* 'A' */
    {0x7F,0x49,0x49,0x49,0x36}, /* 'B' */
    {0x3E,0x41,0x41,0x41,0x22}, /* 'C' */
    {0x7F,0x41,0x41,0x22,0x1C}, /* 'D' */
    {0x7F,0x49,0x49,0x49,0x41}, /* 'E' */
    {0x7F,0x09,0x09,0x09,0x01}, /* 'F' */
    {0x3E,0x41,0x49,0x49,0x7A}, /* 'G' */
    {0x7F,0x08,0x08,0x08,0x7F}, /* 'H' */
    {0x00,0x41,0x7F,0x41,0x00}, /* 'I' */
    {0x20,0x40,0x41,0x3F,0x01}, /* 'J' */
    {0x7F,0x08,0x14,0x22,0x41}, /* 'K' */
    {0x7F,0x40,0x40,0x40,0x40}, /* 'L' */
    {0x7F,0x02,0x0C,0x02,0x7F}, /* 'M' */
    {0x7F,0x04,0x08,0x10,0x7F}, /* 'N' */
    {0x3E,0x41,0x41,0x41,0x3E}, /* 'O' */
    {0x7F,0x09,0x09,0x09,0x06}, /* 'P' */
    {0x3E,0x41,0x51,0x21,0x5E}, /* 'Q' */
    {0x7F,0x09,0x19,0x29,0x46}, /* 'R' */
    {0x46,0x49,0x49,0x49,0x31}, /* 'S' */
    {0x01,0x01,0x7F,0x01,0x01}, /* 'T' */
    {0x3F,0x40,0x40,0x40,0x3F}, /* 'U' */
    {0x1F,0x20,0x40,0x20,0x1F}, /* 'V' */
    {0x3F,0x40,0x38,0x40,0x3F}, /* 'W' */
    {0x63,0x14,0x08,0x14,0x63}, /* 'X' */
    {0x07,0x08,0x70,0x08,0x07}, /* 'Y' */
    {0x61,0x51,0x49,0x45,0x43}, /* 'Z' */
    {0x00,0x7F,0x41,0x41,0x00}, /* '[' */
    {0x02,0x04,0x08,0x10,0x20}, /* '\\' */
    {0x00,0x41,0x41,0x7F,0x00}, /* ']' */
    {0x04,0x02,0x01,0x02,0x04}, /* '^' */
    {0x40,0x40,0x40,0x40,0x40}  /* '_' */
};

static inline void put_px(uint32_t *fb, uint32_t w, uint32_t h, int x, int y, uint32_t color) {
    if (x >= 0 && (uint32_t)x < w && y >= 0 && (uint32_t)y < h) {
        fb[(uint32_t)y * w + (uint32_t)x] = color;
    }
}

static void fill_rect(uint32_t *fb, uint32_t w, uint32_t h, int rx, int ry, int rw, int rh, uint32_t color) {
    for (int y = ry; y < ry + rh; ++y) {
        if (y < 0 || (uint32_t)y >= h) continue;
        for (int x = rx; x < rx + rw; ++x) {
            if (x < 0 || (uint32_t)x >= w) continue;
            fb[(uint32_t)y * w + (uint32_t)x] = color;
        }
    }
}

static void stroke_rect(uint32_t *fb, uint32_t w, uint32_t h, int rx, int ry, int rw, int rh, uint32_t color) {
    fill_rect(fb, w, h, rx, ry, rw, 1, color);
    fill_rect(fb, w, h, rx, ry + rh - 1, rw, 1, color);
    fill_rect(fb, w, h, rx, ry, 1, rh, color);
    fill_rect(fb, w, h, rx + rw - 1, ry, 1, rh, color);
}

static void draw_line(uint32_t *fb, uint32_t w, uint32_t h, int x0, int y0, int x1, int y1, uint32_t color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    for (;;) {
        put_px(fb, w, h, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

static void draw_text(uint32_t *fb, uint32_t w, uint32_t h, int x, int y, const char *str, uint32_t color) {
    if (!str) return;
    int cx = x;
    static const uint8_t kGlyphPipe[5] = {0x00, 0x00, 0x7F, 0x00, 0x00};
    for (size_t i = 0; str[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)str[i];
        const uint8_t *glyph = NULL;
        if (c == '|') {
            glyph = kGlyphPipe;
        } else {
            if (c >= 'a' && c <= 'z') {
                c = (unsigned char)(c - 'a' + 'A');
            }
            if (c < 0x20 || c > 0x5F) {
                c = '?';
            }
            glyph = kFont5x7[c - 0x20];
        }
        for (int col = 0; col < 5; ++col) {
            uint8_t bits = glyph[col];
            for (int row = 0; row < 7; ++row) {
                if (bits & (1U << row)) {
                    put_px(fb, w, h, cx + col, y + row, color);
                }
            }
        }
        cx += 6;
    }
}

static void draw_bar(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y, int bw, int bh,
    int val, int max_val,
    uint32_t bg_col, uint32_t fill_col, uint32_t border_col
) {
    fill_rect(fb, w, h, x, y, bw, bh, bg_col);
    if (max_val > 0 && val > 0) {
        int fw = (val >= max_val) ? (bw - 2) : ((val * (bw - 2)) / max_val);
        fill_rect(fb, w, h, x + 1, y + 1, fw, bh - 2, fill_col);
    }
    stroke_rect(fb, w, h, x, y, bw, bh, border_col);
}

void ob_companion_window_init(ObCompanionWindowState *state) {
    if (!state) return;
    memset(state, 0, sizeof(*state));
    state->mode               = OB_HUD_EXPLORER;
    state->selected_unit_slot = 0;
    state->selected_squad_id  = 0;
}

void ob_telemetry_render_companion_window(
    ObCompanionWindowState *state,
    const ObTelemetryFrame *prev_frame,
    const ObTelemetryFrame *curr_frame,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t *fb,
    uint32_t w,
    uint32_t h
) {
    if (!state || !curr_frame || !fb || w < 320 || h < 240) {
        return;
    }

    /* Record any new bitflag / state transitions into the ring buffer */
    if (prev_frame) {
        ObTelemetryDiffEvent new_events[8];
        size_t n_ev = ob_telemetry_diff_frames(prev_frame, curr_frame, new_events, 8);
        for (size_t i = 0; i < n_ev; ++i) {
            if (state->recent_diff_count < OB_DIFF_LOG_CAPACITY) {
                state->recent_diffs[state->recent_diff_count++] = new_events[i];
            } else {
                memmove(&state->recent_diffs[0], &state->recent_diffs[1],
                        sizeof(ObTelemetryDiffEvent) * (OB_DIFF_LOG_CAPACITY - 1));
                state->recent_diffs[OB_DIFF_LOG_CAPACITY - 1] = new_events[i];
            }
            state->total_diffs_observed++;
        }
    }

    /* Palette constants (0xFFRRGGBB) */
    const uint32_t kColBgDeep     = 0xFF0E131FU;
    const uint32_t kColPanelBg    = 0xFF151D2EU;
    const uint32_t kColHeaderBg   = 0xFF1E2942U;
    const uint32_t kColGoldBorder = 0xFFD4AF37U;
    const uint32_t kColSubBorder  = 0xFF334466U;
    const uint32_t kColTextWhite  = 0xFFF0F4F8U;
    const uint32_t kColTextMuted  = 0xFF94A3B8U;
    const uint32_t kColEmerald    = 0xFF10B981U;
    const uint32_t kColAmber      = 0xFFF59E0BU;
    const uint32_t kColCrimson    = 0xFFEF4444U;
    const uint32_t kColCyan       = 0xFF06B6D4U;

    fill_rect(fb, w, h, 0, 0, (int)w, (int)h, kColBgDeep);

    /* Top Banner */
    fill_rect(fb, w, h, 0, 0, (int)w, 22, kColHeaderBg);
    stroke_rect(fb, w, h, 0, 0, (int)w, 22, kColGoldBorder);

    char line[128];
    snprintf(line, sizeof(line),
             "OGRE BATTLE TELEMETRY COMPANION [FRAME %u | ROSTER %u/100 | DIFFS %u]",
             curr_frame->frame_counter, curr_frame->active_roster_count, state->total_diffs_observed);
    draw_text(fb, w, h, 8, 7, line, kColGoldBorder);

    int mid_x = (int)w / 2;
    int mid_y = ((int)h + 22) / 2;

    /* ======================================================================
     * PANEL 1 (Top-Left): MACRO ECONOMY, REPUTATION & CELESTIAL/LUNAR CLOCK
     * ====================================================================== */
    int p1_x = 4, p1_y = 26, p1_w = mid_x - 6, p1_h = mid_y - 30;
    fill_rect(fb, w, h, p1_x, p1_y, p1_w, p1_h, kColPanelBg);
    stroke_rect(fb, w, h, p1_x, p1_y, p1_w, p1_h, kColSubBorder);
    fill_rect(fb, w, h, p1_x + 1, p1_y + 1, p1_w - 2, 14, kColHeaderBg);
    draw_text(fb, w, h, p1_x + 6, p1_y + 4, "1. REPUTATION, NOON TRIBUTE & CELESTIAL CLOCK", kColCyan);

    int cy = p1_y + 20;
    snprintf(line, sizeof(line), "CHAOS FRAME: %u / 100 (SUB: %u)",
             curr_frame->chaos_frame, curr_frame->chaos_frame_sub);
    draw_text(fb, w, h, p1_x + 8, cy, line, kColTextWhite);
    draw_bar(fb, w, h, p1_x + 8, cy + 10, p1_w - 16, 8,
             curr_frame->chaos_frame, 100, 0xFF090D16U,
             (curr_frame->chaos_frame >= 65) ? kColEmerald : (curr_frame->chaos_frame >= 35 ? kColAmber : kColCrimson),
             kColGoldBorder);
    cy += 24;

    snprintf(line, sizeof(line), "TREASURY: %u GOTH", curr_frame->goth_treasury);
    draw_text(fb, w, h, p1_x + 8, cy, line, kColTextWhite);
    cy += 11;

    snprintf(line, sizeof(line), "NOON FORECAST: %+d G (TRIB %u - UPKEEP %u)",
             curr_frame->projected_noon_net,
             curr_frame->projected_tribute_income,
             curr_frame->active_upkeep_drain);
    draw_text(fb, w, h, p1_x + 8, cy, line,
              (curr_frame->projected_noon_net >= 0) ? kColEmerald : kColAmber);
    cy += 14;

    snprintf(line, sizeof(line), "CALENDAR: YR %u MO %u DAY %u [LUNAR WK %u/7]",
             curr_frame->calendar.year, curr_frame->calendar.month,
             curr_frame->calendar.day, curr_frame->calendar.lunar_weekday);
    draw_text(fb, w, h, p1_x + 8, cy, line, kColTextWhite);
    cy += 11;

    snprintf(line, sizeof(line), "CLOCK: %02u:%02u.%02u (%s) | NOON: %uM",
             curr_frame->calendar.hour, curr_frame->calendar.minute, curr_frame->calendar.sub_tick,
             curr_frame->calendar.is_nighttime ? "NIGHT: LYCAN UP" : "DAY: SOLAR UP",
             curr_frame->calendar.minutes_to_noon);
    draw_text(fb, w, h, p1_x + 8, cy, line,
              curr_frame->calendar.is_nighttime ? kColAmber : kColEmerald);
    cy += 14;

    /* 13-Ending Track Audit */
    ObEndingAudit ending;
    ob_telemetry_audit_ending(curr_frame, &ending);
    snprintf(line, sizeof(line), "ENDING TRACK: %s", ending.ending_name);
    draw_text(fb, w, h, p1_x + 8, cy, line, kColGoldBorder);
    cy += 11;
    snprintf(line, sizeof(line), "ALT TRACK:    %s", ending.nearest_alt_name);
    draw_text(fb, w, h, p1_x + 8, cy, line, kColTextMuted);
    cy += 14;

    /* Town Compatibility Matcher Preview */
    ObCityLiberationMatch matches[4];
    size_t n_matches = ob_telemetry_match_city_liberators(curr_frame, matches, 4);
    if (n_matches > 0) {
        snprintf(line, sizeof(line), "BEST TOWN LIBERATOR: CITY #%u -> SQUAD #%u (%+d CF)",
                 matches[0].city_index, matches[0].recommended_squad_id + 1, matches[0].predicted_cf_delta);
        draw_text(fb, w, h, p1_x + 8, cy, line, kColCyan);
    } else {
        snprintf(line, sizeof(line), "BGM TRACK: $%02X | SFX: $%02X | PRNG: $%04X",
                 curr_frame->bgm_track_id, curr_frame->sfx_last_id, curr_frame->prng_entropy_sample);
        draw_text(fb, w, h, p1_x + 8, cy, line, kColTextMuted);
    }

    /* ======================================================================
     * PANEL 2 (Top-Right): 2D SPATIAL RADAR, KINEMATICS & ENEMY AI MIND-READ
     * ====================================================================== */
    int p2_x = mid_x + 2, p2_y = 26, p2_w = (int)w - mid_x - 6, p2_h = mid_y - 30;
    fill_rect(fb, w, h, p2_x, p2_y, p2_w, p2_h, kColPanelBg);
    stroke_rect(fb, w, h, p2_x, p2_y, p2_w, p2_h, kColSubBorder);
    fill_rect(fb, w, h, p2_x + 1, p2_y + 1, p2_w - 2, 14, kColHeaderBg);
    draw_text(fb, w, h, p2_x + 6, p2_y + 4, "2. SPATIAL RADAR ($18AF) & ENEMY AI LOCKS ($19A5)", kColCyan);

    /* Draw Mini-Radar Canvas on Left Side of Panel 2 */
    int rad_x = p2_x + 8, rad_y = p2_y + 20, rad_w = 136, rad_h = p2_h - 28;
    fill_rect(fb, w, h, rad_x, rad_y, rad_w, rad_h, 0xFF090D16U);
    stroke_rect(fb, w, h, rad_x, rad_y, rad_w, rad_h, kColSubBorder);

    /* Plot Stage Cities */
    for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        const ObCityTelemetry *city = &curr_frame->cities[c];
        if (!city->exists) continue;
        int rx = rad_x + 4 + ((city->world_x & 0x07FF) * (rad_w - 8)) / 2048;
        int ry = rad_y + 4 + ((city->world_y & 0x07FF) * (rad_h - 8)) / 2048;
        uint32_t col = (city->ownership_mask & 0x01) ? kColCyan : kColAmber;
        fill_rect(fb, w, h, rx - 2, ry - 2, 4, 4, col);
    }

    /* Plot Deployed Squads (Player 0..9 in Emerald, Enemy 10..20 in Crimson) */
    uint8_t active_player_sq = 0, active_enemy_sq = 0;
    for (uint8_t s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        const ObMapEntityTelemetry *ent = &curr_frame->map_entities[s];
        if (!ent->is_active) continue;
        if (ent->is_enemy) active_enemy_sq++; else active_player_sq++;
        int rx = rad_x + 4 + ((ent->world_x & 0x07FF) * (rad_w - 8)) / 2048;
        int ry = rad_y + 4 + ((ent->world_y & 0x07FF) * (rad_h - 8)) / 2048;
        if (ent->target_x > 0 && ent->target_x != 0x7FFF) {
            int tx = rad_x + 4 + ((ent->target_x & 0x07FF) * (rad_w - 8)) / 2048;
            int ty = rad_y + 4 + ((ent->target_y & 0x07FF) * (rad_h - 8)) / 2048;
            draw_line(fb, w, h, rx, ry, tx, ty, ent->is_enemy ? 0xFF661A1AU : 0xFF14532DU);
        }
        fill_rect(fb, w, h, rx - 2, ry - 2, 5, 5, ent->is_enemy ? kColCrimson : kColEmerald);
    }

    /* Right side of Panel 2: AI & Kinematic Readout */
    int info_x = rad_x + rad_w + 8;
    int iy = p2_y + 20;
    snprintf(line, sizeof(line), "DEPLOYED: %u PLY / %u ENM", active_player_sq, active_enemy_sq);
    draw_text(fb, w, h, info_x, iy, line, kColTextWhite);
    iy += 12;

    snprintf(line, sizeof(line), "BOSS AGGRO: $%02X | WAVE: %u",
             curr_frame->boss_aggro_state, curr_frame->enemy_spawn_wave);
    draw_text(fb, w, h, info_x, iy, line, kColAmber);
    iy += 11;

    snprintf(line, sizeof(line), "SPAWN TIMER: %u TICKS", curr_frame->enemy_spawn_timer);
    draw_text(fb, w, h, info_x, iy, line, kColTextMuted);
    iy += 14;

    /* List first 5 active entities with coordinates, velocity & AI order */
    uint8_t listed = 0;
    for (uint8_t s = 0; s < OB_MAX_DEPLOYED_SLOTS && listed < 6; ++s) {
        const ObMapEntityTelemetry *ent = &curr_frame->map_entities[s];
        if (!ent->is_active) continue;
        snprintf(line, sizeof(line), "%s#%02u (%d,%d) AI:$%02X",
                 ent->is_enemy ? "E" : "P", s, ent->world_x, ent->world_y, ent->ai_order_state & 0xFF);
        draw_text(fb, w, h, info_x, iy, line, ent->is_enemy ? kColCrimson : kColEmerald);
        iy += 11;
        listed++;
    }
    if (listed == 0) {
        draw_text(fb, w, h, info_x, iy, "NO SQUADS ON OVERLAND MAP", kColTextMuted);
    }

    /* ======================================================================
     * PANEL 3 (Bottom-Left): LIVE CLASH TUG-OF-WAR & MORALITY DRIFT ENGINE
     * ====================================================================== */
    int p3_x = 4, p3_y = mid_y, p3_w = mid_x - 6, p3_h = (int)h - mid_y - 4;
    fill_rect(fb, w, h, p3_x, p3_y, p3_w, p3_h, kColPanelBg);
    stroke_rect(fb, w, h, p3_x, p3_y, p3_w, p3_h, kColSubBorder);
    fill_rect(fb, w, h, p3_x + 1, p3_y + 1, p3_w - 2, 14, kColHeaderBg);
    draw_text(fb, w, h, p3_x + 6, p3_y + 4, "3. CLASH TUG-OF-WAR ($F942) & ALI/CHA KILL DRIFT", kColCyan);

    int p3_cy = p3_y + 20;
    static const char *const kTacticNames[4] = {"LEADER", "STRONG", "WEAK", "BEST"};
    const ObCombatTelemetry *cmb = &curr_frame->combat;

    snprintf(line, sizeof(line), "CLASH DMG: PLAYER %u VS ENEMY %u [TACTIC: %s]",
             cmb->player_clash_damage, cmb->enemy_clash_damage, kTacticNames[cmb->active_tactic & 3]);
    draw_text(fb, w, h, p3_x + 8, p3_cy, line, kColTextWhite);
    p3_cy += 10;

    int total_dmg = (int)cmb->player_clash_damage + (int)cmb->enemy_clash_damage;
    int ply_ratio = (total_dmg > 0) ? ((int)cmb->player_clash_damage * 100 / total_dmg) : 50;
    draw_bar(fb, w, h, p3_x + 8, p3_cy, p3_w - 16, 9, ply_ratio, 100, kColCrimson, kColEmerald, kColGoldBorder);
    p3_cy += 14;

    snprintf(line, sizeof(line), "ACTING SLOT: %u -> TARGET: %u | ACTIONS LEFT: %u",
             cmb->acting_slot, cmb->target_slot, cmb->total_actions_left);
    draw_text(fb, w, h, p3_x + 8, p3_cy, line, kColTextMuted);
    p3_cy += 14;

    draw_text(fb, w, h, p3_x + 8, p3_cy, "PRE-CLASH KILL MORALITY DRIFT (HOLY L3 / UNDEAD):", kColGoldBorder);
    p3_cy += 12;

    /* Show morality drift predictions for top 4 player units */
    ObUnitTelemetry dummy_holy_low = {0};
    dummy_holy_low.level = 3;
    dummy_holy_low.ali   = 75;
    dummy_holy_low.status_mask = 0x00;

    ObUnitTelemetry dummy_evil_high = {0};
    dummy_evil_high.level = 12;
    dummy_evil_high.ali   = 15;
    dummy_evil_high.status_mask = 0x20; /* Undead */

    uint8_t shown_u = 0;
    for (uint8_t u_idx = 0; u_idx < OB_MAX_ROSTER_UNITS && shown_u < 5; ++u_idx) {
        const ObUnitTelemetry *u = &curr_frame->units[u_idx];
        if (!u->is_populated) continue;
        char cname[16];
        ob_telemetry_get_class_name(rom, rom_size, u->class_id, cname, sizeof(cname));

        ObMoralityDriftForecast f_low, f_high;
        ob_telemetry_predict_kill_morality(u, &dummy_holy_low, false, &f_low);
        ob_telemetry_predict_kill_morality(u, &dummy_evil_high, false, &f_high);

        snprintf(line, sizeof(line), "#%02u %-7.7s L%02u A:%02u | L3:%+dA/%+dC | UND:%+dA/%+dC",
                 u->slot_index, cname, u->level, u->ali,
                 f_low.predicted_ali_delta, f_low.predicted_cha_delta,
                 f_high.predicted_ali_delta, f_high.predicted_cha_delta);
        draw_text(fb, w, h, p3_x + 8, p3_cy, line,
                  f_low.overlevel_penalty ? kColAmber : kColTextWhite);
        p3_cy += 11;
        shown_u++;
    }

    /* ======================================================================
     * PANEL 4 (Bottom-Right): PROMOTION CHECKLIST & 2,344-BIT DIFF FEED
     * ====================================================================== */
    int p4_x = mid_x + 2, p4_y = mid_y, p4_w = (int)w - mid_x - 6, p4_h = (int)h - mid_y - 4;
    fill_rect(fb, w, h, p4_x, p4_y, p4_w, p4_h, kColPanelBg);
    stroke_rect(fb, w, h, p4_x, p4_y, p4_w, p4_h, kColSubBorder);
    fill_rect(fb, w, h, p4_x + 1, p4_y + 1, p4_w - 2, 14, kColHeaderBg);
    draw_text(fb, w, h, p4_x + 6, p4_y + 4, "4. PROMOTION INSPECTOR & 2,344-BIT STORY DIFFS", kColCyan);

    int p4_cy = p4_y + 20;
    const ObUnitTelemetry *inspected = &curr_frame->units[state->selected_unit_slot % OB_MAX_ROSTER_UNITS];
    /* If slot 0 is empty, pick first populated unit */
    if (!inspected->is_populated) {
        for (uint8_t i = 0; i < OB_MAX_ROSTER_UNITS; ++i) {
            if (curr_frame->units[i].is_populated) {
                inspected = &curr_frame->units[i];
                break;
            }
        }
    }

    if (inspected->is_populated) {
        char cname[16];
        ob_telemetry_get_class_name(rom, rom_size, inspected->class_id, cname, sizeof(cname));
        snprintf(line, sizeof(line), "UNIT #%02u [%s] LVL:%u EXP:%u HP:%u/%u COST:%uG",
                 inspected->slot_index, cname, inspected->level, inspected->exp,
                 inspected->hp_current, inspected->hp_max, inspected->deploy_cost);
        draw_text(fb, w, h, p4_x + 8, p4_cy, line, kColGoldBorder);
        p4_cy += 11;

        snprintf(line, sizeof(line), "STR:%u AGI:%u INT:%u CHA:%u ALI:%u LUK:%u",
                 inspected->str, inspected->agi, inspected->intel,
                 inspected->cha, inspected->ali, inspected->luk);
        draw_text(fb, w, h, p4_x + 8, p4_cy, line, kColTextWhite);
        p4_cy += 12;

        ObPromotionCheck branches[8];
        size_t n_br = ob_telemetry_eval_promotions(inspected, wram, rom, rom_size, branches, 8);
        for (size_t b = 0; b < n_br && b < 4; ++b) {
            const ObPromotionCheck *br = &branches[b];
            if (br->required_relic != 0) {
                snprintf(line, sizeof(line), "-> %-10s [RELIC $%02X: %s]",
                         br->target_class_name, br->required_relic,
                         br->relic_in_stock ? "IN STOCK OK" : "MISSING");
            } else {
                snprintf(line, sizeof(line), "-> %-10s [L%u(%+d) ALI:%u..%u(%+d) CHA:%u(%+d)]",
                         br->target_class_name,
                         br->req_min_level, br->level_delta,
                         br->req_min_ali, br->req_max_ali, br->ali_delta,
                         br->req_min_cha, br->cha_delta);
            }
            draw_text(fb, w, h, p4_x + 8, p4_cy, line, br->eligible_now ? kColEmerald : kColAmber);
            p4_cy += 10;
        }
    } else {
        draw_text(fb, w, h, p4_x + 8, p4_cy, "AWAITING CAMPAIGN ROSTER INITIALIZATION...", kColTextMuted);
        p4_cy += 24;
    }

    p4_cy += 4;
    draw_text(fb, w, h, p4_x + 8, p4_cy, "LIVE 2,344-BIT STORY & TREASURE DIFF STREAM:", kColGoldBorder);
    p4_cy += 11;

    size_t start_idx = (state->recent_diff_count > 4) ? (state->recent_diff_count - 4) : 0;
    for (size_t d = start_idx; d < state->recent_diff_count; ++d) {
        const ObTelemetryDiffEvent *ev = &state->recent_diffs[d];
        snprintf(line, sizeof(line), "F%05u $7E:%04X [BIT %04u] %u->%u (%s)",
                 ev->frame_number, ev->wram_address, ev->bit_index,
                 ev->old_value, ev->new_value, ev->category);
        draw_text(fb, w, h, p4_x + 8, p4_cy, line, kColCyan);
        p4_cy += 10;
    }
    if (state->recent_diff_count == 0) {
        draw_text(fb, w, h, p4_x + 8, p4_cy, "MONITORING $7E:8600..$7E:8F27 FOR BIT TRANSITIONS...", kColTextMuted);
    }
}

bool ob_companion_window_save_ppm(
    const uint32_t *rgba_framebuffer,
    uint32_t width,
    uint32_t height,
    const char *filepath
) {
    if (!rgba_framebuffer || !filepath || width == 0 || height == 0) {
        return false;
    }
    FILE *fp = fopen(filepath, "wb");
    if (!fp) {
        return false;
    }
    fprintf(fp, "P6\n%u %u\n255\n", width, height);
    for (uint32_t i = 0; i < width * height; ++i) {
        uint32_t px = rgba_framebuffer[i];
        uint8_t rgb[3] = {
            (uint8_t)((px >> 16) & 0xFF),
            (uint8_t)((px >> 8) & 0xFF),
            (uint8_t)(px & 0xFF)
        };
        fwrite(rgb, 1, 3, fp);
    }
    fclose(fp);
    return true;
}
