/* Bank $03 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 97 lifted, 186 unlifted in Bank $03 */
/* not lifted: $03806F: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $0380A5: calls unlifted target 0x0C8157: executes native on LakeSnes */
/* not lifted: $0380A9: COP at $03:80B4 */
/* not lifted: $0380BC: BRK at $03:817E */
/* not lifted: $0382A9: PLX at $82AF pulls below the entry stack (return-address trick) */
/* not lifted: $0385A7: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $038663: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $038670: BRK at $03:86B7 */
/* not lifted: $0386F4: calls unlifted target 0x03E531: executes native on LakeSnes */
/* not lifted: $038712: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $038828: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03889B: $03:88AA reached with two different M/X/stack states */
/* not lifted: $038948: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $038AB1: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $038BE5: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $038BFF: $03:8C45 reached with two different M/X/stack states */
/* not lifted: $038C03: $03:8C45 reached with two different M/X/stack states */
/* not lifted: $038C94: calls unlifted target 0x03E569: executes native on LakeSnes */
/* not lifted: $038D9E: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $038E71: $03:8E95 reached with two different M/X/stack states */
/* not lifted: $038EEA: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $038F20: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $038F63: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $038F7B: PLY at $8F81 pulls below the entry stack (return-address trick) */
/* not lifted: $039256: RTS at $937D with 2 bytes still pushed */
/* not lifted: $03938E: BRK at $03:9444 */
/* not lifted: $03950E: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03990E: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039945: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03994B: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039950: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039978: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $039984: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $0399D5: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $039A8F: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039AD7: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039B13: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039B38: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039B6B: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039BB8: calls unlifted target 0x03B3F9: executes native on LakeSnes */
/* not lifted: $039C04: COP at $03:9C1D */
/* not lifted: $039C0F: calls unlifted target 0x03B3F9: executes native on LakeSnes */
/* not lifted: $039C2F: calls unlifted target 0x03B3F9: executes native on LakeSnes */
/* not lifted: $039C88: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039CBE: calls unlifted target 0x0399D5: executes native on LakeSnes */
/* not lifted: $039CCA: calls unlifted target 0x0399D5: executes native on LakeSnes */
/* not lifted: $039D1F: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039D42: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $039D8F: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039E25: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039E2E: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039E66: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039E91: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039EB1: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039F05: calls unlifted target 0x03E85B: executes native on LakeSnes */
/* not lifted: $039F2B: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039F52: calls unlifted target 0x03B3F9: executes native on LakeSnes */
/* not lifted: $039FA8: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039FB1: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $039FD0: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $039FFA: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A00D: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A01C: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A062: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A0A3: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A0FF: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $03A147: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A185: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A1CB: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03A3ED: calls unlifted target 0x03E85B: executes native on LakeSnes */
/* not lifted: $03A4F9: calls unlifted target 0x03E7CC: executes native on LakeSnes */
/* not lifted: $03A549: calls unlifted target 0x03A6CA: executes native on LakeSnes */
/* not lifted: $03A6CA: RTS at $A702 with 2 bytes still pushed */
/* not lifted: $03A703: calls unlifted target 0x03E85B: executes native on LakeSnes */
/* not lifted: $03A760: calls unlifted target 0x03C361: executes native on LakeSnes */
/* not lifted: $03A870: calls unlifted target 0x03C361: executes native on LakeSnes */
/* not lifted: $03A8B9: $03:A9E7 reached with two different M/X/stack states */
/* not lifted: $03A906: COP at $03:A908 */
/* not lifted: $03A920: BRK at $03:A92D */
/* not lifted: $03A97E: calls unlifted target 0x03E85B: executes native on LakeSnes */
/* not lifted: $03AA3B: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03AA83: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03AAE0: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03ACA5: BRK at $03:ACB7 */
/* not lifted: $03B010: BRK at $03:B010 */
/* not lifted: $03B371: BRK at $03:B38A */
/* not lifted: $03B3AB: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03B3F9: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03B4FD: calls unlifted target 0x03E85B: executes native on LakeSnes */
/* not lifted: $03B725: $03:B78E reached with two different M/X/stack states */
/* not lifted: $03B9A8: calls unlifted target 0x03E569: executes native on LakeSnes */
/* not lifted: $03BAB7: calls unlifted target 0x03E569: executes native on LakeSnes */
/* not lifted: $03BAF7: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03BB89: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03BB9C: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03BC0C: calls unlifted target 0x03BCD9: executes native on LakeSnes */
/* not lifted: $03BC65: calls unlifted target 0x03E569: executes native on LakeSnes */
/* not lifted: $03BCD9: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03BD19: tail jump at $BDB4 with 2 bytes pushed */
/* not lifted: $03BE90: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03BF51: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03BFBA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03C1AA: BRK at $03:C1BE */
/* not lifted: $03C1D5: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03C361: RTS at $C391 with 2 bytes still pushed */
/* not lifted: $03C392: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03C493: BRK at $03:C4A1 */
/* not lifted: $03C631: calls unlifted target 0x03E0F9: executes native on LakeSnes */
/* not lifted: $03C648: TCS at $C6E2 with an unknown stack value */
/* not lifted: $03C747: calls unlifted target 0x03E588: executes native on LakeSnes */
/* not lifted: $03C808: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03C95E: $03:C9B3 reached with two different M/X/stack states */
/* not lifted: $03CA03: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03CA20: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03CAF4: BRK at $03:CAFB */
/* not lifted: $03CBC0: STP at $03:CBC4 */
/* not lifted: $03CBCB: BRK at $03:CBF8 */
/* not lifted: $03CC3B: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03CC78: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03CE51: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03CED0: calls unlifted target 0x03E9A1: executes native on LakeSnes */
/* not lifted: $03CFA3: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03D094: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03D19F: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03D1C2: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03D218: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D250: calls unlifted target 0x03BF51: executes native on LakeSnes */
/* not lifted: $03D25A: calls unlifted target 0x03BF51: executes native on LakeSnes */
/* not lifted: $03D2D9: calls unlifted target 0x03E569: executes native on LakeSnes */
/* not lifted: $03D36F: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D386: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D391: PLX at $D3C9 pulls below the entry stack (return-address trick) */
/* not lifted: $03D3CC: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D3ED: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D451: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D45C: calls unlifted target 0x03BAF7: executes native on LakeSnes */
/* not lifted: $03D4D6: calls unlifted target 0x03EF5C: executes native on LakeSnes */
/* not lifted: $03D533: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03D585: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D590: calls unlifted target 0x03BB9C: executes native on LakeSnes */
/* not lifted: $03D63A: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03D72B: calls unlifted target 0x03E588: executes native on LakeSnes */
/* not lifted: $03D8A5: BRK at $03:D8AC */
/* not lifted: $03D953: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03DA03: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $03DA16: BRK at $03:DAD9 */
/* not lifted: $03DB2A: calls unlifted target 0x03C493: executes native on LakeSnes */
/* not lifted: $03DB30: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03DC32: calls unlifted target 0x03E569: executes native on LakeSnes */
/* not lifted: $03DC8D: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03DD5A: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03DDF5: calls unlifted target 0x03E9A1: executes native on LakeSnes */
/* not lifted: $03DE4F: PLA at $DE5F pulls below the entry stack (return-address trick) */
/* not lifted: $03DE61: STP at $03:DE88 */
/* not lifted: $03DE8F: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03DEFB: $03:E03B reached with two different M/X/stack states */
/* not lifted: $03E06A: calls unlifted target 0x03E07B: executes native on LakeSnes */
/* not lifted: $03E07B: BRK at $03:E094 */
/* not lifted: $03E0A9: BRK at $03:E0D1 */
/* not lifted: $03E0F9: calls unlifted target 0x03E9A1: executes native on LakeSnes */
/* not lifted: $03E11E: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03E14A: RTS at $E2D0 with 4 bytes still pushed */
/* not lifted: $03E27E: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03E378: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03E4F7: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $03E531: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03E543: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03E55B: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03E562: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03E569: BRK at $03:E572 */
/* not lifted: $03E57A: PLD at $E584 pulls below the entry stack (return-address trick) */
/* not lifted: $03E581: PLD at $E584 pulls below the entry stack (return-address trick) */
/* not lifted: $03E588: BRK at $03:E58D */
/* not lifted: $03E58F: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03E7CC: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $03E85B: calls RAM trampoline/sub-8000 ($031199): executes native on LakeSnes */
/* not lifted: $03E9A1: tail jump at $E9B6 with 1 bytes pushed */
/* not lifted: $03E9BA: calls unlifted target 0x03E85B: executes native on LakeSnes */
/* not lifted: $03EBBB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EC06: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EEB9: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EF19: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EF3B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EF5B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EF5C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $03EF88: hardware timing / wait loop (executes genuine on LakeSnes) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $038524, entered with P=$20 via JSR */
void gen_038524(void) {
    goto L_8524;
L_8524:;
    recomp_tick(14); return;  /* 8524 RTS */
}

/* $03888D, entered with P=$20 via JSR */
void gen_03888D(void) {
    goto L_888D;
L_888D:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 888D TDC */
    recomp_tick(16); g_rep(0x20);  /* 888E REP */
    recomp_tick(48); g_wr16(0x7EF92Fu, (uint16_t)g_cpu.C);  /* 8890 STA */
    recomp_tick(16); g_sep(0x20);  /* 8894 SEP */
    recomp_tick(16); { uint8_t _v = 0x24; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8896 LDA */
    recomp_tick(24); g_wr8(g_dp(0xCC), (uint8_t)(uint8_t)g_cpu.C);  /* 8898 STA */
    recomp_tick(14); return;  /* 889A RTS */
}

/* $038A6E, entered with P=$20 via JSR */
void gen_038A6E(void) {
    goto L_8A6E;
L_8A6E:;
    recomp_tick(16); g_bit8(0x40, true);  /* 8A6E BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8A92;  /* 8A70 BEQ */
    recomp_tick(32); g_wr8(g_absx(0x0392), 0);  /* 8A72 STZ */
    recomp_tick(16); g_bit8(0x20, true);  /* 8A75 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8A80;  /* 8A77 BEQ */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 8A79 PHA */
    recomp_tick(16); { uint8_t _v = 0x0E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8A7A LDA */
    recomp_tick(32); g_wr8(g_absx(0x0392), (uint8_t)(uint8_t)g_cpu.C);  /* 8A7C STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8A7F PLA */
L_8A80:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x1F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8A80 AND */
    recomp_tick(32); g_wr8(g_absx(0x0662), (uint8_t)(uint8_t)g_cpu.C);  /* 8A82 STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8A85 INC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF933u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8A87 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8AAE;  /* 8A8B BNE */
    recomp_tick(40); { uint32_t _e = g_absx(0x0662); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8A8D INC */
    recomp_tick(16); goto L_8AAE;  /* 8A90 BRA */
L_8A92:;
    recomp_tick(32); g_wr8(g_absx(0x0395), 0);  /* 8A92 STZ */
    recomp_tick(16); g_bit8(0x20, true);  /* 8A95 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8AA0;  /* 8A97 BEQ */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 8A99 PHA */
    recomp_tick(16); { uint8_t _v = 0x0E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8A9A LDA */
    recomp_tick(32); g_wr8(g_absx(0x0395), (uint8_t)(uint8_t)g_cpu.C);  /* 8A9C STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8A9F PLA */
L_8AA0:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x1F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8AA0 AND */
    recomp_tick(32); g_wr8(g_absx(0x0665), (uint8_t)(uint8_t)g_cpu.C);  /* 8AA2 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF933u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8AA5 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8AAE;  /* 8AA9 BNE */
    recomp_tick(40); { uint32_t _e = g_absx(0x0665); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8AAB INC */
L_8AAE:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8AAE INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8AAF INY */
    recomp_tick(14); return;  /* 8AB0 RTS */
}

/* $038BA8, entered with P=$20 via JSR */
void gen_038BA8(void) {
    goto L_8BA8;
L_8BA8:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8BA8 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8BA9 TAX */
L_8BAA:;
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.X);  /* 8BAA STX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF977u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BAC LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8BB0 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8BB6;  /* 8BB2 BNE */
    recomp_tick(14); g_cpu.flag_C = true;  /* 8BB4 SEC */
    recomp_tick(14); return;  /* 8BB5 RTS */
L_8BB6:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BB6 LDA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8BDD;  /* 8BBA BMI */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(0x7EF934u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BBC EOR */
    recomp_tick(16); g_bit8(0x01, true);  /* 8BC0 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8BDD;  /* 8BC2 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9AAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BC4 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 8BC8 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8BC9 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BCA LDA */
    recomp_tick(24); g_wr8(g_dp(0x0A), (uint8_t)(uint8_t)g_cpu.C);  /* 8BCC STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* 8BCE LDX */
L_8BD0:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x908D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BD0 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x01)));  /* 8BD3 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8BE2;  /* 8BD5 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8BD7 INX */
    recomp_tick(32); { uint32_t _e = g_dp(0x0A); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8BD8 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8BD0;  /* 8BDA BNE */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BDC PLA */
L_8BDD:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.X = _v; g_nz16(_v); }  /* 8BDD LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8BDF INX */
    recomp_tick(16); goto L_8BAA;  /* 8BE0 BRA */
L_8BE2:;
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8BE2 PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8BE3 CLC */
    recomp_tick(14); return;  /* 8BE4 RTS */
}

/* $038CD8, entered with P=$20 via JSR */
void gen_038CD8(void) {
    goto L_8CD8;
L_8CD8:;
    recomp_tick(16); { uint8_t _v = 0x40; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CD8 LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* 8CDA TSB */
    recomp_tick(30); g_push16(0x8CDE); func_table_call_jsr(0x038CE3); g_cpu.S += 2;  /* 8CDC JSR */
    recomp_tick(30); g_push16(0x8CE1); func_table_call_jsr(0x038D46); g_cpu.S += 2;  /* 8CDF JSR */
    recomp_tick(14); return;  /* 8CE2 RTS */
}

/* $038CE3, entered with P=$20 via JSR */
void gen_038CE3(void) {
    goto L_8CE3;
L_8CE3:;
    recomp_tick(24); { uint16_t _v = 0x0003; g_cpu.X = _v; g_nz16(_v); }  /* 8CE3 LDX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* 8CE6 STX */
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CE8 LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* 8CEA STA */
    recomp_tick(14); return;  /* 8CEC RTS */
}

/* $038CED, entered with P=$20 via JSR */
void gen_038CED(void) {
    goto L_8CED;
L_8CED:;
    recomp_tick(24); g_wr8(g_dp(0x0C), (uint8_t)(uint8_t)g_cpu.C);  /* 8CED STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8CEF TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8CF0 TAX */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.X);  /* 8CF1 STX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* 8CF3 LDX */
L_8CF5:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x908D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CF5 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 8CF8 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8CF9 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8CFA TAX */
L_8CFB:;
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.X);  /* 8CFB STX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF977u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8CFD LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8D01 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8D34;  /* 8D03 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D05 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8D0F;  /* 8D07 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D09 LDA */
    recomp_tick(16); goto L_8D15;  /* 8D0D BRA */
L_8D0F:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D0F LDA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8D2F;  /* 8D13 BMI */
L_8D15:;
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(0x7EF934u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D15 EOR */
    recomp_tick(16); g_bit8(0x01, true);  /* 8D19 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8D2F;  /* 8D1B BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9AAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D1D LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x01)));  /* 8D21 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8D2F;  /* 8D23 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x08)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D25 LDA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.X = _v; g_nz16(_v); }  /* 8D27 LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF9C8u), (uint8_t)(uint8_t)g_cpu.C);  /* 8D29 STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x0A); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8D2D INC */
L_8D2F:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.X = _v; g_nz16(_v); }  /* 8D2F LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8D31 INX */
    recomp_tick(16); goto L_8CFB;  /* 8D32 BRA */
L_8D34:;
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D34 PLA */
    recomp_tick(32); { uint32_t _e = g_dp(0x04); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8D35 INC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* 8D37 LDX */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8D39 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8CF5;  /* 8D3B BNE */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.X = _v; g_nz16(_v); }  /* 8D3D LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D3F LDA */
    recomp_tick(40); g_wr8(g_longx(0x7EF9C8u), (uint8_t)(uint8_t)g_cpu.C);  /* 8D41 STA */
    recomp_tick(14); return;  /* 8D45 RTS */
}

/* $038D46, entered with P=$20 via JSR */
void gen_038D46(void) {
    goto L_8D46;
L_8D46:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8D46 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8D47 TAX */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.X);  /* 8D48 STX */
L_8D4A:;
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.X);  /* 8D4A STX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF977u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D4C LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8D50 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8D71;  /* 8D52 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D54 LDA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8D6C;  /* 8D58 BMI */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(0x7EF934u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D5A EOR */
    recomp_tick(16); g_bit8(0x01, true);  /* 8D5E BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8D6C;  /* 8D60 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x08)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D62 LDA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.X = _v; g_nz16(_v); }  /* 8D64 LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF9C8u), (uint8_t)(uint8_t)g_cpu.C);  /* 8D66 STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x0A); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8D6A INC */
L_8D6C:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.X = _v; g_nz16(_v); }  /* 8D6C LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8D6E INX */
    recomp_tick(16); goto L_8D4A;  /* 8D6F BRA */
