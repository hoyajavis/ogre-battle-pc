#include "snes_ui_rasterizer.h"
#include <stdio.h>
#include <string.h>

void ob_snes_canvas_init(ObSnesCanvas *canvas, uint32_t *pixels, int width, int height) {
    if (!canvas) {
        return;
    }
    canvas->pixels = pixels;
    canvas->width = width;
    canvas->height = height;
    canvas->stride = width;
}

uint32_t ob_snes_palette_color(ObSnesPaletteId pal) {
    switch (pal) {
        case OB_PAL_IVORY:   return OB_COLOR_TEXT_IVORY;
        case OB_PAL_GOLD:    return OB_COLOR_TEXT_GOLD;
        case OB_PAL_CRIMSON: return OB_COLOR_TEXT_CRIMSON;
        case OB_PAL_EMERALD: return OB_COLOR_TEXT_EMERALD;
        case OB_PAL_CYAN:    return OB_COLOR_TEXT_CYAN;
        case OB_PAL_AMBER:   return OB_COLOR_TEXT_AMBER;
        case OB_PAL_MUTED:   return OB_COLOR_TEXT_MUTED;
        default:             return OB_COLOR_TEXT_IVORY;
    }
}

static inline void put_pixel(ObSnesCanvas *canvas, int x, int y, uint32_t rgba) {
    if (!canvas || !canvas->pixels) {
        return;
    }
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        canvas->pixels[y * canvas->stride + x] = rgba;
    }
}

void draw_snes_rect_fill(ObSnesCanvas *canvas, int x, int y, int w, int h, uint32_t rgba) {
    if (!canvas || !canvas->pixels || w <= 0 || h <= 0) {
        return;
    }
    int x0 = (x < 0) ? 0 : x;
    int y0 = (y < 0) ? 0 : y;
    int x1 = (x + w > canvas->width) ? canvas->width : (x + w);
    int y1 = (y + h > canvas->height) ? canvas->height : (y + h);
    for (int py = y0; py < y1; ++py) {
        uint32_t *row = &canvas->pixels[py * canvas->stride];
        for (int px = x0; px < x1; ++px) {
            row[px] = rgba;
        }
    }
}

void draw_snes_rect_outline(ObSnesCanvas *canvas, int x, int y, int w, int h, uint32_t rgba) {
    if (w <= 0 || h <= 0) {
        return;
    }
    draw_snes_rect_fill(canvas, x, y, w, 1, rgba);
    draw_snes_rect_fill(canvas, x, y + h - 1, w, 1, rgba);
    draw_snes_rect_fill(canvas, x, y, 1, h, rgba);
    draw_snes_rect_fill(canvas, x + w - 1, y, 1, h, rgba);
}

/* Authentic Quest Royal Blue vertical gradient stepped in 15-bit BGR555 space */
void draw_snes_window_fill(ObSnesCanvas *canvas, int x, int y, int w, int h) {
    if (!canvas || !canvas->pixels || w <= 0 || h <= 0) {
        return;
    }
    for (int ry = 0; ry < h; ++ry) {
        int py = y + ry;
        if (py < 0 || py >= canvas->height) {
            continue;
        }
        /* Interpolate from (#18, #28, #68) at top to (#08, #08, #30) at bottom, snapped to BGR555 8-steps */
        int num = ry;
        int den = (h > 1) ? (h - 1) : 1;
        uint32_t r = (uint32_t)(0x18 - (0x10 * num) / den) & 0xF8u;
        uint32_t g = (uint32_t)(0x28 - (0x20 * num) / den) & 0xF8u;
        uint32_t b = (uint32_t)(0x68 - (0x38 * num) / den) & 0xF8u;
        /* Subtle scanline dither on odd rows */
        if ((ry & 1) != 0 && b >= 0x10u) {
            b = (b - 0x08u) & 0xF8u;
        }
        uint32_t color = OB_BGR555_RGBA(r, g, b);
        for (int rx = 0; rx < w; ++rx) {
            put_pixel(canvas, x + rx, py, color);
        }
    }
}

