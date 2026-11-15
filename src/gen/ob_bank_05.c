/* Bank $05 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 73 lifted, 168 unlifted in Bank $05 */
/* not lifted: $05817C: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $0581CF: BRK at $05:81EF */
/* not lifted: $058241: COP at $05:8296 */
/* not lifted: $058299: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0583EF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $058400: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $058436: calls unlifted target 0x05817C: executes native on LakeSnes */
/* not lifted: $058443: COP at $05:845F */
/* not lifted: $058493: BRK at $05:8575 */
/* not lifted: $0585A1: BRK at $05:8657 */
/* not lifted: $058659: BRK at $05:86CF */
/* not lifted: $0586D1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05872F: calls unlifted target 0x058443: executes native on LakeSnes */
/* not lifted: $058743: BRK at $05:8792 */
/* not lifted: $05879F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0588B6: PLP at $88DB without a matching PHP */
/* not lifted: $058971: BRK at $05:89A9 */
/* not lifted: $058C7A: BRK at $05:8C89 */
/* not lifted: $058C8E: STP at $05:8C9C */
/* not lifted: $058CA2: BRK at $05:8CC7 */
/* not lifted: $058D9E: PLP at $8DC1 without a matching PHP */
/* not lifted: $05942D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0594FA: COP at $05:9519 */
/* not lifted: $059565: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $0595FE: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $0596A1: calls unlifted target 0x0581CF: executes native on LakeSnes */
/* not lifted: $0596DE: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $05972B: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $0597DE: BRK at $05:9806 */
/* not lifted: $059841: calls unlifted target 0x059AF2: executes native on LakeSnes */
/* not lifted: $059920: COP at $05:9923 */
/* not lifted: $05993B: BRK at $05:9947 */
/* not lifted: $059A09: BRK at $05:9A13 */
/* not lifted: $059AAA: COP at $05:9ADF */
/* not lifted: $059AF2: $05:9B7D reached with two different M/X/stack states */
/* not lifted: $059BA8: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $059BB4: BRK at $05:9BBB */
/* not lifted: $059E11: calls unlifted target 0x059ECC: executes native on LakeSnes */
/* not lifted: $059E4A: calls unlifted target 0x05A4D5: executes native on LakeSnes */
/* not lifted: $059E55: tail jump at $9E5D with 4 bytes pushed */
/* not lifted: $059E85: BRK at $05:9EB3 */
/* not lifted: $059ECC: BRK at $05:9EF5 */
/* not lifted: $059F2D: BRK at $05:9F35 */
/* not lifted: $059F54: BRK at $05:9F91 */
/* not lifted: $059F97: BRK at $05:9FCC */
/* not lifted: $059FCE: BRK at $05:9FDB */
/* not lifted: $05A000: BRK at $05:A00B */
/* not lifted: $05A15A: BRK at $05:A16D */
/* not lifted: $05A4D5: BRK at $05:A54C */
/* not lifted: $05A568: BRK at $05:A578 */
/* not lifted: $05A5F0: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05A612: calls unlifted target 0x05A668: executes native on LakeSnes */
/* not lifted: $05A668: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05A73C: XCE at $05:A7EF */
/* not lifted: $05A78A: BRK at $05:A7C5 */
/* not lifted: $05A7F4: BRK at $05:A7F9 */
/* not lifted: $05A898: BRK at $05:A8A9 */
/* not lifted: $05A8AF: BRK at $05:A8D8 */
/* not lifted: $05A9C6: BRK at $05:A9CD */
/* not lifted: $05AA52: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AA7F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AA89: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AA99: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AAC3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AD18: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AD6D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AD7F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AD8F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AD9F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05ADB2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05ADE7: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05ADFA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AE0A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AE1A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AE76: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AE90: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AF60: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AFD9: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05AFE6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B034: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B06C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B079: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B08A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B107: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B142: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B177: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B1A9: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B2E3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B2E8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B37D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B391: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $05B48A: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05B5E8: BRK at $05:B60F */
/* not lifted: $05B77A: BRK at $05:00CC */
/* not lifted: $05B801: calls unlifted target 0x05993B: executes native on LakeSnes */
/* not lifted: $05B881: calls unlifted target 0x05C132: executes native on LakeSnes */
/* not lifted: $05B8D6: calls unlifted target 0x05C132: executes native on LakeSnes */
/* not lifted: $05B9F8: calls unlifted target 0x05BE93: executes native on LakeSnes */
/* not lifted: $05B9FE: calls unlifted target 0x05BE93: executes native on LakeSnes */
/* not lifted: $05BA72: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05BAAC: BRK at $05:BAAE */
/* not lifted: $05BACA: calls unlifted target 0x05BC3E: executes native on LakeSnes */
/* not lifted: $05BAD3: calls unlifted target 0x05BC3E: executes native on LakeSnes */
/* not lifted: $05BADC: calls unlifted target 0x05BC3E: executes native on LakeSnes */
/* not lifted: $05BAE5: calls unlifted target 0x05BC3E: executes native on LakeSnes */
/* not lifted: $05BB09: calls unlifted target 0x05BC3E: executes native on LakeSnes */
/* not lifted: $05BC3E: BRK at $05:BC65 */
/* not lifted: $05BC67: BRK at $05:BCB7 */
/* not lifted: $05BD7D: BRK at $05:BDB9 */
/* not lifted: $05BD81: BRK at $05:BDB9 */
/* not lifted: $05BD85: BRK at $05:BDB9 */
/* not lifted: $05BD89: BRK at $05:BDB9 */
/* not lifted: $05BDC1: BRK at $05:BE06 */
/* not lifted: $05BDC6: BRK at $05:BE06 */
/* not lifted: $05BDCB: BRK at $05:BE06 */
/* not lifted: $05BE93: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05BEB6: BRK at $05:BED2 */
/* not lifted: $05BF3F: calls unlifted target 0x059565: executes native on LakeSnes */
/* not lifted: $05BF4F: calls unlifted target 0x059565: executes native on LakeSnes */
/* not lifted: $05BF5F: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05BF6B: calls unlifted target 0x058299: executes native on LakeSnes */
/* not lifted: $05BF84: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05BF93: tail jump at $BFA2 with 1 bytes pushed */
/* not lifted: $05C005: RTI at $C00C with 1 bytes still pushed */
/* not lifted: $05C01E: BRK at $05:C048 */
/* not lifted: $05C059: BRK at $05:C060 */
/* not lifted: $05C065: BRK at $05:C09E */
/* not lifted: $05C0A2: BRK at $05:C0C8 */
/* not lifted: $05C0FF: calls unlifted target 0x058CA2: executes native on LakeSnes */
/* not lifted: $05C132: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $05C240: calls unlifted target 0x05BF93: executes native on LakeSnes */
/* not lifted: $05C247: calls unlifted target 0x05C005: executes native on LakeSnes */
/* not lifted: $05C24E: calls unlifted target 0x05BA72: executes native on LakeSnes */
/* not lifted: $05C255: calls unlifted target 0x05BAAC: executes native on LakeSnes */
/* not lifted: $05C25C: calls unlifted target 0x05BF84: executes native on LakeSnes */
/* not lifted: $05C263: calls unlifted target 0x05BF4F: executes native on LakeSnes */
/* not lifted: $05C26D: calls unlifted target 0x05872F: executes native on LakeSnes */
/* not lifted: $05C274: calls unlifted target 0x058443: executes native on LakeSnes */
/* not lifted: $05C2A8: calls unlifted target 0x05BACA: executes native on LakeSnes */
/* not lifted: $05C2AF: calls unlifted target 0x05BAD3: executes native on LakeSnes */
/* not lifted: $05C2B6: calls unlifted target 0x05BADC: executes native on LakeSnes */
/* not lifted: $05C2BD: calls unlifted target 0x05BAE5: executes native on LakeSnes */
/* not lifted: $05C456: calls unlifted target 0x05C01E: executes native on LakeSnes */
/* not lifted: $05C45A: calls unlifted target 0x05C005: executes native on LakeSnes */
/* not lifted: $05C468: calls unlifted target 0x05BD7D: executes native on LakeSnes */
/* not lifted: $05C46C: calls unlifted target 0x05BD81: executes native on LakeSnes */
/* not lifted: $05C470: calls unlifted target 0x05BD85: executes native on LakeSnes */
/* not lifted: $05C474: calls unlifted target 0x05BD89: executes native on LakeSnes */
/* not lifted: $05C524: calls unlifted target 0x05BF5F: executes native on LakeSnes */
/* not lifted: $05C53B: calls unlifted target 0x05BF5F: executes native on LakeSnes */
/* not lifted: $05C5B7: calls unlifted target 0x05BEB6: executes native on LakeSnes */
/* not lifted: $05C5BB: calls unlifted target 0x05BF3F: executes native on LakeSnes */
/* not lifted: $05C5C5: calls unlifted target 0x05BDC1: executes native on LakeSnes */
/* not lifted: $05C5CC: calls unlifted target 0x05AAC3: executes native on LakeSnes */
/* not lifted: $05C5D8: calls unlifted target 0x05BDCB: executes native on LakeSnes */
/* not lifted: $05C5ED: calls unlifted target 0x05BB09: executes native on LakeSnes */
/* not lifted: $05C776: calls unlifted target 0x05993B: executes native on LakeSnes */
/* not lifted: $05C792: BRK at $05:C79C */
/* not lifted: $05C8C8: BRK at $05:C907 */
/* not lifted: $05CE98: BRK at $05:CEBF */
/* not lifted: $05CEF9: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05CF37: calls RAM trampoline/sub-8000 ($051199): executes native on LakeSnes */
/* not lifted: $05CFC7: calls unlifted target 0x05CF37: executes native on LakeSnes */
/* not lifted: $05D04E: BRK at $05:D050 */
/* not lifted: $05D092: COP at $05:D0D2 */
/* not lifted: $05FA20: PLB at $FA57 pulls below the entry stack (return-address trick) */
/* not lifted: $05FF29: TXS at $05:FF2E */
/* not lifted: $05FFA9: PLB at $FFA9 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $05822F, entered with P=$20 via JSR */
void gen_05822F(void) {
    goto L_822F;
L_822F:;
    recomp_tick(24); { uint16_t _v = 0x0012; g_cpu.Y = _v; g_nz16(_v); }  /* 822F LDY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8232 TDC */
L_8233:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x18C3)); g_cpu.X = _v; g_nz16(_v); }  /* 8233 LDX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x7FFF);  /* 8236 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_823C;  /* 8239 BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 823B INC */
L_823C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 823C DEY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 823D DEY */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8233;  /* 823E BPL */
    recomp_tick(14); return;  /* 8240 RTS */
}

