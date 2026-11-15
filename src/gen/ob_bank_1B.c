/* Bank $1B recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 7 lifted, 67 unlifted in Bank $1B */
/* not lifted: $1B8021: COP at $1B:8023 */
/* not lifted: $1B80C9: BRK at $1B:8111 */
/* not lifted: $1B8AED: TCS at $8B02 with an unknown stack value */
/* not lifted: $1B8BFF: PLX at $8C01 pulls below the entry stack (return-address trick) */
/* not lifted: $1B8FFE: BRK at $1B:901D */
/* not lifted: $1B90E0: BRK at $1B:90E3 */
/* not lifted: $1B9307: PLA at $930D pulls below the entry stack (return-address trick) */
/* not lifted: $1B970F: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1B9F98: BRK at $1B:9FEC */
/* not lifted: $1B9F9F: BRK at $1B:9FEC */
/* not lifted: $1BAFFE: BRK at $1B:B010 */
/* not lifted: $1BB0BC: COP at $1B:B0CA */
/* not lifted: $1BB33E: calls RAM trampoline/sub-8000 ($1B687F): executes native on LakeSnes */
/* not lifted: $1BB47A: COP at $1B:B481 */
/* not lifted: $1BB654: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1BB6E1: BRK at $1B:B6EB */
/* not lifted: $1BBB1E: BRK at $1B:BB43 */
/* not lifted: $1BBC5B: COP at $1B:BC5F */
/* not lifted: $1BBDF4: XCE at $1B:BE0C */
/* not lifted: $1BBF74: PLB at $BFC5 pulls below the entry stack (return-address trick) */
/* not lifted: $1BC606: COP at $1B:C60B */
/* not lifted: $1BC8FE: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1BCC8D: BRK at $1B:CC93 */
/* not lifted: $1BCF0F: tail jump at $CF63 with 4 bytes pushed */
/* not lifted: $1BD3C8: PLX at $D3C8 pulls below the entry stack (return-address trick) */
/* not lifted: $1BDE34: COP at $1B:DE45 */
/* not lifted: $1BDE9E: STP at $1B:DEB3 */
/* not lifted: $1BDEC0: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1BDF4F: BRK at $1B:DF7E */
/* not lifted: $1BE0FF: PLB at $E0FF pulls below the entry stack (return-address trick) */
/* not lifted: $1BE16E: TCS at $736F with an unknown stack value */
/* not lifted: $1BE1AD: STP at $1B:E1B2 */
/* not lifted: $1BE201: XCE at $1B:E242 */
/* not lifted: $1BE6E2: XCE at $1B:E6EF */
/* not lifted: $1BE6E6: XCE at $1B:E6EF */
/* not lifted: $1BE7E6: COP at $1B:E7ED */
/* not lifted: $1BEA08: STP at $1B:EA0B */
/* not lifted: $1BEB10: PLX at $EB10 pulls below the entry stack (return-address trick) */
/* not lifted: $1BEC08: XCE at $1B:EC57 */
/* not lifted: $1BEC0D: XCE at $1B:EC57 */
/* not lifted: $1BED57: BRK at $1B:ED62 */
/* not lifted: $1BEE13: STP at $1B:EE13 */
/* not lifted: $1BEF5F: BRK at $1B:EF76 */
/* not lifted: $1BEFFF: COP at $1B:F0E9 */
/* not lifted: $1BF0F4: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1BF4BC: BRK at $1B:F4DD */
/* not lifted: $1BF7FE: XCE at $1B:F7FE */
/* not lifted: $1BF800: BRK at $1B:F812 */
/* not lifted: $1BF8B6: BRK at $1B:F905 */
/* not lifted: $1BF918: XCE at $1B:F930 */
/* not lifted: $1BFA07: PLX at $FA0D pulls below the entry stack (return-address trick) */
/* not lifted: $1BFB01: XCE at $1B:FB2C */
/* not lifted: $1BFBFF: WAI at $1B:FC0E */
/* not lifted: $1BFCFC: XCE at $1B:FD1A */
/* not lifted: $1BFE01: PLX at $FE54 pulls below the entry stack (return-address trick) */
/* not lifted: $1BFE07: PLX at $FE54 pulls below the entry stack (return-address trick) */
/* not lifted: $1BFF00: PLY at $FF37 pulls below the entry stack (return-address trick) */
/* not lifted: $1BFF08: PLY at $FF37 pulls below the entry stack (return-address trick) */
/* not lifted: $1BFF3F: STP at $1B:FF68 */
/* not lifted: $1BFF63: STP at $1B:FF68 */
/* not lifted: $1BFF76: XCE at $1B:FF8B */
/* not lifted: $1BFFC1: COP at $1B:FFDC */
/* not lifted: $1BFFD7: STP at $1B:FFEC */
/* not lifted: $1BFFD8: STP at $1B:FFEC */
/* not lifted: $1BFFF4: BRK at $1B:0037 */
/* not lifted: $1BFFF7: BRK at $1B:0037 */
/* not lifted: $1BFFFE: BRK at $1B:0037 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $1B984F, entered with P=$30 via JSR */
void gen_1B984F(void) {
    goto L_984F;
L_97F9:;
    recomp_tick(16); goto L_985C;  /* 97F9 BRA */
L_984F:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x53)));  /* 984F CMP */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x03F509u)))));  /* 9851 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0x7FC2); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9855 INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sr(0xFF))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9858 AND */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xF9A9FDu)))));  /* 985A SBC */
    goto L_985E;
