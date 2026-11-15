/* Bank $22 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 26 lifted, 304 unlifted in Bank $22 */
/* not lifted: $228000: RTS at $801A with 2 bytes still pushed */
/* not lifted: $228014: PLA at $8025 pulls below the entry stack (return-address trick) */
/* not lifted: $228052: WAI at $22:8070 */
/* not lifted: $228199: BRK at $22:81D5 */
/* not lifted: $2281DE: BRK at $22:81E6 */
/* not lifted: $2281F2: BRK at $22:8202 */
/* not lifted: $228207: WAI at $22:8251 */
/* not lifted: $22828A: WAI at $22:82F0 */
/* not lifted: $228335: BRK at $22:833A */
/* not lifted: $2283D7: RTS at $83F6 with 2 bytes still pushed */
/* not lifted: $2283E6: RTS at $83F6 with 2 bytes still pushed */
/* not lifted: $22840E: COP at $22:79A0 */
/* not lifted: $228434: BRK at $22:848F */
/* not lifted: $228505: BRK at $22:8505 */
/* not lifted: $22853A: BRK at $22:8572 */
/* not lifted: $228700: TCS at $8702 with an unknown stack value */
/* not lifted: $22872B: PLA at $8734 pulls below the entry stack (return-address trick) */
/* not lifted: $228757: PLD at $8765 pulls below the entry stack (return-address trick) */
/* not lifted: $2287BC: PLP at $87D1 pulls below the entry stack (return-address trick) */
/* not lifted: $2287E7: COP at $22:17CD */
/* not lifted: $22880D: COP at $22:17CD */
/* not lifted: $228931: tail jump at $896E with 2 bytes pushed */
/* not lifted: $22893E: tail jump at $896E with 2 bytes pushed */
/* not lifted: $22894E: tail jump at $896E with 2 bytes pushed */
/* not lifted: $2289DB: BRK at $22:89E5 */
/* not lifted: $228A08: BRK at $22:8A0E */
/* not lifted: $228A3A: COP at $22:8A47 */
/* not lifted: $228D4B: RTS at $8D6A with 1 bytes still pushed */
/* not lifted: $228E01: BRK at $22:8E41 */
/* not lifted: $228E04: BRK at $22:8E41 */
/* not lifted: $228E6D: BRK at $22:8E70 */
/* not lifted: $228E78: PLY at $8E8A pulls below the entry stack (return-address trick) */
/* not lifted: $228EA8: BRK at $22:8EB8 */
/* not lifted: $228ECD: RTL at $8F3E with 2 bytes still pushed */
/* not lifted: $228ED4: RTL at $8F3E with 2 bytes still pushed */
/* not lifted: $22954D: COP at $22:9556 */
/* not lifted: $22954F: COP at $22:9556 */
/* not lifted: $229556: COP at $22:9556 */
/* not lifted: $22955A: PLD at $955E pulls below the entry stack (return-address trick) */
/* not lifted: $229594: BRK at $22:95F7 */
/* not lifted: $2296DE: XCE at $22:96E9 */
/* not lifted: $229707: calls RAM trampoline/sub-8000 ($0A40FC): executes native on LakeSnes */
/* not lifted: $229723: PLD at $974D pulls below the entry stack (return-address trick) */
/* not lifted: $229738: PLD at $974D pulls below the entry stack (return-address trick) */
/* not lifted: $22973B: PLD at $974D pulls below the entry stack (return-address trick) */
/* not lifted: $2297D1: PLD at $97E5 pulls below the entry stack (return-address trick) */
/* not lifted: $2298C6: PLY at $9946 pulls below the entry stack (return-address trick) */
/* not lifted: $229943: PLY at $9946 pulls below the entry stack (return-address trick) */
/* not lifted: $229988: PLD at $99D1 pulls below the entry stack (return-address trick) */
/* not lifted: $2299B5: PLD at $99D1 pulls below the entry stack (return-address trick) */
/* not lifted: $2299BD: PLD at $99D1 pulls below the entry stack (return-address trick) */
/* not lifted: $229AA1: PLB at $9AAE pulls below the entry stack (return-address trick) */
/* not lifted: $229B08: XCE at $22:9B13 */
/* not lifted: $229B78: BRK at $22:9B90 */
/* not lifted: $229B88: BRK at $22:9B90 */
/* not lifted: $229B99: BRK at $22:9BA8 */
/* not lifted: $229BA8: BRK at $22:9BA8 */
/* not lifted: $229BB7: BRK at $22:9BE6 */
/* not lifted: $229C24: BRK at $22:9C2C */
/* not lifted: $229CB3: BRK at $22:9CC7 */
/* not lifted: $229D8A: TCS at $9DEE with an unknown stack value */
/* not lifted: $229E35: TCS at $9E7F with an unknown stack value */
/* not lifted: $229F1C: RTS at $9F33 with 2 bytes still pushed */
/* not lifted: $229FBC: COP at $22:9FC8 */
/* not lifted: $22A56C: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22A599: TCS at $A599 with an unknown stack value */
/* not lifted: $22A64C: WAI at $22:A66B */
/* not lifted: $22A666: WAI at $22:A66B */
/* not lifted: $22A6B5: PLD at $A6D6 pulls below the entry stack (return-address trick) */
/* not lifted: $22A6CF: PLD at $A6D6 pulls below the entry stack (return-address trick) */
/* not lifted: $22A6D4: PLD at $A6D6 pulls below the entry stack (return-address trick) */
/* not lifted: $22A6D9: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22A6DE: COP at $22:A6F1 */
/* not lifted: $22A724: BRK at $22:A758 */
/* not lifted: $22A7CD: RTS at $C011 with 1 bytes still pushed */
/* not lifted: $22A814: PLP at $A81C pulls below the entry stack (return-address trick) */
/* not lifted: $22A83F: WAI at $22:A843 */
/* not lifted: $22A86C: PLA at $A8BB pulls below the entry stack (return-address trick) */
/* not lifted: $22A8BC: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22A9B9: WAI at $22:A9C8 */
/* not lifted: $22A9E0: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22AA06: BRK at $22:AA2C */
/* not lifted: $22AA27: BRK at $22:AA2C */
/* not lifted: $22AA7B: BRK at $22:AA7F */
/* not lifted: $22AAA8: BRK at $22:AACA */
/* not lifted: $22AAAA: BRK at $22:AAB2 */
/* not lifted: $22AB9E: RTL at $ABD9 with 2 bytes still pushed */
/* not lifted: $22ABF5: TCS at $AC47 with an unknown stack value */
/* not lifted: $22AC2D: TCS at $AC47 with an unknown stack value */
/* not lifted: $22ACB2: WAI at $22:ACF2 */
/* not lifted: $22ACCA: WAI at $22:ACF2 */
/* not lifted: $22ACD1: WAI at $22:ACF2 */
/* not lifted: $22ACEC: WAI at $22:ACF2 */
/* not lifted: $22AD29: BRK at $22:AD95 */
/* not lifted: $22AD66: BRK at $22:AD95 */
/* not lifted: $22AD88: BRK at $22:AD95 */
/* not lifted: $22AE2A: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22AE4A: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22AE62: TCS at $AE8D with an unknown stack value */
/* not lifted: $22AE7A: TCS at $AE8D with an unknown stack value */
/* not lifted: $22AEA3: BRK at $22:34C5 */
/* not lifted: $22AEC9: BRK at $22:AEC9 */
/* not lifted: $22AED9: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22AEE1: COP at $22:AF0A */
/* not lifted: $22AFC9: BRK at $22:95F7 */
/* not lifted: $22B267: tail jump at $B27E with 2 bytes pushed */
/* not lifted: $22B26B: tail jump at $B27E with 2 bytes pushed */
/* not lifted: $22B28B: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22B297: BRK at $22:B2A0 */
/* not lifted: $22B2EC: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22B358: TCS at $B366 with an unknown stack value */
/* not lifted: $22B3B6: COP at $22:B3CC */
/* not lifted: $22B403: BRK at $22:B40F */
/* not lifted: $22B458: PLB at $B468 pulls below the entry stack (return-address trick) */
/* not lifted: $22B504: PLP at $B50F pulls below the entry stack (return-address trick) */
/* not lifted: $22B524: RTI at $B544 with 2 bytes still pushed */
/* not lifted: $22B568: BRK at $22:B5F2 */
/* not lifted: $22B610: BRK at $22:EA53 */
/* not lifted: $22B62D: COP at $22:B671 */
/* not lifted: $22B6A8: XCE at $22:B6AA */
/* not lifted: $22B744: BRK at $22:B759 */
/* not lifted: $22B7C8: BRK at $22:B800 */
/* not lifted: $22B813: BRK at $22:411F */
/* not lifted: $22B828: COP at $22:B83A */
/* not lifted: $22B8E7: PLA at $B918 pulls below the entry stack (return-address trick) */
/* not lifted: $22B900: BRK at $22:B900 */
/* not lifted: $22B904: PLA at $B918 pulls below the entry stack (return-address trick) */
/* not lifted: $22B9E9: PLP at $BA05 pulls below the entry stack (return-address trick) */
/* not lifted: $22B9ED: PLP at $BA05 pulls below the entry stack (return-address trick) */
/* not lifted: $22B9F9: PLP at $BA05 pulls below the entry stack (return-address trick) */
/* not lifted: $22BA1C: WAI at $22:BA32 */
/* not lifted: $22BB02: PLX at $BB86 pulls below the entry stack (return-address trick) */
/* not lifted: $22BB44: TCS at $BB44 with an unknown stack value */
/* not lifted: $22BC01: TCS at $BC86 with an unknown stack value */
/* not lifted: $22BC28: TCS at $BC86 with an unknown stack value */
/* not lifted: $22BC3A: TCS at $BC86 with an unknown stack value */
/* not lifted: $22BCCB: TCS at $BCCB with an unknown stack value */
/* not lifted: $22BD84: COP at $22:BD88 */
/* not lifted: $22BD9D: tail jump at $DFA3 with 2 bytes pushed */
/* not lifted: $22BDB3: TCS at $BDC6 with an unknown stack value */
/* not lifted: $22BDC5: tail jump at $DFA3 with 2 bytes pushed */
/* not lifted: $22BDF2: COP at $22:BE0D */
/* not lifted: $22BE09: COP at $22:BE0D */
/* not lifted: $22BE10: PLA at $BE10 pulls below the entry stack (return-address trick) */
/* not lifted: $22BE28: BRK at $22:BE2C */
/* not lifted: $22BE66: BRK at $22:BE72 */
/* not lifted: $22BE7B: BRK at $22:BE83 */
/* not lifted: $22BFFA: RTS at $C011 with 1 bytes still pushed */
/* not lifted: $22C13F: COP at $22:C148 */
/* not lifted: $22C220: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22C245: tail jump at $C288 with 1 bytes pushed */
/* not lifted: $22C2E8: BRK at $22:C317 */
/* not lifted: $22C3B3: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22C3D4: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22C426: COP at $22:C426 */
/* not lifted: $22C4AB: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22C4BE: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22C4E4: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22C5A1: COP at $22:C5A1 */
/* not lifted: $22C665: TCS at $C66B with an unknown stack value */
/* not lifted: $22C6B9: BRK at $22:C71D */
/* not lifted: $22C718: BRK at $22:C71D */
/* not lifted: $22C737: tail jump at $C788 with 2 bytes pushed */
/* not lifted: $22C74F: PLB at $0865 pulls below the entry stack (return-address trick) */
/* not lifted: $22C769: tail jump at $C788 with 2 bytes pushed */
/* not lifted: $22C8E7: tail jump at $DFA3 with 2 bytes pushed */
/* not lifted: $22C932: PLB at $C934 pulls below the entry stack (return-address trick) */
/* not lifted: $22C952: COP at $22:C962 */
/* not lifted: $22CBA0: COP at $22:CBA0 */
/* not lifted: $22D2D6: PLY at $D2FC pulls below the entry stack (return-address trick) */
/* not lifted: $22D2F1: PLY at $D2FC pulls below the entry stack (return-address trick) */
/* not lifted: $22D31E: BRK at $22:D330 */
/* not lifted: $22D34B: RTI at $D37A with 1 bytes still pushed */
/* not lifted: $22D37B: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22D388: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22D411: COP at $22:D41A */
/* not lifted: $22D495: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22D4F3: TXS at $22:D519 */
/* not lifted: $22D56B: BRK at $22:D580 */
/* not lifted: $22D631: BRK at $22:D637 */
/* not lifted: $22D650: RTI at $D696 with 1 bytes still pushed */
/* not lifted: $22D6E2: BRK at $22:D6EC */
/* not lifted: $22D6FC: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22D724: BRK at $22:1451 */
/* not lifted: $22D72D: PLB at $1463 pulls below the entry stack (return-address trick) */
/* not lifted: $22D75A: RTI at $D76A with 1 bytes still pushed */
/* not lifted: $22D766: RTI at $D76A with 1 bytes still pushed */
/* not lifted: $22D779: RTI at $D788 with 3 bytes still pushed */
/* not lifted: $22D77F: RTI at $D788 with 3 bytes still pushed */
/* not lifted: $22D790: COP at $22:D7DB */
/* not lifted: $22D7BC: COP at $22:D7DB */
/* not lifted: $22D7D6: COP at $22:D7DB */
/* not lifted: $22D852: COP at $22:D852 */
/* not lifted: $22D85A: XCE at $22:D86F */
/* not lifted: $22D861: BRK at $22:D872 */
/* not lifted: $22D918: BRK at $22:D918 */
/* not lifted: $22D999: PLD at $D9A8 pulls below the entry stack (return-address trick) */
/* not lifted: $22D99A: PLD at $D9A8 pulls below the entry stack (return-address trick) */
/* not lifted: $22D9B5: BRK at $22:D9C0 */
/* not lifted: $22D9C2: PLD at $DA21 pulls below the entry stack (return-address trick) */
/* not lifted: $22D9D1: BRK at $22:D9EB */
/* not lifted: $22DA07: PLD at $DA21 pulls below the entry stack (return-address trick) */
/* not lifted: $22DA0E: PLD at $DA21 pulls below the entry stack (return-address trick) */
/* not lifted: $22DA11: PLY at $EE36 pulls below the entry stack (return-address trick) */
/* not lifted: $22DA18: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22DA1F: COP at $22:DA2F */
/* not lifted: $22DA26: COP at $22:DA2F */
/* not lifted: $22DA2D: PLP at $DA2D pulls below the entry stack (return-address trick) */
/* not lifted: $22DA41: COP at $22:DA81 */
/* not lifted: $22DBF2: XCE at $22:DC09 */
/* not lifted: $22DDB6: TCS at $DDCF with an unknown stack value */
/* not lifted: $22E003: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22E06A: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22E1DA: $22:E1DA reached with two different M/X/stack states */
/* not lifted: $22E309: BRK at $22:E317 */
/* not lifted: $22E424: BRK at $22:E460 */
/* not lifted: $22E4B2: COP at $22:E4B2 */
/* not lifted: $22E549: $22:E5AC reached with two different M/X/stack states */
/* not lifted: $22E5F0: PLX at $E602 pulls below the entry stack (return-address trick) */
/* not lifted: $22E66F: TCS at $E6BD with an unknown stack value */
/* not lifted: $22E724: TCS at $E75C with an unknown stack value */
/* not lifted: $22E73C: TCS at $E75C with an unknown stack value */
/* not lifted: $22E774: XCE at $22:E7C2 */
/* not lifted: $22E791: XCE at $22:E7C2 */
/* not lifted: $22E79C: XCE at $22:E7C2 */
/* not lifted: $22E841: PLB at $1E1A pulls below the entry stack (return-address trick) */
/* not lifted: $22E845: PLB at $1E1A pulls below the entry stack (return-address trick) */
/* not lifted: $22E87D: RTI at $F7D8 with 1 bytes still pushed */
/* not lifted: $22E8A7: WAI at $22:E8AB */
/* not lifted: $22E8B5: TCS at $E8BA with an unknown stack value */
/* not lifted: $22E8CE: RTI at $F8A7 with 1 bytes still pushed */
/* not lifted: $22E909: BRK at $22:E91F */
/* not lifted: $22E962: TCS at $E986 with an unknown stack value */
/* not lifted: $22E968: TCS at $E986 with an unknown stack value */
/* not lifted: $22E96E: STP at $22:E98B */
/* not lifted: $22E9B2: PLP at $E9E2 pulls below the entry stack (return-address trick) */
/* not lifted: $22E9E1: PLP at $E9E2 pulls below the entry stack (return-address trick) */
/* not lifted: $22EAAF: BRK at $22:EACF */
/* not lifted: $22EADB: tail jump at $096E with 5 bytes pushed */
/* not lifted: $22EB20: RTS at $EB70 with 4 bytes still pushed */
/* not lifted: $22EB7A: COP at $22:4748 */
/* not lifted: $22EBD3: PLB at $9E1A pulls below the entry stack (return-address trick) */
/* not lifted: $22EBF1: WAI at $22:435C */
/* not lifted: $22EC0F: COP at $22:EC44 */
/* not lifted: $22EC2D: COP at $22:EC44 */
/* not lifted: $22EC3B: COP at $22:EC44 */
/* not lifted: $22EC5C: WAI at $22:EC8D */
/* not lifted: $22EC69: WAI at $22:EC8D */
/* not lifted: $22EC8A: BRK at $22:ECA1 */
/* not lifted: $22EC90: BRK at $22:ECA1 */
/* not lifted: $22EC97: BRK at $22:ECA1 */
/* not lifted: $22EDF8: PLY at $EE36 pulls below the entry stack (return-address trick) */
/* not lifted: $22F004: RTS at $F035 with 2 bytes still pushed */
/* not lifted: $22F1E8: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22F1F5: PLA at $F1FB pulls below the entry stack (return-address trick) */
/* not lifted: $22F223: PLB at $F240 pulls below the entry stack (return-address trick) */
/* not lifted: $22F251: COP at $22:F266 */
/* not lifted: $22F28A: STP at $22:F28F */
/* not lifted: $22F2A2: WAI at $22:F2C7 */
/* not lifted: $22F2BD: WAI at $22:F2C7 */
/* not lifted: $22F2CD: XCE at $22:F2CE */
/* not lifted: $22F2DD: BRK at $22:F2F6 */
/* not lifted: $22F2ED: BRK at $22:F2F6 */
/* not lifted: $22F302: PLP at $F30B pulls below the entry stack (return-address trick) */
/* not lifted: $22F34D: PLA at $F38A pulls below the entry stack (return-address trick) */
/* not lifted: $22F369: RTL at $F38B with 1 bytes still pushed */
/* not lifted: $22F417: BRK at $22:F453 */
/* not lifted: $22F42D: BRK at $22:F453 */
/* not lifted: $22F469: STP at $22:4C63 */
/* not lifted: $22F479: PLP at $F49B without a matching PHP */
/* not lifted: $22F483: PLP at $F49B pulls below the entry stack (return-address trick) */
/* not lifted: $22F4BE: calls unlifted target 0x47A505: executes native on LakeSnes */
/* not lifted: $22F4DA: BRK at $22:F51C */
/* not lifted: $22F4F6: BRK at $22:F51C */
/* not lifted: $22F5C2: BRK at $22:F5D2 */
/* not lifted: $22F5E0: BRK at $22:F5D2 */
/* not lifted: $22F6FC: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $22F70F: PLD at $F73A pulls below the entry stack (return-address trick) */
/* not lifted: $22F7A7: BRK at $22:F7EF */
/* not lifted: $22F817: WAI at $22:F83C */
/* not lifted: $22F853: BRK at $22:F85F */
/* not lifted: $22F880: WAI at $22:F880 */
/* not lifted: $22F8C0: BRK at $22:F8E7 */
/* not lifted: $22F8E4: BRK at $22:F8E7 */
/* not lifted: $22F8EF: TCS at $F8F4 with an unknown stack value */
/* not lifted: $22F905: COP at $22:F906 */
/* not lifted: $22F936: XCE at $22:F95C */
/* not lifted: $22F965: COP at $22:F9A0 */
/* not lifted: $22F9B2: PLA at $F9C0 pulls below the entry stack (return-address trick) */
/* not lifted: $22F9BD: PLA at $F9C0 pulls below the entry stack (return-address trick) */
/* not lifted: $22F9F0: BRK at $22:F807 */
/* not lifted: $22FB1D: XCE at $22:FB31 */
/* not lifted: $22FB1F: XCE at $22:FB31 */
/* not lifted: $22FBDE: tail jump at $FBEC with 2 bytes pushed */
/* not lifted: $22FC29: PLX at $FC30 pulls below the entry stack (return-address trick) */
/* not lifted: $22FC49: XCE at $22:FCB5 */
/* not lifted: $22FC6E: XCE at $22:FCB5 */
/* not lifted: $22FC90: PLA at $FCA7 pulls below the entry stack (return-address trick) */
/* not lifted: $22FCB4: XCE at $22:FCB5 */
/* not lifted: $22FCBF: tail jump at $FD52 with 3 bytes pushed */
/* not lifted: $22FCD5: tail jump at $FD52 with 2 bytes pushed */
/* not lifted: $22FD17: tail jump at $FD52 with 2 bytes pushed */
/* not lifted: $22FD26: PLY at $FD33 pulls below the entry stack (return-address trick) */
/* not lifted: $22FD2B: PLY at $FD33 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2285FB, entered with P=$20 via JSR */
void gen_2285FB(void) {
    goto L_85FB;
L_85FB:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpxi(0x62)))));  /* 85FB ADC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0xFD)))));  /* 85FD ADC */
    recomp_tick(14); return;  /* 85FF RTS */
}