/* $058577, entered with P=$20 via JSR */
void gen_058577(void) {
    goto L_8577;
L_8577:;
    recomp_tick(16); g_rep(0x20);  /* 8577 REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x157A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8579 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8584;  /* 857C BPL */
    recomp_tick(40); g_wr16(g_abs(0x1578), 0);  /* 857E STZ */
    recomp_tick(40); g_wr16(g_abs(0x157A), 0);  /* 8581 STZ */
L_8584:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1578)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8584 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0xE100);  /* 8587 CMP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x157A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 858A LDA */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x05F5));  /* 858D SBC */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_859E;  /* 8590 BCC */
    recomp_tick(24); { uint16_t _v = 0xE0FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8592 LDA */
    recomp_tick(40); g_wr16(g_abs(0x1578), (uint16_t)g_cpu.C);  /* 8595 STA */
    recomp_tick(24); { uint16_t _v = 0x05F5; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8598 LDA */
    recomp_tick(40); g_wr16(g_abs(0x157A), (uint16_t)g_cpu.C);  /* 859B STA */
L_859E:;
    recomp_tick(16); g_sep(0x20);  /* 859E SEP */
    recomp_tick(14); return;  /* 85A0 RTS */
}

/* $058CDA, entered with P=$20 via JSR */
void gen_058CDA(void) {
    goto L_8CDA;
L_8CDA:;
    recomp_tick(16); g_rep(0x20);  /* 8CDA REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8CDC AND */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 8CDF STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8CE1 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8CE2 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8CE3 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* 8CE4 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8CE6 TAY */
    recomp_tick(16); g_sep(0x20);  /* 8CE7 SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8CE9 TDC */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CEA LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 8CEC STA */
L_8CEE:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CEE LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8CF1 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8CF2 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8D10;  /* 8CF4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8CF6 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CF7 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8CFA LSR */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8D10;  /* 8CFB BCS */
    recomp_tick(16); g_rep(0x20);  /* 8CFD REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8CFF TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8D00 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8D01 TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8D02 LDA */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absx(0x0ADA)));  /* 8D05 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8D0D;  /* 8D08 BCS */
    recomp_tick(56); { uint32_t _e = g_absx(0x099A); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 8D0A INC */
L_8D0D:;
    recomp_tick(16); g_sep(0x20);  /* 8D0D SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8D0F TDC */
L_8D10:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8D10 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8CEE;  /* 8D12 BNE */
    recomp_tick(14); return;  /* 8D14 RTS */
}

/* $05953D, entered with P=$20 via JSR */
void gen_05953D(void) {
    goto L_953D;
L_953D:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 953D TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 953E LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 9541 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 9542 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 9543 CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_absx(0x19CD)))));  /* 9544 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9547 TAY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9548 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 954A STA */
L_954C:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 954C TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 954D LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9550 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_955D;  /* 9552 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9554 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9555 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 9558 LSR */
    recomp_tick(16); if (g_cpu.flag_C) goto L_955D;  /* 9559 BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 955B TDC */
    recomp_tick(14); return;  /* 955C RTS */
L_955D:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 955D INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 955E DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_954C;  /* 9560 BNE */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9562 LDA */
    recomp_tick(14); return;  /* 9564 RTS */
}

/* $059598, entered with P=$20 via JSR */
void gen_059598(void) {
    goto L_9598;
L_9598:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9598 LDA */
    recomp_tick(30); g_push16(0x959D); func_table_call_jsr(0x059A7C); g_cpu.S += 2;  /* 959B JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 959E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_95A7;  /* 95A0 BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95A2 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95A5 AND */
L_95A7:;
    recomp_tick(14); return;  /* 95A7 RTS */
}

/* $0595A8, entered with P=$20 via JSR */
void gen_0595A8(void) {
    goto L_95A8;
L_95A8:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 95A8 STA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 95AA ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 95AB ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 95AC CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* 95AD ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 95AF TAY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 95B0 TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95B1 TYA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 95B2 TAY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95B3 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 95B5 STA */
L_95B7:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 95B7 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95B8 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 95BB CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_95C8;  /* 95BD BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 95BF TAX */
    recomp_tick(32); g_wr8(g_absx(0x07BA), 0);  /* 95C0 STZ */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95C3 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0E81), (uint8_t)(uint8_t)g_cpu.C);  /* 95C5 STA */
L_95C8:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 95C8 INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 95C9 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_95B7;  /* 95CB BNE */
    recomp_tick(14); return;  /* 95CD RTS */
}

/* $0595CE, entered with P=$20 via JSR */
void gen_0595CE(void) {
    goto L_95CE;
L_95CE:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 95CE STA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 95D0 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 95D1 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 95D2 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* 95D3 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 95D5 TAY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 95D6 TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95D7 TYA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 95D8 TAY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95D9 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 95DB STA */
L_95DD:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 95DD TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95DE LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 95E1 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_95F8;  /* 95E3 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 95E5 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95E6 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 95E9 ORA */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* 95EB STA */
    recomp_tick(16); g_rep(0x20);  /* 95EE REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 95F0 TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 95F1 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 95F2 TAX */
    recomp_tick(40); g_wr16(g_absx(0x099A), 0);  /* 95F3 STZ */
    recomp_tick(16); g_sep(0x20);  /* 95F6 SEP */
L_95F8:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 95F8 INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 95F9 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_95DD;  /* 95FB BNE */
    recomp_tick(14); return;  /* 95FD RTS */
}

/* $059765, entered with P=$20 via JSR */
void gen_059765(void) {
    goto L_9765;
L_9765:;
    recomp_tick(24); g_wr8(g_dp(0x04), 0);  /* 9765 STZ */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* 9767 LDX */
L_976A:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* 976A STX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x18AF)); g_cpu.Y = _v; g_nz16(_v); }  /* 976C LDY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x7FFF);  /* 976F CPY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9788;  /* 9772 BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9774 LDA */
    recomp_tick(30); g_push16(0x9779); func_table_call_jsr(0x059A7C); g_cpu.S += 2;  /* 9777 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 977A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9788;  /* 977C BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF148u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 977E LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)));  /* 9782 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_9788;  /* 9784 BCS */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* 9786 STA */
L_9788:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.X = _v; g_nz16(_v); }  /* 9788 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 978A INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 978B INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0014);  /* 978C CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_976A;  /* 978F BCC */
    recomp_tick(16); { uint8_t _v = 0x64; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9791 LDA */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* 9793 STA */
L_9795:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* 9795 STX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x18AF)); g_cpu.Y = _v; g_nz16(_v); }  /* 9797 LDY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x7FFF);  /* 979A CPY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_97B3;  /* 979D BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 979F LDA */
    recomp_tick(30); g_push16(0x97A4); func_table_call_jsr(0x059A7C); g_cpu.S += 2;  /* 97A2 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 97A5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_97B3;  /* 97A7 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF148u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 97A9 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x05)));  /* 97AD CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_97B3;  /* 97AF BCC */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* 97B1 STA */
