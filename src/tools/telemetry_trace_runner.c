/*
 * Ogre Battle: The March of the Black Queen — Native PC Port
 * Modernization Area 1: Headless Telemetry Trace Runner (Phase 1 & Phase 5)
 *
 * Steps LakeSnes through hardware boot and canonical Stage 1 (Felnamia) tactical
 * scenarios, polling ObTelemetryFrame at VBlank and emitting JSONL telemetry
 * snapshots + 2,344-bit ($7E:8600-$7E:8F27) & scalar diff events for the
 * Phase 5 Pattern Discovery Lab.
 */

#include "telemetry.h"
#include "telemetry_math.h"
#include "telemetry_window.h"
#include "snes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_file_bytes(const char *path, uint32_t *out_size) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0) { fclose(f); return NULL; }
    uint8_t *buf = (uint8_t *)malloc((size_t)sz);
    if (!buf) { fclose(f); return NULL; }
    if (fread(buf, 1, (size_t)sz, f) != (size_t)sz) {
        free(buf);
        fclose(f);
        return NULL;
    }
    fclose(f);
    *out_size = (uint32_t)sz;
    return buf;
}

static void write_u16_le(uint8_t *wram, uint32_t offset, uint16_t val) {
    wram[offset]     = (uint8_t)(val & 0xFFU);
    wram[offset + 1] = (uint8_t)((val >> 8) & 0xFFU);
}

static void write_u32_le(uint8_t *wram, uint32_t offset, uint32_t val) {
    wram[offset]     = (uint8_t)(val & 0xFFU);
    wram[offset + 1] = (uint8_t)((val >> 8) & 0xFFU);
    wram[offset + 2] = (uint8_t)((val >> 16) & 0xFFU);
    wram[offset + 3] = (uint8_t)((val >> 24) & 0xFFU);
}

static void set_bitflag(uint8_t *wram, uint16_t bit_index, bool value) {
    uint32_t byte_off = 0x8600U + (bit_index >> 3);
    uint8_t  mask     = (uint8_t)(1U << (bit_index & 7U));
    if (value) wram[byte_off] |= mask;
    else       wram[byte_off] &= (uint8_t)~mask;
}

static void emit_frame_summary_jsonl(
    FILE *out,
    const char *scenario_tag,
    const ObTelemetryFrame *frame,
    const ObTelemetryDiffEvent *diffs,
    size_t num_diffs
) {
    int p0_x = (int)frame->map_entities[0].world_x;
    int p0_y = (int)frame->map_entities[0].world_y;
    int p0_vx = (int)frame->map_entities[0].vel_dx;
    int p0_vy = (int)frame->map_entities[0].vel_dy;
    int p0_fatigue = (int)frame->map_entities[0].fatigue_stun;

    int e0_x = (int)frame->map_entities[10].world_x;
    int e0_y = (int)frame->map_entities[10].world_y;
    int e0_target = (int)frame->map_entities[10].ai_order_state;

    int clash_margin = (int)frame->combat.player_clash_damage - (int)frame->combat.enemy_clash_damage;
    bool is_leap = ((frame->calendar.year & 3U) == 0U);

    fprintf(
        out,
        "{\"record_type\":\"frame_snapshot\",\"frame\":%u,\"scenario\":\"%s\","
        "\"goth\":%u,\"chaos_frame\":%u,\"cf_sub\":%u,\"projected_noon_tribute\":%d,"
        "\"calendar\":{\"year\":%u,\"month\":%u,\"day\":%u,\"weekday\":%u,\"hour\":%u,\"minute\":%u,\"is_leap\":%s},"
        "\"player_lead\":{\"x\":%d,\"y\":%d,\"vx\":%d,\"vy\":%d,\"fatigue\":%d,\"ali\":%u,\"cha\":%u,\"lvl\":%u},"
        "\"enemy_lead\":{\"x\":%d,\"y\":%d,\"ai_target\":%d},"
        "\"combat\":{\"active\":%s,\"player_dmg\":%u,\"enemy_dmg\":%u,\"margin\":%d},"
        "\"diff_count\":%zu}\n",
        frame->frame_counter,
        scenario_tag,
        frame->goth_treasury,
        frame->chaos_frame,
        frame->chaos_frame_sub,
        frame->projected_noon_net,
        frame->calendar.year,
        frame->calendar.month,
        frame->calendar.day,
        frame->calendar.lunar_weekday,
        frame->calendar.hour,
        frame->calendar.minute,
        is_leap ? "true" : "false",
        p0_x, p0_y, p0_vx, p0_vy, p0_fatigue,
        frame->units[0].ali, frame->units[0].cha, frame->units[0].level,
        e0_x, e0_y, e0_target,
        frame->combat.in_combat ? "true" : "false",
        frame->combat.player_clash_damage,
        frame->combat.enemy_clash_damage,
        clash_margin,
        num_diffs
    );

    if (num_diffs > 0) {
        char diff_buf[16384];
        size_t written = ob_telemetry_format_diff_jsonl(diffs, num_diffs, diff_buf, sizeof(diff_buf));
        if (written > 0) {
            fwrite(diff_buf, 1, written, out);
        }
    }
}

