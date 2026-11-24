#include "../src/engine/input.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint16_t read_u16(const uint8_t *wram, uint32_t addr) {
    return (uint16_t)((uint16_t)wram[addr] | ((uint16_t)wram[addr + 1u] << 8u));
}

static void write_u16(uint8_t *wram, uint32_t addr, uint16_t val) {
    wram[addr]      = (uint8_t)(val & 0xFFu);
    wram[addr + 1u] = (uint8_t)((val >> 8u) & 0xFFu);
}

/* =========================================================================
 * Gate 2A: Zero-Invasion Idle Lockstep & Deprecation Guard
 * ========================================================================= */
static void test_gate_2a_zero_invasion_lockstep(void) {
    uint8_t *wram_ref  = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t *wram_cand = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));

    assert(wram_ref != NULL && wram_cand != NULL);

    /* Populate baseline tactical map state */
    for (uint32_t i = 0; i < OB_WRAM_SIZE; ++i) {
        uint8_t v = (uint8_t)((i * 73u + 19u) & 0xFFu);
        wram_ref[i]  = v;
        wram_cand[i] = v;
    }

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_4_3, OB_VIEWPORT_HEIGHT);
    assert(!mouse.mouse_active);

    /* Run 1,000 frames in idle/replay mode: must produce 0-byte WRAM drift */
    for (uint32_t f = 1; f <= 1000; ++f) {
        uint16_t pad = (f % 15u == 0u) ? OB_BTN_A : 0x0000u;
        uint16_t out = ob_input_step_frame(&mouse, wram_cand, ppu_oam, pad, f);
        assert(out == pad);
    }

    assert(memcmp(wram_ref, wram_cand, OB_WRAM_SIZE) == 0);
    printf("[PASS] Gate 2A: Zero-Invasion Idle Lockstep (0-byte WRAM drift across 1,000 frames)\n");

    free(wram_ref);
    free(wram_cand);
}

/* =========================================================================
 * Gate 2B: Pillar 1 — Tactical Map 1:1 Direct-State, Snap & Decoupled Camera
 * ========================================================================= */