L_97B3:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.X = _v; g_nz16(_v); }  /* 97B3 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 97B5 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 97B6 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0028);  /* 97B7 CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9795;  /* 97BA BCC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 97BC LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 97BE SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)))));  /* 97BF SBC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* 97C1 CMP */
    recomp_tick(16); if (g_cpu.flag_N) goto L_97D4;  /* 97C3 BMI */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 97C5 LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x02);  /* 97C8 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_97DC;  /* 97CA BCS */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x01);  /* 97CC CMP */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 97CE INY */
    recomp_tick(16); if (g_cpu.flag_C) goto L_97DC;  /* 97CF BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 97D1 INY */
    recomp_tick(16); goto L_97DC;  /* 97D2 BRA */
L_97D4:;
    recomp_tick(24); { uint16_t _v = 0x0003; g_cpu.Y = _v; g_nz16(_v); }  /* 97D4 LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 97D7 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_97DC;  /* 97D9 BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 97DB INY */
L_97DC:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 97DC TYA */
    recomp_tick(14); return;  /* 97DD RTS */
}

/* $0598DB, entered with P=$20 via JSR */
void gen_0598DB(void) {
    goto L_98DB;
L_98DB:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 98DB STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 98DD TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 98DE LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 98E0 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 98E1 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 98E2 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* 98E3 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 98E5 TAY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 98E6 LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* 98E8 STA */
L_98EA:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* 98EA TYX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 98EB TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 98EC LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 98EF CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9903;  /* 98F1 BEQ */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 98F3 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 98F4 TAX */
    recomp_tick(16); g_rep(0x20);  /* 98F5 REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 98F7 LDA */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absx(0x0ADA)));  /* 98FA CMP */
    recomp_tick(16); g_sep(0x20);  /* 98FD SEP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_9903;  /* 98FF BCS */
    recomp_tick(14); g_cpu.flag_C = false;  /* 9901 CLC */
    recomp_tick(14); return;  /* 9902 RTS */
L_9903:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9903 INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9904 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_98EA;  /* 9906 BNE */
    recomp_tick(14); g_cpu.flag_C = true;  /* 9908 SEC */
    recomp_tick(14); return;  /* 9909 RTS */
}

/* $059949, entered with P=$20 via JSR */
void gen_059949(void) {
    goto L_9949;
L_9949:;
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9949 LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x14E6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 994B TRB */
    recomp_tick(14); return;  /* 994E RTS */
}

/* $059A68, entered with P=$20 via JSR */
void gen_059A68(void) {
    goto L_9A68;
L_9A68:;
    recomp_tick(16); g_rep(0x20);  /* 9A68 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A6A AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A6D DEC */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A6E ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9A6F TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x11D32Cu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A70 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9A74 TAX */
    recomp_tick(16); g_sep(0x20);  /* 9A75 SEP */
    recomp_tick(16); { uint8_t _v = 0x11; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9A77 LDA */
    recomp_tick(24); g_wr8(g_dp(0x49), (uint8_t)(uint8_t)g_cpu.C);  /* 9A79 STA */
    recomp_tick(14); return;  /* 9A7B RTS */
}

/* $059A7C, entered with P=$20 via JSR */
void gen_059A7C(void) {
    goto L_9A7C;
L_9A7C:;
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 9A7C STA */
    recomp_tick(16); g_rep(0x20);  /* 9A7E REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A80 AND */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 9A83 STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A85 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A86 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 9A87 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* 9A88 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9A8A TAY */
    recomp_tick(16); g_sep(0x20);  /* 9A8B SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9A8D TDC */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9A8E LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 9A90 STA */
L_9A92:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* 9A92 TYX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9A93 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A96 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9A97 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9AA3;  /* 9A99 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9A9B TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9A9C LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_9AA3;  /* 9A9F BPL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9AA1 TXA */
    recomp_tick(14); return;  /* 9AA2 RTS */
L_9AA3:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9AA3 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9A92;  /* 9AA5 BNE */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9AA7 LDA */
    recomp_tick(14); return;  /* 9AA9 RTS */
}

/* $059E27, entered with P=$20 via JSR */
void gen_059E27(void) {
    goto L_9E27;
L_9E27:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0EFE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E27 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E2A INC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9E36;  /* 9E2B BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x095E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E2D LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x81); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E30 AND */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x80);  /* 9E32 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9E48;  /* 9E34 BEQ */
L_9E36:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0EFF)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E36 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E39 INC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9E45;  /* 9E3A BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x095F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E3C LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x81); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E3F AND */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x80);  /* 9E41 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9E48;  /* 9E43 BEQ */
L_9E45:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9E45 LDA */
    recomp_tick(14); return;  /* 9E47 RTS */
L_9E48:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9E48 TDC */
    recomp_tick(14); return;  /* 9E49 RTS */
}

/* $059EBB, entered with P=$00 via JSR */
void gen_059EBB(void) {
    goto L_9EBB;
L_9EBB:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9EBB TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7ED028u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9EBC LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 9EC0 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0xD028));  /* 9EC1 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9EC4 TAX */
    recomp_tick(16); g_sep(0x20);  /* 9EC5 SEP */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9EC7 LDA */
    recomp_tick(24); g_wr8(g_dp(0x49), (uint8_t)(uint8_t)g_cpu.C);  /* 9EC9 STA */
    recomp_tick(14); return;  /* 9ECB RTS */
}

/* $05A822, entered with P=$20 via JSR */
void gen_05A822(void) {
    goto L_A822;
L_A822:;
    recomp_tick(16); g_rep(0x20);  /* A822 REP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A824 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A825 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A826 TAY */
L_A827:;
    recomp_tick(32); g_wr16(g_dp(0x04), 0);  /* A827 STZ */
L_A829:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A829 LDA */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absy(0xA870)));  /* A82B CMP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A82E LDA */
    recomp_tick(40); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_absy(0xA872))));  /* A830 SBC */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_A848;  /* A833 BCC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A835 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* A837 SEC */
    recomp_tick(40); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_absy(0xA870))));  /* A838 SBC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* A83B STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A83D LDA */
    recomp_tick(40); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_absy(0xA872))));  /* A83F SBC */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* A842 STA */
    recomp_tick(48); { uint32_t _e = g_dp(0x04); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* A844 INC */
    recomp_tick(16); goto L_A829;  /* A846 BRA */
L_A848:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A848 LDA */
    recomp_tick(48); g_wr16(g_longx(0x7F0000u), (uint16_t)g_cpu.C);  /* A84A STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A84E INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A84F INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A850 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A851 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A852 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000A);  /* A853 CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_A827;  /* A856 BCC */
    recomp_tick(16); g_sep(0x20);  /* A858 SEP */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* A85A LDX */
L_A85D:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7F0000u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A85D LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A86F;  /* A861 BNE */
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A863 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7F0000u), (uint8_t)(uint8_t)g_cpu.C);  /* A865 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A869 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0009);  /* A86A CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_A85D;  /* A86D BCC */
L_A86F:;
    recomp_tick(14); return;  /* A86F RTS */
}

/* $05B90D, entered with P=$20 via JSR */
void gen_05B90D(void) {
    goto L_B90D;
L_B90D:;
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* B90D STZ */
    recomp_tick(16); { uint8_t _v = 0xBA; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B90F LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* B911 STA */
L_B913:;
    recomp_tick(30); g_push16(0xB915); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B913 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B916 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B91C;  /* B918 BEQ */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B91A INC */
L_B91C:;
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B91C INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B91E LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xC8);  /* B920 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B913;  /* B922 BCC */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B924 LDA */
    recomp_tick(30); g_push16(0xB928); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B926 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B929 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B92F;  /* B92B BEQ */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B92D INC */
L_B92F:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B92F LDA */
    recomp_tick(14); return;  /* B931 RTS */
}

/* $05B932, entered with P=$20 via JSR */
void gen_05B932(void) {
    goto L_B932;
L_B932:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x15FC)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B932 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x1D);  /* B935 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B93C;  /* B937 BNE */
    recomp_tick(16); { uint8_t _v = 0x0C; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B939 LDA */
    recomp_tick(14); return;  /* B93B RTS */
L_B93C:;
    recomp_tick(30); g_push16(0xB93E); func_table_call_jsr(0x05B90D); g_cpu.S += 2;  /* B93C JSR */
    recomp_tick(14); g_cpu.flag_C = false;  /* B93F CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0C1A)))));  /* B940 ADC */
    recomp_tick(14); g_cpu.flag_C = false;  /* B943 CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x157C)))));  /* B944 ADC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x7D);  /* B947 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B951;  /* B949 BCS */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x32);  /* B94B CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B9A4;  /* B94D BCS */
    recomp_tick(16); goto L_B9B3;  /* B94F BRA */
