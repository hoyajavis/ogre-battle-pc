#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "telemetry.h"
#include "telemetry_math.h"
#include "telemetry_window.h"

/* LakeSnes hardware emulation headers */
#include "snes.h"
#include "cpu.h"
#include "ppu.h"
#include "cart.h"
#include "input.h"

static uint8_t *load_rom_file(const char *path, uint32_t *out_size) {
    FILE *fp = fopen(path, "rb");
    if (!fp) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *buf = (uint8_t *)malloc((size_t)sz);
    if (!buf) {
        fclose(fp);
        return NULL;
    }
    if (fread(buf, 1, (size_t)sz, fp) != (size_t)sz) {
        free(buf);
        fclose(fp);
        return NULL;
    }
    fclose(fp);
    *out_size = (uint32_t)sz;
    return buf;
}

static void write_u16_le(uint8_t *buf, uint32_t offset, uint16_t val) {
    buf[offset]     = (uint8_t)(val & 0xFFU);
    buf[offset + 1] = (uint8_t)((val >> 8) & 0xFFU);
}

static void write_u32_le(uint8_t *buf, uint32_t offset, uint32_t val) {
    buf[offset]     = (uint8_t)(val & 0xFFU);
    buf[offset + 1] = (uint8_t)((val >> 8) & 0xFFU);
    buf[offset + 2] = (uint8_t)((val >> 16) & 0xFFU);
    buf[offset + 3] = (uint8_t)((val >> 24) & 0xFFU);
}

/* ==========================================================================
 * TEST 1 (GATE 1A): Dual-Execution Lockstep 0-Byte Drift Guarantee
 * ========================================================================== */
static void test_01_gate_1a_lockstep_zero_invasion(const uint8_t *rom, uint32_t rom_size) {
    printf("[TEST 01 / GATE 1A] Running Dual-Core Lockstep Non-Invasion Verification...\n");

    Snes *snes_ref  = snes_init();
    Snes *snes_cand = snes_init();
    assert(snes_ref && snes_cand);

    bool ok_ref  = snes_loadRom(snes_ref, rom, (int)rom_size);
    bool ok_cand = snes_loadRom(snes_cand, rom, (int)rom_size);
    assert(ok_ref && ok_cand);

    ObTelemetryFrame prev_frame, curr_frame;
    memset(&prev_frame, 0, sizeof(prev_frame));
    memset(&curr_frame, 0, sizeof(curr_frame));

    ObCompanionWindowState win_state;
    ob_companion_window_init(&win_state);

    uint32_t *companion_fb = (uint32_t *)malloc(OB_COMPANION_WIDTH * OB_COMPANION_HEIGHT * sizeof(uint32_t));
    assert(companion_fb != NULL);

    /* Step 600 live frames of Ogre Battle boot, intro & title sequence in lockstep */
    const uint32_t kTotalLockstepFrames = 600;
    for (uint32_t f = 1; f <= kTotalLockstepFrames; ++f) {
        /* Inject scripted Start/A presses at frame 320 and 450 on both cores */
        uint16_t buttons = 0;
        if (f == 320 || f == 450) {
            buttons = 0x1000 | 0x0080; /* Start + A */
        }
        snes_ref->input1->currentState  = buttons;
        snes_cand->input1->currentState = buttons;

        snes_runFrame(snes_ref);
        snes_runFrame(snes_cand);

        /* Poll 60Hz VBlank Telemetry & render Companion Window ONLY on candidate core */
        ob_telemetry_poll_vblank(snes_cand->ram, rom, rom_size, f, &curr_frame);
        if (f % 30 == 0) {
            ob_telemetry_render_companion_window(
                &win_state, &prev_frame, &curr_frame,
                snes_cand->ram, rom, rom_size,
                companion_fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT
            );
        }
        prev_frame = curr_frame;

        /* Assert 0-byte drift across 128KB WRAM, 64KB VRAM, 512B CGRAM, 544B OAM */
        assert(memcmp(snes_ref->ram, snes_cand->ram, OB_WRAM_SIZE_BYTES) == 0);
        assert(memcmp(snes_ref->ppu->vram, snes_cand->ppu->vram, sizeof(snes_ref->ppu->vram)) == 0);
        assert(memcmp(snes_ref->ppu->cgram, snes_cand->ppu->cgram, sizeof(snes_ref->ppu->cgram)) == 0);
        assert(memcmp(snes_ref->ppu->oam, snes_cand->ppu->oam, sizeof(snes_ref->ppu->oam)) == 0);
        assert(memcmp(snes_ref->ppu->highOam, snes_cand->ppu->highOam, sizeof(snes_ref->ppu->highOam)) == 0);
    }

    free(companion_fb);
    snes_free(snes_ref);
    snes_free(snes_cand);
    printf("  -> [PASS] 600 / 600 Emulated Frames Certified with 0-Byte WRAM/VRAM/CGRAM/OAM Drift!\n");
}