/* $22867A, entered with P=$20 via JSR */
void gen_22867A(void) {
    goto L_867A;
L_867A:;
    recomp_tick(40); { uint32_t _e = g_absx(0x4DFC); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* 867A ROL */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x3526);  /* 867D CPY */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0314)));  /* 8680 CMP */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x46))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8683 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x686362u)))));  /* 8685 ADC */
    recomp_tick(14); return;  /* 8689 RTL */
}

/* $228EC6, entered with P=$20 via JSR */
void gen_228EC6(void) {
    goto L_8EC6;
L_8EC6:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpiy(0x1E)))));  /* 8EC6 ADC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_longx(0x00FF7Au))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EC8 AND */
    recomp_tick(24); g_wr8(g_dpil(0xC0), (uint8_t)(uint8_t)g_cpu.C);  /* 8ECC STA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x03))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8ECE ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpx(0xAF))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8ED0 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xC0FF00u)))));  /* 8ED2 ADC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_longx(0xF9367Eu))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8ED6 ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0xFC)))));  /* 8EDA ADC */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xBF6FC0u)))));  /* 8EDC SBC */
    recomp_tick(14); g_cpu.DP = g_cpu.C; g_nz16(g_cpu.DP);  /* 8EE0 TCD */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0xC0FF)); g_cpu.X = _v; g_nz16(_v); }  /* 8EE1 LDX */
    recomp_tick(14); g_cpu.flag_D = true;  /* 8EE4 SED */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(0xBA9E7Eu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EE5 AND */
    recomp_tick(14); ;  /* 8EE9 NOP */
    recomp_tick(16); goto L_8F1D;  /* 8EEA BRA */
L_8F1D:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x3274C0u)))));  /* 8F1D SBC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_longx(0xB2053Eu))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F21 AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x3C))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F25 ORA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_absx(0xFFB7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F27 EOR */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0B03);  /* 8F2A CPY */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8F62;  /* 8F2D BMI */
    recomp_tick(40); { uint32_t _e = g_absx(0x8FBF); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* 8F2F ASL */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xC0FF1Au)))));  /* 8F32 ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x26))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F36 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x5D0706u)))));  /* 8F38 SBC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0x1B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F3C LDA */
    recomp_tick(14); return;  /* 8F3E RTL */