L_B951:;
    recomp_tick(30); g_push16(0xB953); func_table_call_jsr(0x05B9CD); g_cpu.S += 2;  /* B951 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B954 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B96D;  /* B956 BEQ */
    recomp_tick(16); { uint8_t _v = 0x67; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B958 LDA */
    recomp_tick(30); g_push16(0xB95C); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* B95A JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B95D CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B96D;  /* B95F BEQ */
    recomp_tick(16); { uint8_t _v = 0x63; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B961 LDA */
    recomp_tick(30); g_push16(0xB965); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* B963 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B966 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B96D;  /* B968 BEQ */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B96A LDA */
    recomp_tick(14); return;  /* B96C RTS */
L_B96D:;
    recomp_tick(30); g_push16(0xB96F); func_table_call_jsr(0x05B9E0); g_cpu.S += 2;  /* B96D JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B970 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B980;  /* B972 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF620u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B974 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B97D;  /* B978 BNE */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B97A LDA */
    recomp_tick(14); return;  /* B97C RTS */
L_B97D:;
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B97D LDA */
    recomp_tick(14); return;  /* B97F RTS */
L_B980:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF620u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B980 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B995;  /* B984 BNE */
    recomp_tick(16); { uint8_t _v = 0x67; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B986 LDA */
    recomp_tick(30); g_push16(0xB98A); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* B988 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B98B CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B992;  /* B98D BEQ */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B98F LDA */
    recomp_tick(14); return;  /* B991 RTS */
L_B992:;
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B992 LDA */
    recomp_tick(14); return;  /* B994 RTS */
L_B995:;
    recomp_tick(16); { uint8_t _v = 0x63; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B995 LDA */
    recomp_tick(30); g_push16(0xB999); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* B997 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B99A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9A1;  /* B99C BEQ */
    recomp_tick(16); { uint8_t _v = 0x04; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B99E LDA */
    recomp_tick(14); return;  /* B9A0 RTS */
L_B9A1:;
    recomp_tick(16); { uint8_t _v = 0x06; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9A1 LDA */
    recomp_tick(14); return;  /* B9A3 RTS */
L_B9A4:;
    recomp_tick(16); { uint8_t _v = 0x63; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9A4 LDA */
    recomp_tick(30); g_push16(0xB9A8); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* B9A6 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9A9 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9B0;  /* B9AB BEQ */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9AD LDA */
    recomp_tick(14); return;  /* B9AF RTS */
L_B9B0:;
    recomp_tick(16); { uint8_t _v = 0x08; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9B0 LDA */
    recomp_tick(14); return;  /* B9B2 RTS */
L_B9B3:;
    recomp_tick(16); { uint8_t _v = 0x7D; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9B3 LDA */
    recomp_tick(30); g_push16(0xB9B7); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* B9B5 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9B8 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9BF;  /* B9BA BEQ */
    recomp_tick(16); { uint8_t _v = 0x09; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9BC LDA */
    recomp_tick(14); return;  /* B9BE RTS */
L_B9BF:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF42Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9BF LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x32);  /* B9C3 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B9CA;  /* B9C5 BCC */
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9C7 LDA */
    recomp_tick(14); return;  /* B9C9 RTS */
L_B9CA:;
    recomp_tick(16); { uint8_t _v = 0x0B; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9CA LDA */
    recomp_tick(14); return;  /* B9CC RTS */
}

/* $05B9CD, entered with P=$20 via JSR */
void gen_05B9CD(void) {
    goto L_B9CD;
L_B9CD:;
    recomp_tick(16); { uint8_t _v = 0xBC; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9CD LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* B9CF STA */
L_B9D1:;
    recomp_tick(30); g_push16(0xB9D3); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9D1 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9D4 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9F7;  /* B9D6 BEQ */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B9D8 INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9DA LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xC8);  /* B9DC CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B9D1;  /* B9DE BCC */
    recomp_tick(16); { uint8_t _v = 0xBA; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9E0 LDA */
    recomp_tick(30); g_push16(0xB9E4); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9E2 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9E5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9F7;  /* B9E7 BEQ */
    recomp_tick(16); { uint8_t _v = 0xBB; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9E9 LDA */
    recomp_tick(30); g_push16(0xB9ED); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9EB JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9EE CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9F7;  /* B9F0 BEQ */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9F2 LDA */
    recomp_tick(30); g_push16(0xB9F6); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9F4 JSR */
L_B9F7:;
    recomp_tick(14); return;  /* B9F7 RTS */
}

/* $05B9E0, entered with P=$20 via JSR */
void gen_05B9E0(void) {
    goto L_B9E0;
L_B9E0:;
    recomp_tick(16); { uint8_t _v = 0xBA; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9E0 LDA */
    recomp_tick(30); g_push16(0xB9E4); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9E2 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9E5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9F7;  /* B9E7 BEQ */
    recomp_tick(16); { uint8_t _v = 0xBB; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9E9 LDA */
    recomp_tick(30); g_push16(0xB9ED); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9EB JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* B9EE CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9F7;  /* B9F0 BEQ */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9F2 LDA */
    recomp_tick(30); g_push16(0xB9F6); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* B9F4 JSR */
L_B9F7:;
    recomp_tick(14); return;  /* B9F7 RTS */
}

/* $05BA05, entered with P=$20 via JSR */
void gen_05BA05(void) {
    goto L_BA05;
L_BA05:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* BA05 STA */
    recomp_tick(24); { uint16_t _v = 0x0063; g_cpu.X = _v; g_nz16(_v); }  /* BA07 LDX */
L_BA0A:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x0007BAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA0A LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* BA0E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA17;  /* BA10 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* BA12 DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BA0A;  /* BA13 BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA15 TDC */
    recomp_tick(14); return;  /* BA16 RTS */
L_BA17:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA17 LDA */
    recomp_tick(14); return;  /* BA19 RTS */
}

/* $05BA1A, entered with P=$20 via JSR */
void gen_05BA1A(void) {
    goto L_BA1A;
L_BA1A:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* BA1A STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA1C TDC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x20)); g_cpu.X = _v; g_nz16(_v); }  /* BA1D LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA1F LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* BA22 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* BA23 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* BA24 CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_absx(0x19CD)))));  /* BA25 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* BA28 TAY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA29 LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* BA2B STA */
L_BA2D:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* BA2D TYX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x000E81u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA2E LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* BA32 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA3F;  /* BA34 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BA36 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x0007BAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA37 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* BA3B CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA46;  /* BA3D BEQ */
L_BA3F:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* BA3F INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* BA40 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_BA2D;  /* BA42 BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA44 TDC */
    recomp_tick(14); return;  /* BA45 RTS */
L_BA46:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA46 LDA */
    recomp_tick(14); return;  /* BA48 RTS */
}

/* $05BA49, entered with P=$20 via JSR */
void gen_05BA49(void) {
    goto L_BA49;
L_BA49:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* BA49 STA */
    recomp_tick(24); { uint16_t _v = 0x007C; g_cpu.X = _v; g_nz16(_v); }  /* BA4B LDX */
L_BA4E:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x157E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA4E LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* BA51 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA6F;  /* BA53 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* BA55 DEX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* BA56 DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BA4E;  /* BA57 BPL */
    recomp_tick(24); { uint16_t _v = 0x0063; g_cpu.X = _v; g_nz16(_v); }  /* BA59 LDX */
L_BA5C:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x0007BAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA5C LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA6A;  /* BA60 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF5BCu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA62 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* BA66 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA6F;  /* BA68 BEQ */
L_BA6A:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* BA6A DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BA5C;  /* BA6B BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA6D TDC */
    recomp_tick(14); return;  /* BA6E RTS */
L_BA6F:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA6F LDA */
    recomp_tick(14); return;  /* BA71 RTS */
}

/* $05BF30, entered with P=$20 via JSR */
void gen_05BF30(void) {
    goto L_BF30;
L_BF30:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BF30 TAX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BF31 TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF32 TXA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BF33 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF34 LDA */
    recomp_tick(30); g_push16(0xBF39); func_table_call_jsr(0x059A7C); g_cpu.S += 2;  /* BF37 JSR */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x0007BAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF3A LDA */
    recomp_tick(14); return;  /* BF3E RTS */
}

/* $05C0FE, entered with P=$20 via JSR */
void gen_05C0FE(void) {
    goto L_C0FE;
L_C0FE:;
    recomp_tick(14); return;  /* C0FE RTS */
}

/* $05C113, entered with P=$20 via JSR */
void gen_05C113(void) {
    goto L_C113;
L_C113:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x20)); g_cpu.X = _v; g_nz16(_v); }  /* C113 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C115 LDA */
    recomp_tick(30); g_push16(0xC11A); func_table_call_jsr(0x059A7C); g_cpu.S += 2;  /* C118 JSR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* C11B ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C11C TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0C7E)); g_cpu.Y = _v; g_nz16(_v); }  /* C11D LDY */
    recomp_tick(40); g_wr16(g_abs(0x12B7), (uint16_t)g_cpu.Y);  /* C120 STY */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0C7E)); g_cpu.Y = _v; g_nz16(_v); }  /* C123 LDY */
    recomp_tick(40); g_wr16(g_abs(0x12B3), (uint16_t)g_cpu.Y);  /* C126 STY */
    recomp_tick(16); { uint8_t _v = 0x11; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C129 LDA */
    recomp_tick(32); g_wr8(g_abs(0x12B5), (uint8_t)(uint8_t)g_cpu.C);  /* C12B STA */
    recomp_tick(32); g_wr8(g_abs(0x12B9), (uint8_t)(uint8_t)g_cpu.C);  /* C12E STA */
    recomp_tick(14); return;  /* C131 RTS */
}

/* $05C220, entered with P=$20 via JSR */
void gen_05C220(void) {
    goto L_C220;
L_C220:;
    recomp_tick(32); { uint32_t _e = g_dp(0x2B); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C220 INC */
    recomp_tick(14); return;  /* C222 RTS */
}

/* $05C223, entered with P=$20 via JSR */
void gen_05C223(void) {
    goto L_C223;
L_C223:;
    recomp_tick(30); g_push16(0xC225); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C223 JSR */
    recomp_tick(30); g_push16(0xC228); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C226 JSR */
    recomp_tick(14); return;  /* C229 RTS */
}

/* $05C22A, entered with P=$20 via JSR */
void gen_05C22A(void) {
    goto L_C22A;
L_C22A:;
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C22A LDA */
    recomp_tick(16); goto L_C234;  /* C22C BRA */
L_C234:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C234 XBA */
    recomp_tick(30); g_push16(0xC237); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C235 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C238 TAX */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C239 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7E8D08u), (uint8_t)(uint8_t)g_cpu.C);  /* C23B STA */
    recomp_tick(14); return;  /* C23F RTS */
}

/* $05C232, entered with P=$20 via JSR */
void gen_05C232(void) {
    goto L_C232;
L_C232:;
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C232 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C234 XBA */
    recomp_tick(30); g_push16(0xC237); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C235 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C238 TAX */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C239 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7E8D08u), (uint8_t)(uint8_t)g_cpu.C);  /* C23B STA */
    recomp_tick(14); return;  /* C23F RTS */
}

/* $05C292, entered with P=$20 via JSR */
void gen_05C292(void) {
    goto L_C292;
L_C292:;
    recomp_tick(30); g_push16(0xC294); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C292 JSR */
    recomp_tick(14); g_cpu.flag_C = false;  /* C295 CLC */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(0x000C1Au))));  /* C296 ADC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_C29D;  /* C29A BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C29C TDC */
