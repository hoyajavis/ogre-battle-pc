#ifndef OGRE_BATTLE_ORACLE_H
#define OGRE_BATTLE_ORACLE_H

#include <stdint.h>
#include <stdbool.h>

#include "snes.h"
#include "snapshot.h"
#include "replay.h"

typedef struct OracleRunner {
    Snes* snes;
    uint8_t* rom_data;
    size_t rom_size;

    uint32_t current_frame;
    bool lockstep_active;

    OgreBattleSnapshot last_snapshot;
} OracleRunner;

// Initialize Golden Master Oracle with Ogre Battle ROM
OracleRunner* oracle_init(const char* rom_path);

// Free Oracle instance
void oracle_free(OracleRunner* oracle);

// Reset Oracle to power-on state
void oracle_reset(OracleRunner* oracle);

// Step one frame with given 16-bit joypad input word
void oracle_step_frame(OracleRunner* oracle, uint16_t joypad_input);

// Capture state snapshot at current frame
void oracle_get_snapshot(OracleRunner* oracle, OgreBattleSnapshot* out_snapshot);

// Save current state to .obsav file
bool oracle_save_state(OracleRunner* oracle, const char* filepath);

// Load state from .obsav file
bool oracle_load_state(OracleRunner* oracle, const char* filepath);

// Replay a .obrec trace through the Oracle and verify deterministic output
bool oracle_run_replay(OracleRunner* oracle, const ReplayTrace* trace, OgreBattleSnapshot* final_snapshot);

#endif // OGRE_BATTLE_ORACLE_H
