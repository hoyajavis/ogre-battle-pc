#include "oracle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

OracleRunner* oracle_init(const char* rom_path) {
    if (!rom_path) return NULL;

    FILE* f = fopen(rom_path, "rb");
    if (!f) {
        fprintf(stderr, "[ORACLE] Failed to open ROM: %s\n", rom_path);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    uint8_t* rom = (uint8_t*)malloc(size);
    if (!rom) {
        fclose(f);
        return NULL;
    }

    if (fread(rom, 1, size, f) != (size_t)size) {
        free(rom);
        fclose(f);
        return NULL;
    }
    fclose(f);

    Snes* snes = snes_init();
    if (!snes) {
        free(rom);
        return NULL;
    }

    snes_loadRom(snes, rom, size);
    snes_reset(snes, true);

    // Set controller 1 as standard gamepad
    snes->input1->type = inputDeviceController;
    snes->input2->type = inputDeviceNone;

    OracleRunner* oracle = (OracleRunner*)malloc(sizeof(OracleRunner));
    if (!oracle) {
        snes_free(snes);
        free(rom);
        return NULL;
    }

    oracle->snes = snes;
    oracle->rom_data = rom;
    oracle->rom_size = size;
    oracle->current_frame = 0;
    oracle->lockstep_active = true;

    snapshot_capture(snes, &oracle->last_snapshot, 0);
    return oracle;
}

void oracle_free(OracleRunner* oracle) {
    if (!oracle) return;
    if (oracle->snes) snes_free(oracle->snes);
    if (oracle->rom_data) free(oracle->rom_data);
    free(oracle);
}

void oracle_reset(OracleRunner* oracle) {
    if (!oracle || !oracle->snes) return;
    snes_reset(oracle->snes, true);
    oracle->current_frame = 0;
    snapshot_capture(oracle->snes, &oracle->last_snapshot, 0);
}

void oracle_step_frame(OracleRunner* oracle, uint16_t joypad_input) {
    if (!oracle || !oracle->snes) return;

    // Set controller 1 state for this frame
    oracle->snes->input1->currentState = joypad_input;

    // Run 1 frame through LakeSnes cycle execution
    snes_runFrame(oracle->snes);
    oracle->current_frame++;

    // Update snapshot
    snapshot_capture(oracle->snes, &oracle->last_snapshot, oracle->current_frame);
}

void oracle_get_snapshot(OracleRunner* oracle, OgreBattleSnapshot* out_snapshot) {
    if (!oracle || !out_snapshot) return;
    *out_snapshot = oracle->last_snapshot;
}

bool oracle_save_state(OracleRunner* oracle, const char* filepath) {
    if (!oracle || !filepath) return false;
    return snapshot_save_file(&oracle->last_snapshot, filepath);
}

bool oracle_load_state(OracleRunner* oracle, const char* filepath) {
    if (!oracle || !filepath) return false;
    OgreBattleSnapshot loaded;
    if (!snapshot_load_file(&loaded, filepath)) return false;

    if (!snapshot_restore(oracle->snes, &loaded)) return false;
    oracle->last_snapshot = loaded;
    oracle->current_frame = loaded.frame_number;
    return true;
}

bool oracle_run_replay(OracleRunner* oracle, const ReplayTrace* trace, OgreBattleSnapshot* final_snapshot) {
    if (!oracle || !trace) return false;

    oracle_reset(oracle);
    for (uint32_t f = 0; f < trace->header.frame_count; ++f) {
        uint16_t input = replay_get_frame_input(trace, f);
        oracle_step_frame(oracle, input);
    }

    if (final_snapshot) {
        *final_snapshot = oracle->last_snapshot;
    }
    return true;
}
