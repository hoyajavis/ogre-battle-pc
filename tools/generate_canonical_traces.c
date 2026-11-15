#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "oracle.h"
#include "snapshot.h"
#include "replay.h"
#include "lockstep.h"

static void save_png(Snes* snes, const char* png_filename) {
    char ppm_filename[256];
    snprintf(ppm_filename, sizeof(ppm_filename), "%s.ppm", png_filename);
    FILE* f = fopen(ppm_filename, "wb");
    if (!f) return;
    fprintf(f, "P6\n256 224\n255\n");
    Ppu* ppu = snes->ppu;
    int fmt = ppu->pixelOutputFormat; // 1 for BGRX
    for (int y = 0; y < 224; ++y) {
        uint8_t* line = &ppu->pixelBuffer[y * 2048];
        for (int x = 0; x < 256; ++x) {
            uint8_t b = line[x * 8 + fmt + 0];
            uint8_t g = line[x * 8 + fmt + 1];
            uint8_t r = line[x * 8 + fmt + 2];
            fputc(r, f); fputc(g, f); fputc(b, f);
        }
    }
    fclose(f);

    char cmd[512];
    snprintf(cmd, sizeof(cmd), "python3 -c \"from PIL import Image; Image.open('%s').save('%s'); import os; os.remove('%s')\"",
             ppm_filename, png_filename, ppm_filename);
    system(cmd);
}

