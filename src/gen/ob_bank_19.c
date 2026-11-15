/* Bank $19 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 7 unlifted in Bank $19 */
/* not lifted: $198F76: COP at $19:8F84 */
/* not lifted: $199040: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $199FCB: BRK at $19:23CA */
/* not lifted: $19A800: XCE at $19:A800 */
/* not lifted: $19C0E0: BRK at $19:C0E6 */
/* not lifted: $19FCFF: BRK at $19:FD11 */
/* not lifted: $19FF1F: BRK at $19:FF25 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $19E60E, entered with P=$30 via JSR */
void gen_19E60E(void) {
    goto L_E60E;
L_E60E:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpx(0x5A))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E60E AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpx(0x7B))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E610 AND */
    recomp_tick(24); g_bit8(g_rd8(g_dpx(0x63)), false);  /* E612 BIT */
    recomp_tick(32); g_bit8(g_rd8(g_absx(0x17EE)), false);  /* E614 BIT */
    recomp_tick(14); return;  /* E617 RTI */
}

/* $19FF9E, entered with P=$30 via JSR */
void gen_19FF9E(void) {
    goto L_FF9E;
L_FF9E:;
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(0x0F40E2u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FF9E ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x60E0E0u)))));  /* FFA2 SBC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_longx(0x0700F0u))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FFA6 AND */
    recomp_tick(14); return;  /* FFAA RTI */
}

void gen_register_bank_19(void) {
    func_table_register_flags(0x19E60E, gen_19E60E, false);
    func_table_register_flags(0x19FF9E, gen_19FF9E, false);
}
