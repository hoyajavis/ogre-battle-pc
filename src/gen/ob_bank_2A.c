/* Bank $2A recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 11 lifted, 91 unlifted in Bank $2A */
/* not lifted: $2A80FD: XCE at $2A:8103 */
/* not lifted: $2A8264: XCE at $2A:827D */
/* not lifted: $2A842E: BRK at $2A:8434 */
/* not lifted: $2A8802: tail jump at $8866 with 2 bytes pushed */
/* not lifted: $2A8828: tail jump at $8866 with 2 bytes pushed */
/* not lifted: $2A888A: XCE at $2A:8892 */
/* not lifted: $2A8A2A: BRK at $2A:8ACA */
/* not lifted: $2A8A88: TXS at $2A:8A93 */
/* not lifted: $2A8AAA: COP at $2A:8AAA */
/* not lifted: $2A8AE2: COP at $2A:8AF8 */
/* not lifted: $2A8C3F: XCE at $2A:8C47 */
/* not lifted: $2A90E5: COP at $2A:9109 */
/* not lifted: $2A90E6: COP at $2A:9109 */
/* not lifted: $2A90E7: COP at $2A:9109 */
/* not lifted: $2A90ED: WAI at $2A:90F3 */
/* not lifted: $2A90EE: COP at $2A:9109 */
/* not lifted: $2A90EF: WAI at $2A:90F3 */
/* not lifted: $2A90F5: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2A90F6: COP at $2A:9109 */
/* not lifted: $2A90F7: COP at $2A:9109 */
/* not lifted: $2A90FD: COP at $2A:9109 */
/* not lifted: $2A90FE: XCE at $2A:9104 */
/* not lifted: $2A90FF: COP at $2A:9109 */
/* not lifted: $2A91E5: COP at $2A:91EB */
/* not lifted: $2A91E6: COP at $2A:91EB */
/* not lifted: $2A91E7: COP at $2A:91EB */
/* not lifted: $2A91F6: WAI at $2A:9204 */
/* not lifted: $2A91F7: WAI at $2A:9204 */
/* not lifted: $2A91FD: WAI at $2A:9204 */
/* not lifted: $2A91FE: WAI at $2A:9204 */
/* not lifted: $2A91FF: WAI at $2A:9204 */
/* not lifted: $2A991E: XCE at $2A:9922 */
/* not lifted: $2A9E0E: XCE at $2A:9E19 */
/* not lifted: $2AA040: BRK at $2A:A048 */
/* not lifted: $2AA063: COP at $2A:A07D */
/* not lifted: $2AA2A2: PLY at $A2ED pulls below the entry stack (return-address trick) */
/* not lifted: $2AA2AA: COP at $2A:A37D */
/* not lifted: $2AA7AA: XCE at $2A:A7DD */
/* not lifted: $2AA882: TXS at $2A:A8A8 */
/* not lifted: $2AA8A8: TXS at $2A:A8A8 */
/* not lifted: $2AAA2A: PLX at $AA34 pulls below the entry stack (return-address trick) */
/* not lifted: $2AAA80: PLX at $AAA0 pulls below the entry stack (return-address trick) */
/* not lifted: $2AAAA2: XCE at $2A:AAA2 */
/* not lifted: $2AAABA: XCE at $2A:AAA2 */
/* not lifted: $2AACAA: XCE at $2A:AD6E */
/* not lifted: $2AAE8A: BRK at $2A:B0F2 */
/* not lifted: $2AB904: COP at $2A:B90D */
/* not lifted: $2ABA8A: BRK at $2A:BA9A */
/* not lifted: $2ABD0C: BRK at $2A:BD20 */
/* not lifted: $2AC17F: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2ACF26: WAI at $2A:CF36 */
/* not lifted: $2ACF43: PLY at $CF6E pulls below the entry stack (return-address trick) */
/* not lifted: $2AD226: BRK at $2A:0DD7 */
/* not lifted: $2AD617: BRK at $2A:D69B */
/* not lifted: $2ADA05: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AE190: COP at $2A:E1A2 */
/* not lifted: $2AE191: COP at $2A:E1A2 */
/* not lifted: $2AE290: BRK at $2A:E2C2 */
/* not lifted: $2AE291: BRK at $2A:E2C2 */
/* not lifted: $2AE2AA: BRK at $2A:E2C2 */
/* not lifted: $2AE390: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AE391: BRK at $2A:E39F */
/* not lifted: $2AE490: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AE491: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AE6FF: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AE990: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AE991: COP at $2A:E993 */
/* not lifted: $2AEA2A: BRK at $2A:EA4E */
/* not lifted: $2AEA90: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AEA91: WAI at $2A:EB38 */
/* not lifted: $2AEB90: BRK at $2A:EB9F */
/* not lifted: $2AEB91: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AF191: PLY at $F191 pulls below the entry stack (return-address trick) */
/* not lifted: $2AF291: PLP at $F2AB pulls below the entry stack (return-address trick) */
/* not lifted: $2AF391: BRK at $2A:B8AF */
/* not lifted: $2AF491: tail jump at $F4E5 with 2 bytes pushed */
/* not lifted: $2AF990: BRK at $2A:F992 */
/* not lifted: $2AFA90: COP at $2A:FA9A */
/* not lifted: $2AFA91: COP at $2A:FA9A */
/* not lifted: $2AFB90: BRK at $2A:FBAF */
/* not lifted: $2AFB91: BRK at $2A:FBAF */
/* not lifted: $2AFC2C: XCE at $2A:FC2E */
/* not lifted: $2AFC90: RTL at $FD10 with 4 bytes still pushed */
/* not lifted: $2AFC91: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AFE00: tail jump at $FE1C with 2 bytes pushed */
/* not lifted: $2AFE0D: tail jump at $FE1C with 2 bytes pushed */
/* not lifted: $2AFF69: PLA at $FF69 pulls below the entry stack (return-address trick) */
/* not lifted: $2AFFE0: PLX at $FFED pulls below the entry stack (return-address trick) */
/* not lifted: $2AFFE8: PLX at $FFED pulls below the entry stack (return-address trick) */
/* not lifted: $2AFFF0: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2AFFF8: TCS at $0031 with an unknown stack value */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2A91F5, entered with P=$30 via JSR */
void gen_2A91F5(void) {
    goto L_91F5;
L_0ED0:;
    recomp_tick(40); g_wr8(0x3535A0u, (uint8_t)(uint8_t)g_cpu.C);  /* 0ED0 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* 0ED4 DEX */
    recomp_tick(32); { uint32_t _e = g_dp(0x2E); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 0ED5 TRB */
    recomp_tick(14); return;  /* 0ED7 RTI */
L_91F5:;
    recomp_tick(24); goto L_0ED0;  /* 91F5 JMP */
}

/* $2AA8AA, entered with P=$30 via JSL */
void gen_2AA8AA(void) {
    goto L_A8AA;
L_A8AA:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* A8AA TXY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x9C))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8AB ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x059D05u)))));  /* A8AD SBC */
    recomp_tick(32); g_wr8(g_absx(0x9F05), 0);  /* A8B1 STZ */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xA0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8B4 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04A104u)))));  /* A8B6 SBC */
    recomp_tick(16); { uint8_t _v = 0x04; g_cpu.X = _v; g_nz8(_v); }  /* A8BA LDX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_sr(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8BC LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xFF)); g_cpu.Y = _v; g_nz8(_v); }  /* A8BE LDY */
    recomp_tick(32); { uint32_t _e = g_dp(0xA5); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8C0 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xA6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8C2 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xA7); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8C4 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xA8); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8C6 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04A904u)))));  /* A8C8 SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* A8CC TAX */
    recomp_tick(32); { uint32_t _e = g_dp(0xAB); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8CD TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xAC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8CF TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04AD04u)))));  /* A8D1 SBC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0xAF04)); g_cpu.X = _v; g_nz8(_v); }  /* A8D5 LDX */
    recomp_tick(32); { uint32_t _e = g_dp(0xA0); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A8D8 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05A105u)))));  /* A8DA SBC */
    recomp_tick(16); { uint8_t _v = 0x05; g_cpu.X = _v; g_nz8(_v); }  /* A8DE LDX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_sr(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8E0 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xFF)); g_cpu.Y = _v; g_nz8(_v); }  /* A8E2 LDY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xA5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8E4 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xA6))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8E6 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xA7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8E8 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xA8))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8EA ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05A905u)))));  /* A8EC SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* A8F0 TAX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xAB))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8F1 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xAC))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8F3 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05AD05u)))));  /* A8F5 SBC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0xAF05)); g_cpu.X = _v; g_nz8(_v); }  /* A8F9 LDX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xB0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8FC ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04B104u)))));  /* A8FE SBC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpi(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A902 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_sriy(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A904 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0xFF)); g_cpu.Y = _v; g_nz8(_v); }  /* A906 LDY */
    recomp_tick(32); { uint32_t _e = g_dp(0xB5); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A908 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xB6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A90A TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xB7); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A90C TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xB8); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A90E TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04B904u)))));  /* A910 SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.S; g_cpu.X = _v; g_nz8(_v); }  /* A914 TSX */
    recomp_tick(32); { uint32_t _e = g_dp(0xBB); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A915 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xBC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A917 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04BD04u)))));  /* A919 SBC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xBF04)); g_cpu.X = _v; g_nz8(_v); }  /* A91D LDX */
    recomp_tick(32); { uint32_t _e = g_dp(0xB0); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A920 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05B105u)))));  /* A922 SBC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpi(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A926 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_sriy(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A928 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0xFF)); g_cpu.Y = _v; g_nz8(_v); }  /* A92A LDY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xB5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A92C ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xB6))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A92E ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xB7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A930 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xB8))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A932 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05B905u)))));  /* A934 SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.S; g_cpu.X = _v; g_nz8(_v); }  /* A938 TSX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xBB))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A939 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xBC))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A93B ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05BD05u)))));  /* A93D SBC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xBF05)); g_cpu.X = _v; g_nz8(_v); }  /* A941 LDX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xC0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A944 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04C104u)))));  /* A946 SBC */
    recomp_tick(16); g_rep(0x04);  /* A94A REP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x04)));  /* A94C CMP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.Y, g_rd8(g_dp(0xFF)));  /* A94E CPY */
    recomp_tick(32); { uint32_t _e = g_dp(0xC5); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A950 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xC6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A952 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xC7); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A954 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xC8); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A956 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04C904u)))));  /* A958 SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* A95C DEX */
    recomp_tick(32); { uint32_t _e = g_dp(0xCB); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A95D TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A95F TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04CD04u)))));  /* A961 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0xCF04); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A965 DEC */
    recomp_tick(32); { uint32_t _e = g_dp(0xC0); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A968 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05C105u)))));  /* A96A SBC */
    recomp_tick(16); g_rep(0x05);  /* A96E REP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x05)));  /* A970 CMP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.Y, g_rd8(g_dp(0xFF)));  /* A972 CPY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xC5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A974 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xC6))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A976 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xC7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A978 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xC8))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A97A ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05C905u)))));  /* A97C SBC */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* A980 DEX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xCB))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A981 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xCC))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A983 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05CD05u)))));  /* A985 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0xCF05); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A989 DEC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xD0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A98C ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04D104u)))));  /* A98E SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dpi(0x04)));  /* A992 CMP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x04)));  /* A994 CMP */
    recomp_tick(24); g_push16(g_rd16(g_dp(0xFF)));  /* A996 PEI */
    recomp_tick(32); { uint32_t _e = g_dp(0xD5); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A998 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xD6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A99A TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xD7); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A99C TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xD8); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A99E TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04D904u)))));  /* A9A0 SBC */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* A9A4 PHX */
    recomp_tick(32); { uint32_t _e = g_dp(0xDB); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9A5 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xDC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9A7 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04DD04u)))));  /* A9A9 SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xDF04); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A9AD DEC */
    recomp_tick(32); { uint32_t _e = g_dp(0xD0); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9B0 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05D105u)))));  /* A9B2 SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dpi(0x05)));  /* A9B6 CMP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x05)));  /* A9B8 CMP */
    recomp_tick(24); g_push16(g_rd16(g_dp(0xFF)));  /* A9BA PEI */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xD5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9BC ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xD6))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9BE ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xD7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9C0 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xD8))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9C2 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05D905u)))));  /* A9C4 SBC */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* A9C8 PHX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xDB))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9C9 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xDC))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9CB ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05DD05u)))));  /* A9CD SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xDF05); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A9D1 DEC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xE0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9D4 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04E104u)))));  /* A9D6 SBC */
    recomp_tick(16); g_sep(0x04);  /* A9DA SEP */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x04)))));  /* A9DC SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0xFF)));  /* A9DE CPX */
    recomp_tick(32); { uint32_t _e = g_dp(0xE5); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9E0 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xE6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9E2 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xE7); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9E4 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xE8); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9E6 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04E904u)))));  /* A9E8 SBC */
    recomp_tick(14); ;  /* A9EC NOP */
    recomp_tick(32); { uint32_t _e = g_dp(0xEB); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9ED TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xEC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9EF TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04ED04u)))));  /* A9F1 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0xEF04); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A9F5 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0xE0); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A9F8 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05E105u)))));  /* A9FA SBC */
    recomp_tick(16); g_sep(0x05);  /* A9FE SEP */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x05)))));  /* AA00 SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0xFF)));  /* AA02 CPX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xE5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA04 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xE6))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA06 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xE7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA08 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xE8))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA0A ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05E905u)))));  /* AA0C SBC */
    recomp_tick(14); ;  /* AA10 NOP */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xEB))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA11 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xEC))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA13 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05ED05u)))));  /* AA15 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0xEF05); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA19 INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xF0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA1C ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04F104u)))));  /* AA1E SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpi(0x04)))));  /* AA22 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x04)))));  /* AA24 SBC */
    recomp_tick(24); g_push16(0x04FF);  /* AA26 PEA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x04)))));  /* AA29 SBC */
    recomp_tick(32); { uint32_t _e = g_dpx(0x04); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA2B INC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0x04)))));  /* AA2D SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA2F SED */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04F904u)))));  /* AA30 SBC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* AA34 PLX */
    recomp_tick(32); { uint32_t _e = g_dp(0xFB); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* AA35 TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0xFC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* AA37 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x04FD04u)))));  /* AA39 SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xFF04); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA3D INC */
    recomp_tick(32); { uint32_t _e = g_dp(0xF0); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* AA40 TSB */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05F105u)))));  /* AA42 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpi(0x05)))));  /* AA46 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x05)))));  /* AA48 SBC */
    recomp_tick(24); g_push16(0x05FF);  /* AA4A PEA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x05)))));  /* AA4D SBC */
    recomp_tick(32); { uint32_t _e = g_dpx(0x05); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA4F INC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0x05)))));  /* AA51 SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA53 SED */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05F905u)))));  /* AA54 SBC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* AA58 PLX */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xFB))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA59 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xFC))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA5B ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x05FD05u)))));  /* AA5D SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xFF05); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA61 INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0xF0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA64 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x80F180u)))));  /* AA66 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpi(0x80)))));  /* AA6A SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x80)))));  /* AA6C SBC */
    recomp_tick(24); g_push16(0x80FF);  /* AA6E PEA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x80)))));  /* AA71 SBC */
    recomp_tick(32); { uint32_t _e = g_dpx(0x80); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA73 INC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0x80)))));  /* AA75 SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA77 SED */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x80F980u)))));  /* AA78 SBC */
    goto L_AA7C;
