#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lockstep.h"
#include "oracle.h"
#include "replay.h"
#include "snapshot.h"

int main(int argc, char **argv) {
    const char *rom_path = (argc > 1) ? argv[1] : "ogre_battle.sfc";

    printf("=== Ogre Battle Oracle & Lockstep Harness Test ===\n");

    /* 1. Replay trace round-trip */
    ReplayTrace *trace = replay_create("unit_test_boot", 128);
    assert(trace != NULL);
    for (int i = 0; i < 60; i++) {
        uint16_t btn = (i == 45) ? SNES_BTN_START : 0;
        assert(replay_record_frame(trace, btn));
    }
    assert(trace->header.frame_count == 60);
    assert(replay_get_frame_input(trace, 45) == SNES_BTN_START);
    assert(replay_get_frame_input(trace, 999) == 0);

    const char *tmp_obrec = "/tmp/test_oracle_unit.obrec";
    assert(replay_save_file(trace, tmp_obrec));
    ReplayTrace *loaded = replay_load_file(tmp_obrec);
    assert(loaded != NULL);
    assert(loaded->header.frame_count == 60);
    assert(memcmp(trace->inputs, loaded->inputs, 60 * sizeof(uint16_t)) == 0);
    remove(tmp_obrec);
    printf("[PASS] Replay round-trip (60 frames)\n");

    /* 2. Oracle stepping + snapshot round-trip */
    OracleRunner *oracle = oracle_init(rom_path);
    assert(oracle != NULL);
    for (int i = 0; i < 30; i++) {
        oracle_step_frame(oracle, 0);
    }
    OgreBattleSnapshot snap1;
    oracle_get_snapshot(oracle, &snap1);

    const char *tmp_obsav = "/tmp/test_oracle_unit.obsav";
    assert(snapshot_save_file(&snap1, tmp_obsav));
    OgreBattleSnapshot snap2;
    assert(snapshot_load_file(&snap2, tmp_obsav));
    remove(tmp_obsav);

    SnapshotDiff diff;
    assert(snapshot_compare(&snap1, &snap2, &diff));
    oracle_free(oracle);
    printf("[PASS] Oracle + Snapshot round-trip\n");

    /* 3. Dual-execution lockstep (RM_BOTH) */
    LockstepHarness *harness = lockstep_init(rom_path, RM_BOTH);
    assert(harness != NULL);
    assert(lockstep_run_trace(harness, loaded));
    lockstep_free(harness);
    printf("[PASS] Lockstep RM_BOTH (60 frames bit-exact)\n");

    replay_free(trace);
    replay_free(loaded);
    printf("=== All Oracle Harness Tests Passed ===\n");
    return 0;
}
