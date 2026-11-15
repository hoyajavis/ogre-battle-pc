/* Bank $1C recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 9 unlifted in Bank $1C */
/* not lifted: $1CB607: BRK at $1C:B610 */
/* not lifted: $1CDA35: XCE at $1C:4C0C */
/* not lifted: $1CFCFE: STP at $1C:07E0 */
/* not lifted: $1CFD07: STP at $1C:07E0 */
/* not lifted: $1CFEFE: PLD at $FF10 pulls below the entry stack (return-address trick) */
/* not lifted: $1CFF23: BRK at $1C:FF25 */
/* not lifted: $1CFF44: BRK at $1C:FF81 */
/* not lifted: $1CFFFE: COP at $1C:FFFE */
/* not lifted: $1CFFFF: BRK at $1C:000C */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $1CE3E6, entered with P=$00 via JSR */
void gen_1CE3E6(void) {
    goto L_E3E6;
L_E3E6:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpily(0xF4))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E3E6 ORA */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_absy(0x184C))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E3E8 ORA */
    recomp_tick(48); { uint16_t _v = g_rd16(0x4C174Cu); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E3EB LDA */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C ^ g_rd16(g_abs(0x4017))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E3EF EOR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpx(0x17))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E3F2 ORA */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xF53D);  /* E3F4 CPX */
    recomp_tick(56); { uint32_t _e = g_abs(0xE07F); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* E3F7 TSB */
    recomp_tick(48); { uint32_t _e = g_dpx(0x17); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* E3FA ASL */
    recomp_tick(14); return;  /* E3FC RTI */
}

void gen_register_bank_1C(void) {
    func_table_register_flags(0x1CE3E6, gen_1CE3E6, false);
}
