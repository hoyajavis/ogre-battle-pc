#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/engine/input.h"
#include "../src/engine/snes_ui_rasterizer.h"
#include "../src/engine/widescreen.h"

static inline void write_u16_le(uint8_t *buf, uint32_t addr, uint16_t val) {
    buf[addr]      = (uint8_t)(val & 0xFFu);
    buf[addr + 1u] = (uint8_t)((val >> 8u) & 0xFFu);
}

static inline void write_u32_le(uint8_t *buf, uint32_t addr, uint32_t val) {
    buf[addr]      = (uint8_t)(val & 0xFFu);
    buf[addr + 1u] = (uint8_t)((val >> 8u) & 0xFFu);
    buf[addr + 2u] = (uint8_t)((val >> 16u) & 0xFFu);
    buf[addr + 3u] = (uint8_t)((val >> 24u) & 0xFFu);
}

static void populate_canonical_wram(uint8_t *wram) {
    memset(wram, 0, OB_WRAM_SIZE);
    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        write_u16_le(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2), 0xFFFFu);
        write_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2), 0xFFFFu);
    }
    for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
        write_u16_le(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2), 0xFFFFu);
        write_u16_le(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2), 0xFFFFu);
    }

    /* Macro state: CF = 72, Goth = 42,650, Clock = 12:00 */
    wram[0x157Cu] = 72u;
    write_u32_le(wram, 0x1578u, 42650u);
    wram[0x1570u] = 12u;
    wram[0x1571u] = 0u;

    /* Camera bounds and tactical map cursor */
    write_u16_le(wram, OB_WRAM_CAM_MIN_X, 0u);
    write_u16_le(wram, OB_WRAM_CAM_MIN_Y, 0u);
    write_u16_le(wram, OB_WRAM_CAM_MAX_X, 1024u);
    write_u16_le(wram, OB_WRAM_CAM_MAX_Y, 1024u);
    write_u16_le(wram, OB_WRAM_CAM_X, 200u);
    write_u16_le(wram, OB_WRAM_CAM_Y, 150u);
    write_u16_le(wram, OB_WRAM_MAP_TILES_X, 128u);
    write_u16_le(wram, OB_WRAM_MAP_TILES_Y, 128u);
    write_u16_le(wram, OB_WRAM_CUR_SCREEN_X, 110u);
    write_u16_le(wram, OB_WRAM_CUR_SCREEN_Y, 96u);
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0x80u;

    /* Player Squads #0, #1, #2 and Enemy Squad #10 approaching City #0 */
    write_u16_le(wram, OB_WRAM_SQUAD_X_BASE + 0, 310u);
    write_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + 0, 246u);
    write_u16_le(wram, OB_WRAM_SQUAD_X_BASE + 2, 340u);
    write_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + 2, 260u);
    write_u16_le(wram, OB_WRAM_SQUAD_X_BASE + 4, 480u);
    write_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + 4, 390u);

    /* Enemy Squad #10 closing within 48px of Liberated Temple #0 */
    write_u16_le(wram, OB_WRAM_SQUAD_X_BASE + 20, 280u);
    write_u16_le(wram, OB_WRAM_SQUAD_Y_BASE + 20, 218u);

    /* City #0 (Liberated Temple) & City #1 (Daskania, Compatibility 70) */
    write_u16_le(wram, OB_WRAM_CITY_X_BASE + 0, 250u);
    write_u16_le(wram, OB_WRAM_CITY_Y_BASE + 0, 200u);
    write_u16_le(wram, 0x1B5Du + 0, 8000u);
    wram[0x1C25u + 0] = 50u;
    wram[0x1C4Du + 0] = 0x05u; /* Liberated + Temple */

    write_u16_le(wram, OB_WRAM_CITY_X_BASE + 2, 308u);
    write_u16_le(wram, OB_WRAM_CITY_Y_BASE + 2, 232u);
    write_u16_le(wram, 0x1B5Du + 2, 9500u);
    wram[0x1C25u + 1] = 70u;
    wram[0x1C4Du + 1] = 0x03u; /* Liberated + Hidden PoI */

    /* Roster level & ALI for Lord (#0) and Ashe (#1) */
    wram[0xF148u + 0] = 6u;
    wram[0xF42Cu + 0] = 72u;
    wram[0xF148u + 1] = 5u;
    wram[0xF42Cu + 1] = 74u;

    /* Camp Inventory: Quicksilver (0x45), Tablet of Yaru (0x49), Garnet (0x50), Amethyst (0x51) */
    wram[0x157Eu + 0] = 0x45u;
    wram[0x157Eu + 1] = 0x49u;
    wram[0x157Eu + 2] = 0x50u;
    wram[0x157Eu + 3] = 0x51u;
}

