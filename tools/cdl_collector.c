#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include "snes.h"
#include "cpu.h"
#include "cart.h"
#include "dma.h"
#include "oracle.h"
#include "replay.h"
#include "opcodes_65816.h"

// Mesen-S standard CDL bitmask constants
#define CDL_CODE         0x01 // Executed as Opcode
#define CDL_DATA         0x02 // Read as Data by CPU
#define CDL_VIDEO        0x04 // Read via DMA (PPU)
#define CDL_AUDIO        0x08 // Audio / APU stream
#define CDL_JUMP_TARGET  0x10 // Jump / Branch destination
#define CDL_SUB_ENTRY    0x20 // Subroutine Call (JSR/JSL) target
#define CDL_FLAG_M8      0x40 // Accumulator width: 1 = 8-bit, 0 = 16-bit
#define CDL_FLAG_X8      0x80 // Index width: 1 = 8-bit, 0 = 16-bit

static uint8_t* g_cdl = NULL;
static uint32_t g_rom_size = 1572864; // 1.5 MB unheadered LoROM

static uint32_t s_last_pc = 0xFFFFFFFF;
static uint32_t s_expected_next_pc = 0xFFFFFFFF;
static uint8_t  s_last_opcode = 0;

static uint64_t s_opcode_count = 0;
static uint64_t s_data_read_count = 0;
static uint64_t s_dma_read_count = 0;

static inline int snes_to_lorom(uint32_t pb_pc) {
    uint8_t bank = (pb_pc >> 16) & 0x7F;
    uint16_t adr = pb_pc & 0xFFFF;
    if (adr >= 0x8000 || bank >= 0x40) {
        return (int)(((bank << 15) | (adr & 0x7FFF)) & (g_rom_size - 1));
    }
    return -1;
}

static void on_cpu_opcode(void* mem, uint32_t pb_pc, uint8_t opcode, bool mf, bool xf) {
    s_opcode_count++;
    int rom_off = snes_to_lorom(pb_pc);
    if (rom_off >= 0 && rom_off < (int)g_rom_size) {
        uint8_t flags = CDL_CODE;
        if (mf) flags |= CDL_FLAG_M8;
        if (xf) flags |= CDL_FLAG_X8;

        // Subroutine entry detection: previous instruction was a call
        if (s_last_opcode == 0x20 || s_last_opcode == 0x22 || s_last_opcode == 0xFC) {
            flags |= CDL_SUB_ENTRY;
        }

        // Jump target detection: non-sequential control flow
        if (pb_pc != s_expected_next_pc && s_expected_next_pc != 0xFFFFFFFF) {
            flags |= CDL_JUMP_TARGET;
        }

        g_cdl[rom_off] |= flags;
    }

    int len = get_65816_insn_len(opcode, mf, xf);
    s_last_pc = pb_pc;
    s_last_opcode = opcode;

    // Determine if instruction is terminal / unconditional
    switch (opcode) {
        case 0x4C: // JMP abs
        case 0x5C: // JML long
        case 0x6C: // JMP (abs)
        case 0x7C: // JMP (abs,X)
        case 0xDC: // JML [abs]
        case 0x80: // BRA
        case 0x82: // BRL
        case 0x60: // RTS
        case 0x6B: // RTL
        case 0x40: // RTI
        case 0xDB: // STP
            s_expected_next_pc = 0xFFFFFFFF;
            break;
        default:
            s_expected_next_pc = ((pb_pc & 0xFF0000) | ((pb_pc + len) & 0xFFFF));
            break;
    }
}

static void on_cart_read(uint32_t rom_offset, bool is_dma) {
    if (rom_offset < g_rom_size) {
        if (is_dma) {
            g_cdl[rom_offset] |= CDL_VIDEO;
            s_dma_read_count++;
        } else {
            g_cdl[rom_offset] |= CDL_DATA;
            s_data_read_count++;
        }
    }
}