L_AA7A:;
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absy(0xFA80)))));  /* AA7A SBC */
    goto L_AA7D;
L_AA7C:;
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* AA7C PLX */
L_AA7D:;
    recomp_tick(16); goto L_AA7A;  /* AA7D BRA */
}

/* $2AAA01, entered with P=$00 via JSR */
void gen_2AAA01(void) {
    goto L_AA01;
L_AA01:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xE4))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA01 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x05E505u))));  /* AA03 SBC */
    recomp_tick(48); { uint32_t _e = g_dp(0x05); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA07 INC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpil(0x05))));  /* AA09 SBC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AA0B INX */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x05E905u))));  /* AA0C SBC */
    recomp_tick(14); ;  /* AA10 NOP */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xEB))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA11 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xEC))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA13 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x05ED05u))));  /* AA15 SBC */
    recomp_tick(56); { uint32_t _e = g_abs(0xEF05); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA19 INC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xF0))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA1C ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x04F104u))));  /* AA1E SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpi(0x04))));  /* AA22 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0x04))));  /* AA24 SBC */
    recomp_tick(24); g_push16(0x04FF);  /* AA26 PEA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpx(0x04))));  /* AA29 SBC */
    recomp_tick(48); { uint32_t _e = g_dpx(0x04); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA2B INC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpily(0x04))));  /* AA2D SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA2F SED */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x04F904u))));  /* AA30 SBC */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AA34 PLX */
    recomp_tick(48); { uint32_t _e = g_dp(0xFB); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* AA35 TSB */
    recomp_tick(48); { uint32_t _e = g_dp(0xFC); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* AA37 TSB */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x04FD04u))));  /* AA39 SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0xFF04); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA3D INC */
    recomp_tick(48); { uint32_t _e = g_dp(0xF0); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* AA40 TSB */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x05F105u))));  /* AA42 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpi(0x05))));  /* AA46 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0x05))));  /* AA48 SBC */
    recomp_tick(24); g_push16(0x05FF);  /* AA4A PEA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpx(0x05))));  /* AA4D SBC */
    recomp_tick(48); { uint32_t _e = g_dpx(0x05); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA4F INC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpily(0x05))));  /* AA51 SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA53 SED */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x05F905u))));  /* AA54 SBC */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AA58 PLX */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xFB))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA59 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xFC))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA5B ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x05FD05u))));  /* AA5D SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0xFF05); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA61 INC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xF0))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA64 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x80F180u))));  /* AA66 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpi(0x80))));  /* AA6A SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0x80))));  /* AA6C SBC */
    recomp_tick(24); g_push16(0x80FF);  /* AA6E PEA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpx(0x80))));  /* AA71 SBC */
    recomp_tick(48); { uint32_t _e = g_dpx(0x80); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA73 INC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpily(0x80))));  /* AA75 SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA77 SED */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x80F980u))));  /* AA78 SBC */
    goto L_AA7C;