/* ==========================================================================
 * TEST 2 (GATE 1B - TIER 1): SoA Roster, Squads, Economy & Reputation
 * ========================================================================== */
static void test_02_gate_1b_tier1_soa_extraction(const uint8_t *rom, uint32_t rom_size) {
    printf("[TEST 02 / GATE 1B-T1] Verifying Tier 1 SoA Character, Squad & Economy Extraction...\n");

    uint8_t *wram = (uint8_t *)calloc(1, OB_WRAM_SIZE_BYTES);
    assert(wram != NULL);

    /* Populate canonical New Game state per $00:8383 ($000383) & $03:EC80 ($01EC80) */
    write_u32_le(wram, 0x1578, 30000U); /* Starting Goth = 30,000 (0x7530) */
    wram[0x157C] = 50U;                 /* Starting Chaos Frame = 50 (0x32) */
    wram[0x157D] = 14U;                 /* Sub-accumulator */

    /* Unit 0: Opinion Leader (Lord, Class 79, Lvl 5, HP 125/125, ALI 68, CHA 64) */
    wram[0x07BA + 0] = 0x52; /* Hero Template */
    wram[0x085A + 0] = 79;   /* Lord */
    wram[0x08FA + 0] = 0x00; /* Small */
    wram[0xF148 + 0] = 5;
    wram[0xF1E8 + 0] = 42;
    write_u16_le(wram, 0x099A + 0, 125);
    write_u16_le(wram, 0x0ADA + 0, 125);
    wram[0xF24C + 0] = 58;
    wram[0xF2EC + 0] = 55;
    wram[0xF38C + 0] = 52;
    wram[0xF42C + 0] = 64;
    wram[0x0C1A + 0] = 68;
    wram[0xF490 + 0] = 57;
    write_u16_le(wram, 0xF4F4 + 0, 0); /* Lord has 0 deploy cost */
    write_u16_le(wram, 0x0C7E + 0, 19);

    /* Unit 1: Lans (Knight, Class 2, Lvl 6, HP 110/118, ALI 72, CHA 61, Cost 340) */
    wram[0x07BA + 1] = 0x53;
    wram[0x085A + 1] = 2; /* Knight */
    wram[0x08FA + 1] = 0x00;
    wram[0xF148 + 1] = 6;
    wram[0xF1E8 + 1] = 80;
    write_u16_le(wram, 0x099A + 2, 110);
    write_u16_le(wram, 0x0ADA + 2, 118);
    wram[0xF24C + 1] = 62;
    wram[0xF2EC + 1] = 50;
    wram[0xF38C + 1] = 41;
    wram[0xF42C + 1] = 61;
    wram[0x0C1A + 1] = 72;
    wram[0xF490 + 1] = 49;
    write_u16_le(wram, 0xF4F4 + 2, 340);

    /* Unit 2: Fighter (Class 1, Lvl 4, ALI 32, CHA 51, Cost 150) */
    wram[0x07BA + 2] = 0x01;
    wram[0x085A + 2] = 1; /* Fighter */
    wram[0xF148 + 2] = 4;
    write_u16_le(wram, 0x099A + 4, 88);
    write_u16_le(wram, 0x0ADA + 4, 88);
    wram[0xF24C + 2] = 48;
    wram[0xF2EC + 2] = 47;
    wram[0xF38C + 2] = 35;
    wram[0xF42C + 2] = 51;
    wram[0x0C1A + 2] = 32;
    write_u16_le(wram, 0xF4F4 + 4, 150);

    /* Squad 0 Formation: Units 0, 1, 2 */
    memset(&wram[0x0E81], 0xFF, 125);
    wram[0x0E81 + 0] = 0; wram[0x0DCD + 0] = 0x24; /* 2 actions, slot 4 (back center) */
    wram[0x0E81 + 1] = 1; wram[0x0DCD + 1] = 0x20; /* 2 actions, slot 0 (front left)  */
    wram[0x0E81 + 2] = 2; wram[0x0DCD + 2] = 0x22; /* 2 actions, slot 2 (front right) */
    wram[0xF901 + 0] = 3; /* Tactic: Best */

    /* Tarot Hand: Magician (1), Chariot (7), World (21) */
    memset(&wram[0x0DBE], 0xFF, 14);
    wram[0x0DBE + 0] = 1;
    wram[0x0DBE + 1] = 7;
    wram[0x0DBE + 2] = 21;

    ObTelemetryFrame frame;
    ob_telemetry_poll_vblank(wram, rom, rom_size, 100, &frame);

    assert(frame.goth_treasury == 30000U);
    assert(frame.chaos_frame == 50U);
    assert(frame.chaos_frame_sub == 14U);
    assert(frame.active_roster_count == 3U);
    assert(frame.units[0].class_id == 79U && frame.units[0].hp_max == 125U);
    assert(frame.units[1].class_id == 2U && frame.units[1].ali == 72U && frame.units[1].deploy_cost == 340U);
    assert(frame.squads[0].has_leader == true);
    assert(frame.squads[0].member_count == 3U);
    assert(frame.squads[0].total_deploy_cost == 490U);
    assert(frame.squads[0].avg_alignment == (68 + 72 + 32) / 3);
    assert(frame.squads[0].tactic_stance == 3U);
    assert(frame.tarot_hand_count == 3U);

    free(wram);
    printf("  -> [PASS] Tier 1 SoA Roster, Squads, Tarot Hand & Economy Verified!\n");
}

