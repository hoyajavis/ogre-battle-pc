#include "snapshot.h"
#include <stdio.h>
#include <string.h>

static uint8_t pack_cpu_flags(const Cpu* cpu) {
    uint8_t flags = 0;
    if (cpu->n)  flags |= (1 << 7);
    if (cpu->v)  flags |= (1 << 6);
    if (cpu->mf) flags |= (1 << 5);
    if (cpu->xf) flags |= (1 << 4);
    if (cpu->d)  flags |= (1 << 3);
    if (cpu->i)  flags |= (1 << 2);
    if (cpu->z)  flags |= (1 << 1);
    if (cpu->c)  flags |= (1 << 0);
    return flags;
}

static void unpack_cpu_flags(Cpu* cpu, uint8_t flags) {
    cpu->n  = (flags & (1 << 7)) != 0;
    cpu->v  = (flags & (1 << 6)) != 0;
    cpu->mf = (flags & (1 << 5)) != 0;
    cpu->xf = (flags & (1 << 4)) != 0;
    cpu->d  = (flags & (1 << 3)) != 0;
    cpu->i  = (flags & (1 << 2)) != 0;
    cpu->z  = (flags & (1 << 1)) != 0;
    cpu->c  = (flags & (1 << 0)) != 0;
}

void snapshot_capture(Snes* snes, OgreBattleSnapshot* out_snapshot, uint32_t frame_number) {
    if (!snes || !out_snapshot) return;

    memset(out_snapshot, 0, sizeof(OgreBattleSnapshot));
    out_snapshot->magic = OBSAV_MAGIC;
    out_snapshot->version = OBSAV_VERSION;
    out_snapshot->frame_number = frame_number;

    // Capture CPU registers
    Cpu* cpu = snes->cpu;
    out_snapshot->cpu.a     = cpu->a;
    out_snapshot->cpu.x     = cpu->x;
    out_snapshot->cpu.y     = cpu->y;
    out_snapshot->cpu.sp    = cpu->sp;
    out_snapshot->cpu.pc    = cpu->pc;
    out_snapshot->cpu.dp    = cpu->dp;
    out_snapshot->cpu.k     = cpu->k;
    out_snapshot->cpu.db    = cpu->db;
    out_snapshot->cpu.flags = pack_cpu_flags(cpu);

    // Capture Work RAM (128 KB)
    memcpy(out_snapshot->wram, snes->ram, 0x20000);

    // Capture PPU Memories
    Ppu* ppu = snes->ppu;
    memcpy(out_snapshot->vram, ppu->vram, 0x8000 * sizeof(uint16_t));
    memcpy(out_snapshot->cgram, ppu->cgram, 0x100 * sizeof(uint16_t));
    memcpy(out_snapshot->oam, ppu->oam, 0x100 * sizeof(uint16_t));
    memcpy(out_snapshot->highOam, ppu->highOam, 0x20);

    // Capture Cartridge Battery SRAM if present
    if (snes->cart && snes->cart->ram && snes->cart->ramSize > 0) {
        size_t copy_size = snes->cart->ramSize > 0x2000 ? 0x2000 : snes->cart->ramSize;
        memcpy(out_snapshot->sram, snes->cart->ram, copy_size);
    }
}

bool snapshot_restore(Snes* snes, const OgreBattleSnapshot* in_snapshot) {
    if (!snes || !in_snapshot) return false;
    if (in_snapshot->magic != OBSAV_MAGIC || in_snapshot->version != OBSAV_VERSION) {
        fprintf(stderr, "[ERROR] Corrupt snapshot magic/version!\n");
        return false;
    }

    // Restore CPU registers
    Cpu* cpu = snes->cpu;
    cpu->a  = in_snapshot->cpu.a;
    cpu->x  = in_snapshot->cpu.x;
    cpu->y  = in_snapshot->cpu.y;
    cpu->sp = in_snapshot->cpu.sp;
    cpu->pc = in_snapshot->cpu.pc;
    cpu->dp = in_snapshot->cpu.dp;
    cpu->k  = in_snapshot->cpu.k;
    cpu->db = in_snapshot->cpu.db;
    unpack_cpu_flags(cpu, in_snapshot->cpu.flags);

    // Restore Work RAM
    memcpy(snes->ram, in_snapshot->wram, 0x20000);

    // Restore PPU Memories
    Ppu* ppu = snes->ppu;
    memcpy(ppu->vram, in_snapshot->vram, 0x8000 * sizeof(uint16_t));
    memcpy(ppu->cgram, in_snapshot->cgram, 0x100 * sizeof(uint16_t));
    memcpy(ppu->oam, in_snapshot->oam, 0x100 * sizeof(uint16_t));
    memcpy(ppu->highOam, in_snapshot->highOam, 0x20);

    // Restore SRAM
    if (snes->cart && snes->cart->ram && snes->cart->ramSize > 0) {
        size_t copy_size = snes->cart->ramSize > 0x2000 ? 0x2000 : snes->cart->ramSize;
        memcpy(snes->cart->ram, in_snapshot->sram, copy_size);
    }

    return true;
}