L_8F62:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x14BE80u)))));  /* 8F62 SBC */
    recomp_tick(14); return;  /* 8F66 RTI */
}

/* $228EE9, entered with P=$20 via JSR */
void gen_228EE9(void) {
    goto L_8EE9;
L_8EE9:;
    recomp_tick(14); ;  /* 8EE9 NOP */
    recomp_tick(16); goto L_8F1D;  /* 8EEA BRA */
L_8F1D:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x3274C0u)))));  /* 8F1D SBC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_longx(0xB2053Eu))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F21 AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x3C))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F25 ORA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_absx(0xFFB7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F27 EOR */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0B03);  /* 8F2A CPY */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8F62;  /* 8F2D BMI */
    recomp_tick(40); { uint32_t _e = g_absx(0x8FBF); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* 8F2F ASL */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xC0FF1Au)))));  /* 8F32 ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x26))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F36 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x5D0706u)))));  /* 8F38 SBC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0x1B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F3C LDA */
    recomp_tick(14); return;  /* 8F3E RTL */
L_8F62:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x14BE80u)))));  /* 8F62 SBC */
    recomp_tick(14); return;  /* 8F66 RTI */
}

/* $22952B, entered with P=$10 via JSR */
void gen_22952B(void) {
    goto L_952B;
L_952B:;
    recomp_tick(16); if (g_cpu.flag_V) goto L_953C;  /* 952B BVS */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0x77)); g_cpu.Y = _v; g_nz8(_v); }  /* 952D LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.Y, 0x1E);  /* 952F CPY */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x1D1905u))));  /* 9531 ADC */
    recomp_tick(32); g_wr16(g_dpx(0x66), 0);  /* 9535 STZ */
    recomp_tick(56); { uint32_t _e = g_abs(0xA74A); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* 9537 ASL */
    recomp_tick(48); { uint32_t _e = g_dpx(0x64); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 953A ROR */
L_953C:;
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dpil(0x06))));  /* 953C ADC */
    recomp_tick(16); ;  /* 953E WDM */
    recomp_tick(14); return;  /* 9540 RTI */
}