int main(int argc, char **argv) {
    const char *rom_path   = (argc > 1) ? argv[1] : "/home/antigravity/ogre_battle.sfc";
    const char *jsonl_path = (argc > 2) ? argv[2] : "/home/antigravity/build/telemetry_trace.jsonl";
    const char *ppm_path   = (argc > 3) ? argv[3] : "/tmp/companion_window_preview.ppm";

    uint32_t rom_size = 0;
    uint8_t *rom = load_file_bytes(rom_path, &rom_size);
    if (!rom) {
        fprintf(stderr, "Failed to load ROM: %s\n", rom_path);
        return 1;
    }

    FILE *out = fopen(jsonl_path, "w");
    if (!out) {
        fprintf(stderr, "Failed to open output JSONL: %s\n", jsonl_path);
        free(rom);
        return 1;
    }

    Snes *snes = snes_init();
    if (!snes_loadRom(snes, rom, (int)rom_size)) {
        fprintf(stderr, "LakeSnes failed to load ROM\n");
        fclose(out);
        free(rom);
        return 1;
    }

    ObTelemetryFrame prev_frame;
    ObTelemetryFrame curr_frame;
    memset(&prev_frame, 0, sizeof(prev_frame));
    memset(&curr_frame, 0, sizeof(curr_frame));

    ObCompanionWindowState win_state;
    ob_companion_window_init(&win_state);
    win_state.selected_unit_slot = 3; /* Inspect Ashe (Fighter Lv6 ready for Knight/Samurai promotion) */
    win_state.selected_squad_id  = 0;

    uint32_t *win_rgba = (uint32_t *)calloc(OB_COMPANION_WIDTH * OB_COMPANION_HEIGHT, sizeof(uint32_t));
    ObTelemetryDiffEvent diffs[256];
    uint32_t global_tick = 0;

    /* Phase 1: Boot & Title Screen (Run 120 real hardware frames, sample every 10 frames) */
    for (int f = 0; f < 120; ++f) {
        snes_runFrame(snes);
        global_tick++;
        if (f % 10 == 0) {
            ob_telemetry_poll_vblank(snes->ram, rom, rom_size, global_tick, &curr_frame);
            size_t nd = (f == 0) ? 0 : ob_telemetry_diff_frames(&prev_frame, &curr_frame, diffs, 256);
            emit_frame_summary_jsonl(out, "boot_sequence", &curr_frame, diffs, nd);
            prev_frame = curr_frame;
        }
    }

    /* Phase 2: New Game Init ($00:8383 Canonical Defaults + Stage 1 Felnamia Setup) */
    uint8_t *wram = snes->ram;
    wram[0x00CB] = 3; /* Tactical Map mode */
    write_u32_le(wram, 0x1578, 30000U); /* Goth Treasury */
    wram[0x157C] = 50U;                 /* Chaos Frame */
    wram[0x157D] = 0U;                  /* Chaos Frame sub-accumulator */
    wram[0x156D] = 1U;                  /* Year 1 */
    wram[0x156E] = 1U;                  /* Month 1 */
    wram[0x156F] = 0U;                  /* Sun Day */
    wram[0x1570] = 1U;                  /* Day 1 */
    wram[0x1571] = 9U;                  /* 09:00 AM */
    wram[0x1572] = 0U;                  /* Minute 0 */
    wram[0x1573] = 0U;                  /* Subtick 0 */
    wram[0x1575] = 3U;                  /* Clock Speed */

    /* Populate Leader (Slot 0: Opinion Leader), Lans (Slot 1: Knight), Warren (Slot 2: Wizard),
     * Ashe (Slot 3: Fighter ready for promotion), Lyon (Slot 4: Beast Tamer) */
    uint8_t classes[5]   = { 75, 2, 7, 1, 13 };
    uint8_t levels[5]    = { 4,  5, 5, 6, 4  };
    uint8_t alis[5]      = { 68, 74, 62, 71, 44 };
    uint8_t chas[5]      = { 72, 68, 66, 59, 51 };
    uint16_t hps[5]      = { 125, 142, 96, 118, 130 };
    uint16_t costs[5]    = { 0, 520, 480, 220, 390 };

    for (int u = 0; u < 5; ++u) {
        wram[0x07BA + u] = (uint8_t)(u + 1);
        wram[0x085A + u] = classes[u];
        wram[0xF148 + u] = levels[u];
        wram[0x0C1A + u] = alis[u];
        wram[0xF42C + u] = chas[u];
        wram[0xF24C + u] = (uint8_t)(42 + u * 3);
        wram[0xF2EC + u] = (uint8_t)(38 + u * 2);
        wram[0xF38C + u] = (uint8_t)(40 + u * 4);
        wram[0xF490 + u] = (uint8_t)(50 + u);
        wram[0x0F35 + u] = (u < 3) ? 0 : 1;
        write_u16_le(wram, 0x099A + u * 2, hps[u]);
        write_u16_le(wram, 0x0ADA + u * 2, hps[u]);
        write_u16_le(wram, 0xF4F4 + u * 2, costs[u]);
    }

    /* Enemy Boss (Stage Boss in Slot 20) */
    wram[0x07BA + 20] = 80;
    wram[0x085A + 20] = 7;  /* Wizard */
    wram[0xF148 + 20] = 6;
    wram[0x0C1A + 20] = 35;
    wram[0xF42C + 20] = 60;
    wram[0x0F35 + 20] = 10;
    write_u16_le(wram, 0x099A + 20 * 2, 145);
    write_u16_le(wram, 0x0ADA + 20 * 2, 145);

    /* Configure Squad 0 (Opinion Leader + Lans + Warren) and Squad 1 (Ashe + Lyon) */
    memset(&wram[0x0E81], 0xFF, 25 * 5);
    wram[0x0E81 + 0] = 0;
    wram[0x0E81 + 1] = 1;
    wram[0x0E81 + 2] = 2;
    wram[0x0DCD + 0] = (2U << 4) | 1U;
    wram[0x0DCD + 1] = (2U << 4) | 0U;
    wram[0x0DCD + 2] = (2U << 4) | 4U;

    wram[0x0E81 + 5 + 0] = 3;
    wram[0x0E81 + 5 + 1] = 4;
    wram[0x0DCD + 5 + 0] = (2U << 4) | 1U;
    wram[0x0DCD + 5 + 1] = (2U << 4) | 2U;

    /* Initialize unused map entity & city slots to 0x7FFF (inactive) */
    for (int s = 0; s < OB_MAX_DEPLOYED_SLOTS; ++s) {
        write_u16_le(wram, 0x18AF + s * 2, 0x7FFFU);
        write_u16_le(wram, 0x18D9 + s * 2, 0x7FFFU);
    }
    for (int c = 0; c < OB_MAX_STAGE_CITIES; ++c) {
        write_u16_le(wram, 0x1A95 + c * 2, 0x7FFFU);
        write_u16_le(wram, 0x1B0D + c * 2, 0x7FFFU);
    }

    /* Configure Stage 1 Cities (4 towns + Rebel Base + Castle) */
    uint16_t city_x[5]      = { 120, 180, 260, 340, 420 };
    uint16_t city_y[5]      = { 400, 330, 270, 210, 140 };
    uint16_t city_trib[5]   = { 1500, 1200, 1400, 1800, 2500 };
    uint16_t city_compat[5] = { 70,   72,   55,   80,   65 };
    uint16_t city_own[5]    = { 1,    0,    0,    0,    0 }; /* Town 0 Rebel Base liberated */
    uint16_t city_morale[5] = { 78,   68,   52,   74,   60 };

    for (int c = 0; c < 5; ++c) {
        write_u16_le(wram, 0x1A95 + c * 2, city_x[c]);
        write_u16_le(wram, 0x1B0D + c * 2, city_y[c]);
        write_u16_le(wram, 0x1B5D + c * 2, city_trib[c]);
        write_u16_le(wram, 0x1C25 + c * 2, city_compat[c]);
        write_u16_le(wram, 0x1C4D + c * 2, city_own[c]);
        write_u16_le(wram, 0x1C75 + c * 2, city_morale[c]);
    }

    /* Set Warren Quiz completion bitflag (bit 12 in $7E:8600) */
    set_bitflag(wram, 12, true);

    /* Phase 3: Tactical March & Kinematics (30 steps of marching toward Town 1 & Enemy Squad 10) */
    int16_t p0_x = 120, p0_y = 400;
    int16_t p1_x = 125, p1_y = 395;
    int16_t e0_x = 290, e0_y = 260;

    for (int step = 0; step < 30; ++step) {
        global_tick++;
        p0_x += 4; p0_y -= 4;
        p1_x += 3; p1_y -= 3;
        e0_x -= 3; e0_y += 2;

        write_u16_le(wram, 0x18AF + 0 * 2, (uint16_t)p0_x);
        write_u16_le(wram, 0x18D9 + 0 * 2, (uint16_t)p0_y);
        write_u16_le(wram, 0x1905 + 0 * 2, 180);
        write_u16_le(wram, 0x192D + 0 * 2, 330);
        write_u16_le(wram, 0x1955 + 0 * 2, (uint16_t)(int16_t)4);
        write_u16_le(wram, 0x197D + 0 * 2, (uint16_t)(int16_t)-4);
        write_u16_le(wram, 0x19CD + 0 * 2, (uint16_t)(step * 2));
        write_u16_le(wram, 0x1A11 + 0 * 2, 4);

        write_u16_le(wram, 0x18AF + 1 * 2, (uint16_t)p1_x);
        write_u16_le(wram, 0x18D9 + 1 * 2, (uint16_t)p1_y);
        write_u16_le(wram, 0x1905 + 1 * 2, 260);
        write_u16_le(wram, 0x192D + 1 * 2, 270);
        write_u16_le(wram, 0x1955 + 1 * 2, (uint16_t)(int16_t)3);
        write_u16_le(wram, 0x197D + 1 * 2, (uint16_t)(int16_t)-3);
        write_u16_le(wram, 0x1A11 + 1 * 2, 3);

        /* Enemy Squad 10 locks onto Player Squad 0 */
        write_u16_le(wram, 0x18AF + 10 * 2, (uint16_t)e0_x);
        write_u16_le(wram, 0x18D9 + 10 * 2, (uint16_t)e0_y);
        write_u16_le(wram, 0x1905 + 10 * 2, (uint16_t)p0_x);
        write_u16_le(wram, 0x192D + 10 * 2, (uint16_t)p0_y);
        write_u16_le(wram, 0x1955 + 10 * 2, (uint16_t)(int16_t)-3);
        write_u16_le(wram, 0x197D + 10 * 2, (uint16_t)(int16_t)2);
        write_u16_le(wram, 0x19A5 + 10 * 2, 0x0100U); /* Target Player Squad 0 */
        write_u16_le(wram, 0x1A11 + 10 * 2, 3);

        /* Advance clock by 6 minutes per step */
        uint8_t min = (uint8_t)(wram[0x1572] + 6);
        if (min >= 60) {
            min -= 60;
            wram[0x1571]++;
        }
        wram[0x1572] = min;

        /* Step 15: Town 1 Liberation! */
        if (step == 15) {
            write_u16_le(wram, 0x1C4D + 1 * 2, 1U);
            write_u16_le(wram, 0x1C9D + 1 * 2, 1U);
            wram[0x157C] = 52U; /* +2 Chaos Frame from high ALI liberation */
            wram[0x0DBE + 0] = 6U; /* THE LOVERS drawn */
            set_bitflag(wram, 145, true); /* STORY_BIT_A: Stage 1 Town 1 liberated flag */
        }

        /* Step 22: Hidden Treasure Discovered by Squad 1! */
        if (step == 22) {
            wram[0x157E + 0] = 0x4BU; /* Undead Staff / Crown relic */
            set_bitflag(wram, 160 * 8 + 3, true); /* TREASURE_BIT_B: Hidden treasure bitflag ($7E:86A0) */
        }

        ob_telemetry_poll_vblank(wram, rom, rom_size, global_tick, &curr_frame);
        size_t nd = ob_telemetry_diff_frames(&prev_frame, &curr_frame, diffs, 256);
        emit_frame_summary_jsonl(out, "tactical_march", &curr_frame, diffs, nd);
        ob_telemetry_render_companion_window(&win_state, &prev_frame, &curr_frame, wram, rom, rom_size, win_rgba, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT);
        prev_frame = curr_frame;
    }

    /* Phase 4: Live Combat Clash Tug-of-War ($7E:F942 vs $7E:F944) */
    uint16_t p_dmg_seq[8] = { 0, 24, 58, 58, 96, 134, 134, 178 };
    uint16_t e_dmg_seq[8] = { 0, 0,  19, 47, 47, 47,  79,  79  };
    wram[0x00CB] = 4; /* Combat Arena mode */
    wram[0xF92B] = 1; /* Active combat flag */
    memset(&wram[0xF98C], 0xFF, 10);
    wram[0xF98C + 0] = 0;  /* Opinion Leader */
    wram[0xF98C + 1] = 1;  /* Lans */
    wram[0xF98C + 2] = 2;  /* Warren */
    wram[0xF98C + 5] = 20; /* Enemy Boss */

    for (int turn = 0; turn < 8; ++turn) {
        global_tick++;
        write_u16_le(wram, 0xF942, p_dmg_seq[turn]);
        write_u16_le(wram, 0xF944, e_dmg_seq[turn]);
        wram[0xF941] = (uint8_t)(8 - turn);
        wram[0xF977 + 0] = (uint8_t)(turn % 6);
        wram[0xF996 + 0] = (uint8_t)((turn < 6) ? (2 - (turn / 3)) : 0);

        if (turn == 7) {
            /* Clash won + Boss defeated recruitment bitflag */
            wram[0x0C1A + 0] = 70;
            wram[0xF42C + 0] = 74;
            wram[0x1723 + 0] = 1U; /* Stage 1 Felnamia cleared flag */
            set_bitflag(wram, 230 * 8 + 4, true); /* RECRUIT_BIT_C: Warren recruitment flag ($7E:86E6) */
        }

        ob_telemetry_poll_vblank(wram, rom, rom_size, global_tick, &curr_frame);
        size_t nd = ob_telemetry_diff_frames(&prev_frame, &curr_frame, diffs, 256);
        emit_frame_summary_jsonl(out, "combat_clash", &curr_frame, diffs, nd);
        ob_telemetry_render_companion_window(&win_state, &prev_frame, &curr_frame, wram, rom, rom_size, win_rgba, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT);
        prev_frame = curr_frame;
    }

    /* Export Companion Window Snapshot during peak Combat Clash before clearing arena */
    ob_companion_window_save_ppm(win_rgba, OB_COMPANION_WIDTH, OB_COMPANION_HEIGHT, ppm_path);

    /* Clear combat accumulators after clash */
    wram[0x00CB] = 3;
    wram[0xF92B] = 0;
    write_u16_le(wram, 0xF942, 0);
    write_u16_le(wram, 0xF944, 0);
    wram[0xF941] = 0;
    memset(&wram[0xF98C], 0xFF, 10);

    /* Phase 5: Noon Tribute & Leap-Year Celestial Calendar Rollover */
    wram[0x1571] = 12U; /* 12:00 PM Noon Tribute Trigger */
    wram[0x1572] = 0U;
    write_u32_le(wram, 0x1578, 30000U + 1280U); /* +1,280 Goth net noon tribute */
    global_tick++;
    ob_telemetry_poll_vblank(wram, rom, rom_size, global_tick, &curr_frame);
    size_t nd = ob_telemetry_diff_frames(&prev_frame, &curr_frame, diffs, 256);
    emit_frame_summary_jsonl(out, "noon_tribute_payout", &curr_frame, diffs, nd);
    prev_frame = curr_frame;

    /* Test Leap Year (Year 4, Month 2 Day 29) */
    wram[0x156D] = 4U; /* (4 & 3) == 0 -> Leap Year! */
    wram[0x156E] = 2U;
    wram[0x1570] = 29U;
    wram[0x156F] = 6U; /* Chaos / Dark Lunar Phase */
    global_tick++;
    ob_telemetry_poll_vblank(wram, rom, rom_size, global_tick, &curr_frame);
    nd = ob_telemetry_diff_frames(&prev_frame, &curr_frame, diffs, 256);
    emit_frame_summary_jsonl(out, "leap_year_celestial_check", &curr_frame, diffs, nd);

    free(win_rgba);
    fclose(out);
    snes_free(snes);
    free(rom);
    printf("Generated telemetry trace at %s and Companion Window preview at %s\n", jsonl_path, ppm_path);
    return 0;
}