L_8D71:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.X = _v; g_nz16(_v); }  /* 8D71 LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D73 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7EF9C8u), (uint8_t)(uint8_t)g_cpu.C);  /* 8D75 STA */
    recomp_tick(14); return;  /* 8D79 RTS */
}

/* $038D7A, entered with P=$20 via JSR */
void gen_038D7A(void) {
    goto L_8D7A;
L_8D7A:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.Y);  /* 8D7A STY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8D7C TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D7D LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8D7F ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8D80 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D81 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8D83 TAX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* 8D84 STX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8D86 INY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8D87 LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* 8D89 STA */
    recomp_tick(30); g_push16(0x8D8D); func_table_call_jsr(0x038BA8); g_cpu.S += 2;  /* 8D8B JSR */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8D91;  /* 8D8E BCS */
    recomp_tick(14); return;  /* 8D90 RTS */
L_8D91:;
    recomp_tick(16); g_rep(0x20);  /* 8D91 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8D93 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8D95 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x000A));  /* 8D96 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8D99 TAY */
    recomp_tick(16); g_sep(0x20);  /* 8D9A SEP */
    recomp_tick(16); goto L_8D7A;  /* 8D9C BRA */
}

/* $038DBF, entered with P=$20 via JSR */
void gen_038DBF(void) {
    goto L_8DBF;
L_8DBF:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8DBF TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DC0 TAX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* 8DC1 STX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DC3 LDA */
    recomp_tick(30); g_push16(0x8DC9); func_table_call_jsr(0x039075); g_cpu.S += 2;  /* 8DC7 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DCA TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF63B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DCB LDA */
    recomp_tick(24); g_wr8(g_dp(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* 8DCE STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF9C8u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DD0 LDA */
    recomp_tick(24); g_wr8(g_dp(0x08), (uint8_t)(uint8_t)g_cpu.C);  /* 8DD4 STA */
    recomp_tick(30); g_push16(0x8DD8); func_table_call_jsr(0x039075); g_cpu.S += 2;  /* 8DD6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DD9 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF63B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DDA LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 8DDD SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x07)))));  /* 8DDE SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8DE5;  /* 8DE0 BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DE2 EOR */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DE4 INC */
L_8DE5:;
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8DE5 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8DE7 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DE8 TAX */
L_8DE9:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8DE9 INX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8DEA TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DEB LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8DEF CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8DF4;  /* 8DF1 BNE */
    recomp_tick(14); return;  /* 8DF3 RTS */
L_8DF4:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8DF4 TAY */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 8DF5 PHX */
    recomp_tick(30); g_push16(0x8DF8); func_table_call_jsr(0x039075); g_cpu.S += 2;  /* 8DF6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DF9 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF63B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DFA LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8DFD PLX */
    recomp_tick(14); g_cpu.flag_C = true;  /* 8DFE SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x07)))));  /* 8DFF SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8E06;  /* 8E01 BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E03 EOR */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E05 INC */
L_8E06:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x06)));  /* 8E06 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8E18;  /* 8E08 BNE */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E0A XBA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x51)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E0B LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8E0D LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8E0E LSR */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E0F XBA */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8DE9;  /* 8E10 BCS */
L_8E12:;
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8E12 STA */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.Y);  /* 8E14 STY */
    recomp_tick(16); goto L_8DE9;  /* 8E16 BRA */
L_8E18:;
    recomp_tick(16); if (g_cpu.flag_C) goto L_8E12;  /* 8E18 BCS */
    recomp_tick(16); goto L_8DE9;  /* 8E1A BRA */
}

/* $038E1C, entered with P=$20 via JSR */
void gen_038E1C(void) {
    goto L_8E1C;
L_8E1C:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8E1C TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8E1D TAX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* 8E1E STX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF9C8u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E20 LDA */
    recomp_tick(24); g_wr8(g_dp(0x08), (uint8_t)(uint8_t)g_cpu.C);  /* 8E24 STA */
    recomp_tick(30); g_push16(0x8E28); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* 8E26 JSR */
    recomp_tick(16); g_rep(0x20);  /* 8E29 REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8E2B ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8E2C TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x00099Au)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E2D LDA */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* 8E31 STA */
    recomp_tick(16); g_sep(0x20);  /* 8E33 SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8E35 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8E36 TAX */
L_8E37:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8E37 INX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8E38 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E39 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8E3D CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8E42;  /* 8E3F BNE */
    recomp_tick(14); return;  /* 8E41 RTS */
L_8E42:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8E42 TAY */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 8E43 PHX */
    recomp_tick(30); g_push16(0x8E46); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* 8E44 JSR */
    recomp_tick(16); g_rep(0x20);  /* 8E47 REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8E49 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8E4A TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x00099Au)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E4B LDA */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.C);  /* 8E4F STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8E51 PLX */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x06)));  /* 8E52 CMP */
    recomp_tick(16); g_sep(0x20);  /* 8E54 SEP */
    recomp_tick(14); g_push8(cpu_get_p());  /* 8E56 PHP */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF92Eu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E57 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x01);  /* 8E5B CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8E64;  /* 8E5D BNE */
    recomp_tick(14); g_set_p(g_pull8());  /* 8E5F PLP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8E67;  /* 8E60 BCS */
    recomp_tick(16); goto L_8E37;  /* 8E62 BRA */
L_8E64:;
    recomp_tick(14); g_set_p(g_pull8());  /* 8E64 PLP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8E37;  /* 8E65 BCS */
L_8E67:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* 8E67 PHY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.Y = _v; g_nz16(_v); }  /* 8E68 LDY */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.Y);  /* 8E6A STY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* 8E6C PLY */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.Y);  /* 8E6D STY */
    recomp_tick(16); goto L_8E37;  /* 8E6F BRA */
}

/* $038EC9, entered with P=$20 via JSR */
void gen_038EC9(void) {
    goto L_8EC9;
L_8DBF:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8DBF TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DC0 TAX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* 8DC1 STX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DC3 LDA */
    recomp_tick(30); g_push16(0x8DC9); func_table_call_jsr(0x039075); g_cpu.S += 2;  /* 8DC7 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DCA TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF63B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DCB LDA */
    recomp_tick(24); g_wr8(g_dp(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* 8DCE STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF9C8u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DD0 LDA */
    recomp_tick(24); g_wr8(g_dp(0x08), (uint8_t)(uint8_t)g_cpu.C);  /* 8DD4 STA */
    recomp_tick(30); g_push16(0x8DD8); func_table_call_jsr(0x039075); g_cpu.S += 2;  /* 8DD6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DD9 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF63B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DDA LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 8DDD SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x07)))));  /* 8DDE SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8DE5;  /* 8DE0 BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DE2 EOR */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DE4 INC */
L_8DE5:;
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8DE5 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8DE7 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DE8 TAX */
L_8DE9:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8DE9 INX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8DEA TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DEB LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8DEF CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8DF4;  /* 8DF1 BNE */
    recomp_tick(14); return;  /* 8DF3 RTS */
L_8DF4:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8DF4 TAY */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 8DF5 PHX */
    recomp_tick(30); g_push16(0x8DF8); func_table_call_jsr(0x039075); g_cpu.S += 2;  /* 8DF6 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DF9 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF63B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DFA LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8DFD PLX */
    recomp_tick(14); g_cpu.flag_C = true;  /* 8DFE SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x07)))));  /* 8DFF SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8E06;  /* 8E01 BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E03 EOR */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E05 INC */
L_8E06:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x06)));  /* 8E06 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8E18;  /* 8E08 BNE */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E0A XBA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x51)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E0B LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8E0D LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8E0E LSR */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E0F XBA */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8DE9;  /* 8E10 BCS */
L_8E12:;
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8E12 STA */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.Y);  /* 8E14 STY */
    recomp_tick(16); goto L_8DE9;  /* 8E16 BRA */
L_8E18:;
    recomp_tick(16); if (g_cpu.flag_C) goto L_8E12;  /* 8E18 BCS */
    recomp_tick(16); goto L_8DE9;  /* 8E1A BRA */
L_8EC9:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8EC9 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8ECA TAX */
L_8ECB:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8ECB LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 8ECF CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8ED6;  /* 8ED1 BNE */
    recomp_tick(24); goto L_8DBF;  /* 8ED3 JMP */
L_8ED6:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8ED6 TAY */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 8ED7 PHX */
    recomp_tick(30); g_push16(0x8EDA); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* 8ED8 JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8EDB TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EDC LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8EE5;  /* 8EDF BPL */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8EE1 PLX */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.Y);  /* 8EE2 STY */
    recomp_tick(14); return;  /* 8EE4 RTS */
L_8EE5:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8EE5 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8EE6 INX */
    recomp_tick(16); goto L_8ECB;  /* 8EE7 BRA */
}

/* $038F87, entered with P=$20 via JSR */
void gen_038F87(void) {
    goto L_8F87;
L_8F87:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* 8F87 PHY */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0000)); g_cpu.Y = _v; g_nz16(_v); }  /* 8F88 LDY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8F8B INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8F8C INX */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.Y);  /* 8F8D STY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* 8F8F PLY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x0A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F90 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8F95;  /* 8F92 BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8F94 TDC */
L_8F95:;
    recomp_tick(14); return;  /* 8F95 RTS */
}

/* $038FE5, entered with P=$20 via JSR */
void gen_038FE5(void) {
    goto L_8FE5;
L_8FE5:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x06)));  /* 8FE5 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8FF1;  /* 8FE7 BCS */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8FE9 STA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 8FEB PHA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8FEC LDA */
    recomp_tick(24); g_wr8(g_dp(0x08), (uint8_t)(uint8_t)g_cpu.C);  /* 8FEE STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8FF0 PLA */
L_8FF1:;
    recomp_tick(14); return;  /* 8FF1 RTS */
}

/* $039075, entered with P=$20 via JSR */
void gen_039075(void) {
    goto L_9075;
L_9075:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9075 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF98Cu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9076 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 907A TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 907B LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 907E TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 907F LDA */
    recomp_tick(14); return;  /* 9082 RTS */
}

/* $03907A, entered with P=$20 via JSR */
void gen_03907A(void) {
    goto L_907A;
L_907A:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 907A TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 907B LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 907E TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 907F LDA */
    recomp_tick(14); return;  /* 9082 RTS */
}

/* $039083, entered with P=$20 via JSR */
void gen_039083(void) {
    goto L_9083;
L_9083:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9083 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF98Cu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9084 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9088 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9089 LDA */
    recomp_tick(14); return;  /* 908C RTS */
}

/* $0390C5, entered with P=$20 via JSR */
void gen_0390C5(void) {
    goto L_90C5;
L_90C5:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 90C5 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90C6 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 90CA TAX */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 90CB ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 90CC TAY */
    recomp_tick(16); g_rep(0x20);  /* 90CD REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x0472)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 90CF LDA */
    recomp_tick(40); g_wr16(g_abs(0x0470), (uint16_t)g_cpu.C);  /* 90D2 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x04D2)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 90D5 LDA */
    recomp_tick(40); g_wr16(g_abs(0x04D0), (uint16_t)g_cpu.C);  /* 90D8 STA */
    recomp_tick(16); g_sep(0x20);  /* 90DB SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 90DD TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 90DE TAY */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF935u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90DF LDA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_90E8;  /* 90E3 BMI */
    recomp_tick(24); { uint16_t _v = 0x0003; g_cpu.Y = _v; g_nz16(_v); }  /* 90E5 LDY */
L_90E8:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0399)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90E8 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0398), (uint8_t)(uint8_t)g_cpu.C);  /* 90EB STA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90EE ORA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 90F0 PHA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0x0392))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90F1 ORA */
    recomp_tick(32); g_wr8(g_absy(0x0392), (uint8_t)(uint8_t)g_cpu.C);  /* 90F4 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_sr(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90F7 LDA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0x0393))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90F9 ORA */
    recomp_tick(32); g_wr8(g_absy(0x0393), (uint8_t)(uint8_t)g_cpu.C);  /* 90FC STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 90FF PLA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0x0394))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9100 ORA */
    recomp_tick(32); g_wr8(g_absy(0x0394), (uint8_t)(uint8_t)g_cpu.C);  /* 9103 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x03F9)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9106 LDA */
    recomp_tick(32); g_wr8(g_abs(0x03F8), (uint8_t)(uint8_t)g_cpu.C);  /* 9109 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x03C9)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 910C LDA */
    recomp_tick(32); g_wr8(g_abs(0x03C8), (uint8_t)(uint8_t)g_cpu.C);  /* 910F STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0429)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9112 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0428), (uint8_t)(uint8_t)g_cpu.C);  /* 9115 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9118 TDC */
    recomp_tick(32); g_wr8(g_absy(0x0422), (uint8_t)(uint8_t)g_cpu.C);  /* 9119 STA */
    recomp_tick(32); g_wr8(g_absy(0x0423), (uint8_t)(uint8_t)g_cpu.C);  /* 911C STA */
    recomp_tick(32); g_wr8(g_absy(0x0424), (uint8_t)(uint8_t)g_cpu.C);  /* 911F STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9122 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9126 AND */
    recomp_tick(32); g_wr8(g_abs(0x0668), (uint8_t)(uint8_t)g_cpu.C);  /* 9128 STA */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 912B PHX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 912C TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 912D LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9131 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9132 LDA */
    recomp_tick(16); g_bit8(0x08, true);  /* 9136 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9152;  /* 9138 BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0662)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 913A LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 913D EOR */
    recomp_tick(32); g_wr8(g_absy(0x0662), (uint8_t)(uint8_t)g_cpu.C);  /* 913F STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0663)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9142 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9145 EOR */
    recomp_tick(32); g_wr8(g_absy(0x0663), (uint8_t)(uint8_t)g_cpu.C);  /* 9147 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0664)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 914A LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 914D EOR */
    recomp_tick(32); g_wr8(g_absy(0x0664), (uint8_t)(uint8_t)g_cpu.C);  /* 914F STA */
L_9152:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 9152 PLX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9AAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9153 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x05);  /* 9157 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9161;  /* 9159 BCC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0668); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 915B INC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0668); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 915E INC */
L_9161:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0339)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9161 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0339), 0);  /* 9164 STZ */
    recomp_tick(32); g_wr8(g_abs(0x0338), (uint8_t)(uint8_t)g_cpu.C);  /* 9167 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 916A XBA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF935u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 916B LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 916F AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_917C;  /* 9171 BEQ */
L_9173:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 9173 XBA */
    recomp_tick(32); g_wr8(g_absy(0x0332), (uint8_t)(uint8_t)g_cpu.C);  /* 9174 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 9177 XBA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9178 INY */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9179 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9173;  /* 917A BNE */
L_917C:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 917C TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF936u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 917D LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9181 TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9182 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9185 TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x07BA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9186 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x55);  /* 9189 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9198;  /* 918B BNE */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 918D LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0398); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 918F TRB */
    recomp_tick(40); { uint32_t _e = g_abs(0x0392); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 9192 TRB */
    recomp_tick(40); { uint32_t _e = g_abs(0x0393); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 9195 TRB */
L_9198:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9198 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9199 TAY */
L_919A:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xEAEC)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 919A LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_91B2;  /* 919D BEQ */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF938u));  /* 919F CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_91A8;  /* 91A3 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 91A5 INY */
    recomp_tick(16); goto L_919A;  /* 91A6 BRA */
L_91A8:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xEB10)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91A8 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 91AB CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0668)))));  /* 91AC ADC */
    recomp_tick(32); g_wr8(g_abs(0x0668), (uint8_t)(uint8_t)g_cpu.C);  /* 91AF STA */
L_91B2:;
    recomp_tick(24); { uint16_t _v = 0x0002; g_cpu.Y = _v; g_nz16(_v); }  /* 91B2 LDY */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF933u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91B5 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_91BE;  /* 91B9 BNE */
    recomp_tick(24); { uint16_t _v = 0xFFFE; g_cpu.Y = _v; g_nz16(_v); }  /* 91BB LDY */
