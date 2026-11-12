#ifndef OB_SNES_UI_THEME_H
#define OB_SNES_UI_THEME_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================
 * 1. Authentic 15-Bit SNES BGR555 Color Space (Stepped in Multiples of 8)
 *    Packed as 0xAABBGGRR (32-bit RGBA in little-endian memory: R, G, B, A)
 * ============================================================================ */
#define OB_BGR555_RGBA(r, g, b) \
    ((uint32_t)(0xFF000000u | (((uint32_t)(b) & 0xF8u) << 16) | (((uint32_t)(g) & 0xF8u) << 8) | ((uint32_t)(r) & 0xF8u)))

/* Quest 1993 Royal Blue Window Backdrop Gradient */
#define OB_COLOR_WINDOW_TOP          OB_BGR555_RGBA(0x18, 0x28, 0x68) /* #182868 Top Royal Blue */
#define OB_COLOR_WINDOW_MID          OB_BGR555_RGBA(0x10, 0x18, 0x48) /* #101848 Mid Indigo */
#define OB_COLOR_WINDOW_BOTTOM       OB_BGR555_RGBA(0x08, 0x08, 0x30) /* #080830 Deep Midnight Blue */
#define OB_COLOR_WINDOW_INNER_BEVEL  OB_BGR555_RGBA(0x08, 0x08, 0x10) /* #080810 Inner Bevel & Drop Shadow */
#define OB_COLOR_HEADER_FILL         OB_BGR555_RGBA(0x10, 0x18, 0x38) /* #101838 Embossed Header Plate */
#define OB_COLOR_CANVAS_BACKDROP     OB_BGR555_RGBA(0x08, 0x08, 0x18) /* #080818 Outer Wing Frame Backdrop */

/* 9-Slice Ornate Gold Border Palette */
#define OB_COLOR_GOLD_HI             OB_BGR555_RGBA(0xF8, 0xD8, 0x70) /* #F8D870 Highlight Gold */
#define OB_COLOR_GOLD_MID            OB_BGR555_RGBA(0xC8, 0x98, 0x38) /* #C89838 Mid Brass */
#define OB_COLOR_GOLD_SHADOW         OB_BGR555_RGBA(0x78, 0x50, 0x18) /* #785018 Shadow Bronze */
#define OB_COLOR_GOLD_DARK           OB_BGR555_RGBA(0x38, 0x20, 0x08) /* #382008 Outer Dark Bronze */

/* Zenobian Stone & Parchment Tapestry Palette (Vanilla 16:9 Menu Fill) */
#define OB_COLOR_STONE_HI            OB_BGR555_RGBA(0x58, 0x50, 0x60) /* #585060 Carved Stone Highlight */
#define OB_COLOR_STONE_MID           OB_BGR555_RGBA(0x38, 0x30, 0x40) /* #383040 Carved Stone Mid */
#define OB_COLOR_STONE_DARK          OB_BGR555_RGBA(0x20, 0x18, 0x28) /* #201828 Carved Stone Shadow */

/* Semantic Pixel Typography Palettes */
#define OB_COLOR_TEXT_IVORY          OB_BGR555_RGBA(0xF8, 0xF8, 0xF0) /* #F8F8F0 Primary Crisp Ivory */
#define OB_COLOR_TEXT_GOLD           OB_BGR555_RGBA(0xF8, 0xE0, 0x50) /* #F8E050 Section Headers / Goth */
#define OB_COLOR_TEXT_CRIMSON        OB_BGR555_RGBA(0xF8, 0x48, 0x48) /* #F84848 Threat / -5 CF / Overlevel */
#define OB_COLOR_TEXT_EMERALD        OB_BGR555_RGBA(0x58, 0xF8, 0x78) /* #58F878 Eligible / Positive Delta */
#define OB_COLOR_TEXT_CYAN           OB_BGR555_RGBA(0x68, 0xE8, 0xF8) /* #68E8F8 Celestial / Sky / PoI */
#define OB_COLOR_TEXT_AMBER          OB_BGR555_RGBA(0xF8, 0xA8, 0x38) /* #F8A838 Caution / Drift Warning */
#define OB_COLOR_TEXT_MUTED          OB_BGR555_RGBA(0x98, 0xA0, 0xB0) /* #98A0B0 Secondary Silver */
#define OB_COLOR_TEXT_SHADOW         OB_BGR555_RGBA(0x08, 0x08, 0x10) /* #080810 1px Drop Shadow */

/* Alert & Radar Box Colors */
#define OB_COLOR_ALERT_BG            OB_BGR555_RGBA(0x48, 0x10, 0x18) /* #481018 Crimson Hazard Fill */
#define OB_COLOR_RADAR_BG            OB_BGR555_RGBA(0x10, 0x18, 0x20) /* #101820 Radar Terrain Dark */
#define OB_COLOR_RADAR_FOREST        OB_BGR555_RGBA(0x18, 0x38, 0x20) /* #183820 Radar Forest Canopy */
#define OB_COLOR_RADAR_RIVER         OB_BGR555_RGBA(0x20, 0x40, 0x78) /* #204078 Radar River Channel */

typedef enum ObSnesPaletteId {
    OB_PAL_IVORY = 0,
    OB_PAL_GOLD = 1,
    OB_PAL_CRIMSON = 2,
    OB_PAL_EMERALD = 3,
    OB_PAL_CYAN = 4,
    OB_PAL_AMBER = 5,
    OB_PAL_MUTED = 6
} ObSnesPaletteId;

typedef enum ObSnesIconId {
    OB_ICON_ARROW_RIGHT = 0,
    OB_ICON_CROWN = 1,
    OB_ICON_SUN = 2,
    OB_ICON_MOON = 3,
    OB_ICON_SWORD = 4,
    OB_ICON_SHIELD = 5,
    OB_ICON_WING = 6,
    OB_ICON_WARNING = 7
} ObSnesIconId;

#ifdef __cplusplus
}
#endif

#endif /* OB_SNES_UI_THEME_H */
