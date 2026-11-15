#ifndef OGRE_BATTLE_SNAPSHOT_H
#define OGRE_BATTLE_SNAPSHOT_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "snes.h"

#define OBSAV_MAGIC 0x564153424F53424F // "OBOSBASV" (Ogre Battle Save Snapshot)
#define OBSAV_VERSION 1

#pragma pack(push, 1)

typedef struct CpuStateSnapshot {
    uint16_t a;
    uint16_t x;
    uint16_t y;
    uint16_t sp;
    uint16_t pc;
    uint16_t dp;
    uint8_t  k;
    uint8_t  db;
    uint8_t  flags; // packed P register: N, V, M, X, D, I, Z, C
} CpuStateSnapshot;

typedef struct OgreBattleSnapshot {
    uint64_t magic;           // OBSAV_MAGIC
    uint32_t version;         // OBSAV_VERSION
    uint32_t frame_number;

    CpuStateSnapshot cpu;

    uint8_t  wram[0x20000];   // 128 KB Work RAM ($7E:0000 - $7F:FFFF)
    uint16_t vram[0x8000];    // 64 KB Video RAM (Word addressed)
    uint8_t  sram[0x2000];    // 8 KB Battery Save RAM
    uint16_t cgram[0x100];    // 512 B Palette Data (256 15-bit colors)
    uint16_t oam[0x100];      // 512 B Low OAM (128 sprites x 4 bytes)
    uint8_t  highOam[0x20];   // 32 B High OAM (128 sprites x 2 bits)
} OgreBattleSnapshot;

#pragma pack(pop)

typedef struct SnapshotDiff {
    bool cpu_mismatch;
    size_t wram_diff_count;
    uint32_t first_wram_diff_addr;
    uint8_t  expected_wram_val;
    uint8_t  actual_wram_val;

    size_t vram_diff_count;
    uint32_t first_vram_diff_addr;
    uint16_t expected_vram_val;
    uint16_t actual_vram_val;

    size_t sram_diff_count;
    size_t cgram_diff_count;
    size_t oam_diff_count;
} SnapshotDiff;

// Capture current state of LakeSnes core into snapshot
void snapshot_capture(Snes* snes, OgreBattleSnapshot* out_snapshot, uint32_t frame_number);

// Restore snapshot into LakeSnes core
bool snapshot_restore(Snes* snes, const OgreBattleSnapshot* in_snapshot);

// Save snapshot to .obsav binary file
bool snapshot_save_file(const OgreBattleSnapshot* snapshot, const char* filepath);

// Load snapshot from .obsav binary file
bool snapshot_load_file(OgreBattleSnapshot* out_snapshot, const char* filepath);

// Compare two snapshots and populate diff report. Returns true if identical.
bool snapshot_compare(const OgreBattleSnapshot* ref, const OgreBattleSnapshot* test, SnapshotDiff* out_diff);

// Print human-readable diff diagnosis
void snapshot_print_diff(const SnapshotDiff* diff);

#endif // OGRE_BATTLE_SNAPSHOT_H