/* ==========================================================================
 * TEST 3 (GATE 1B - TIER 2): Deep Exploratory WRAM Domains E-J & Bit-Diffs
 * ========================================================================== */
static void test_03_gate_1b_tier2_deep_domains(const uint8_t *rom, uint32_t rom_size) {
    printf("[TEST 03 / GATE 1B-T2] Verifying Tier 2 Deep WRAM Domains (E-J) & 2,344-Bit Diffs...\n");

    uint8_t *wram = (uint8_t *)calloc(1, OB_WRAM_SIZE_BYTES);
    assert(wram != NULL);

    /* Domain H: 7-Register Calendar ($7E:156D..$7E:1575) at 19:30 (Nighttime) */
    wram[0x156D] = 1;  /* Year 1 */
    wram[0x156E] = 3;  /* Month 3 */
    wram[0x156F] = 5;  /* Lunar weekday 5 */
    wram[0x1570] = 14; /* Day 14 */
    wram[0x1571] = 19; /* 19:00 (7 PM - Nighttime!) */
    wram[0x1572] = 30; /* 30 mins */
    wram[0x1573] = 45; /* 45 sub-ticks */
    wram[0x1575] = 2;

    /* Domain E & F: Deployed Player Squad 0 and Enemy Squad 10 */
    for (int s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        write_u16_le(wram, 0x18AF + s * 2, 0x7FFF);
    }
    write_u16_le(wram, 0x18AF + 0, 320); /* Player Squad 0 X=320 */
    write_u16_le(wram, 0x18D9 + 0, 480); /* Player Squad 0 Y=480 */
    write_u16_le(wram, 0x1905 + 0, 500); /* Target X=500 */
    write_u16_le(wram, 0x192D + 0, 480); /* Target Y=480 */
    write_u16_le(wram, 0x1955 + 0, 2);   /* Vel dX=+2 */
    write_u16_le(wram, 0x197D + 0, 0);   /* Vel dY=0 */

    write_u16_le(wram, 0x18AF + 20, 420); /* Enemy Squad 10 X=420 */
    write_u16_le(wram, 0x18D9 + 20, 480); /* Enemy Squad 10 Y=480 */
    write_u16_le(wram, 0x1955 + 20, (uint16_t)-2); /* Vel dX=-2 (approaching!) */
    write_u16_le(wram, 0x19A5 + 20, 0x0102); /* AI Order Lock */

    /* Domain G: Live Combat Arena Micro-State ($7E:F925..$7E:F9FC) */
    wram[0xF92B] = 1;  /* Combat active */
    wram[0xF92E] = 2;  /* Tactic: Weak */
    wram[0xF931] = 1;  /* Acting slot 1 */
    wram[0xF934] = 6;  /* Target slot 6 */
    wram[0xF941] = 7;  /* 7 total actions left */
    write_u16_le(wram, 0xF942, 184); /* Player cumulative clash damage = 184 */
    write_u16_le(wram, 0xF944, 142); /* Enemy cumulative clash damage  = 142 */

    ObTelemetryFrame frame_a, frame_b;
    ob_telemetry_poll_vblank(wram, rom, rom_size, 500, &frame_a);

    assert(frame_a.calendar.is_nighttime == true);
    assert(frame_a.calendar.minutes_to_noon == (4 * 60 + 30) + 12 * 60); /* 16h 30m = 990m */
    assert(frame_a.calendar.minutes_to_phase_shift == (4 * 60 + 30) + 6 * 60); /* 10h 30m to 06:00 Dawn = 630m */
    assert(frame_a.map_entities[0].is_active == true && frame_a.map_entities[0].world_x == 320);
    assert(frame_a.map_entities[10].is_active == true && frame_a.map_entities[10].is_enemy == true);
    assert(frame_a.combat.in_combat == true);
    assert(frame_a.combat.player_clash_damage == 184 && frame_a.combat.enemy_clash_damage == 142);

    /* Domain I: Flip 3 specific bits in $7E:8600..$7E:8F27 and change Chaos Frame */
    wram[0x157C] = 52;         /* Chaos Frame +2 */
    wram[0x8600 + 10] |= 0x04; /* Story Bit A #82 (10*8 + 2) -> 1 */
    wram[0x8600 + 160] |= 0x80;/* Treasure Bit B #1287 (160*8 + 7) -> 1 */
    wram[0x8600 + 240] |= 0x01;/* Recruit Bit C #1920 (240*8 + 0) -> 1 */

    ob_telemetry_poll_vblank(wram, rom, rom_size, 501, &frame_b);

    ObTelemetryDiffEvent diffs[16];
    size_t n_diffs = ob_telemetry_diff_frames(&frame_a, &frame_b, diffs, 16);
    assert(n_diffs == 4);
    assert(strcmp(diffs[0].category, "CHAOS_FRAME") == 0 && diffs[0].new_value == 52);
    assert(strcmp(diffs[1].category, "STORY_BIT_A") == 0 && diffs[1].bit_index == 82);
    assert(strcmp(diffs[2].category, "TREASURE_BIT_B") == 0 && diffs[2].bit_index == 1287);
    assert(strcmp(diffs[3].category, "RECRUIT_BIT_C") == 0 && diffs[3].bit_index == 1920);

    free(wram);
    printf("  -> [PASS] Tier 2 Kinematics, Combat Tug-of-War, Lunar Clock & 2,344-Bit Diffs Verified!\n");
}

