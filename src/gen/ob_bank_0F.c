/* Bank $0F recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 14 unlifted in Bank $0F */
/* not lifted: $0F84B4: PLB at $84C8 pulls below the entry stack (return-address trick) */
/* not lifted: $0F9A1C: PLX at $9A64 pulls below the entry stack (return-address trick) */
/* not lifted: $0F9A21: PLX at $9A64 pulls below the entry stack (return-address trick) */
/* not lifted: $0FA2AA: WAI at $0F:A2E4 */
/* not lifted: $0FAA2A: XCE at $0F:AA5B */
/* not lifted: $0FAA88: PLB at $AAF4 pulls below the entry stack (return-address trick) */
/* not lifted: $0FAAAE: calls unlifted target 0x88E0C8: executes native on LakeSnes */
/* not lifted: $0FABEA: BRK at $0F:AC2C */
/* not lifted: $0FAE89: PLB at $AEB3 pulls below the entry stack (return-address trick) */
/* not lifted: $0FB479: BRK at $0F:B488 */
/* not lifted: $0FCEFC: calls RAM trampoline/sub-8000 ($555854): executes native on LakeSnes */
/* not lifted: $0FEAE2: PLB at $EB34 pulls below the entry stack (return-address trick) */
/* not lifted: $0FF32A: PLP at $F3BC pulls below the entry stack (return-address trick) */
/* not lifted: $0FFC3C: PLB at $FC73 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $0F9B48, entered with P=$30 via JSR */
void gen_0F9B48(void) {
    goto L_9B48;
L_9B48:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0x9E)))));  /* 9B48 ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x7B))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9B4A ORA */
    recomp_tick(32); g_wr8(g_absx(0xFF05), 0);  /* 9B4C STZ */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_absy(0x079E)))));  /* 9B4F ADC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_absx(0x059E)))));  /* 9B52 ADC */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9B55 TDC */
    recomp_tick(32); g_wr8(g_absx(0x0CFF), 0);  /* 9B56 STZ */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x9E9E9Eu)))));  /* 9B59 ADC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x10);  /* 9B5D CPX */
    recomp_tick(14); return;  /* 9B5F RTS */
}

/* $0FA77D, entered with P=$10 via JSL */
void gen_0FA77D(void) {
    goto L_A77D;
L_A77D:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x18EF)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A77D LDA */
    recomp_tick(14); return;  /* A780 RTL */
}

/* $0FAAAA, entered with P=$30 via JSR */
void gen_0FAAAA(void) {
    goto L_AAAA;
L_AAAA:;
    recomp_tick(14); return;  /* AAAA RTS */
}

void gen_register_bank_0F(void) {
    func_table_register_flags(0x0F9B48, gen_0F9B48, false);
    func_table_register_flags(0x0FA77D, gen_0FA77D, true);
    func_table_register_flags(0x0FAAAA, gen_0FAAAA, false);
}