L_C29D:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x64);  /* C29D CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C2A3;  /* C29F BCC */
    recomp_tick(16); { uint8_t _v = 0x64; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A1 LDA */
L_C2A3:;
    recomp_tick(40); g_wr8(0x000C1Au, (uint8_t)(uint8_t)g_cpu.C);  /* C2A3 STA */
    recomp_tick(14); return;  /* C2A7 RTS */
}

/* $05C2C4, entered with P=$20 via JSR */
void gen_05C2C4(void) {
    goto L_C2C4;
L_C2C4:;
    recomp_tick(30); g_push16(0xC2C6); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C2C4 JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* C2C7 STA */
    recomp_tick(30); g_push16(0xC2CB); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C2C9 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C2CC TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x157C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2CD LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* C2D0 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C2D8;  /* C2D2 BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2D4 TXA */
    recomp_tick(30); g_push16(0xC2D7); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C2D5 JSR */
L_C2D8:;
    recomp_tick(14); return;  /* C2D8 RTS */
}

/* $05C2D9, entered with P=$20 via JSR */
void gen_05C2D9(void) {
    goto L_C2D9;
L_C2D9:;
    recomp_tick(30); g_push16(0xC2DB); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C2D9 JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* C2DC STA */
    recomp_tick(30); g_push16(0xC2E0); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C2DE JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C2E1 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x157C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2E2 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* C2E5 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C2ED;  /* C2E7 BCC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2E9 TXA */
    recomp_tick(30); g_push16(0xC2EC); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C2EA JSR */
L_C2ED:;
    recomp_tick(14); return;  /* C2ED RTS */
}

/* $05C2EE, entered with P=$20 via JSR */
void gen_05C2EE(void) {
    goto L_C2EE;
L_C2EE:;
    recomp_tick(30); g_push16(0xC2F0); func_table_call_jsr(0x05C73C); g_cpu.S += 2;  /* C2EE JSR */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* C2F1 STX */
    recomp_tick(30); g_push16(0xC2F5); func_table_call_jsr(0x05C73C); g_cpu.S += 2;  /* C2F3 JSR */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* C2F6 STX */
    recomp_tick(30); g_push16(0xC2FA); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C2F8 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C2FB TAX */
    recomp_tick(16); g_rep(0x20);  /* C2FC REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1578)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2FE LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* C301 CMP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x157A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C303 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* C306 SBC */
    recomp_tick(16); g_sep(0x20);  /* C308 SEP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C310;  /* C30A BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C30C TXA */
    recomp_tick(30); g_push16(0xC30F); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C30D JSR */
L_C310:;
    recomp_tick(14); return;  /* C310 RTS */
}

/* $05C311, entered with P=$20 via JSR */
void gen_05C311(void) {
    goto L_C311;
L_C311:;
    recomp_tick(30); g_push16(0xC313); func_table_call_jsr(0x05C73C); g_cpu.S += 2;  /* C311 JSR */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* C314 STX */
    recomp_tick(30); g_push16(0xC318); func_table_call_jsr(0x05C73C); g_cpu.S += 2;  /* C316 JSR */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* C319 STX */
    recomp_tick(30); g_push16(0xC31D); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C31B JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C31E TAX */
    recomp_tick(16); g_rep(0x20);  /* C31F REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1578)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C321 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* C324 CMP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x157A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C326 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* C329 SBC */
    recomp_tick(16); g_sep(0x20);  /* C32B SEP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C333;  /* C32D BCC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C32F TXA */
    recomp_tick(30); g_push16(0xC332); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C330 JSR */
L_C333:;
    recomp_tick(14); return;  /* C333 RTS */
}

/* $05C334, entered with P=$20 via JSR */
void gen_05C334(void) {
    goto L_C334;
L_C334:;
    recomp_tick(30); g_push16(0xC336); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C334 JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x20)); g_cpu.Y = _v; g_nz16(_v); }  /* C337 LDY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C33E;  /* C339 BNE */
    recomp_tick(30); g_push16(0xC33D); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C33B JSR */
L_C33E:;
    recomp_tick(14); return;  /* C33E RTS */
}

/* $05C33F, entered with P=$20 via JSR */
void gen_05C33F(void) {
    goto L_C33F;
L_C33F:;
    recomp_tick(30); g_push16(0xC341); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C33F JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x20)); g_cpu.Y = _v; g_nz16(_v); }  /* C342 LDY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C349;  /* C344 BEQ */
    recomp_tick(30); g_push16(0xC348); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C346 JSR */
L_C349:;
    recomp_tick(14); return;  /* C349 RTS */
}

/* $05C34A, entered with P=$20 via JSR */
void gen_05C34A(void) {
    goto L_C34A;
L_C34A:;
    recomp_tick(30); g_push16(0xC34C); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C34A JSR */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* C34D STA */
    recomp_tick(30); g_push16(0xC351); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C34F JSR */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* C352 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x20)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C354 LDA */
    recomp_tick(30); g_push16(0xC358); func_table_call_jsr(0x05BF30); g_cpu.S += 2;  /* C356 JSR */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)));  /* C359 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C362;  /* C35B BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C35D LDA */
    recomp_tick(30); g_push16(0xC361); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C35F JSR */
L_C362:;
    recomp_tick(14); return;  /* C362 RTS */
}

/* $05C363, entered with P=$20 via JSR */
void gen_05C363(void) {
    goto L_C363;
L_C363:;
    recomp_tick(30); g_push16(0xC365); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C363 JSR */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* C366 STA */
    recomp_tick(30); g_push16(0xC36A); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C368 JSR */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* C36B STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x20)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C36D LDA */
    recomp_tick(30); g_push16(0xC371); func_table_call_jsr(0x05BF30); g_cpu.S += 2;  /* C36F JSR */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)));  /* C372 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C37B;  /* C374 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C376 LDA */
    recomp_tick(30); g_push16(0xC37A); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C378 JSR */
L_C37B:;
    recomp_tick(14); return;  /* C37B RTS */
}