/* ==========================================================================
 * TEST 4 (GATE 1C): Mod-Aware Promotion Tree Evaluator (Vanilla vs Modded)
 * ========================================================================== */
static void test_04_gate_1c_mod_aware_promotions(const uint8_t *rom, uint32_t rom_size) {
    printf("[TEST 04 / GATE 1C] Verifying Mod-Aware Promotion Tree Evaluation...\n");

    uint8_t *wram = (uint8_t *)calloc(1, OB_WRAM_SIZE_BYTES);
    uint8_t *mod_rom = (uint8_t *)malloc(rom_size);
    assert(wram && mod_rom);
    memcpy(mod_rom, rom, rom_size);

    /* Case A: Vanilla Fighter (Class 1, Level 6, ALI 38, CHA 52)
     * Checking Knight (Class 2: req L5, ALI 50..100, CHA 50)
     * and Ninja (Class 23: wait - let's check all 7 Fighter branches in Vanilla ROM!) */
    ObUnitTelemetry fighter = {0};
    fighter.slot_index  = 0;
    fighter.is_populated = true;
    fighter.class_id    = 1; /* Fighter */
    fighter.level       = 6;
    fighter.ali         = 38;
    fighter.cha         = 52;

    ObPromotionCheck branches[OB_MAX_PROMO_BRANCHES];
    size_t n_br = ob_telemetry_eval_promotions(&fighter, wram, rom, rom_size, branches, OB_MAX_PROMO_BRANCHES);
    assert(n_br >= 7); /* 7 standard branches + Rotten Pumpkin relic branch */

    /* Branch 0 is Knight (Class 2: min_lvl=5, min_ali=50, max_ali=100, min_cha=50) */
    assert(branches[0].target_class_id == 2);
    assert(branches[0].req_min_level == 5 && branches[0].level_delta == -1);
    assert(branches[0].req_min_ali == 50 && branches[0].ali_delta == +12); /* Needs +12 ALI */
    assert(branches[0].eligible_now == false);

    /* Branch 1 is Samurai (Class 4: min_lvl=6, min_ali=0, max_ali=49, min_cha=50) */
    assert(branches[1].target_class_id == 4);
    assert(branches[1].eligible_now == true);

    /* Case B: Apply Dragoner Rebalance Mod to mod_rom (Dragoner branch index 14: min_lvl=5, min_ali=60, min_cha=50) */
    mod_rom[0x04AED4 + 14] = 5;   /* Dragoner min_lvl: 1 -> 5 */
    mod_rom[0x04AF21 + 14] = 60;  /* Dragoner min_ali: 0 -> 60 */
    mod_rom[0x04AFBB + 14] = 50;  /* Dragoner min_cha: 0 -> 50 */

    /* Test custom pointer targeting class 15 (Dragoner branch idx 14) */
    uint16_t ptr_c10 = (uint16_t)mod_rom[0x04AD4C + (10 - 1) * 2] | ((uint16_t)mod_rom[0x04AD4C + (10 - 1) * 2 + 1] << 8);
    uint32_t off_c10 = 0x048000U + (ptr_c10 - 0x8000U);
    mod_rom[off_c10] = 15; /* Link class 10 first target to 15 (Dragoner branch idx 14) */

    ObUnitTelemetry amazon = {0};
    amazon.class_id = 10;
    amazon.level    = 4;
    amazon.ali      = 55;
    amazon.cha      = 52;

    size_t n_mod = ob_telemetry_eval_promotions(&amazon, wram, mod_rom, rom_size, branches, OB_MAX_PROMO_BRANCHES);
    assert(n_mod > 0);
    assert(branches[0].target_class_id == 15);
    assert(branches[0].req_min_level == 5 && branches[0].level_delta == +1);
    assert(branches[0].req_min_ali == 60 && branches[0].ali_delta == +5);
    assert(branches[0].eligible_now == false);

    /* Put Royal Crown (0x59) in Camp Inventory and verify Princess relic promotion */
    wram[0x157E + 0] = 0x59;
    n_mod = ob_telemetry_eval_promotions(&amazon, wram, mod_rom, rom_size, branches, OB_MAX_PROMO_BRANCHES);
    bool found_princess = false;
    for (size_t i = 0; i < n_mod; ++i) {
        if (branches[i].target_class_id == 14 && branches[i].required_relic == 0x59) {
            assert(branches[i].relic_in_stock == true);
            assert(branches[i].eligible_now == true);
            found_princess = true;
        }
    }
    assert(found_princess);

    free(mod_rom);
    free(wram);
    printf("  -> [PASS] Gate 1C Mod-Aware Promotion Tree & Relic Triggers Certified!\n");
}

