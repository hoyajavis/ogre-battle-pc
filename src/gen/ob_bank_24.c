/* Bank $24 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 9 lifted, 42 unlifted in Bank $24 */
/* not lifted: $248037: PLD at $8050 pulls below the entry stack (return-address trick) */
/* not lifted: $2480A9: RTS at $80C6 with 2 bytes still pushed */
/* not lifted: $248106: BRK at $24:8108 */
/* not lifted: $248123: BRK at $24:8132 */
/* not lifted: $24828F: PLY at $82BC pulls below the entry stack (return-address trick) */
/* not lifted: $248500: PLX at $853D pulls below the entry stack (return-address trick) */
/* not lifted: $248504: PLX at $853D pulls below the entry stack (return-address trick) */
/* not lifted: $248580: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2488CC: COP at $24:8938 */
/* not lifted: $2488CD: RTS at $891A with 1 bytes still pushed */
/* not lifted: $2488D8: COP at $24:88EC */
/* not lifted: $2488F4: RTS at $891A with 1 bytes still pushed */
/* not lifted: $2488FD: RTS at $891A with 1 bytes still pushed */
/* not lifted: $248946: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $24896D: BRK at $24:8978 */
/* not lifted: $2489A2: PLY at $89A2 pulls below the entry stack (return-address trick) */
/* not lifted: $2489E3: XCE at $24:8A00 */
/* not lifted: $248C11: COP at $24:8C22 */
/* not lifted: $24906E: PLD at $906E pulls below the entry stack (return-address trick) */
/* not lifted: $24940E: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $249480: COP at $24:9488 */
/* not lifted: $249811: COP at $24:9815 */
/* not lifted: $249920: BRK at $24:9922 */
/* not lifted: $24A221: WAI at $24:A22B */
/* not lifted: $24A26A: PLY at $5DC2 pulls below the entry stack (return-address trick) */
/* not lifted: $24A903: tail jump at $A91F with 3 bytes pushed */
/* not lifted: $24A943: PLB at $A972 pulls below the entry stack (return-address trick) */
/* not lifted: $24AA2A: PLP at $AA2E without a matching PHP */
/* not lifted: $24AA8A: BRK at $24:AA8C */
/* not lifted: $24AAA2: RTI at $AB50 with 10 bytes still pushed */
/* not lifted: $24B43C: XCE at $24:B447 */
/* not lifted: $24B4FC: BRK at $24:B506 */
/* not lifted: $24C6C5: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $24E0D7: BRK at $24:E0F7 */
/* not lifted: $24F25A: RTI at $40AD with 5 bytes still pushed */
/* not lifted: $24F6A5: WAI at $24:F6DD */
/* not lifted: $24F6B6: WAI at $24:F6DD */
/* not lifted: $24F6B9: WAI at $24:F6BD */
/* not lifted: $24F891: WAI at $24:F8B6 */
/* not lifted: $24F8F7: COP at $24:F900 */
/* not lifted: $24FC17: BRK at $24:FC22 */
/* not lifted: $24FC51: TCS at $1CFA with an unknown stack value */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2480C2, entered with P=$00 via JSR */
void gen_2480C2(void) {
    goto L_80C2;
L_80C2:;
    recomp_tick(56); { uint32_t _e = g_absx(0x8540); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 80C2 ROL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 80C5 CLC */
    recomp_tick(14); return;  /* 80C6 RTS */
}

/* $24838D, entered with P=$30 via JSR */
void gen_24838D(void) {
    goto L_838D;
L_838D:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpxi(0x62)))));  /* 838D ADC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x0F)))));  /* 838F ADC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_absx(0xC5AF)))));  /* 8391 ADC */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x1B1A1Cu));  /* 8394 CMP */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absx(0x3C07))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8398 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x48))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 839B ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpi(0xF1)))));  /* 839D SBC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_longx(0xC6C4E1u))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 839F EOR */
    recomp_tick(14); g_push8((uint8_t)g_cpu.Y);  /* 83A3 PHY */
    recomp_tick(14); g_push8((uint8_t)g_cpu.Y);  /* 83A4 PHY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x36))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83A5 ORA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0x27)));  /* 83A7 CPX */
    recomp_tick(16); g_rep(0x3F);  /* 83A9 REP */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x03))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 83AB ORA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 83AD PLA */
    recomp_tick(16); if (g_cpu.flag_V) goto L_8421;  /* 83AE BVS */
    recomp_tick(14); return;  /* 83B0 RTL */
L_8421:;
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(0x1213FEu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8421 ORA */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_absx(0xFF0E))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8425 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(0xFDE1F0u)));  /* 8428 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpxi(0x17))));  /* 842C SBC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x7403)); g_cpu.X = _v; g_nz16(_v); }  /* 842E LDX */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0xEF))));  /* 8431 ADC */
    recomp_tick(48); { uint32_t _e = g_dp(0x67); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8433 ROR */
    recomp_tick(14); return;  /* 8435 RTS */
}

/* $248400, entered with P=$00 via JSR */
void gen_248400(void) {
    goto L_8400;
L_8400:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpx(0x14))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8400 ORA */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_840A;  /* 8402 BCC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_sriy(0xE0)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8404 LDA */
    recomp_tick(48); g_cmp16(g_cpu.C, g_rd16(0xC5C4E1u));  /* 8406 CMP */