L_985C:;
    recomp_tick(16); { uint8_t _v = 0xF9; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 985C LDA */
L_985E:;
    recomp_tick(16); goto L_97F9;  /* 985E BRA */
}

/* $1B99FF, entered with P=$30 via JSR */
void gen_1B99FF(void) {
    goto L_99FF;
L_99FF:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpxi(0x00)))));  /* 99FF ADC */
    recomp_tick(14); { uint8_t _v = g_ror8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 9A01 ROR */
    recomp_tick(14); return;  /* 9A02 RTI */
}

/* $1B9BFF, entered with P=$30 via JSR */
void gen_1B9BFF(void) {
    goto L_9BFF;
L_075D:;
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0xEF)))));  /* 075D SBC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0xFD))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 075F ORA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0xA6F6FFu));  /* 0761 CMP */
    recomp_tick(40); { uint32_t _e = g_absx(0x9984); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* 0765 ROR */
    recomp_tick(14); return;  /* 0768 RTI */
L_9BFF:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 9BFF XBA */
    recomp_tick(24); goto L_075D;  /* 9C00 JMP */
}

/* $1BA8ED, entered with P=$30 via JSR */
void gen_1BA8ED(void) {
    goto L_A8ED;
L_A8ED:;
    recomp_tick(14); return;  /* A8ED RTS */
}

/* $1BA901, entered with P=$30 via JSR */
void gen_1BA901(void) {
    goto L_A901;
L_A901:;
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x7E40))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A901 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0xFE))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A904 ORA */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* A906 DEX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x39))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A907 ORA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x5FC061u)));  /* A909 CMP */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xFE))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A90D ORA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xBB); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A90F EOR */
    recomp_tick(40); { uint32_t _e = g_absx(0xFFFF); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A911 INC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absx(0xFCFD)))));  /* A914 SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xFEFC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A917 INC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absx(0x7FFB)))));  /* A91A SBC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absy(0xFAF3)))));  /* A91D SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0xFA)))));  /* A920 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0xFE)))));  /* A922 SBC */
    recomp_tick(32); { uint32_t _e = g_dp(0xB9); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* A924 ASL */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xFCFDFCu)))));  /* A926 SBC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absx(0xFDF9)))));  /* A92A SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpiy(0xFD)))));  /* A92D SBC */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xF2FFE2u)))));  /* A92F SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xEF7E); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A933 INC */
    recomp_tick(40); { uint32_t _e = g_absx(0xFFBF); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A936 INC */
    recomp_tick(40); { uint32_t _e = g_absx(0x9E7F); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A939 DEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absx(0xFF3C)))));  /* A93C SBC */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_absy(0xFDFF))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A93F AND */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0xFEF703u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A942 LDA */
    recomp_tick(14); return;  /* A946 RTS */
}

/* $1BBEE1, entered with P=$30 via JSR */
void gen_1BBEE1(void) {
    goto L_BEE1;
L_BEE1:;
    recomp_tick(14); return;  /* BEE1 RTS */
}

/* $1BF63E, entered with P=$30 via JSR */
void gen_1BF63E(void) {
    goto L_F63E;
L_F63E:;
    recomp_tick(32); { uint32_t _e = g_dp(0xDA); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* F63E ASL */
    recomp_tick(40); { uint32_t _e = g_abs(0x08E3); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* F640 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xB582FDu)))));  /* F643 SBC */
    recomp_tick(32); { uint32_t _e = g_dp(0x71); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* F647 DEC */
    recomp_tick(40); g_wr8(0xFFC69Fu, (uint8_t)(uint8_t)g_cpu.C);  /* F649 STA */
    recomp_tick(24); g_wr8(g_dpy(0x55), (uint8_t)g_cpu.X);  /* F64D STX */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x7720)))));  /* F64F ADC */
    recomp_tick(14); g_cpu.flag_C = false;  /* F652 CLC */
    recomp_tick(14); return;  /* F653 RTS */
}

void gen_register_bank_1B(void) {
    func_table_register_flags(0x1B984F, gen_1B984F, false);
    func_table_register_flags(0x1B99FF, gen_1B99FF, false);
    func_table_register_flags(0x1B9BFF, gen_1B9BFF, false);
    func_table_register_flags(0x1BA8ED, gen_1BA8ED, false);
    func_table_register_flags(0x1BA901, gen_1BA901, false);
    func_table_register_flags(0x1BBEE1, gen_1BBEE1, false);
    func_table_register_flags(0x1BF63E, gen_1BF63E, false);
}