/* 8x8 Ornate Gold Corner Tile (2BPP/4BPP index pattern:
 * 0 = Inner Bevel (#080810), 1 = Shadow Bronze (#785018),
 * 2 = Mid Brass (#C89838), 3 = Highlight Gold (#F8D870)) */
static const uint8_t k_corner_tl[8][8] = {
    { 0, 1, 2, 3, 3, 2, 1, 2 },
    { 1, 2, 3, 2, 2, 1, 3, 3 },
    { 2, 3, 2, 1, 1, 2, 2, 1 },
    { 3, 2, 1, 3, 2, 1, 0, 0 },
    { 3, 2, 1, 2, 1, 0, 0, 0 },
    { 2, 1, 2, 1, 0, 0, 0, 0 },
    { 1, 3, 2, 0, 0, 0, 0, 0 },
    { 2, 3, 1, 0, 0, 0, 0, 0 }
};

static uint32_t border_index_to_rgba(uint8_t idx) {
    switch (idx) {
        case 3:  return OB_COLOR_GOLD_HI;
        case 2:  return OB_COLOR_GOLD_MID;
        case 1:  return OB_COLOR_GOLD_SHADOW;
        default: return OB_COLOR_WINDOW_INNER_BEVEL;
    }
}

void draw_snes_9slice_box(ObSnesCanvas *canvas, int x, int y, int w, int h, bool fill_backdrop) {
    if (!canvas || w < 16 || h < 16) {
        return;
    }
    if (fill_backdrop) {
        draw_snes_window_fill(canvas, x + 4, y + 4, w - 8, h - 8);
    }

    /* Top and Bottom Horizontal Rails (4px thick beveled gold rail) */
    for (int px = x + 8; px < x + w - 8; ++px) {
        /* Top rail */
        put_pixel(canvas, px, y + 0, OB_COLOR_GOLD_DARK);
        put_pixel(canvas, px, y + 1, OB_COLOR_GOLD_HI);
        put_pixel(canvas, px, y + 2, OB_COLOR_GOLD_MID);
        put_pixel(canvas, px, y + 3, OB_COLOR_GOLD_SHADOW);
        put_pixel(canvas, px, y + 4, OB_COLOR_WINDOW_INNER_BEVEL);

        /* Bottom rail */
        put_pixel(canvas, px, y + h - 5, OB_COLOR_WINDOW_INNER_BEVEL);
        put_pixel(canvas, px, y + h - 4, OB_COLOR_GOLD_SHADOW);
        put_pixel(canvas, px, y + h - 3, OB_COLOR_GOLD_HI);
        put_pixel(canvas, px, y + h - 2, OB_COLOR_GOLD_MID);
        put_pixel(canvas, px, y + h - 1, OB_COLOR_GOLD_DARK);
    }

    /* Left and Right Vertical Rails */
    for (int py = y + 8; py < y + h - 8; ++py) {
        /* Left rail */
        put_pixel(canvas, x + 0, py, OB_COLOR_GOLD_DARK);
        put_pixel(canvas, x + 1, py, OB_COLOR_GOLD_HI);
        put_pixel(canvas, x + 2, py, OB_COLOR_GOLD_MID);
        put_pixel(canvas, x + 3, py, OB_COLOR_GOLD_SHADOW);
        put_pixel(canvas, x + 4, py, OB_COLOR_WINDOW_INNER_BEVEL);

        /* Right rail */
        put_pixel(canvas, x + w - 5, py, OB_COLOR_WINDOW_INNER_BEVEL);
        put_pixel(canvas, x + w - 4, py, OB_COLOR_GOLD_SHADOW);
        put_pixel(canvas, x + w - 3, py, OB_COLOR_GOLD_HI);
        put_pixel(canvas, x + w - 2, py, OB_COLOR_GOLD_MID);
        put_pixel(canvas, x + w - 1, py, OB_COLOR_GOLD_DARK);
    }

    /* 4 Ornate 8x8 Corner Tiles (Mirrored symmetrically) */
    for (int cy = 0; cy < 8; ++cy) {
        for (int cx = 0; cx < 8; ++cx) {
            uint8_t idx = k_corner_tl[cy][cx];
            if (idx == 0 && fill_backdrop && cx >= 4 && cy >= 4) {
                continue;
            }
            uint32_t c = border_index_to_rgba(idx);
            put_pixel(canvas, x + cx, y + cy, c);                         /* TL */
            put_pixel(canvas, x + w - 1 - cx, y + cy, c);                 /* TR */
            put_pixel(canvas, x + cx, y + h - 1 - cy, c);                 /* BL */
            put_pixel(canvas, x + w - 1 - cx, y + h - 1 - cy, c);         /* BR */
        }
    }
}