L_AA7A:;
    recomp_tick(40); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_absy(0xFA80))));  /* AA7A SBC */
    goto L_AA7D;
L_AA7C:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AA7C PLX */
L_AA7D:;
    recomp_tick(16); goto L_AA7A;  /* AA7D BRA */
}

/* $2AAA82, entered with P=$30 via JSL */
void gen_2AAA82(void) {
    goto L_AA82;
L_AA7A:;
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absy(0xFA80)))));  /* AA7A SBC */
    recomp_tick(16); goto L_AA7A;  /* AA7D BRA */
L_AA81:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x80FD80u)))));  /* AA81 SBC */
    goto L_AA85;
L_AA82:;
    recomp_tick(16); goto L_AA81;  /* AA82 BRA */
L_AA85:;
    recomp_tick(40); { uint32_t _e = g_absx(0xFF80); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA85 INC */
    recomp_tick(16); goto L_AA7A;  /* AA88 BRA */
}

/* $2AAA8A, entered with P=$00 via JSL */
void gen_2AAA8A(void) {
    goto L_AA8A;
L_AA8A:;
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x81F181u))));  /* AA8A SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpi(0x81))));  /* AA8E SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0x81))));  /* AA90 SBC */
    recomp_tick(24); g_push16(0x81FF);  /* AA92 PEA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpx(0x81))));  /* AA95 SBC */
    recomp_tick(48); { uint32_t _e = g_dpx(0x81); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA97 INC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpily(0x81))));  /* AA99 SBC */
    recomp_tick(14); g_cpu.flag_D = true;  /* AA9B SED */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x81F981u))));  /* AA9C SBC */
    goto L_AAA0;