/* $229D3D, entered with P=$20 via JSR */
void gen_229D3D(void) {
    goto L_9D3D;
L_9D3D:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x03))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D3D ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x0F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D3F ORA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7FFFF4u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D41 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0xEF)))));  /* 9D45 ADC */
    recomp_tick(32); { uint32_t _e = g_dp(0x27); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* 9D47 ROL */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dpxi(0x74)));  /* 9D49 CMP */
    recomp_tick(40); { uint32_t _e = g_abs(0x0113); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 9D4B TRB */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpil(0x01)))));  /* 9D4E SBC */
    recomp_tick(32); g_bit8(g_rd8(g_abs(0xFF23)), false);  /* 9D50 BIT */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(0x28CC1Eu));  /* 9D53 CMP */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x29); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D57 AND */
    recomp_tick(14); g_cpu.flag_D = true;  /* 9D59 SED */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x94))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5A ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x42))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5C ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x82))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5E ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x03)))));  /* 9D60 ADC */
    recomp_tick(24); g_wr8(g_dpx(0x03), 0);  /* 9D62 STZ */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0xF4))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D64 ORA */
    recomp_tick(40); { uint32_t _e = g_absx(0x5EFF); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9D66 INC */
    recomp_tick(40); g_wr16(g_abs(0x2625), (uint16_t)g_cpu.X);  /* 9D69 STX */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x12)));  /* 9D6C CMP */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absx(0x7674))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D6E ORA */
    recomp_tick(32); g_wr16(g_dp(0x27), (uint16_t)g_cpu.X);  /* 9D71 STX */
    recomp_tick(14); return;  /* 9D73 RTI */
}