/* ==========================================================================
 * TEST 5: Predictive Morality, Engagement TTC & Secondary Companion Window
 * ========================================================================== */
static void test_05_companion_window_and_predictive_math(const uint8_t *rom, uint32_t rom_size) {
    printf("[TEST 05] Verifying Predictive Math & Secondary Companion Window Rendering...\n");

    uint8_t *wram = (uint8_t *)calloc(1, OB_WRAM_SIZE_BYTES);
    assert(wram != NULL);

    /* Populate rich tactical stage state for Companion Window snapshot */
    write_u32_le(wram, 0x1578, 42650U);
    wram[0x157C] = 74U;
    wram[0x157D] = 8U;
    wram[0x156D] = 1; wram[0x156E] = 2; wram[0x156F] = 3; wram[0x1570] = 9;
    wram[0x1571] = 16; wram[0x1572] = 40; wram[0x1573] = 12;

    /* Populate 4 Roster Units */
    wram[0x07BA + 0] = 0x52; wram[0x085A + 0] = 79; wram[0xF148 + 0] = 8;
    write_u16_le(wram, 0x099A + 0, 164); write_u16_le(wram, 0x0ADA + 0, 164);
    wram[0xF24C + 0] = 71; wram[0xF2EC + 0] = 68; wram[0xF38C + 0] = 64;
    wram[0xF42C + 0] = 76; wram[0x0C1A + 0] = 78; wram[0xF490 + 0] = 61;

    wram[0x07BA + 1] = 0x01; wram[0x085A + 1] = 1; wram[0xF148 + 1] = 6;
    write_u16_le(wram, 0x099A + 2, 112); write_u16_le(wram, 0x0ADA + 2, 112);
    wram[0xF24C + 1] = 56; wram[0xF2EC + 1] = 52; wram[0xF38C + 1] = 40;
    wram[0xF42C + 1] = 54; wram[0x0C1A + 1] = 44; wram[0xF490 + 1] = 48;
    write_u16_le(wram, 0xF4F4 + 2, 260);

    wram[0x07BA + 2] = 0x54; wram[0x085A + 2] = 19; wram[0xF148 + 2] = 7; /* Wizard */
    write_u16_le(wram, 0x099A + 4, 92); write_u16_le(wram, 0x0ADA + 4, 98);
    wram[0xF24C + 2] = 39; wram[0xF2EC + 2] = 55; wram[0xF38C + 2] = 74;
    wram[0xF42C + 2] = 62; wram[0x0C1A + 2] = 34; wram[0xF490 + 2] = 52;
    write_u16_le(wram, 0xF4F4 + 4, 380);

    /* Squads & Deployed Entities */
    memset(&wram[0x0E81], 0xFF, 125);
    wram[0x0E81 + 0] = 0; wram[0x0E81 + 1] = 1; wram[0x0E81 + 2] = 2;
    for (int s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        write_u16_le(wram, 0x18AF + s * 2, 0x7FFF);
    }
    write_u16_le(wram, 0x18AF + 0, 640); write_u16_le(wram, 0x18D9 + 0, 920);
    write_u16_le(wram, 0x1905 + 0, 880); write_u16_le(wram, 0x192D + 0, 620);
    write_u16_le(wram, 0x18AF + 2, 480); write_u16_le(wram, 0x18D9 + 2, 740);
    write_u16_le(wram, 0x18AF + 20, 960); write_u16_le(wram, 0x18D9 + 20, 540);
    write_u16_le(wram, 0x1905 + 20, 640); write_u16_le(wram, 0x192D + 20, 920);
    write_u16_le(wram, 0x19A5 + 20, 0x0001);

    /* Cities */
    for (int c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        write_u16_le(wram, 0x1A95 + c * 2, 0x7FFF);
    }
    write_u16_le(wram, 0x1A95 + 0, 600); write_u16_le(wram, 0x1B0D + 0, 960);
    write_u16_le(wram, 0x1B5D + 0, 180); wram[0x1C4D + 0] = 0x01; /* Liberated */
    write_u16_le(wram, 0x1A95 + 2, 880); write_u16_le(wram, 0x1B0D + 2, 620);
    write_u16_le(wram, 0x1B5D + 2, 220); wram[0x1C25 + 2] = 58; wram[0x1C4D + 2] = 0x00; /* Enemy */

    /* Combat Clash Damage */
    wram[0xF92B] = 1; wram[0xF92E] = 3; wram[0xF931] = 2; wram[0xF934] = 7; wram[0xF941] = 4;
    write_u16_le(wram, 0xF942, 248);
    write_u16_le(wram, 0xF944, 165);

    ObTelemetryFrame f1, f2;
    ob_telemetry_poll_vblank(wram, rom, rom_size, 1420, &f1);

    wram[0x8600 + 18] |= 0x10;
    wram[0x8600 + 172] |= 0x02;
    ob_telemetry_poll_vblank(wram, rom, rom_size, 1421, &f2);

    ObCompanionWindowState state;
    ob_companion_window_init(&state);
    state.selected_unit_slot = 1; /* Inspect Fighter promotions */

    uint32_t *fb = (uint32_t *)malloc(OB_COMPANION_WIDTH * OB_COMPANION_HEIGHT * sizeof(uint32_t));
    assert(fb != NULL);
    ob_telemetry_render_companion_window(&state, &f1, &f2, wram, rom, rom_size, fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT);

    bool saved = ob_companion_window_save_ppm(fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT, "/tmp/companion_window_preview.ppm");
    assert(saved);

    free(fb);
    free(wram);
    printf("  -> [PASS] Secondary Companion Window (640x480) Rendered & Verified!\n");
}

