/* Bank $13 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 0 unlifted in Bank $13 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $13CE0D, entered with P=$00 via JSR */
void gen_13CE0D(void) {
    goto L_CE0D;
L_CE0D:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dpi(0xF1)));  /* CE0D CMP */
    recomp_tick(56); { uint32_t _e = g_abs(0x7300); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* CE0F ASL */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0xFE))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE12 ORA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_longx(0x0FF901u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE14 AND */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sriy(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE18 ORA */
    recomp_tick(14); return;  /* CE1A RTL */
}

void gen_register_bank_13(void) {
    func_table_register_flags(0x13CE0D, gen_13CE0D, false);
}
