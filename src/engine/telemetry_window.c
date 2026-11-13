#include "telemetry_window.h"
#include "ob_snes_ui_theme.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

/* Authentic Quest Ogre Battle Screen Backdrop with SNES Mode 1 Tapestry Lattice */
static void draw_snes_screen_backdrop(uint32_t *fb, uint32_t w, uint32_t h) {
    for (int y = 0; y < (int)h; ++y) {
        for (int x = 0; x < (int)w; ++x) {
            int lx = x & 7;
            int ly = y & 7;
            bool is_lattice = ((lx + ly == 4) || (lx - ly == 3) || (ly - lx == 3) || (lx + ly == 10));
            uint32_t col = is_lattice ? OB_COLOR_BACKDROP_LIGHT : OB_COLOR_BACKDROP_DARK;
            fb[(uint32_t)y * w + (uint32_t)x] = col;
        }
    }

    /* Screen Outer Gold Filigree Border */
    stroke_rect(fb, w, h, 2, 2, (int)w - 4, (int)h - 4, OB_COLOR_GOLD_DARK);
    stroke_rect(fb, w, h, 3, 3, (int)w - 6, (int)h - 6, OB_COLOR_GOLD_MID);
    stroke_rect(fb, w, h, 4, 4, (int)w - 8, (int)h - 8, OB_COLOR_GOLD_SHADOW);

    /* 4 Corner Gem Studs */
    fill_rect(fb, w, h, 2, 2, 5, 5, OB_COLOR_GOLD_HI);
    fill_rect(fb, w, h, (int)w - 7, 2, 5, 5, OB_COLOR_GOLD_HI);
    fill_rect(fb, w, h, 2, (int)h - 7, 5, 5, OB_COLOR_GOLD_HI);
    fill_rect(fb, w, h, (int)w - 7, (int)h - 7, 5, 5, OB_COLOR_GOLD_HI);
}

/* Authentic Quest Ogre Battle Royal Blue Window Fill with Scanline Dither */
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

/* 8x8 2BPP Tile Blitter with 4-Color Palette Mapping */
static void draw_snes_tile_2bpp(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y, const uint8_t tile[16],
    uint32_t col0, uint32_t col1, uint32_t col2, uint32_t col3,
    bool transparent_col0
) {
    uint32_t palette[4] = { col0, col1, col2, col3 };
    for (int r = 0; r < 8; ++r) {
        uint8_t bp0 = tile[r * 2];
        uint8_t bp1 = tile[r * 2 + 1];
        for (int c = 0; c < 8; ++c) {
            uint8_t bit = 7 - c;
            uint8_t idx = ((bp0 >> bit) & 1) | (((bp1 >> bit) & 1) << 1);
            if (idx == 0 && transparent_col0) {
                continue;
            }
            put_px(fb, w, h, x + c, y + r, palette[idx]);
        }
    }
}

/* Authentic 9-Slice Dialogue Box with Extracted ROM Tiles */
static void draw_snes_9slice_box(
    uint32_t *fb, uint32_t w, uint32_t h,
    int rx, int ry, int rw, int rh,
    const char *title
) {
    rx = (rx / 8) * 8;
    ry = (ry / 8) * 8;
    rw = (rw / 8) * 8;
    rh = (rh / 8) * 8;

    stroke_rect(fb, w, h, rx + 1, ry + 1, rw, rh, 0xFF04060CU);
    draw_snes_window_fill(fb, w, h, rx + 4, ry + 4, rw - 8, rh - 8);

    uint32_t col0 = 0;
    uint32_t col1 = 0xFF0A122AU;
    uint32_t col2 = OB_COLOR_GOLD_MID;
    uint32_t col3 = OB_COLOR_GOLD_HI;

    draw_snes_tile_2bpp(fb, w, h, rx, ry, kSnesTileCornerTL, col0, col1, col2, col3, true);
    draw_snes_tile_2bpp(fb, w, h, rx + rw - 8, ry, kSnesTileCornerTR, col0, col1, col2, col3, true);
    draw_snes_tile_2bpp(fb, w, h, rx, ry + rh - 8, kSnesTileCornerBL, col0, col1, col2, col3, true);
    draw_snes_tile_2bpp(fb, w, h, rx + rw - 8, ry + rh - 8, kSnesTileCornerBR, col0, col1, col2, col3, true);

    for (int x = rx + 8; x <= rx + rw - 16; x += 8) {
        draw_snes_tile_2bpp(fb, w, h, x, ry, kSnesTileRailTop, col0, col1, col2, col3, true);
        draw_snes_tile_2bpp(fb, w, h, x, ry + rh - 8, kSnesTileRailBottom, col0, col1, col2, col3, true);
    }

    for (int y = ry + 8; y <= ry + rh - 16; y += 8) {
        draw_snes_tile_2bpp(fb, w, h, rx, y, kSnesTileRailLeft, col0, col1, col2, col3, true);
        draw_snes_tile_2bpp(fb, w, h, rx + rw - 8, y, kSnesTileRailRight, col0, col1, col2, col3, true);
    }

    if (title && title[0] != '\0') {
        fill_rect(fb, w, h, rx + 8, ry + 4, rw - 16, 12, 0xFF24180CU);
        stroke_rect(fb, w, h, rx + 8, ry + 4, rw - 16, 12, OB_COLOR_GOLD_DARK);
        stroke_rect(fb, w, h, rx + 9, ry + 5, rw - 18, 10, OB_COLOR_GOLD_SHADOW);
        draw_snes_tile_2bpp(fb, w, h, rx + 10, ry + 6, kSnesTileGem, col0, 0xFF801018U, OB_COLOR_GOLD_MID, OB_COLOR_GOLD_HI, true);
    }
}

/* Palette Mapping for 8x8 Text */
static uint32_t get_snes_pal_color(ObSnesPalette pal, uint32_t *out_mid) {
    switch (pal) {
        case OB_SNES_PAL_GOLD:
            if (out_mid) *out_mid = 0xFFC89838U;
            return OB_COLOR_TEXT_GOLD;
        case OB_SNES_PAL_CRIMSON:
            if (out_mid) *out_mid = 0xFFA03030U;
            return OB_COLOR_TEXT_CRIMSON;
        case OB_SNES_PAL_EMERALD:
            if (out_mid) *out_mid = 0xFF38A850U;
            return OB_COLOR_TEXT_EMERALD;
        case OB_SNES_PAL_SKY:
            if (out_mid) *out_mid = 0xFF3898B8U;
            return OB_COLOR_TEXT_SKY;
        case OB_SNES_PAL_MUTED:
            if (out_mid) *out_mid = 0xFF606070U;
            return OB_COLOR_TEXT_MUTED;
        case OB_SNES_PAL_PURPLE:
            if (out_mid) *out_mid = 0xFF8848B0U;
            return OB_COLOR_TEXT_PURPLE;
        case OB_SNES_PAL_AMBER:
            if (out_mid) *out_mid = 0xFFB87020U;
            return OB_COLOR_TEXT_AMBER;
        case OB_SNES_PAL_IVORY:
        default:
            if (out_mid) *out_mid = 0xFFB0B0A0U;
            return OB_COLOR_TEXT_IVORY;
    }
}