/* $05C37C, entered with P=$20 via JSR */
void gen_05C37C(void) {
    goto L_C37C;
L_C37C:;
    recomp_tick(30); g_push16(0xC37E); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C37C JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C37F TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1271)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C380 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C389;  /* C383 BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C385 TXA */
    recomp_tick(30); g_push16(0xC388); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C386 JSR */
L_C389:;
    recomp_tick(14); return;  /* C389 RTS */
}

/* $05C38A, entered with P=$20 via JSR */
void gen_05C38A(void) {
    goto L_C38A;
L_C38A:;
    recomp_tick(30); g_push16(0xC38C); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C38A JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C38D TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1271)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C38E LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C397;  /* C391 BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C393 TXA */
    recomp_tick(30); g_push16(0xC396); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C394 JSR */
L_C397:;
    recomp_tick(14); return;  /* C397 RTS */
}

/* $05C398, entered with P=$20 via JSR */
void gen_05C398(void) {
    goto L_C398;
L_C398:;
    recomp_tick(30); g_push16(0xC39A); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C398 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C39B TAY */
    recomp_tick(30); g_push16(0xC39E); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C39C JSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* C39F STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3A1 TYA */
    recomp_tick(30); g_push16(0xC3A4); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* C3A2 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* C3A5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C3AE;  /* C3A7 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3A9 LDA */
    recomp_tick(30); g_push16(0xC3AD); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C3AB JSR */
L_C3AE:;
    recomp_tick(14); return;  /* C3AE RTS */
}

/* $05C3AF, entered with P=$20 via JSR */
void gen_05C3AF(void) {
    goto L_C3AF;
L_C3AF:;
    recomp_tick(30); g_push16(0xC3B1); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C3AF JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C3B2 TAY */
    recomp_tick(30); g_push16(0xC3B5); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C3B3 JSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* C3B6 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3B8 TYA */
    recomp_tick(30); g_push16(0xC3BB); func_table_call_jsr(0x05BA49); g_cpu.S += 2;  /* C3B9 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* C3BC CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C3C5;  /* C3BE BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3C0 LDA */
    recomp_tick(30); g_push16(0xC3C4); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C3C2 JSR */
L_C3C5:;
    recomp_tick(14); return;  /* C3C5 RTS */
}

/* $05C3C6, entered with P=$20 via JSR */
void gen_05C3C6(void) {
    goto L_C3C6;
L_C3C6:;
    recomp_tick(30); g_push16(0xC3C8); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C3C6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C3C9 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1630)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3CA LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C3D3;  /* C3CD BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3CF TXA */
    recomp_tick(30); g_push16(0xC3D2); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C3D0 JSR */
L_C3D3:;
    recomp_tick(14); return;  /* C3D3 RTS */
}

/* $05C3D4, entered with P=$20 via JSR */
void gen_05C3D4(void) {
    goto L_C3D4;
L_C3D4:;
    recomp_tick(30); g_push16(0xC3D6); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C3D4 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C3D7 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1630)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3D8 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C3E1;  /* C3DB BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3DD TXA */
    recomp_tick(30); g_push16(0xC3E0); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C3DE JSR */
L_C3E1:;
    recomp_tick(14); return;  /* C3E1 RTS */
}

/* $05C3E2, entered with P=$20 via JSR */
void gen_05C3E2(void) {
    goto L_C3E2;
L_C3E2:;
    recomp_tick(30); g_push16(0xC3E4); func_table_call_jsr(0x05C73C); g_cpu.S += 2;  /* C3E2 JSR */
    recomp_tick(30); g_push16(0xC3E7); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C3E5 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C3E8 TAY */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7E8D08u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3E9 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C3F3;  /* C3ED BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3EF TYA */
    recomp_tick(30); g_push16(0xC3F2); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C3F0 JSR */
L_C3F3:;
    recomp_tick(14); return;  /* C3F3 RTS */
}

/* $05C3F4, entered with P=$20 via JSR */
void gen_05C3F4(void) {
    goto L_C3F4;
L_C3F4:;
    recomp_tick(30); g_push16(0xC3F6); func_table_call_jsr(0x05C73C); g_cpu.S += 2;  /* C3F4 JSR */
    recomp_tick(30); g_push16(0xC3F9); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C3F7 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C3FA TAY */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7E8D08u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3FB LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C405;  /* C3FF BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C401 TYA */
    recomp_tick(30); g_push16(0xC404); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C402 JSR */
L_C405:;
    recomp_tick(14); return;  /* C405 RTS */
}

/* $05C406, entered with P=$20 via JSR */
void gen_05C406(void) {
    goto L_C406;
L_C406:;
    recomp_tick(30); g_push16(0xC408); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C406 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C409 TAY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C40A TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x15FC)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C40B LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C40E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x001723u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C40F LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C419;  /* C413 BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C415 TYA */
    recomp_tick(30); g_push16(0xC418); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C416 JSR */
L_C419:;
    recomp_tick(14); return;  /* C419 RTS */
}

/* $05C41A, entered with P=$20 via JSR */
void gen_05C41A(void) {
    goto L_C41A;
L_C41A:;
    recomp_tick(30); g_push16(0xC41C); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C41A JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C41D TAY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C41E TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x15FC)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C41F LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C422 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x001723u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C423 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C42D;  /* C427 BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C429 TYA */
    recomp_tick(30); g_push16(0xC42C); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C42A JSR */
L_C42D:;
    recomp_tick(14); return;  /* C42D RTS */
}

/* $05C42E, entered with P=$20 via JSR */
void gen_05C42E(void) {
    goto L_C42E;
L_C42E:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C42E TDC */
    recomp_tick(30); g_push16(0xC431); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C42F JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C432 TAX */
    recomp_tick(30); g_push16(0xC435); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C433 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C436 TAY */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x001723u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C437 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C441;  /* C43B BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C43D TYA */
    recomp_tick(30); g_push16(0xC440); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C43E JSR */
L_C441:;
    recomp_tick(14); return;  /* C441 RTS */
}

/* $05C442, entered with P=$20 via JSR */
void gen_05C442(void) {
    goto L_C442;
L_C442:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C442 TDC */
    recomp_tick(30); g_push16(0xC445); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C443 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C446 TAX */
    recomp_tick(30); g_push16(0xC449); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C447 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C44A TAY */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x001723u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C44B LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C455;  /* C44F BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C451 TYA */
    recomp_tick(30); g_push16(0xC454); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C452 JSR */
L_C455:;
    recomp_tick(14); return;  /* C455 RTS */
}

/* $05C478, entered with P=$20 via JSR */
void gen_05C478(void) {
    goto L_C478;
L_C478:;
    recomp_tick(30); g_push16(0xC47A); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C478 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C47B TAY */
    recomp_tick(30); g_push16(0xC47E); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C47C JSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* C47F STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C481 TYA */
    recomp_tick(30); g_push16(0xC484); func_table_call_jsr(0x05BA1A); g_cpu.S += 2;  /* C482 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* C485 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C48E;  /* C487 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C489 LDA */
    recomp_tick(30); g_push16(0xC48D); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C48B JSR */
L_C48E:;
    recomp_tick(14); return;  /* C48E RTS */
}

/* $05C48F, entered with P=$20 via JSR */
void gen_05C48F(void) {
    goto L_C48F;
L_C48F:;
    recomp_tick(30); g_push16(0xC491); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C48F JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C492 TAY */
    recomp_tick(30); g_push16(0xC495); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C493 JSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* C496 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C498 TYA */
    recomp_tick(30); g_push16(0xC49B); func_table_call_jsr(0x05BA1A); g_cpu.S += 2;  /* C499 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* C49C CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C4BC;  /* C49E BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4A0 LDA */
    recomp_tick(30); g_push16(0xC4A4); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C4A2 JSR */
    recomp_tick(14); return;  /* C4A5 RTS */
L_C4BC:;
    recomp_tick(14); return;  /* C4BC RTS */
}

/* $05C4A6, entered with P=$20 via JSR */
void gen_05C4A6(void) {
    goto L_C4A6;
L_C4A6:;
    recomp_tick(30); g_push16(0xC4A8); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4A6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C4A9 TAY */
    recomp_tick(30); g_push16(0xC4AC); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4AA JSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* C4AD STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4AF TYA */
    recomp_tick(30); g_push16(0xC4B2); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* C4B0 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* C4B3 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C4BC;  /* C4B5 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4B7 LDA */
    recomp_tick(30); g_push16(0xC4BB); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C4B9 JSR */
L_C4BC:;
    recomp_tick(14); return;  /* C4BC RTS */
}

/* $05C4BD, entered with P=$20 via JSR */
void gen_05C4BD(void) {
    goto L_C4BD;
L_C4BD:;
    recomp_tick(30); g_push16(0xC4BF); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4BD JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C4C0 TAY */
    recomp_tick(30); g_push16(0xC4C3); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4C1 JSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* C4C4 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4C6 TYA */
    recomp_tick(30); g_push16(0xC4C9); func_table_call_jsr(0x05BA05); g_cpu.S += 2;  /* C4C7 JSR */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* C4CA CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C4D3;  /* C4CC BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4CE LDA */
    recomp_tick(30); g_push16(0xC4D2); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C4D0 JSR */
L_C4D3:;
    recomp_tick(14); return;  /* C4D3 RTS */
}