L_AA9F:;
    recomp_tick(32); g_wr16(g_dpxi(0xFA), (uint16_t)g_cpu.C);  /* AA9F STA */
    goto L_AAA1;
L_AAA0:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AAA0 PLX */
L_AAA1:;
    recomp_tick(32); g_wr16(g_dpxi(0xFB), (uint16_t)g_cpu.C);  /* AAA1 STA */
    recomp_tick(32); g_wr16(g_dpxi(0xFC), (uint16_t)g_cpu.C);  /* AAA3 STA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x81FD81u))));  /* AAA5 SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0xFF81); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AAA9 INC */
    recomp_tick(32); g_wr16(g_dpxi(0xE0), (uint16_t)g_cpu.C);  /* AAAC STA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x80E180u))));  /* AAAE SBC */
    recomp_tick(16); g_sep(0x80);  /* AAB2 SEP */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sr(0x80))));  /* AAB4 SBC */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_dp(0xFF)));  /* AAB6 CPX */
    recomp_tick(16); goto L_AA9F;  /* AAB8 BRA */
}

/* $2AAAA8, entered with P=$30 via JSL */
void gen_2AAAA8(void) {
    goto L_AAA8;
L_AA9F:;
    recomp_tick(24); g_wr8(g_dpxi(0xFA), (uint8_t)(uint8_t)g_cpu.C);  /* AA9F STA */
    recomp_tick(24); g_wr8(g_dpxi(0xFB), (uint8_t)(uint8_t)g_cpu.C);  /* AAA1 STA */
    recomp_tick(24); g_wr8(g_dpxi(0xFC), (uint8_t)(uint8_t)g_cpu.C);  /* AAA3 STA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x81FD81u)))));  /* AAA5 SBC */
    goto L_AAA9;
L_AAA8:;
    recomp_tick(24); g_wr8(g_dpxi(0xFE), (uint8_t)(uint8_t)g_cpu.C);  /* AAA8 STA */
    goto L_AAAA;
L_AAA9:;
    recomp_tick(40); { uint32_t _e = g_absx(0xFF81); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AAA9 INC */
    goto L_AAAC;
L_AAAA:;
    recomp_tick(24); g_wr8(g_dpxi(0xFF), (uint8_t)(uint8_t)g_cpu.C);  /* AAAA STA */
L_AAAC:;
    recomp_tick(24); g_wr8(g_dpxi(0xE0), (uint8_t)(uint8_t)g_cpu.C);  /* AAAC STA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x80E180u)))));  /* AAAE SBC */
    recomp_tick(16); g_sep(0x80);  /* AAB2 SEP */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x80)))));  /* AAB4 SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0xFF)));  /* AAB6 CPX */
    recomp_tick(16); goto L_AA9F;  /* AAB8 BRA */
}

