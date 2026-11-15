/* Bank $30 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 5 lifted, 38 unlifted in Bank $30 */
/* not lifted: $3082AA: BRK at $30:82A5 */
/* not lifted: $3083E1: BRK at $30:83ED */
/* not lifted: $30855D: BRK at $30:855F */
/* not lifted: $3087BD: BRK at $30:87C1 */
/* not lifted: $30883A: BRK at $30:8841 */
/* not lifted: $308A82: STP at $30:8AC3 */
/* not lifted: $308AA2: STP at $30:8AC3 */
/* not lifted: $308AAA: STP at $30:8AC3 */
/* not lifted: $308BAA: BRK at $30:8BCD */
/* not lifted: $308FA9: BRK at $30:8FB8 */
/* not lifted: $3096FB: BRK at $30:96FE */
/* not lifted: $309795: COP at $30:97FE */
/* not lifted: $30981D: COP at $30:9824 */
/* not lifted: $30A088: PLA at $A0B7 pulls below the entry stack (return-address trick) */
/* not lifted: $30A22A: BRK at $30:A22A */
/* not lifted: $30A28A: BRK at $30:A291 */
/* not lifted: $30A2A2: $30:A2AE reached with two different M/X/stack states */
/* not lifted: $30A2AA: $30:A2AA reached with two different M/X/stack states */
/* not lifted: $30A888: RTS at $A897 with 2 bytes still pushed */
/* not lifted: $30A8A2: BRK at $30:A8B1 */
/* not lifted: $30A8AA: BRK at $30:A8B1 */
/* not lifted: $30AA0C: BRK at $30:AA0C */
/* not lifted: $30AA2A: BRK at $30:AA2E */
/* not lifted: $30AA88: BRK at $30:AA95 */
/* not lifted: $30AA8A: BRK at $30:AA95 */
/* not lifted: $30AAA0: BRK at $30:AAB1 */
/* not lifted: $30AAA2: BRK at $30:AAB1 */
/* not lifted: $30AAA8: BRK at $30:AAB1 */
/* not lifted: $30AAAA: BRK at $30:AAB1 */
/* not lifted: $30AAAB: BRK at $30:AAB1 */
/* not lifted: $30AAEA: PLY at $AAF2 pulls below the entry stack (return-address trick) */
/* not lifted: $30AC8A: BRK at $30:AC4F */
/* not lifted: $30BACA: COP at $30:BACA */
/* not lifted: $30D4FE: RTS at $D5B2 with 1 bytes still pushed */
/* not lifted: $30DFFC: COP at $30:DFFC */
/* not lifted: $30E2AA: RTS at $E2AD with 1 bytes still pushed */
/* not lifted: $30EAAA: BRK at $30:EAB6 */
/* not lifted: $30FAAA: PLB at $FB3E pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $309709, entered with P=$30 via JSR */
void gen_309709(void) {
    goto L_9709;
L_9709:;
    recomp_tick(14); return;  /* 9709 RTS */
}

/* $309A10, entered with P=$30 via JSL */
void gen_309A10(void) {
    goto L_9A10;
L_9A10:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* 9A10 DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* 9A11 DEX */
    recomp_tick(24); g_wr8(g_dp(0x0A), (uint8_t)g_cpu.X);  /* 9A12 STX */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)g_cpu.Y);  /* 9A14 STY */
    recomp_tick(16); g_rep(0x20);  /* 9A16 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A18 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A1B ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* 9A1C TAY */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz8(_v); }  /* 9A1D DEY */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz8(_v); }  /* 9A1E DEY */
L_9A1F:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz8(_v); }  /* 9A1F DEY */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz8(_v); }  /* 9A20 DEY */
    recomp_tick(16); if (g_cpu.flag_N) goto L_9A52;  /* 9A21 BMI */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)g_cpu.Y);  /* 9A23 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A25 LDA */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* 9A27 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* 9A29 TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A2A LDA */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.C);  /* 9A2C STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_cpu.X = _v; g_nz8(_v); }  /* 9A2E LDX */