L_91BE:;
    recomp_tick(16); g_rep(0x20);  /* 91BE REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 91C0 TYA */
    recomp_tick(48); g_wr16(0x7EF973u, (uint16_t)g_cpu.C);  /* 91C1 STA */
    recomp_tick(16); g_sep(0x20);  /* 91C5 SEP */
    recomp_tick(24); { uint16_t _v = 0xE4BD; g_cpu.Y = _v; g_nz16(_v); }  /* 91C7 LDY */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9AAu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91CA LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x05);  /* 91CE CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_91D5;  /* 91D0 BCS */
    recomp_tick(24); { uint16_t _v = 0xE458; g_cpu.Y = _v; g_nz16(_v); }  /* 91D2 LDY */
L_91D5:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* 91D5 STY */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91D7 LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 91D9 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 91DB TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91DC LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 91E0 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91E1 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 91E3 XBA */
    recomp_tick(30); g_push16(0x91E6); func_table_call_jsr(0x03E993); g_cpu.S += 2;  /* 91E4 JSR */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_91EC;  /* 91E7 BCC */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91E9 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 91EB XBA */
L_91EC:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 91EC XBA */
    recomp_tick(40); g_wr8(0x7EF975u, (uint8_t)(uint8_t)g_cpu.C);  /* 91ED STA */
    recomp_tick(40); g_wr8(0x7EF976u, (uint8_t)(uint8_t)g_cpu.C);  /* 91F1 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 91F5 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91F6 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 91FA TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 91FB LDA */
    recomp_tick(16); g_bit8(0x08, true);  /* 91FF BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9209;  /* 9201 BEQ */
    recomp_tick(40); { uint32_t _e = g_abs(0xF975); uint8_t _v = g_lsr8(g_rd8(_e)); g_wr8(_e, _v); }  /* 9203 LSR */
    recomp_tick(40); { uint32_t _e = g_abs(0xF976); uint8_t _v = g_lsr8(g_rd8(_e)); g_wr8(_e, _v); }  /* 9206 LSR */
L_9209:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9209 INC */
    recomp_tick(16); g_sep(0x10);  /* 920B SEP */
    recomp_tick(30); g_push16(0x920F); func_table_call_jsr(0x03E96F); g_cpu.S += 2;  /* 920D JSR */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9210 LDA */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(0x7EFA0Du)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9212 ORA */
    recomp_tick(40); g_wr8(0x7EFA0Du, (uint8_t)(uint8_t)g_cpu.C);  /* 9216 STA */
    recomp_tick(16); g_rep(0x10);  /* 921A REP */
    recomp_tick(14); return;  /* 921C RTS */
}

/* $03921D, entered with P=$20 via JSR */
void gen_03921D(void) {
    goto L_921D;
L_921D:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF975u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 921D LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9225;  /* 9221 BNE */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9223 INC */
L_9225:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9225 INC */
    recomp_tick(14); return;  /* 9227 RTS */
}

/* $039228, entered with P=$20 via JSR */
void gen_039228(void) {
    goto L_9228;
L_9228:;
    recomp_tick(30); g_push16(0x922A); func_table_call_jsr(0x03923A); g_cpu.S += 2;  /* 9228 JSR */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF975u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 922B LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 922F DEC */
    recomp_tick(40); g_wr8(0x7EF975u, (uint8_t)(uint8_t)g_cpu.C);  /* 9230 STA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9237;  /* 9234 BEQ */
    recomp_tick(14); return;  /* 9236 RTS */
L_9237:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9237 INC */
    recomp_tick(14); return;  /* 9239 RTS */
}

/* $03923A, entered with P=$20 via JSR */
void gen_03923A(void) {
    goto L_923A;
L_923A:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF973u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 923A LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 923E CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0471)))));  /* 923F ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* 9242 STA */
    recomp_tick(16); g_rep(0x20);  /* 9245 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF973u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9247 LDA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 924B LSR */
    recomp_tick(16); g_sep(0x20);  /* 924C SEP */
    recomp_tick(14); g_cpu.flag_C = false;  /* 924E CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04D1)))));  /* 924F ADC */
    recomp_tick(32); g_wr8(g_abs(0x04D1), (uint8_t)(uint8_t)g_cpu.C);  /* 9252 STA */
    recomp_tick(14); return;  /* 9255 RTS */
}

/* $039AAC, entered with P=$20 via JSR */
void gen_039AAC(void) {
    goto L_9AAC;
L_9AAC:;
    recomp_tick(24); { uint16_t _v = 0xFF00; g_cpu.X = _v; g_nz16(_v); }  /* 9AAC LDX */
    recomp_tick(40); g_wr16(g_abs(0x210F), (uint16_t)g_cpu.X);  /* 9AAF STX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9AB2 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9AC4;  /* 9AB6 BNE */
    recomp_tick(24); { uint16_t _v = 0xFFF0; g_cpu.X = _v; g_nz16(_v); }  /* 9AB8 LDX */
    recomp_tick(32); g_wr16(g_dp(0x80), (uint16_t)g_cpu.X);  /* 9ABB STX */
    recomp_tick(24); { uint16_t _v = 0x00A0; g_cpu.X = _v; g_nz16(_v); }  /* 9ABD LDX */
    recomp_tick(32); g_wr16(g_dp(0x82), (uint16_t)g_cpu.X);  /* 9AC0 STX */
    recomp_tick(16); goto L_9ACE;  /* 9AC2 BRA */
L_9AC4:;
    recomp_tick(24); { uint16_t _v = 0xFFA4; g_cpu.X = _v; g_nz16(_v); }  /* 9AC4 LDX */
    recomp_tick(32); g_wr16(g_dp(0x80), (uint16_t)g_cpu.X);  /* 9AC7 STX */
    recomp_tick(24); { uint16_t _v = 0x00A0; g_cpu.X = _v; g_nz16(_v); }  /* 9AC9 LDX */
    recomp_tick(32); g_wr16(g_dp(0x82), (uint16_t)g_cpu.X);  /* 9ACC STX */
L_9ACE:;
    recomp_tick(16); { uint8_t _v = 0x17; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9ACE LDA */
    recomp_tick(24); g_wr8(g_dp(0x9D), (uint8_t)(uint8_t)g_cpu.C);  /* 9AD0 STA */
    recomp_tick(24); g_wr8(g_dp(0x9E), 0);  /* 9AD2 STZ */
    recomp_tick(24); g_wr8(g_dp(0x94), 0);  /* 9AD4 STZ */
    recomp_tick(14); return;  /* 9AD6 RTS */
}

/* $03A04F, entered with P=$20 via JSR */
void gen_03A04F(void) {
    goto L_A04F;
L_A04F:;
    recomp_tick(24); { uint16_t _v = 0x7E40; g_cpu.X = _v; g_nz16(_v); }  /* A04F LDX */
    recomp_tick(30); g_push16(0xA054); func_table_call_jsr(0x03A4BD); g_cpu.S += 2;  /* A052 JSR */
    recomp_tick(30); g_push16(0xA057); func_table_call_jsr(0x03A435); g_cpu.S += 2;  /* A055 JSR */
    recomp_tick(30); g_push16(0xA05A); func_table_call_jsr(0x03A494); g_cpu.S += 2;  /* A058 JSR */
    recomp_tick(24); { uint16_t _v = 0x7E40; g_cpu.X = _v; g_nz16(_v); }  /* A05B LDX */
    recomp_tick(30); g_push16(0xA060); func_table_call_jsr(0x03A4BD); g_cpu.S += 2;  /* A05E JSR */
    recomp_tick(14); return;  /* A061 RTS */
}

/* $03A30B, entered with P=$20 via JSR */
void gen_03A30B(void) {
    goto L_A30B;
L_A30B:;
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* A30B STX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.Y);  /* A30D STY */
    recomp_tick(16); g_rep(0x20);  /* A30F REP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A311 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A312 TAX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A313 LDA */
L_A315:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.C);  /* A315 PHA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x01FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A316 AND */
    recomp_tick(24); g_bit16(0x0100, true);  /* A319 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A31F;  /* A31C BEQ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A31E TDC */
L_A31F:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* A31F STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_sr(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A321 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* A323 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x08))));  /* A324 ADC */
    recomp_tick(24); g_bit16(0x0100, true);  /* A326 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A33B;  /* A329 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A32B TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A32C LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A337;  /* A32E BNE */
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A330 LDA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* A333 STA */
    recomp_tick(16); goto L_A341;  /* A335 BRA */
L_A337:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A337 TYA */
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A338 LDA */
L_A33B:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* A33B XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0xFF00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A33C AND */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A33F ORA */
L_A341:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A341 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A345 PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* A346 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* A347 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A349 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A34A INX */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_dp(0x04)));  /* A34B CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A315;  /* A34D BNE */
    recomp_tick(16); g_sep(0x20);  /* A34F SEP */
    recomp_tick(14); return;  /* A351 RTS */
}

/* $03A352, entered with P=$20 via JSR */
void gen_03A352(void) {
    goto L_A352;
L_A352:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A352 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A353 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A354 LDA */
    recomp_tick(16); g_rep(0x20);  /* A358 REP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A383;  /* A35A BNE */
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A35C LDA */
L_A35F:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A35F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A363 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A364 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0070);  /* A365 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A35F;  /* A368 BNE */
    recomp_tick(24); { uint16_t _v = 0xFFFE; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A36A LDA */
L_A36D:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A36D STA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A37A;  /* A371 BEQ */
    recomp_tick(24); g_bit16(0x00FF, true);  /* A373 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A37A;  /* A376 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A378 DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A379 DEC */
L_A37A:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A37A INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A37B INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* A37C CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A36D;  /* A37F BNE */
    recomp_tick(16); goto L_A3A8;  /* A381 BRA */
L_A383:;
    recomp_tick(24); { uint16_t _v = 0xFA00; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A383 LDA */
L_A386:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A386 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A38A INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A38B INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0070);  /* A38C CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A386;  /* A38F BNE */
    recomp_tick(24); { uint16_t _v = 0xFA00; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A391 LDA */
L_A394:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A394 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* A398 XBA */
    recomp_tick(24); g_bit16(0x00FF, true);  /* A399 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A3A0;  /* A39C BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A39E DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A39F DEC */
L_A3A0:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* A3A0 XBA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A3A1 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A3A2 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* A3A3 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A394;  /* A3A6 BNE */
L_A3A8:;
    recomp_tick(16); g_sep(0x20);  /* A3A8 SEP */
    recomp_tick(14); return;  /* A3AA RTS */
}

/* $03A435, entered with P=$20 via JSR */
void gen_03A435(void) {
    goto L_A435;
L_A435:;
    recomp_tick(24); { uint16_t _v = 0x005E; g_cpu.X = _v; g_nz16(_v); }  /* A435 LDX */
    recomp_tick(16); { uint8_t _v = 0x50; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A438 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A43A STA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* A43C STA */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A43E LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* A440 STA */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A442 LDA */
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* A444 STA */
L_A446:;
    recomp_tick(16); g_rep(0x20);  /* A446 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A448 LDA */
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A44A STA */
    recomp_tick(16); g_sep(0x20);  /* A44E SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A450 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* A452 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)))));  /* A453 ADC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A455 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A45B;  /* A457 BNE */
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* A459 STZ */
L_A45B:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A45B LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* A45D CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x03)))));  /* A45E ADC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A466;  /* A460 BNE */
    recomp_tick(24); g_wr8(g_dp(0x03), 0);  /* A462 STZ */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A464 LDA */
L_A466:;
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* A466 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A468 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A469 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x00E0);  /* A46A CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A473;  /* A46D BNE */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A46F LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* A471 STA */
L_A473:;
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0140);  /* A473 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A47C;  /* A476 BNE */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A478 LDA */
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* A47A STA */
L_A47C:;
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* A47C CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A446;  /* A47F BNE */
    recomp_tick(16); { uint8_t _v = 0x58; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A481 LDA */
    recomp_tick(40); g_wr8(0x7F7F70u, (uint8_t)(uint8_t)g_cpu.C);  /* A483 STA */
    recomp_tick(40); g_wr8(0x7F7F72u, (uint8_t)(uint8_t)g_cpu.C);  /* A487 STA */
    recomp_tick(40); g_wr8(0x7F7F74u, (uint8_t)(uint8_t)g_cpu.C);  /* A48B STA */
    recomp_tick(40); g_wr8(0x7F7F76u, (uint8_t)(uint8_t)g_cpu.C);  /* A48F STA */
    recomp_tick(14); return;  /* A493 RTS */
}

/* $03A494, entered with P=$20 via JSR */
void gen_03A494(void) {
    goto L_A494;
L_A494:;
    recomp_tick(14); g_push8(g_cpu.DB);  /* A494 PHB */
    recomp_tick(16); g_rep(0x20);  /* A495 REP */
    recomp_tick(24); { uint16_t _v = 0x7E40; g_cpu.X = _v; g_nz16(_v); }  /* A497 LDX */
    recomp_tick(24); { uint16_t _v = 0x7900; g_cpu.Y = _v; g_nz16(_v); }  /* A49A LDY */
    recomp_tick(24); { uint16_t _v = 0x01BF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A49D LDA */
    recomp_tick(24); g_mvn(0x7F, 0x7F);  /* A4A0 MVN */
    recomp_tick(16); g_sep(0x20);  /* A4A3 SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A4A5 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A4A6 TAX */
L_A4A7:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A4A7 TDC */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x00E0);  /* A4A8 CPX */
    recomp_tick(16); if (g_cpu.flag_C) goto L_A4B0;  /* A4AB BCS */
    recomp_tick(32); g_wr8(g_absx(0x7900), (uint8_t)(uint8_t)g_cpu.C);  /* A4AD STA */
L_A4B0:;
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A4B0 DEC */
    recomp_tick(32); g_wr8(g_absx(0x7901), (uint8_t)(uint8_t)g_cpu.C);  /* A4B1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4B4 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4B5 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0140);  /* A4B6 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A4A7;  /* A4B9 BNE */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* A4BB PLB */
    recomp_tick(14); return;  /* A4BC RTS */
}

/* $03A4BD, entered with P=$20 via JSR */
void gen_03A4BD(void) {
    goto L_A4BD;
L_A4BD:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A4BD TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A4BE TAY */
    recomp_tick(16); g_rep(0x20);  /* A4BF REP */
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4C1 LDA */
L_A4C4:;
    recomp_tick(48); g_wr16(g_longx(0x7F0000u), (uint16_t)g_cpu.C);  /* A4C4 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4C8 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4C9 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A4CA INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x00E0);  /* A4CB CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A4C4;  /* A4CE BNE */
    recomp_tick(16); g_sep(0x20);  /* A4D0 SEP */
    recomp_tick(14); return;  /* A4D2 RTS */
}

/* $03A4D3, entered with P=$20 via JSR */
void gen_03A4D3(void) {
    goto L_A4D3;
L_A4D3:;
    recomp_tick(24); { uint16_t _v = 0x7E40; g_cpu.X = _v; g_nz16(_v); }  /* A4D3 LDX */
    recomp_tick(30); g_push16(0xA4D8); func_table_call_jsr(0x03A4BD); g_cpu.S += 2;  /* A4D6 JSR */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A4D9 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A4DA LDA */
    recomp_tick(16); g_rep(0x20);  /* A4DC REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* A4DE ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A4DF TAX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4E0 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4E2 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A4E5 TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4E6 LDA */
L_A4E8:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A4E8 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4EC INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4ED INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* A4EE CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A4F6;  /* A4F1 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* A4F3 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A4E8;  /* A4F4 BNE */
L_A4F6:;
    recomp_tick(16); g_sep(0x20);  /* A4F6 SEP */
    recomp_tick(14); return;  /* A4F8 RTS */
}

/* $03A4D9, entered with P=$20 via JSR */
void gen_03A4D9(void) {
    goto L_A4D9;
L_A4D9:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A4D9 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A4DA LDA */
    recomp_tick(16); g_rep(0x20);  /* A4DC REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* A4DE ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A4DF TAX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4E0 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4E2 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A4E5 TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A4E6 LDA */
L_A4E8:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* A4E8 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4EC INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A4ED INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* A4EE CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A4F6;  /* A4F1 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* A4F3 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A4E8;  /* A4F4 BNE */
L_A4F6:;
    recomp_tick(16); g_sep(0x20);  /* A4F6 SEP */
    recomp_tick(14); return;  /* A4F8 RTS */
}

/* $03A504, entered with P=$00 via JSR */
void gen_03A504(void) {
    goto L_A504;
L_A504:;
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpil(0x7B))));  /* A504 SBC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A506 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A507 TAY */
    recomp_tick(16); g_rep(0x20);  /* A508 REP */
