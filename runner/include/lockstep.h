#ifndef OGRE_BATTLE_LOCKSTEP_H
#define OGRE_BATTLE_LOCKSTEP_H

#include <stdint.h>
#include <stdbool.h>
#include "oracle.h"
#include "snapshot.h"
#include "replay.h"

typedef enum LockstepExecutionMode {
    RM_REFERENCE_ONLY = 0, // Only Golden Master (LakeSnes) runs
    RM_RECOMP_ONLY    = 1, // Only Native C Recompiled code runs
    RM_BOTH           = 2  // Dual-execution with per-frame lockstep memory comparison
} LockstepExecutionMode;

typedef struct LockstepHarness {
    LockstepExecutionMode mode;
    OracleRunner* ref_oracle;       // Golden reference SNES silicon
    OracleRunner* cand_oracle;      // Candidate execution core (or 2nd instance in self-test)

    uint32_t current_frame;
    bool desync_detected;
    SnapshotDiff last_diff;

    // Optional snapshot dump paths on desync
    char ref_dump_path[256];
    char cand_dump_path[256];
} LockstepHarness;

// Initialize dual-execution lockstep harness
LockstepHarness* lockstep_init(const char* rom_path, LockstepExecutionMode mode);

// Free lockstep harness
void lockstep_free(LockstepHarness* harness);

// Reset both cores to initial power-on state
void lockstep_reset(LockstepHarness* harness);

// Step one frame on active cores with the given controller input
// In RM_BOTH mode, compares state immediately after frame execution.
// Returns true if in sync (or single-core mode), false if desynchronization detected.
bool lockstep_step_frame(LockstepHarness* harness, uint16_t joypad_input);

// Run a complete .obrec trace through the harness
// Returns true if 100% bit-exact across all frames, false on first desync.
bool lockstep_run_trace(LockstepHarness* harness, const ReplayTrace* trace);

// Dump state snapshots from both cores when a desync occurs
bool lockstep_dump_desync_states(LockstepHarness* harness, uint32_t frame);

#endif // OGRE_BATTLE_LOCKSTEP_H