/* $05C4D4, entered with P=$20 via JSR */
void gen_05C4D4(void) {
    goto L_C4D4;
L_C4D4:;
    recomp_tick(30); g_push16(0xC4D6); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4D4 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C4D7 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1271)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4D8 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C4E1;  /* C4DB BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4DD TXA */
    recomp_tick(30); g_push16(0xC4E0); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C4DE JSR */
L_C4E1:;
    recomp_tick(14); return;  /* C4E1 RTS */
}

/* $05C4E2, entered with P=$20 via JSR */
void gen_05C4E2(void) {
    goto L_C4E2;
L_C4E2:;
    recomp_tick(30); g_push16(0xC4E4); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4E2 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C4E5 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1271)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4E6 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x01);  /* C4E9 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C4F1;  /* C4EB BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4ED TXA */
    recomp_tick(30); g_push16(0xC4F0); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C4EE JSR */
L_C4F1:;
    recomp_tick(14); return;  /* C4F1 RTS */
}

/* $05C4F2, entered with P=$20 via JSR */
void gen_05C4F2(void) {
    goto L_C4F2;
L_C4F2:;
    recomp_tick(30); g_push16(0xC4F4); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C4F2 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C4F5 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1271)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4F6 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x02);  /* C4F9 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C501;  /* C4FB BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4FD TXA */
    recomp_tick(30); g_push16(0xC500); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C4FE JSR */
L_C501:;
    recomp_tick(14); return;  /* C501 RTS */
}

/* $05C502, entered with P=$20 via JSR */
void gen_05C502(void) {
    goto L_C502;
L_C502:;
    recomp_tick(30); g_push16(0xC504); func_table_call_jsr(0x05C0FE); g_cpu.S += 2;  /* C502 JSR */
    recomp_tick(14); return;  /* C505 RTS */
}

/* $05C506, entered with P=$20 via JSR */
void gen_05C506(void) {
    goto L_C506;
L_C506:;
    recomp_tick(30); g_push16(0xC508); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C506 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C509 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF620u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C50A LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C514;  /* C50E BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C510 TXA */
    recomp_tick(30); g_push16(0xC513); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C511 JSR */
L_C514:;
    recomp_tick(14); return;  /* C514 RTS */
}

/* $05C515, entered with P=$20 via JSR */
void gen_05C515(void) {
    goto L_C515;
L_C515:;
    recomp_tick(30); g_push16(0xC517); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C515 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C518 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF620u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C519 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C523;  /* C51D BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C51F TXA */
    recomp_tick(30); g_push16(0xC522); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C520 JSR */
L_C523:;
    recomp_tick(14); return;  /* C523 RTS */
}

/* $05C552, entered with P=$20 via JSR */
void gen_05C552(void) {
    goto L_C552;
L_C552:;
    recomp_tick(30); g_push16(0xC554); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C552 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C555 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x14C8)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C556 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x02);  /* C559 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C561;  /* C55B BCC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C55D TXA */
    recomp_tick(30); g_push16(0xC560); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C55E JSR */
L_C561:;
    recomp_tick(14); return;  /* C561 RTS */
}

/* $05C562, entered with P=$20 via JSR */
void gen_05C562(void) {
    goto L_C562;
L_C562:;
    recomp_tick(30); g_push16(0xC564); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C562 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C565 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x14C8)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C566 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x02);  /* C569 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C571;  /* C56B BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C56D TXA */
    recomp_tick(30); g_push16(0xC570); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C56E JSR */
L_C571:;
    recomp_tick(14); return;  /* C571 RTS */
}

/* $05C572, entered with P=$20 via JSR */
void gen_05C572(void) {
    goto L_C572;
L_C572:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C572 LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0x2C); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* C574 TSB */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x20)); g_cpu.X = _v; g_nz16(_v); }  /* C576 LDX */
    recomp_tick(32); g_wr8(g_absx(0x19A6), 0);  /* C578 STZ */
    recomp_tick(16); g_rep(0x20);  /* C57B REP */
    recomp_tick(24); { uint16_t _v = 0x7FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C57D LDA */
    recomp_tick(40); g_wr16(g_absx(0x1905), (uint16_t)g_cpu.C);  /* C580 STA */
    recomp_tick(16); g_sep(0x20);  /* C583 SEP */
    recomp_tick(16); { uint8_t _v = 0x09; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C585 LDA */
    recomp_tick(32); g_wr8(g_absx(0x1A45), (uint8_t)(uint8_t)g_cpu.C);  /* C587 STA */
    recomp_tick(14); return;  /* C58A RTS */
}

/* $05C58B, entered with P=$20 via JSR */
void gen_05C58B(void) {
    goto L_C58B;
L_C58B:;
    recomp_tick(30); g_push16(0xC58D); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C58B JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* C58E STA */
    recomp_tick(30); g_push16(0xC592); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C590 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C593 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x000C1Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C594 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* C598 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C5A0;  /* C59A BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C59C TXA */
    recomp_tick(30); g_push16(0xC59F); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C59D JSR */
L_C5A0:;
    recomp_tick(14); return;  /* C5A0 RTS */
}

/* $05C5A1, entered with P=$20 via JSR */
void gen_05C5A1(void) {
    goto L_C5A1;
L_C5A1:;
    recomp_tick(30); g_push16(0xC5A3); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C5A1 JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* C5A4 STA */
    recomp_tick(30); g_push16(0xC5A8); func_table_call_jsr(0x05C733); g_cpu.S += 2;  /* C5A6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C5A9 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x000C1Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5AA LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* C5AE CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C5B6;  /* C5B0 BCC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5B2 TXA */
    recomp_tick(30); g_push16(0xC5B5); func_table_call_jsr(0x05C748); g_cpu.S += 2;  /* C5B3 JSR */
L_C5B6:;
    recomp_tick(14); return;  /* C5B6 RTS */
}

/* $05C709, entered with P=$20 via JSR */
void gen_05C709(void) {
    goto L_C709;
L_C709:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C709 LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0x2C); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* C70B TSB */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x20)); g_cpu.X = _v; g_nz16(_v); }  /* C70D LDX */
    recomp_tick(32); g_wr8(g_absx(0x19A6), 0);  /* C70F STZ */
    recomp_tick(16); g_rep(0x20);  /* C712 REP */
    recomp_tick(24); { uint16_t _v = 0x7FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C714 LDA */
    recomp_tick(40); g_wr16(g_absx(0x1905), (uint16_t)g_cpu.C);  /* C717 STA */
    recomp_tick(16); g_sep(0x20);  /* C71A SEP */
    recomp_tick(32); g_wr8(g_absx(0x1A45), 0);  /* C71C STZ */
    recomp_tick(14); return;  /* C71F RTS */
}

/* $05C733, entered with P=$20 via JSR */
void gen_05C733(void) {
    goto L_C733;
L_C733:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpil(0x28)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C733 LDA */
    recomp_tick(16); g_rep(0x20);  /* C735 REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x28); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* C737 INC */
    recomp_tick(16); g_sep(0x20);  /* C739 SEP */
    recomp_tick(14); return;  /* C73B RTS */
}