/* Authentic SNES Special Glyphs */
static const uint8_t kSnesGlyphParenL[16] = {
    0x08, 0x18, 0x10, 0x30, 0x20, 0x60, 0x20, 0x60, 0x20, 0x60, 0x10, 0x30, 0x08, 0x18, 0x00, 0x00
};
static const uint8_t kSnesGlyphParenR[16] = {
    0x10, 0x18, 0x08, 0x0C, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x08, 0x0C, 0x10, 0x18, 0x00, 0x00
};
static const uint8_t kSnesGlyphBracketL[16] = {
    0x38, 0x78, 0x20, 0x60, 0x20, 0x60, 0x20, 0x60, 0x20, 0x60, 0x20, 0x60, 0x38, 0x78, 0x00, 0x00
};
static const uint8_t kSnesGlyphBracketR[16] = {
    0x1C, 0x1E, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x04, 0x06, 0x1C, 0x1E, 0x00, 0x00
};
static const uint8_t kSnesGlyphArrowR[16] = {
    0x00, 0x00, 0x20, 0x60, 0x30, 0x70, 0x38, 0x78, 0x30, 0x70, 0x20, 0x60, 0x00, 0x00, 0x00, 0x00
};
static const uint8_t kSnesGlyphArrowL[16] = {
    0x00, 0x00, 0x04, 0x06, 0x0C, 0x0E, 0x1C, 0x1E, 0x0C, 0x0E, 0x04, 0x06, 0x00, 0x00, 0x00, 0x00
};

static inline uint8_t snes_char_to_tile_idx(char ch, const uint8_t **out_custom_tile) {
    if (out_custom_tile) *out_custom_tile = NULL;
    if (ch >= '0' && ch <= '9') return (uint8_t)ch;
    if (ch >= 'A' && ch <= 'Z') return (uint8_t)ch;
    if (ch >= 'a' && ch <= 'z') return (uint8_t)(ch - 'a' + 'A');
    switch (ch) {
        case ' ': return 32;
        case '!': return 33;
        case '"': return 34;
        case '%': return 37;
        case '&': return 38;
        case '\'': return 16;
        case '+': return 43;
        case ',': return 44;
        case '-': return 45;
        case '.': return 46;
        case '/': return 47;
        case ':': return 58;
        case '=': return 61;
        case '?': return 63;
        case '(':
            if (out_custom_tile) *out_custom_tile = kSnesGlyphParenL;
            return 255;
        case ')':
            if (out_custom_tile) *out_custom_tile = kSnesGlyphParenR;
            return 255;
        case '[':
            if (out_custom_tile) *out_custom_tile = kSnesGlyphBracketL;
            return 255;
        case ']':
            if (out_custom_tile) *out_custom_tile = kSnesGlyphBracketR;
            return 255;
        case '>':
            if (out_custom_tile) *out_custom_tile = kSnesGlyphArrowR;
            return 255;
        case '<':
            if (out_custom_tile) *out_custom_tile = kSnesGlyphArrowL;
            return 255;
        default:
            return 32;
    }
}

/* Two-Pass Authentic SNES 8x8 Font Blitter with 1px Drop Shadow */
static void draw_snes_tile_text(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y, const char *str, ObSnesPalette pal
) {
    if (!str) return;
    uint32_t mid_col = 0;
    uint32_t fg_col = get_snes_pal_color(pal, &mid_col);
    int cx = x;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        const uint8_t *custom_glyph = NULL;
        uint8_t c = snes_char_to_tile_idx(str[i], &custom_glyph);
        if (c == 32 && !custom_glyph) {
            cx += 8;
            continue;
        }
        const uint8_t *glyph = custom_glyph ? custom_glyph : &kSnesFontRom2BPP[(uint32_t)c * 16];

        /* Pass 1: Drop Shadow */
        for (int r = 0; r < 8; ++r) {
            uint8_t bp0 = glyph[r * 2];
            uint8_t bp1 = glyph[r * 2 + 1];
            for (int col = 0; col < 8; ++col) {
                uint8_t bit = 7 - col;
                uint8_t color_idx = ((bp0 >> bit) & 1) | (((bp1 >> bit) & 1) << 1);
                if ((!custom_glyph && (color_idx == 2 || color_idx == 3)) ||
                    (custom_glyph && color_idx != 0)) {
                    put_px(fb, w, h, cx + col + 1, y + r + 1, OB_COLOR_TEXT_SHADOW);
                }
            }
        }

        /* Pass 2: Glyph Face & Bevel */
        for (int r = 0; r < 8; ++r) {
            uint8_t bp0 = glyph[r * 2];
            uint8_t bp1 = glyph[r * 2 + 1];
            for (int col = 0; col < 8; ++col) {
                uint8_t bit = 7 - col;
                uint8_t color_idx = ((bp0 >> bit) & 1) | (((bp1 >> bit) & 1) << 1);
                if (!custom_glyph) {
                    if (color_idx == 3) {
                        put_px(fb, w, h, cx + col, y + r, fg_col);
                    } else if (color_idx == 2) {
                        put_px(fb, w, h, cx + col, y + r, mid_col);
                    }
                } else {
                    if (color_idx & 2) {
                        put_px(fb, w, h, cx + col, y + r, fg_col);
                    } else if (color_idx & 1) {
                        put_px(fb, w, h, cx + col, y + r, mid_col);
                    }
                }
            }
        }
        cx += 8;
    }
}

/* Draw Special Icon from ROM Font Sheet */
static void draw_snes_icon_tile(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y, uint8_t icon_tile_idx,
    uint32_t fg_col, uint32_t mid_col
) {
    const uint8_t *glyph = &kSnesFontRom2BPP[(uint32_t)icon_tile_idx * 16];
    for (int r = 0; r < 8; ++r) {
        uint8_t bp0 = glyph[r * 2];
        uint8_t bp1 = glyph[r * 2 + 1];
        for (int col = 0; col < 8; ++col) {
            uint8_t bit = 7 - col;
            uint8_t color_idx = ((bp0 >> bit) & 1) | (((bp1 >> bit) & 1) << 1);
            if (color_idx == 2 || color_idx == 3) {
                put_px(fb, w, h, x + col + 1, y + r + 1, OB_COLOR_TEXT_SHADOW);
            }
        }
    }
    for (int r = 0; r < 8; ++r) {
        uint8_t bp0 = glyph[r * 2];
        uint8_t bp1 = glyph[r * 2 + 1];
        for (int col = 0; col < 8; ++col) {
            uint8_t bit = 7 - col;
            uint8_t color_idx = ((bp0 >> bit) & 1) | (((bp1 >> bit) & 1) << 1);
            if (color_idx == 3) {
                put_px(fb, w, h, x + col, y + r, fg_col);
            } else if (color_idx == 2) {
                put_px(fb, w, h, x + col, y + r, mid_col);
            }
        }
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
        fill_rect(fb, w, h, x + 1, y + 1, fw, 1, 0xFFFFFFFFU);
        for (int sx = x + 8; sx < x + 1 + fw; sx += 8) {
            fill_rect(fb, w, h, sx, y + 1, 1, bh - 2, OB_COLOR_TEXT_SHADOW);
        }
    }
}

