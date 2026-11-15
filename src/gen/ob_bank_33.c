/* Bank $33 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 4 lifted, 2 unlifted in Bank $33 */
/* not lifted: $33E85B: calls RAM trampoline/sub-8000 ($331199): executes native on LakeSnes */
/* not lifted: $33FF1C: COP at $33:FF24 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $33BFB8, entered with P=$30 via JSR */
void gen_33BFB8(void) {
    goto L_BFB8;
L_BFB8:;
    recomp_tick(14); ;  /* BFB8 NOP */
    recomp_tick(14); return;  /* BFB9 RTS */
}

/* $33BFB9, entered with P=$20 via JSR */
void gen_33BFB9(void) {
    goto L_BFB9;
L_BFB9:;
    recomp_tick(14); return;  /* BFB9 RTS */
}

/* $33E96F, entered with P=$30 via JSR */
void gen_33E96F(void) {
    goto L_E96F;
L_E96F:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E96F TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* E970 TAX */
L_E971:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0398)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E971 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7EFA0Du), (uint8_t)(uint8_t)g_cpu.C);  /* E974 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* E978 INX */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x0B);  /* E979 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E971;  /* E97B BNE */
    recomp_tick(14); return;  /* E97D RTS */
}

/* $33E993, entered with P=$20 via JSR */
void gen_33E993(void) {
    goto L_E993;
L_E993:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xCB)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E993 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x06);  /* E995 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E99B;  /* E997 BNE */
L_E999:;
    recomp_tick(14); g_cpu.flag_C = false;  /* E999 CLC */
    recomp_tick(14); return;  /* E99A RTS */
L_E99B:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xD8)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E99B LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E999;  /* E99D BEQ */
    recomp_tick(14); g_cpu.flag_C = true;  /* E99F SEC */
    recomp_tick(14); return;  /* E9A0 RTS */
}

void gen_register_bank_33(void) {
    func_table_register_flags(0x33BFB8, gen_33BFB8, false);
    func_table_register_flags(0x33BFB9, gen_33BFB9, false);
    func_table_register_flags(0x33E96F, gen_33E96F, false);
    func_table_register_flags(0x33E993, gen_33E993, false);
}