/* $05C73C, entered with P=$20 via JSR */
void gen_05C73C(void) {
    goto L_C73C;
L_C73C:;
    recomp_tick(16); g_rep(0x20);  /* C73C REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpil(0x28)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C73E LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C740 TAX */
    recomp_tick(48); { uint32_t _e = g_dp(0x28); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* C741 INC */
    recomp_tick(48); { uint32_t _e = g_dp(0x28); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* C743 INC */
    recomp_tick(16); g_sep(0x20);  /* C745 SEP */
    recomp_tick(14); return;  /* C747 RTS */
}

/* $05C748, entered with P=$20 via JSR */
void gen_05C748(void) {
    goto L_C748;
L_C748:;
    recomp_tick(16); g_rep(0x20);  /* C748 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C74A AND */
    recomp_tick(24); g_bit16(0x0080, true);  /* C74D BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C755;  /* C750 BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0xFF00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C752 ORA */
L_C755:;
    recomp_tick(14); g_cpu.flag_C = false;  /* C755 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x28))));  /* C756 ADC */
    recomp_tick(32); g_wr16(g_dp(0x28), (uint16_t)g_cpu.C);  /* C758 STA */
    recomp_tick(16); g_sep(0x20);  /* C75A SEP */
    recomp_tick(14); return;  /* C75C RTS */
}

/* $05CDBD, entered with P=$20 via JSR */
void gen_05CDBD(void) {
    goto L_CDBD;
L_CDBD:;
    recomp_tick(24); g_wr8(g_dp(0x00), 0);  /* CDBD STZ */
    recomp_tick(24); { uint16_t _v = 0xCDE6; g_cpu.Y = _v; g_nz16(_v); }  /* CDBF LDY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x1C25)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDC2 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* CDC5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CDCE;  /* CDC7 BEQ */
    recomp_tick(24); { uint16_t _v = 0xCDDE; g_cpu.Y = _v; g_nz16(_v); }  /* CDC9 LDY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* CDCC INC */
L_CDCE:;
    recomp_tick(40); g_wr16(g_abs(0x12BF), (uint16_t)g_cpu.Y);  /* CDCE STY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDD1 LDA */
    recomp_tick(32); g_wr8(g_abs(0x12C1), (uint8_t)(uint8_t)g_cpu.C);  /* CDD3 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CDD6 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDD7 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* CDD9 TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x1C4D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDDA LDA */
    recomp_tick(14); return;  /* CDDD RTS */
}

/* $05CEE4, entered with P=$20 via JSR */
void gen_05CEE4(void) {
    goto L_CEE4;
L_CEE4:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CEE4 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CEE5 TAX */
L_CEE6:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x18AF)); g_cpu.Y = _v; g_nz16(_v); }  /* CEE6 LDY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x7FFF);  /* CEE9 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CEEF;  /* CEEC BNE */
    recomp_tick(14); return;  /* CEEE RTS */
L_CEEF:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CEEF INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CEF0 INX */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CEF1 INC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0A);  /* CEF2 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CEE6;  /* CEF4 BCC */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CEF6 LDA */
    recomp_tick(14); return;  /* CEF8 RTS */
}

/* $05CF72, entered with P=$20 via JSL */
void gen_05CF72(void) {
    goto L_CF72;
L_CF72:;
    recomp_tick(16); g_rep(0x20);  /* CF72 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CF74 AND */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* CF77 STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CF79 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CF7A ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* CF7B CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* CF7C ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* CF7E TAY */
    recomp_tick(16); g_sep(0x20);  /* CF7F SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CF81 TDC */
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* CF82 STZ */
    recomp_tick(16); { uint8_t _v = 0x09; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF84 LDA */
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CF86 STA */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF88 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* CF8A STA */
L_CF8C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* CF8C TYX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF8D LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CF90 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* CF91 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CFC0;  /* CF93 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CF95 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF96 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CF99 LSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF9A LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF9D DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CF9E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02FD9Au)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF9F LDA */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CFA8;  /* CFA3 BCC */
    recomp_tick(24); { uint16_t _v = 0x0020; g_cpu.X = _v; g_nz16(_v); }  /* CFA5 LDX */
L_CFA8:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)));  /* CFA8 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CFC0;  /* CFAA BCC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CFB8;  /* CFAC BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02FD35u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CFAE LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x03)));  /* CFB2 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_CFC0;  /* CFB4 BCS */
    recomp_tick(16); goto L_CFBE;  /* CFB6 BRA */
L_CFB8:;
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* CFB8 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02FD35u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CFBA LDA */
L_CFBE:;
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CFBE STA */
L_CFC0:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* CFC0 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CF8C;  /* CFC2 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CFC4 LDA */
    recomp_tick(14); return;  /* CFC6 RTL */
}

/* $05D03A, entered with P=$20 via JSR */
void gen_05D03A(void) {
    goto L_D03A;
L_D03A:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* D03A LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x02);  /* D03D CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D04C;  /* D03F BCC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D041 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x06);  /* D042 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D04C;  /* D044 BCC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D046 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x09);  /* D047 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D04C;  /* D049 BCC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D04B INY */
L_D04C:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D04C TYA */
    recomp_tick(14); return;  /* D04D RTS */
}

void gen_register_bank_05(void) {
    func_table_register_flags(0x05822F, gen_05822F, false);
    func_table_register_flags(0x058577, gen_058577, false);
    func_table_register_flags(0x058CDA, gen_058CDA, false);
    func_table_register_flags(0x05953D, gen_05953D, false);
    func_table_register_flags(0x059598, gen_059598, false);
    func_table_register_flags(0x0595A8, gen_0595A8, false);
    func_table_register_flags(0x0595CE, gen_0595CE, false);
    func_table_register_flags(0x059765, gen_059765, false);
    func_table_register_flags(0x0598DB, gen_0598DB, false);
    func_table_register_flags(0x059949, gen_059949, false);
    func_table_register_flags(0x059A68, gen_059A68, false);
    func_table_register_flags(0x059A7C, gen_059A7C, false);
    func_table_register_flags(0x059E27, gen_059E27, false);
    func_table_register_flags(0x059EBB, gen_059EBB, false);
    func_table_register_flags(0x05A822, gen_05A822, false);
    func_table_register_flags(0x05B90D, gen_05B90D, false);
    func_table_register_flags(0x05B932, gen_05B932, false);
    func_table_register_flags(0x05B9CD, gen_05B9CD, false);
    func_table_register_flags(0x05B9E0, gen_05B9E0, false);
    func_table_register_flags(0x05BA05, gen_05BA05, false);
    func_table_register_flags(0x05BA1A, gen_05BA1A, false);
    func_table_register_flags(0x05BA49, gen_05BA49, false);
    func_table_register_flags(0x05BF30, gen_05BF30, false);
    func_table_register_flags(0x05C0FE, gen_05C0FE, false);
    func_table_register_flags(0x05C113, gen_05C113, false);
    func_table_register_flags(0x05C220, gen_05C220, false);
    func_table_register_flags(0x05C223, gen_05C223, false);
    func_table_register_flags(0x05C22A, gen_05C22A, false);
    func_table_register_flags(0x05C232, gen_05C232, false);
    func_table_register_flags(0x05C292, gen_05C292, false);
    func_table_register_flags(0x05C2C4, gen_05C2C4, false);
    func_table_register_flags(0x05C2D9, gen_05C2D9, false);
    func_table_register_flags(0x05C2EE, gen_05C2EE, false);
    func_table_register_flags(0x05C311, gen_05C311, false);
    func_table_register_flags(0x05C334, gen_05C334, false);
    func_table_register_flags(0x05C33F, gen_05C33F, false);
    func_table_register_flags(0x05C34A, gen_05C34A, false);
    func_table_register_flags(0x05C363, gen_05C363, false);
    func_table_register_flags(0x05C37C, gen_05C37C, false);
    func_table_register_flags(0x05C38A, gen_05C38A, false);
    func_table_register_flags(0x05C398, gen_05C398, false);
    func_table_register_flags(0x05C3AF, gen_05C3AF, false);
    func_table_register_flags(0x05C3C6, gen_05C3C6, false);
    func_table_register_flags(0x05C3D4, gen_05C3D4, false);
    func_table_register_flags(0x05C3E2, gen_05C3E2, false);
    func_table_register_flags(0x05C3F4, gen_05C3F4, false);
    func_table_register_flags(0x05C406, gen_05C406, false);
    func_table_register_flags(0x05C41A, gen_05C41A, false);
    func_table_register_flags(0x05C42E, gen_05C42E, false);
    func_table_register_flags(0x05C442, gen_05C442, false);
    func_table_register_flags(0x05C478, gen_05C478, false);
    func_table_register_flags(0x05C48F, gen_05C48F, false);
    func_table_register_flags(0x05C4A6, gen_05C4A6, false);
    func_table_register_flags(0x05C4BD, gen_05C4BD, false);
    func_table_register_flags(0x05C4D4, gen_05C4D4, false);
    func_table_register_flags(0x05C4E2, gen_05C4E2, false);
    func_table_register_flags(0x05C4F2, gen_05C4F2, false);
    func_table_register_flags(0x05C502, gen_05C502, false);
    func_table_register_flags(0x05C506, gen_05C506, false);
    func_table_register_flags(0x05C515, gen_05C515, false);
    func_table_register_flags(0x05C552, gen_05C552, false);
    func_table_register_flags(0x05C562, gen_05C562, false);
    func_table_register_flags(0x05C572, gen_05C572, false);
    func_table_register_flags(0x05C58B, gen_05C58B, false);
    func_table_register_flags(0x05C5A1, gen_05C5A1, false);
    func_table_register_flags(0x05C709, gen_05C709, false);
    func_table_register_flags(0x05C733, gen_05C733, false);
    func_table_register_flags(0x05C73C, gen_05C73C, false);
    func_table_register_flags(0x05C748, gen_05C748, false);
    func_table_register_flags(0x05CDBD, gen_05CDBD, false);
    func_table_register_flags(0x05CEE4, gen_05CEE4, false);
    func_table_register_flags(0x05CF72, gen_05CF72, true);
    func_table_register_flags(0x05D03A, gen_05D03A, false);
}