static void test_gate_2b_pillar1_tactical_map(void) {
    uint8_t *wram = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));
    assert(wram != NULL);

    /* Configure active Tactical Battlefield Map state ($14E6 = 0xC0, $00CE = 0) */
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0xC0u;
    wram[OB_WRAM_CAM_STATE]        = 0x00u;
    wram[OB_WRAM_OAM1_Y]           = OB_OAM_OFFSCREEN_Y;

    write_u16(wram, OB_WRAM_CAM_X, 300u);
    write_u16(wram, OB_WRAM_CAM_Y, 200u);
    write_u16(wram, OB_WRAM_CAM_WORLD_X, 300u);
    write_u16(wram, OB_WRAM_CAM_WORLD_Y, 200u);
    write_u16(wram, OB_WRAM_CAM_MIN_X, 0u);
    write_u16(wram, OB_WRAM_CAM_MIN_Y, 0u);
    write_u16(wram, OB_WRAM_CAM_MAX_X, 1024u);
    write_u16(wram, OB_WRAM_CAM_MAX_Y, 1024u);
    write_u16(wram, OB_WRAM_MAP_TILES_X, 128u);
    write_u16(wram, OB_WRAM_MAP_TILES_Y, 128u);
    write_u16(wram, OB_WRAM_CUR_SCREEN_X, 128u);
    write_u16(wram, OB_WRAM_CUR_SCREEN_Y, 112u);
    write_u16(wram, OB_WRAM_CUR_EDGE_MASK, 0x0003u); /* Pre-dirty $14E7 to verify clearing */

    /* Mark all squads/cities inactive (0xFFFF) initially */
    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        write_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2), 0xFFFFu);
        write_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2), 0xFFFFu);
    }
    for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
        write_u16(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2), 0xFFFFu);
        write_u16(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2), 0xFFFFu);
    }

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_4_3, OB_VIEWPORT_HEIGHT);

    /* 1. Move mouse to (240, 195) in 1:1 256x224 window (outside old inner box, inside 10px margin) */
    ob_input_on_mouse_move(&mouse, 240, 195, 256, 224, 10u);
    uint16_t joy = ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 10u);

    assert(mouse.mouse_active);
    assert(mouse.active_mode == OB_MOUSE_MODE_TACTICAL_MAP);
    assert((joy & OB_BTN_DPAD_MASK) == 0u); /* Zero synthetic D-Pad injection! */
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_X) == 240u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_Y) == 195u);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_X) == 300u + 240u);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_Y) == 200u + 195u);
    assert(read_u16(wram, OB_WRAM_CUR_EDGE_MASK) == 0x0000u); /* $14E7 cleared! */
    /* Camera MUST NOT scroll during interior hover! */
    assert(read_u16(wram, OB_WRAM_CAM_X) == 300u);
    assert(read_u16(wram, OB_WRAM_CAM_Y) == 200u);

    /* 2. Test +-8px Magnetic Entity Snapping to Deployed Squad #0 at world (450, 310) */
    write_u16(wram, OB_WRAM_SQUAD_X_BASE + 0u, 450u);
    write_u16(wram, OB_WRAM_SQUAD_Y_BASE + 0u, 310u);
    /* Move mouse to screen (145, 106) -> world (445, 306), which is (-5, -4) from Squad #0 */
    ob_input_on_mouse_move(&mouse, 145, 106, 256, 224, 11u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 11u);
    assert(mouse.snapped_type == OB_SNAP_SQUAD);
    assert(mouse.snapped_index == 0);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_X) == 450u);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_Y) == 310u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_X) == 150u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_Y) == 110u);

    /* 3. Test Right-Click Grab-Drag Camera Panning */
    ob_input_on_mouse_button(&mouse, false, true, false, 12u); /* Right button down at (145, 106) */
    ob_input_on_mouse_move(&mouse, 125, 86, 256, 224, 13u);     /* Drag pointer by (-20, -20) */
    joy = ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 13u);
    assert(mouse.drag_active && mouse.drag_moved);
    assert(read_u16(wram, OB_WRAM_CAM_X) == 320u); /* Camera panned +20 in X */
    assert(read_u16(wram, OB_WRAM_CAM_Y) == 220u); /* Camera panned +20 in Y */

    /* Releasing Right-Click after a drag MUST NOT fire Joypad B (cancel) */
    ob_input_on_mouse_button(&mouse, false, false, false, 14u);
    joy = ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 14u);
    assert((joy & OB_BTN_B) == 0u);

    /* A clean Right-Click tap without dragging MUST fire Joypad B */
    ob_input_on_mouse_button(&mouse, false, true, false, 15u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 15u);
    ob_input_on_mouse_button(&mouse, false, false, false, 16u);
    joy = ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 16u);
    assert((joy & OB_BTN_B) == OB_BTN_B);

    printf("[PASS] Gate 2B: Pillar 1 Tactical Map 1:1 Cursor, +-8px Squad Snap & Decoupled Camera\n");
    free(wram);
}

/* =========================================================================
 * Gate 2C: Pillar 2 — 7-Icon Command Bar & 3x2 Formation Grid Hit-Boxes
 * ========================================================================= */