/* $2AAAAA, entered with P=$20 via JSL */
void gen_2AAAAA(void) {
    goto L_AAAA;
L_AA9F:;
    recomp_tick(24); g_wr8(g_dpxi(0xFA), (uint8_t)(uint8_t)g_cpu.C);  /* AA9F STA */
    recomp_tick(24); g_wr8(g_dpxi(0xFB), (uint8_t)(uint8_t)g_cpu.C);  /* AAA1 STA */
    recomp_tick(24); g_wr8(g_dpxi(0xFC), (uint8_t)(uint8_t)g_cpu.C);  /* AAA3 STA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x81FD81u)))));  /* AAA5 SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xFF81); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AAA9 INC */
    goto L_AAAC;
L_AAAA:;
    recomp_tick(24); g_wr8(g_dpxi(0xFF), (uint8_t)(uint8_t)g_cpu.C);  /* AAAA STA */
L_AAAC:;
    recomp_tick(24); g_wr8(g_dpxi(0xE0), (uint8_t)(uint8_t)g_cpu.C);  /* AAAC STA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x80E180u)))));  /* AAAE SBC */
    recomp_tick(16); g_sep(0x80);  /* AAB2 SEP */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x80)))));  /* AAB4 SBC */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_dp(0xFF)));  /* AAB6 CPX */
    recomp_tick(16); goto L_AA9F;  /* AAB8 BRA */
}