/* ==========================================================================
 * SPECIALIZED AUTHENTIC VISUALIZERS (Minimap, Tarot, Zodiac)
 * ========================================================================== */

/* Authentic 2D Spatial Cartographic Minimap */
static void draw_snes_minimap(
    uint32_t *fb, uint32_t w, uint32_t h,
    int rx, int ry, int rw, int rh,
    const ObTelemetryFrame *curr_frame,
    bool show_hidden_poi
) {
    fill_rect(fb, w, h, rx, ry, rw, rh, 0xFF282218U);
    stroke_rect(fb, w, h, rx, ry, rw, rh, OB_COLOR_GOLD_MID);
    stroke_rect(fb, w, h, rx + 1, ry + 1, rw - 2, rh - 2, OB_COLOR_GOLD_SHADOW);

    /* River with gentle bends */
    for (int y = ry + 8; y < ry + rh - 8; ++y) {
        int offset = (int)(12.0f * ((y / 16) % 2 ? 1.0f : -0.5f));
        int rx_pos = rx + (rw / 2) + offset;
        put_px(fb, w, h, rx_pos, y, 0xFF183858U);
        put_px(fb, w, h, rx_pos + 1, y, 0xFF284878U);
    }

    /* Forest groves (moss green dither) */
    for (int fy = ry + 12; fy < ry + 40; fy += 2) {
        for (int fx = rx + 12; fx < rx + 44; fx += 2) {
            put_px(fb, w, h, fx, fy, 0xFF20381CU);
        }
    }
    for (int fy = ry + rh - 36; fy < ry + rh - 12; fy += 2) {
        for (int fx = rx + rw - 48; fx < rx + rw - 16; fx += 2) {
            put_px(fb, w, h, fx, fy, 0xFF20381CU);
        }
    }

    /* Mountain ridges (sepia peaks) */
    for (int mx = rx + 75; mx < rx + 105; mx += 3) {
        put_px(fb, w, h, mx, ry + 22, 0xFF4A3828U);
        put_px(fb, w, h, mx + 1, ry + 23, 0xFF584834U);
    }

    /* Compass Rose North Indicator */
    put_px(fb, w, h, rx + rw - 12, ry + 6, OB_COLOR_GOLD_HI);
    put_px(fb, w, h, rx + rw - 13, ry + 7, OB_COLOR_GOLD_MID);
    put_px(fb, w, h, rx + rw - 11, ry + 7, OB_COLOR_GOLD_MID);
    put_px(fb, w, h, rx + rw - 12, ry + 8, OB_COLOR_GOLD_SHADOW);

    /* Plot Cities & Keeps */
    for (uint8_t c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        const ObCityTelemetry *city = &curr_frame->cities[c];
        if (!city->exists) continue;
        int cx = rx + 6 + ((city->world_x & 0x07FF) * (rw - 14)) / 2048;
        int cy = ry + 6 + ((city->world_y & 0x07FF) * (rh - 14)) / 2048;
        bool is_lib = ((city->ownership_mask & 0x01) != 0);
        bool is_hidden = ((city->ownership_mask & 0x02) != 0);

        if (is_hidden && !show_hidden_poi) continue;

        if (is_hidden) {
            draw_snes_icon_tile(fb, w, h, cx - 4, cy - 4, 41, OB_COLOR_GOLD_HI, OB_COLOR_TEXT_PURPLE);
        } else if (is_lib) {
            fill_rect(fb, w, h, cx - 2, cy - 2, 5, 5, 0xFF204828U);
            fill_rect(fb, w, h, cx - 1, cy - 1, 3, 3, OB_COLOR_TEXT_EMERALD);
            stroke_rect(fb, w, h, cx - 2, cy - 2, 5, 5, OB_COLOR_TEXT_SHADOW);
        } else {
            fill_rect(fb, w, h, cx - 2, cy - 2, 5, 5, 0xFF581818U);
            fill_rect(fb, w, h, cx - 1, cy - 1, 3, 3, OB_COLOR_TEXT_CRIMSON);
            stroke_rect(fb, w, h, cx - 2, cy - 2, 5, 5, OB_COLOR_TEXT_SHADOW);
        }
    }

    /* Plot Squads & Trajectory Vectors */
    for (uint8_t s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        const ObMapEntityTelemetry *ent = &curr_frame->map_entities[s];
        if (!ent->is_active) continue;
        int sx = rx + 6 + ((ent->world_x & 0x07FF) * (rw - 14)) / 2048;
        int sy = ry + 6 + ((ent->world_y & 0x07FF) * (rh - 14)) / 2048;

        if (ent->target_x > 0 && ent->target_x != 0x7FFF) {
            int tx = rx + 6 + ((ent->target_x & 0x07FF) * (rw - 14)) / 2048;
            int ty = ry + 6 + ((ent->target_y & 0x07FF) * (rh - 14)) / 2048;
            draw_line(fb, w, h, sx, sy, tx, ty, ent->is_enemy ? 0xFFA03030U : 0xFF3898B8U);
        }

        if (ent->is_enemy) {
            fill_rect(fb, w, h, sx - 3, sy - 3, 7, 7, 0xFF601010U);
            fill_rect(fb, w, h, sx - 2, sy - 2, 5, 5, OB_COLOR_TEXT_CRIMSON);
            stroke_rect(fb, w, h, sx - 3, sy - 3, 7, 7, OB_COLOR_TEXT_SHADOW);
        } else {
            fill_rect(fb, w, h, sx - 3, sy - 3, 7, 7, 0xFF183858U);
            fill_rect(fb, w, h, sx - 2, sy - 2, 5, 5, OB_COLOR_TEXT_SKY);
            stroke_rect(fb, w, h, sx - 3, sy - 3, 7, 7, OB_COLOR_TEXT_SHADOW);
        }
    }
}

