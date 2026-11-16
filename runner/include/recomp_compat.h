#ifndef OGRE_BATTLE_RECOMP_COMPAT_H
#define OGRE_BATTLE_RECOMP_COMPAT_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct Snes;
typedef void (*snes_func_t)(void);

void snesrecomp_set_snes(struct Snes *snes);
struct Snes *snesrecomp_get_snes(void);
void func_table_register_flags(uint32_t snes_addr, snes_func_t func, bool is_long);

extern void (*g_cpuOpcodeHook)(void *mem, uint32_t pb_pc, uint8_t opcode, bool mf, bool xf);
extern void (*g_cartReadHook)(uint32_t rom_offset, bool is_dma);

#ifdef __cplusplus
}
#endif

#endif /* OGRE_BATTLE_RECOMP_COMPAT_H */