static void test_gate_2c_pillar2_menu_hitboxes(void) {
    uint8_t *wram = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));
    assert(wram != NULL);

    /* Configure 7-Icon Horizontal Command Strip (OAM[1] tile=0xCE, y=119) */
    wram[OB_WRAM_OAM1_X]    = 75u;
    wram[OB_WRAM_OAM1_Y]    = 119u;
    wram[OB_WRAM_OAM1_TILE] = OB_TILE_ICON_BAR_FINGER;
    wram[OB_WRAM_OAM1_ATTR] = 0x3Au;

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_4_3, OB_VIEWPORT_HEIGHT);

    /* Sweep across all 7 icons (slots 0..6) and verify deterministic slot indexing */
    for (int slot = 0; slot < OB_ICON_BAR_COUNT; ++slot) {
        int hover_x = OB_ICON_BAR_X0 + slot * OB_ICON_BAR_STRIDE + 5;
        int hover_y = 118;
        ob_input_on_mouse_move(&mouse, hover_x, hover_y, 256, 224, (uint32_t)(20 + slot));
        uint16_t joy = ob_input_step_frame(&mouse, wram, ppu_oam, 0u, (uint32_t)(20 + slot));

        assert(mouse.active_mode == OB_MOUSE_MODE_ICON_BAR);
        assert((joy & OB_BTN_DPAD_MASK) == 0u);
        assert(wram[OB_WRAM_ICON_BAR_INDEX] == (uint8_t)slot);
        assert(read_u16(wram, OB_WRAM_ICON_BAR_X) == (uint16_t)(71 + slot * 16));
        assert(wram[OB_WRAM_OAM1_X] == (uint8_t)(75 + slot * 16));
    }

    /* Move pointer far outside the icon bar (220, 40) for 120 frames:
     * Rev 8 spun 171 -> 75 every 7 frames here; Rev 9 must stay locked on slot 6! */
    ob_input_on_mouse_move(&mouse, 220, 40, 256, 224, 30u);
    for (uint32_t f = 30; f < 150; ++f) {
        uint16_t joy = ob_input_step_frame(&mouse, wram, ppu_oam, 0u, f);
        assert((joy & OB_BTN_DPAD_MASK) == 0u);
        assert(wram[OB_WRAM_ICON_BAR_INDEX] == 6u);
        assert(wram[OB_WRAM_OAM1_X] == 171u);
    }

    /* Now switch OAM[1] to 3x2 Formation Grid (tile=0xCC, y=64) */
    wram[OB_WRAM_OAM1_TILE] = OB_TILE_FORMATION_FINGER;
    wram[OB_WRAM_OAM1_Y]    = 64u;

    /* Hover Col 1, Row 2 (bottom-right cell of 3x2 grid: X=50, Y=78 -> slot 5) */
    ob_input_on_mouse_move(&mouse, 50, 78, 256, 224, 160u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 160u);
    assert(mouse.active_mode == OB_MOUSE_MODE_FORMATION_GRID);
    assert(wram[OB_WRAM_FORMATION_INDEX] == 5u);
    assert(wram[OB_WRAM_OAM1_X] == 38u);
    assert(wram[OB_WRAM_OAM1_Y] == 72u);

    printf("[PASS] Gate 2C: Pillar 2 7-Icon Bar & 3x2 Formation Grid Hit-Boxes (0 wrap-around)\n");
    free(wram);
}

/* =========================================================================
 * Gate 2D: Pillar 3 — Continental World Map & Hybrid Keyboard Handoff
 * ========================================================================= */
static void test_gate_2d_pillar3_world_map_and_hybrid(void) {
    uint8_t *wram = (uint8_t *)calloc(OB_WRAM_SIZE, 1);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));
    assert(wram != NULL);

    /* Configure Continental World Map state (matching Frame 8610 in task-4440.log):
     * WRAM[$0100..$013F] has Y=0xE0 sentinel, PPU OAM[27] has stage banner at (128, 63) */
    wram[OB_WRAM_OAM1_Y]           = OB_OAM_OFFSCREEN_Y;
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0x00u;

    ppu_oam[27 * 4 + 0] = 128u; /* X = 128 */
    ppu_oam[27 * 4 + 1] = 63u;  /* Y = 63 */
    ppu_oam[27 * 4 + 2] = 0x64u;
    ppu_oam[27 * 4 + 3] = 0x38u;

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_4_3, OB_VIEWPORT_HEIGHT);

    /* Hover over Stage Banner OAM[27] at (132, 68) */
    ob_input_on_mouse_move(&mouse, 132, 68, 256, 224, 200u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 200u);

    assert(mouse.active_mode == OB_MOUSE_MODE_WORLD_MAP);
    assert(mouse.hovered_slot == (27 - 24));
    assert(wram[OB_WRAM_WORLD_NODE_INDEX] == 3u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_X) == 136u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_Y) == 71u);

    /* Test Hybrid Input Priority: pressing physical D-Pad Right immediately yields to keyboard */
    uint16_t joy = ob_input_step_frame(&mouse, wram, ppu_oam, OB_BTN_RIGHT, 205u);
    assert(joy == OB_BTN_RIGHT);
    assert(!mouse.mouse_active);
    assert(mouse.active_mode == OB_MOUSE_MODE_PASSIVE);

    /* After keyboard cooldown (18 frames), moving mouse >= 2px wakes pointer control */
    ob_input_on_mouse_move(&mouse, 135, 70, 256, 224, 205u + OB_KEYBOARD_COOLDOWN_FRAMES);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 205u + OB_KEYBOARD_COOLDOWN_FRAMES);
    assert(mouse.mouse_active);
    assert(mouse.active_mode == OB_MOUSE_MODE_WORLD_MAP);

    printf("[PASS] Gate 2D: Pillar 3 Continental World Map Stage Node Hit-Testing & Hybrid Priority\n");
    free(wram);
}