/* Authentic Miniature Tarot Card (32 x 42 px) */
static void draw_snes_mini_tarot(
    uint32_t *fb, uint32_t w, uint32_t h,
    int x, int y,
    const char *numeral,
    int motif_type,
    bool overlevel_risk
) {
    int cw = 32, ch = 42;
    fill_rect(fb, w, h, x + 1, y + 1, cw, ch, 0xFF060810U);
    fill_rect(fb, w, h, x, y, cw, ch, 0xFFE0D0A8U);
    stroke_rect(fb, w, h, x, y, cw, ch, OB_COLOR_GOLD_DARK);
    stroke_rect(fb, w, h, x + 1, y + 1, cw - 2, ch - 2, OB_COLOR_GOLD_MID);

    /* Roman numeral header centered */
    fill_rect(fb, w, h, x + 2, y + 2, cw - 4, 8, 0xFF302010U);
    int num_len = (int)strlen(numeral);
    int num_x = x + (cw - num_len * 8) / 2;
    draw_snes_tile_text(fb, w, h, num_x, y + 2, numeral, OB_SNES_PAL_GOLD);

    /* Card art frame (24 x 26 px) */
    int ax = x + 4, ay = y + 11, aw = cw - 8, ah = 26;
    fill_rect(fb, w, h, ax, ay, aw, ah, 0xFF141A28U);
    stroke_rect(fb, w, h, ax, ay, aw, ah, OB_COLOR_GOLD_SHADOW);

    if (motif_type == 0) {
        /* I. MAGICIAN: Wizard Robe + Flaming Staff */
        fill_rect(fb, w, h, ax + 10, ay + 3, 4, 5, 0xFFD8D8E0U);
        fill_rect(fb, w, h, ax + 8, ay + 8, 8, 14, 0xFF384878U);
        fill_rect(fb, w, h, ax + 17, ay + 2, 2, 20, OB_COLOR_GOLD_MID);
        fill_rect(fb, w, h, ax + 16, ay + 1, 4, 4, 0xFFF84820U);
        put_px(fb, w, h, ax + 17, ay + 2, 0xFFF8D040U);
    } else if (motif_type == 1) {
        /* VI. LOVERS: Winged Heart / Cherub */
        fill_rect(fb, w, h, ax + 3, ay + 8, 5, 4, 0xFFE0E8F8U);
        fill_rect(fb, w, h, ax + 16, ay + 8, 5, 4, 0xFFE0E8F8U);
        fill_rect(fb, w, h, ax + 8, ay + 7, 8, 7, 0xFFF83858U);
        fill_rect(fb, w, h, ax + 10, ay + 14, 4, 4, 0xFFF82848U);
        put_px(fb, w, h, ax + 11, ay + 18, 0xFFF82848U);
        fill_rect(fb, w, h, ax + 10, ay + 3, 4, 2, OB_COLOR_GOLD_HI);
    } else {
        /* VII. CHARIOT: War Chariot & Crest */
        fill_rect(fb, w, h, ax + 6, ay + 4, 12, 12, OB_COLOR_GOLD_MID);
        stroke_rect(fb, w, h, ax + 6, ay + 4, 12, 12, OB_COLOR_GOLD_HI);
        fill_rect(fb, w, h, ax + 9, ay + 7, 6, 6, 0xFFF84848U);
        fill_rect(fb, w, h, ax + 4, ay + 16, 4, 7, 0xFF584838U);
        fill_rect(fb, w, h, ax + 16, ay + 16, 4, 7, 0xFF584838U);
    }

    if (overlevel_risk) {
        fill_rect(fb, w, h, x + cw - 10, y + ch - 10, 9, 9, 0xFF881018U);
        stroke_rect(fb, w, h, x + cw - 10, y + ch - 10, 9, 9, OB_COLOR_TEXT_CRIMSON);
        put_px(fb, w, h, x + cw - 6, y + ch - 6, 0xFFFFFFFFU);
    }
}

