#ifndef OGRE_BATTLE_REPLAY_H
#define OGRE_BATTLE_REPLAY_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define OBREC_MAGIC 0x434552424F53424F // "OBOSBREC" (Ogre Battle Replay Trace)
#define OBREC_VERSION 1

// Standard 16-bit SNES controller button bitmasks
#define SNES_BTN_B      (1 << 0)
#define SNES_BTN_Y      (1 << 1)
#define SNES_BTN_SELECT (1 << 2)
#define SNES_BTN_START  (1 << 3)
#define SNES_BTN_UP     (1 << 4)
#define SNES_BTN_DOWN   (1 << 5)
#define SNES_BTN_LEFT   (1 << 6)
#define SNES_BTN_RIGHT  (1 << 7)
#define SNES_BTN_A      (1 << 8)
#define SNES_BTN_X      (1 << 9)
#define SNES_BTN_L      (1 << 10)
#define SNES_BTN_R      (1 << 11)

#pragma pack(push, 1)

typedef struct ReplayHeader {
    uint64_t magic;          // OBREC_MAGIC
    uint32_t version;        // OBREC_VERSION
    uint32_t frame_count;    // Total frames recorded
    uint32_t initial_seed;   // Optional RNG initial seed if known
    char     title[32];      // Scenario name, e.g. "trace_01_boot_to_title"
} ReplayHeader;

#pragma pack(pop)

typedef struct ReplayTrace {
    ReplayHeader header;
    uint16_t* inputs;        // Array of 16-bit joypad1 words (frame_count items)
    size_t capacity;
} ReplayTrace;

// Create an empty trace recorder
ReplayTrace* replay_create(const char* title, size_t initial_capacity);

// Free replay trace memory
void replay_free(ReplayTrace* trace);

// Append a frame input to the trace
bool replay_record_frame(ReplayTrace* trace, uint16_t joypad_word);

// Save trace to .obrec file
bool replay_save_file(const ReplayTrace* trace, const char* filepath);

// Load trace from .obrec file
ReplayTrace* replay_load_file(const char* filepath);

// Get input word for given frame (returns 0 if past end)
uint16_t replay_get_frame_input(const ReplayTrace* trace, uint32_t frame_number);

#endif // OGRE_BATTLE_REPLAY_H