L_A50A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A50A LDA */
    recomp_tick(48); g_wr16(g_longx(0x7F7C80u), (uint16_t)g_cpu.C);  /* A50C STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A510 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A511 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A512 TXA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x003F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A513 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A516 TAY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* A517 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A50A;  /* A51A BNE */
    recomp_tick(16); g_sep(0x20);  /* A51C SEP */
    recomp_tick(16); { uint8_t _v = 0x04; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A51E LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0x50); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A520 TSB */
    recomp_tick(14); return;  /* A522 RTS */
}

/* $03A664, entered with P=$20 via JSR */
void gen_03A664(void) {
    goto L_A664;
L_A664:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1D0F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A664 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A667 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A668 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A669 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A66A LSR */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A66B AND */
    recomp_tick(14); g_cpu.flag_C = false;  /* A66D CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x31)));  /* A66E ADC */
    recomp_tick(14); return;  /* A670 RTS */
}

/* $03A671, entered with P=$20 via JSR */
void gen_03A671(void) {
    goto L_A671;
L_A671:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A671 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A672 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A673 TAY */
L_A674:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A674 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* A678 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A6C9;  /* A67A BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* A67C PHX */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A67D ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A67E TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0473)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A67F LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A682 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x04D3)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A684 LDA */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* A687 STA */
L_A689:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0320)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A689 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A693;  /* A68C BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A68E INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A68F INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A690 INY */
    recomp_tick(16); goto L_A689;  /* A691 BRA */
L_A693:;
    recomp_tick(16); { uint8_t _v = 0x21; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A693 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0380), (uint8_t)(uint8_t)g_cpu.C);  /* A695 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A698 TDC */
    recomp_tick(32); g_wr8(g_absy(0x0410), (uint8_t)(uint8_t)g_cpu.C);  /* A699 STA */
    recomp_tick(32); g_wr8(g_absy(0x03E0), (uint8_t)(uint8_t)g_cpu.C);  /* A69C STA */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A69F LDA */
    recomp_tick(32); g_wr8(g_absy(0x03B0), (uint8_t)(uint8_t)g_cpu.C);  /* A6A1 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1D0F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6A4 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6A7 AND */
    recomp_tick(32); g_wr8(g_absy(0x0650), (uint8_t)(uint8_t)g_cpu.C);  /* A6A9 STA */
    recomp_tick(16); { uint8_t _v = 0xC0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6AC LDA */
    recomp_tick(32); g_wr8(g_absy(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* A6AE STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6B1 TYA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A6B2 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A6B3 TAX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6B4 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0441), (uint8_t)(uint8_t)g_cpu.C);  /* A6B6 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6B9 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04A1), (uint8_t)(uint8_t)g_cpu.C);  /* A6BB STA */
    recomp_tick(30); g_push16(0xA6C0); func_table_call_jsr(0x03A664); g_cpu.S += 2;  /* A6BE JSR */
    recomp_tick(32); g_wr8(g_absy(0x0320), (uint8_t)(uint8_t)g_cpu.C);  /* A6C1 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* A6C4 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6C5 INX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A6C6 TDC */
    recomp_tick(16); goto L_A674;  /* A6C7 BRA */
L_A6C9:;
    recomp_tick(14); return;  /* A6C9 RTS */
}

/* $03A883, entered with P=$20 via JSR */
void gen_03A883(void) {
    goto L_A883;
L_A883:;
    recomp_tick(30); g_push16(0xA885); func_table_call_jsr(0x03E993); g_cpu.S += 2;  /* A883 JSR */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_A88C;  /* A886 BCC */
    recomp_tick(16); { uint8_t _v = 0x0F; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A888 LDA */
    recomp_tick(16); goto L_A8A5;  /* A88A BRA */
L_A88C:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A88C LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xE0); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A890 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A899;  /* A892 BNE */
L_A894:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A894 INC */
L_A896:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A896 INC */
    recomp_tick(14); return;  /* A898 RTS */
L_A899:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A899 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A89A LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A89E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x01E3F3u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A89F LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A894;  /* A8A3 BEQ */
L_A8A5:;
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* A8A5 STA */
    recomp_tick(16); goto L_A896;  /* A8A9 BRA */
}

/* $03A8AB, entered with P=$20 via JSR */
void gen_03A8AB(void) {
    goto L_A8AB;
L_A8AB:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7F0000u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8AB LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A8AF DEC */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* A8B0 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A8B8;  /* A8B4 BNE */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A8B6 INC */
L_A8B8:;
    recomp_tick(14); return;  /* A8B8 RTS */
}

/* $03A9EC, entered with P=$30 via JSR */
void gen_03A9EC(void) {
    goto L_A9EC;
L_A9EC:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A9EC TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* A9ED TAX */
L_A9EE:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0392)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9EE LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* A9F1 PHA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0E); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9F2 AND */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A9F4 LSR */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* A9F5 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9F6 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A9F8 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9FA PLA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xF1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9FB AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x00))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A9FD ORA */
    recomp_tick(32); g_wr8(g_absx(0x0392), (uint8_t)(uint8_t)g_cpu.C);  /* A9FF STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* AA02 INX */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x11);  /* AA03 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A9EE;  /* AA05 BNE */
    recomp_tick(14); return;  /* AA07 RTS */
}

/* $03AA7B, entered with P=$20 via JSR */
void gen_03AA7B(void) {
    goto L_AA7B;
L_AA5F:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7F7700u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA5F LDA */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* AA63 STA */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* AA65 PHX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* AA66 TYX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7F7700u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA67 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* AA6B PHA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA6C LDA */
    recomp_tick(40); g_wr8(g_longx(0x7F7700u), (uint8_t)(uint8_t)g_cpu.C);  /* AA6E STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA72 PLA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AA73 PLX */
    recomp_tick(40); g_wr8(g_longx(0x7F7700u), (uint8_t)(uint8_t)g_cpu.C);  /* AA74 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AA78 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AA79 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* AA7A INY */
L_AA7B:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* AA7B INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* AA7C DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AA5F;  /* AA7E BNE */
    recomp_tick(16); g_sep(0x20);  /* AA80 SEP */
    recomp_tick(14); return;  /* AA82 RTS */
}

/* $03AAAB, entered with P=$20 via JSR */
void gen_03AAAB(void) {
    goto L_AAAB;
L_AAAB:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AAAB TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* AAAC TAX */
L_AAAD:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xAACD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AAAD LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AAB0 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AAB9;  /* AAB2 BNE */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AAB4 INC */
L_AAB6:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AAB6 INC */
    recomp_tick(14); return;  /* AAB8 RTS */
L_AAB9:;
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF93Au));  /* AAB9 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AAC2;  /* AABD BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AABF INX */
    recomp_tick(16); goto L_AAAD;  /* AAC0 BRA */
L_AAC2:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AAC2 TXA */
    recomp_tick(32); g_wr8(g_abs(0x1D11), (uint8_t)(uint8_t)g_cpu.C);  /* AAC3 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AAC6 TDC */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* AAC7 STA */
    recomp_tick(16); goto L_AAB6;  /* AACB BRA */
}

/* $03B2D8, entered with P=$20 via JSR */
void gen_03B2D8(void) {
    goto L_B2D8;
L_B2D8:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7F0000u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B2D8 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B2DC INC */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* B2DD STA */
    recomp_tick(14); return;  /* B2E1 RTS */
}

/* $03B2FD, entered with P=$20 via JSR */
void gen_03B2FD(void) {
    goto L_B2FD;
L_B2FD:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* B2FD ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* B2FF ASL */
    recomp_tick(16); g_sep(0x10);  /* B301 SEP */
    recomp_tick(16); { uint8_t _v = 0x02; g_cpu.X = _v; g_nz8(_v); }  /* B303 LDX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B305 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x01)));  /* B307 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B30D;  /* B309 BCC */
    recomp_tick(16); { uint8_t _v = 0xFE; g_cpu.X = _v; g_nz8(_v); }  /* B30B LDX */
L_B30D:;
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)g_cpu.X);  /* B30D STX */
    recomp_tick(16); g_rep(0x20);  /* B30F REP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* B311 LDX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* B313 TXY */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F76A0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B314 LDA */
L_B318:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.C);  /* B318 PHA */
    recomp_tick(16); g_sep(0x20);  /* B319 SEP */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B31B TXA */
    recomp_tick(14); g_cpu.flag_C = false;  /* B31C CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)))));  /* B31D ADC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* B31F TAX */
    recomp_tick(16); g_rep(0x20);  /* B320 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F76A0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B322 LDA */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* B326 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B328 PLA */
    recomp_tick(48); g_wr16(g_longx(0x7F76A0u), (uint16_t)g_cpu.C);  /* B329 STA */
    recomp_tick(16); g_sep(0x20);  /* B32D SEP */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B32F TYA */
    recomp_tick(14); g_cpu.flag_C = false;  /* B330 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)))));  /* B331 ADC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* B333 TAY */
    recomp_tick(16); g_rep(0x20);  /* B334 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B336 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.Y, g_rd8(g_dp(0x01)));  /* B338 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B318;  /* B33A BNE */
    recomp_tick(16); g_sep(0x20);  /* B33C SEP */
    recomp_tick(16); g_rep(0x10);  /* B33E REP */
    recomp_tick(14); return;  /* B340 RTS */
}

/* $03B341, entered with P=$20 via JSR */
void gen_03B341(void) {
    goto L_B341;
L_B341:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* B341 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* B343 ASL */
    recomp_tick(16); g_sep(0x10);  /* B345 SEP */
    recomp_tick(16); g_rep(0x20);  /* B347 REP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* B349 LDX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* B34B TXY */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F76A0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B34C LDA */
L_B350:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.C);  /* B350 PHA */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* B351 INX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* B352 INX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F76A0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B353 LDA */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* B357 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B359 PLA */
    recomp_tick(48); g_wr16(g_longx(0x7F76A0u), (uint16_t)g_cpu.C);  /* B35A STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B35E LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz8(_v); }  /* B360 INY */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz8(_v); }  /* B361 INY */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.Y, g_rd8(g_dp(0x01)));  /* B362 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B350;  /* B364 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* B366 LDX */
    recomp_tick(48); g_wr16(g_longx(0x7F76A0u), (uint16_t)g_cpu.C);  /* B368 STA */
    recomp_tick(16); g_sep(0x20);  /* B36C SEP */
    recomp_tick(16); g_rep(0x10);  /* B36E REP */
    recomp_tick(14); return;  /* B370 RTS */
}

/* $03B53C, entered with P=$20 via JSR */
void gen_03B53C(void) {
    goto L_B53C;
L_B53C:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B53C LDA */
    recomp_tick(16); g_bit8(0x08, true);  /* B540 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B555;  /* B542 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B544 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x5B);  /* B548 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B55B;  /* B54A BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x5C);  /* B54C CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B55B;  /* B54E BEQ */
L_B550:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B550 TDC */
    recomp_tick(40); g_wr8(0x7EF935u, (uint8_t)(uint8_t)g_cpu.C);  /* B551 STA */
L_B555:;
    recomp_tick(30); g_push16(0xB557); func_table_call_jsr(0x03B5FE); g_cpu.S += 2;  /* B555 JSR */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B558 INC */
    recomp_tick(14); return;  /* B55A RTS */
L_B55B:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B55B LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x60);  /* B55F CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B573;  /* B561 BCS */
    recomp_tick(32); g_wr8(g_abs(0x0668), 0);  /* B563 STZ */
    recomp_tick(16); { uint8_t _v = 0x04; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B566 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0665), (uint8_t)(uint8_t)g_cpu.C);  /* B568 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0338)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B56B LDA */
    recomp_tick(32); g_wr8(g_abs(0x0335), (uint8_t)(uint8_t)g_cpu.C);  /* B56E STA */
    recomp_tick(16); goto L_B550;  /* B571 BRA */
L_B573:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xAB);  /* B573 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B589;  /* B575 BEQ */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B577 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0668), (uint8_t)(uint8_t)g_cpu.C);  /* B579 STA */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B57C LDA */
    recomp_tick(32); g_wr8(g_abs(0x0665), (uint8_t)(uint8_t)g_cpu.C);  /* B57E STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0338)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B581 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0335), (uint8_t)(uint8_t)g_cpu.C);  /* B584 STA */
    recomp_tick(16); goto L_B550;  /* B587 BRA */
L_B589:;
    recomp_tick(16); { uint8_t _v = 0x06; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B589 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0666), (uint8_t)(uint8_t)g_cpu.C);  /* B58B STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B58E TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B58F LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B593 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* B594 TXY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* B595 DEY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0338)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B596 LDA */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_absy(0x0339)));  /* B599 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B5A0;  /* B59C BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* B59E INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* B59F INY */
L_B5A0:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0399)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5A0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5A3 ORA */
    recomp_tick(32); g_wr8(g_abs(0x0395), (uint8_t)(uint8_t)g_cpu.C);  /* B5A5 STA */
    recomp_tick(32); g_wr8(g_abs(0x0396), (uint8_t)(uint8_t)g_cpu.C);  /* B5A8 STA */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5AB LDA */
    recomp_tick(32); g_wr8(g_abs(0x0668), (uint8_t)(uint8_t)g_cpu.C);  /* B5AD STA */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5B0 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0665), (uint8_t)(uint8_t)g_cpu.C);  /* B5B2 STA */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5B5 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0669), (uint8_t)(uint8_t)g_cpu.C);  /* B5B7 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5BA INC */
    recomp_tick(32); g_wr8(g_absx(0x0669), (uint8_t)(uint8_t)g_cpu.C);  /* B5BB STA */
    recomp_tick(16); { uint8_t _v = 0xC0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5BE LDA */
    recomp_tick(32); g_wr8(g_absx(0x0369), (uint8_t)(uint8_t)g_cpu.C);  /* B5C0 STA */
    recomp_tick(32); g_wr8(g_absy(0x0369), (uint8_t)(uint8_t)g_cpu.C);  /* B5C3 STA */
    recomp_tick(16); { uint8_t _v = 0x2D; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5C6 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0335), (uint8_t)(uint8_t)g_cpu.C);  /* B5C8 STA */
    recomp_tick(32); g_wr8(g_abs(0x0336), (uint8_t)(uint8_t)g_cpu.C);  /* B5CB STA */
    recomp_tick(32); g_wr8(g_absx(0x0339), (uint8_t)(uint8_t)g_cpu.C);  /* B5CE STA */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5D1 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* B5D3 PHA */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* B5D4 PLB */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF9AA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5D5 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* B5D8 PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xF9AA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5D9 LDA */
    recomp_tick(32); g_wr8(g_absx(0xF9AA), (uint8_t)(uint8_t)g_cpu.C);  /* B5DC STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5DF PLA */
    recomp_tick(32); g_wr8(g_absy(0xF9AA), (uint8_t)(uint8_t)g_cpu.C);  /* B5E0 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xF98C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5E3 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B5E6 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xF98C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5E7 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B5EA TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0DCD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5EB LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* B5EE PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0DCD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5EF LDA */
    recomp_tick(32); g_wr8(g_absx(0x0DCD), (uint8_t)(uint8_t)g_cpu.C);  /* B5F2 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5F5 PLA */
    recomp_tick(32); g_wr8(g_absy(0x0DCD), (uint8_t)(uint8_t)g_cpu.C);  /* B5F6 STA */
    recomp_tick(14); g_push8(0x03);  /* B5F9 PHK */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* B5FA PLB */
    recomp_tick(24); goto L_B550;  /* B5FB JMP */
}

/* $03B5FE, entered with P=$20 via JSR */
void gen_03B5FE(void) {
    goto L_B5FE;
L_B5FE:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B5FE LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x75);  /* B602 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B612;  /* B604 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B606 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x52);  /* B60A CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B612;  /* B60C BNE */
    recomp_tick(40); { uint32_t _e = g_abs(0x0664); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B60E INC */
    recomp_tick(14); return;  /* B611 RTS */
L_B612:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B612 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xAA);  /* B616 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B622;  /* B618 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B61A LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x54);  /* B61E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B642;  /* B620 BEQ */
L_B622:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B622 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xA3);  /* B626 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B632;  /* B628 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B62A LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x53);  /* B62E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B642;  /* B630 BEQ */
L_B632:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B632 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xA4);  /* B636 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B649;  /* B638 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF938u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B63A LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x55);  /* B63E CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B649;  /* B640 BNE */
L_B642:;
    recomp_tick(40); { uint32_t _e = g_abs(0x0668); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B642 INC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0662); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B645 INC */
    recomp_tick(14); return;  /* B648 RTS */
L_B649:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF936u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B649 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x7D);  /* B64D CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B683;  /* B64F BCC */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B651 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B652 TAY */
L_B653:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xB661)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B653 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B683;  /* B656 BEQ */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF938u));  /* B658 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B672;  /* B65C BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* B65E INY */
    recomp_tick(16); goto L_B653;  /* B65F BRA */