/* Authentic 12 Zodiac Stones Jeweler's Tray (3 x 4 Grid) */
static void draw_snes_zodiac_tray(
    uint32_t *fb, uint32_t w, uint32_t h,
    int rx, int ry, uint16_t stones_mask
) {
    static const struct {
        const char *code;
        uint32_t gem_col;
        uint32_t facet_col;
    } kZodiacGems[12] = {
        { "ARI", 0xFFE02838U, 0xFFF88898U },
        { "TAU", 0xFFB848F8U, 0xFFE898F8U },
        { "GEM", 0xFF48C8F8U, 0xFFA0E8F8U },
        { "CAN", 0xFFF0F0F8U, 0xFFFFFFFFU },
        { "LEO", 0xFF38D868U, 0xFF88F8A8U },
        { "VIR", 0xFFF0E8D8U, 0xFFFFFFFFU },
        { "LIB", 0xFFF82858U, 0xFFF888A8U },
        { "SCO", 0xFF98F038U, 0xFFD0F888U },
        { "SAG", 0xFF2868F8U, 0xFF88B8F8U },
        { "CAP", 0xFFD8E8F8U, 0xFFFFFFFFU },
        { "AQU", 0xFFF8A828U, 0xFFF8D878U },
        { "PIS", 0xFF30C8C8U, 0xFF88E8E8U }
    };

    int tw = 280, th = 68;
    fill_rect(fb, w, h, rx, ry, tw, th, 0xFF140E0AU);
    stroke_rect(fb, w, h, rx, ry, tw, th, OB_COLOR_GOLD_MID);
    stroke_rect(fb, w, h, rx + 1, ry + 1, tw - 2, th - 2, OB_COLOR_GOLD_SHADOW);

    for (int s = 0; s < 12; ++s) {
        int col = s % 6;
        int row = s / 6;
        int sx = rx + 6 + col * 45;
        int sy = ry + 5 + row * 30;
        bool collected = ((stones_mask & (1U << s)) != 0);

        fill_rect(fb, w, h, sx, sy, 38, 20, collected ? 0xFF201610U : 0xFF0E0A08U);
        stroke_rect(fb, w, h, sx, sy, 38, 20, OB_COLOR_GOLD_DARK);
        stroke_rect(fb, w, h, sx + 1, sy + 1, 36, 18, collected ? OB_COLOR_GOLD_MID : OB_COLOR_GOLD_SHADOW);

        if (collected) {
            int gx = sx + 5, gy = sy + 3;
            fill_rect(fb, w, h, gx, gy, 12, 10, kZodiacGems[s].gem_col);
            stroke_rect(fb, w, h, gx, gy, 12, 10, OB_COLOR_TEXT_SHADOW);
            put_px(fb, w, h, gx + 2, gy + 2, kZodiacGems[s].facet_col);
            put_px(fb, w, h, gx + 3, gy + 2, 0xFFFFFFFFU);
            put_px(fb, w, h, gx + 2, gy + 3, 0xFFFFFFFFU);
        } else {
            fill_rect(fb, w, h, sx + 5, sy + 3, 12, 10, 0xFF080608U);
            stroke_rect(fb, w, h, sx + 5, sy + 3, 12, 10, 0xFF241C14U);
            put_px(fb, w, h, sx + 4, sy + 2, OB_COLOR_GOLD_SHADOW);
            put_px(fb, w, h, sx + 17, sy + 2, OB_COLOR_GOLD_SHADOW);
            put_px(fb, w, h, sx + 4, sy + 13, OB_COLOR_GOLD_SHADOW);
            put_px(fb, w, h, sx + 17, sy + 13, OB_COLOR_GOLD_SHADOW);
        }

        draw_snes_tile_text(fb, w, h, sx + 19, sy + 4, kZodiacGems[s].code,
                            collected ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);
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
    draw_snes_gauge_bar(fb, w, h, q1_x + 12, cy + 11, q1_w - 24, 10,
                        curr_frame->chaos_frame, 100,
                        (curr_frame->chaos_frame >= 65) ? OB_COLOR_TEXT_EMERALD :
                        (curr_frame->chaos_frame >= 35 ? OB_COLOR_TEXT_AMBER : OB_COLOR_TEXT_CRIMSON),
                        0xFF0C1428U);
    cy += 26;

    snprintf(line, sizeof(line), "ALIGNMENT: %s",
             (curr_frame->chaos_frame >= 65) ? "HIGH REPUTATION" :
             (curr_frame->chaos_frame >= 35 ? "NEUTRAL REPUTATION" : "LOW REPUTATION"));
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line,
                        (curr_frame->chaos_frame >= 65) ? OB_SNES_PAL_EMERALD :
                        (curr_frame->chaos_frame >= 35 ? OB_SNES_PAL_AMBER : OB_SNES_PAL_CRIMSON));
    cy += 12;

    snprintf(line, sizeof(line), "PATH: %s",
             (curr_frame->chaos_frame >= 65) ? "EMPEROR / WORLD ENDING" :
             (curr_frame->chaos_frame >= 35 ? "THE STAR / MOON ENDING" : "THE DEVIL / CHARIOT"));
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_GOLD);
    cy += 14;

    draw_snes_icon_tile(fb, w, h, q1_x + 12, cy, 39, OB_COLOR_GOLD_HI, OB_COLOR_GOLD_SHADOW);
    snprintf(line, sizeof(line), "TREASURY: %u GOTH", curr_frame->goth_treasury);
    draw_snes_tile_text(fb, w, h, q1_x + 24, cy, line, OB_SNES_PAL_GOLD);
    cy += 13;

    snprintf(line, sizeof(line), "NOON NET: %+d GOTH", curr_frame->projected_noon_net);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line,
                        (curr_frame->projected_noon_net >= 0) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
    cy += 13;

    draw_snes_icon_tile(fb, w, h, q1_x + 12, cy,
                        curr_frame->calendar.is_nighttime ? 42 : 40,
                        curr_frame->calendar.is_nighttime ? OB_COLOR_TEXT_AMBER : OB_COLOR_TEXT_GOLD,
                        OB_COLOR_GOLD_SHADOW);
    snprintf(line, sizeof(line), "CLOCK: %02u:%02u (%s)",
             curr_frame->calendar.hour, curr_frame->calendar.minute,
             curr_frame->calendar.is_nighttime ? "NIGHT - DARK" : "DAY - SOLAR");
    draw_snes_tile_text(fb, w, h, q1_x + 24, cy, line, OB_SNES_PAL_IVORY);
    cy += 13;

    snprintf(line, sizeof(line), "CALENDAR: YR %u MO %u DAY %u",
             curr_frame->calendar.year, curr_frame->calendar.month, curr_frame->calendar.day);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_MUTED);
    cy += 15;

    ObEndingAudit ending;
    ob_telemetry_audit_ending(curr_frame, &ending);
    snprintf(line, sizeof(line), "ENDING: %s", ending.ending_name);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_GOLD);
    cy += 12;
    snprintf(line, sizeof(line), "ALT:    %s", ending.nearest_alt_name);
    draw_snes_tile_text(fb, w, h, q1_x + 12, cy, line, OB_SNES_PAL_MUTED);

    /* QUADRANT 2: 2D Spatial Radar & Threat Vectors */
    draw_snes_9slice_box(fb, w, h, q2_x, q2_y, q2_w, q2_h, "2. SPATIAL RADAR");
    draw_snes_tile_text(fb, w, h, q2_x + 24, q2_y + 6, "2. SPATIAL RADAR", OB_SNES_PAL_GOLD);

    int mw = 152, mh = 108;
    int mx = q2_x + 12, my = q2_y + 24;
    draw_snes_minimap(fb, w, h, mx, my, mw, mh, curr_frame, state->show_hidden_poi_radar);

    int rx_info = mx + mw + 8;
    int ry_info = q2_y + 24;

    uint8_t ply_cnt = 0, enm_cnt = 0;
    for (uint8_t s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        if (curr_frame->map_entities[s].is_active) {
            if (curr_frame->map_entities[s].is_enemy) enm_cnt++; else ply_cnt++;
        }
    }
    draw_snes_tile_text(fb, w, h, rx_info, ry_info, "SQUADS:", OB_SNES_PAL_IVORY);
    ry_info += 12;
    snprintf(line, sizeof(line), "%uP / %uE", ply_cnt, enm_cnt);
    draw_snes_tile_text(fb, w, h, rx_info, ry_info, line, OB_SNES_PAL_GOLD);
    ry_info += 14;

    draw_snes_tile_text(fb, w, h, rx_info, ry_info, "POI RADAR:", OB_SNES_PAL_MUTED);
    ry_info += 12;
    snprintf(line, sizeof(line), "[%s]", state->show_hidden_poi_radar ? "ACTIVE" : "OFF");
    draw_snes_tile_text(fb, w, h, rx_info, ry_info, line,
                        state->show_hidden_poi_radar ? OB_SNES_PAL_SKY : OB_SNES_PAL_MUTED);
    ry_info += 16;

    draw_snes_tile_text(fb, w, h, rx_info, ry_info, "TERRAIN:", OB_SNES_PAL_MUTED);
    ry_info += 12;
    draw_snes_tile_text(fb, w, h, rx_info, ry_info, "PLAINS", OB_SNES_PAL_EMERALD);

    ObRecaptureThreat threats[4];
    size_t n_threats = ob_telemetry_detect_recapture_threats(curr_frame, threats, 4);
    int th_y = q2_y + 138;
    if (n_threats > 0) {
        fill_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 30, 0xFF401018U);
        stroke_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 30, OB_COLOR_TEXT_CRIMSON);
        stroke_rect(fb, w, h, q2_x + 9, th_y + 1, q2_w - 18, 28, 0xFF882028U);
        draw_snes_tile_text(fb, w, h, q2_x + 14, th_y + 4, "! -5 CF RECAPTURE RISK !", OB_SNES_PAL_CRIMSON);
        snprintf(line, sizeof(line), "ENM #%02u -> %s (ETA %dt)",
                 threats[0].enemy_slot, threats[0].is_temple ? "TEMPLE" : "CITY", threats[0].eta_ticks);
        draw_snes_tile_text(fb, w, h, q2_x + 14, th_y + 16, line, OB_SNES_PAL_AMBER);
    } else {
        fill_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 30, 0xFF101C28U);
        stroke_rect(fb, w, h, q2_x + 8, th_y, q2_w - 16, 30, OB_COLOR_GOLD_MID);
        stroke_rect(fb, w, h, q2_x + 9, th_y + 1, q2_w - 18, 28, OB_COLOR_GOLD_SHADOW);
        draw_snes_tile_text(fb, w, h, q2_x + 14, th_y + 6, "STAGE CITIES SECURE", OB_SNES_PAL_EMERALD);
        draw_snes_tile_text(fb, w, h, q2_x + 14, th_y + 17, "NO RECAPTURE THREATS", OB_SNES_PAL_MUTED);
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

    ObHiddenPoISummary poi;
    ob_telemetry_audit_hidden_poi(curr_frame, &poi);
    snprintf(line, sizeof(line), "POI: %u HIDDEN CITIES, %u TEMPLES",
             poi.unrevealed_cities_count, poi.unrevealed_temples_count);
    draw_snes_tile_text(fb, w, h, q3_x + 12, ly, line, OB_SNES_PAL_MUTED);

    /* QUADRANT 4: Squad Mobility & Intercepts */
    draw_snes_9slice_box(fb, w, h, q4_x, q4_y, q4_w, q4_h, "4. SQUAD MOBILITY");
    draw_snes_tile_text(fb, w, h, q4_x + 24, q4_y + 6, "4. SQUAD MOBILITY", OB_SNES_PAL_GOLD);

    int my_pos = q4_y + 24;
    ObSquadMobilityAnalysis mob;
    ob_telemetry_analyze_squad_mobility(curr_frame, state->selected_squad_id, &mob);

    snprintf(line, sizeof(line), "SQ #%02u: %s", state->selected_squad_id, mob.move_type_name);
    draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, line, OB_SNES_PAL_GOLD);
    my_pos += 14;

    snprintf(line, sizeof(line), "FLYERS: %u (NEED +%u -> SKY)", mob.flyers_count, mob.flyers_needed_for_sky);
    draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, line,
                        (mob.flyers_needed_for_sky == 0) ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_SKY);
    my_pos += 14;

    snprintf(line, sizeof(line), "TIME BUFF: %s",
             mob.is_day_favored ? "DAY / SOLAR (+STR)" : (mob.is_night_favored ? "NIGHT / LUNAR" : "BALANCED"));
    draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, line, OB_SNES_PAL_IVORY);
    my_pos += 16;

    if (mob.flyers_needed_for_sky > 0) {
        snprintf(line, sizeof(line), "UPGRADE: +%u FLYERS -> SKY", mob.flyers_needed_for_sky);
        draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, line, OB_SNES_PAL_SKY);
    } else {
        draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, "UPGRADE: FULL SKY SQUAD!", OB_SNES_PAL_EMERALD);
    }
    my_pos += 16;

    draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, "LIVE BIT-DIFF EVENT STREAM:", OB_SNES_PAL_MUTED);
    my_pos += 12;
    if (state->recent_diff_count > 0) {
        const ObTelemetryDiffEvent *ev = &state->recent_diffs[state->recent_diff_count - 1];
        snprintf(line, sizeof(line), "$7E:%04X [BIT %04u] %u->%u",
                 ev->wram_address, ev->bit_index, ev->old_value, ev->new_value);
        draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, line, OB_SNES_PAL_SKY);
    } else {
        draw_snes_tile_text(fb, w, h, q4_x + 12, my_pos, "NO STATE TRANSITIONS OBSERVED", OB_SNES_PAL_MUTED);
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

    snprintf(line, sizeof(line), "HAND: %zu / 14 CARDS [LORD LV%u]",
             n_cards, curr_frame->units[0].level);
    draw_snes_tile_text(fb, w, h, q1_x + 12, ty, line, OB_SNES_PAL_GOLD);
    ty += 16;

    static const char *kCardNumerals[3] = { "I", "VI", "VII" };
    static const char *kCardEffects[3] = {
        "FIRE DAMAGE TO ALL FOES",
        "CHARM FOES / +2 CF BONUS",
        "PHYSICAL RANGED STRIKE"
    };

    for (size_t i = 0; i < n_cards && i < 3; ++i) {
        const ObTarotAudit *a = &audits[i];
        int card_y = ty + (int)i * 50;

        /* Miniature Card on Left (32 x 42 px) */
        draw_snes_mini_tarot(fb, w, h, q1_x + 12, card_y, kCardNumerals[i % 3], (int)i, a->leader_overlevel_risk);

        /* Detailed Text on Right (x = q1_x + 52) */
        int tx = q1_x + 52;
        snprintf(line, sizeof(line), "%s. %s", kCardNumerals[i % 3], a->card_name);
        draw_snes_tile_text(fb, w, h, tx, card_y + 2, line, OB_SNES_PAL_GOLD);

        snprintf(line, sizeof(line), "EFF: %s", kCardEffects[i % 3]);
        draw_snes_tile_text(fb, w, h, tx, card_y + 14, line, OB_SNES_PAL_IVORY);

        if (a->leader_overlevel_risk) {
            draw_snes_tile_text(fb, w, h, tx, card_y + 26, "! OVERLEVEL TRAP: -ALI !", OB_SNES_PAL_CRIMSON);
        } else {
            draw_snes_tile_text(fb, w, h, tx, card_y + 26, "DRAW SAFE (+MORALE BONUS)", OB_SNES_PAL_EMERALD);
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

    draw_snes_icon_tile(fb, w, h, q2_x + 12, cy, 41, OB_COLOR_GOLD_HI, OB_COLOR_GOLD_SHADOW);
    snprintf(line, sizeof(line), "STATUS: %s", cmb->in_combat ? "ACTIVE CLASH" : "BATTLE STANDBY");
    draw_snes_tile_text(fb, w, h, q2_x + 24, cy, line,
                        cmb->in_combat ? OB_SNES_PAL_CRIMSON : OB_SNES_PAL_MUTED);
    cy += 16;

    snprintf(line, sizeof(line), "PLY: %u DMG  VS  ENM: %u DMG",
             cmb->player_clash_damage, cmb->enemy_clash_damage);
    draw_snes_tile_text(fb, w, h, q2_x + 12, cy, line, OB_SNES_PAL_IVORY);
    cy += 14;

    int total_dmg = (int)cmb->player_clash_damage + (int)cmb->enemy_clash_damage;
    int ply_ratio = (total_dmg > 0) ? ((int)cmb->player_clash_damage * 100 / total_dmg) : 50;
    draw_snes_gauge_bar(fb, w, h, q2_x + 12, cy, q2_w - 24, 12,
                        ply_ratio, 100, OB_COLOR_TEXT_EMERALD, OB_COLOR_TEXT_CRIMSON);
    cy += 20;

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

    int my_c = q3_y + 24;
    draw_snes_tile_text(fb, w, h, q3_x + 12, my_c, "KILL DRIFT FORECAST:", OB_SNES_PAL_IVORY);
    my_c += 14;

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
        draw_snes_tile_text(fb, w, h, q3_x + 12, my_c, line, OB_SNES_PAL_IVORY);
        my_c += 11;
        snprintf(line, sizeof(line), " vs L3: %+dA | vs UND: %+dA",
                 f_low.predicted_ali_delta, f_high.predicted_ali_delta);
        draw_snes_tile_text(fb, w, h, q3_x + 12, my_c, line,
                            f_low.overlevel_penalty ? OB_SNES_PAL_AMBER : OB_SNES_PAL_EMERALD);
        my_c += 13;
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
    draw_snes_tile_text(fb, w, h, q4_x + 12, ny, line,
                        neutral.persuade_ready ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_MUTED);
    ny += 14;

    snprintf(line, sizeof(line), "PERSUADE: %s", neutral.persuade_ready ? "READY (CHANCE HIGH)" : "NO RECRUITER");
    draw_snes_tile_text(fb, w, h, q4_x + 12, ny, line,
                        neutral.persuade_ready ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
    ny += 16;

    if (neutral.is_undead_ali_farm) {
        draw_snes_icon_tile(fb, w, h, q4_x + 12, ny, 41, OB_COLOR_TEXT_SKY, OB_COLOR_GOLD_SHADOW);
        draw_snes_tile_text(fb, w, h, q4_x + 24, ny, "HOLY FARM: PERSUADE UNDEAD!", OB_SNES_PAL_SKY);
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

    /* 2-Column Zenobian Hero Roster */
    for (size_t i = 0; i < n_heroes && i < 12; ++i) {
        const ObHeroRecruitmentAudit *ha = &heroes[i];
        int col = (int)(i / 6);
        int row = (int)(i % 6);
        int hx = q1_x + 10 + col * 144;
        int r_y = hy + row * 26;

        draw_snes_icon_tile(fb, w, h, hx, r_y, 39,
                            ha->is_recruited ? OB_COLOR_TEXT_EMERALD :
                            (ha->prereq_cf_met && ha->prereq_ali_met ? OB_COLOR_GOLD_HI : OB_COLOR_TEXT_MUTED),
                            OB_COLOR_GOLD_SHADOW);

        snprintf(line, sizeof(line), "%-7.7s", ha->hero_name);
        draw_snes_tile_text(fb, w, h, hx + 12, r_y, line,
                            ha->is_recruited ? OB_SNES_PAL_EMERALD :
                            (ha->prereq_cf_met && ha->prereq_ali_met ? OB_SNES_PAL_GOLD : OB_SNES_PAL_IVORY));

        const char *st_code = ha->is_recruited ? "[JOINED]" :
                             (ha->prereq_cf_met && ha->prereq_ali_met ? "[READY]" : "[PREREQ]");
        draw_snes_tile_text(fb, w, h, hx + 12, r_y + 11, st_code,
                            ha->is_recruited ? OB_SNES_PAL_EMERALD :
                            (ha->prereq_cf_met && ha->prereq_ali_met ? OB_SNES_PAL_AMBER : OB_SNES_PAL_MUTED));
    }

    /* QUADRANT 2: 12 Zodiac Stones Tracker */
    draw_snes_9slice_box(fb, w, h, q2_x, q2_y, q2_w, q2_h, "2. 12 ZODIAC STONES");
    draw_snes_tile_text(fb, w, h, q2_x + 24, q2_y + 6, "2. 12 ZODIAC STONES", OB_SNES_PAL_GOLD);

    int zy = q2_y + 24;
    ObZodiacQuestStatus z;
    ob_telemetry_track_zodiac_stones(curr_frame, &z);

    snprintf(line, sizeof(line), "STONES: %u / 12 COLLECTED", z.stones_collected_count);
    draw_snes_tile_text(fb, w, h, q2_x + 12, zy, line, OB_SNES_PAL_GOLD);
    zy += 14;

    draw_snes_zodiac_tray(fb, w, h, q2_x + 12, zy, z.stones_mask);
    zy += 74;

    snprintf(line, sizeof(line), "QUICKSILVER: %s", z.quicksilver_in_hand ? "IN HAND" : "MISSING");
    draw_snes_tile_text(fb, w, h, q2_x + 12, zy, line,
                        z.quicksilver_in_hand ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_MUTED);
    zy += 13;

    snprintf(line, sizeof(line), "TABLET OF YARU: %s", z.tablet_of_yaru_in_hand ? "IN HAND" : "PENDING");
    draw_snes_tile_text(fb, w, h, q2_x + 12, zy, line,
                        z.tablet_of_yaru_in_hand ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_MUTED);
    zy += 13;

    snprintf(line, sizeof(line), "BRUNHILD QUEST: %s",
             (z.quicksilver_in_hand && z.tablet_of_yaru_in_hand && z.stones_collected_count == 12)
             ? "READY!" : "PREREQS PENDING");
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
    draw_snes_tile_text(fb, w, h, q3_x + 12, wy, line, OB_SNES_PAL_SKY);

    /* QUADRANT 4: Promotion Tree Inspector */
    draw_snes_9slice_box(fb, w, h, q4_x, q4_y, q4_w, q4_h, "4. PROMOTION TREE");
    draw_snes_tile_text(fb, w, h, q4_x + 24, q4_y + 6, "4. PROMOTION TREE", OB_SNES_PAL_GOLD);

    int py = q4_y + 24;
    const ObUnitTelemetry *inspected = &curr_frame->units[state->selected_unit_slot % OB_MAX_ROSTER_UNITS];
    if (inspected->is_populated) {
        char cname[16];
        ob_telemetry_get_class_name(rom, rom_size, inspected->class_id, cname, sizeof(cname));
        snprintf(line, sizeof(line), "UNIT #%02u: %s (LV%u A%u C%u)",
                 inspected->slot_index, cname, inspected->level, inspected->ali, inspected->cha);
        draw_snes_tile_text(fb, w, h, q4_x + 12, py, line, OB_SNES_PAL_GOLD);
        py += 14;

        draw_snes_tile_text(fb, w, h, q4_x + 12, py, "PROMOTION BRANCHES:", OB_SNES_PAL_IVORY);
        py += 13;

        ObPromotionCheck branches[4];
        size_t n_br = ob_telemetry_eval_promotions(inspected, wram, rom, rom_size, branches, 4);
        if (n_br > 0) {
            for (size_t b = 0; b < n_br && b < 3; ++b) {
                const ObPromotionCheck *br = &branches[b];
                if (br->required_relic != 0) {
                    snprintf(line, sizeof(line), "-> %-8s [RELIC $%02X]", br->target_class_name, br->required_relic);
                    draw_snes_tile_text(fb, w, h, q4_x + 12, py, line, OB_SNES_PAL_SKY);
                    py += 11;
                    snprintf(line, sizeof(line), "   STATUS: %s", br->relic_in_stock ? "RELIC READY" : "RELIC MISSING");
                    draw_snes_tile_text(fb, w, h, q4_x + 12, py, line,
                                        br->relic_in_stock ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
                } else {
                    snprintf(line, sizeof(line), "-> %-8s [L%u ALI:%u..%u]",
                             br->target_class_name, br->req_min_level,
                             br->req_min_ali, br->req_max_ali);
                    draw_snes_tile_text(fb, w, h, q4_x + 12, py, line,
                                        br->eligible_now ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_AMBER);
                    py += 11;
                    snprintf(line, sizeof(line), "   STATUS: %s",
                             br->eligible_now ? "READY TO PROMOTE!" : "PREREQUISITES PENDING");
                    draw_snes_tile_text(fb, w, h, q4_x + 12, py, line,
                                        br->eligible_now ? OB_SNES_PAL_EMERALD : OB_SNES_PAL_MUTED);
                }
                py += 14;
            }
        } else {
            draw_snes_tile_text(fb, w, h, q4_x + 12, py, "CLASS: FINAL / SPECIAL FORM", OB_SNES_PAL_AMBER);
            py += 14;
            draw_snes_tile_text(fb, w, h, q4_x + 12, py, "NO HIGHER BRANCHES IN ROM", OB_SNES_PAL_MUTED);
            py += 14;
            draw_snes_tile_text(fb, w, h, q4_x + 12, py, "NIGHT: TRANSFORMS TO WEREWOLF", OB_SNES_PAL_SKY);
            py += 14;
            draw_snes_tile_text(fb, w, h, q4_x + 12, py, "BATTLE: 2X SLASH / 1X HOWL", OB_SNES_PAL_IVORY);
            py += 14;
            draw_snes_tile_text(fb, w, h, q4_x + 12, py, "TIP: CYCLE UNIT SLOT TO VIEW", OB_SNES_PAL_GOLD);
            draw_snes_tile_text(fb, w, h, q4_x + 12, py + 12, "FIGHTER/AMAZON PROMOTIONS", OB_SNES_PAL_GOLD);
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

    draw_snes_screen_backdrop(fb, w, h);

    int tab_w = 148, tab_h = 22;
    int tab1_x = 10, tab2_x = 166, tab3_x = 322;

    /* Tab 1: Tactical Radar */
    bool t1_act = (state->active_page == OB_COMPANION_PAGE_TACTICAL);
    fill_rect(fb, w, h, tab1_x, 5, tab_w, tab_h, t1_act ? 0xFF302010U : 0xFF101420U);
    stroke_rect(fb, w, h, tab1_x, 5, tab_w, tab_h, t1_act ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_DARK);
    stroke_rect(fb, w, h, tab1_x + 1, 6, tab_w - 2, tab_h - 2, t1_act ? OB_COLOR_GOLD_MID : 0xFF1C2434U);
    if (t1_act) {
        draw_snes_tile_2bpp(fb, w, h, tab1_x + 6, 8, kSnesTileGem, 0, 0xFF881018U, OB_COLOR_GOLD_MID, OB_COLOR_GOLD_HI, true);
    }
    draw_snes_tile_text(fb, w, h, tab1_x + (t1_act ? 18 : 10), 10, "1. TACTICAL RADAR",
                        t1_act ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);

    /* Tab 2: Combat & Tarot */
    bool t2_act = (state->active_page == OB_COMPANION_PAGE_COMBAT_TAROT);
    fill_rect(fb, w, h, tab2_x, 5, tab_w, tab_h, t2_act ? 0xFF302010U : 0xFF101420U);
    stroke_rect(fb, w, h, tab2_x, 5, tab_w, tab_h, t2_act ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_DARK);
    stroke_rect(fb, w, h, tab2_x + 1, 6, tab_w - 2, tab_h - 2, t2_act ? OB_COLOR_GOLD_MID : 0xFF1C2434U);
    if (t2_act) {
        draw_snes_tile_2bpp(fb, w, h, tab2_x + 6, 8, kSnesTileGem, 0, 0xFF881018U, OB_COLOR_GOLD_MID, OB_COLOR_GOLD_HI, true);
    }
    draw_snes_tile_text(fb, w, h, tab2_x + (t2_act ? 18 : 10), 10, "2. COMBAT/TAROT",
                        t2_act ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);

    /* Tab 3: Campaign Guide */
    bool t3_act = (state->active_page == OB_COMPANION_PAGE_CAMPAIGN_GUIDE);
    fill_rect(fb, w, h, tab3_x, 5, tab_w, tab_h, t3_act ? 0xFF302010U : 0xFF101420U);
    stroke_rect(fb, w, h, tab3_x, 5, tab_w, tab_h, t3_act ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_DARK);
    stroke_rect(fb, w, h, tab3_x + 1, 6, tab_w - 2, tab_h - 2, t3_act ? OB_COLOR_GOLD_MID : 0xFF1C2434U);
    if (t3_act) {
        draw_snes_tile_2bpp(fb, w, h, tab3_x + 6, 8, kSnesTileGem, 0, 0xFF881018U, OB_COLOR_GOLD_MID, OB_COLOR_GOLD_HI, true);
    }
    draw_snes_tile_text(fb, w, h, tab3_x + (t3_act ? 18 : 10), 10, "3. CAMPAIGN GUIDE",
                        t3_act ? OB_SNES_PAL_GOLD : OB_SNES_PAL_MUTED);

    /* Status Plaque Top-Right */
    int pl_x = (int)w - 156, pl_y = 5, pl_w = 146, pl_h = 22;
    fill_rect(fb, w, h, pl_x, pl_y, pl_w, pl_h, 0xFF181824U);
    stroke_rect(fb, w, h, pl_x, pl_y, pl_w, pl_h, OB_COLOR_GOLD_MID);
    stroke_rect(fb, w, h, pl_x + 1, pl_y + 1, pl_w - 2, pl_h - 2, OB_COLOR_GOLD_SHADOW);

    char hdr[64];
    snprintf(hdr, sizeof(hdr), "F%05u [POI:%s]",
             curr_frame->frame_counter, state->show_hidden_poi_radar ? "ON" : "OFF");
    draw_snes_tile_text(fb, w, h, pl_x + 10, pl_y + 6, hdr, OB_SNES_PAL_SKY);

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