/* =========================================================================
 * Gate 2E: LakeSnes 0x55 Guard, Live $14E6=0x00 Tactical & OAM[1] World Map
 * ========================================================================= */
static void test_gate_2e_uninit_wram_and_live_maps(void) {
    uint8_t *wram = (uint8_t *)malloc(OB_WRAM_SIZE);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    assert(wram != NULL);
    memset(wram, 0x55, OB_WRAM_SIZE);
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_16_9, OB_VIEWPORT_HEIGHT);
    ob_input_set_wings_enabled(&mouse, true);

    /* 1. Uninitialized 0x55 WRAM must stay PASSIVE in core area (not false Tactical Map) */
    ob_input_on_mouse_move(&mouse, 180, 100, 400, 224, 10u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 10u);
    assert(mouse.active_mode == OB_MOUSE_MODE_PASSIVE);

    /* 2. Live Tactical Map with $14E6=0x00 (cursor visible) must detect TACTICAL_MAP */
    wram[0x00CBu]                  = 0x01u;
    wram[0x00CCu]                  = 0x10u;
    wram[OB_WRAM_CAM_STATE]        = 0x00u;
    wram[0x07BAu]                  = 0x4Fu;
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0x00u;
    write_u16(wram, OB_WRAM_CAM_X, 0u);
    write_u16(wram, OB_WRAM_CAM_Y, 0u);
    write_u16(wram, OB_WRAM_MAP_TILES_X, 64u);
    write_u16(wram, OB_WRAM_MAP_TILES_Y, 64u);
    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        write_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2), 0xFFFFu);
        write_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2), 0xFFFFu);
    }
    for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
        write_u16(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2), 0xFFFFu);
        write_u16(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2), 0xFFFFu);
    }
    ob_input_on_mouse_move(&mouse, 180, 120, 400, 224, 11u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 11u);
    assert(mouse.active_mode == OB_MOUSE_MODE_TACTICAL_MAP);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_X) == 108u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_Y) == 120u);

    /* 3. Live World Map with $14E6=0x55 and stage banner in OAM[1] */
    memset(wram, 0x55, OB_WRAM_SIZE);
    wram[0x00CBu] = 0x03u;
    wram[0x07BAu] = 0xFFu;
    write_u16(wram, 0x07A2u, 0x0008u);
    ppu_oam[1 * 4 + 0] = 104u;
    ppu_oam[1 * 4 + 1] = 95u;
    ppu_oam[1 * 4 + 2] = 0x40u;
    ppu_oam[1 * 4 + 3] = 0x38u;
    ob_input_on_mouse_move(&mouse, 180, 99, 400, 224, 12u); /* core_x=108, y=99 */
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 12u);
    assert(mouse.active_mode == OB_MOUSE_MODE_WORLD_MAP);
    assert(mouse.hovered_slot == 0);

    printf("[PASS] Gate 2E: LakeSnes 0x55 Guard, Live $14E6=0x00 Tactical & OAM[1] World Map\n");
    free(wram);
}

/* =========================================================================
 * Gate 2F: Live Bank $00 12.4 Subpixels, $14ED/$1517 Projection & Bank $02 Menus
 * (Regression test for GitHub Issue #7)
 * ========================================================================= */