int main(int argc, char* argv[]) {
    const char* rom_path = "ogre_battle.sfc";
    const char* cdl_out_path = "ogre_battle.cdl";

    if (argc > 1) rom_path = argv[1];
    if (argc > 2) cdl_out_path = argv[2];

    printf("====================================================================\n");
    printf("Ogre Battle Dynamic CDL Collector (Mesen-S Format)\n");
    printf("Target ROM: %s\n", rom_path);
    printf("Output CDL: %s\n", cdl_out_path);
    printf("====================================================================\n\n");

    // Allocate CDL bitmask
    g_cdl = (uint8_t*)calloc(g_rom_size, 1);
    assert(g_cdl != NULL);

    // Initialize LakeSnes Oracle Runner
    OracleRunner* oracle = oracle_init(rom_path);
    if (!oracle) {
        fprintf(stderr, "Failed to initialize Oracle Runner with ROM: %s\n", rom_path);
        return 1;
    }

    // Attach hooks
    g_cpuOpcodeHook = on_cpu_opcode;
    g_cartReadHook = on_cart_read;

    // Canonical Traces to replay
    const char* trace_files[] = {
        "traces/trace_01_boot_to_title.obrec",
        "traces/trace_02_tarot_creation.obrec",
        "traces/trace_03_felnamia_deploy.obrec",
        "traces/trace_04_tactical_march_clock.obrec",
        "traces/trace_05_battle_encounter.obrec",
        "traces/trace_06_daskania_liberation.obrec",
        "traces/trace_07_warren_boss_clear.obrec",
        "traces/trace_08_world_map_save.obrec"
    };
    int num_traces = sizeof(trace_files) / sizeof(trace_files[0]);

    for (int t = 0; t < num_traces; ++t) {
        ReplayTrace* trace = replay_load_file(trace_files[t]);
        if (!trace) {
            fprintf(stderr, "Warning: failed to load %s, skipping\n", trace_files[t]);
            continue;
        }

        printf("[%d/%d] Replaying %s (%u frames)...\n", 
               t + 1, num_traces, trace_files[t], trace->header.frame_count);

        oracle_reset(oracle);
        s_expected_next_pc = 0xFFFFFFFF;
        s_last_opcode = 0;

        for (uint32_t f = 0; f < trace->header.frame_count; ++f) {
            uint16_t pad = replay_get_frame_input(trace, f);
            oracle_step_frame(oracle, pad);
        }

        replay_free(trace);
    }

    // Detach hooks
    g_cpuOpcodeHook = NULL;
    g_cartReadHook = NULL;

    // Save CDL file
    FILE* f_out = fopen(cdl_out_path, "wb");
    if (!f_out) {
        fprintf(stderr, "Failed to open output CDL for writing: %s\n", cdl_out_path);
        return 1;
    }
    fwrite(g_cdl, 1, g_rom_size, f_out);
    fclose(f_out);
    printf("\nSuccessfully saved CDL file: %s (%u bytes)\n", cdl_out_path, g_rom_size);

    // Compute CDL Statistics
    uint32_t total_code = 0;
    uint32_t total_data = 0;
    uint32_t total_video = 0;
    uint32_t unique_subs = 0;
    uint32_t unique_jumps = 0;

    uint32_t bank_code[64] = {0};
    uint32_t bank_data[64] = {0};

    for (uint32_t i = 0; i < g_rom_size; ++i) {
        uint8_t c = g_cdl[i];
        if (c & CDL_CODE) total_code++;
        if (c & CDL_DATA) total_data++;
        if (c & CDL_VIDEO) total_video++;
        if (c & CDL_SUB_ENTRY) unique_subs++;
        if (c & CDL_JUMP_TARGET) unique_jumps++;

        uint8_t bank = i / 32768;
        if (bank < 64) {
            if (c & CDL_CODE) bank_code[bank]++;
            if (c & (CDL_DATA | CDL_VIDEO)) bank_data[bank]++;
        }
    }

    printf("\n====================================================================\n");
    printf("CDL PROFILING ANALYSIS SUMMARY\n");
    printf("====================================================================\n");
    printf("Total Instructions Decoded:   %lu\n", s_opcode_count);
    printf("Total Data Reads:             %lu\n", s_data_read_count);
    printf("Total DMA Reads:              %lu\n", s_dma_read_count);
    printf("Distinct Code Bytes:          %u (%.2f%% of ROM)\n", 
           total_code, (double)total_code / g_rom_size * 100.0);
    printf("Distinct Data Bytes:          %u (%.2f%% of ROM)\n", 
           total_data, (double)total_data / g_rom_size * 100.0);
    printf("Distinct Video DMA Bytes:     %u (%.2f%% of ROM)\n", 
           total_video, (double)total_video / g_rom_size * 100.0);
    printf("Unique Subroutine Entry Points: %u\n", unique_subs);
    printf("Unique Jump Targets:            %u\n", unique_jumps);

    printf("\nBank-by-Bank Code/Data Density (Active Banks):\n");
    for (int b = 0; b < 64; ++b) {
        if (bank_code[b] > 0 || bank_data[b] > 0) {
            printf("  Bank $%02X: Code: %5u B (%5.1f%%) | Data: %5u B (%5.1f%%)\n",
                   b, bank_code[b], (double)bank_code[b] / 32768.0 * 100.0,
                   bank_data[b], (double)bank_data[b] / 32768.0 * 100.0);
        }
    }
    printf("====================================================================\n");

    oracle_free(oracle);
    free(g_cdl);
    return 0;
}
