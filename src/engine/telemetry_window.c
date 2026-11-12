#include "telemetry_window.h"
#include "ob_snes_ui_theme.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ==========================================================================
 * SNES TILE & GRAPHICS PRIMITIVES (Zero-Invasion Software Rasterizer)
 * ========================================================================== */

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

/* Authentic Quest Royal Blue Vertical Gradient with Mode 1 Dither */
static void draw_snes_window_fill(uint32_t *fb, uint32_t w, uint32_t h, int rx, int ry, int rw, int rh) {
    if (rw <= 0 || rh <= 0) return;
    int r_top = 0x18, g_top = 0x28, b_top = 0x68;
    int r_bot = 0x08, g_bot = 0x08, b_bot = 0x30;

    for (int y = ry; y < ry + rh; ++y) {
        if (y < 0 || (uint32_t)y >= h) continue;
        float t = (rh > 1) ? ((float)(y - ry) / (float)(rh - 1)) : 0.0f;
        int r = (int)(r_top + t * (r_bot - r_top));
        int g = (int)(g_top + t * (g_bot - g_top));
        int b = (int)(b_top + t * (b_bot - b_top));

        /* Subtle scanline dither: alternate by 2 steps */
        int dither = (y & 1) ? 2 : -2;
        r = (r + dither < 0) ? 0 : ((r + dither > 255) ? 255 : (r + dither));
        g = (g + dither < 0) ? 0 : ((g + dither > 255) ? 255 : (g + dither));
        b = (b + dither < 0) ? 0 : ((b + dither > 255) ? 255 : (b + dither));
        uint32_t col = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;

        for (int x = rx; x < rx + rw; ++x) {
            if (x < 0 || (uint32_t)x >= w) continue;
            fb[(uint32_t)y * w + (uint32_t)x] = col;
        }
    }
}

/* 8x8 1-bit Tile Blitter with Transparent Keying and 1px Drop Shadow */
static void draw_snes_tile_1bit(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y, const uint8_t tile[8],
    uint32_t fg_col, uint32_t bg_col, bool transparent_bg, bool shadow
) {
    for (int r = 0; r < 8; ++r) {
        uint8_t row = tile[r];
        for (int c = 0; c < 8; ++c) {
            if (row & (0x80U >> c)) {
                if (shadow) {
                    put_px(fb, w, h, x + c + 1, y + r + 1, OB_COLOR_WINDOW_BEVEL_DARK);
                }
                put_px(fb, w, h, x + c, y + r, fg_col);
            } else if (!transparent_bg) {
                put_px(fb, w, h, x + c, y + r, bg_col);
            }
        }
    }
}

/* Authentic 9-Slice Dialogue Box with Ornate Gold Corners and Rails */
static void draw_snes_9slice_box(
    uint32_t *fb, uint32_t w, uint32_t h,
    int rx, int ry, int rw, int rh,
    const char *title
) {
    /* Snap to 8-pixel boundaries */
    rx = (rx / 8) * 8;
    ry = (ry / 8) * 8;
    rw = (rw / 8) * 8;
    rh = (rh / 8) * 8;

    /* Fill Royal Blue Gradient Interior */
    draw_snes_window_fill(fb, w, h, rx + 4, ry + 4, rw - 8, rh - 8);

    /* Dark inner bevel shadow */
    stroke_rect(fb, w, h, rx + 3, ry + 3, rw - 6, rh - 6, OB_COLOR_WINDOW_BEVEL_DARK);

    /* 4 Ornate Corners */
    draw_snes_tile_1bit(fb, w, h, rx, ry, kSnesTileCornerTL, OB_COLOR_GOLD_HI, 0, true, false);
    draw_snes_tile_1bit(fb, w, h, rx + rw - 8, ry, kSnesTileCornerTR, OB_COLOR_GOLD_HI, 0, true, false);
    draw_snes_tile_1bit(fb, w, h, rx, ry + rh - 8, kSnesTileCornerBL, OB_COLOR_GOLD_SHADOW, 0, true, false);
    draw_snes_tile_1bit(fb, w, h, rx + rw - 8, ry + rh - 8, kSnesTileCornerBR, OB_COLOR_GOLD_SHADOW, 0, true, false);

    /* Horizontal Rails */
    for (int x = rx + 8; x <= rx + rw - 16; x += 8) {
        draw_snes_tile_1bit(fb, w, h, x, ry, kSnesTileRailHoriz, OB_COLOR_GOLD_MID, 0, true, false);
        draw_snes_tile_1bit(fb, w, h, x, ry + rh - 8, kSnesTileRailHoriz, OB_COLOR_GOLD_SHADOW, 0, true, false);
    }

    /* Vertical Rails */
    for (int y = ry + 8; y <= ry + rh - 16; y += 8) {
        draw_snes_tile_1bit(fb, w, h, rx, y, kSnesTileRailVert, OB_COLOR_GOLD_MID, 0, true, false);
        draw_snes_tile_1bit(fb, w, h, rx + rw - 8, y, kSnesTileRailVert, OB_COLOR_GOLD_SHADOW, 0, true, false);
    }

    /* Header Bar & Title */
    if (title && title[0] != '\0') {
        fill_rect(fb, w, h, rx + 8, ry + 3, rw - 16, 13, 0xFF101838U);
        stroke_rect(fb, w, h, rx + 8, ry + 3, rw - 16, 13, OB_COLOR_GOLD_DARK);
        draw_snes_tile_1bit(fb, w, h, rx + 10, ry + 6, kSnesTileHeaderGem, OB_COLOR_GOLD_HI, 0, true, false);
    }
}