/* $229D58, entered with P=$20 via JSR */
void gen_229D58(void) {
    goto L_9D58;
L_9D58:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xF8); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D58 AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x94))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5A ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x42))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5C ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x82))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5E ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x03)))));  /* 9D60 ADC */
    recomp_tick(24); g_wr8(g_dpx(0x03), 0);  /* 9D62 STZ */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0xF4))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D64 ORA */
    recomp_tick(40); { uint32_t _e = g_absx(0x5EFF); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9D66 INC */
    recomp_tick(40); g_wr16(g_abs(0x2625), (uint16_t)g_cpu.X);  /* 9D69 STX */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x12)));  /* 9D6C CMP */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absx(0x7674))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D6E ORA */
    recomp_tick(32); g_wr16(g_dp(0x27), (uint16_t)g_cpu.X);  /* 9D71 STX */
    recomp_tick(14); return;  /* 9D73 RTI */
}

/* $22A024, entered with P=$20 via JSR */
void gen_22A024(void) {
    goto L_A024;
L_A024:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x13)));  /* A024 CMP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* A026 TYX */
    recomp_tick(32); { uint32_t _e = g_dp(0x74); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* A027 TRB */
    recomp_tick(14); return;  /* A029 RTS */
}

/* $22AAFF, entered with P=$20 via JSR */
void gen_22AAFF(void) {
    goto L_AAFF;
L_AAFF:;
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0x65)))));  /* AAFF SBC */
    recomp_tick(32); { uint32_t _e = g_dp(0x67); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* AB01 ROR */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(0x0374E8u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AB03 ORA */
    recomp_tick(14); return;  /* AB07 RTS */
}

/* $22ADC2, entered with P=$20 via JSR */
void gen_22ADC2(void) {
    goto L_ADC2;
L_ADC2:;
    recomp_tick(40); { uint8_t _v = g_rd8(0x06FC04u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ADC2 LDA */
    recomp_tick(40); { uint32_t _e = g_abs(0x042A); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* ADC6 ROR */
    recomp_tick(14); g_cpu.C = g_cpu.S; g_nz16(g_cpu.C);  /* ADC9 TSC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x07)))));  /* ADCA ADC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpi(0x56)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ADCC LDA */
    recomp_tick(32); { uint32_t _e = g_dp(0xBC); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* ADCE TSB */
    recomp_tick(14); return;  /* ADD0 RTI */
}

/* $22B40E, entered with P=$20 via JSR */
void gen_22B40E(void) {
    goto L_B40E;
L_B40E:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x00); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B40E ORA */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_longx(0x9A3FF0u))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B410 AND */
    recomp_tick(40); { uint32_t _e = g_abs(0x18FE); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* B414 ASL */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* B417 PHA */
    recomp_tick(14); g_cpu.flag_C = false;  /* B418 CLC */
    recomp_tick(16); ;  /* B419 WDM */
    recomp_tick(24); g_wr8(g_dpi(0x93), (uint8_t)(uint8_t)g_cpu.C);  /* B41B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B41D TAY */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x9594A9u)))));  /* B41E SBC */
    recomp_tick(32); g_wr16(g_dpy(0x0A), (uint16_t)g_cpu.X);  /* B422 STX */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* B424 ASL */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dpil(0xEC)));  /* B425 CMP */
    recomp_tick(14); g_cpu.C = g_cpu.S; g_nz16(g_cpu.C);  /* B427 TSC */
    recomp_tick(40); { uint32_t _e = g_absx(0x0EF2); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B428 INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpi(0x56))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B42B AND */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B42D PLA */
    recomp_tick(14); return;  /* B42E RTL */
}

