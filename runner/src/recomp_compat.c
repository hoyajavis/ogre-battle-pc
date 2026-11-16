#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "snes.h"
#include "snesrecomp/func_table.h"

/* Runtime state pointer used by snesrecomp bus/cpu/recomp_interp and runner/lockstep */
static Snes *s_snes = NULL;

bool g_recomp_validating = false;
bool g_recomp_frame_touched = false;

void snesrecomp_set_snes(Snes *snes) {
    s_snes = snes;
}

Snes *snesrecomp_get_snes(void) {
    return s_snes;
}

/* Compatibility wrapper for generated bank registration code */
void func_table_register_flags(uint32_t snes_addr, snes_func_t func, bool is_long) {
    func_table_register(snes_addr, func);
    recomp_timed_add_intercept(snes_addr, is_long);
}

/* Optional CDL collector hooks when using unpatched upstream LakeSnes */
void (*g_cpuOpcodeHook)(void *mem, uint32_t pb_pc, uint8_t opcode, bool mf, bool xf) = NULL;
void (*g_cartReadHook)(uint32_t rom_offset, bool is_dma) = NULL;