int main(int argc, char* argv[]) {
    const char* rom_path = (argc > 1) ? argv[1] : "ogre_battle.sfc";
    printf("====================================================================\n");
    printf("Ogre Battle PC: Canonical Walkthrough Trace Generator (Traces 01-08)\n");
    printf("ROM: %s\n", rom_path);
    printf("====================================================================\n\n");

    system("mkdir -p traces");

    OracleRunner* oracle = oracle_init(rom_path);
    if (!oracle) {
        fprintf(stderr, "Failed to load ROM: %s\n", rom_path);
        return 1;
    }

    // ====================================================================
    // TRACE 1: Boot to Title Screen Demo (3,000 frames)
    // ====================================================================
    printf("[CANONICAL TRACE 1] Recording trace_01_boot_to_title.obrec (3,000 frames)...\n");
    ReplayTrace* t1 = replay_create("trace_01_boot_to_title", 3000);
    assert(t1 != NULL);
    for (uint32_t f = 0; f < 3000; ++f) {
        replay_record_frame(t1, 0);
        oracle_step_frame(oracle, 0);
    }
    assert(replay_save_file(t1, "traces/trace_01_boot_to_title.obrec"));
    oracle_save_state(oracle, "traces/trace_01.obsav");
    save_png(oracle->snes, "traces/trace_01_screen.png");
    printf("  Trace 1 complete at frame %u. Saved trace_01.obsav & screen.png\n", oracle->current_frame);

    // ====================================================================
    // TRACE 2: Tarot Character Creation (8,600 frames total)
    // ====================================================================
    printf("[CANONICAL TRACE 2] Recording trace_02_tarot_creation.obrec (8,600 frames)...\n");
    ReplayTrace* t2 = replay_create("trace_02_tarot_creation", 8600);
    assert(t2 != NULL);

    for (uint32_t f = 0; f < 3000; ++f) {
        replay_record_frame(t2, replay_get_frame_input(t1, f));
    }
    replay_free(t1);

    // Frames 3000..8600: Enter Warren, Name/Birthday, all 6 Tarot questions to reach World Map
    for (uint32_t f = 3000; f < 8600; ++f) {
        uint16_t pad = ((f % 20) < 5) ? (SNES_BTN_A | SNES_BTN_START) : 0;
        replay_record_frame(t2, pad);
        oracle_step_frame(oracle, pad);
    }
    assert(replay_save_file(t2, "traces/trace_02_tarot_creation.obrec"));
    oracle_save_state(oracle, "traces/trace_02.obsav");
    save_png(oracle->snes, "traces/trace_02_screen.png");
    printf("  Trace 2 complete at frame %u. Saved trace_02.obsav & screen.png\n", oracle->current_frame);

    // ====================================================================
    // TRACE 3: Felnamia Castle Deploy (9,500 frames total)
    // ====================================================================
    printf("[CANONICAL TRACE 3] Recording trace_03_felnamia_deploy.obrec (9,500 frames)...\n");
    ReplayTrace* t3 = replay_create("trace_03_felnamia_deploy", 9500);
    assert(t3 != NULL);

    for (uint32_t f = 0; f < 8600; ++f) {
        replay_record_frame(t3, replay_get_frame_input(t2, f));
    }

    // Frames 8600..8660: Settle on World Map
    for (uint32_t f = 8600; f < 8660; ++f) {
        replay_record_frame(t3, 0);
        oracle_step_frame(oracle, 0);
    }
    // Frames 8660..8670: Press B to close World Map menu
    for (uint32_t f = 8660; f < 8670; ++f) {
        replay_record_frame(t3, SNES_BTN_B);
        oracle_step_frame(oracle, SNES_BTN_B);
    }
    // Frames 8670..8690: Settle
    for (uint32_t f = 8670; f < 8690; ++f) {
        replay_record_frame(t3, 0);
        oracle_step_frame(oracle, 0);
    }
    // Frames 8690..8700: Press A to enter Castle of Warren
    for (uint32_t f = 8690; f < 8700; ++f) {
        replay_record_frame(t3, SNES_BTN_A);
        oracle_step_frame(oracle, SNES_BTN_A);
    }
    // Frames 8700..9200: Load map and clear stage briefing
    for (uint32_t f = 8700; f < 9200; ++f) {
        uint16_t pad = (f > 8900 && (f % 30 < 5)) ? SNES_BTN_A : 0;
        replay_record_frame(t3, pad);
        oracle_step_frame(oracle, pad);
    }
    // Frames 9200..9420: Open Felnamia Castle menu, select Deploy, confirm Unit 1
    for (uint32_t f = 9200; f < 9420; ++f) {
        uint32_t step = f - 9200;
        uint16_t pad = 0;
        if (step >= 20 && step < 35) pad = SNES_BTN_A;       // Open Castle Menu
        else if (step >= 80 && step < 95) pad = SNES_BTN_A;  // Select Deploy Unit
        else if (step >= 160 && step < 175) pad = SNES_BTN_A;// Confirm Unit 1 Deploy
        replay_record_frame(t3, pad);
        oracle_step_frame(oracle, pad);
    }
    // Frames 9420..9500: Wait for READY deploy animation
    for (uint32_t f = 9420; f < 9500; ++f) {
        replay_record_frame(t3, 0);
        oracle_step_frame(oracle, 0);
    }

    assert(replay_save_file(t3, "traces/trace_03_felnamia_deploy.obrec"));
    oracle_save_state(oracle, "traces/trace_03.obsav");
    save_png(oracle->snes, "traces/trace_03_screen.png");
    printf("  Trace 3 complete at frame %u. Saved trace_03.obsav & screen.png\n", oracle->current_frame);

    // ====================================================================
    // TRACE 4: Tactical March & Real-time Clock (10,800 frames total)
    // ====================================================================
    printf("[CANONICAL TRACE 4] Recording trace_04_tactical_march_clock.obrec (10,800 frames)...\n");
    ReplayTrace* t4 = replay_create("trace_04_tactical_march_clock", 10800);
    assert(t4 != NULL);

    for (uint32_t f = 0; f < 9500; ++f) {
        replay_record_frame(t4, replay_get_frame_input(t3, f));
    }
    replay_free(t3);

    // Dismiss first tutorial sequence
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_R); oracle_step_frame(oracle, SNES_BTN_R); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_UP); oracle_step_frame(oracle, SNES_BTN_UP); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }

    // Real Move Order
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_R); oracle_step_frame(oracle, SNES_BTN_R); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_UP); oracle_step_frame(oracle, SNES_BTN_UP); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }

    // Pan destination UP and RIGHT towards Daskania waypoint (80 frames)
    for (int f = 0; f < 80; ++f) {
        replay_record_frame(t4, SNES_BTN_UP | SNES_BTN_RIGHT);
        oracle_step_frame(oracle, SNES_BTN_UP | SNES_BTN_RIGHT);
    }
    for (int f = 0; f < 20; ++f) {
        replay_record_frame(t4, 0);
        oracle_step_frame(oracle, 0);
    }

    // Confirm destination with A!
    for (int f = 0; f < 10; ++f) { replay_record_frame(t4, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t4, 0); oracle_step_frame(oracle, 0); }

    // Real-time tactical march across the road advancing day/night clock (up to frame 10,800)
    while (oracle->current_frame < 10800) {
        replay_record_frame(t4, 0);
        oracle_step_frame(oracle, 0);
    }

    assert(replay_save_file(t4, "traces/trace_04_tactical_march_clock.obrec"));
    oracle_save_state(oracle, "traces/trace_04.obsav");
    save_png(oracle->snes, "traces/trace_04_screen.png");
    printf("  Trace 4 complete at frame %u. Saved trace_04.obsav & screen.png\n", oracle->current_frame);

    // ====================================================================
    // TRACE 5: Battle Encounter & Combat Rounds (12,850 frames total)
    // ====================================================================
    printf("[CANONICAL TRACE 5] Recording trace_05_battle_encounter.obrec (12,850 frames)...\n");
    ReplayTrace* t5 = replay_create("trace_05_battle_encounter", 12850);
    assert(t5 != NULL);

    for (uint32_t f = 0; f < 10800; ++f) {
        replay_record_frame(t5, replay_get_frame_input(t4, f));
    }
    replay_free(t4);

    // Issue Move order along road towards enemy encounter
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_L); oracle_step_frame(oracle, SNES_BTN_L); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_UP); oracle_step_frame(oracle, SNES_BTN_UP); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }

    // Pan UP 40 frames
    for (int f = 0; f < 40; ++f) { replay_record_frame(t5, SNES_BTN_UP); oracle_step_frame(oracle, SNES_BTN_UP); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t5, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t5, 0); oracle_step_frame(oracle, 0); }

    // March, trigger Battle Arena in Bank $05, fight 3 combat rounds, win and draw tarot card
    while (oracle->current_frame < 12850) {
        uint16_t pad = (oracle->current_frame < 12770 && oracle->current_frame % 25 < 5) ? SNES_BTN_A : 0;
        replay_record_frame(t5, pad);
        oracle_step_frame(oracle, pad);
    }

    assert(replay_save_file(t5, "traces/trace_05_battle_encounter.obrec"));
    oracle_save_state(oracle, "traces/trace_05.obsav");
    save_png(oracle->snes, "traces/trace_05_screen.png");
    printf("  Trace 5 complete at frame %u. Saved trace_05.obsav & screen.png\n", oracle->current_frame);

    // ====================================================================
    // TRACE 6: Daskania Town Liberation & Tarot Draw (14,000 frames total)
    // ====================================================================
    printf("[CANONICAL TRACE 6] Recording trace_06_daskania_liberation.obrec (14,000 frames)...\n");
    ReplayTrace* t6 = replay_create("trace_06_daskania_liberation", 14000);
    assert(t6 != NULL);

    for (uint32_t f = 0; f < 12850; ++f) {
        replay_record_frame(t6, replay_get_frame_input(t5, f));
    }
    replay_free(t5);

    // Open Move menu from combat location
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_LEFT); oracle_step_frame(oracle, SNES_BTN_LEFT); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }

    // Pan 8 LEFT, 10 DOWN into Daskania
    for (int f = 0; f < 8; ++f) { replay_record_frame(t6, SNES_BTN_LEFT); oracle_step_frame(oracle, SNES_BTN_LEFT); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_DOWN); oracle_step_frame(oracle, SNES_BTN_DOWN); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }

    // Plant flag
    for (int f = 0; f < 10; ++f) { replay_record_frame(t6, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t6, 0); oracle_step_frame(oracle, 0); }

    // March into Daskania, liberate town, draw Tarot card (The Sun / Fortune)
    while (oracle->current_frame < 14000) {
        uint16_t pad = (oracle->current_frame % 25 < 5) ? SNES_BTN_A : 0;
        replay_record_frame(t6, pad);
        oracle_step_frame(oracle, pad);
    }

    assert(replay_save_file(t6, "traces/trace_06_daskania_liberation.obrec"));
    oracle_save_state(oracle, "traces/trace_06.obsav");
    save_png(oracle->snes, "traces/trace_06_screen.png");
    printf("  Trace 6 complete at frame %u. Saved trace_06.obsav & screen.png\n", oracle->current_frame);

    // ====================================================================
    // TRACE 7: March to Volzak, Encounter Combat & Warren Confrontation (15,700 frames)
    // ====================================================================
    printf("[CANONICAL TRACE 7] Recording trace_07_warren_boss_clear.obrec (15,700 frames)...\n");
    ReplayTrace* t7 = replay_create("trace_07_warren_boss_clear", 15700);
    assert(t7 != NULL);

    for (uint32_t f = 0; f < 14000; ++f) {
        replay_record_frame(t7, replay_get_frame_input(t6, f));
    }
    replay_free(t6);

    // Select Unit 1 with L
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_L); oracle_step_frame(oracle, SNES_BTN_L); }
    for (int f = 0; f < 50; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 50; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Select Move
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 50; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Select Road March
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 50; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Dismiss banner: tap LEFT then A
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_LEFT); oracle_step_frame(oracle, SNES_BTN_LEFT); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Pan onto Volzak Castle [ ? ]: 27 LEFT, 4 DOWN
    for (int f = 0; f < 27; ++f) { replay_record_frame(t7, SNES_BTN_LEFT); oracle_step_frame(oracle, SNES_BTN_LEFT); }
    for (int f = 0; f < 4; ++f) { replay_record_frame(t7, SNES_BTN_DOWN); oracle_step_frame(oracle, SNES_BTN_DOWN); }
    for (int f = 0; f < 20; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Plant flag (opens confirmation modal)
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Confirm modal (commences march towards Volzak Castle)
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // March with pad = 0 until encounter dialogue appears at frame 14932
    while (oracle->last_snapshot.cpu.pc != 0xA6D6 && oracle->last_snapshot.cpu.pc != 0xA6D4) {
        replay_record_frame(t7, 0);
        oracle_step_frame(oracle, 0);
    }

    // Dismiss encounter dialogue with A
    for (int f = 0; f < 10; ++f) { replay_record_frame(t7, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t7, 0); oracle_step_frame(oracle, 0); }

    // Combat round in Bank $05 (300 frames)
    for (int f = 0; f < 300; ++f) {
        uint16_t pad = (f % 20 < 5) ? SNES_BTN_A : 0;
        replay_record_frame(t7, pad);
        oracle_step_frame(oracle, pad);
    }
    while (oracle->last_snapshot.cpu.k != 0x00) {
        replay_record_frame(t7, SNES_BTN_A);
        oracle_step_frame(oracle, SNES_BTN_A);
    }

    // Dismiss post-combat tarot card / summary with A (100 frames)
    for (int f = 0; f < 100; ++f) {
        uint16_t pad = (f % 20 < 5) ? SNES_BTN_A : 0;
        replay_record_frame(t7, pad);
        oracle_step_frame(oracle, pad);
    }

    // Auto-resume march with pad = 0 straight into Sage Warren's Castle at frame 15408
    while (oracle->last_snapshot.cpu.pc != 0xA6D6 && oracle->last_snapshot.cpu.pc != 0xA6D4) {
        replay_record_frame(t7, 0);
        oracle_step_frame(oracle, 0);
    }

    // Advance Sage Warren's confrontation dialogue with periodic A
    for (int f = 0; f < 200; ++f) {
        uint16_t pad = (f % 20 < 5) ? SNES_BTN_A : 0;
        replay_record_frame(t7, pad);
        oracle_step_frame(oracle, pad);
    }

    // Settle on tactical map with pad = 0 to frame 15,700
    while (oracle->current_frame < 15700) {
        replay_record_frame(t7, 0);
        oracle_step_frame(oracle, 0);
    }

    assert(replay_save_file(t7, "traces/trace_07_warren_boss_clear.obrec"));
    oracle_save_state(oracle, "traces/trace_07.obsav");
    save_png(oracle->snes, "traces/trace_07_screen.png");
    replay_free(t7);
    printf("  Trace 7 complete at frame %u. Saved trace_07.obsav & screen.png\n", oracle->current_frame);

    oracle_free(oracle);

    // ====================================================================
    // TRACE 8: Zenobia World Map Battery Backup Save (9,000 frames total)
    // ====================================================================
    printf("[CANONICAL TRACE 8] Recording trace_08_world_map_save.obrec (9,000 frames)...\n");
    oracle = oracle_init(rom_path);
    assert(oracle != NULL);

    ReplayTrace* t8 = replay_create("trace_08_world_map_save", 9000);
    assert(t8 != NULL);

    // Replay Trace 02 through frame 8600 (arrives on Zenobia World Map)
    for (uint32_t f = 0; f < 8600; ++f) {
        uint16_t pad = replay_get_frame_input(t2, f);
        replay_record_frame(t8, pad);
        oracle_step_frame(oracle, pad);
    }
    replay_free(t2);

    // Settle on World Map for 60 frames
    for (int f = 0; f < 60; ++f) {
        replay_record_frame(t8, 0);
        oracle_step_frame(oracle, 0);
    }

    // Press RIGHT twice to focus 3rd icon (DATA / Quill)
    for (int f = 0; f < 10; ++f) { replay_record_frame(t8, SNES_BTN_RIGHT); oracle_step_frame(oracle, SNES_BTN_RIGHT); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t8, 0); oracle_step_frame(oracle, 0); }
    for (int f = 0; f < 10; ++f) { replay_record_frame(t8, SNES_BTN_RIGHT); oracle_step_frame(oracle, SNES_BTN_RIGHT); }
    for (int f = 0; f < 30; ++f) { replay_record_frame(t8, 0); oracle_step_frame(oracle, 0); }

    // Press A to open DATA menu (SAVE / LOAD)
    for (int f = 0; f < 10; ++f) { replay_record_frame(t8, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t8, 0); oracle_step_frame(oracle, 0); }

    // Press A to choose SAVE (opens Slot 1 / 2 / 3 selection)
    for (int f = 0; f < 10; ++f) { replay_record_frame(t8, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 40; ++f) { replay_record_frame(t8, 0); oracle_step_frame(oracle, 0); }

    // Press A to confirm Save to Slot 1 (triggers SRAM write)
    for (int f = 0; f < 10; ++f) { replay_record_frame(t8, SNES_BTN_A); oracle_step_frame(oracle, SNES_BTN_A); }
    for (int f = 0; f < 60; ++f) { replay_record_frame(t8, 0); oracle_step_frame(oracle, 0); }

    // Settle with pad = 0 to frame 9000
    while (oracle->current_frame < 9000) {
        replay_record_frame(t8, 0);
        oracle_step_frame(oracle, 0);
    }

    // Verify Cartridge SRAM has battery save data
    uint8_t* sram = oracle->snes->cart->ram;
    uint32_t nonzero_sram = 0;
    for (int i = 0; i < 8192; ++i) {
        if (sram[i] != 0) nonzero_sram++;
    }
    printf("  Cartridge SRAM verified: %u bytes written to Slot 1!\n", nonzero_sram);
    assert(nonzero_sram > 2000);

    assert(replay_save_file(t8, "traces/trace_08_world_map_save.obrec"));
    oracle_save_state(oracle, "traces/trace_08.obsav");
    save_png(oracle->snes, "traces/trace_08_screen.png");
    replay_free(t8);
    printf("  Trace 8 complete at frame %u. Saved trace_08.obsav & screen.png\n", oracle->current_frame);

    oracle_free(oracle);

    printf("\n====================================================================\n");
    printf("ALL 8 CANONICAL WALKTHROUGH TRACES GENERATED AND SAVED SUCCESSFULLY!\n");
    printf("====================================================================\n");
    return 0;
}