static void test_gate_2f_live_subpixels_and_bank02_menus(void) {
    uint8_t *wram = (uint8_t *)malloc(OB_WRAM_SIZE);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    assert(wram != NULL);
    memset(wram, 0x55, OB_WRAM_SIZE);
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_16_9, OB_VIEWPORT_HEIGHT);
    ob_input_set_wings_enabled(&mouse, true);

    /* 1. Configure live Tutorial Stage 1 (Felnamia) tactical state at Frame 9525:
     *    - $00CB = 0x01, $00CC = 0x10, $00CE = 0x00, $07BA = 0x4F, $14E6 = 0x00
     *    - Camera ($00BD = 116, $00BF = 339), Map tiles ($14D3 = 48, $14D5 = 48 -> 383x383 px)
     *    - Squad 0 in 12.4 subpixels: $18AF = 3904 (244 px), $18D9 = 5760 (360 px)
     *    - Mode-7 projected screen coords ($00:B7C0): $14ED = 121, $1517 = 101
     *    - City 0 in 12.4 subpixels: $1A95 = 3712 (232 px), $1B0D = 5632 (352 px) */
    wram[0x00CBu]                  = 0x01u;
    wram[0x00CCu]                  = 0x10u;
    wram[OB_WRAM_CAM_STATE]        = 0x00u;
    wram[0x07BAu]                  = 0x4Fu;
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0x00u;
    wram[OB_WRAM_MENU_SLOT_COUNT]  = 0x00u;
    wram[OB_WRAM_OAM1_Y]           = 112u;
    wram[OB_WRAM_OAM1_TILE]        = 0x64u;
    write_u16(wram, OB_WRAM_CAM_X, 116u);
    write_u16(wram, OB_WRAM_CAM_Y, 339u);
    write_u16(wram, OB_WRAM_MAP_TILES_X, 48u);
    write_u16(wram, OB_WRAM_MAP_TILES_Y, 48u);

    for (int i = 0; i < OB_MAX_DEPLOYED_SQUADS; ++i) {
        write_u16(wram, OB_WRAM_SQUAD_X_BASE + (uint32_t)(i * 2), 0x7FFFu);
        write_u16(wram, OB_WRAM_SQUAD_Y_BASE + (uint32_t)(i * 2), 0x7FFFu);
        write_u16(wram, OB_WRAM_SQUAD_SCREEN_X_BASE + (uint32_t)(i * 2), 0xFE89u);
        write_u16(wram, OB_WRAM_SQUAD_SCREEN_Y_BASE + (uint32_t)(i * 2), 0xFF2Bu);
    }
    for (int j = 0; j < OB_MAX_STAGE_CITIES; ++j) {
        write_u16(wram, OB_WRAM_CITY_X_BASE + (uint32_t)(j * 2), 0x7FFFu);
        write_u16(wram, OB_WRAM_CITY_Y_BASE + (uint32_t)(j * 2), 0x7FFFu);
    }

    write_u16(wram, OB_WRAM_SQUAD_X_BASE + 0u, 3904u); /* 244 << 4 */
    write_u16(wram, OB_WRAM_SQUAD_Y_BASE + 0u, 5760u); /* 360 << 4 */
    write_u16(wram, OB_WRAM_SQUAD_SCREEN_X_BASE + 0u, 121u);
    write_u16(wram, OB_WRAM_SQUAD_SCREEN_Y_BASE + 0u, 101u);

    write_u16(wram, OB_WRAM_CITY_X_BASE + 0u, 3712u);  /* 232 << 4 */
    write_u16(wram, OB_WRAM_CITY_Y_BASE + 0u, 5632u);  /* 352 << 4 */

    /* Hover near Squad 0's projected screen center (121+7=128, 101+11=112 -> snes_x = 72+125=197, y = 110) */
    ob_input_on_mouse_move(&mouse, 197, 110, 400, 224, 20u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 20u);
    assert(mouse.active_mode == OB_MOUSE_MODE_TACTICAL_MAP);
    assert(mouse.snapped_type == OB_SNAP_SQUAD);
    assert(mouse.snapped_index == 0);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_X) == 244u);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_Y) == 360u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_X) == 128u);
    assert(read_u16(wram, OB_WRAM_CUR_SCREEN_Y) == 112u);

    /* Left Wing click on Squad 0 with 12.4 subpixel coordinates must center camera on (244, 360) */
    ob_input_on_mouse_move(&mouse, 30, 25, 400, 224, 21u);
    ob_input_on_mouse_button(&mouse, true, false, false, 21u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 21u);
    assert(mouse.active_mode == OB_MOUSE_MODE_LEFT_WING);
    assert(read_u16(wram, OB_WRAM_CAM_X) == 244u - 128u);
    assert(read_u16(wram, OB_WRAM_CAM_Y) == 360u - 112u);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_X) == 244u);
    assert(read_u16(wram, OB_WRAM_CUR_WORLD_Y) == 360u);
    ob_input_on_mouse_button(&mouse, false, false, false, 22u);

    /* 2. Live Bank $02 Squad Command Strip & 3x2 Formation Grid ($02:EC90-$02:F190, Frame 9613):
     *    - $14E6 = 0x80 (battlefield cursor hidden while menu open)
     *    - OAM[1] uses live tile 0x6A at Y=119 (or 0x68 in formation grid)
     *    - $0424 = 9 active slots:
     *        Slots 0..4: Formation grid units ($04B2 = 0xFF)
     *        Slots 5..7: 3-icon command strip at X = {103, 119, 135}, Y = 109 ($04B2 = {0, 2, 5})
     *        Slot 8:     Squad header at X = 88, Y = 38 ($04B2 = 0x80) */
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0x80u;
    wram[0x04E0u]                  = 0x01u;
    wram[OB_WRAM_MENU_SLOT_COUNT]  = 9u;
    wram[OB_WRAM_ICON_BAR_INDEX]   = 5u;
    wram[OB_WRAM_OAM1_X]           = 107u;
    wram[OB_WRAM_OAM1_Y]           = 119u;
    wram[OB_WRAM_OAM1_TILE]        = OB_TILE_LIVE_ICON_BAR_FINGER; /* 0x6A */

    const uint8_t slot_x[9] = { 128, 96, 96, 96, 128, 103, 119, 135, 88 };
    const uint8_t slot_y[9] = {  76, 52, 68, 84,  60, 109, 109, 109, 38 };
    const uint8_t slot_t[9] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x02, 0x05, 0x80 };
    for (int i = 0; i < 9; ++i) {
        wram[OB_WRAM_MENU_SLOT_X_BASE + i]    = slot_x[i];
        wram[OB_WRAM_MENU_SLOT_Y_BASE + i]    = slot_y[i];
        wram[OB_WRAM_MENU_SLOT_TYPE_BASE + i] = slot_t[i];
    }

    /* Hover over Command Icon slot 7 (core_x = 138 -> snes_x = 72 + 138 = 210, snes_y = 118) */
    ob_input_on_mouse_move(&mouse, 210, 118, 400, 224, 25u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 25u);
    assert(mouse.active_mode == OB_MOUSE_MODE_ICON_BAR);
    assert(wram[OB_WRAM_ICON_BAR_INDEX] == 7u);
    assert(wram[OB_WRAM_ICON_BAR_X] == 135u);
    assert(wram[OB_WRAM_ICON_BAR_Y] == 109u);
    assert(wram[OB_WRAM_OAM1_X] == 139u);
    assert(wram[OB_WRAM_OAM1_Y] == 119u);
    assert(wram[OB_WRAM_OAM1_TILE] == OB_TILE_LIVE_ICON_BAR_FINGER);

    /* Hover directly up into Formation Grid slot 1 (core_x = 98 -> snes_x = 72 + 98 = 170, snes_y = 52) */
    ob_input_on_mouse_move(&mouse, 170, 52, 400, 224, 26u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 26u);
    assert(wram[OB_WRAM_ICON_BAR_INDEX] == 1u);
    assert(wram[OB_WRAM_FORMATION_INDEX] == 1u);
    assert(wram[OB_WRAM_OAM1_X] == 86u);
    assert(wram[OB_WRAM_OAM1_Y] == 52u);
    assert(wram[OB_WRAM_OAM1_TILE] == OB_TILE_LIVE_FORMATION_FINGER); /* Switched to 0x68 */

    /* Next frame in formation grid detects OB_MOUSE_MODE_FORMATION_GRID and allows hovering back to icon bar */
    ob_input_on_mouse_move(&mouse, 195, 118, 400, 224, 27u); /* core_x = 123 -> slot 6 (X=119) */
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 27u);
    assert(mouse.active_mode == OB_MOUSE_MODE_FORMATION_GRID);
    assert(wram[OB_WRAM_ICON_BAR_INDEX] == 6u);
    assert(wram[OB_WRAM_OAM1_X] == 123u);
    assert(wram[OB_WRAM_OAM1_Y] == 119u);
    assert(wram[OB_WRAM_OAM1_TILE] == OB_TILE_LIVE_ICON_BAR_FINGER);

    printf("[PASS] Gate 2F: Live Bank $00 12.4 Subpixels, $14ED/$1517 Projection & Bank $02 Menu Slots\n");
    free(wram);
}

