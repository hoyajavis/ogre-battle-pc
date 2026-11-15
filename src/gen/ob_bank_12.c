/* Bank $12 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 5 lifted, 20 unlifted in Bank $12 */
/* not lifted: $1292FF: PLP at $934A without a matching PHP */
/* not lifted: $129E0B: BRK at $12:9E0B */
/* not lifted: $12A40C: BRK at $12:A42B */
/* not lifted: $12AF45: RTI at $AF7D with 2 bytes still pushed */
/* not lifted: $12B1C3: BRK at $12:B1F3 */
/* not lifted: $12BA1E: BRK at $12:BA21 */
/* not lifted: $12BDBF: PLX at $BDC1 pulls below the entry stack (return-address trick) */
/* not lifted: $12BFC0: BRK at $12:BFC3 */
/* not lifted: $12C405: BRK at $12:C405 */
/* not lifted: $12CE0E: BRK at $12:CE13 */
/* not lifted: $12D66F: BRK at $12:D66F */
/* not lifted: $12D8E7: COP at $12:D8E7 */
/* not lifted: $12F980: PLP at $F983 pulls below the entry stack (return-address trick) */
/* not lifted: $12FBF8: XCE at $12:81B2 */
/* not lifted: $12FC3E: COP at $12:FC56 */
/* not lifted: $12FF17: BRK at $12:FF19 */
/* not lifted: $12FF1E: BRK at $12:FF34 */
/* not lifted: $12FF50: PLX at $FF7D pulls below the entry stack (return-address trick) */
/* not lifted: $12FF6C: PLX at $FF7D pulls below the entry stack (return-address trick) */
/* not lifted: $12FFE0: indirect jump table dispatch: executes native on LakeSnes */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $12ECF6, entered with P=$30 via JSR */
void gen_12ECF6(void) {
    goto L_ECF6;
L_ECF6:;
    recomp_tick(40); { uint32_t _e = g_absx(0xE901); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* ECF6 DEC */
    recomp_tick(32); { uint32_t _e = g_dp(0xF9); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* ECF9 ASL */
    recomp_tick(16); if (g_cpu.flag_V) goto L_ED51;  /* ECFB BVS */
    recomp_tick(14); return;  /* ECFD RTI */
L_ED51:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x0D)))));  /* ED51 ADC */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xD109D4u)))));  /* ED53 ADC */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x9A); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ED57 ORA */
    recomp_tick(32); { uint32_t _e = g_dp(0xE2); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* ED59 ASL */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpxi(0xD8))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ED5B ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xE76067u)))));  /* ED5D SBC */
    recomp_tick(16); g_sep(0xE6);  /* ED61 SEP */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x66);  /* ED63 CPX */
    recomp_tick(14); return;  /* ED65 RTS */
}

/* $12ECFF, entered with P=$30 via JSR */
void gen_12ECFF(void) {
    goto L_ECFF;
L_ECFF:;
    recomp_tick(14); return;  /* ECFF RTI */
}

/* $12EEEE, entered with P=$30 via JSR */
void gen_12EEEE(void) {
    goto L_EEEE;
L_EED5:;
    recomp_tick(16); { uint8_t _v = 0xDF; g_cpu.X = _v; g_nz8(_v); }  /* EED5 LDX */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x84EF62u)))));  /* EED7 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0000); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* EEDB DEC */
    recomp_tick(14); return;  /* EEDE RTI */
L_EEEE:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x70);  /* EEEE CPX */
    recomp_tick(16); goto L_EED5;  /* EEF0 BRA */
}

/* $12F022, entered with P=$30 via JSR */
void gen_12F022(void) {
    goto L_F022;
L_F022:;
    recomp_tick(14); g_cpu.flag_C = true;  /* F022 SEC */
    recomp_tick(14); return;  /* F023 RTI */
}

/* $12F914, entered with P=$30 via JSR */
void gen_12F914(void) {
    goto L_F914;
L_F914:;
    recomp_tick(14); return;  /* F914 RTS */
}

void gen_register_bank_12(void) {
    func_table_register_flags(0x12ECF6, gen_12ECF6, false);
    func_table_register_flags(0x12ECFF, gen_12ECFF, false);
    func_table_register_flags(0x12EEEE, gen_12EEEE, false);
    func_table_register_flags(0x12F022, gen_12F022, false);
    func_table_register_flags(0x12F914, gen_12F914, false);
}