L_B672:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Au); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B672 LDA */
    recomp_tick(16); g_bit8(0xE0, true);  /* B676 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B683;  /* B678 BEQ */
    recomp_tick(40); { uint32_t _e = g_abs(0x0668); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B67A INC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xB66A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B67D LDA */
    recomp_tick(32); g_wr8(g_abs(0x0662), (uint8_t)(uint8_t)g_cpu.C);  /* B680 STA */
L_B683:;
    recomp_tick(14); return;  /* B683 RTS */
}

/* $03B684, entered with P=$20 via JSR */
void gen_03B684(void) {
    goto L_B684;
L_B684:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B684 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B685 TAY */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF935u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B686 LDA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_B68F;  /* B68A BMI */
    recomp_tick(24); { uint16_t _v = 0x0003; g_cpu.Y = _v; g_nz16(_v); }  /* B68C LDY */
L_B68F:;
    recomp_tick(32); g_wr8(g_abs(0x03F8), 0);  /* B68F STZ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* B692 PHY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B693 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF936u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B694 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B698 TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B699 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B69C TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x07BA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B69D LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* B6A0 PLY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x55);  /* B6A1 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B6AC;  /* B6A3 BNE */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6A5 LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0398); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* B6A7 TRB */
    recomp_tick(16); goto L_B6BE;  /* B6AA BRA */
L_B6AC:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x54);  /* B6AC CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B6B4;  /* B6AE BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x53);  /* B6B0 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B6B9;  /* B6B2 BNE */
L_B6B4:;
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6B4 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0428), (uint8_t)(uint8_t)g_cpu.C);  /* B6B6 STA */
L_B6B9:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6B9 LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0398); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* B6BB TSB */
L_B6BE:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x03C8)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6BE LDA */
    recomp_tick(32); g_wr8(g_absy(0x03C2), (uint8_t)(uint8_t)g_cpu.C);  /* B6C1 STA */
    recomp_tick(32); g_wr8(g_absy(0x03C3), (uint8_t)(uint8_t)g_cpu.C);  /* B6C4 STA */
    recomp_tick(32); g_wr8(g_absy(0x03C4), (uint8_t)(uint8_t)g_cpu.C);  /* B6C7 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6CA TYA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* B6CB ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B6CC TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0471)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6CD LDA */
    recomp_tick(32); g_wr8(g_absx(0x0465), (uint8_t)(uint8_t)g_cpu.C);  /* B6D0 STA */
    recomp_tick(32); g_wr8(g_absx(0x0467), (uint8_t)(uint8_t)g_cpu.C);  /* B6D3 STA */
    recomp_tick(32); g_wr8(g_absx(0x0469), (uint8_t)(uint8_t)g_cpu.C);  /* B6D6 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04D1)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6D9 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04C5), (uint8_t)(uint8_t)g_cpu.C);  /* B6DC STA */
    recomp_tick(32); g_wr8(g_absx(0x04C7), (uint8_t)(uint8_t)g_cpu.C);  /* B6DF STA */
    recomp_tick(32); g_wr8(g_absx(0x04C9), (uint8_t)(uint8_t)g_cpu.C);  /* B6E2 STA */
    recomp_tick(30); g_push16(0xB6E7); func_table_call_jsr(0x03E993); g_cpu.S += 2;  /* B6E5 JSR */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B711;  /* B6E8 BCC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF933u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6EA LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF934u));  /* B6EE CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B6FE;  /* B6F2 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6F4 LDA */
    recomp_tick(16); g_bit8(0x10, true);  /* B6F8 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B706;  /* B6FA BNE */
    recomp_tick(16); goto L_B70E;  /* B6FC BRA */
L_B6FE:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6FE LDA */
    recomp_tick(16); g_bit8(0x10, true);  /* B702 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B70E;  /* B704 BNE */
L_B706:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0428)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B706 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0x03); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B709 EOR */
    recomp_tick(32); g_wr8(g_abs(0x0428), (uint8_t)(uint8_t)g_cpu.C);  /* B70B STA */
L_B70E:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B70E TDC */
    recomp_tick(16); goto L_B716;  /* B70F BRA */
L_B711:;
    recomp_tick(16); { uint8_t _v = 0xC0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B711 LDA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x0368))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B713 ORA */
L_B716:;
    recomp_tick(32); g_wr8(g_abs(0x0368), (uint8_t)(uint8_t)g_cpu.C);  /* B716 STA */
    recomp_tick(32); g_wr8(g_absy(0x0362), (uint8_t)(uint8_t)g_cpu.C);  /* B719 STA */
    recomp_tick(32); g_wr8(g_absy(0x0363), (uint8_t)(uint8_t)g_cpu.C);  /* B71C STA */
    recomp_tick(32); g_wr8(g_absy(0x0364), (uint8_t)(uint8_t)g_cpu.C);  /* B71F STA */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B722 INC */
    recomp_tick(14); return;  /* B724 RTS */
}

/* $03B994, entered with P=$20 via JSR */
void gen_03B994(void) {
    goto L_B994;
L_B994:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B994 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B995 TAX */
L_B996:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B996 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B99A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B9A7;  /* B99C BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B99E TAY */
    recomp_tick(16); { uint8_t _v = 0x81; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B99F LDA */
    recomp_tick(32); g_wr8(g_absy(0x0609), (uint8_t)(uint8_t)g_cpu.C);  /* B9A1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B9A4 INX */
    recomp_tick(16); goto L_B996;  /* B9A5 BRA */
L_B9A7:;
    recomp_tick(14); return;  /* B9A7 RTS */
}

/* $03BAAA, entered with P=$20 via JSR */
void gen_03BAAA(void) {
    goto L_BAAA;
L_BAAA:;
    recomp_tick(16); g_rep(0x20);  /* BAAA REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAAC AND */
    recomp_tick(14); g_cpu.flag_C = false;  /* BAAF CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x0B))));  /* BAB0 ADC */
    recomp_tick(32); g_wr16(g_dp(0x0B), (uint16_t)g_cpu.C);  /* BAB2 STA */
    recomp_tick(16); g_sep(0x20);  /* BAB4 SEP */
    recomp_tick(14); return;  /* BAB6 RTS */
}

/* $03BC57, entered with P=$20 via JSR */
void gen_03BC57(void) {
    goto L_BC57;
L_BC57:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* BC57 XBA */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC58 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* BC5A XBA */
    recomp_tick(16); g_rep(0x20);  /* BC5B REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* BC5D CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* BC5E ADC */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* BC60 STA */
    recomp_tick(16); g_sep(0x20);  /* BC62 SEP */
    recomp_tick(14); return;  /* BC64 RTS */
}

/* $03BEE1, entered with P=$20 via JSR */
void gen_03BEE1(void) {
    goto L_BEE1;
L_BEE1:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BEE1 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x15)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BEE2 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* BEE4 TAY */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BEE5 TDC */
    recomp_tick(32); g_wr8(g_absy(0x0410), (uint8_t)(uint8_t)g_cpu.C);  /* BEE6 STA */
    recomp_tick(32); g_wr8(g_absy(0x0411), (uint8_t)(uint8_t)g_cpu.C);  /* BEE9 STA */
    recomp_tick(32); g_wr8(g_absy(0x0412), (uint8_t)(uint8_t)g_cpu.C);  /* BEEC STA */
    recomp_tick(16); { uint8_t _v = 0x3E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BEEF LDA */
    recomp_tick(32); g_wr8(g_absy(0x0380), (uint8_t)(uint8_t)g_cpu.C);  /* BEF1 STA */
    recomp_tick(32); g_wr8(g_absy(0x0381), (uint8_t)(uint8_t)g_cpu.C);  /* BEF4 STA */
    recomp_tick(32); g_wr8(g_absy(0x0382), (uint8_t)(uint8_t)g_cpu.C);  /* BEF7 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BEFA LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BF04;  /* BEFE BEQ */
    recomp_tick(16); { uint8_t _v = 0x09; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF00 LDA */
    recomp_tick(16); goto L_BF06;  /* BF02 BRA */
L_BF04:;
    recomp_tick(16); { uint8_t _v = 0x06; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF04 LDA */
L_BF06:;
    recomp_tick(32); g_wr8(g_absy(0x0650), (uint8_t)(uint8_t)g_cpu.C);  /* BF06 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF09 INC */
    recomp_tick(32); g_wr8(g_absy(0x0651), (uint8_t)(uint8_t)g_cpu.C);  /* BF0A STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF0D INC */
    recomp_tick(32); g_wr8(g_absy(0x0652), (uint8_t)(uint8_t)g_cpu.C);  /* BF0E STA */
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* BF11 PHY */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* BF12 PHX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF13 TYA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* BF14 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* BF15 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF16 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* BF18 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BF19 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0473)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF1A LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* BF1D CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x04)));  /* BF1E ADC */
    recomp_tick(32); g_wr8(g_absy(0x0441), (uint8_t)(uint8_t)g_cpu.C);  /* BF20 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* BF23 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x08)));  /* BF24 ADC */
    recomp_tick(32); g_wr8(g_absy(0x0443), (uint8_t)(uint8_t)g_cpu.C);  /* BF26 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* BF29 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x08)));  /* BF2A ADC */
    recomp_tick(32); g_wr8(g_absy(0x0445), (uint8_t)(uint8_t)g_cpu.C);  /* BF2C STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x04D3)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF2F LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x20)));  /* BF32 SBC */
    recomp_tick(32); g_wr8(g_absy(0x04A1), (uint8_t)(uint8_t)g_cpu.C);  /* BF34 STA */
    recomp_tick(32); g_wr8(g_absy(0x04A3), (uint8_t)(uint8_t)g_cpu.C);  /* BF37 STA */
    recomp_tick(32); g_wr8(g_absy(0x04A5), (uint8_t)(uint8_t)g_cpu.C);  /* BF3A STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* BF3D PLX */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* BF3E PLY */
    recomp_tick(16); { uint8_t _v = 0x3F; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BF3F LDA */
    recomp_tick(32); g_wr8(g_absy(0x0320), (uint8_t)(uint8_t)g_cpu.C);  /* BF41 STA */
    recomp_tick(32); g_wr8(g_absy(0x0321), (uint8_t)(uint8_t)g_cpu.C);  /* BF44 STA */
    recomp_tick(32); g_wr8(g_absy(0x0322), (uint8_t)(uint8_t)g_cpu.C);  /* BF47 STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x15); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BF4A INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x15); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BF4C INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x15); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BF4E INC */
    recomp_tick(14); return;  /* BF50 RTS */
}

/* $03BFB8, entered with P=$00 via JSR */
void gen_03BFB8(void) {
    goto L_BFB8;
L_BFB8:;
    recomp_tick(14); ;  /* BFB8 NOP */
    recomp_tick(14); return;  /* BFB9 RTS */
}

/* $03BFB9, entered with P=$30 via JSR */
void gen_03BFB9(void) {
    goto L_BFB9;
L_BFB9:;
    recomp_tick(14); return;  /* BFB9 RTS */
}

/* $03C194, entered with P=$20 via JSR */
void gen_03C194(void) {
    goto L_C194;
L_C194:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C194 XBA */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C195 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C197 XBA */
    recomp_tick(16); g_rep(0x20);  /* C198 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* C19A CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C19B ADC */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* C19D STA */
    recomp_tick(16); g_sep(0x20);  /* C19F SEP */
    recomp_tick(14); return;  /* C1A1 RTS */
}

/* $03C24F, entered with P=$20 via JSR */
void gen_03C24F(void) {
    goto L_C24F;
L_C24F:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C24F XBA */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C250 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C252 XBA */
    recomp_tick(16); g_rep(0x20);  /* C253 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* C255 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* C256 ADC */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* C258 STA */
    recomp_tick(16); g_sep(0x20);  /* C25A SEP */
    recomp_tick(14); return;  /* C25C RTS */
}

/* $03C265, entered with P=$20 via JSR */
void gen_03C265(void) {
    goto L_C265;
L_C265:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.X = _v; g_nz16(_v); }  /* C265 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C267 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C268 LDA */
    recomp_tick(30); g_push16(0xC26E); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* C26C JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C26F TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C270 LDA */
    recomp_tick(16); g_bit8(0x10, true);  /* C274 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C27B;  /* C276 BEQ */
    recomp_tick(24); goto L_C30E;  /* C278 JMP */
L_C27B:;
    recomp_tick(16); g_rep(0x20);  /* C27B REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C27D TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* C27E ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C27F TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C280 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* C283 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C284 SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_C290;  /* C286 BPL */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C288 LDA */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* C28B STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C28D LDA */
L_C290:;
    recomp_tick(40); g_wr16(g_absx(0x099A), (uint16_t)g_cpu.C);  /* C290 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C2DA;  /* C293 BNE */
    recomp_tick(16); g_sep(0x20);  /* C295 SEP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.X = _v; g_nz16(_v); }  /* C297 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C299 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C29A LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* C29E PHA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C29F TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x3F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A4 AND */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A6 ORA */
    recomp_tick(40); g_wr8(g_longx(0x7EF982u), (uint8_t)(uint8_t)g_cpu.C);  /* C2A8 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2AC PLA */
    recomp_tick(30); g_push16(0xC2AF); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* C2AD JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C2B0 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2B1 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2B4 ORA */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* C2B6 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2B9 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C2CF;  /* C2BD BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C2BF TDC */
    recomp_tick(40); g_wr8(g_longx(0x7EF1E8u), (uint8_t)(uint8_t)g_cpu.C);  /* C2C0 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Fu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2C4 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2C8 INC */
    recomp_tick(40); g_wr8(0x7EF93Fu, (uint8_t)(uint8_t)g_cpu.C);  /* C2C9 STA */
    recomp_tick(16); goto L_C2D8;  /* C2CD BRA */
L_C2CF:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF940u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2CF LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2D3 INC */
    recomp_tick(40); g_wr8(0x7EF940u, (uint8_t)(uint8_t)g_cpu.C);  /* C2D4 STA */
L_C2D8:;
    recomp_tick(16); g_rep(0x20);  /* C2D8 REP */
L_C2DA:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2DA LDA */
    recomp_tick(48); g_wr16(0x7EF947u, (uint16_t)g_cpu.C);  /* C2DC STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xCB)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2E0 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2E2 AND */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0004);  /* C2E5 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C30B;  /* C2E8 BNE */
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF934u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2EA LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2EE AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C300;  /* C2F1 BNE */
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF944u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2F3 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C2F7 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C2F8 ADC */
    recomp_tick(48); g_wr16(0x7EF944u, (uint16_t)g_cpu.C);  /* C2FA STA */
    recomp_tick(16); goto L_C30B;  /* C2FE BRA */
L_C300:;
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF942u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C300 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C304 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C305 ADC */
    recomp_tick(48); g_wr16(0x7EF942u, (uint16_t)g_cpu.C);  /* C307 STA */
L_C30B:;
    recomp_tick(16); g_sep(0x20);  /* C30B SEP */
    recomp_tick(14); return;  /* C30D RTS */
L_C30E:;
    recomp_tick(16); g_rep(0x20);  /* C30E REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C310 TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* C311 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C312 TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C313 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C316 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C317 ADC */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absx(0x0ADA)));  /* C319 CMP */
    recomp_tick(16); if (g_cpu.flag_N) goto L_C32A;  /* C31C BMI */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0ADA)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C31E LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* C321 SEC */
    recomp_tick(40); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_absx(0x099A))));  /* C322 SBC */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* C325 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0ADA)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C327 LDA */
L_C32A:;
    recomp_tick(40); g_wr16(g_absx(0x099A), (uint16_t)g_cpu.C);  /* C32A STA */
    recomp_tick(16); g_sep(0x20);  /* C32D SEP */
    recomp_tick(14); return;  /* C32F RTS */
}