/* $22B786, entered with P=$00 via JSR */
void gen_22B786(void) {
    goto L_B786;
L_B786:;
    recomp_tick(14); return;  /* B786 RTI */
}

/* $22BAEF, entered with P=$00 via JSR */
void gen_22BAEF(void) {
    goto L_BAEF;
L_BAEF:;
    recomp_tick(14); g_cpu.flag_C = false;  /* BAEF CLC */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_longx(0x717003u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAF0 ORA */
    recomp_tick(14); return;  /* BAF4 RTL */
}

/* $22BDCA, entered with P=$20 via JSR */
void gen_22BDCA(void) {
    goto L_BDCA;
L_BDCA:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x32))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BDCA ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpiy(0x14))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BDCC AND */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BDCE LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dpxi(0x03)));  /* BDD1 CMP */
    recomp_tick(40); { uint32_t _e = g_abs(0xF2EF); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* BDD3 TSB */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0xEBFB)));  /* BDD6 CPX */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0xF373)));  /* BDD9 CPX */
    recomp_tick(40); { uint32_t _e = g_absx(0xF20F); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BDDC INC */
    recomp_tick(32); { uint32_t _e = g_dp(0xEF); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* BDDF TSB */
    recomp_tick(32); { uint32_t _e = g_dp(0x74); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* BDE1 TRB */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x16)))));  /* BDE3 ADC */
    recomp_tick(40); { uint32_t _e = g_absx(0x131C); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* BDE5 ROR */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BDE8 TXA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absx(0x1688))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BDE9 ORA */
    recomp_tick(40); { uint32_t _e = g_abs(0x051A); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* BDEC TRB */
    recomp_tick(14); return;  /* BDEF RTI */
}