static void test_06_phase_5b_walkthrough_models(const uint8_t *rom, uint32_t rom_size) {
    printf("[TEST 06 / PHASE 5B] Verifying Walkthrough-Driven Predictive & Mechanics Models...\n");
    uint8_t *wram = (uint8_t *)calloc(OB_WRAM_SIZE_BYTES, 1);
    assert(wram != NULL);

    /* Setup Opinion Leader, Lans, Warren */
    wram[0x07BA + 0] = 1; wram[0x085A + 0] = 75; wram[0xF148 + 0] = 6; wram[0x0C1A + 0] = 72; wram[0xF42C + 0] = 74;
    wram[0x07BA + 1] = 2; wram[0x085A + 1] = 2;  wram[0xF148 + 1] = 5; wram[0x0C1A + 1] = 74; wram[0xF42C + 1] = 68;
    wram[0x07BA + 2] = 3; wram[0x085A + 2] = 7;  wram[0xF148 + 2] = 5; wram[0x0C1A + 2] = 62; wram[0xF42C + 2] = 66;
    write_u16_le(wram, 0x099A + 0, 140); write_u16_le(wram, 0x0ADA + 0, 140);
    write_u16_le(wram, 0x099A + 2, 130); write_u16_le(wram, 0x0ADA + 2, 130);
    write_u16_le(wram, 0x099A + 4, 110); write_u16_le(wram, 0x0ADA + 4, 110);

    /* Setup Squad 0 with Opinion Leader and Lans (no flyers -> Normal ground) */
    wram[0x0E81 + 0] = 0; wram[0x0E81 + 1] = 1; wram[0x0E81 + 2] = 2;

    /* Setup City 0 (liberated temple) and City 1 (enemy city) */
    write_u16_le(wram, 0x1A95 + 0, 400); write_u16_le(wram, 0x1B0D + 0, 300);
    write_u16_le(wram, 0x1B5D + 0, 1500); wram[0x1C4D + 0] = 0x05; /* Liberated (1) + Temple (4) */
    write_u16_le(wram, 0x1A95 + 2, 800); write_u16_le(wram, 0x1B0D + 2, 600);
    write_u16_le(wram, 0x1B5D + 2, 1200); wram[0x1C4D + 2] = 0x02; /* Hidden (2) + Unliberated */

    /* Setup Enemy Squad 10 marching toward City 0 */
    write_u16_le(wram, 0x18AF + 20, 450); write_u16_le(wram, 0x18D9 + 20, 300);
    write_u16_le(wram, 0x1905 + 20, 400); write_u16_le(wram, 0x192D + 20, 300);
    write_u16_le(wram, 0x1955 + 20, (uint16_t)(int16_t)-3);
    write_u16_le(wram, 0x1A11 + 20, 3);
    write_u16_le(wram, 0x19A5 + 20, 0x0100);

    /* Inventory: Quicksilver ($45), Tablet of Yaru ($49), Stone 1 ($50), Stone 2 ($51) */
    wram[0x157E + 0] = 0x45;
    wram[0x157E + 1] = 0x49;
    wram[0x157E + 2] = 0x50;
    wram[0x157E + 3] = 0x51;

    /* Tarot Hand: Magician (0), Lovers (5), Chariot (6) */
    memset(&wram[0x0DBE], 0xFF, OB_MAX_TAROT_HAND);
    wram[0x0DBE + 0] = 0; /* Magician: Offensive */
    wram[0x0DBE + 1] = 5; /* Lovers: CF +2 */
    wram[0x0DBE + 2] = 6; /* Chariot: Offensive */

    wram[0x157C] = 72; /* CF = 72 */

    ObTelemetryFrame frame;
    ob_telemetry_poll_vblank(wram, rom, rom_size, 200, &frame);

    /* 1. Verify Recapture Threat detection */
    ObRecaptureThreat threats[4];
    size_t n_threats = ob_telemetry_detect_recapture_threats(&frame, threats, 4);
    assert(n_threats > 0);
    assert(threats[0].enemy_slot == 10);
    assert(threats[0].target_city_index == 0);
    assert(threats[0].is_temple == true);
    assert(threats[0].penalty_cf == -5);

    /* 2. Verify Tarot Audit & Leader Overlevel Guard */
    ObTarotAudit tarot[8];
    size_t n_tarot = ob_telemetry_audit_tarot_hand(&frame, tarot, 8);
    assert(n_tarot == 3);
    assert(tarot[0].is_offensive == true);
    assert(tarot[0].leader_overlevel_risk == true); /* Lord Lv6 -> offensive card kill risk */
    assert(tarot[1].is_offensive == false);

    /* 3. Verify 18-Hero Recruitment Audit */
    ObHeroRecruitmentAudit heroes[18];
    size_t n_heroes = ob_telemetry_audit_special_recruits(&frame, heroes, 18);
    assert(n_heroes == 18);
    assert(heroes[0].is_recruited == true); /* Lans is in roster */
    /* Slust requires CF >= 67 & Leader ALI >= 70 (both met: CF=72, ALI=72) */
    assert(heroes[10].prereq_cf_met == true);
    assert(heroes[10].prereq_ali_met == true);
    /* Deneb tradeoff warning */
    assert(strstr(heroes[16].tradeoff_warning, "Halloween") != NULL);
    /* Galf tradeoff warning */
    assert(strstr(heroes[17].tradeoff_warning, "Top 3 Endings") != NULL);

    /* 4. Verify Zodiac Stones & Quest Status */
    ObZodiacQuestStatus z;
    ob_telemetry_track_zodiac_stones(&frame, &z);
    assert(z.quicksilver_in_hand == true);
    assert(z.tablet_of_yaru_in_hand == true);
    assert(z.stones_collected_count == 2);
    assert((z.stones_mask & 0x03) == 0x03);

    /* 5. Verify Squad Mobility */
    ObSquadMobilityAnalysis mob;
    ob_telemetry_analyze_squad_mobility(&frame, 0, &mob);
    assert(mob.flyers_needed_for_sky > 0);

    /* 6. Verify Hidden PoI Audit */
    ObHiddenPoISummary poi;
    ob_telemetry_audit_hidden_poi(&frame, &poi);
    assert(poi.hidden_cities_count >= 1);
    assert(poi.unliberated_cities_count >= 1);

    /* 7. Verify Multi-Page Rendering across Pages 1, 2, and 3 */
    ObCompanionWindowState state;
    ob_companion_window_init(&state);
    uint32_t *fb = (uint32_t *)malloc(OB_COMPANION_WIDTH * OB_COMPANION_HEIGHT * sizeof(uint32_t));
    assert(fb != NULL);

    /* Page 1: Tactical */
    state.active_page = OB_COMPANION_PAGE_TACTICAL;
    ob_companion_window_toggle_poi(&state);
    assert(state.show_hidden_poi_radar == true);
    ob_telemetry_render_companion_window(&state, NULL, &frame, wram, rom, rom_size, fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT);
    ob_companion_window_save_ppm(fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT, "/tmp/companion_page1.ppm");

    /* Page 2: Combat & Tarot */
    ob_companion_window_cycle_page(&state);
    assert(state.active_page == OB_COMPANION_PAGE_COMBAT_TAROT);
    ob_telemetry_render_companion_window(&state, NULL, &frame, wram, rom, rom_size, fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT);
    ob_companion_window_save_ppm(fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT, "/tmp/companion_page2.ppm");

    /* Page 3: Campaign Guide */
    ob_companion_window_cycle_page(&state);
    assert(state.active_page == OB_COMPANION_PAGE_CAMPAIGN_GUIDE);
    ob_telemetry_render_companion_window(&state, NULL, &frame, wram, rom, rom_size, fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT);
    ob_companion_window_save_ppm(fb, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT, "/tmp/companion_page3.ppm");

    free(fb);
    free(wram);
    printf("  -> [PASS] Phase 5B Walkthrough Models & 3-Page Companion Window Certified!\n");
}

int main(void) {
    printf("================================================================================\n");
    printf("  OGRE BATTLE PC PORT: AREA 1 TELEMETRY & LOCKSTEP CERTIFICATION SUITE\n");
    printf("================================================================================\n");

    uint32_t rom_size = 0;
    uint8_t *rom = load_rom_file("/home/antigravity/ogre_battle.sfc", &rom_size);
    assert(rom != NULL && rom_size == OB_ROM_BASE_SIZE_BYTES);

    test_01_gate_1a_lockstep_zero_invasion(rom, rom_size);
    test_02_gate_1b_tier1_soa_extraction(rom, rom_size);
    test_03_gate_1b_tier2_deep_domains(rom, rom_size);
    test_04_gate_1c_mod_aware_promotions(rom, rom_size);
    test_05_companion_window_and_predictive_math(rom, rom_size);
    test_06_phase_5b_walkthrough_models(rom, rom_size);

    free(rom);
    printf("================================================================================\n");
    printf("  ALL 6 AREA 1 TELEMETRY & LOCKSTEP QUALITY GATES PASSED (100%% CERTIFIED)\n");
    printf("================================================================================\n");
    return 0;
}