/* $03C27B, entered with P=$20 via JSR */
void gen_03C27B(void) {
    goto L_C27B;
L_C27B:;
    recomp_tick(16); g_rep(0x20);  /* C27B REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C27D TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* C27E ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C27F TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C280 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* C283 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C284 SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_C290;  /* C286 BPL */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C288 LDA */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* C28B STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C28D LDA */
L_C290:;
    recomp_tick(40); g_wr16(g_absx(0x099A), (uint16_t)g_cpu.C);  /* C290 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C2DA;  /* C293 BNE */
    recomp_tick(16); g_sep(0x20);  /* C295 SEP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.X = _v; g_nz16(_v); }  /* C297 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C299 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C29A LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* C29E PHA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C29F TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x3F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A4 AND */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2A6 ORA */
    recomp_tick(40); g_wr8(g_longx(0x7EF982u), (uint8_t)(uint8_t)g_cpu.C);  /* C2A8 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2AC PLA */
    recomp_tick(30); g_push16(0xC2AF); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* C2AD JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C2B0 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2B1 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2B4 ORA */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* C2B6 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2B9 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C2CF;  /* C2BD BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C2BF TDC */
    recomp_tick(40); g_wr8(g_longx(0x7EF1E8u), (uint8_t)(uint8_t)g_cpu.C);  /* C2C0 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Fu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2C4 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2C8 INC */
    recomp_tick(40); g_wr8(0x7EF93Fu, (uint8_t)(uint8_t)g_cpu.C);  /* C2C9 STA */
    recomp_tick(16); goto L_C2D8;  /* C2CD BRA */
L_C2CF:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF940u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2CF LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C2D3 INC */
    recomp_tick(40); g_wr8(0x7EF940u, (uint8_t)(uint8_t)g_cpu.C);  /* C2D4 STA */
L_C2D8:;
    recomp_tick(16); g_rep(0x20);  /* C2D8 REP */
L_C2DA:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2DA LDA */
    recomp_tick(48); g_wr16(0x7EF947u, (uint16_t)g_cpu.C);  /* C2DC STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xCB)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2E0 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2E2 AND */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0004);  /* C2E5 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C30B;  /* C2E8 BNE */
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF934u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2EA LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2EE AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C300;  /* C2F1 BNE */
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF944u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C2F3 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C2F7 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C2F8 ADC */
    recomp_tick(48); g_wr16(0x7EF944u, (uint16_t)g_cpu.C);  /* C2FA STA */
    recomp_tick(16); goto L_C30B;  /* C2FE BRA */
L_C300:;
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF942u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C300 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C304 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* C305 ADC */
    recomp_tick(48); g_wr16(0x7EF942u, (uint16_t)g_cpu.C);  /* C307 STA */
L_C30B:;
    recomp_tick(16); g_sep(0x20);  /* C30B SEP */
    recomp_tick(14); return;  /* C30D RTS */
}

/* $03C330, entered with P=$20 via JSR */
void gen_03C330(void) {
    goto L_C330;
L_C330:;
    recomp_tick(24); { uint16_t _v = 0x000E; g_cpu.X = _v; g_nz16(_v); }  /* C330 LDX */
L_C333:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0320)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C333 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x3F);  /* C336 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C33D;  /* C338 BNE */
    recomp_tick(32); g_wr8(g_absx(0x0320), 0);  /* C33A STZ */
L_C33D:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* C33D DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_C333;  /* C33E BPL */
    recomp_tick(14); return;  /* C340 RTS */
}

/* $03C341, entered with P=$20 via JSR */
void gen_03C341(void) {
    goto L_C341;
L_C341:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* C341 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C343 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C344 TAX */
L_C345:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0320)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C345 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C35A;  /* C348 BEQ */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)));  /* C34A CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C35A;  /* C34C BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C34E LDA */
    recomp_tick(16); g_bit8(0x80, true);  /* C351 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C35A;  /* C353 BNE */
    recomp_tick(16); { uint8_t _v = 0xC0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C355 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* C357 STA */
L_C35A:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C35A INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000F);  /* C35B CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C345;  /* C35E BNE */
    recomp_tick(14); return;  /* C360 RTS */
}

/* $03C56C, entered with P=$20 via JSR */
void gen_03C56C(void) {
    goto L_C56C;
L_C56C:;
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.X = _v; g_nz16(_v); }  /* C56C LDX */
    recomp_tick(32); g_wr16(g_dp(0x97), (uint16_t)g_cpu.X);  /* C56F STX */
    recomp_tick(32); g_wr16(g_dp(0x99), (uint16_t)g_cpu.X);  /* C571 STX */
    recomp_tick(16); { uint8_t _v = 0x15; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C573 LDA */
    recomp_tick(24); g_wr8(g_dp(0x9D), (uint8_t)(uint8_t)g_cpu.C);  /* C575 STA */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C577 LDA */
    recomp_tick(24); g_wr8(g_dp(0x9E), (uint8_t)(uint8_t)g_cpu.C);  /* C579 STA */
    recomp_tick(16); { uint8_t _v = 0xC0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C57B LDA */
    recomp_tick(24); g_wr8(g_dp(0x94), (uint8_t)(uint8_t)g_cpu.C);  /* C57D STA */
    recomp_tick(16); { uint8_t _v = 0xC0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C57F LDA */
    recomp_tick(24); g_wr8(g_dp(0x96), (uint8_t)(uint8_t)g_cpu.C);  /* C581 STA */
    recomp_tick(24); g_wr8(g_dp(0xA1), 0);  /* C583 STZ */
    recomp_tick(24); g_wr8(g_dp(0xA2), 0);  /* C585 STZ */
    recomp_tick(24); g_wr8(g_dp(0xA0), (uint8_t)(uint8_t)g_cpu.C);  /* C587 STA */
    recomp_tick(24); g_wr8(g_dp(0x9F), 0);  /* C589 STZ */
    recomp_tick(24); g_wr8(g_dp(0x77), 0);  /* C58B STZ */
    recomp_tick(16); { uint8_t _v = 0x30; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C58D LDA */
    recomp_tick(32); g_wr8(g_abs(0x210B), (uint8_t)(uint8_t)g_cpu.C);  /* C58F STA */
    recomp_tick(16); { uint8_t _v = 0x40; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C592 LDA */
    recomp_tick(24); g_wr8(g_dp(0x79), (uint8_t)(uint8_t)g_cpu.C);  /* C594 STA */
    recomp_tick(32); g_wr8(g_abs(0x2108), (uint8_t)(uint8_t)g_cpu.C);  /* C596 STA */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C599 LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0050); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* C59B TRB */
    recomp_tick(16); { uint8_t _v = 0xE0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C59E LDA */
    recomp_tick(24); g_wr8(g_dp(0xA3), (uint8_t)(uint8_t)g_cpu.C);  /* C5A0 STA */
    recomp_tick(24); g_wr8(g_dp(0xA4), 0);  /* C5A2 STZ */
    recomp_tick(24); g_wr8(g_dp(0xA5), 0);  /* C5A4 STZ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C5A6 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C5A7 TAX */
    recomp_tick(32); g_wr16(g_dp(0x80), (uint16_t)g_cpu.X);  /* C5A8 STX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* C5AA DEX */
    recomp_tick(32); g_wr16(g_dp(0x82), (uint16_t)g_cpu.X);  /* C5AB STX */
    recomp_tick(14); return;  /* C5AD RTS */
}

/* $03C5AE, entered with P=$20 via JSR */
void gen_03C5AE(void) {
    goto L_C5AE;
L_C5AE:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF976u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5AE LDA */
    recomp_tick(40); g_wr8(0x7EF975u, (uint8_t)(uint8_t)g_cpu.C);  /* C5B2 STA */
    recomp_tick(16); g_rep(0x20);  /* C5B6 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(0x7EF973u); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C5B8 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C5BC EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C5BF INC */
    recomp_tick(48); g_wr16(0x7EF973u, (uint16_t)g_cpu.C);  /* C5C0 STA */
    recomp_tick(16); g_sep(0x20);  /* C5C4 SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C5C6 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C5C7 TAX */
L_C5C8:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9D3u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5C8 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* C5CC CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C5E1;  /* C5CE BEQ */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF939u));  /* C5D0 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C5D9;  /* C5D4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C5D6 INX */
    recomp_tick(16); goto L_C5C8;  /* C5D7 BRA */
L_C5D9:;
    recomp_tick(16); { uint8_t _v = 0x28; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5D9 LDA */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* C5DB STA */
    recomp_tick(16); goto L_C5E3;  /* C5DF BRA */
L_C5E1:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C5E1 INC */
L_C5E3:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C5E3 INC */
    recomp_tick(14); return;  /* C5E5 RTS */
}

/* $03C5E6, entered with P=$20 via JSR */
void gen_03C5E6(void) {
    goto L_C5E6;
L_C5E6:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7F0000u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5E6 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C5F2;  /* C5EA BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5EC DEC */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* C5ED STA */
    recomp_tick(14); return;  /* C5F1 RTS */
L_C5F2:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C5F2 INC */
    recomp_tick(14); return;  /* C5F4 RTS */
}

/* $03C5F5, entered with P=$20 via JSR */
void gen_03C5F5(void) {
    goto L_C5F5;
L_C5F5:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF975u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5F5 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C5FE;  /* C5F9 BEQ */
    recomp_tick(30); g_push16(0xC5FD); func_table_call_jsr(0x03C63B); g_cpu.S += 2;  /* C5FB JSR */
L_C5FE:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0320)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C5FE LDA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x0323))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C601 ORA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x0326))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C604 ORA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x0329))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C607 ORA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x032C))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C60A ORA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C610;  /* C60D BEQ */
    recomp_tick(14); return;  /* C60F RTS */
L_C610:;
    recomp_tick(30); g_push16(0xC612); func_table_call_jsr(0x03DDE1); g_cpu.S += 2;  /* C610 JSR */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C613 INC */
    recomp_tick(14); return;  /* C615 RTS */
}

/* $03C616, entered with P=$20 via JSR */
void gen_03C616(void) {
    goto L_C616;
L_C616:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF975u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C616 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C620;  /* C61A BEQ */
    recomp_tick(30); g_push16(0xC61E); func_table_call_jsr(0x03C63B); g_cpu.S += 2;  /* C61C JSR */
    recomp_tick(14); return;  /* C61F RTS */
L_C620:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C620 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C624 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0338)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C625 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0338), 0);  /* C628 STZ */
    recomp_tick(32); g_wr8(g_absx(0x0339), (uint8_t)(uint8_t)g_cpu.C);  /* C62B STA */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C62E INC */
    recomp_tick(14); return;  /* C630 RTS */
}

/* $03C63B, entered with P=$20 via JSR */
void gen_03C63B(void) {
    goto L_C63B;
L_C63B:;
    recomp_tick(30); g_push16(0xC63D); func_table_call_jsr(0x03923A); g_cpu.S += 2;  /* C63B JSR */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF975u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C63E LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C642 DEC */
    recomp_tick(40); g_wr8(0x7EF975u, (uint8_t)(uint8_t)g_cpu.C);  /* C643 STA */
    recomp_tick(14); return;  /* C647 RTS */
}

/* $03C7E7, entered with P=$20 via JSR */
void gen_03C7E7(void) {
    goto L_C7E7;
L_C7E7:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C7E7 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C7FF;  /* C7EB BNE */
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C7ED LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0xD5); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* C7EF TSB */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xD6)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C7F1 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C7FF;  /* C7F3 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF934u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C7F5 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C7FF;  /* C7F9 BNE */
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C7FB LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0xD6); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* C7FD TSB */
L_C7FF:;
    recomp_tick(14); return;  /* C7FF RTS */
}

/* $03C800, entered with P=$20 via JSR */
void gen_03C800(void) {
    goto L_C800;
L_C800:;
    recomp_tick(40); { uint32_t _e = g_abs(0x07A2); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* C800 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C807;  /* C803 BNE */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C805 INC */
L_C807:;
    recomp_tick(14); return;  /* C807 RTS */
}

/* $03C8C9, entered with P=$20 via JSR */
void gen_03C8C9(void) {
    goto L_C8C9;
L_C8C9:;
    recomp_tick(24); { uint16_t _v = 0x0003; g_cpu.Y = _v; g_nz16(_v); }  /* C8C9 LDY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C8CC LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C8D3;  /* C8CE BEQ */
    recomp_tick(24); { uint16_t _v = 0x0006; g_cpu.Y = _v; g_nz16(_v); }  /* C8D0 LDY */
L_C8D3:;
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.Y);  /* C8D3 STY */
    recomp_tick(16); g_rep(0x20);  /* C8D5 REP */
L_C8D7:;
    recomp_tick(32); g_wr16(g_dp(0x06), 0);  /* C8D7 STZ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C8D9 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C8DA TAY */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* C8DB PHX */
L_C8DC:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F0002u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C8DC LDA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_dpily(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C8E0 AND */
    recomp_tick(48); g_wr16(g_longx(0x7F0002u), (uint16_t)g_cpu.C);  /* C8E2 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* C8E6 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* C8E7 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0020);  /* C8E8 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C8EF;  /* C8EB BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C8ED TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C8EE TAY */
L_C8EF:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C8EF INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C8F0 INX */
    recomp_tick(48); { uint32_t _e = g_dp(0x06); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* C8F1 INC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C8F3 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0080);  /* C8F5 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C8DC;  /* C8F8 BNE */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C8FA PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C8FB CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0200));  /* C8FC ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C8FF TAX */
    recomp_tick(48); { uint32_t _e = g_dp(0x08); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* C900 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C8D7;  /* C902 BNE */
    recomp_tick(16); g_sep(0x20);  /* C904 SEP */
    recomp_tick(14); return;  /* C906 RTS */
}

/* $03C907, entered with P=$20 via JSR */
void gen_03C907(void) {
    goto L_C907;
L_C907:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C907 INC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C909 LDA */
    recomp_tick(16); g_bit8(0x01, true);  /* C90C BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C941;  /* C90E BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Eu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C910 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x19);  /* C914 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C95D;  /* C916 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x095E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C918 LDA */
    recomp_tick(16); g_bit8(0x01, true);  /* C91B BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C95D;  /* C91D BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x081E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C91F LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x5B);  /* C922 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C92D;  /* C924 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x095F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C926 LDA */
    recomp_tick(16); g_bit8(0x01, true);  /* C929 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C95D;  /* C92B BEQ */
L_C92D:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C92D LDA */
    recomp_tick(40); g_wr8(0x7EF968u, (uint8_t)(uint8_t)g_cpu.C);  /* C92F STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C933 TDC */
    recomp_tick(16); g_rep(0x20);  /* C934 REP */
    recomp_tick(48); g_wr16(0x7EF944u, (uint16_t)g_cpu.C);  /* C936 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C93A INC */
    recomp_tick(48); g_wr16(0x7EF942u, (uint16_t)g_cpu.C);  /* C93B STA */
    recomp_tick(16); goto L_C959;  /* C93F BRA */
L_C941:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x0007BAu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C941 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x4E);  /* C945 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C95D;  /* C947 BCC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x52);  /* C949 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C95D;  /* C94B BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C94D TDC */
    recomp_tick(16); g_rep(0x20);  /* C94E REP */
    recomp_tick(48); g_wr16(0x7EF942u, (uint16_t)g_cpu.C);  /* C950 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C954 INC */
    recomp_tick(48); g_wr16(0x7EF944u, (uint16_t)g_cpu.C);  /* C955 STA */
L_C959:;
    recomp_tick(16); g_sep(0x20);  /* C959 SEP */
    recomp_tick(24); g_wr8(g_dp(0xCB), (uint8_t)(uint8_t)g_cpu.C);  /* C95B STA */
L_C95D:;
    recomp_tick(14); return;  /* C95D RTS */
}

/* $03C9BC, entered with P=$20 via JSR */
void gen_03C9BC(void) {
    goto L_C9BC;
L_C9BC:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C9BC TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF939u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9BD LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C9C1 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9C2 LDA */
    recomp_tick(16); g_bit8(0x80, true);  /* C9C6 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C9F3;  /* C9C8 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF996u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9CA LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9CE DEC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_C9D2;  /* C9CF BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C9D1 TDC */
L_C9D2:;
    recomp_tick(40); g_wr8(g_longx(0x7EF996u), (uint8_t)(uint8_t)g_cpu.C);  /* C9D2 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C9E2;  /* C9D6 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9D8 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9DC ORA */
    recomp_tick(40); g_wr8(g_longx(0x7EF982u), (uint8_t)(uint8_t)g_cpu.C);  /* C9DE STA */
L_C9E2:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9E2 LDA */
    recomp_tick(16); g_bit8(0x30, true);  /* C9E6 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C9F3;  /* C9E8 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF941u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9EA LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9EE DEC */
    recomp_tick(40); g_wr8(0x7EF941u, (uint8_t)(uint8_t)g_cpu.C);  /* C9EF STA */
L_C9F3:;
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9F3 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* C9F5 XBA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF92Fu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9F6 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C9FA TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C9FB INC */
    recomp_tick(40); g_wr8(0x7EF92Fu, (uint8_t)(uint8_t)g_cpu.C);  /* C9FC STA */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* CA00 INC */
    recomp_tick(14); return;  /* CA02 RTS */
}

/* $03CD77, entered with P=$20 via JSR */
void gen_03CD77(void) {
    goto L_CD77;
L_CD77:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CD77 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CD78 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x07A2)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CD79 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CD81;  /* CD7C BEQ */
    recomp_tick(24); { uint16_t _v = 0x0007; g_cpu.X = _v; g_nz16(_v); }  /* CD7E LDX */