/* $22D191, entered with P=$30 via JSR */
void gen_22D191(void) {
    goto L_D191;
L_D191:;
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_absy(0xF517)))));  /* D191 ADC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x44))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D194 ORA */
    recomp_tick(32); { uint32_t _e = g_dp(0x71); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D196 ROL */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dp(0x01))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D198 EOR */
    recomp_tick(24); g_mvp(0xF0, 0x26);  /* D19A MVP */
    recomp_tick(14); return;  /* D19D RTI */
}

/* $22D293, entered with P=$30 via JSR */
void gen_22D293(void) {
    goto L_D293;
L_D293:;
    recomp_tick(14); return;  /* D293 RTL */
}

/* $22D747, entered with P=$20 via JSR */
void gen_22D747(void) {
    goto L_D747;
L_D747:;
    recomp_tick(40); { uint32_t _e = g_abs(0x4A88); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* D747 TSB */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D74A LSR */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dp(0x1C))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D74B AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dpx(0x52))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D74D EOR */
    recomp_tick(14); return;  /* D74F RTI */
}

/* $22D89A, entered with P=$20 via JSR */
void gen_22D89A(void) {
    goto L_D89A;
L_D873:;
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpil(0xFF)))));  /* D873 SBC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpil(0xC0))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D875 AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dpil(0xFE))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D877 EOR */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0xC3))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D879 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpxi(0x01))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D87B ORA */
    recomp_tick(14); return;  /* D87D RTI */
L_D89A:;
    recomp_tick(16); goto L_D873;  /* D89A BRA */
}

/* $22DA34, entered with P=$20 via JSR */
void gen_22DA34(void) {
    goto L_DA34;
L_DA34:;
    recomp_tick(24); g_mvp(0x0D, 0xD3);  /* DA34 MVP */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x8F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DA37 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpxi(0x40))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DA39 ORA */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(0xB333BFu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DA3B ORA */
    recomp_tick(14); return;  /* DA3F RTS */
}

/* $22DA3C, entered with P=$20 via JSR */
void gen_22DA3C(void) {
    goto L_DA3C;
L_DA3C:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x60B333u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DA3C LDA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x143E80u)))));  /* DA40 SBC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(0xAF4BBFu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DA44 AND */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x7CA0C0u)))));  /* DA48 SBC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0214); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* DA4C ROL */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x4D))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DA4F ORA */
    recomp_tick(24); g_bit8(g_rd8(g_dp(0x27)), false);  /* DA51 BIT */
    recomp_tick(40); { uint32_t _e = g_absx(0xC0FF); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* DA53 ROL */
    recomp_tick(14); return;  /* DA56 RTI */
}

/* $22E6F8, entered with P=$30 via JSR */
void gen_22E6F8(void) {
    goto L_E6F8;
L_E6F8:;
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_absx(0x845B)));  /* E6F8 CMP */
    recomp_tick(32); g_wr8(g_abs(0x9926), (uint8_t)g_cpu.X);  /* E6FB STX */
    recomp_tick(24); goto L_FE8E;  /* E6FE BRL */