L_840A:;
    recomp_tick(48); { uint32_t _e = g_dp(0x1E); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* 840A DEC */
    recomp_tick(32); g_wr16(g_dp(0x07), (uint16_t)g_cpu.C);  /* 840C STA */
    recomp_tick(56); { uint32_t _e = g_absx(0x766F); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 840E ROR */
    recomp_tick(56); { uint32_t _e = g_absx(0x41AF); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 8411 INC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x17))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8414 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpxi(0x14))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8416 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x03))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8418 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpx(0x71))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 841A ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpxi(0x07))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 841C ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x0FBD07u))));  /* 841E SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0x1213); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 8422 INC */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_absx(0xFF0E))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8425 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(0xFDE1F0u)));  /* 8428 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpxi(0x17))));  /* 842C SBC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x7403)); g_cpu.X = _v; g_nz16(_v); }  /* 842E LDX */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0xEF))));  /* 8431 ADC */
    recomp_tick(48); { uint32_t _e = g_dp(0x67); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8433 ROR */
    recomp_tick(14); return;  /* 8435 RTS */
}

/* $248413, entered with P=$00 via JSR */
void gen_248413(void) {
    goto L_8413;
L_8413:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C ^ g_rd16(g_dpxi(0x03))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8413 EOR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpily(0x01))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8415 ORA */
    recomp_tick(48); { uint32_t _e = g_dp(0x03); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v & ~g_cpu.C)); }  /* 8417 TRB */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x15))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8419 ORA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dpiy(0x01))));  /* 841B ADC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0xFF))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 841D ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0xBD))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 841F ORA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(0x1213FEu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8421 ORA */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_absx(0xFF0E))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8425 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(0xFDE1F0u)));  /* 8428 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpxi(0x17))));  /* 842C SBC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x7403)); g_cpu.X = _v; g_nz16(_v); }  /* 842E LDX */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0xEF))));  /* 8431 ADC */
    recomp_tick(48); { uint32_t _e = g_dp(0x67); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8433 ROR */
    recomp_tick(14); return;  /* 8435 RTS */
}

/* $248414, entered with P=$00 via JSR */
void gen_248414(void) {
    goto L_8414;
L_8414:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x17))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8414 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpxi(0x14))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8416 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x03))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8418 ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpx(0x71))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 841A ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpxi(0x07))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 841C ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x0FBD07u))));  /* 841E SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0x1213); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 8422 INC */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_absx(0xFF0E))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8425 ORA */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(0xFDE1F0u)));  /* 8428 SBC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpxi(0x17))));  /* 842C SBC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x7403)); g_cpu.X = _v; g_nz16(_v); }  /* 842E LDX */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0xEF))));  /* 8431 ADC */
    recomp_tick(48); { uint32_t _e = g_dp(0x67); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8433 ROR */
    recomp_tick(14); return;  /* 8435 RTS */
}

/* $2488AA, entered with P=$30 via JSR */
void gen_2488AA(void) {
    goto L_88AA;
L_88AA:;
    recomp_tick(16); { uint8_t _v = 0x19; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 88AA LDA */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_longx(0x755225u))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 88AC ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x76))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 88B0 ORA */
    recomp_tick(14); return;  /* 88B2 RTI */
}

/* $24A200, entered with P=$00 via JSR */
void gen_24A200(void) {
    goto L_A200;
L_A200:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0x17))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A200 ORA */
    recomp_tick(48); g_cmp16(g_cpu.C, g_rd16(g_longx(0x434B42u)));  /* A202 CMP */
    recomp_tick(14); return;  /* A206 RTI */
}

/* $24B20F, entered with P=$00 via JSR */
void gen_24B20F(void) {
    goto L_B20F;
L_B20F:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_dpxi(0x17))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B20F AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* B211 DEX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B212 TAX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xC7E1);  /* B213 CPX */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_dp(0xC5)));  /* B216 CPY */
    recomp_tick(48); { uint32_t _e = g_dp(0x06); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* B218 DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* B21A TYX */
    recomp_tick(48); { uint32_t _e = g_dp(0x81); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* B21B ASL */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0xF8))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B21D ORA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_sriy(0xBE))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B21F AND */
    recomp_tick(56); { uint32_t _e = g_abs(0xB345); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* B221 DEC */
    recomp_tick(14); return;  /* B224 RTI */
}

/* $24EAAA, entered with P=$30 via JSR */
void gen_24EAAA(void) {
    goto L_EAAA;
L_EAAA:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.Y, 0x47);  /* EAAA CPY */
    recomp_tick(14); return;  /* EAAC RTI */
}

void gen_register_bank_24(void) {
    func_table_register_flags(0x2480C2, gen_2480C2, false);
    func_table_register_flags(0x24838D, gen_24838D, false);
    func_table_register_flags(0x248400, gen_248400, false);
    func_table_register_flags(0x248413, gen_248413, false);
    func_table_register_flags(0x248414, gen_248414, false);
    func_table_register_flags(0x2488AA, gen_2488AA, false);
    func_table_register_flags(0x24A200, gen_24A200, false);
    func_table_register_flags(0x24B20F, gen_24B20F, false);
    func_table_register_flags(0x24EAAA, gen_24EAAA, false);
}
