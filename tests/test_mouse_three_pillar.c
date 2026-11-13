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

int main(void) {
    printf("====================================================================\n");
    printf(" Ogre Battle PC: Gate 2 Three-Pillar Mouse Architecture Verification\n");
    printf("====================================================================\n");

    test_gate_2a_zero_invasion_lockstep();
    test_gate_2b_pillar1_tactical_map();
    test_gate_2c_pillar2_menu_hitboxes();
    test_gate_2d_pillar3_world_map_and_hybrid();

    printf("====================================================================\n");
    printf(" ALL GATE 2 THREE-PILLAR MOUSE ARCHITECTURE TESTS PASSED (100%%)\n");
    printf("====================================================================\n");
    return 0;
}