L_CD81:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CD81 TXA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD82 CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x1271)))));  /* CD83 ADC */
    recomp_tick(40); g_wr8(0x7EF9C8u, (uint8_t)(uint8_t)g_cpu.C);  /* CD86 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CD8A TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0DBE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CD8B LDA */
    recomp_tick(14); return;  /* CD8E RTS */
}

/* $03CF3D, entered with P=$20 via JSR */
void gen_03CF3D(void) {
    goto L_CF3D;
L_CF3D:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CF3D TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF937u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF3E LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CF42 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xCF8D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF43 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0690), (uint8_t)(uint8_t)g_cpu.C);  /* CF46 STA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_CF6A;  /* CF49 BPL */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF931u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF4B LDA */
    recomp_tick(16); g_bit8(0x04, true);  /* CF4F BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CF67;  /* CF51 BEQ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CF53 TDC */
    recomp_tick(40); g_wr8(0x7EF934u, (uint8_t)(uint8_t)g_cpu.C);  /* CF54 STA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x10); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF58 AND */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF5A ORA */
    recomp_tick(40); g_wr8(0x7EF93Cu, (uint8_t)(uint8_t)g_cpu.C);  /* CF5C STA */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF60 LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0690); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* CF62 TRB */
    recomp_tick(16); goto L_CF7A;  /* CF65 BRA */
L_CF67:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0690)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF67 LDA */
L_CF6A:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* CF6A PHA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF6B AND */
    recomp_tick(40); g_wr8(0x7EF934u, (uint8_t)(uint8_t)g_cpu.C);  /* CF6D STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF71 PLA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x10); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF72 AND */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF74 ORA */
    recomp_tick(40); g_wr8(0x7EF93Cu, (uint8_t)(uint8_t)g_cpu.C);  /* CF76 STA */
L_CF7A:;
    recomp_tick(30); g_push16(0xCF7C); func_table_call_jsr(0x038CE3); g_cpu.S += 2;  /* CF7A JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0690)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF7D LDA */
    recomp_tick(16); g_bit8(0x20, true);  /* CF80 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CF85;  /* CF82 BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CF84 TDC */
L_CF85:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x20); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF85 AND */
    recomp_tick(30); g_push16(0xCF89); func_table_call_jsr(0x038CED); g_cpu.S += 2;  /* CF87 JSR */
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* CF8A INC */
    recomp_tick(14); return;  /* CF8C RTS */
}

/* $03D065, entered with P=$20 via JSR */
void gen_03D065(void) {
    goto L_D065;
L_D065:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D065 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D066 TAX */
L_D067:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD089)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D067 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D06A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D084;  /* D06C BEQ */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF937u));  /* D06E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D077;  /* D072 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D074 INX */
    recomp_tick(16); goto L_D067;  /* D075 BRA */
L_D077:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD08F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D077 LDA */
    recomp_tick(32); g_wr8(g_abs(0x07A2), (uint8_t)(uint8_t)g_cpu.C);  /* D07A STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D07D TDC */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* D07E STA */
    recomp_tick(16); goto L_D086;  /* D082 BRA */
L_D084:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D084 INC */
L_D086:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D086 INC */
    recomp_tick(14); return;  /* D088 RTS */
}

/* $03D186, entered with P=$20 via JSR */
void gen_03D186(void) {
    goto L_D186;
L_D186:;
    recomp_tick(30); g_push16(0xD188); func_table_call_jsr(0x03DDE1); g_cpu.S += 2;  /* D186 JSR */
    recomp_tick(30); g_push16(0xD18B); func_table_call_jsr(0x03E983); g_cpu.S += 2;  /* D189 JSR */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF931u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D18C LDA */
    recomp_tick(16); g_bit8(0x04, true);  /* D190 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D19C;  /* D192 BEQ */
    recomp_tick(30); g_push16(0xD196); func_table_call_jsr(0x03C330); g_cpu.S += 2;  /* D194 JSR */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D197 LDA */
    recomp_tick(24); g_wr8(g_dp(0xCC), (uint8_t)(uint8_t)g_cpu.C);  /* D199 STA */
    recomp_tick(14); return;  /* D19B RTS */
L_D19C:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D19C INC */
    recomp_tick(14); return;  /* D19E RTS */
}

/* $03D26A, entered with P=$20 via JSR */
void gen_03D26A(void) {
    goto L_D26A;
L_D26A:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D26A TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D26B LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D26D TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D26E LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xBF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D272 AND */
    recomp_tick(40); g_wr8(g_longx(0x7EF982u), (uint8_t)(uint8_t)g_cpu.C);  /* D274 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF996u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D278 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D27C INC */
    recomp_tick(40); g_wr8(g_longx(0x7EF996u), (uint8_t)(uint8_t)g_cpu.C);  /* D27D STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D281 LDA */
    recomp_tick(16); g_bit8(0xB0, true);  /* D285 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D292;  /* D287 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF941u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D289 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D28D INC */
    recomp_tick(40); g_wr8(0x7EF941u, (uint8_t)(uint8_t)g_cpu.C);  /* D28E STA */
L_D292:;
    recomp_tick(14); g_cpu.flag_C = false;  /* D292 CLC */
    recomp_tick(14); return;  /* D293 RTS */
}

/* $03D294, entered with P=$20 via JSR */
void gen_03D294(void) {
    goto L_D294;
L_D294:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D294 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x04); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D298 ORA */
    recomp_tick(40); g_wr8(0x7EF93Cu, (uint8_t)(uint8_t)g_cpu.C);  /* D29A STA */
    recomp_tick(16); { uint8_t _v = 0xB2; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D29E LDA */
    recomp_tick(40); g_wr8(0x7EF93Au, (uint8_t)(uint8_t)g_cpu.C);  /* D2A0 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D2A4 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2A5 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D2A7 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2A8 LDA */
    recomp_tick(16); g_bit8(0x10, true);  /* D2AC BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D2CB;  /* D2AE BNE */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x10); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2B0 ORA */
    recomp_tick(40); g_wr8(g_longx(0x7EF982u), (uint8_t)(uint8_t)g_cpu.C);  /* D2B2 STA */
    recomp_tick(16); g_bit8(0x20, true);  /* D2B6 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D2CB;  /* D2B8 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF996u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2BA LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D2BE PHA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF941u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2BF LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* D2C3 SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x01)))));  /* D2C4 SBC */
    recomp_tick(40); g_wr8(0x7EF941u, (uint8_t)(uint8_t)g_cpu.C);  /* D2C6 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2CA PLA */
L_D2CB:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D2CB TXA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D2CC ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D2CD TAX */
    recomp_tick(16); g_rep(0x20);  /* D2CE REP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D2D0 TDC */
    recomp_tick(48); g_wr16(g_longx(0x7EF8C9u), (uint16_t)g_cpu.C);  /* D2D1 STA */
    recomp_tick(16); g_sep(0x20);  /* D2D5 SEP */
    recomp_tick(14); g_cpu.flag_C = false;  /* D2D7 CLC */
    recomp_tick(14); return;  /* D2D8 RTS */
}

/* $03D37A, entered with P=$20 via JSR */
void gen_03D37A(void) {
    goto L_D37A;
L_D37A:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF931u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D37A LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D37E ORA */
    recomp_tick(40); g_wr8(0x7EF931u, (uint8_t)(uint8_t)g_cpu.C);  /* D380 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D384 CLC */
    recomp_tick(14); return;  /* D385 RTS */
}

/* $03D3D7, entered with P=$20 via JSR */
void gen_03D3D7(void) {
    goto L_D3D7;
L_D3D7:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Cu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D3D7 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D3DB ORA */
    recomp_tick(40); g_wr8(0x7EF93Cu, (uint8_t)(uint8_t)g_cpu.C);  /* D3DD STA */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF931u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D3E1 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x20); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D3E5 ORA */
    recomp_tick(40); g_wr8(0x7EF931u, (uint8_t)(uint8_t)g_cpu.C);  /* D3E7 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D3EB CLC */
    recomp_tick(14); return;  /* D3EC RTS */
}

/* $03D41B, entered with P=$20 via JSR */
void gen_03D41B(void) {
    goto L_D41B;
L_D41B:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D41B TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D41C LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D41E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF982u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D41F LDA */
    recomp_tick(16); g_bit8(0x38, true);  /* D423 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D44F;  /* D425 BEQ */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D427 PHA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xC7); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D428 AND */
    recomp_tick(40); g_wr8(g_longx(0x7EF982u), (uint8_t)(uint8_t)g_cpu.C);  /* D42A STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D42E PLA */
    recomp_tick(16); g_bit8(0x30, true);  /* D42F BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D44F;  /* D431 BEQ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF996u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D433 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D437 CLC */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(0x7EF941u))));  /* D438 ADC */
    recomp_tick(40); g_wr8(0x7EF941u, (uint8_t)(uint8_t)g_cpu.C);  /* D43C STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D440 TXA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D441 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D442 TAX */
    recomp_tick(16); g_rep(0x20);  /* D443 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7EF88Du)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D445 LDA */
    recomp_tick(48); g_wr16(g_longx(0x7EF8C9u), (uint16_t)g_cpu.C);  /* D449 STA */
    recomp_tick(16); g_sep(0x20);  /* D44D SEP */
L_D44F:;
    recomp_tick(14); g_cpu.flag_C = false;  /* D44F CLC */
    recomp_tick(14); return;  /* D450 RTS */
}

/* $03D4BC, entered with P=$20 via JSR */
void gen_03D4BC(void) {
    goto L_D4BC;
L_D4BC:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D4BC TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D4BD LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D4BF ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D4C0 TAX */
    recomp_tick(16); g_rep(0x20);  /* D4C1 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7EF8C9u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D4C3 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D4C7 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0032));  /* D4C8 ADC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_D4CE;  /* D4CB BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D4CD TDC */
L_D4CE:;
    recomp_tick(48); g_wr16(g_longx(0x7EF8C9u), (uint16_t)g_cpu.C);  /* D4CE STA */
    recomp_tick(16); g_sep(0x20);  /* D4D2 SEP */
    recomp_tick(14); g_cpu.flag_C = false;  /* D4D4 CLC */
    recomp_tick(14); return;  /* D4D5 RTS */
}

/* $03D5C3, entered with P=$20 via JSR */
void gen_03D5C3(void) {
    goto L_D5C3;
L_D5C3:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF931u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C3 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x10); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C7 ORA */
    recomp_tick(40); g_wr8(0x7EF931u, (uint8_t)(uint8_t)g_cpu.C);  /* D5C9 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D5CD CLC */
    recomp_tick(14); return;  /* D5CE RTS */
}

/* $03D5CF, entered with P=$20 via JSR */
void gen_03D5CF(void) {
    goto L_D5CF;
L_D5CF:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D5CF TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D5D0 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* D5D1 TAY */
L_D5D2:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xD609)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5D2 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D5D5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5E9;  /* D5D7 BEQ */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF937u));  /* D5D9 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5E2;  /* D5DD BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D5DF INY */
    recomp_tick(16); goto L_D5D2;  /* D5E0 BRA */
L_D5E2:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xD60F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5E2 LDA */
    recomp_tick(40); g_wr8(0x7EF93Au, (uint8_t)(uint8_t)g_cpu.C);  /* D5E5 STA */
L_D5E9:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD614)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5E9 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D5EC CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D604;  /* D5EE BEQ */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x7EF937u));  /* D5F0 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5F9;  /* D5F4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D5F6 INX */
    recomp_tick(16); goto L_D5E9;  /* D5F7 BRA */
L_D5F9:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5F9 TXA */
    recomp_tick(32); g_wr8(g_abs(0x07A2), (uint8_t)(uint8_t)g_cpu.C);  /* D5FA STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D5FD TDC */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* D5FE STA */
    recomp_tick(16); goto L_D606;  /* D602 BRA */
L_D604:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D604 INC */
L_D606:;
    recomp_tick(32); { uint32_t _e = g_dp(0xCC); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D606 INC */
    recomp_tick(14); return;  /* D608 RTS */
}

/* $03D61F, entered with P=$20 via JSR */
void gen_03D61F(void) {
    goto L_D61F;
L_D61F:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF93Bu); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D61F LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x05);  /* D623 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D638;  /* D625 BEQ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D627 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D628 LDA */
    recomp_tick(30); g_push16(0xD62C); func_table_call_jsr(0x039083); g_cpu.S += 2;  /* D62A JSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D62D TAX */
    recomp_tick(14); g_cpu.flag_C = false;  /* D62E CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D62F LDA */
    recomp_tick(16); g_bit8(0x20, true);  /* D632 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D637;  /* D634 BEQ */
    recomp_tick(14); g_cpu.flag_C = true;  /* D636 SEC */
L_D637:;
    recomp_tick(14); return;  /* D637 RTS */
L_D638:;
    recomp_tick(14); g_cpu.flag_C = false;  /* D638 CLC */
    recomp_tick(14); return;  /* D639 RTS */
}

/* $03D908, entered with P=$20 via JSR */
void gen_03D908(void) {
    goto L_D908;
L_D908:;
    recomp_tick(16); g_rep(0x20);  /* D908 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D90A AND */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* D90D STA */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* D90F STA */
    recomp_tick(24); { uint16_t _v = 0x0140; g_cpu.X = _v; g_nz16(_v); }  /* D911 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D914 TDC */
L_D915:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.C);  /* D915 PHA */
L_D916:;
    recomp_tick(48); g_wr16(g_longx(0x7F7E40u), (uint16_t)g_cpu.C);  /* D916 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D91A LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D928;  /* D91C BEQ */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* D91E DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* D920 DEX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* D921 DEX */
    recomp_tick(16); if (g_cpu.flag_N) goto L_D92C;  /* D922 BMI */
    recomp_tick(32); { uint16_t _v = g_rd16(g_sr(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D924 LDA */
    recomp_tick(16); goto L_D916;  /* D926 BRA */
L_D928:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D928 LDA */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* D92A STA */
L_D92C:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D92C PLA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D92D INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* D92E DEX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* D92F DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_D915;  /* D930 BPL */
    recomp_tick(16); g_sep(0x20);  /* D932 SEP */
    recomp_tick(14); return;  /* D934 RTS */
}

/* $03DC65, entered with P=$20 via JSR */
void gen_03DC65(void) {
    goto L_DC65;
L_DC65:;
    recomp_tick(16); g_rep(0x20);  /* DC65 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* DC67 LDA */
    recomp_tick(40); g_wr16(g_absx(0x0592), (uint16_t)g_cpu.C);  /* DC69 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* DC6C LDA */
    recomp_tick(40); g_wr16(g_absx(0x0532), (uint16_t)g_cpu.C);  /* DC6E STA */
    recomp_tick(16); g_sep(0x20);  /* DC71 SEP */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0369)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DC73 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x20); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DC76 ORA */
    recomp_tick(32); g_wr8(g_absy(0x0369), (uint8_t)(uint8_t)g_cpu.C);  /* DC78 STA */
    recomp_tick(14); return;  /* DC7B RTS */
}

/* $03DC7C, entered with P=$20 via JSR */
void gen_03DC7C(void) {
    goto L_DC7C;
L_DC7C:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* DC7C TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* DC7D TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* DC7E TAY */
L_DC7F:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9C8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DC7F LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* DC83 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_DC8B;  /* DC85 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* DC87 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* DC88 INX */
    recomp_tick(16); goto L_DC7F;  /* DC89 BRA */
L_DC8B:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DC8B TYA */
    recomp_tick(14); return;  /* DC8C RTS */
}

/* $03DDE1, entered with P=$20 via JSR */
void gen_03DDE1(void) {
    goto L_DDE1;
L_DDE1:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* DDE1 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* DDE2 TAX */
L_DDE3:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0369)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDE3 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xDC); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDE6 AND */
    recomp_tick(32); g_wr8(g_absx(0x0369), (uint8_t)(uint8_t)g_cpu.C);  /* DDE8 STA */
    recomp_tick(32); g_wr8(g_absx(0x0609), 0);  /* DDEB STZ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* DDEE INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000A);  /* DDEF CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_DDE3;  /* DDF2 BNE */
    recomp_tick(14); return;  /* DDF4 RTS */
}

/* $03E098, entered with P=$20 via JSR */
void gen_03E098(void) {
    goto L_E098;
L_E098:;
    recomp_tick(16); g_rep(0x20);  /* E098 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E09A TYA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E09B CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0100));  /* E09C ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* E09F TAY */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E0A0 TXA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E0A1 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0200));  /* E0A2 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E0A5 TAX */
    recomp_tick(16); g_sep(0x20);  /* E0A6 SEP */
    recomp_tick(14); return;  /* E0A8 RTS */
}

