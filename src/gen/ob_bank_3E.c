/* Bank $3E recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 9 unlifted in Bank $3E */
/* not lifted: $3E8060: calls RAM trampoline/sub-8000 ($591775): executes native on LakeSnes */
/* not lifted: $3EC314: BRK at $3E:C35F */
/* not lifted: $3EC835: COP at $3E:C874 */
/* not lifted: $3ECCC0: PLX at $CCAD pulls below the entry stack (return-address trick) */
/* not lifted: $3EE215: PLB at $E22B pulls below the entry stack (return-address trick) */
/* not lifted: $3EF608: BRK at $3E:98CC */
/* not lifted: $3EF707: PLP at $F725 pulls below the entry stack (return-address trick) */
/* not lifted: $3EFF20: PLP at $FF7F pulls below the entry stack (return-address trick) */
/* not lifted: $3EFFDD: PLB at $FFF2 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $3EBA33, entered with P=$00 via JSR */
void gen_3EBA33(void) {
    goto L_BA33;
L_BA33:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xA4)); g_cpu.Y = _v; g_nz16(_v); }  /* BA33 LDY */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0xE0))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA35 ORA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x37)); g_cpu.Y = _v; g_nz16(_v); }  /* BA37 LDY */
    recomp_tick(14); g_cpu.flag_D = true;  /* BA39 SED */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xA6)); g_cpu.X = _v; g_nz16(_v); }  /* BA3A LDX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xF2)); g_cpu.X = _v; g_nz16(_v); }  /* BA3C LDX */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0xD0))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA3E ORA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x37)); g_cpu.X = _v; g_nz16(_v); }  /* BA40 LDX */
    recomp_tick(14); g_cpu.flag_D = true;  /* BA42 SED */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(0x94EFC0u)));  /* BA43 ADC */
    recomp_tick(14); return;  /* BA47 RTI */
}

void gen_register_bank_3E(void) {
    func_table_register_flags(0x3EBA33, gen_3EBA33, false);
}