L_9A30:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* 9A30 INX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* 9A31 INX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* 9A32 TXY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A33 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* 9A35 TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A36 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 9A38 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x08))));  /* 9A39 SBC */
    recomp_tick(16); if (g_cpu.flag_V) goto L_9A41;  /* 9A3B BVS */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_9A49;  /* 9A3D BPL */
    recomp_tick(16); goto L_9A43;  /* 9A3F BRA */
L_9A41:;
    recomp_tick(16); if (g_cpu.flag_N) goto L_9A49;  /* 9A41 BMI */
L_9A43:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A43 TYA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* 9A44 TXY */
    recomp_tick(32); g_wr16(g_dpiy(0x0A), (uint16_t)g_cpu.C);  /* 9A45 STA */
    recomp_tick(16); goto L_9A30;  /* 9A47 BRA */
L_9A49:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A49 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* 9A4B TXY */
    recomp_tick(32); g_wr16(g_dpiy(0x0A), (uint16_t)g_cpu.C);  /* 9A4C STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_cpu.Y = _v; g_nz8(_v); }  /* 9A4E LDY */
    recomp_tick(16); goto L_9A1F;  /* 9A50 BRA */
L_9A52:;
    recomp_tick(16); g_sep(0x20);  /* 9A52 SEP */
    recomp_tick(14); return;  /* 9A54 RTS */
}

/* $30A83B, entered with P=$30 via JSR */
void gen_30A83B(void) {
    goto L_A83B;
L_A827:;
    recomp_tick(32); g_wr8(g_abs(0x07B5), 0);  /* A827 STZ */
    recomp_tick(14); return;  /* A82A RTS */
L_A839:;
    recomp_tick(32); g_wr8(g_abs(0x07B7), (uint8_t)(uint8_t)g_cpu.C);  /* A839 STA */
    goto L_A83C;
L_A83B:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x85))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A83B ORA */
    goto L_A83D;
L_A83C:;
    recomp_tick(24); g_wr8(g_dp(0x75), (uint8_t)(uint8_t)g_cpu.C);  /* A83C STA */
    goto L_A83E;
L_A83D:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x60)))));  /* A83D ADC */
    goto L_A83F;
L_A83E:;
    recomp_tick(14); return;  /* A83E RTS */
L_A83F:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x51)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A83F LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x03); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A841 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A83E;  /* A843 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x07B7)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A845 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A848 DEC */
    recomp_tick(16); if (g_cpu.flag_N) goto L_A827;  /* A849 BMI */
    recomp_tick(16); goto L_A839;  /* A84B BRA */
}

/* $30D5B3, entered with P=$20 via JSR */
void gen_30D5B3(void) {
    goto L_D5B3;
L_D5B3:;
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.X);  /* D5B3 STX */
L_D5B5:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.Y = _v; g_nz16(_v); }  /* D5B5 LDY */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.Y);  /* D5B7 STY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xAF29)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5B9 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5BC ORA */
    recomp_tick(32); g_wr8(g_absy(0xAF29), (uint8_t)(uint8_t)g_cpu.C);  /* D5BE STA */
    recomp_tick(24); { uint16_t _v = 0x7FFF; g_cpu.X = _v; g_nz16(_v); }  /* D5C1 LDX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* D5C4 STX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x8F28)); g_cpu.X = _v; g_nz16(_v); }  /* D5C6 LDX */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.X);  /* D5C9 STX */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* D5CB LDX */
