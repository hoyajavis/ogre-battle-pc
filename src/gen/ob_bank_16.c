/* Bank $16 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 7 unlifted in Bank $16 */
/* not lifted: $16A3D5: BRK at $16:5002 */
/* not lifted: $16BA00: BRK at $16:BA3B */
/* not lifted: $16E003: BRK at $16:E012 */
/* not lifted: $16E0FF: BRK at $16:E0FF */
/* not lifted: $16F7D9: PLY at $F7F4 pulls below the entry stack (return-address trick) */
/* not lifted: $16FFFC: COP at $16:FFB7 */
/* not lifted: $16FFFD: BRK at $16:80C2 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $16F87D, entered with P=$00 via JSR */
void gen_16F87D(void) {
    goto L_F87D;
L_F87D:;
    recomp_tick(16); if (g_cpu.flag_Z) goto L_F88D;  /* F87D BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F87F INC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dpily(0x6B))));  /* F880 ADC */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* F882 XBA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* F883 DEY */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x2E05FBu))));  /* F884 SBC */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F888 ASL */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_dpil(0x32))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F889 AND */
    recomp_tick(14); return;  /* F88B RTL */
L_F88D:;
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x234052u))));  /* F88D SBC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x63))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F891 ORA */
    recomp_tick(56); { uint32_t _e = g_abs(0x7788); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v & ~g_cpu.C)); }  /* F893 TRB */
    recomp_tick(56); { uint32_t _e = g_absx(0x6F03); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* F896 INC */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_absy(0x1922))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F899 ORA */
    recomp_tick(14); return;  /* F89C RTI */
}

void gen_register_bank_16(void) {
    func_table_register_flags(0x16F87D, gen_16F87D, false);
}