L_FE8E:;
    recomp_tick(32); { uint32_t _e = g_dpx(0x74); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* FE8E ROR */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x82))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FE90 ORA */
    recomp_tick(24); g_wr8(g_sr(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* FE92 STA */
    recomp_tick(24); g_wr8(g_dpx(0x4F), (uint8_t)(uint8_t)g_cpu.C);  /* FE94 STA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0B4B); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* FE96 TSB */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0xBF))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FE99 ORA */
    recomp_tick(14); g_cpu.flag_C = false;  /* FE9B CLC */
    recomp_tick(32); { uint32_t _e = g_dpx(0x7F); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* FE9C ASL */
    recomp_tick(24); g_bit8(g_rd8(g_dp(0x17)), false);  /* FE9E BIT */
    recomp_tick(14); return;  /* FEA0 RTI */
}

/* $22EAFA, entered with P=$30 via JSR */
void gen_22EAFA(void) {
    goto L_EAFA;
L_EAFA:;
    recomp_tick(14); return;  /* EAFA RTL */
}

/* $22EBAA, entered with P=$30 via JSR */
void gen_22EBAA(void) {
    goto L_EBAA;
L_EBAA:;
    recomp_tick(14); return;  /* EBAA RTI */
}

/* $22F1FA, entered with P=$20 via JSR */
void gen_22F1FA(void) {
    goto L_F1FA;
L_F1FA:;
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(0xBA0668u))));  /* F1FA ADC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0x47)))));  /* F1FE ADC */
    recomp_tick(32); g_bit8(g_rd8(g_absx(0xF426)), false);  /* F200 BIT */
    recomp_tick(32); { uint32_t _e = g_dp(0x22); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* F203 ROL */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpiy(0x82))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F205 AND */
    recomp_tick(24); g_wr8(g_sr(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* F207 STA */
    recomp_tick(24); { uint16_t _v = 0x3406; g_cpu.X = _v; g_nz16(_v); }  /* F209 LDX */
    recomp_tick(32); { uint32_t _e = g_dpx(0x0A); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* F20C ROL */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x22)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F20E LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpx(0xF6)))));  /* F210 SBC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F212 ASL */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_absy(0x6766)));  /* F213 CMP */
    recomp_tick(32); { uint32_t _e = g_dp(0x98); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* F216 TSB */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x6A)))));  /* F218 ADC */
    recomp_tick(14); return;  /* F21A RTL */
}

/* $22F6D0, entered with P=$10 via JSR */
void gen_22F6D0(void) {
    goto L_F6D0;
L_F6D0:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0xC2))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F6D0 ORA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_longx(0xE0C2C1u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F6D2 ORA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0xE1))));  /* F6D6 SBC */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0xEE)));  /* F6D8 CMP */
    recomp_tick(14); return;  /* F6DA RTI */
}

/* $22F893, entered with P=$30 via JSR */
void gen_22F893(void) {
    goto L_F893;
L_F893:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x68))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F893 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpx(0xF1))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F895 ORA */
    recomp_tick(16); goto L_F89D;  /* F897 BRA */
L_F89D:;
    recomp_tick(32); { uint32_t _e = g_dpx(0x79); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* F89D ASL */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absx(0x1848))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F89F ORA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_absx(0x6817))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F8A2 AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0xF1))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F8A5 ORA */
    recomp_tick(14); return;  /* F8A7 RTI */
}

void gen_register_bank_22(void) {
    func_table_register_flags(0x2285FB, gen_2285FB, false);
    func_table_register_flags(0x22867A, gen_22867A, false);
    func_table_register_flags(0x228EC6, gen_228EC6, false);
    func_table_register_flags(0x228EE9, gen_228EE9, false);
    func_table_register_flags(0x22952B, gen_22952B, false);
    func_table_register_flags(0x229D3D, gen_229D3D, false);
    func_table_register_flags(0x229D58, gen_229D58, false);
    func_table_register_flags(0x22A024, gen_22A024, false);
    func_table_register_flags(0x22AAFF, gen_22AAFF, false);
    func_table_register_flags(0x22ADC2, gen_22ADC2, false);
    func_table_register_flags(0x22B40E, gen_22B40E, false);
    func_table_register_flags(0x22B786, gen_22B786, false);
    func_table_register_flags(0x22BAEF, gen_22BAEF, false);
    func_table_register_flags(0x22BDCA, gen_22BDCA, false);
    func_table_register_flags(0x22D191, gen_22D191, false);
    func_table_register_flags(0x22D293, gen_22D293, false);
    func_table_register_flags(0x22D747, gen_22D747, false);
    func_table_register_flags(0x22D89A, gen_22D89A, false);
    func_table_register_flags(0x22DA34, gen_22DA34, false);
    func_table_register_flags(0x22DA3C, gen_22DA3C, false);
    func_table_register_flags(0x22E6F8, gen_22E6F8, false);
    func_table_register_flags(0x22EAFA, gen_22EAFA, false);
    func_table_register_flags(0x22EBAA, gen_22EBAA, false);
    func_table_register_flags(0x22F1FA, gen_22F1FA, false);
    func_table_register_flags(0x22F6D0, gen_22F6D0, false);
    func_table_register_flags(0x22F893, gen_22F893, false);
}