/* Palette Mapping for 8x8 Text */
static uint32_t get_snes_pal_color(ObSnesPalette pal) {
    switch (pal) {
        case OB_SNES_PAL_GOLD:    return OB_COLOR_TEXT_GOLD;
        case OB_SNES_PAL_CRIMSON: return OB_COLOR_TEXT_CRIMSON;
        case OB_SNES_PAL_EMERALD: return OB_COLOR_TEXT_EMERALD;
        case OB_SNES_PAL_CYAN:    return OB_COLOR_TEXT_CYAN;
        case OB_SNES_PAL_MUTED:   return OB_COLOR_TEXT_MUTED;
        case OB_SNES_PAL_PURPLE:  return OB_COLOR_TEXT_PURPLE;
        case OB_SNES_PAL_AMBER:   return OB_COLOR_TEXT_AMBER;
        case OB_SNES_PAL_IVORY:
        default:                  return OB_COLOR_TEXT_IVORY;
    }
}

/* Authentic 8x8 SNES Drop-Shadow Typography */
static void draw_snes_tile_text(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y,
    const char *str,
    ObSnesPalette pal
) {
    if (!str) return;
    uint32_t fg_col = get_snes_pal_color(pal);
    int cx = x;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)str[i];
        if (c < 0x20 || c > 0x7E) c = '?';
        const uint8_t *glyph = kSnesFont8x8[c - 0x20];

        /* Blit glyph with 1px drop shadow */
        for (int r = 0; r < 8; ++r) {
            uint8_t row = glyph[r];
            for (int col = 0; col < 8; ++col) {
                if (row & (0x80U >> col)) {
                    /* Shadow */
                    put_px(fb, w, h, cx + col + 1, y + r + 1, OB_COLOR_WINDOW_BEVEL_DARK);
                    /* Foreground */
                    put_px(fb, w, h, cx + col, y + r, fg_col);
                }
            }
        }
        cx += 8;
    }
}

/* Segmented 16-Bit RPG Gauge Meter */
static void draw_snes_gauge_bar(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y, int bw, int bh,
    int val, int max_val,
    uint32_t fill_col, uint32_t empty_col
) {
    fill_rect(fb, w, h, x, y, bw, bh, empty_col);
    stroke_rect(fb, w, h, x, y, bw, bh, OB_COLOR_GOLD_SHADOW);

    if (max_val > 0 && val > 0) {
        int fw = (val >= max_val) ? (bw - 2) : ((val * (bw - 2)) / max_val);
        fill_rect(fb, w, h, x + 1, y + 1, fw, bh - 2, fill_col);
        /* Segment dividers every 8 pixels */
        for (int sx = x + 8; sx < x + 1 + fw; sx += 8) {
            fill_rect(fb, w, h, sx, y + 1, 1, bh - 2, OB_COLOR_WINDOW_BEVEL_DARK);
        }
    }
}

/* ==========================================================================
 * COMPANION WINDOW STATE MANAGEMENT
 * ========================================================================== */

void ob_companion_window_init(ObCompanionWindowState *state) {
    if (!state) return;
    memset(state, 0, sizeof(*state));
    state->mode                  = OB_HUD_EXPLORER;
    state->active_page           = OB_COMPANION_PAGE_TACTICAL;
    state->selected_unit_slot    = 0;
    state->selected_squad_id     = 0;
    state->show_hidden_poi_radar = false;
}

void ob_companion_window_cycle_page(ObCompanionWindowState *state) {
    if (!state) return;
    state->active_page = (ObCompanionPage)(((int)state->active_page + 1) % 3);
}

void ob_companion_window_toggle_poi(ObCompanionWindowState *state) {
    if (!state) return;
    state->show_hidden_poi_radar = !state->show_hidden_poi_radar;
}

/* ==========================================================================
 * PAGE 1: Tactical Command, Spatial Radar & Recapture Threat Vectors
 * ========================================================================== */