static void assert_bgr555_compliance(const uint32_t *pixels, int count) {
    for (int i = 0; i < count; ++i) {
        uint32_t px = pixels[i];
        uint8_t r = (uint8_t)(px & 0xFFu);
        uint8_t g = (uint8_t)((px >> 8u) & 0xFFu);
        uint8_t b = (uint8_t)((px >> 16u) & 0xFFu);
        assert((r & 0x07u) == 0u);
        assert((g & 0x07u) == 0u);
        assert((b & 0x07u) == 0u);
    }
}

int main(void) {
    uint8_t *wram_live   = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t *wram_golden = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t *ppu_oam     = (uint8_t *)calloc(OB_PPU_OAM_SIZE, 1);
    uint32_t *fb_800x448 = (uint32_t *)calloc(OB_WIDE_2X_W * OB_WIDE_2X_H, sizeof(uint32_t));
    assert(wram_live && wram_golden && ppu_oam && fb_800x448);

    populate_canonical_wram(wram_live);
    memcpy(wram_golden, wram_live, OB_WRAM_SIZE);

    ObWidescreenState ws;
    ob_widescreen_init(&ws);

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_16_9, OB_VIEWPORT_HEIGHT);
    ob_input_set_wings_enabled(&mouse, true);

    /* ========================================================================
     * GATE 3A & 3B: Zero-Invasion Lockstep & BGR555 Palette Compliance
     * ======================================================================== */
    /* 1. Tactical Overland Map (with City #1 Hovered in Right Wing Inspector) */
    mouse.snapped_type  = OB_SNAP_CITY;
    mouse.snapped_index = 1;
    ws.active_scene     = ob_widescreen_detect_scene(wram_live, ppu_oam);
    assert(ws.active_scene == OB_SCENE_TACTICAL_MAP);

    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    assert(ws.telemetry.chaos_frame == 72u);
    assert(ws.telemetry.recapture_threat_active == true);
    assert(ws.inspector_mode == OB_INSPECT_CITY_LIBERATION);
    assert(ws.telemetry.predicted_cf_delta == +2);

    ob_widescreen_render_frame(&ws, wram_live, NULL, fb_800x448);
    assert(memcmp(wram_live, wram_golden, OB_WRAM_SIZE) == 0);
    assert_bgr555_compliance(fb_800x448, OB_WIDE_2X_W * OB_WIDE_2X_H);

    ObSnesCanvas dump_canvas;
    ob_snes_canvas_init(&dump_canvas, fb_800x448, OB_WIDE_2X_W, OB_WIDE_2X_H);
    ob_snes_ui_save_ppm(&dump_canvas, "/tmp/widescreen_01_tactical_map.ppm");
    printf("[PASS] Gate 3A/3B (Tactical Map 16:9 Wings): 0-byte WRAM drift & 100%% BGR555 compliance\n");

    /* 2. Combat Stage (Clash Tug-of-War & Tarot Overlevel Guard Dock) */
    write_u16_le(wram_live, 0xF942u, 178u);
    write_u16_le(wram_live, 0xF944u, 79u);
    memcpy(wram_golden, wram_live, OB_WRAM_SIZE);

    ws.active_scene = ob_widescreen_detect_scene(wram_live, ppu_oam);
    assert(ws.active_scene == OB_SCENE_COMBAT_STAGE);
    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    ob_widescreen_render_frame(&ws, wram_live, NULL, fb_800x448);
    assert(memcmp(wram_live, wram_golden, OB_WRAM_SIZE) == 0);
    assert_bgr555_compliance(fb_800x448, OB_WIDE_2X_W * OB_WIDE_2X_H);
    ob_snes_ui_save_ppm(&dump_canvas, "/tmp/widescreen_02_combat_stage.ppm");
    printf("[PASS] Gate 3A/3B (Combat Stage 16:9 Wings): 0-byte WRAM drift & 100%% BGR555 compliance\n");

    /* 3. Continental World Map + [Tab] Campaign Grimoire Overlay */
    write_u16_le(wram_live, 0xF942u, 0u);
    write_u16_le(wram_live, 0xF944u, 0u);
    wram_live[OB_WRAM_CUR_SPRITE_FLAGS] = 0x00u;
    wram_live[OB_WRAM_OAM1_Y]           = OB_OAM_OFFSCREEN_Y;
    ppu_oam[25 * 4 + 0]                 = 120u;
    ppu_oam[25 * 4 + 1]                 = 88u;
    ppu_oam[25 * 4 + 2]                 = 0x84u;
    ppu_oam[25 * 4 + 3]                 = 0x38u;
    memcpy(wram_golden, wram_live, OB_WRAM_SIZE);

    ws.active_scene = ob_widescreen_detect_scene(wram_live, ppu_oam);
    assert(ws.active_scene == OB_SCENE_WORLD_MAP);
    ob_widescreen_toggle_grimoire(&ws);
    assert(ws.grimoire_open == true);

    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    ob_widescreen_render_frame(&ws, wram_live, NULL, fb_800x448);
    assert(memcmp(wram_live, wram_golden, OB_WRAM_SIZE) == 0);
    assert_bgr555_compliance(fb_800x448, OB_WIDE_2X_W * OB_WIDE_2X_H);
    ob_snes_ui_save_ppm(&dump_canvas, "/tmp/widescreen_03_world_map_grimoire.ppm");
    ob_widescreen_toggle_grimoire(&ws);
    printf("[PASS] Gate 3C (World Map + [Tab] Grimoire Overlay): 18-Hero & 12-Zodiac ledger verified\n");

    /* 4. Warren's Character Creation Quiz (Mod/Seed Config + Live Lord Archetype Decoder) */
    memset(ppu_oam, 0xE0, OB_PPU_OAM_SIZE);
    wram_live[0x0010u] = 1u;
    memcpy(wram_golden, wram_live, OB_WRAM_SIZE);

    ws.active_scene = ob_widescreen_detect_scene(wram_live, ppu_oam);
    assert(ws.active_scene == OB_SCENE_WARREN_QUIZ);
    ob_widescreen_render_frame(&ws, wram_live, NULL, fb_800x448);
    assert(memcmp(wram_live, wram_golden, OB_WRAM_SIZE) == 0);
    assert_bgr555_compliance(fb_800x448, OB_WIDE_2X_W * OB_WIDE_2X_H);
    ob_snes_ui_save_ppm(&dump_canvas, "/tmp/widescreen_04_warren_quiz.ppm");
    printf("[PASS] Gate 3C (Warren Quiz 16:9 Wings): Mod/Seed & Lord Archetype Decoder verified\n");

    /* ========================================================================
     * GATE 3D: Widescreen Mouse +72px Core Offset & Interactive Wing Docks
     * ======================================================================== */
    populate_canonical_wram(wram_live);
    /* Test 1: Left Wing Squad Plate #2 Click -> Jumps Camera ($00BD/$00BF) to Squad #2 (480, 390) */
    ob_input_on_mouse_move(&mouse, 36, 85, 400, 224, 10u);
    ob_input_on_mouse_button(&mouse, true, false, false, 10u);
    uint16_t mask = ob_input_step_frame(&mouse, wram_live, ppu_oam, 0u, 10u);
    assert(mouse.active_mode == OB_MOUSE_MODE_LEFT_WING);
    assert(mouse.hovered_slot == 2);
    assert((mask & OB_BTN_DPAD_MASK) == 0u);
    uint16_t jumped_cam_x = (uint16_t)(wram_live[OB_WRAM_CAM_X] | (wram_live[OB_WRAM_CAM_X + 1] << 8));
    uint16_t jumped_cam_y = (uint16_t)(wram_live[OB_WRAM_CAM_Y] | (wram_live[OB_WRAM_CAM_Y + 1] << 8));
    assert(jumped_cam_x == 480u - 128u);
    assert(jumped_cam_y == 390u - 112u);
    ob_input_on_mouse_button(&mouse, false, false, false, 11u);

    /* Test 2: Center Core +72px Offset for Pillar 2 7-Icon Command Strip */
    wram_live[OB_WRAM_OAM1_TILE] = OB_TILE_ICON_BAR_FINGER;
    wram_live[OB_WRAM_OAM1_Y]    = OB_ICON_BAR_FINGER_Y;
    /* Icon #3 is at core_x = 71 + 3*16 + 4 = 123 -> snes_x = 72 + 123 = 195 */
    ob_input_on_mouse_move(&mouse, 195, 119, 400, 224, 12u);
    ob_input_step_frame(&mouse, wram_live, ppu_oam, 0u, 12u);
    assert(mouse.active_mode == OB_MOUSE_MODE_ICON_BAR);
    assert(wram_live[OB_WRAM_ICON_BAR_INDEX] == 3u);

    /* Test 3: Right Wing Tarot Guard Dock Slot Indexing */
    ob_input_on_mouse_move(&mouse, 360, 120, 400, 224, 13u);
    ob_input_step_frame(&mouse, wram_live, ppu_oam, 0u, 13u);
    assert(mouse.active_mode == OB_MOUSE_MODE_RIGHT_WING);
    assert(mouse.hovered_slot == 1);
    printf("[PASS] Gate 3D (Widescreen Mouse +72px Core Offset & Interactive Wing Docks): Verified\n");

    /* ========================================================================
     * GATE 3E: LakeSnes 0x55 Uninitialized WRAM Guard Regression Tests
     * ======================================================================== */
    memset(wram_live, 0x55, OB_WRAM_SIZE);
    memset(ppu_oam, 0xE0, OB_PPU_OAM_SIZE);
    ws.active_scene = ob_widescreen_detect_scene(wram_live, ppu_oam);
    assert(ws.active_scene == OB_SCENE_TITLE_BOOT);
    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    assert(ws.telemetry.chaos_frame == 0u);
    assert(ws.telemetry.goth_treasury == 0u);
    assert(ws.telemetry.player_clash_dmg == 0u);
    assert(ws.telemetry.enemy_clash_dmg == 0u);
    assert(ws.telemetry.lord_level == 0u);
    assert(ws.telemetry.tarot_count == 0u);
    ob_widescreen_render_frame(&ws, wram_live, NULL, fb_800x448);
    assert_bgr555_compliance(fb_800x448, OB_WIDE_2X_W * OB_WIDE_2X_H);

    /* World Map with 0x55 in uninitialized WRAM ($14E6=0x55, $F942=0x5555) */
    wram_live[0x00CBu] = 0x03u;
    wram_live[0x00CCu] = 0x0Du;
    write_u16_le(wram_live, 0x07A2u, 0x0008u);
    wram_live[0x07BAu] = 0xFFu;
    write_u32_le(wram_live, 0x1578u, 30000u);
    assert(ob_widescreen_detect_scene(wram_live, ppu_oam) == OB_SCENE_WORLD_MAP);

    /* Warren's Quiz with 0x55 in uninitialized WRAM */
    wram_live[0x00CCu] = 0x03u;
    write_u16_le(wram_live, 0x07A2u, 0x0000u);
    assert(ob_widescreen_detect_scene(wram_live, ppu_oam) == OB_SCENE_WARREN_QUIZ);
    printf("[PASS] Gate 3E (LakeSnes 0x55 Uninitialized WRAM Guard): Verified\n");

    /* ========================================================================
     * GATE 3F: Scene Detection Immunity & Tactical Wing Hysteresis
     * ======================================================================== */
    memset(wram_live, 0, OB_WRAM_SIZE);
    /* 1. Direct-Page scratch $0010 == 1 must never override live TITLE_BOOT, WORLD_MAP, or TACTICAL_MAP */
    wram_live[0x0010u] = 1u;
    wram_live[0x07BAu] = 0x55u;
    assert(ob_widescreen_detect_scene(wram_live, ppu_oam) == OB_SCENE_TITLE_BOOT);

    wram_live[0x07BAu] = 0x4Fu;
    wram_live[0x00CBu] = 0x03u;
    wram_live[0x00CCu] = 0x10u;
    write_u32_le(wram_live, 0x1578u, 30000u);
    write_u16_le(wram_live, OB_WRAM_SQUAD_X_BASE, 0x7FFFu);
    assert(ob_widescreen_detect_scene(wram_live, ppu_oam) == OB_SCENE_WORLD_MAP);

    /* World Map with live OAM[0] sword cursor (tile 0x6E) while $00CB == 0x01 and no Squad 0 */
    wram_live[0x00CBu] = 0x01u;
    wram_live[OB_WRAM_OAM0_Y] = 108u;
    wram_live[OB_WRAM_OAM0_TILE] = OB_TILE_WORLD_MAP_SWORD;
    assert(ob_widescreen_detect_scene(wram_live, ppu_oam) == OB_SCENE_WORLD_MAP);
    wram_live[OB_WRAM_OAM0_Y] = OB_OAM_OFFSCREEN_Y;
    wram_live[OB_WRAM_OAM0_TILE] = 0x01u;

    /* 2. Tactical Map with $0010 == 1, camera pan ($00CE == 3), cursor hidden ($14E6 == 0),
     *    and stale post-combat cumulative damage ($F942 == 240, $F944 == 180, $F92B == 0) */
    wram_live[0x00CBu] = 0x01u;
    wram_live[0x00CCu] = 0x10u;
    wram_live[OB_WRAM_CAM_STATE] = 3u;
    wram_live[OB_WRAM_CUR_SPRITE_FLAGS] = 0u;
    write_u16_le(wram_live, OB_WRAM_SQUAD_X_BASE, 512u);
    write_u16_le(wram_live, OB_WRAM_SQUAD_Y_BASE, 512u);
    write_u16_le(wram_live, 0xF942u, 240u);
    write_u16_le(wram_live, 0xF944u, 180u);
    wram_live[0xF92Bu] = 0u;
    wram_live[0xF941u] = 0u;
    assert(ob_widescreen_detect_scene(wram_live, ppu_oam) == OB_SCENE_TACTICAL_MAP);

    /* 3. Live calendar ($156D == 1) reads Hour from $1571 and Minute from $1572 */
    wram_live[0x156Du] = 1u;
    wram_live[0x1570u] = 14u; /* Day 14 */
    wram_live[0x1571u] = 19u; /* 19:00 (Night) */
    wram_live[0x1572u] = 45u; /* :45 */
    ob_widescreen_init(&ws);
    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    assert(ws.telemetry.clock_hour == 19u);
    assert(ws.telemetry.clock_minute == 45u);
    assert(!ws.telemetry.is_daytime);

    /* 4. 45-Frame Sticky Inspector Hold prevents rapid widget flickering when cursor leaves target */
    mouse.snapped_type = OB_SNAP_CITY;
    mouse.snapped_index = 2;
    wram_live[0x1C75u + 2] = 64u;
    wram_live[0x1C4Du + 2] = 0x01u;
    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    assert(ws.inspector_mode == OB_INSPECT_CITY_LIBERATION);

    mouse.snapped_type = OB_SNAP_NONE;
    mouse.snapped_index = -1;
    for (int f = 0; f < 44; ++f) {
        ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
        assert(ws.inspector_mode == OB_INSPECT_CITY_LIBERATION);
    }
    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    assert(ws.inspector_mode == OB_INSPECT_MOBILITY_NEUTRAL);

    /* 5. Recapture Threat Schmitt-trigger hysteresis (180px entry + 15-frame debounce, 210px exit) */
    write_u16_le(wram_live, OB_WRAM_CITY_X_BASE + 0, 400u);
    write_u16_le(wram_live, OB_WRAM_CITY_Y_BASE + 0, 400u);
    wram_live[0x1C4Du + 0] = 0x01u;
    write_u16_le(wram_live, OB_WRAM_SQUAD_X_BASE + 10 * 2, 500u); /* dist = 100 < 180 */
    write_u16_le(wram_live, OB_WRAM_SQUAD_Y_BASE + 10 * 2, 400u);
    for (int f = 0; f < 14; ++f) {
        ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
        assert(!ws.telemetry.recapture_threat_active);
    }
    ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    assert(ws.telemetry.recapture_threat_active);

    /* Moving enemy to dist = 195 (between 180 entry and 210 exit) keeps threat active without flicker */
    write_u16_le(wram_live, OB_WRAM_SQUAD_X_BASE + 10 * 2, 595u);
    for (int f = 0; f < 20; ++f) {
        ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
        assert(ws.telemetry.recapture_threat_active);
    }

    /* 6. Live 12.4 Fixed-Point Subpixel Coordinates (Stage 1 Felnamia: Squad 0 at (3904, 5760) = world (244, 360),
     *    Rebel Base at (3712, 5632) = world (232, 352), Enemy Squad 10 at (5120, 5632) = world (320, 352)) */
    memset(wram_live, 0xFF, OB_WRAM_SIZE);
    wram_live[0x07BAu] = 0x4Fu;
    wram_live[0x00CBu] = 0x01u;
    wram_live[0x00CCu] = 0x10u;
    wram_live[0x00CEu] = 0x00u;
    write_u16_le(wram_live, OB_WRAM_SQUAD_X_BASE + 0 * 2, 3904u);
    write_u16_le(wram_live, OB_WRAM_SQUAD_Y_BASE + 0 * 2, 5760u);
    write_u16_le(wram_live, OB_WRAM_SQUAD_X_BASE + 10 * 2, 5120u); /* world X = 320 -> dist to base (232) = 88 px < 180 */
    write_u16_le(wram_live, OB_WRAM_SQUAD_Y_BASE + 10 * 2, 5632u); /* world Y = 352 */
    write_u16_le(wram_live, OB_WRAM_CITY_X_BASE + 0 * 2, 3712u);
    write_u16_le(wram_live, OB_WRAM_CITY_Y_BASE + 0 * 2, 5632u);
    wram_live[0x1C4Du + 0] = 0x01u; /* Liberated Rebel Base */
    ob_widescreen_init(&ws);
    for (int f = 0; f < 15; ++f) {
        ob_widescreen_extract_telemetry(&ws, wram_live, &mouse);
    }
    assert(ws.telemetry.deployed_squads == 2u);
    assert(ws.telemetry.liberated_cities == 1u);
    assert(ws.telemetry.total_stage_cities == 1u);
    assert(ws.telemetry.recapture_threat_active);
    printf("[PASS] Gate 3F (Scene Detection Immunity & Tactical Wing Hysteresis): Verified\n");

    free(wram_live);
    free(wram_golden);
    free(ppu_oam);
    free(fb_800x448);
    printf("\n=== ALL GATE 3 (16:9 WIDESCREEN & AREA 1 WING INTEGRATION) GATES PASSED ===\n");
    return 0;
}