/* =========================================================================
 * Gate 2G: Live World Map Sword ($0441/$04A1 + OAM[0]=0x6E), Signed Camera
 *          Bounds ($14CB/$14CD < 0), Edge-Pan Config & 3-Frame Click Pulses
 * ========================================================================= */
static void test_gate_2g_world_map_sword_signed_cam_and_pulses(void) {
    uint8_t *wram = (uint8_t *)malloc(OB_WRAM_SIZE);
    uint8_t  ppu_oam[OB_PPU_OAM_SIZE];
    assert(wram != NULL);
    memset(wram, 0x55, OB_WRAM_SIZE);
    memset(ppu_oam, 0xE0, sizeof(ppu_oam));

    ObMouseState mouse;
    ob_input_init(&mouse, OB_VIEWPORT_WIDTH_16_9, OB_VIEWPORT_HEIGHT);
    ob_input_set_wings_enabled(&mouse, true);

    /* 1. Live World Map right after Warren's Quiz (Frame 8680):
     *    $00CB=0x01, $00CC=0x10, $00CE=0x55 (uninit), $07BA=0x4F, $14E6=0xC0,
     *    OAM[0]=(200,108,tile=0x6E), OAM[1]=(18,185,tile=0x68 scroll border), $0424=0 */
    wram[0x00CBu]                  = 0x01u;
    wram[0x00CCu]                  = 0x10u;
    wram[OB_WRAM_CAM_STATE]        = 0x55u;
    wram[0x07BAu]                  = 0x4Fu;
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0xC0u;
    wram[OB_WRAM_MENU_SLOT_COUNT]  = 0x00u;
    wram[OB_WRAM_OAM0_X]           = 200u;
    wram[OB_WRAM_OAM0_Y]           = 108u;
    wram[OB_WRAM_OAM0_TILE]        = OB_TILE_WORLD_MAP_SWORD; /* 0x6E */
    wram[OB_WRAM_OAM1_X]           = 18u;
    wram[OB_WRAM_OAM1_Y]           = 185u;
    wram[OB_WRAM_OAM1_TILE]        = 0x68u;
    wram[OB_WRAM_WORLD_CUR_X]      = 200u;
    wram[OB_WRAM_WORLD_CUR_Y]      = 108u;

    /* Hover core (100, 80) -> snes_x = 172, snes_y = 80 */
    ob_input_on_mouse_move(&mouse, 172, 80, 400, 224, 10u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 10u);
    assert(mouse.active_mode == OB_MOUSE_MODE_WORLD_MAP);
    assert(wram[OB_WRAM_WORLD_CUR_X] == 100u);
    assert(wram[OB_WRAM_WORLD_CUR_Y] == 80u);
    assert(wram[OB_WRAM_OAM0_X] == 100u);
    assert(wram[OB_WRAM_OAM0_Y] == 80u);
    /* Must not corrupt uninitialized $00BD/$00BF (0x5555) */
    assert(read_u16(wram, OB_WRAM_CAM_X) == 0x5555u);
    assert(read_u16(wram, OB_WRAM_CAM_Y) == 0x5555u);

    /* Returning to World Map after a stage ($00CE=0x00) must still detect WORLD_MAP and clamp to scroll */
    wram[OB_WRAM_CAM_STATE] = 0x00u;
    ob_input_on_mouse_move(&mouse, 80, 10, 400, 224, 11u); /* core_x=8 -> clamp 50, y=10 -> clamp 32 */
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 11u);
    assert(mouse.active_mode == OB_MOUSE_MODE_WORLD_MAP);
    assert(wram[OB_WRAM_WORLD_CUR_X] == OB_WORLD_MAP_MIN_X);
    assert(wram[OB_WRAM_WORLD_CUR_Y] == OB_WORLD_MAP_MIN_Y);

    /* 2. Signed int16_t Tactical Map Camera Bounds ($14CB=-128, $14CD=-21) & Edge-Pan Config */
    wram[OB_WRAM_OAM0_Y]           = OB_OAM_OFFSCREEN_Y;
    wram[OB_WRAM_OAM0_TILE]        = 0x01u;
    wram[OB_WRAM_CUR_SPRITE_FLAGS] = 0x00u;
    write_u16(wram, OB_WRAM_CAM_X, (uint16_t)(int16_t)(-10));
    write_u16(wram, OB_WRAM_CAM_Y, (uint16_t)(int16_t)(-5));
    write_u16(wram, OB_WRAM_CAM_MIN_X, (uint16_t)(int16_t)(-128));
    write_u16(wram, OB_WRAM_CAM_MIN_Y, (uint16_t)(int16_t)(-21));
    write_u16(wram, OB_WRAM_CAM_MAX_X, 384u);
    write_u16(wram, OB_WRAM_CAM_MAX_Y, 491u);
    write_u16(wram, OB_WRAM_MAP_TILES_X, 64u);
    write_u16(wram, OB_WRAM_MAP_TILES_Y, 64u);

    /* Disable edge pan: hovering top edge (y=2) must NOT move camera */
    ob_input_set_edge_pan(&mouse, false, 6);
    ob_input_on_mouse_move(&mouse, 200, 2, 400, 224, 12u);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 12u);
    assert(mouse.active_mode == OB_MOUSE_MODE_TACTICAL_MAP);
    assert((int16_t)read_u16(wram, OB_WRAM_CAM_Y) == -5);

    /* Enable edge pan at speed 6: hovering top edge must pan -5 -> -11 (preserving negative signed bounds!) */
    ob_input_set_edge_pan(&mouse, true, 6);
    ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 13u);
    assert((int16_t)read_u16(wram, OB_WRAM_CAM_Y) == -11);

    /* 3. Multi-Frame Click Pulse (OB_CLICK_PULSE_FRAMES = 5f) for World Map stage entry */
    ob_input_on_mouse_move(&mouse, 200, 100, 400, 224, 20u);
    ob_input_on_mouse_button(&mouse, true, false, false, 20u);
    assert((ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 20u) & OB_BTN_A) == OB_BTN_A);
    ob_input_on_mouse_button(&mouse, false, false, false, 21u);
    for (uint32_t k = 1u; k < OB_CLICK_PULSE_FRAMES; ++k) {
        assert((ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 20u + k) & OB_BTN_A) == OB_BTN_A);
    }
    assert((ob_input_step_frame(&mouse, wram, ppu_oam, 0u, 20u + OB_CLICK_PULSE_FRAMES) & OB_BTN_A) == 0u);

    printf("[PASS] Gate 2G: World Map Sword ($0441/$04A1), Signed Camera Bounds, Edge-Pan & Click Pulses\n");
    free(wram);
}

int main(void) {
    printf("====================================================================\n");
    printf(" Ogre Battle PC: Gate 2 Three-Pillar Mouse Architecture Verification\n");
    printf("====================================================================\n");

    test_gate_2a_zero_invasion_lockstep();
    test_gate_2b_pillar1_tactical_map();
    test_gate_2c_pillar2_menu_hitboxes();
    test_gate_2d_pillar3_world_map_and_hybrid();
    test_gate_2e_uninit_wram_and_live_maps();
    test_gate_2f_live_subpixels_and_bank02_menus();
    test_gate_2g_world_map_sword_signed_cam_and_pulses();

    printf("====================================================================\n");
    printf(" ALL GATE 2 THREE-PILLAR MOUSE ARCHITECTURE TESTS PASSED (100%%)\n");
    printf("====================================================================\n");
    return 0;
}