static void render_page_tactical(
    ObCompanionWindowState *state,
    const ObTelemetryFrame *curr_frame,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t *fb,
    uint32_t w,
    uint32_t h
) {
    (void)wram; (void)rom; (void)rom_size;
    char line[128];

    /* 4-Quadrant 8-Pixel Snapped Layout */
    int q1_x = 8,   q1_y = 32,  q1_w = 304, q1_h = 208;
    int q2_x = 328, q2_y = 32,  q2_w = 304, q2_h = 208;
    int q3_x = 8,   q3_y = 248, q3_w = 304, q3_h = 224;
    int q4_x = 328, q4_y = 248, q4_w = 304, q4_h = 224;

    /* QUADRANT 1: Macro Economy & Celestial Clock */
    draw_snes_9slice_box(fb, w, h, q1_x, q1_y, q1_w, q1_h, "1. REPUTATION & CLOCK");
    draw_snes_tile_text(fb, w, h, q1_x + 24, q1_y + 6, "1. REPUTATION & CLOCK", OB_SNES_PAL_GOLD);

    int cy = q1_y + 24;
    snprintf(line, sizeof(line), "CHAOS FRAME: %u / 100", curr_frame->chaos_frame);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_IVORY);
    draw_snes_gauge_bar(fb, w, h, q1_x + 12, cy + 11, q1_w - 24, 9,
                        curr_frame->chaos_frame, 100,
                        (curr_frame->chaos_frame >= 65) ? OB_COLOR_TEXT_EMERALD :
                        (curr_frame->chaos_frame >= 35 ? OB_COLOR_TEXT_AMBER : OB_COLOR_TEXT_CRIMSON),
                        OB_COLOR_WINDOW_BEVEL_DARK);
    cy += 26;

    snprintf(line, sizeof(line), "TREASURY: %u GOTH", curr_frame->goth_treasury);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_GOLD);
    cy += 14;

    snprintf(line, sizeof(line), "NOON NET: %+d GOTH", curr_frame->projected_noon_net);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line,
                        (curr_frame->projected_noon_net >= 0) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
    cy += 14;

    /* Celestial Phase with Sun/Moon Icon */
    draw_snes_tile_1bit(fb, w, h, q1_x + 12, cy,
                        curr_frame->calendar.is_nighttime ? kSnesIconMoon : kSnesIconSun,
                        curr_frame->calendar.is_nighttime ? OB_COLOR_TEXT_AMBER : OB_COLOR_TEXT_GOLD,
                        0, true, true);
    snprintf(line, sizeof(line), "CLOCK: %02u:%02u (%s)",
             curr_frame->calendar.hour, curr_frame->calendar.minute,
             curr_frame->calendar.is_nighttime ? "NIGHT" : "DAY");
    draw_snes_tile_text(fb, w, h, q1_x + 24, cy, line, OB_SNES_PAL_IVORY);
    cy += 14;

    snprintf(line, sizeof(line), "CALENDAR: YR %u MO %u DAY %u [WK %u]",
             curr_frame->calendar.year, curr_frame->calendar.month,
             curr_frame->calendar.day, curr_frame->calendar.lunar_weekday);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_MUTED);
    cy += 16;

    ObEndingAudit ending;
    ob_telemetry_audit_ending(curr_frame, &ending);
    snprintf(line, sizeof(line), "ENDING: %s", ending.ending_name);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_GOLD);
    cy += 13;
    snprintf(line, sizeof(line), "ALT:    %s", ending.nearest_alt_name);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_MUTED);

    /* QUADRANT 2: 2D Spatial Radar & Recapture Alert */
    draw_snes_9slice_box(fb, w, h, q2_x, q2_y, q2_w, q2_h, "2. SPATIAL RADAR");
    draw_snes_tile_text(fb, w, h, q2_x + 24, q2_y + 6, "2. SPATIAL RADAR", OB_SNES_PAL_GOLD);

    /* Mini-Radar Canvas (136 x 112 px) */
    int rad_x = q2_x + 12, rad_y = q2_y + 24, rad_w = 136, rad_h = 104;
    fill_rect(fb, w, h, rad_x, rad_y, rad_w, rad_h, 0xFF0A1020U);
    stroke_rect(fb, w, h, rad_x, rad_y, rad_w, rad_h, OB_COLOR_GOLD_DARK);

    /* Subtle Terrain Dither Dots */
    for (int ty = rad_y + 4; ty < rad_y + rad_h - 4; ty += 8) {
        for (int tx = rad_x + 4; tx < rad_x + rad_w - 4; tx += 8) {
            put_px(fb, w, h, tx, ty, 0xFF142038U);
        }
    }

    /* Plot Cities on Radar */
    for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        const ObCityTelemetry *city = &curr_frame->cities[c];
        if (!city->exists) continue;
        int cx = rad_x + 4 + ((city->world_x & 0x07FF) * (rad_w - 8)) / 2048;
        int c_y = rad_y + 4 + ((city->world_y & 0x07FF) * (rad_h - 8)) / 2048;
        bool is_lib = ((city->ownership_mask & 0x01) != 0);
        bool is_hidden = ((city->ownership_mask & 0x02) != 0);

        if (is_hidden && !state->show_hidden_poi_radar) continue;

        uint32_t col = is_lib ? OB_COLOR_TEXT_CYAN : (is_hidden ? OB_COLOR_TEXT_PURPLE : OB_COLOR_TEXT_AMBER);
        fill_rect(fb, w, h, cx - 2, c_y - 2, 4, 4, col);
        if (is_hidden) {
            stroke_rect(fb, w, h, cx - 3, c_y - 3, 6, 6, OB_COLOR_GOLD_HI);
        }
    }

    /* Plot Squads on Radar */
    uint8_t ply_cnt = 0, enm_cnt = 0;
    for (uint8_t s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        const ObMapEntityTelemetry *ent = &curr_frame->map_entities[s];
        if (!ent->is_active) continue;
        if (ent->is_enemy) enm_cnt++; else ply_cnt++;
        int sx = rad_x + 4 + ((ent->world_x & 0x07FF) * (rad_w - 8)) / 2048;
        int sy = rad_y + 4 + ((ent->world_y & 0x07FF) * (rad_h - 8)) / 2048;
        if (ent->target_x > 0 && ent->target_x != 0x7FFF) {
            int tx = rad_x + 4 + ((ent->target_x & 0x07FF) * (rad_w - 8)) / 2048;
            int ty = rad_y + 4 + ((ent->target_y & 0x07FF) * (rad_h - 8)) / 2048;
            draw_line(fb, w, h, sx, sy, tx, ty, ent->is_enemy ? 0xFF882020U : 0xFF208840U);
        }
        fill_rect(fb, w, h, sx - 2, sy - 2, 5, 5, ent->is_enemy ? OB_COLOR_TEXT_CRIMSON : OB_COLOR_TEXT_EMERALD);
    }

    /* Info beside radar */
    int rx_info = rad_x + rad_w + 10;
    int ry_info = q2_y + 24;
    snprintf(line, sizeof(line), "SQUADS: %uP/%uE", ply_cnt, enm_cnt);
    draw_snes_tile_text(fb, w, h, rx_info, ry_info, line, OB_SNES_PAL_IVORY);
    ry_info += 14;

    snprintf(line, sizeof(line), "POI RADAR: %s", state->show_hidden_poi_radar ? "ON" : "OFF");
    draw_snes_tile_text(fb, w, h, rx_info, ry_info, line,
                        state->show_hidden_poi_radar ? OB_SNES_PAL_CYAN : OB_SNES_PAL_MUTED);
    ry_info += 14;

    /* Recapture Threat Alert Box */
    ObRecaptureThreat threats[4];
    size_t n_threats = ob_telemetry_detect_recapture_threats(curr_frame, threats, 4);
    int th_y = q2_y + 138;
    if (n_threats > 0) {
        fill_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 26, 0xFF481010U);
        stroke_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 26, OB_COLOR_TEXT_CRIMSON);
        draw_snes_tile_text(fb, w, h, q2_x + 12, th_y + 4, "! -5 CF RECAPTURE RISK !", OB_SNES_PAL_CRIMSON);
        snprintf(line, sizeof(line), "ENM #%02u -> %s (ETA %dt)",
                 threats[0].enemy_slot, threats[0].is_temple ? "TEMPLE" : "CITY", threats[0].eta_ticks);
        draw_snes_tile_text(fb, w, h, q2_x + 12, th_y + 15, line, OB_SNES_PAL_AMBER);
    } else {
        fill_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 26, 0xFF101828U);
        stroke_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 26, OB_COLOR_GOLD_DARK);
        draw_snes_tile_text(fb, w, h, q2_x + 12, th_y + 8, "CITIES SECURE (NO THREAT)", OB_SNES_PAL_EMERALD);
    }

    /* QUADRANT 3: Town Liberation Matcher */
    draw_snes_9slice_box(fb, w, h, q3_x, q3_y, q3_w, q3_h, "3. LIBERATION ADVISOR");
    draw_snes_tile_text(fb, w, h, q3_x + 24, q3_y + 6, "3. LIBERATION ADVISOR", OB_SNES_PAL_GOLD);

    int ly = q3_y + 24;
    ObCityLiberationMatch matches[4];
    size_t n_matches = ob_telemetry_match_city_liberators(curr_frame, matches, 4);
    if (n_matches > 0) {
        for (size_t m = 0; m < n_matches && m < 3; ++m) {
            const ObCityLiberationMatch *lm = &matches[m];
            snprintf(line, sizeof(line), "CITY #%02u -> SQ #%02u:", lm->city_index, lm->recommended_squad_id);
            draw_snes_tile_text(fb, w, h, q3_x + 12, ly, line, OB_SNES_PAL_IVORY);
            ly += 12;
            snprintf(line, sizeof(line), "  CF: %+d (MISMATCH: %u)",
                     lm->predicted_cf_delta, lm->ali_mismatch_distance);
            draw_snes_tile_text(fb, w, h, q3_x + 12, ly, line,
                                (lm->predicted_cf_delta >= 1) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
            ly += 14;
        }
    } else {
        draw_snes_tile_text(fb, w, h, q3_x + 12, ly, "ALL STAGE CITIES LIBERATED!", OB_SNES_PAL_EMERALD);
        ly += 14;
    }

    /* Stage PoI summary */
    ObHiddenPoISummary poi;
    ob_telemetry_audit_hidden_poi(curr_frame, &poi);
    snprintf(line, sizeof(line), "POI: %u HIDDEN CITIES, %u TEMPLES",
             poi.unrevealed_cities_count, poi.unrevealed_temples_count);
    draw_snes_tile_text(fb, w, h, q3_x + 12, ly, line, OB_SNES_PAL_MUTED);

    /* QUADRANT 4: Squad Mobility & Intercepts */
    draw_snes_9slice_box(fb, w, h, q4_x, q4_y, q4_w, q4_h, "4. SQUAD MOBILITY");
    draw_snes_tile_text(fb, w, h, q4_x + 24, q4_y + 6, "4. SQUAD MOBILITY", OB_SNES_PAL_GOLD);

    int my = q4_y + 24;
    ObSquadMobilityAnalysis mob;
    ob_telemetry_analyze_squad_mobility(curr_frame, state->selected_squad_id, &mob);

    snprintf(line, sizeof(line), "SQ #%02u: %s", state->selected_squad_id, mob.move_type_name);
    draw_snes_tile_text(fb, w, h, q4_x + 12, my, line, OB_SNES_PAL_GOLD);
    my += 14;

    snprintf(line, sizeof(line), "FLYERS: %u (NEED +%u -> SKY)", mob.flyers_count, mob.flyers_needed_for_sky);
    draw_snes_tile_text(fb, w, h, q4_x + 12, my, line,
                        (mob.flyers_needed_for_sky == 0) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_CYAN);
    my += 14;

    snprintf(line, sizeof(line), "TIME BUFF: %s",
             mob.is_day_favored ? "DAY / SOLAR (+STR)" : (mob.is_night_favored ? "NIGHT / LUNAR" : "BALANCED"));
    draw_snes_tile_text(fb, w, h, q4_x + 12, my, line, OB_SNES_PAL_IVORY);
    my += 16;

    if (mob.flyers_needed_for_sky > 0) {
        snprintf(line, sizeof(line), "UPGRADE: +%u FLYERS -> SKY", mob.flyers_needed_for_sky);
        draw_snes_tile_text(fb, w, h, q4_x + 12, my, line, OB_SNES_PAL_CYAN);
    } else {
        draw_snes_tile_text(fb, w, h, q4_x + 12, my, "UPGRADE: FULL SKY SQUAD!", OB_SNES_PAL_EMERALD);
    }
    my += 16;

    /* Live 2,344-bit diff stream snippet */
    draw_snes_tile_text(fb, w, h, q4_x + 12, my, "LIVE BIT-DIFF EVENT STREAM:", OB_SNES_PAL_MUTED);
    my += 12;
    if (state->recent_diff_count > 0) {
        const ObTelemetryDiffEvent *ev = &state->recent_diffs[state->recent_diff_count - 1];
        snprintf(line, sizeof(line), "$7E:%04X [BIT %04u] %u->%u",
                 ev->wram_address, ev->bit_index, ev->old_value, ev->new_value);
        draw_snes_tile_text(fb, w, h, q4_x + 12, my, line, OB_SNES_PAL_CYAN);
    } else {
        draw_snes_tile_text(fb, w, h, q4_x + 12, my, "NO STATE TRANSITIONS OBSERVED", OB_SNES_PAL_MUTED);
    }
}