/* $03E0E5, entered with P=$20 via JSR */
void gen_03E0E5(void) {
    goto L_E0E5;
L_E0E5:;
    recomp_tick(14); g_push8(g_cpu.DB);  /* E0E5 PHB */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* E0E6 PHA */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* E0E7 PLB */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E0E8 TYA */
L_E0E9:;
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E0F7;  /* E0E9 BEQ */
L_E0EB:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0000)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E0EB LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E0F3;  /* E0EE BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E0F0 INX */
    recomp_tick(16); goto L_E0EB;  /* E0F1 BRA */
L_E0F3:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E0F3 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* E0F4 DEY */
    recomp_tick(16); goto L_E0E9;  /* E0F5 BRA */
L_E0F7:;
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* E0F7 PLB */
    recomp_tick(14); return;  /* E0F8 RTS */
}

/* $03E2D1, entered with P=$20 via JSR */
void gen_03E2D1(void) {
    goto L_E2D1;
L_E2D1:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* E2D1 PHA */
    recomp_tick(16); g_rep(0x20);  /* E2D2 REP */
    recomp_tick(24); { uint16_t _v = 0xA000; g_cpu.X = _v; g_nz16(_v); }  /* E2D4 LDX */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* E2D7 LDY */
    recomp_tick(24); { uint16_t _v = 0x1FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2DA LDA */
    recomp_tick(24); g_mvn(0x7F, 0x0A);  /* E2DD MVN */
    recomp_tick(16); g_sep(0x20);  /* E2E0 SEP */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E2E2 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* E2E4 PHA */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* E2E5 PLB */
    recomp_tick(16); g_rep(0x20);  /* E2E6 REP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E2E8 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E2E9 TAX */
L_E2EA:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2EA TXA */
    recomp_tick(24); g_bit16(0x0010, true);  /* E2EB BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E30A;  /* E2EE BNE */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F0000u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2F0 LDA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_longx(0x7F0010u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E2F4 ORA */
    recomp_tick(16); g_sep(0x20);  /* E2F8 SEP */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* E2FA PHA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x01))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E2FB ORA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E2FD EOR */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_longx(0x7F0000u))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E2FF ORA */
    recomp_tick(40); g_wr8(g_longx(0x7F0000u), (uint8_t)(uint8_t)g_cpu.C);  /* E303 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E307 PLA */
    recomp_tick(16); g_rep(0x20);  /* E308 REP */
L_E30A:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E30A INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E30B INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x2000);  /* E30C CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E2EA;  /* E30F BNE */
    recomp_tick(24); { uint16_t _v = 0xC000; g_cpu.X = _v; g_nz16(_v); }  /* E311 LDX */
    recomp_tick(24); { uint16_t _v = 0x2F20; g_cpu.Y = _v; g_nz16(_v); }  /* E314 LDY */
    recomp_tick(24); { uint16_t _v = 0x02FF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E317 LDA */
    recomp_tick(24); g_mvn(0x7F, 0x0A);  /* E31A MVN */
    recomp_tick(24); { uint16_t _v = 0x8020; g_cpu.X = _v; g_nz16(_v); }  /* E31D LDX */
    recomp_tick(24); { uint16_t _v = 0x3220; g_cpu.Y = _v; g_nz16(_v); }  /* E320 LDY */
    recomp_tick(24); { uint16_t _v = 0x01DF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E323 LDA */
    recomp_tick(24); g_mvn(0x7F, 0x0A);  /* E326 MVN */
    recomp_tick(16); g_sep(0x20);  /* E329 SEP */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E32B LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* E32D PHA */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* E32E PLB */
    recomp_tick(24); { uint16_t _v = 0x3600; g_cpu.Y = _v; g_nz16(_v); }  /* E32F LDY */
    recomp_tick(40); g_wr16(g_abs(0x2181), (uint16_t)g_cpu.Y);  /* E332 STY */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E335 LDA */
    recomp_tick(32); g_wr8(g_abs(0x2183), (uint8_t)(uint8_t)g_cpu.C);  /* E337 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E33A TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E33B TAX */
    recomp_tick(24); { uint16_t _v = 0x0600; g_cpu.Y = _v; g_nz16(_v); }  /* E33C LDY */
L_E33F:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E33F TXA */
    recomp_tick(16); g_bit8(0x08, true);  /* E340 BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E34C;  /* E342 BEQ */
    recomp_tick(32); g_wr8(g_abs(0x2180), 0);  /* E344 STZ */
    recomp_tick(32); g_wr8(g_abs(0x2180), 0);  /* E347 STZ */
    recomp_tick(16); goto L_E354;  /* E34A BRA */
L_E34C:;
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E34C LDA */
    recomp_tick(32); g_wr8(g_abs(0x2180), (uint8_t)(uint8_t)g_cpu.C);  /* E34E STA */
    recomp_tick(32); g_wr8(g_abs(0x2180), 0);  /* E351 STZ */
L_E354:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E354 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* E355 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E33F;  /* E356 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xCA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E358 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x07);  /* E35A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E360;  /* E35C BEQ */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E35E PLA */
    recomp_tick(14); return;  /* E35F RTS */
L_E360:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E360 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E361 TAX */
    recomp_tick(24); { uint16_t _v = 0x0100; g_cpu.Y = _v; g_nz16(_v); }  /* E362 LDY */
    recomp_tick(16); g_rep(0x20);  /* E365 REP */
L_E367:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F3200u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E367 LDA */
    recomp_tick(48); g_wr16(g_longx(0x7F3400u), (uint16_t)g_cpu.C);  /* E36B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E36F INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E370 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* E371 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E367;  /* E372 BNE */
    recomp_tick(16); g_sep(0x20);  /* E374 SEP */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E376 PLA */
    recomp_tick(14); return;  /* E377 RTS */
}

/* $03E423, entered with P=$00 via JSR */
void gen_03E423(void) {
    goto L_E423;
L_E423:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E423 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* E424 TAY */
L_E425:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E425 LDA */
    recomp_tick(32); g_wr16(g_dpily(0x07), (uint16_t)g_cpu.C);  /* E427 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* E429 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* E42A INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* E42B DEX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E425;  /* E42C BNE */
    recomp_tick(14); return;  /* E42E RTS */
}

/* $03E425, entered with P=$00 via JSR */
void gen_03E425(void) {
    goto L_E425;
L_E425:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* E425 LDA */
    recomp_tick(32); g_wr16(g_dpily(0x07), (uint16_t)g_cpu.C);  /* E427 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* E429 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* E42A INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* E42B DEX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E425;  /* E42C BNE */
    recomp_tick(14); return;  /* E42E RTS */
}

/* $03E94B, entered with P=$20 via JSR */
void gen_03E94B(void) {
    goto L_E94B;
L_E94B:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E94B TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E94C TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* E94D TAY */
L_E94E:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF9D3u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E94E LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_E95E;  /* E952 BPL */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* E954 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E966;  /* E956 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* E958 TYX */
    recomp_tick(40); g_wr8(g_longx(0x7EF9C8u), (uint8_t)(uint8_t)g_cpu.C);  /* E959 STA */
    recomp_tick(14); return;  /* E95D RTS */
L_E95E:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* E95E PHX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* E95F TYX */
    recomp_tick(40); g_wr8(g_longx(0x7EF9C8u), (uint8_t)(uint8_t)g_cpu.C);  /* E960 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* E964 INY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* E965 PLX */
L_E966:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7E); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E966 AND */
    recomp_tick(40); g_wr8(g_longx(0x7EF9D3u), (uint8_t)(uint8_t)g_cpu.C);  /* E968 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E96C INX */
    recomp_tick(16); goto L_E94E;  /* E96D BRA */
}

/* $03E96F, entered with P=$30 via JSR */
void gen_03E96F(void) {
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

/* $03E97E, entered with P=$20 via JSR */
void gen_03E97E(void) {
    goto L_E97E;
L_E97E:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E97E TDC */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E97F INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E980 TAX */
    recomp_tick(16); goto L_E985;  /* E981 BRA */
L_E985:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EFA0Du)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E985 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0398), (uint8_t)(uint8_t)g_cpu.C);  /* E989 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E98C INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000B);  /* E98D CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E985;  /* E990 BNE */
    recomp_tick(14); return;  /* E992 RTS */
}

/* $03E983, entered with P=$20 via JSR */
void gen_03E983(void) {
    goto L_E983;
L_E983:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E983 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E984 TAX */
L_E985:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EFA0Du)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E985 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0398), (uint8_t)(uint8_t)g_cpu.C);  /* E989 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E98C INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000B);  /* E98D CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E985;  /* E990 BNE */
    recomp_tick(14); return;  /* E992 RTS */
}

/* $03E993, entered with P=$20 via JSR */
void gen_03E993(void) {
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

/* $03F92F, entered with P=$20 via JSR */
void gen_03F92F(void) {
    goto L_F92F;
L_F92F:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x40))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F92F ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpiy(0x31))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F931 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_sriy(0x53))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F933 EOR */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dpxi(0x33))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F935 EOR */
    recomp_tick(24); g_bit8(g_rd8(g_dpx(0x63)), false);  /* F937 BIT */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x40))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F939 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpiy(0x41))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F93B ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x55)))));  /* F93D ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sriy(0x22))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F93F AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpi(0x62))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F941 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x50))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F943 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpiy(0x51))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F945 ORA */
    recomp_tick(24); g_mvp(0x33, 0x21);  /* F947 MVP */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpi(0x11))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F94A ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x05)))));  /* F94C ADC */
    recomp_tick(14); return;  /* F94E RTS */
}

/* $03F93A, entered with P=$20 via JSR */
void gen_03F93A(void) {
    goto L_F93A;
L_F93A:;
    recomp_tick(14); return;  /* F93A RTI */
}

/* $03F93B, entered with P=$20 via JSR */
void gen_03F93B(void) {
    goto L_F93B;
L_F93B:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpiy(0x41))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F93B ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x55)))));  /* F93D ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sriy(0x22))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F93F AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpi(0x62))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F941 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x50))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F943 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpiy(0x51))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F945 ORA */
    recomp_tick(24); g_mvp(0x33, 0x21);  /* F947 MVP */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpi(0x11))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F94A ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x05)))));  /* F94C ADC */
    recomp_tick(14); return;  /* F94E RTS */
}

void gen_register_bank_03(void) {
    func_table_register_flags(0x038524, gen_038524, false);
    func_table_register_flags(0x03888D, gen_03888D, false);
    func_table_register_flags(0x038A6E, gen_038A6E, false);
    func_table_register_flags(0x038BA8, gen_038BA8, false);
    func_table_register_flags(0x038CD8, gen_038CD8, false);
    func_table_register_flags(0x038CE3, gen_038CE3, false);
    func_table_register_flags(0x038CED, gen_038CED, false);
    func_table_register_flags(0x038D46, gen_038D46, false);
    func_table_register_flags(0x038D7A, gen_038D7A, false);
    func_table_register_flags(0x038DBF, gen_038DBF, false);
    func_table_register_flags(0x038E1C, gen_038E1C, false);
    func_table_register_flags(0x038EC9, gen_038EC9, false);
    func_table_register_flags(0x038F87, gen_038F87, false);
    func_table_register_flags(0x038FE5, gen_038FE5, false);
    func_table_register_flags(0x039075, gen_039075, false);
    func_table_register_flags(0x03907A, gen_03907A, false);
    func_table_register_flags(0x039083, gen_039083, false);
    func_table_register_flags(0x0390C5, gen_0390C5, false);
    func_table_register_flags(0x03921D, gen_03921D, false);
    func_table_register_flags(0x039228, gen_039228, false);
    func_table_register_flags(0x03923A, gen_03923A, false);
    func_table_register_flags(0x039AAC, gen_039AAC, false);
    func_table_register_flags(0x03A04F, gen_03A04F, false);
    func_table_register_flags(0x03A30B, gen_03A30B, false);
    func_table_register_flags(0x03A352, gen_03A352, false);
    func_table_register_flags(0x03A435, gen_03A435, false);
    func_table_register_flags(0x03A494, gen_03A494, false);
    func_table_register_flags(0x03A4BD, gen_03A4BD, false);
    func_table_register_flags(0x03A4D3, gen_03A4D3, false);
    func_table_register_flags(0x03A4D9, gen_03A4D9, false);
    func_table_register_flags(0x03A504, gen_03A504, false);
    func_table_register_flags(0x03A664, gen_03A664, false);
    func_table_register_flags(0x03A671, gen_03A671, false);
    func_table_register_flags(0x03A883, gen_03A883, false);
    func_table_register_flags(0x03A8AB, gen_03A8AB, false);
    func_table_register_flags(0x03A9EC, gen_03A9EC, false);
    func_table_register_flags(0x03AA7B, gen_03AA7B, false);
    func_table_register_flags(0x03AAAB, gen_03AAAB, false);
    func_table_register_flags(0x03B2D8, gen_03B2D8, false);
    func_table_register_flags(0x03B2FD, gen_03B2FD, false);
    func_table_register_flags(0x03B341, gen_03B341, false);
    func_table_register_flags(0x03B53C, gen_03B53C, false);
    func_table_register_flags(0x03B5FE, gen_03B5FE, false);
    func_table_register_flags(0x03B684, gen_03B684, false);
    func_table_register_flags(0x03B994, gen_03B994, false);
    func_table_register_flags(0x03BAAA, gen_03BAAA, false);
    func_table_register_flags(0x03BC57, gen_03BC57, false);
    func_table_register_flags(0x03BEE1, gen_03BEE1, false);
    func_table_register_flags(0x03BFB8, gen_03BFB8, false);
    func_table_register_flags(0x03BFB9, gen_03BFB9, false);
    func_table_register_flags(0x03C194, gen_03C194, false);
    func_table_register_flags(0x03C24F, gen_03C24F, false);
    func_table_register_flags(0x03C265, gen_03C265, false);
    func_table_register_flags(0x03C27B, gen_03C27B, false);
    func_table_register_flags(0x03C330, gen_03C330, false);
    func_table_register_flags(0x03C341, gen_03C341, false);
    func_table_register_flags(0x03C56C, gen_03C56C, false);
    func_table_register_flags(0x03C5AE, gen_03C5AE, false);
    func_table_register_flags(0x03C5E6, gen_03C5E6, false);
    func_table_register_flags(0x03C5F5, gen_03C5F5, false);
    func_table_register_flags(0x03C616, gen_03C616, false);
    func_table_register_flags(0x03C63B, gen_03C63B, false);
    func_table_register_flags(0x03C7E7, gen_03C7E7, false);
    func_table_register_flags(0x03C800, gen_03C800, false);
    func_table_register_flags(0x03C8C9, gen_03C8C9, false);
    func_table_register_flags(0x03C907, gen_03C907, false);
    func_table_register_flags(0x03C9BC, gen_03C9BC, false);
    func_table_register_flags(0x03CD77, gen_03CD77, false);
    func_table_register_flags(0x03CF3D, gen_03CF3D, false);
    func_table_register_flags(0x03D065, gen_03D065, false);
    func_table_register_flags(0x03D186, gen_03D186, false);
    func_table_register_flags(0x03D26A, gen_03D26A, false);
    func_table_register_flags(0x03D294, gen_03D294, false);
    func_table_register_flags(0x03D37A, gen_03D37A, false);
    func_table_register_flags(0x03D3D7, gen_03D3D7, false);
    func_table_register_flags(0x03D41B, gen_03D41B, false);
    func_table_register_flags(0x03D4BC, gen_03D4BC, false);
    func_table_register_flags(0x03D5C3, gen_03D5C3, false);
    func_table_register_flags(0x03D5CF, gen_03D5CF, false);
    func_table_register_flags(0x03D61F, gen_03D61F, false);
    func_table_register_flags(0x03D908, gen_03D908, false);
    func_table_register_flags(0x03DC65, gen_03DC65, false);
    func_table_register_flags(0x03DC7C, gen_03DC7C, false);
    func_table_register_flags(0x03DDE1, gen_03DDE1, false);
    func_table_register_flags(0x03E098, gen_03E098, false);
    func_table_register_flags(0x03E0E5, gen_03E0E5, false);
    func_table_register_flags(0x03E2D1, gen_03E2D1, false);
    func_table_register_flags(0x03E423, gen_03E423, false);
    func_table_register_flags(0x03E425, gen_03E425, false);
    func_table_register_flags(0x03E94B, gen_03E94B, false);
    func_table_register_flags(0x03E96F, gen_03E96F, false);
    func_table_register_flags(0x03E97E, gen_03E97E, false);
    func_table_register_flags(0x03E983, gen_03E983, false);
    func_table_register_flags(0x03E993, gen_03E993, false);
    func_table_register_flags(0x03F92F, gen_03F92F, false);
    func_table_register_flags(0x03F93A, gen_03F93A, false);
    func_table_register_flags(0x03F93B, gen_03F93B, false);
}