/* $2AAAAE, entered with P=$30 via JSL */
void gen_2AAAAE(void) {
    goto L_AAAE;
L_AA9F:;
    recomp_tick(24); g_wr8(g_dpxi(0xFA), (uint8_t)(uint8_t)g_cpu.C);  /* AA9F STA */
    recomp_tick(24); g_wr8(g_dpxi(0xFB), (uint8_t)(uint8_t)g_cpu.C);  /* AAA1 STA */
    recomp_tick(24); g_wr8(g_dpxi(0xFC), (uint8_t)(uint8_t)g_cpu.C);  /* AAA3 STA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x81FD81u)))));  /* AAA5 SBC */
    recomp_tick(40); { uint32_t _e = g_absx(0xFF81); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AAA9 INC */
    recomp_tick(24); g_wr8(g_dpxi(0xE0), (uint8_t)(uint8_t)g_cpu.C);  /* AAAC STA */
L_AAAE:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x80E180u)))));  /* AAAE SBC */
    recomp_tick(16); g_sep(0x80);  /* AAB2 SEP */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x80)))));  /* AAB4 SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0xFF)));  /* AAB6 CPX */
    recomp_tick(16); goto L_AA9F;  /* AAB8 BRA */
}

/* $2AEC90, entered with P=$30 via JSR */
void gen_2AEC90(void) {
    goto L_EC90;
L_EC90:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x65)))));  /* EC90 ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpxi(0x1A))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* EC92 ORA */
    recomp_tick(14); return;  /* EC94 RTI */
}