bool snapshot_save_file(const OgreBattleSnapshot* snapshot, const char* filepath) {
    if (!snapshot || !filepath) return false;
    FILE* f = fopen(filepath, "wb");
    if (!f) {
        fprintf(stderr, "[ERROR] Cannot open snapshot destination: %s\n", filepath);
        return false;
    }
    size_t written = fwrite(snapshot, 1, sizeof(OgreBattleSnapshot), f);
    fclose(f);
    return written == sizeof(OgreBattleSnapshot);
}

bool snapshot_load_file(OgreBattleSnapshot* out_snapshot, const char* filepath) {
    if (!out_snapshot || !filepath) return false;
    FILE* f = fopen(filepath, "rb");
    if (!f) return false;

    size_t read = fread(out_snapshot, 1, sizeof(OgreBattleSnapshot), f);
    fclose(f);

    if (read != sizeof(OgreBattleSnapshot)) return false;
    if (out_snapshot->magic != OBSAV_MAGIC || out_snapshot->version != OBSAV_VERSION) return false;
    return true;
}

bool snapshot_compare(const OgreBattleSnapshot* ref, const OgreBattleSnapshot* test, SnapshotDiff* out_diff) {
    if (!ref || !test) return false;
    if (out_diff) memset(out_diff, 0, sizeof(SnapshotDiff));

    bool identical = true;

    // Compare CPU state (tracked for diagnostic insight)
    if (memcmp(&ref->cpu, &test->cpu, sizeof(CpuStateSnapshot)) != 0) {
        if (out_diff) out_diff->cpu_mismatch = true;
    }

    // Compare WRAM (128 KB)
    for (size_t i = 0; i < 0x20000; ++i) {
        // Stack scratch below active SP: in 65816, the stack grows downwards.
        // Popped memory below SP (when SP is in sync) is unallocated scratch (matches snesrecomp validate_compare).
        if (ref->cpu.sp == test->cpu.sp && i <= ref->cpu.sp && i > (size_t)(ref->cpu.sp > 0x100 ? ref->cpu.sp - 0x100 : 0)) {
            continue;
        }
        if (ref->wram[i] != test->wram[i]) {
            identical = false;
            if (out_diff) {
                if (out_diff->wram_diff_count == 0) {
                    out_diff->first_wram_diff_addr = (uint32_t)i;
                    out_diff->expected_wram_val = ref->wram[i];
                    out_diff->actual_wram_val = test->wram[i];
                }
                out_diff->wram_diff_count++;
            }
        }
    }

    // Compare VRAM (64 KB)
    for (size_t i = 0; i < 0x8000; ++i) {
        if (ref->vram[i] != test->vram[i]) {
            identical = false;
            if (out_diff) {
                if (out_diff->vram_diff_count == 0) {
                    out_diff->first_vram_diff_addr = (uint32_t)i;
                    out_diff->expected_vram_val = ref->vram[i];
                    out_diff->actual_vram_val = test->vram[i];
                }
                out_diff->vram_diff_count++;
            }
        }
    }

    // Compare CGRAM
    for (size_t i = 0; i < 0x100; ++i) {
        if (ref->cgram[i] != test->cgram[i]) {
            identical = false;
            if (out_diff) out_diff->cgram_diff_count++;
        }
    }

    // Compare OAM
    for (size_t i = 0; i < 0x100; ++i) {
        if (ref->oam[i] != test->oam[i]) {
            identical = false;
            if (out_diff) out_diff->oam_diff_count++;
        }
    }

    return identical;
}

void snapshot_print_diff(const SnapshotDiff* diff) {
    if (!diff) return;
    printf("=== SNAPSHOT DIFFERENCE REPORT ===\n");
    if (diff->cpu_mismatch) {
        printf("  [DIFF] CPU Registers mismatch\n");
    }
    if (diff->wram_diff_count > 0) {
        printf("  [DIFF] WRAM bytes different: %zu\n", diff->wram_diff_count);
        printf("         First divergence at WRAM 0x7E:%04X (Expected 0x%02X, Actual 0x%02X)\n",
               diff->first_wram_diff_addr, diff->expected_wram_val, diff->actual_wram_val);
    }
    if (diff->vram_diff_count > 0) {
        printf("  [DIFF] VRAM words different: %zu\n", diff->vram_diff_count);
        printf("         First divergence at VRAM 0x%04X (Expected 0x%04X, Actual 0x%04X)\n",
               diff->first_vram_diff_addr, diff->expected_vram_val, diff->actual_vram_val);
    }
    if (diff->cgram_diff_count > 0) {
        printf("  [DIFF] CGRAM palette entries different: %zu\n", diff->cgram_diff_count);
    }
    if (diff->oam_diff_count > 0) {
        printf("  [DIFF] OAM sprite attributes different: %zu\n", diff->oam_diff_count);
    }
    printf("==================================\n");
}
