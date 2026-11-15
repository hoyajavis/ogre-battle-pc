#include "lockstep.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <snesrecomp/func_table.h>
#include <snesrecomp/bus.h>
#include "ob_recomp.h"

LockstepHarness* lockstep_init(const char* rom_path, LockstepExecutionMode mode) {
    if (!rom_path) return NULL;

    static bool s_recomp_registered = false;
    if (!s_recomp_registered) {
        func_table_init();
        gen_register_all();
        s_recomp_registered = true;
    }

    LockstepHarness* harness = (LockstepHarness*)malloc(sizeof(LockstepHarness));
    if (!harness) return NULL;

    memset(harness, 0, sizeof(LockstepHarness));
    harness->mode = mode;
    harness->current_frame = 0;
    harness->desync_detected = false;

    if (mode == RM_REFERENCE_ONLY || mode == RM_BOTH) {
        harness->ref_oracle = oracle_init(rom_path);
        if (!harness->ref_oracle) {
            fprintf(stderr, "[LOCKSTEP] Failed to initialize reference Oracle from %s\n", rom_path);
            free(harness);
            return NULL;
        }
    }

    if (mode == RM_RECOMP_ONLY || mode == RM_BOTH) {
        harness->cand_oracle = oracle_init(rom_path);
        if (!harness->cand_oracle) {
            fprintf(stderr, "[LOCKSTEP] Failed to initialize candidate Oracle from %s\n", rom_path);
            if (harness->ref_oracle) oracle_free(harness->ref_oracle);
            free(harness);
            return NULL;
        }
    }

    return harness;
}

void lockstep_free(LockstepHarness* harness) {
    if (!harness) return;
    if (harness->ref_oracle) oracle_free(harness->ref_oracle);
    if (harness->cand_oracle) oracle_free(harness->cand_oracle);
    free(harness);
}

void lockstep_reset(LockstepHarness* harness) {
    if (!harness) return;
    if (harness->ref_oracle) oracle_reset(harness->ref_oracle);
    if (harness->cand_oracle) oracle_reset(harness->cand_oracle);
    harness->current_frame = 0;
    harness->desync_detected = false;
    memset(&harness->last_diff, 0, sizeof(SnapshotDiff));
}

bool lockstep_step_frame(LockstepHarness* harness, uint16_t joypad_input) {
    if (!harness) return false;

    if (harness->mode == RM_BOTH) {
        // Step 1: Run reference Oracle (pure golden 65816 ROM)
        recomp_timed_recomp_disable();
        oracle_step_frame(harness->ref_oracle, joypad_input);

        // Step 2: Run candidate Oracle (recompiled native C + LakeSnes)
        snesrecomp_set_snes(harness->cand_oracle->snes);
        recomp_timed_recomp_enable();
        oracle_step_frame(harness->cand_oracle, joypad_input);
        recomp_timed_recomp_disable();

        harness->current_frame++;

        OgreBattleSnapshot ref_snap, cand_snap;
        oracle_get_snapshot(harness->ref_oracle, &ref_snap);
        oracle_get_snapshot(harness->cand_oracle, &cand_snap);

        if (!snapshot_compare(&ref_snap, &cand_snap, &harness->last_diff)) {
            harness->desync_detected = true;
            fprintf(stderr, "\n[LOCKSTEP DESYNC] Divergence detected at frame %u!\n", harness->current_frame);
            snapshot_print_diff(&harness->last_diff);
            lockstep_dump_desync_states(harness, harness->current_frame);
            return false;
        }

        if (harness->current_frame % 50 == 0) {
            printf("  [LOCKSTEP] Frame %u evaluated - in sync (0 byte drift).\n", harness->current_frame);
            fflush(stdout);
        }
        return true;
    } else if (harness->mode == RM_REFERENCE_ONLY) {
        recomp_timed_recomp_disable();
        oracle_step_frame(harness->ref_oracle, joypad_input);
        harness->current_frame++;
        return true;
    } else if (harness->mode == RM_RECOMP_ONLY) {
        snesrecomp_set_snes(harness->cand_oracle->snes);
        recomp_timed_recomp_enable();
        oracle_step_frame(harness->cand_oracle, joypad_input);
        recomp_timed_recomp_disable();
        harness->current_frame++;
        return true;
    }

    return false;
}

bool lockstep_dump_desync_states(LockstepHarness* harness, uint32_t frame) {
    if (!harness) return false;

    snprintf(harness->ref_dump_path, sizeof(harness->ref_dump_path),
             "desync_frame_%u_ref.obsav", frame);
    snprintf(harness->cand_dump_path, sizeof(harness->cand_dump_path),
             "desync_frame_%u_cand.obsav", frame);

    if (harness->ref_oracle) {
        oracle_save_state(harness->ref_oracle, harness->ref_dump_path);
        fprintf(stderr, "[LOCKSTEP] Dumped Reference snapshot to %s\n", harness->ref_dump_path);
    }
    if (harness->cand_oracle) {
        oracle_save_state(harness->cand_oracle, harness->cand_dump_path);
        fprintf(stderr, "[LOCKSTEP] Dumped Candidate snapshot to %s\n", harness->cand_dump_path);
    }

    return true;
}

bool lockstep_run_trace(LockstepHarness* harness, const ReplayTrace* trace) {
    if (!harness || !trace) return false;

    lockstep_reset(harness);
    for (uint32_t f = 0; f < trace->header.frame_count; ++f) {
        uint16_t input = replay_get_frame_input(trace, f);
        if (!lockstep_step_frame(harness, input)) {
            return false;
        }
    }

    return true;
}
