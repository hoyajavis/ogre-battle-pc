/* Bank $37 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 1 unlifted in Bank $37 */
/* not lifted: $37C502: BRK at $37:C517 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $37F0CE, entered with P=$20 via JSR */
void gen_37F0CE(void) {
    goto L_F0CE;
L_93C3:;
    recomp_tick(14); return;  /* 93C3 RTS */
L_F0CE:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0CE TAX */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0CF LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0D2 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0D3 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0D4 TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x222A)); g_cpu.X = _v; g_nz16(_v); }  /* F0D5 LDX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F0D8 TXA */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0D9 LDX */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0DC LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0DF TAX */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0E0 LDX */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0E3 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0E6 TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0xAA2A)); g_cpu.X = _v; g_nz16(_v); }  /* F0E7 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0EA TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0EB TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* F0EC INX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F0ED TXA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0EE TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0EF TAX */
    recomp_tick(14); { uint8_t _v = g_rol8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F0F0 ROL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F0F1 TXA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* F0F2 TAY */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0F3 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0F6 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0F7 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0F8 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0F9 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0FA TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0FB TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F0FC TAX */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F0FD LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F100 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F101 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F102 TAX */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.X = _v; g_nz16(_v); }  /* F103 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F106 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F107 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F108 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F109 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F10A TXA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F10B TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F10C TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* F10D DEY */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F10E ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F10F TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F110 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F111 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F112 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F113 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F114 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F115 TAX */
    recomp_tick(24); goto L_93C3;  /* F116 BRL */
}

void gen_register_bank_37(void) {
    func_table_register_flags(0x37F0CE, gen_37F0CE, false);
}
