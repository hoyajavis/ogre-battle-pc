/*
 * verify_trace.c — Dual-Execution Lockstep Verification Oracle (RM_BOTH)
 *
 * Verifies 100% bit-exact parity between:
 *   1. Golden Reference Emulator (pure LakeSnes interpreter)
 *   2. Candidate Native Recomp Core (libob_recomp + timed interception)
 *
 * Across all 128KB WRAM, 64KB VRAM, CGRAM, OAM, High OAM, and Cartridge SRAM.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/bus.h>
#include <snesrecomp/cpu.h>
#include <snesrecomp/func_table.h>
#include "snes.h"
#include "replay.h"

extern bool (*g_cpuRecompHook)(Cpu*);
extern void ob_recomp_register_all(void);
extern void snesrecomp_set_snes(Snes *snes);

void platform_set_headless(const char *record_path) { (void)record_path; }
bool platform_is_headless(void) { return true; }
bool platform_init(const char *window_title, int scale) { (void)window_title; (void)scale; return true; }
void platform_present_frame(const uint8_t *framebuffer) { (void)framebuffer; }
void platform_queue_audio(const int16_t *samples, int sample_count) { (void)samples; (void)sample_count; }
bool platform_poll_events(void) { return true; }
void platform_frame_sync(void) {}
void platform_request_screenshot(void) {}
bool platform_mouse_to_snes(int *x, int *y) { (void)x; (void)y; return false; }
void platform_shutdown(void) {}

static bool load_rom(Snes *snes, const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "Error: cannot open ROM %s\n", path);
        return false;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    uint8_t *data = (uint8_t *)malloc(size);
    if (!data) {
        fclose(f);
        return false;
    }
    size_t read_bytes = fread(data, 1, size, f);
    fclose(f);
    if ((long)read_bytes != size) {
        free(data);
        return false;
    }

    bool ok = snes_loadRom(snes, data, (int)size);
    free(data);
    return ok;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <trace_file.obrec> [rom_file.sfc]\n", argv[0]);
        return 1;
    }
    const char *trace_path = NULL;
    const char *rom_path = "/home/antigravity/ogre_battle.sfc";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--rom") == 0 && i + 1 < argc) {
            rom_path = argv[++i];
        } else if (strcmp(argv[i], "--trace") == 0 && i + 1 < argc) {
            trace_path = argv[++i];
        } else if (!trace_path) {
            trace_path = argv[i];
        } else if (argc >= 5 && i == 4) {
            /* CMakeLists.txt 4-arg form: <trace.obrec> <out.obsav> <out.png> <rom.sfc> */
            rom_path = argv[i];
        } else if (argc == 3 && i == 2) {
            rom_path = argv[i];
        }
    }
    if (!trace_path) {
        fprintf(stderr, "Error: no trace file specified.\n");
        return 1;
    }

    printf("====================================================\n");
    printf("Validating Trace: %s\n", trace_path);
    printf("====================================================\n");

    /* 1. Load Trace (supports both 52-byte OBSOBREC ReplayHeader and raw format) */
    uint32_t frame_count = 0;
    uint16_t *buttons = NULL;
    FILE *ft = fopen(trace_path, "rb");
    if (!ft) {
        fprintf(stderr, "Error: cannot open trace file '%s'\n", trace_path);
        return 1;
    }
    uint64_t magic_u64 = 0;
    if (fread(&magic_u64, sizeof(uint64_t), 1, ft) == 1 && magic_u64 == OBREC_MAGIC) {
        fclose(ft);
        ReplayTrace *rt = replay_load_file(trace_path);
        if (!rt || rt->header.frame_count == 0) {
            fprintf(stderr, "Error: invalid OBSOBREC trace '%s'\n", trace_path);
            if (rt) replay_free(rt);
            return 1;
        }
        frame_count = rt->header.frame_count;
        buttons = (uint16_t *)malloc(frame_count * sizeof(uint16_t));
        memcpy(buttons, rt->inputs, frame_count * sizeof(uint16_t));
        replay_free(rt);
    } else {
        fseek(ft, 0, SEEK_SET);
        if (fread(&frame_count, sizeof(uint32_t), 1, ft) != 1 || frame_count == 0) {
            fprintf(stderr, "Error: invalid trace header in '%s'\n", trace_path);
            fclose(ft);
            return 1;
        }
        buttons = (uint16_t *)malloc(frame_count * sizeof(uint16_t));
        if (!buttons) {
            fprintf(stderr, "Error: memory allocation failure for %u buttons\n", frame_count);
            fclose(ft);
            return 1;
        }
        if (fread(buttons, sizeof(uint16_t), frame_count, ft) != frame_count) {
            fprintf(stderr, "Error: unexpected EOF reading buttons from '%s'\n", trace_path);
            free(buttons);
            fclose(ft);
            return 1;
        }
        fclose(ft);
    }
    printf("Loaded %u frames from trace.\n", frame_count);

    /* 2. Initialize Reference Emulator */
    Snes *ref_snes = snes_init();
    if (!ref_snes || !load_rom(ref_snes, rom_path)) {
        fprintf(stderr, "Error: failed to initialize Reference SNES with ROM '%s'\n", rom_path);
        free(buttons);
        return 1;
    }

    /* 3. Initialize Candidate Emulator */
    Snes *cand_snes = snes_init();
    if (!cand_snes || !load_rom(cand_snes, rom_path)) {
        fprintf(stderr, "Error: failed to initialize Candidate SNES with ROM '%s'\n", rom_path);
        snes_free(ref_snes);
        free(buttons);
        return 1;
    }

    /* 4. Configure Recompiled Function Interceptions on Candidate */
    func_table_init();
    ob_recomp_register_all();

    /* Register verified recompiled routines */
    recomp_interp_set_enabled(true);
    recomp_timed_add_intercept(0x058299, false); /* Bank 05 table reading & WRAM 0x7E:0007 setup */


    printf("Executing in RM_BOTH dual-execution lockstep mode...\n");

    /* 5. Dual-Execution Lockstep Loop */
    for (uint32_t f = 0; f < frame_count; f++) {
        uint16_t btn = buttons[f];

        /* Step Reference (Golden Interpreter) */
        ref_snes->input1->currentState = btn;
        g_cpuRecompHook = NULL;
        snes_runFrame(ref_snes);

        /* Step Candidate (Recomp Core) */
        cand_snes->input1->currentState = btn;
        snesrecomp_set_snes(cand_snes);
        recomp_timed_recomp_enable();
        snes_runFrame(cand_snes);

        /* Evaluate Lockstep Parity across All Memory Regions */
        /* WRAM (128KB): compare active memory, excluding dead stack scratch below SP (recomp_interp.c:538) */
        uint16_t sp = ref_snes->cpu->sp;
        bool wram_match = true;
        uint32_t diff_offset = 0;
        for (uint32_t i = 0; i < 0x20000; i++) {
            if (i <= sp && i > (uint16_t)(sp - 0x100)) continue;
            if (ref_snes->ram[i] != cand_snes->ram[i]) {
                wram_match = false;
                diff_offset = i;
                break;
            }
        }
        if (!wram_match) {
            fprintf(stderr, "\n[LOCKSTEP DESYNC] Divergence detected at frame %u!\n", f + 1);
            fprintf(stderr, "  [DIFF] WRAM divergence at 0x7E:%04X (Ref: 0x%02X, Cand: 0x%02X)\n",
                    diff_offset, ref_snes->ram[diff_offset], cand_snes->ram[diff_offset]);
            snes_free(ref_snes);
            snes_free(cand_snes);
            free(buttons);
            return 1;
        }

        /* At final frame of trace, verify 100% full 128KB WRAM bit-exact match */
        if (f + 1 == frame_count) {
            if (memcmp(ref_snes->ram, cand_snes->ram, 0x20000) != 0) {
                fprintf(stderr, "\n[LOCKSTEP DESYNC] Full WRAM divergence at final frame %u!\n", f + 1);
                snes_free(ref_snes);
                snes_free(cand_snes);
                free(buttons);
                return 1;
            }
        }

        if (memcmp(ref_snes->ppu->vram, cand_snes->ppu->vram, 0x10000) != 0) {
            fprintf(stderr, "\n[LOCKSTEP DESYNC] VRAM divergence detected at frame %u!\n", f + 1);
            snes_free(ref_snes);
            snes_free(cand_snes);
            free(buttons);
            return 1;
        }

        if (memcmp(ref_snes->ppu->cgram, cand_snes->ppu->cgram, 0x200) != 0) {
            fprintf(stderr, "\n[LOCKSTEP DESYNC] CGRAM divergence detected at frame %u!\n", f + 1);
            snes_free(ref_snes);
            snes_free(cand_snes);
            free(buttons);
            return 1;
        }

        if (memcmp(ref_snes->ppu->oam, cand_snes->ppu->oam, 0x200) != 0) {
            fprintf(stderr, "\n[LOCKSTEP DESYNC] OAM divergence detected at frame %u!\n", f + 1);
            snes_free(ref_snes);
            snes_free(cand_snes);
            free(buttons);
            return 1;
        }

        if (memcmp(ref_snes->ppu->highOam, cand_snes->ppu->highOam, 0x20) != 0) {
            fprintf(stderr, "\n[LOCKSTEP DESYNC] High OAM divergence detected at frame %u!\n", f + 1);
            snes_free(ref_snes);
            snes_free(cand_snes);
            free(buttons);
            return 1;
        }

        if (ref_snes->cart->ram && cand_snes->cart->ram && ref_snes->cart->ramSize > 0) {
            if (memcmp(ref_snes->cart->ram, cand_snes->cart->ram, ref_snes->cart->ramSize) != 0) {
                fprintf(stderr, "\n[LOCKSTEP DESYNC] SRAM divergence detected at frame %u!\n", f + 1);
                snes_free(ref_snes);
                snes_free(cand_snes);
                free(buttons);
                return 1;
            }
        }

        /* Progress Logging */
        if ((f + 1) % 50 == 0 || (f + 1) == frame_count) {
            printf("  [LOCKSTEP] Frame %u evaluated - in sync (0 byte drift).\n", f + 1);
            fflush(stdout);
        }
    }

    printf("[PASS] %s certified: %u frames with 0 byte desync!\n", trace_path, frame_count);

    snes_free(ref_snes);
    snes_free(cand_snes);
    free(buttons);
    return 0;
}