/* $2AEC91, entered with P=$30 via JSR */
void gen_2AEC91(void) {
    goto L_EC91;
L_EC91:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x01)))));  /* EC91 ADC */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* EC93 INC */
    recomp_tick(14); return;  /* EC94 RTI */
}

/* $2AF991, entered with P=$30 via JSL */
void gen_2AF991(void) {
    goto L_F991;
L_F991:;
    recomp_tick(14); return;  /* F991 RTL */
}

void gen_register_bank_2A(void) {
    func_table_register_flags(0x2A91F5, gen_2A91F5, false);
    func_table_register_flags(0x2AA8AA, gen_2AA8AA, true);
    func_table_register_flags(0x2AAA01, gen_2AAA01, false);
    func_table_register_flags(0x2AAA82, gen_2AAA82, true);
    func_table_register_flags(0x2AAA8A, gen_2AAA8A, true);
    func_table_register_flags(0x2AAAA8, gen_2AAAA8, true);
    func_table_register_flags(0x2AAAAA, gen_2AAAAA, true);
    func_table_register_flags(0x2AAAAE, gen_2AAAAE, true);
    func_table_register_flags(0x2AEC90, gen_2AEC90, false);
    func_table_register_flags(0x2AEC91, gen_2AEC91, false);
    func_table_register_flags(0x2AF991, gen_2AF991, true);
}
