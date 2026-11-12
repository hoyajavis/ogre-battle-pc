#ifndef OB_ENGINE_SNES_UI_RASTERIZER_H
#define OB_ENGINE_SNES_UI_RASTERIZER_H

#include <stdbool.h>
#include <stdint.h>
#include "../../include/ob_snes_ui_theme.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ObSnesCanvas {
    uint32_t *pixels;
    int width;
    int height;
    int stride;
} ObSnesCanvas;

/* Initialize a target RGBA software canvas */
void ob_snes_canvas_init(ObSnesCanvas *canvas, uint32_t *pixels, int width, int height);

/* Map semantic palette enum to 32-bit BGR555 RGBA color */
uint32_t ob_snes_palette_color(ObSnesPaletteId pal);

/* Fill solid rectangle clipped to canvas bounds */
void draw_snes_rect_fill(ObSnesCanvas *canvas, int x, int y, int w, int h, uint32_t rgba);

/* Draw 1px rectangle outline */
void draw_snes_rect_outline(ObSnesCanvas *canvas, int x, int y, int w, int h, uint32_t rgba);

/* Fill window interior with authentic Quest Royal Blue BGR555 vertical gradient + scanline dither */
void draw_snes_window_fill(ObSnesCanvas *canvas, int x, int y, int w, int h);

/* Draw 8x8 tile-snapped ornate 9-slice gold border around (x, y, w, h) */
void draw_snes_9slice_box(ObSnesCanvas *canvas, int x, int y, int w, int h, bool fill_backdrop);

/* Draw an embossed SNES section header plate inside a 9-slice box */
void draw_snes_header_plate(
    ObSnesCanvas *canvas,
    int x,
    int y,
    int w,
    const char *title,
    ObSnesPaletteId pal
);

/* Render authentic 8x8 SNES pixel font with 1px (#080810) drop shadow (8px char stride) */
void draw_snes_tile_text(
    ObSnesCanvas *canvas,
    int x,
    int y,
    const char *text,
    ObSnesPaletteId pal
);

/* Render compact 6x8 shadowed pixel font for dense 144px-wide wing telemetry rows (6px char stride) */
void draw_snes_compact_text(
    ObSnesCanvas *canvas,
    int x,
    int y,
    const char *text,
    ObSnesPaletteId pal
);

/* Draw a segmented 16-bit RPG gauge bar (8px segment dividers + 3D bevel) */
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
);

/* Draw an 8x8 2BPP/4BPP status icon with 1px drop shadow */
void draw_snes_icon(
    ObSnesCanvas *canvas,
    int x,
    int y,
    ObSnesIconId icon,
    ObSnesPaletteId pal
);

/* Draw a 16x24 miniature Major Arcana Tarot card with Roman header & optional overlevel seal */
void draw_snes_mini_tarot_card(
    ObSnesCanvas *canvas,
    int x,
    int y,
    uint8_t card_id,
    bool overlevel_hazard
);

/* Draw a faceted Zodiac Stone socket (28x14 px) with 3-letter constellation tag */
void draw_snes_zodiac_gem(
    ObSnesCanvas *canvas,
    int x,
    int y,
    uint8_t stone_index,
    bool collected
);

/* Draw Zenobian Stone & Parchment tapestry pillar for Vanilla 16:9 fixed-width menu screens */
void draw_snes_tapestry_pillar(ObSnesCanvas *canvas, int x, int y, int w, int h);

/* Export RGBA canvas to binary PPM (P6) file for closed-loop visual verification */
bool ob_snes_ui_save_ppm(const ObSnesCanvas *canvas, const char *filepath);

#ifdef __cplusplus
}
#endif

#endif /* OB_ENGINE_SNES_UI_RASTERIZER_H */