L_D5CE:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* D5CE STX */
    recomp_tick(16); g_rep(0x20);  /* D5D0 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D5D2 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D5D4 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x00D671u))));  /* D5D5 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* D5D9 TAY */
    recomp_tick(16); g_sep(0x20);  /* D5DA SEP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0xAF28)); g_cpu.X = _v; g_nz16(_v); }  /* D5DC LDX */
    recomp_tick(16); if (g_cpu.flag_N) goto L_D65A;  /* D5DF BMI */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5E1 TYA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7E); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5E2 AND */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* D5E4 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5E6 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7E); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5E8 AND */
    recomp_tick(14); g_cpu.flag_C = true;  /* D5EA SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* D5EB SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5ED INC */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5EE INC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x06);  /* D5EF CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D65A;  /* D5F1 BCS */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x2000);  /* D5F3 CPY */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D65A;  /* D5F6 BCS */
    recomp_tick(16); g_rep(0x20);  /* D5F8 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* D5FA LDX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D5FC LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D5FE CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x00D681u))));  /* D5FF ADC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* D603 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D605 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D607 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x00D691u))));  /* D608 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D60C TAX */
    recomp_tick(16); g_sep(0x20);  /* D60D SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D60F TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7F8000u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D610 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D614 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xCF28)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D615 LDA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* D618 LDX */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* D61A STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7F8000u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D61C LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D620 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xCF28)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D621 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D624 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* D625 ADC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D64F;  /* D627 BCS */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* D629 LDX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0007);  /* D62B CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D635;  /* D62E BCC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D630 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07D8B9u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D631 LDA */
L_D635:;
    recomp_tick(16); g_rep(0x20);  /* D635 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* D637 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x08))));  /* D638 ADC */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absy(0x8F28)));  /* D63A CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D64D;  /* D63D BCS */
    recomp_tick(40); g_wr16(g_absy(0x8F28), (uint16_t)g_cpu.C);  /* D63F STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0xAF28)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D642 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x8000); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D645 AND */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x02))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D648 ORA */
    recomp_tick(40); g_wr16(g_absy(0xAF28), (uint16_t)g_cpu.C);  /* D64A STA */
L_D64D:;
    recomp_tick(16); g_sep(0x20);  /* D64D SEP */
L_D64F:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x8F28)); g_cpu.X = _v; g_nz16(_v); }  /* D64F LDX */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_dp(0x06)));  /* D652 CPX */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D65A;  /* D654 BCS */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* D656 STX */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.Y);  /* D658 STY */
L_D65A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* D65A LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D65C INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D65D INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0010);  /* D65E CPX */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D666;  /* D661 BCS */
    recomp_tick(24); goto L_D5CE;  /* D663 JMP */
L_D666:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.X = _v; g_nz16(_v); }  /* D666 LDX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x7FFF);  /* D668 CPX */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D670;  /* D66B BCS */
    recomp_tick(24); goto L_D5B5;  /* D66D JMP */
L_D670:;
    recomp_tick(14); return;  /* D670 RTS */
}

/* $30E2EC, entered with P=$00 via JSR */
void gen_30E2EC(void) {
    goto L_E2EC;
L_E2EC:;
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0xE6))));  /* E2EC SBC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1244)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2EE LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E2F7;  /* E2F1 BNE */
    recomp_tick(56); { uint32_t _e = g_abs(0x1247); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* E2F3 INC */
    recomp_tick(14); return;  /* E2F6 RTS */
L_E2F7:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2F7 DEC */
    recomp_tick(40); g_wr16(g_abs(0x1244), (uint16_t)g_cpu.C);  /* E2F8 STA */
    recomp_tick(16); g_rep(0x20);  /* E2FB REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2FD AND */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* E300 STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* E302 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* E303 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* E304 ADC */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* E306 PHX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E307 TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3000u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E308 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* E30C TAY */
    recomp_tick(16); g_sep(0x20);  /* E30D SEP */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7E3002u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E30F LDA */
    recomp_tick(24); g_wr8(g_dp(0x27), (uint8_t)(uint8_t)g_cpu.C);  /* E313 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* E315 PLX */
    recomp_tick(14); return;  /* E316 RTS */
}

void gen_register_bank_30(void) {
    func_table_register_flags(0x309709, gen_309709, false);
    func_table_register_flags(0x309A10, gen_309A10, true);
    func_table_register_flags(0x30A83B, gen_30A83B, false);
    func_table_register_flags(0x30D5B3, gen_30D5B3, false);
    func_table_register_flags(0x30E2EC, gen_30E2EC, false);
}