/* ==========================================================================
 * PAGE 2: Combat Arena, Live Clash Tug-of-War & Tarot Overlevel Guard
 * ========================================================================== */
static void render_page_combat_tarot(
    ObCompanionWindowState *state,
    const ObTelemetryFrame *curr_frame,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t *fb,
    uint32_t w,
    uint32_t h
) {
    (void)state; (void)wram; (void)rom; (void)rom_size;
    char line[128];

    int q1_x = 8,   q1_y = 32,  q1_w = 304, q1_h = 208;
    int q2_x = 328, q2_y = 32,  q2_w = 304, q2_h = 208;
    int q3_x = 8,   q3_y = 248, q3_w = 304, q3_h = 224;
    int q4_x = 328, q4_y = 248, q4_w = 304, q4_h = 224;

    /* QUADRANT 1: 14-Slot Tarot Hand & Overlevel Risk Alerts */
    draw_snes_9slice_box(fb, w, h, q1_x, q1_y, q1_w, q1_h, "1. TAROT HAND AUDIT");
    draw_snes_tile_text(fb, w, h, q1_x + 24, q1_y + 6, "1. TAROT HAND AUDIT", OB_SNES_PAL_GOLD);

    int ty = q1_y + 24;
    ObTarotAudit audits[14];
    size_t n_cards = ob_telemetry_audit_tarot_hand(curr_frame, audits, 14);

    snprintf(line, sizeof(line), "HAND: %zu/14 CARDS | LORD LV%u",
             n_cards, curr_frame->units[0].level);
    draw_snes_tile_text(fb, w, h, q1_x + 12, ty, line, OB_SNES_PAL_GOLD);
    ty += 14;

    for (size_t i = 0; i < n_cards && i < 3; ++i) {
        const ObTarotAudit *a = &audits[i];
        draw_snes_tile_1bit(fb, w, h, q1_x + 12, ty, kSnesIconTarot,
                            a->leader_overlevel_risk ? OB_COLOR_TEXT_CRIMSON : OB_COLOR_TEXT_GOLD,
                            0, true, true);
        snprintf(line, sizeof(line), "%s", a->card_name);
        draw_snes_tile_text(fb, w, h, q1_x + 24, ty, line,
                            a->leader_overlevel_risk ? OB_SNES_PAL_CRIMSON : OB_SNES_PAL_IVORY);
        ty += 12;

        if (a->leader_overlevel_risk) {
            draw_snes_tile_text(fb, w, h, q1_x + 24, ty, "! OVERLEVEL TRAP: -ALI !", OB_SNES_PAL_CRIMSON);
            ty += 12;
        } else {
            snprintf(line, sizeof(line), "-> %s", a->draw_effect);
            draw_snes_tile_text(fb, w, h, q1_x + 24, ty, line, OB_SNES_PAL_MUTED);
            ty += 12;
        }
    }
    if (n_cards == 0) {
        draw_snes_tile_text(fb, w, h, q1_x + 12, ty, "NO TAROT CARDS IN HAND", OB_SNES_PAL_MUTED);
    }

    /* QUADRANT 2: Live Combat Tug-of-War */
    draw_snes_9slice_box(fb, w, h, q2_x, q2_y, q2_w, q2_h, "2. CLASH TUG-OF-WAR");
    draw_snes_tile_text(fb, w, h, q2_x + 24, q2_y + 6, "2. CLASH TUG-OF-WAR", OB_SNES_PAL_GOLD);

    int cy = q2_y + 24;
    const ObCombatTelemetry *cmb = &curr_frame->combat;

    draw_snes_tile_1bit(fb, w, h, q2_x + 12, cy, kSnesIconSword, OB_COLOR_TEXT_GOLD, 0, true, true);
    snprintf(line, sizeof(line), "STATUS: %s", cmb->in_combat ? "ACTIVE CLASH" : "STANDBY");
    draw_snes_tile_text(fb, w, h, q2_x + 24, cy, line,
                        cmb->in_combat ? OB_SNES_PAL_CRIMSON : OB_SNES_PAL_MUTED);
    cy += 14;

    snprintf(line, sizeof(line), "PLY: %u DMG  VS  ENM: %u DMG",
             cmb->player_clash_damage, cmb->enemy_clash_damage);
    draw_snes_tile_text(fb, w, h, q2_x + 12, cy, line, OB_SNES_PAL_IVORY);
    cy += 12;

    int total_dmg = (int)cmb->player_clash_damage + (int)cmb->enemy_clash_damage;
    int ply_ratio = (total_dmg > 0) ? ((int)cmb->player_clash_damage * 100 / total_dmg) : 50;
    draw_snes_gauge_bar(fb, w, h, q2_x + 12, cy, q2_w - 24, 10,
                        ply_ratio, 100, OB_COLOR_TEXT_EMERALD, OB_COLOR_TEXT_CRIMSON);
    cy += 18;

    int margin = (int)cmb->player_clash_damage - (int)cmb->enemy_clash_damage;
    snprintf(line, sizeof(line), "PUSHBACK MARGIN: %+d DMG", margin);
    draw_snes_tile_text(fb, w, h, q2_x + 12, cy, line,
                        (margin >= 0) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_CRIMSON);
    cy += 14;
    snprintf(line, sizeof(line), "TACTIC: $%02X | ACTIONS LEFT: %u",
             cmb->active_tactic, cmb->total_actions_left);
    draw_snes_tile_text(fb, w, h, q2_x + 12, cy, line, OB_SNES_PAL_MUTED);

    /* QUADRANT 3: Pre-Clash Morality Drift */
    draw_snes_9slice_box(fb, w, h, q3_x, q3_y, q3_w, q3_h, "3. MORALITY DRIFT");
    draw_snes_tile_text(fb, w, h, q3_x + 24, q3_y + 6, "3. MORALITY DRIFT", OB_SNES_PAL_GOLD);

    int my = q3_y + 24;
    draw_snes_tile_text(fb, w, h, q3_x + 12, my, "KILL DRIFT FORECAST:", OB_SNES_PAL_IVORY);
    my += 14;

    ObUnitTelemetry dummy_holy_low = {0};
    dummy_holy_low.level = 3; dummy_holy_low.ali = 75;
    ObUnitTelemetry dummy_evil_high = {0};
    dummy_evil_high.level = 12; dummy_evil_high.ali = 15; dummy_evil_high.status_mask = 0x20;

    for (uint8_t u_idx = 0; u_idx < 4; ++u_idx) {
        const ObUnitTelemetry *u = &curr_frame->units[u_idx];
        if (!u->is_populated) continue;
        char cname[16];
        ob_telemetry_get_class_name(rom, rom_size, u->class_id, cname, sizeof(cname));
        ObMoralityDriftForecast f_low, f_high;
        ob_telemetry_predict_kill_morality(u, &dummy_holy_low, false, &f_low);
        ob_telemetry_predict_kill_morality(u, &dummy_evil_high, false, &f_high);

        snprintf(line, sizeof(line), "#%02u %-6.6s L%02u A%02u:", u->slot_index, cname, u->level, u->ali);
        draw_snes_tile_text(fb, w, h, q3_x + 12, my, line, OB_SNES_PAL_IVORY);
        my += 11;
        snprintf(line, sizeof(line), " vs L3: %+dA | vs UND: %+dA",
                 f_low.predicted_ali_delta, f_high.predicted_ali_delta);
        draw_snes_tile_text(fb, w, h, q3_x + 12, my, line,
                            f_low.overlevel_penalty ? OB_SNES_PAL_AMBER : OB_SNES_PAL_EMERALD);
        my += 13;
    }

    /* QUADRANT 4: Neutral Encounter Matrix */
    draw_snes_9slice_box(fb, w, h, q4_x, q4_y, q4_w, q4_h, "4. NEUTRAL MATRIX");
    draw_snes_tile_text(fb, w, h, q4_x + 24, q4_y + 6, "4. NEUTRAL MATRIX", OB_SNES_PAL_GOLD);

    int ny = q4_y + 24;
    ObNeutralSpawnForecast neutral;
    ob_telemetry_forecast_neutral_encounters(curr_frame, state->selected_squad_id, &neutral);

    snprintf(line, sizeof(line), "TERRAIN: %s", neutral.terrain_name);
    draw_snes_tile_text(fb, w, h, q4_x + 12, ny, line, OB_SNES_PAL_GOLD);
    ny += 14;

    snprintf(line, sizeof(line), "SPAWN: %s (LV %u)", neutral.spawn_class_name, neutral.spawn_level);
    draw_snes_tile_text(fb, w, h, q4_x + 12, ny, line, OB_SNES_PAL_IVORY);
    ny += 14;

    snprintf(line, sizeof(line), "RECRUITER: %s", neutral.recruiter_class_name);
    draw_snes_tile_text(fb, w, h, q4_x + 12, ny, line, OB_SNES_PAL_MUTED);
    ny += 14;

    snprintf(line, sizeof(line), "PERSUADE: %s", neutral.persuade_ready ? "READY (IN SQUAD)" : "LACK RECRUITER");
    draw_snes_tile_text(fb, w, h, q4_x + 12, ny, line,
                        neutral.persuade_ready ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
    ny += 16;

    if (neutral.is_undead_ali_farm) {
        draw_snes_tile_1bit(fb, w, h, q4_x + 12, ny, kSnesIconSkull, OB_COLOR_TEXT_CYAN, 0, true, true);
        draw_snes_tile_text(fb, w, h, q4_x + 24, ny, "HOLY FARM: PERSUADE UNDEAD!", OB_SNES_PAL_CYAN);
    }
}

/* ==========================================================================
 * PAGE 3: Campaign Guide, 18 Special Heroes & 12 Zodiac Stones Tracker
 * ========================================================================== */
static void render_page_campaign_guide(
    ObCompanionWindowState *state,
    const ObTelemetryFrame *curr_frame,
    const uint8_t *wram,
    const uint8_t *rom,
    uint32_t rom_size,
    uint32_t *fb,
    uint32_t w,
    uint32_t h
) {
    (void)state; (void)rom; (void)rom_size;
    char line[128];

    int q1_x = 8,   q1_y = 32,  q1_w = 304, q1_h = 208;
    int q2_x = 328, q2_y = 32,  q2_w = 304, q2_h = 208;
    int q3_x = 8,   q3_y = 248, q3_w = 304, q3_h = 224;
    int q4_x = 328, q4_y = 248, q4_w = 304, q4_h = 224;

    /* QUADRANT 1: 18 Special Heroes Auditor */
    draw_snes_9slice_box(fb, w, h, q1_x, q1_y, q1_w, q1_h, "1. SPECIAL HEROES");
    draw_snes_tile_text(fb, w, h, q1_x + 24, q1_y + 6, "1. SPECIAL HEROES", OB_SNES_PAL_GOLD);

    int hy = q1_y + 24;
    ObHeroRecruitmentAudit heroes[18];
    size_t n_heroes = ob_telemetry_audit_special_recruits(curr_frame, heroes, 18);

    for (size_t i = 0; i < n_heroes && i < 6; ++i) {
        const ObHeroRecruitmentAudit *ha = &heroes[i];
        draw_snes_tile_1bit(fb, w, h, q1_x + 12, hy, kSnesIconCrown,
                            ha->is_recruited ? OB_COLOR_TEXT_EMERALD : OB_COLOR_TEXT_MUTED,
                            0, true, true);
        snprintf(line, sizeof(line), "%-8s [%s]", ha->hero_name, ha->status_summary);
        draw_snes_tile_text(fb, w, h, q1_x + 24, hy, line,
                            ha->is_recruited ? OB_SNES_PAL_EMERALD :
                            (ha->prereq_cf_met && ha->prereq_ali_met ? OB_SNES_PAL_AMBER : OB_SNES_PAL_MUTED));
        hy += 13;
        if (ha->tradeoff_warning[0] != '\0') {
            snprintf(line, sizeof(line), " ! %s", ha->tradeoff_warning);
            draw_snes_tile_text(fb, w, h, q1_x + 24, hy, line, OB_SNES_PAL_CRIMSON);
            hy += 12;
        }
    }

    /* QUADRANT 2: 12 Zodiac Stones Tracker */
    draw_snes_9slice_box(fb, w, h, q2_x, q2_y, q2_w, q2_h, "2. 12 ZODIAC STONES");
    draw_snes_tile_text(fb, w, h, q2_x + 24, q2_y + 6, "2. 12 ZODIAC STONES", OB_SNES_PAL_GOLD);

    int zy = q2_y + 24;
    ObZodiacQuestStatus z;
    ob_telemetry_track_zodiac_stones(curr_frame, &z);

    draw_snes_tile_1bit(fb, w, h, q2_x + 12, zy, kSnesIconGem, OB_COLOR_TEXT_PURPLE, 0, true, true);
    snprintf(line, sizeof(line), "STONES: %u / 12 COLLECTED", z.stones_collected_count);
    draw_snes_tile_text(fb, w, h, q2_x + 24, zy, line, OB_SNES_PAL_GOLD);
    zy += 14;

    draw_snes_gauge_bar(fb, w, h, q2_x + 12, zy, q2_w - 24, 8,
                        z.stones_collected_count, 12, OB_COLOR_TEXT_PURPLE, OB_COLOR_WINDOW_BEVEL_DARK);
    zy += 16;

    snprintf(line, sizeof(line), "QUICKSILVER ($45): %s", z.quicksilver_in_hand ? "IN INVENTORY" : "MISSING");
    draw_snes_tile_text(fb, w, h, q2_x + 12, zy, line,
                        z.quicksilver_in_hand ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_MUTED);
    zy += 13;

    snprintf(line, sizeof(line), "TABLET OF YARU:    %s", z.tablet_of_yaru_in_hand ? "IN INVENTORY" : "PENDING");
    draw_snes_tile_text(fb, w, h, q2_x + 12, zy, line,
                        z.tablet_of_yaru_in_hand ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_MUTED);
    zy += 13;

    snprintf(line, sizeof(line), "BRUNHILD QUEST: %s",
             (z.quicksilver_in_hand && z.tablet_of_yaru_in_hand && z.stones_collected_count == 12)
             ? "READY TO RETRIEVE!" : "PREREQUISITES PENDING");
    draw_snes_tile_text(fb, w, h, q2_x + 12, zy, line,
                        (z.quicksilver_in_hand && z.tablet_of_yaru_in_hand) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);

    /* QUADRANT 3: Warren Quiz Lord Archetype */
    draw_snes_9slice_box(fb, w, h, q3_x, q3_y, q3_w, q3_h, "3. LORD ARCHETYPE");
    draw_snes_tile_text(fb, w, h, q3_x + 24, q3_y + 6, "3. LORD ARCHETYPE", OB_SNES_PAL_GOLD);

    int wy = q3_y + 24;
    ObLordArchetypePreview lord_prev;
    ob_telemetry_preview_lord_archetype(wram, &lord_prev);

    snprintf(line, sizeof(line), "ARCHETYPE: %s", lord_prev.archetype_name);
    draw_snes_tile_text(fb, w, h, q3_x + 12, wy, line, OB_SNES_PAL_GOLD);
    wy += 14;

    snprintf(line, sizeof(line), "FRONT: %s", lord_prev.front_skill);
    draw_snes_tile_text(fb, w, h, q3_x + 12, wy, line, OB_SNES_PAL_IVORY);
    wy += 12;

    snprintf(line, sizeof(line), "BACK:  %s", lord_prev.back_skill);
    draw_snes_tile_text(fb, w, h, q3_x + 12, wy, line, OB_SNES_PAL_IVORY);
    wy += 12;

    snprintf(line, sizeof(line), "ARMY:  %s", lord_prev.starting_troops);
    draw_snes_tile_text(fb, w, h, q3_x + 12, wy, line, OB_SNES_PAL_CYAN);

    /* QUADRANT 4: Promotion Tree Inspector */
    draw_snes_9slice_box(fb, w, h, q4_x, q4_y, q4_w, q4_h, "4. PROMOTION TREE");
    draw_snes_tile_text(fb, w, h, q4_x + 24, q4_y + 6, "4. PROMOTION TREE", OB_SNES_PAL_GOLD);

    int py = q4_y + 24;
    const ObUnitTelemetry *inspected = &curr_frame->units[state->selected_unit_slot % OB_MAX_ROSTER_UNITS];
    if (inspected->is_populated) {
        char cname[16];
        ob_telemetry_get_class_name(rom, rom_size, inspected->class_id, cname, sizeof(cname));
        snprintf(line, sizeof(line), "UNIT #%02u [%s] LV%u A%u C%u",
                 inspected->slot_index, cname, inspected->level, inspected->ali, inspected->cha);
        draw_snes_tile_text(fb, w, h, q4_x + 12, py, line, OB_SNES_PAL_GOLD);
        py += 14;

        ObPromotionCheck branches[4];
        size_t n_br = ob_telemetry_eval_promotions(inspected, wram, rom, rom_size, branches, 4);
        for (size_t b = 0; b < n_br && b < 3; ++b) {
            const ObPromotionCheck *br = &branches[b];
            if (br->required_relic != 0) {
                snprintf(line, sizeof(line), "-> %-8s [RELIC $%02X: %s]",
                         br->target_class_name, br->required_relic,
                         br->relic_in_stock ? "READY" : "MISSING");
            } else {
                snprintf(line, sizeof(line), "-> %-8s [L%u ALI:%u..%u]",
                         br->target_class_name, br->req_min_level,
                         br->req_min_ali, br->req_max_ali);
            }
            draw_snes_tile_text(fb, w, h, q4_x + 12, py, line,
                                br->eligible_now ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
            py += 13;
        }
    }
}

/* ==========================================================================
 * MAIN RENDER PIPELINE: Secondary Companion Window (640 x 480 RGBA)
 * ========================================================================== */
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

    /* Record diff events into ring buffer */
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

    /* Clear Entire Framebuffer to Dark Royal Blue */
    draw_snes_window_fill(fb, w, h, 0, 0, (int)w, (int)h);

    /* Top Navigation Bar: 3 Embossed SNES Menu Tabs */
    int tab_w = 140, tab_h = 22;
    int tab1_x = 8, tab2_x = 156, tab3_x = 304;

    /* Tab 1: Tactical Radar */
    bool t1_act = (state->active_page == OB_COMPANION_PAGE_TACTICAL);
    fill_rect(fb, w, h, tab1_x, 4, tab_w, tab_h, t1_act ? 0xFF182858U : 0xFF0E1428U);
    stroke_rect(fb, w, h, tab1_x, 4, tab_w, tab_h, t1_act ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_DARK);
    draw_snes_tile_text(fb, w, h, tab1_x + 10, 10, "1. TACTICAL RADAR", t1_act ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);

    /* Tab 2: Combat & Tarot */
    bool t2_act = (state->active_page == OB_COMPANION_PAGE_COMBAT_TAROT);
    fill_rect(fb, w, h, tab2_x, 4, tab_w, tab_h, t2_act ? 0xFF182858U : 0xFF0E1428U);
    stroke_rect(fb, w, h, tab2_x, 4, tab_w, tab_h, t2_act ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_DARK);
    draw_snes_tile_text(fb, w, h, tab2_x + 10, 10, "2. COMBAT/TAROT", t2_act ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);

    /* Tab 3: Campaign Guide */
    bool t3_act = (state->active_page == OB_COMPANION_PAGE_CAMPAIGN_GUIDE);
    fill_rect(fb, w, h, tab3_x, 4, tab_w, tab_h, t3_act ? 0xFF182858U : 0xFF0E1428U);
    stroke_rect(fb, w, h, tab3_x, 4, tab_w, tab_h, t3_act ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_DARK);
    draw_snes_tile_text(fb, w, h, tab3_x + 10, 10, "3. CAMPAIGN GUIDE", t3_act ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);

    /* Status Readout Top-Right */
    char hdr[64];
    snprintf(hdr, sizeof(hdr), "F%05u [POI:%s]",
             curr_frame->frame_counter, state->show_hidden_poi_radar ? "ON" : "OFF");
    draw_snes_tile_text(fb, w, h, (int)w - 144, 10, hdr, OB_SNES_PAL_CYAN);

    /* Dispatch to Active Page */
    switch (state->active_page) {
        case OB_COMPANION_PAGE_COMBAT_TAROT:
            render_page_combat_tarot(state, curr_frame, wram, rom, rom_size, fb, w, h);
            break;
        case OB_COMPANION_PAGE_CAMPAIGN_GUIDE:
            render_page_campaign_guide(state, curr_frame, wram, rom, rom_size, fb, w, h);
            break;
        case OB_COMPANION_PAGE_TACTICAL:
        default:
            render_page_tactical(state, curr_frame, wram, rom, rom_size, fb, w, h);
            break;
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
