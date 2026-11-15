/* Bank $34 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 6 lifted, 23 unlifted in Bank $34 */
/* not lifted: $348106: calls unlifted target 0x34896D: executes native on LakeSnes */
/* not lifted: $348123: BRK at $34:8133 */
/* not lifted: $34828F: COP at $34:8294 */
/* not lifted: $348414: BRK at $34:8419 */
/* not lifted: $348420: PLA at $83D3 pulls below the entry stack (return-address trick) */
/* not lifted: $348504: BRK at $34:84DD */
/* not lifted: $348580: BRK at $34:8598 */
/* not lifted: $3488CD: calls RAM trampoline/sub-8000 ($341199): executes native on LakeSnes */
/* not lifted: $3488D8: BRK at $34:88DC */
/* not lifted: $3488F4: calls RAM trampoline/sub-8000 ($341199): executes native on LakeSnes */
/* not lifted: $3488FD: BRK at $34:8917 */
/* not lifted: $348946: BRK at $34:894F */
/* not lifted: $34896D: BRK at $34:8970 */
/* not lifted: $3489A2: PLD at $89A6 pulls below the entry stack (return-address trick) */
/* not lifted: $3489E3: COP at $34:8A07 */
/* not lifted: $349920: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $34A200: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $34A903: BRK at $34:71DC */
/* not lifted: $34AA20: tail jump at $AA3F with 2 bytes pushed */
/* not lifted: $34B02F: COP at $34:B031 */
/* not lifted: $34F6A5: BRK at $34:F6A8 */
/* not lifted: $34FC17: calls unlifted target 0x03E9A1: executes native on LakeSnes */
/* not lifted: $34FC51: BRK at $34:FC5A */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $348037, entered with P=$30 via JSR */
void gen_348037(void) {
    goto L_8037;
L_8037:;
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8037 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2103), (uint8_t)(uint8_t)g_cpu.C);  /* 8039 STA */
    recomp_tick(32); g_wr8(g_abs(0x2102), 0);  /* 803C STZ */
    recomp_tick(32); g_wr8(g_abs(0x2103), 0);  /* 803F STZ */
    recomp_tick(32); g_wr8(g_abs(0x2102), 0);  /* 8042 STZ */
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8045 LDA */
    recomp_tick(32); g_wr8(g_abs(0x211A), (uint8_t)(uint8_t)g_cpu.C);  /* 8047 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 804A TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 804B TAX */
    recomp_tick(24); g_wr8(g_dp(0x94), (uint8_t)g_cpu.X);  /* 804C STX */
    recomp_tick(24); g_wr8(g_dp(0x96), 0);  /* 804E STZ */
    recomp_tick(24); g_wr8(g_dp(0x97), (uint8_t)g_cpu.X);  /* 8050 STX */
    recomp_tick(24); g_wr8(g_dp(0x99), (uint8_t)g_cpu.X);  /* 8052 STX */
    recomp_tick(24); g_wr8(g_dp(0x9B), (uint8_t)g_cpu.X);  /* 8054 STX */
    recomp_tick(24); g_wr8(g_dp(0x9D), (uint8_t)g_cpu.X);  /* 8056 STX */
    recomp_tick(24); g_wr8(g_dp(0x9F), (uint8_t)g_cpu.X);  /* 8058 STX */
    recomp_tick(16); { uint8_t _v = 0x30; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 805A LDA */
    recomp_tick(24); g_wr8(g_dp(0xA1), (uint8_t)(uint8_t)g_cpu.C);  /* 805C STA */
    recomp_tick(24); g_wr8(g_dp(0xA2), 0);  /* 805E STZ */
    recomp_tick(16); { uint8_t _v = 0xE0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8060 LDA */
    recomp_tick(24); g_wr8(g_dp(0xA3), (uint8_t)(uint8_t)g_cpu.C);  /* 8062 STA */
    recomp_tick(24); g_wr8(g_dp(0xA4), 0);  /* 8064 STZ */
    recomp_tick(24); g_wr8(g_dp(0xA5), 0);  /* 8066 STZ */
    recomp_tick(32); g_wr8(g_abs(0x2133), 0);  /* 8068 STZ */
    recomp_tick(16); g_rep(0x20);  /* 806B REP */
    recomp_tick(24); { uint16_t _v = 0xFFFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 806D LDA */
    recomp_tick(32); g_wr16(g_dp(0x7C), 0);  /* 8070 STZ */
    recomp_tick(32); g_wr16(g_dp(0x7E), (uint16_t)g_cpu.C);  /* 8072 STA */
    recomp_tick(32); g_wr16(g_dp(0x80), 0);  /* 8074 STZ */
    recomp_tick(32); g_wr16(g_dp(0x82), (uint16_t)g_cpu.C);  /* 8076 STA */
    recomp_tick(32); g_wr16(g_dp(0x84), 0);  /* 8078 STZ */
    recomp_tick(32); g_wr16(g_dp(0x86), (uint16_t)g_cpu.C);  /* 807A STA */
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 807C LDA */
    recomp_tick(32); g_wr16(g_dp(0x97), (uint16_t)g_cpu.C);  /* 807F STA */
    recomp_tick(32); g_wr16(g_dp(0x99), (uint16_t)g_cpu.C);  /* 8081 STA */
    recomp_tick(16); g_sep(0x20);  /* 8083 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x7C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8085 LDA */
    recomp_tick(32); g_wr8(g_abs(0x210D), (uint8_t)(uint8_t)g_cpu.C);  /* 8087 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x7D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 808A LDA */
    recomp_tick(32); g_wr8(g_abs(0x210D), (uint8_t)(uint8_t)g_cpu.C);  /* 808C STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x7E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 808F LDA */
    recomp_tick(32); g_wr8(g_abs(0x210E), (uint8_t)(uint8_t)g_cpu.C);  /* 8091 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x7F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8094 LDA */
    recomp_tick(32); g_wr8(g_abs(0x210E), (uint8_t)(uint8_t)g_cpu.C);  /* 8096 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x80)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8099 LDA */
    recomp_tick(32); g_wr8(g_abs(0x210F), (uint8_t)(uint8_t)g_cpu.C);  /* 809B STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 809E LDA */
    recomp_tick(32); g_wr8(g_abs(0x210F), (uint8_t)(uint8_t)g_cpu.C);  /* 80A0 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x82)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80A3 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2110), (uint8_t)(uint8_t)g_cpu.C);  /* 80A5 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x83)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80A8 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2110), (uint8_t)(uint8_t)g_cpu.C);  /* 80AA STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x84)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80AD LDA */
    recomp_tick(32); g_wr8(g_abs(0x2111), (uint8_t)(uint8_t)g_cpu.C);  /* 80AF STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x85)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80B2 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2111), (uint8_t)(uint8_t)g_cpu.C);  /* 80B4 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x86)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80B7 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2112), (uint8_t)(uint8_t)g_cpu.C);  /* 80B9 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x87)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80BC LDA */
    recomp_tick(32); g_wr8(g_abs(0x2112), (uint8_t)(uint8_t)g_cpu.C);  /* 80BE STA */
    recomp_tick(14); return;  /* 80C1 RTS */
}

/* $3480A9, entered with P=$30 via JSR */
void gen_3480A9(void) {
    goto L_80A9;
L_80A9:;
    recomp_tick(24); g_wr8(g_sr(0x8D), (uint8_t)(uint8_t)g_cpu.C);  /* 80A9 STA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_80CE;  /* 80AB BPL */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x84)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80AD LDA */
    recomp_tick(32); g_wr8(g_abs(0x2111), (uint8_t)(uint8_t)g_cpu.C);  /* 80AF STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x85)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80B2 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2111), (uint8_t)(uint8_t)g_cpu.C);  /* 80B4 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x86)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80B7 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2112), (uint8_t)(uint8_t)g_cpu.C);  /* 80B9 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x87)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80BC LDA */
    recomp_tick(32); g_wr8(g_abs(0x2112), (uint8_t)(uint8_t)g_cpu.C);  /* 80BE STA */
    recomp_tick(14); return;  /* 80C1 RTS */
L_80CE:;
    recomp_tick(24); g_wr8(g_dpx(0x94), (uint8_t)g_cpu.Y);  /* 80CE STY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sr(0xA5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80D0 AND */
    recomp_tick(24); g_wr8(g_dpy(0x95), (uint8_t)g_cpu.X);  /* 80D2 STX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dp(0x84))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80D4 AND */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* 80D6 TXY */
    recomp_tick(24); g_wr8(g_dpx(0x9B), (uint8_t)g_cpu.Y);  /* 80D7 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x97)); g_cpu.Y = _v; g_nz8(_v); }  /* 80D9 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x26), (uint8_t)g_cpu.Y);  /* 80DB STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x99)); g_cpu.Y = _v; g_nz8(_v); }  /* 80DD LDY */
    recomp_tick(24); g_wr8(g_dpx(0x28), (uint8_t)g_cpu.Y);  /* 80DF STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x9D)); g_cpu.Y = _v; g_nz8(_v); }  /* 80E1 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x2C), (uint8_t)g_cpu.Y);  /* 80E3 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x9F)); g_cpu.Y = _v; g_nz8(_v); }  /* 80E5 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x9F), (uint8_t)g_cpu.Y);  /* 80E7 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA1)); g_cpu.Y = _v; g_nz8(_v); }  /* 80E9 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x30), (uint8_t)g_cpu.Y);  /* 80EB STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA3)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80ED LDA */
    recomp_tick(24); g_wr8(g_dpx(0x32), (uint8_t)(uint8_t)g_cpu.C);  /* 80EF STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA4)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80F1 LDA */
    recomp_tick(24); g_wr8(g_dpx(0x32), (uint8_t)(uint8_t)g_cpu.C);  /* 80F3 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA5)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80F5 LDA */
    recomp_tick(24); g_wr8(g_dpx(0x32), (uint8_t)(uint8_t)g_cpu.C);  /* 80F7 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x76)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80F9 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2101), (uint8_t)(uint8_t)g_cpu.C);  /* 80FB STA */
    recomp_tick(24); g_wr8(g_dp(0xC9), 0);  /* 80FE STZ */
    recomp_tick(32); g_wr8(g_abs(0x1CF0), 0);  /* 8100 STZ */
    recomp_tick(24); g_wr8(g_dp(0xC8), 0);  /* 8103 STZ */
    recomp_tick(14); return;  /* 8105 RTS */
}

/* $3480C2, entered with P=$30 via JSR */
void gen_3480C2(void) {
    goto L_80C2;
L_80C2:;
    recomp_tick(16); { uint8_t _v = 0x00; g_cpu.X = _v; g_nz8(_v); }  /* 80C2 LDX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpxi(0xA4))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80C4 AND */
    recomp_tick(14); g_cpu.flag_I = true;  /* 80C6 SEI */
    recomp_tick(24); g_wr8(g_dpx(0x07), (uint8_t)g_cpu.Y);  /* 80C7 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x7A)); g_cpu.Y = _v; g_nz8(_v); }  /* 80C9 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x09), (uint8_t)g_cpu.Y);  /* 80CB STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x94)); g_cpu.Y = _v; g_nz8(_v); }  /* 80CD LDY */
    recomp_tick(24); g_wr8(g_dpx(0x23), (uint8_t)g_cpu.Y);  /* 80CF STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x96)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80D1 LDA */
    recomp_tick(24); g_wr8(g_dpx(0x25), (uint8_t)(uint8_t)g_cpu.C);  /* 80D3 STA */
    recomp_tick(24); g_wr8(g_dp(0x9B), (uint8_t)g_cpu.Y);  /* 80D5 STY */
    recomp_tick(24); g_wr8(g_dpx(0x9B), (uint8_t)g_cpu.Y);  /* 80D7 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x97)); g_cpu.Y = _v; g_nz8(_v); }  /* 80D9 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x26), (uint8_t)g_cpu.Y);  /* 80DB STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x99)); g_cpu.Y = _v; g_nz8(_v); }  /* 80DD LDY */
    recomp_tick(24); g_wr8(g_dpx(0x28), (uint8_t)g_cpu.Y);  /* 80DF STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x9D)); g_cpu.Y = _v; g_nz8(_v); }  /* 80E1 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x2C), (uint8_t)g_cpu.Y);  /* 80E3 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x9F)); g_cpu.Y = _v; g_nz8(_v); }  /* 80E5 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x9F), (uint8_t)g_cpu.Y);  /* 80E7 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA1)); g_cpu.Y = _v; g_nz8(_v); }  /* 80E9 LDY */
    recomp_tick(24); g_wr8(g_dpx(0x30), (uint8_t)g_cpu.Y);  /* 80EB STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA3)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80ED LDA */
    recomp_tick(24); g_wr8(g_dpx(0x32), (uint8_t)(uint8_t)g_cpu.C);  /* 80EF STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA4)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80F1 LDA */
    recomp_tick(24); g_wr8(g_dpx(0x32), (uint8_t)(uint8_t)g_cpu.C);  /* 80F3 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA5)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80F5 LDA */
    recomp_tick(24); g_wr8(g_dpx(0x32), (uint8_t)(uint8_t)g_cpu.C);  /* 80F7 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x76)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 80F9 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2101), (uint8_t)(uint8_t)g_cpu.C);  /* 80FB STA */
    recomp_tick(24); g_wr8(g_dp(0xC9), 0);  /* 80FE STZ */
    recomp_tick(32); g_wr8(g_abs(0x1CF0), 0);  /* 8100 STZ */
    recomp_tick(24); g_wr8(g_dp(0xC8), 0);  /* 8103 STZ */
    recomp_tick(14); return;  /* 8105 RTS */
}

/* $348413, entered with P=$30 via JSR */
void gen_348413(void) {
    goto L_8413;
L_8413:;
    recomp_tick(14); return;  /* 8413 RTS */
}

/* $3488CC, entered with P=$30 via JSR */
void gen_3488CC(void) {
    goto L_88CC;
L_88CC:;
    recomp_tick(14); return;  /* 88CC RTS */
}

/* $34C23F, entered with P=$20 via JSR */
void gen_34C23F(void) {
    goto L_C23F;
L_C23F:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x404040u)))));  /* C23F SBC */
    recomp_tick(14); return;  /* C243 RTI */
}

void gen_register_bank_34(void) {
    func_table_register_flags(0x348037, gen_348037, false);
    func_table_register_flags(0x3480A9, gen_3480A9, false);
    func_table_register_flags(0x3480C2, gen_3480C2, false);
    func_table_register_flags(0x348413, gen_348413, false);
    func_table_register_flags(0x3488CC, gen_3488CC, false);
    func_table_register_flags(0x34C23F, gen_34C23F, false);
}