void draw_snes_header_plate(
    ObSnesCanvas *canvas,
    int x,
    int y,
    int w,
    const char *title,
    ObSnesPaletteId pal
) {
    draw_snes_rect_fill(canvas, x, y, w, 12, OB_COLOR_HEADER_FILL);
    draw_snes_rect_outline(canvas, x, y, w, 12, OB_COLOR_GOLD_SHADOW);
    draw_snes_icon(canvas, x + 3, y + 2, OB_ICON_ARROW_RIGHT, OB_PAL_GOLD);
    draw_snes_compact_text(canvas, x + 13, y + 2, title, pal);
}

/* ============================================================================
 * 5x7 Pixel Glyph Table (Used by both 8x8 Tile Font and 6x8 Compact Wing Font)
 * Each glyph is 7 rows of 5 bits (MSB = left pixel: 0x10..0x01)
 * ============================================================================ */
static void get_glyph_5x7(char c, uint8_t out_rows[7]) {
    memset(out_rows, 0, 7);
    if (c >= 'a' && c <= 'z') {
        c = (char)(c - 'a' + 'A');
    }
    switch (c) {
        case 'A': { const uint8_t r[7] = {0x0E,0x11,0x11,0x1F,0x11,0x11,0x11}; memcpy(out_rows, r, 7); break; }
        case 'B': { const uint8_t r[7] = {0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E}; memcpy(out_rows, r, 7); break; }
        case 'C': { const uint8_t r[7] = {0x0E,0x11,0x10,0x10,0x10,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case 'D': { const uint8_t r[7] = {0x1E,0x11,0x11,0x11,0x11,0x11,0x1E}; memcpy(out_rows, r, 7); break; }
        case 'E': { const uint8_t r[7] = {0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F}; memcpy(out_rows, r, 7); break; }
        case 'F': { const uint8_t r[7] = {0x1F,0x10,0x10,0x1E,0x10,0x10,0x10}; memcpy(out_rows, r, 7); break; }
        case 'G': { const uint8_t r[7] = {0x0E,0x11,0x10,0x17,0x11,0x11,0x0F}; memcpy(out_rows, r, 7); break; }
        case 'H': { const uint8_t r[7] = {0x11,0x11,0x11,0x1F,0x11,0x11,0x11}; memcpy(out_rows, r, 7); break; }
        case 'I': { const uint8_t r[7] = {0x0E,0x04,0x04,0x04,0x04,0x04,0x0E}; memcpy(out_rows, r, 7); break; }
        case 'J': { const uint8_t r[7] = {0x07,0x02,0x02,0x02,0x12,0x12,0x0C}; memcpy(out_rows, r, 7); break; }
        case 'K': { const uint8_t r[7] = {0x11,0x12,0x14,0x18,0x14,0x12,0x11}; memcpy(out_rows, r, 7); break; }
        case 'L': { const uint8_t r[7] = {0x10,0x10,0x10,0x10,0x10,0x10,0x1F}; memcpy(out_rows, r, 7); break; }
        case 'M': { const uint8_t r[7] = {0x11,0x1B,0x15,0x15,0x11,0x11,0x11}; memcpy(out_rows, r, 7); break; }
        case 'N': { const uint8_t r[7] = {0x11,0x19,0x15,0x13,0x11,0x11,0x11}; memcpy(out_rows, r, 7); break; }
        case 'O': { const uint8_t r[7] = {0x0E,0x11,0x11,0x11,0x11,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case 'P': { const uint8_t r[7] = {0x1E,0x11,0x11,0x1E,0x10,0x10,0x10}; memcpy(out_rows, r, 7); break; }
        case 'Q': { const uint8_t r[7] = {0x0E,0x11,0x11,0x11,0x15,0x12,0x0D}; memcpy(out_rows, r, 7); break; }
        case 'R': { const uint8_t r[7] = {0x1E,0x11,0x11,0x1E,0x14,0x12,0x11}; memcpy(out_rows, r, 7); break; }
        case 'S': { const uint8_t r[7] = {0x0F,0x10,0x10,0x0E,0x01,0x01,0x1E}; memcpy(out_rows, r, 7); break; }
        case 'T': { const uint8_t r[7] = {0x1F,0x04,0x04,0x04,0x04,0x04,0x04}; memcpy(out_rows, r, 7); break; }
        case 'U': { const uint8_t r[7] = {0x11,0x11,0x11,0x11,0x11,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case 'V': { const uint8_t r[7] = {0x11,0x11,0x11,0x11,0x11,0x0A,0x04}; memcpy(out_rows, r, 7); break; }
        case 'W': { const uint8_t r[7] = {0x11,0x11,0x11,0x15,0x15,0x1B,0x11}; memcpy(out_rows, r, 7); break; }
        case 'X': { const uint8_t r[7] = {0x11,0x11,0x0A,0x04,0x0A,0x11,0x11}; memcpy(out_rows, r, 7); break; }
        case 'Y': { const uint8_t r[7] = {0x11,0x11,0x0A,0x04,0x04,0x04,0x04}; memcpy(out_rows, r, 7); break; }
        case 'Z': { const uint8_t r[7] = {0x1F,0x01,0x02,0x04,0x08,0x10,0x1F}; memcpy(out_rows, r, 7); break; }
        case '0': { const uint8_t r[7] = {0x0E,0x11,0x13,0x15,0x19,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case '1': { const uint8_t r[7] = {0x04,0x0C,0x04,0x04,0x04,0x04,0x0E}; memcpy(out_rows, r, 7); break; }
        case '2': { const uint8_t r[7] = {0x0E,0x11,0x01,0x06,0x08,0x10,0x1F}; memcpy(out_rows, r, 7); break; }
        case '3': { const uint8_t r[7] = {0x1F,0x02,0x04,0x06,0x01,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case '4': { const uint8_t r[7] = {0x02,0x06,0x0A,0x12,0x1F,0x02,0x02}; memcpy(out_rows, r, 7); break; }
        case '5': { const uint8_t r[7] = {0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case '6': { const uint8_t r[7] = {0x06,0x08,0x10,0x1E,0x11,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case '7': { const uint8_t r[7] = {0x1F,0x01,0x02,0x04,0x08,0x08,0x08}; memcpy(out_rows, r, 7); break; }
        case '8': { const uint8_t r[7] = {0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E}; memcpy(out_rows, r, 7); break; }
        case '9': { const uint8_t r[7] = {0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C}; memcpy(out_rows, r, 7); break; }
        case ':': { const uint8_t r[7] = {0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x00}; memcpy(out_rows, r, 7); break; }
        case '.': { const uint8_t r[7] = {0x00,0x00,0x00,0x00,0x00,0x0C,0x0C}; memcpy(out_rows, r, 7); break; }
        case ',': { const uint8_t r[7] = {0x00,0x00,0x00,0x00,0x04,0x04,0x08}; memcpy(out_rows, r, 7); break; }
        case '-': { const uint8_t r[7] = {0x00,0x00,0x00,0x1F,0x00,0x00,0x00}; memcpy(out_rows, r, 7); break; }
        case '+': { const uint8_t r[7] = {0x00,0x04,0x04,0x1F,0x04,0x04,0x00}; memcpy(out_rows, r, 7); break; }
        case '/': { const uint8_t r[7] = {0x01,0x02,0x02,0x04,0x08,0x08,0x10}; memcpy(out_rows, r, 7); break; }
        case '!': { const uint8_t r[7] = {0x04,0x04,0x04,0x04,0x04,0x00,0x04}; memcpy(out_rows, r, 7); break; }
        case '?': { const uint8_t r[7] = {0x0E,0x11,0x01,0x02,0x04,0x00,0x04}; memcpy(out_rows, r, 7); break; }
        case '[': { const uint8_t r[7] = {0x0E,0x08,0x08,0x08,0x08,0x08,0x0E}; memcpy(out_rows, r, 7); break; }
        case ']': { const uint8_t r[7] = {0x0E,0x02,0x02,0x02,0x02,0x02,0x0E}; memcpy(out_rows, r, 7); break; }
        case '(': { const uint8_t r[7] = {0x02,0x04,0x08,0x08,0x08,0x04,0x02}; memcpy(out_rows, r, 7); break; }
        case ')': { const uint8_t r[7] = {0x08,0x04,0x02,0x02,0x02,0x04,0x08}; memcpy(out_rows, r, 7); break; }
        case '#': { const uint8_t r[7] = {0x0A,0x1F,0x0A,0x0A,0x1F,0x0A,0x00}; memcpy(out_rows, r, 7); break; }
        case '%': { const uint8_t r[7] = {0x19,0x19,0x02,0x04,0x08,0x13,0x13}; memcpy(out_rows, r, 7); break; }
        case '>': { const uint8_t r[7] = {0x08,0x0C,0x0E,0x0F,0x0E,0x0C,0x08}; memcpy(out_rows, r, 7); break; }
        case '<': { const uint8_t r[7] = {0x02,0x06,0x0E,0x1E,0x0E,0x06,0x02}; memcpy(out_rows, r, 7); break; }
        case '=': { const uint8_t r[7] = {0x00,0x00,0x1F,0x00,0x1F,0x00,0x00}; memcpy(out_rows, r, 7); break; }
        case '|': { const uint8_t r[7] = {0x04,0x04,0x04,0x04,0x04,0x04,0x04}; memcpy(out_rows, r, 7); break; }
        case '&': { const uint8_t r[7] = {0x0C,0x12,0x14,0x08,0x15,0x12,0x0D}; memcpy(out_rows, r, 7); break; }
        case '$': { const uint8_t r[7] = {0x04,0x0F,0x14,0x0E,0x05,0x1E,0x04}; memcpy(out_rows, r, 7); break; }
        case '*': { const uint8_t r[7] = {0x00,0x01,0x02,0x14,0x08,0x00,0x00}; memcpy(out_rows, r, 7); break; }
        default: break;
    }
}

static void render_glyph_with_shadow(
    ObSnesCanvas *canvas,
    int x,
    int y,
    char c,
    uint32_t fg_rgba,
    bool bold_8x8
) {
    if (c == ' ') {
        return;
    }
    uint8_t rows[7];
    get_glyph_5x7(c, rows);

    /* Pass 1: 1px bottom-right drop shadow (#080810) */
    for (int ry = 0; ry < 7; ++ry) {
        uint8_t bits = rows[ry];
        for (int rx = 0; rx < 5; ++rx) {
            if ((bits & (1u << (4 - rx))) != 0) {
                put_pixel(canvas, x + rx + 1, y + ry + 1, OB_COLOR_TEXT_SHADOW);
                if (bold_8x8) {
                    put_pixel(canvas, x + rx + 2, y + ry + 1, OB_COLOR_TEXT_SHADOW);
                }
            }
        }
    }

    /* Pass 2: Foreground glyph pixels */
    for (int ry = 0; ry < 7; ++ry) {
        uint8_t bits = rows[ry];
        for (int rx = 0; rx < 5; ++rx) {
            if ((bits & (1u << (4 - rx))) != 0) {
                put_pixel(canvas, x + rx, y + ry, fg_rgba);
                if (bold_8x8) {
                    put_pixel(canvas, x + rx + 1, y + ry, fg_rgba);
                }
            }
        }
    }
}

void draw_snes_tile_text(
    ObSnesCanvas *canvas,
    int x,
    int y,
    const char *text,
    ObSnesPaletteId pal
) {
    if (!canvas || !text) {
        return;
    }
    uint32_t fg = ob_snes_palette_color(pal);
    int cx = x;
    for (const char *p = text; *p != '\0'; ++p) {
        render_glyph_with_shadow(canvas, cx, y, *p, fg, true);
        cx += 8;
    }
}

void draw_snes_compact_text(
    ObSnesCanvas *canvas,
    int x,
    int y,
    const char *text,
    ObSnesPaletteId pal
) {
    if (!canvas || !text) {
        return;
    }
    uint32_t fg = ob_snes_palette_color(pal);
    int cx = x;
    for (const char *p = text; *p != '\0'; ++p) {
        render_glyph_with_shadow(canvas, cx, y, *p, fg, false);
        cx += 6;
    }
}

void draw_snes_gauge_bar(
    ObSnesCanvas *canvas,
    int x,
    int y,
    int w,
    int h,
    int value,
    int max_value,
    uint32_t fill_rgba,
    uint32_t back_rgba
) {
    if (!canvas || w < 4 || h < 4) {
        return;
    }
    if (max_value <= 0) {
        max_value = 1;
    }
    if (value < 0) {
        value = 0;
    }
    if (value > max_value) {
        value = max_value;
    }

    /* Outer bronze bevel frame */
    draw_snes_rect_outline(canvas, x, y, w, h, OB_COLOR_GOLD_SHADOW);
    int inner_w = w - 2;
    int inner_h = h - 2;
    int fill_w = (inner_w * value) / max_value;

    /* Background & foreground fill */
    draw_snes_rect_fill(canvas, x + 1, y + 1, inner_w, inner_h, back_rgba);
    if (fill_w > 0) {
        draw_snes_rect_fill(canvas, x + 1, y + 1, fill_w, inner_h, fill_rgba);
        /* Top 1px specular sheen */
        draw_snes_rect_fill(canvas, x + 1, y + 1, fill_w, 1, OB_COLOR_TEXT_IVORY);
    }

    /* 8px segment dividers */
    for (int sx = 8; sx < inner_w; sx += 8) {
        draw_snes_rect_fill(canvas, x + 1 + sx, y + 1, 1, inner_h, OB_COLOR_WINDOW_INNER_BEVEL);
    }
}

static const uint8_t k_icon_8x8[8][8] = {
    /* 0: OB_ICON_ARROW_RIGHT */
    { 0x00, 0x20, 0x30, 0x7C, 0x30, 0x20, 0x00, 0x00 },
    /* 1: OB_ICON_CROWN */
    { 0x00, 0x42, 0x66, 0x7E, 0x7E, 0x3C, 0x7E, 0x00 },
    /* 2: OB_ICON_SUN */
    { 0x10, 0x54, 0x38, 0x7C, 0x38, 0x54, 0x10, 0x00 },
    /* 3: OB_ICON_MOON */
    { 0x1C, 0x38, 0x70, 0x70, 0x70, 0x38, 0x1C, 0x00 },
    /* 4: OB_ICON_SWORD */
    { 0x02, 0x06, 0x0C, 0x18, 0x70, 0x20, 0x40, 0x00 },
    /* 5: OB_ICON_SHIELD */
    { 0x7E, 0x7E, 0x7E, 0x7E, 0x3C, 0x18, 0x00, 0x00 },
    /* 6: OB_ICON_WING */
    { 0x06, 0x1E, 0x3C, 0x78, 0x3E, 0x1C, 0x08, 0x00 },
    /* 7: OB_ICON_WARNING */
    { 0x18, 0x3C, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x00 }
};

void draw_snes_icon(
    ObSnesCanvas *canvas,
    int x,
    int y,
    ObSnesIconId icon,
    ObSnesPaletteId pal
) {
    if (!canvas || (int)icon < 0 || (int)icon > 7) {
        return;
    }
    uint32_t fg = ob_snes_palette_color(pal);
    const uint8_t *rows = k_icon_8x8[(int)icon];
    for (int ry = 0; ry < 8; ++ry) {
        uint8_t bits = rows[ry];
        for (int rx = 0; rx < 8; ++rx) {
            if ((bits & (1u << (7 - rx))) != 0) {
                put_pixel(canvas, x + rx + 1, y + ry + 1, OB_COLOR_TEXT_SHADOW);
                put_pixel(canvas, x + rx, y + ry, fg);
            }
        }
    }
}

void draw_snes_mini_tarot_card(
    ObSnesCanvas *canvas,
    int x,
    int y,
    uint8_t card_id,
    bool overlevel_hazard
) {
    /* 0-indexed Ogre Battle Tarot IDs (0=I.Magician .. 21=XXII.Fool) */
    static const char *const k_roman[22] = {
        "I",  "II", "3",  "IV", "V",  "VI", "7",  "8",
        "IX", "X",  "XI", "12", "13", "14", "XV", "16",
        "17", "18", "19", "XX", "21", "0"
    };

    /* 18x24 Tarot Frame */
    draw_snes_rect_fill(canvas, x, y, 18, 24, OB_COLOR_WINDOW_INNER_BEVEL);
    draw_snes_rect_outline(canvas, x, y, 18, 24,
        overlevel_hazard ? OB_COLOR_TEXT_CRIMSON : OB_COLOR_GOLD_HI);
    draw_snes_rect_fill(canvas, x + 1, y + 1, 16, 8, OB_COLOR_GOLD_SHADOW);

    /* Centered Roman numeral at top of card */
    const char *rn = (card_id < 22u) ? k_roman[card_id] : "I";
    int rn_len = (int)strlen(rn);
    int tx = x + (18 - rn_len * 6) / 2;
    draw_snes_compact_text(canvas, tx, y + 1, rn, OB_PAL_GOLD);

    /* Symbolic Arcana Art in center (14x11) */
    uint32_t art_color = overlevel_hazard ? OB_COLOR_TEXT_CRIMSON : OB_COLOR_TEXT_CYAN;
    draw_snes_rect_fill(canvas, x + 3, y + 10, 12, 11, OB_COLOR_HEADER_FILL);
    draw_snes_rect_fill(canvas, x + 6, y + 12, 6, 7, art_color);
    draw_snes_rect_fill(canvas, x + 8, y + 10, 2, 11, OB_COLOR_GOLD_HI);

    /* Hazard seal in bottom-right corner if card causes Lord Overlevel */
    if (overlevel_hazard) {
        draw_snes_rect_fill(canvas, x + 12, y + 18, 5, 5, OB_COLOR_TEXT_CRIMSON);
        put_pixel(canvas, x + 14, y + 20, OB_COLOR_TEXT_IVORY);
    }
}

void draw_snes_zodiac_gem(
    ObSnesCanvas *canvas,
    int x,
    int y,
    uint8_t stone_index,
    bool collected
) {
    static const char *const k_zodiac_tag[12] = {
        "GAR", "AME", "AQU", "DIA", "EME", "PEA",
        "RUB", "PER", "SAP", "OPA", "TOP", "TUR"
    };
    static const uint32_t k_gem_colors[12] = {
        OB_BGR555_RGBA(0xF8, 0x38, 0x38), /* Garnet */
        OB_BGR555_RGBA(0xB8, 0x48, 0xF8), /* Amethyst */
        OB_BGR555_RGBA(0x48, 0xD8, 0xF8), /* Aquamarine */
        OB_BGR555_RGBA(0xF8, 0xF8, 0xF8), /* Diamond */
        OB_BGR555_RGBA(0x48, 0xF8, 0x68), /* Emerald */
        OB_BGR555_RGBA(0xF8, 0xE8, 0xD0), /* Pearl */
        OB_BGR555_RGBA(0xE8, 0x20, 0x50), /* Ruby */
        OB_BGR555_RGBA(0x98, 0xF8, 0x38), /* Peridot */
        OB_BGR555_RGBA(0x38, 0x68, 0xF8), /* Sapphire */
        OB_BGR555_RGBA(0xF8, 0xA8, 0xC8), /* Opal */
        OB_BGR555_RGBA(0xF8, 0xC8, 0x38), /* Topaz */
        OB_BGR555_RGBA(0x38, 0xF8, 0xD8)  /* Turquoise */
    };

    uint8_t idx = (uint8_t)(stone_index % 12u);
    draw_snes_rect_fill(canvas, x, y, 30, 12, OB_COLOR_WINDOW_INNER_BEVEL);
    draw_snes_rect_outline(canvas, x, y, 30, 12,
        collected ? OB_COLOR_GOLD_HI : OB_COLOR_GOLD_SHADOW);

    /* 6x6 Faceted Gemstone icon */
    uint32_t gem_c = collected ? k_gem_colors[idx] : OB_COLOR_STONE_DARK;
    draw_snes_rect_fill(canvas, x + 2, y + 3, 6, 6, gem_c);
    if (collected) {
        put_pixel(canvas, x + 3, y + 4, OB_COLOR_TEXT_IVORY);
    }

    draw_snes_compact_text(canvas, x + 10, y + 2, k_zodiac_tag[idx],
        collected ? OB_PAL_IVORY : OB_PAL_MUTED);
}

void draw_snes_tapestry_pillar(ObSnesCanvas *canvas, int x, int y, int w, int h) {
    if (!canvas || w <= 0 || h <= 0) {
        return;
    }
    for (int ry = 0; ry < h; ++ry) {
        for (int rx = 0; rx < w; ++rx) {
            int tx = rx & 15;
            int ty = ry & 15;
            uint32_t c = OB_COLOR_STONE_MID;
            if (tx == 0 || ty == 0) {
                c = OB_COLOR_STONE_HI;
            } else if (tx == 15 || ty == 15) {
                c = OB_COLOR_STONE_DARK;
            } else if (((tx + ty) & 3) == 0) {
                c = OB_COLOR_STONE_DARK;
            }
            put_pixel(canvas, x + rx, y + ry, c);
        }
    }
    /* Gold trim separator along inner edge */
    draw_snes_rect_outline(canvas, x, y, w, h, OB_COLOR_GOLD_SHADOW);
}

bool ob_snes_ui_save_ppm(const ObSnesCanvas *canvas, const char *filepath) {
    if (!canvas || !canvas->pixels || !filepath) {
        return false;
    }
    FILE *fp = fopen(filepath, "wb");
    if (!fp) {
        return false;
    }
    fprintf(fp, "P6\n%d %d\n255\n", canvas->width, canvas->height);
    for (int y = 0; y < canvas->height; ++y) {
        const uint32_t *row = &canvas->pixels[y * canvas->stride];
        for (int x = 0; x < canvas->width; ++x) {
            uint32_t px = row[x];
            uint8_t rgb[3] = {
                (uint8_t)(px & 0xFFu),
                (uint8_t)((px >> 8) & 0xFFu),
                (uint8_t)((px >> 16) & 0xFFu)
            };
            fwrite(rgb, 1, 3, fp);
        }
    }
    fclose(fp);
    return true;
}
