/* Bank $00 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 47 lifted, 272 unlifted in Bank $00 */
/* not lifted: $008000: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008009: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00809E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0080C6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008146: calls unlifted target 0x0083E1: executes native on LakeSnes */
/* not lifted: $0082AA: BRK at $00:82A5 */
/* not lifted: $008386: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083BE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083C8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083D5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083E1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083F2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00844E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008470: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0084A2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0085B7: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00867B: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $008782: calls unlifted target 0x0085B7: executes native on LakeSnes */
/* not lifted: $00889F: BRK at $00:88B8 */
/* not lifted: $008AA2: STP at $00:8AC3 */
/* not lifted: $008AAA: STP at $00:8AC3 */
/* not lifted: $008BAA: BRK at $00:8BCD */
/* not lifted: $008D6D: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $008D9E: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $0090B0: BRK at $00:90B0 */
/* not lifted: $0096C8: BRK at $00:96C8 */
/* not lifted: $0096FB: BRK at $00:96FE */
/* not lifted: $009795: COP at $00:97FE */
/* not lifted: $00981D: COP at $00:9824 */
/* not lifted: $009843: WAI at $00:987D */
/* not lifted: $009893: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009A6C: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $009A95: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B03: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B04: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B21: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B45: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B58: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B5F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BC2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BC5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BC8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BCB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BCE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BD1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BD4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BD7: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BDA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BDD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE9: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BEC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BEF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BF2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BF5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BF8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BFB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BFE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C01: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C04: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C07: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C0A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C0D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C10: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C13: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C16: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C19: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C1C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C1F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C22: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C23: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C6C: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $009CC4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E7B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E86: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E87: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E93: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E9B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EA2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EAA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EB6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EC2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009ED1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EE0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F0F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F1E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F3C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F6B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F8B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009FBD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A00D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A024: $00:A0B3 reached with two different M/X/stack states */
/* not lifted: $00A088: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A0E3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A0EC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A0F2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A113: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A125: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A18C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A22A: BRK at $00:A22A */
/* not lifted: $00A28A: BRK at $00:A291 */
/* not lifted: $00A2A2: $00:A2AE reached with two different M/X/stack states */
/* not lifted: $00A2AA: $00:A2AA reached with two different M/X/stack states */
/* not lifted: $00A2BD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A2CA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A2DC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A2EE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A30A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A44A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A456: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A468: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A5B7: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $00A5C4: RTS at $A6B8 with 1 bytes still pushed */
/* not lifted: $00A5D6: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $00A5E8: RTS at $A6B8 with 1 bytes still pushed */
/* not lifted: $00A604: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $00A6D1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A6DF: calls unlifted target 0x00A6F8: executes native on LakeSnes */
/* not lifted: $00A6F8: TXS at $00:A739 */
/* not lifted: $00A773: calls unlifted target 0x00A789: executes native on LakeSnes */
/* not lifted: $00A789: TXS at $00:A7D3 */
/* not lifted: $00A80D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A82B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A831: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A83B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A83F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A845: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A862: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A868: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A87B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A888: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A88C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A898: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A8A2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A8AA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A8AF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A909: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00A940: calls unlifted target 0x00F5D2: executes native on LakeSnes */
/* not lifted: $00AA0C: BRK at $00:AA0C */
/* not lifted: $00AA1F: calls unlifted target 0x00DED6: executes native on LakeSnes */
/* not lifted: $00AA2A: BRK at $00:AA2E */
/* not lifted: $00AA5F: PLA at $AA69 pulls below the entry stack (return-address trick) */
/* not lifted: $00AA60: BRK at $00:AA7A */
/* not lifted: $00AA88: BRK at $00:AA95 */
/* not lifted: $00AA8A: BRK at $00:AA95 */
/* not lifted: $00AA9D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAAA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAAB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAEA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AB01: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ACD3: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00AEAE: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00AEF4: calls unlifted target 0x00B7C0: executes native on LakeSnes */
/* not lifted: $00AF03: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AF33: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AF5C: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00AFBA: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00B020: BRK at $00:B022 */
/* not lifted: $00B041: calls unlifted target 0x00DF16: executes native on LakeSnes */
/* not lifted: $00B16F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00B1E0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00B282: calls unlifted target 0x00CB22: executes native on LakeSnes */
/* not lifted: $00B457: calls unlifted target 0x00C774: executes native on LakeSnes */
/* not lifted: $00B47C: calls unlifted target 0x00B6A8: executes native on LakeSnes */
/* not lifted: $00B4C6: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00B542: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00B56E: BRK at $00:B56F */
/* not lifted: $00B590: calls unlifted target 0x00B64A: executes native on LakeSnes */
/* not lifted: $00B5FD: calls unlifted target 0x00B64A: executes native on LakeSnes */
/* not lifted: $00B64A: calls unlifted target 0x00867B: executes native on LakeSnes */
/* not lifted: $00B6A8: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00B77A: calls unlifted target 0x00DF16: executes native on LakeSnes */
/* not lifted: $00B7C0: $00:B83F reached with two different M/X/stack states */
/* not lifted: $00B8B3: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00B8FA: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00B931: calls unlifted target 0x00C980: executes native on LakeSnes */
/* not lifted: $00B97D: calls unlifted target 0x00CC03: executes native on LakeSnes */
/* not lifted: $00B9AB: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00BA22: PLX at $BA17 pulls below the entry stack (return-address trick) */
/* not lifted: $00BACA: COP at $00:BACA */
/* not lifted: $00BB69: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00BB84: calls unlifted target 0x0085B7: executes native on LakeSnes */
/* not lifted: $00BCAA: calls unlifted target 0x00BDAA: executes native on LakeSnes */
/* not lifted: $00BDAA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $00C0BC: BRK at $00:C0CC */
/* not lifted: $00C11B: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $00C48C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00C50F: BRK at $00:C54E */
/* not lifted: $00C558: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00C5C5: calls unlifted target 0x00C5EC: executes native on LakeSnes */
/* not lifted: $00C5EC: calls unlifted target 0x00A18C: executes native on LakeSnes */
/* not lifted: $00C614: calls unlifted target 0x00A18C: executes native on LakeSnes */
/* not lifted: $00C619: BRK at $00:C623 */
/* not lifted: $00C635: calls unlifted target 0x009A6C: executes native on LakeSnes */
/* not lifted: $00C6A7: calls unlifted target 0x009A6C: executes native on LakeSnes */
/* not lifted: $00C774: calls unlifted target 0x008D9E: executes native on LakeSnes */
/* not lifted: $00C980: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00C9E8: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CADA: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CB22: calls unlifted target 0x00889F: executes native on LakeSnes */
/* not lifted: $00CBAE: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CC03: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CF3A: calls unlifted target 0x009893: executes native on LakeSnes */
/* not lifted: $00D386: calls unlifted target 0x00D394: executes native on LakeSnes */
/* not lifted: $00D394: calls unlifted target 0x00D4BD: executes native on LakeSnes */
/* not lifted: $00D4BD: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00D620: BRK at $00:D62D */
/* not lifted: $00D6A1: calls unlifted target 0x009893: executes native on LakeSnes */
/* not lifted: $00D776: calls unlifted target 0x00A0EC: executes native on LakeSnes */
/* not lifted: $00D7C5: calls unlifted target 0x00F5D2: executes native on LakeSnes */
/* not lifted: $00D7FC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D867: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D95B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D979: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00DBAF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DC89: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DDB2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DE0D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DEBE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DED6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DEE6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DF16: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DF4C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DF54: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00DFF5: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00E01A: $00:E128 reached with two different M/X/stack states */
/* not lifted: $00E12B: calls unlifted target 0x00E3CD: executes native on LakeSnes */
/* not lifted: $00E181: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00E228: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00E235: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00E240: calls unlifted target 0x00E181: executes native on LakeSnes */
/* not lifted: $00E29D: RTS at $E2AD with 2 bytes still pushed */
/* not lifted: $00E2AA: RTS at $E2AD with 1 bytes still pushed */
/* not lifted: $00E3CD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00E538: PLX at $E567 pulls below the entry stack (return-address trick) */
/* not lifted: $00E56C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00EA2A: $00:A5A8 reached with two different M/X/stack states */
/* not lifted: $00EAAA: BRK at $00:EAB6 */
/* not lifted: $00EB50: $00:A5A8 reached with two different M/X/stack states */
/* not lifted: $00EC23: calls unlifted target 0x00ECA6: executes native on LakeSnes */
/* not lifted: $00EC7F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00EC97: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ECA6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ECB5: calls unlifted target 0x00ECA6: executes native on LakeSnes */
/* not lifted: $00EDA8: $00:A5A8 reached with two different M/X/stack states */
/* not lifted: $00EFEF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F00F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F087: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F122: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F1CB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F1F4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F24E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F26C: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $00F3E0: calls unlifted target 0x009893: executes native on LakeSnes */
/* not lifted: $00F423: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F46D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F5D2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F5E6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F65E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F790: $00:F7FC reached with two different M/X/stack states */
/* not lifted: $00F801: calls unlifted target 0x00F87D: executes native on LakeSnes */
/* not lifted: $00F87D: tail jump at $F8BB with 3 bytes pushed */
/* not lifted: $00FAA2: COP at $00:FAA2 */
/* not lifted: $00FAAA: PLB at $FB3E pulls below the entry stack (return-address trick) */
/* not lifted: $00FFBF: BRK at $00:FFBF */
/* not lifted: $00FFFF: TXS at $00:0011 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $008202, entered with P=$20 via JSR */
void gen_008202(void) {
    goto L_8202;
L_8202:;
    recomp_tick(24); { uint16_t _v = 0x0006; g_cpu.Y = _v; g_nz16(_v); }  /* 8202 LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* 8205 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8212;  /* 8207 BEQ */
    recomp_tick(24); { uint16_t _v = 0x0AB0; g_cpu.Y = _v; g_nz16(_v); }  /* 8209 LDY */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 820C DEC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8212;  /* 820D BEQ */
    recomp_tick(24); { uint16_t _v = 0x155A; g_cpu.Y = _v; g_nz16(_v); }  /* 820F LDY */
L_8212:;
    recomp_tick(32); g_wr16(g_dp(0x03), (uint16_t)g_cpu.Y);  /* 8212 STY */
    recomp_tick(16); { uint8_t _v = 0x70; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8214 LDA */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* 8216 STA */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8218 LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 821A STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* 821C LDX */
    recomp_tick(16); g_rep(0x20);  /* 821F REP */
L_8221:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x82C0)); g_cpu.Y = _v; g_nz16(_v); }  /* 8221 LDY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_827A;  /* 8224 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8226 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8227 INX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x82C0)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8228 LDA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 822B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 822D INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 822E INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 822F TYA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_824D;  /* 8230 BMI */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.Y);  /* 8232 STY */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 8234 LDY */
    recomp_tick(16); g_sep(0x20);  /* 8237 SEP */
L_8239:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8239 LDA */
    recomp_tick(24); g_wr8(g_dpily(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 823B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 823D INY */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_dp(0x06)));  /* 823E CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_8239;  /* 8240 BCC */
    recomp_tick(16); g_rep(0x20);  /* 8242 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8244 CLC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8245 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x06))));  /* 8247 ADC */
    recomp_tick(32); g_wr16(g_dp(0x03), (uint16_t)g_cpu.C);  /* 8249 STA */
    recomp_tick(16); goto L_8221;  /* 824B BRA */
L_824D:;
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7FFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 824D AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8250 TAY */
L_8251:;
    recomp_tick(16); g_sep(0x20);  /* 8251 SEP */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8253 LDA */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8255 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpil(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8257 LDA */
    recomp_tick(24); g_wr8(g_dp(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* 8259 STA */
    recomp_tick(16); g_rep(0x20);  /* 825B REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x03); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 825D INC */
L_825F:;
    recomp_tick(48); { uint32_t _e = g_dp(0x06); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* 825F ASL */
    recomp_tick(16); g_sep(0x20);  /* 8261 SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8263 TDC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* 8264 ADC */
    recomp_tick(24); g_wr8(g_dpil(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 8266 STA */
    recomp_tick(16); g_rep(0x20);  /* 8268 REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 826A INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 826C DEY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8278;  /* 826D BEQ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 826F LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8271 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_825F;  /* 8274 BNE */
    recomp_tick(16); goto L_8251;  /* 8276 BRA */
L_8278:;
    recomp_tick(16); goto L_8221;  /* 8278 BRA */
L_827A:;
    recomp_tick(16); g_sep(0x20);  /* 827A SEP */
    recomp_tick(14); return;  /* 827C RTS */
}

/* $00827D, entered with P=$20 via JSR */
void gen_00827D(void) {
    goto L_827D;
L_827D:;
    recomp_tick(24); { uint16_t _v = 0x0002; g_cpu.Y = _v; g_nz16(_v); }  /* 827D LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* 8280 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_828D;  /* 8282 BEQ */
    recomp_tick(24); { uint16_t _v = 0x0AAC; g_cpu.Y = _v; g_nz16(_v); }  /* 8284 LDY */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8287 DEC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_828D;  /* 8288 BEQ */
    recomp_tick(24); { uint16_t _v = 0x1556; g_cpu.Y = _v; g_nz16(_v); }  /* 828A LDY */
L_828D:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* 828D STY */
    recomp_tick(16); { uint8_t _v = 0x70; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 828F LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 8291 STA */
    recomp_tick(16); g_rep(0x20);  /* 8293 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpil(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8295 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0AA7);  /* 8297 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_82BB;  /* 829A BNE */
    recomp_tick(24); { uint16_t _v = 0x0002; g_cpu.Y = _v; g_nz16(_v); }  /* 829C LDY */
    recomp_tick(32); g_wr16(g_dp(0x04), 0);  /* 829F STZ */
L_82A1:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 82A1 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 82A3 AND */
    recomp_tick(14); g_cpu.flag_C = false;  /* 82A6 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* 82A7 ADC */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* 82A9 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 82AB INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 82AC TYA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dpil(0x00)));  /* 82AD CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_82A1;  /* 82AF BCC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 82B1 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dpily(0x00)));  /* 82B3 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_82BB;  /* 82B5 BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 82B7 TDC */
    recomp_tick(16); g_sep(0x20);  /* 82B8 SEP */
    recomp_tick(14); return;  /* 82BA RTS */
L_82BB:;
    recomp_tick(16); g_sep(0x20);  /* 82BB SEP */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 82BD LDA */
    recomp_tick(14); return;  /* 82BF RTS */
}

/* $00855D, entered with P=$00 via JSR */
void gen_00855D(void) {
    goto L_855D;
L_855D:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 855D LDA */
    recomp_tick(24); { uint16_t _v = 0x0020; g_cpu.Y = _v; g_nz16(_v); }  /* 8560 LDY */
L_8563:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8563 ASL */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8565 ROL */
    recomp_tick(14); { uint16_t _v = g_rol16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8567 ROL */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* 8568 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_856E;  /* 856A BCC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* 856C SBC */
L_856E:;
    recomp_tick(48); { uint32_t _e = g_dp(0x06); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 856E ROL */
    recomp_tick(48); { uint32_t _e = g_dp(0x08); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8570 ROL */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8572 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8563;  /* 8573 BNE */
    recomp_tick(14); return;  /* 8575 RTS */
}

/* $0087BD, entered with P=$00 via JSR */
void gen_0087BD(void) {
    goto L_87BD;
L_87BD:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 87BD PHX */
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* 87BE PHY */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 87BF LDY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87C2 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_87D8;  /* 87C4 BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87C6 EOR */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* 87C9 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87CB LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87CD EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87D0 INC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 87D1 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_87D7;  /* 87D3 BNE */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 87D5 INC */
L_87D7:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 87D7 INY */
L_87D8:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87D8 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_87E3;  /* 87DA BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87DC EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87DF INC */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* 87E0 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 87E2 DEY */
L_87E3:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* 87E3 PHY */
    recomp_tick(30); g_push16(0x87E6); func_table_call_jsr(0x00855D); g_cpu.S += 2;  /* 87E4 JSR */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* 87E7 PLY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0000);  /* 87E8 CPY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8800;  /* 87EB BEQ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87ED LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87EF EOR */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.C);  /* 87F2 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87F4 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87F6 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87F9 INC */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* 87FA STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8800;  /* 87FC BNE */
    recomp_tick(48); { uint32_t _e = g_dp(0x08); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 87FE INC */
L_8800:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* 8800 PLY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8801 PLX */
    recomp_tick(14); return;  /* 8802 RTS */
}

/* $008803, entered with P=$00 via JSR */
void gen_008803(void) {
    goto L_8803;
L_8803:;
    recomp_tick(16); g_sep(0x10);  /* 8803 SEP */
    recomp_tick(16); { uint8_t _v = 0x00; g_cpu.X = _v; g_nz8(_v); }  /* 8805 LDX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* 8807 TXY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8808 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8820;  /* 880A BPL */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* 880C INX */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 880D EOR */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* 8810 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8812 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8814 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8817 INC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 8818 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_881E;  /* 881A BNE */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 881C INC */
L_881E:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 881E LDA */
L_8820:;
    recomp_tick(16); if (g_cpu.flag_Z) goto L_882C;  /* 8820 BEQ */
L_8822:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz8(_v); }  /* 8822 INY */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8823 LSR */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_882A;  /* 8824 BEQ */
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8826 ROR */
    recomp_tick(16); goto L_8822;  /* 8828 BRA */
L_882A:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 882A ROR */
L_882C:;
    recomp_tick(16); g_sep(0x20);  /* 882C SEP */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 882E TYA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x00);  /* 882F CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8835;  /* 8831 BEQ */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8833 ORA */
L_8835:;
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 8835 STA */
    recomp_tick(16); g_rep(0x30);  /* 8837 REP */
    recomp_tick(14); return;  /* 8839 RTS */
}

/* $00883A, entered with P=$00 via JSR */
void gen_00883A(void) {
    goto L_883A;
L_883A:;
    recomp_tick(16); g_sep(0x10);  /* 883A SEP */
    recomp_tick(16); { uint8_t _v = 0x00; g_cpu.X = _v; g_nz8(_v); }  /* 883C LDX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_cpu.Y = _v; g_nz8(_v); }  /* 883E TXY */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0000);  /* 883F CMP */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8849;  /* 8842 BPL */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz8(_v); }  /* 8844 INX */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8845 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8848 INC */
L_8849:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8849 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_8855;  /* 884C BCC */
L_884E:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz8(_v); }  /* 884E INY */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 884F LSR */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8850 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_884E;  /* 8853 BCS */
L_8855:;
    recomp_tick(16); g_sep(0x20);  /* 8855 SEP */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8857 XBA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8858 TYA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x00);  /* 8859 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_885F;  /* 885B BEQ */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 885D ORA */
L_885F:;
    recomp_tick(16); g_rep(0x10);  /* 885F REP */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8861 XBA */
    recomp_tick(14); return;  /* 8862 RTS */
}

/* $008914, entered with P=$00 via JSR */
void gen_008914(void) {
    goto L_8914;
L_8914:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8914 LDA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 8916 LDY */
    recomp_tick(16); goto L_8922;  /* 8919 BRA */
L_891B:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 891B INY */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = g_lsr16(g_rd16(_e)); g_wr16(_e, _v); }  /* 891C LSR */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 891E ROR */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = g_lsr16(g_rd16(_e)); g_wr16(_e, _v); }  /* 891F LSR */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8921 ROR */
L_8922:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8922 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_891B;  /* 8925 BCS */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* 8927 LDX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_891B;  /* 8929 BNE */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 892B ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 892C TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x008943u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 892D LDA */
    recomp_tick(32); g_wr16(g_dp(0x02), 0);  /* 8931 STZ */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 8933 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* 8935 TYX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8940;  /* 8936 BEQ */
L_8938:;
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8938 ASL */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8939 ROL */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 893B DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8938;  /* 893C BNE */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 893E STA */
L_8940:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8940 LDA */
    recomp_tick(14); return;  /* 8942 RTS */
}

/* $008B43, entered with P=$00 via JSR */
void gen_008B43(void) {
    goto L_8B43;
L_8B43:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8B43 TAY */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8B4A;  /* 8B44 BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8B46 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8B49 INC */
L_8B4A:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 8B4A LDY */
    recomp_tick(16); goto L_8B51;  /* 8B4D BRA */
L_8B4F:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8B4F INY */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8B50 LSR */
L_8B51:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8B51 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8B4F;  /* 8B54 BCS */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8B56 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8B57 TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x008B6Du)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8B58 LDA */
    recomp_tick(32); g_wr16(g_dp(0x02), 0);  /* 8B5C STZ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* 8B5E TYX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8B6A;  /* 8B5F BEQ */
L_8B61:;
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8B61 ASL */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8B62 ROL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8B64 ASL */
    recomp_tick(48); { uint32_t _e = g_dp(0x02); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 8B65 ROL */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8B67 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8B61;  /* 8B68 BNE */
L_8B6A:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 8B6A STA */
    recomp_tick(14); return;  /* 8B6C RTS */
}

/* $008DD2, entered with P=$00 via JSR */
void gen_008DD2(void) {
    goto L_8DD2;
L_8DD2:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 8DD2 LDY */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DD5 TAX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8DDE;  /* 8DD6 BEQ */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8DDE;  /* 8DD8 BMI */
L_8DDA:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8DDA DEY */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8DDB ASL */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8DDA;  /* 8DDC BPL */
L_8DDE:;
    recomp_tick(16); g_sep(0x20);  /* 8DDE SEP */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DE0 TYA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8DE1 XBA */
    recomp_tick(14); return;  /* 8DE2 RTS */
}

/* $008DE3, entered with P=$00 via JSR */
void gen_008DE3(void) {
    goto L_8DE3;
L_8DE3:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 8DE3 LDY */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DE6 TAX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8DF5;  /* 8DE7 BEQ */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8DE9 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_8DF5;  /* 8DEC BCC */
L_8DEE:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8DEE INY */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8DEF LSR */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8DF0 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8DEE;  /* 8DF3 BCS */
L_8DF5:;
    recomp_tick(16); g_sep(0x20);  /* 8DF5 SEP */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8DF7 XBA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8DF8 TYA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8DF9 XBA */
    recomp_tick(14); return;  /* 8DFA RTS */
}

/* $008DFB, entered with P=$00 via JSR */
void gen_008DFB(void) {
    goto L_8DFB;
L_8DFB:;
    recomp_tick(24); { uint16_t _v = 0x0008; g_cpu.Y = _v; g_nz16(_v); }  /* 8DFB LDY */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8DFE TAX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8E13;  /* 8DFF BEQ */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8E07;  /* 8E01 BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E03 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E06 INC */
L_8E07:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8E07 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_8E13;  /* 8E0A BCC */
L_8E0C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8E0C INY */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8E0D LSR */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0100);  /* 8E0E CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8E0C;  /* 8E11 BCS */
L_8E13:;
    recomp_tick(16); g_sep(0x20);  /* 8E13 SEP */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E15 XBA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E16 TYA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E17 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* 8E19 TXY */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8E1E;  /* 8E1A BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E1C ORA */
L_8E1E:;
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E1E XBA */
    recomp_tick(16); g_rep(0x20);  /* 8E1F REP */
    recomp_tick(14); return;  /* 8E21 RTS */
}

/* $008E22, entered with P=$00 via JSR */
void gen_008E22(void) {
    goto L_8E22;
L_8E22:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8E22 TAX */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 8E23 XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x007F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E24 AND */
    recomp_tick(14); g_cpu.flag_C = true;  /* 8E27 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0008));  /* 8E28 SBC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8E5C;  /* 8E2B BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x007F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E2D AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8E30 TAY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0040);  /* 8E31 CPY */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8E4D;  /* 8E34 BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E36 TXA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E37 AND */
L_8E3A:;
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8E3A ASL */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8E48;  /* 8E3B BMI */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8E3D DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8E3A;  /* 8E3E BNE */
L_8E40:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* 8E40 TXY */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_8E47;  /* 8E41 BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E43 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E46 INC */
L_8E47:;
    recomp_tick(14); return;  /* 8E47 RTS */
L_8E48:;
    recomp_tick(24); { uint16_t _v = 0x7FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E48 LDA */
    recomp_tick(16); goto L_8E40;  /* 8E4B BRA */
L_8E4D:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E4D TXA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E4E AND */
L_8E51:;
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8E51 LSR */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8E40;  /* 8E52 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8E54 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0080);  /* 8E55 CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_8E51;  /* 8E58 BCC */
    recomp_tick(16); goto L_8E40;  /* 8E5A BRA */
L_8E5C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E5C TXA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E5D AND */
    recomp_tick(16); goto L_8E40;  /* 8E60 BRA */
}

/* $008E62, entered with P=$00 via JSR */
void gen_008E62(void) {
    goto L_8E62;
L_8E62:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 8E62 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0100));  /* 8E63 ADC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x03FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E66 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8E69 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8E6A TAY */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x8E6F)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8E6B LDA */
    recomp_tick(14); return;  /* 8E6E RTS */
}

/* $00966F, entered with P=$00 via JSR */
void gen_00966F(void) {
    goto L_966F;
L_966F:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 966F TAY */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9670 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9673 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9674 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9675 TYA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* 9676 XBA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9677 LSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9678 TXA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_968D;  /* 9679 BEQ */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9683;  /* 967B BCC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0x01FE); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 967D EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9680 INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9681 INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9682 TAX */
L_9683:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x9693)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9683 LDA */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_968C;  /* 9686 BCC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9688 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 968B INC */
L_968C:;
    recomp_tick(14); return;  /* 968C RTS */
L_968D:;
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9692;  /* 968D BCC */
    recomp_tick(24); { uint16_t _v = 0x5FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 968F LDA */
L_9692:;
    recomp_tick(14); return;  /* 9692 RTS */
}

/* $009709, entered with P=$20 via JSR */
void gen_009709(void) {
    goto L_9709;
L_9709:;
    recomp_tick(14); return;  /* 9709 RTS */
}

/* $0099F4, entered with P=$20 via JSR */
void gen_0099F4(void) {
    goto L_99F4;
L_99F4:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* 99F4 STX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.Y);  /* 99F6 STY */
    recomp_tick(16); g_rep(0x20);  /* 99F8 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 99FA AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 99FD ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 99FE TAY */
    recomp_tick(24); { uint16_t _v = 0x7FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 99FF LDA */
    recomp_tick(32); g_wr16(g_dpiy(0x02), (uint16_t)g_cpu.C);  /* 9A02 STA */
L_9A04:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A04 TYA */
    recomp_tick(32); g_wr16(g_dpiy(0x00), (uint16_t)g_cpu.C);  /* 9A05 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A07 DEY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A08 DEY */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_9A04;  /* 9A09 BPL */
    recomp_tick(16); g_sep(0x20);  /* 9A0B SEP */
    recomp_tick(14); return;  /* 9A0D RTS */
}

/* $009A0E, entered with P=$20 via JSR */
void gen_009A0E(void) {
    goto L_9A0E;
L_9A0E:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* 9A0E STX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* 9A10 DEX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* 9A11 DEX */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.X);  /* 9A12 STX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.Y);  /* 9A14 STY */
    recomp_tick(16); g_rep(0x20);  /* 9A16 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A18 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A1B ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9A1C TAY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A1D DEY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A1E DEY */
L_9A1F:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A1F DEY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9A20 DEY */
    recomp_tick(16); if (g_cpu.flag_N) goto L_9A52;  /* 9A21 BMI */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.Y);  /* 9A23 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A25 LDA */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* 9A27 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9A29 TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A2A LDA */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.C);  /* 9A2C STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* 9A2E LDX */
L_9A30:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9A30 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9A31 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* 9A32 TXY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A33 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9A35 TAY */
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
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* 9A44 TXY */
    recomp_tick(32); g_wr16(g_dpiy(0x0A), (uint16_t)g_cpu.C);  /* 9A45 STA */
    recomp_tick(16); goto L_9A30;  /* 9A47 BRA */
L_9A49:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A49 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* 9A4B TXY */
    recomp_tick(32); g_wr16(g_dpiy(0x0A), (uint16_t)g_cpu.C);  /* 9A4C STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.Y = _v; g_nz16(_v); }  /* 9A4E LDY */
    recomp_tick(16); goto L_9A1F;  /* 9A50 BRA */
L_9A52:;
    recomp_tick(16); g_sep(0x20);  /* 9A52 SEP */
    recomp_tick(14); return;  /* 9A54 RTS */
}

/* $009A55, entered with P=$20 via JSR */
void gen_009A55(void) {
    goto L_9A55;
L_9A55:;
    recomp_tick(14); g_push8(cpu_get_p());  /* 9A55 PHP */
    recomp_tick(16); g_rep(0x20);  /* 9A56 REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A58 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9A5B TAY */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x0007); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A5C AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A5F ASL */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 9A60 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A62 TYA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00F8); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A63 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A66 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 9A67 ASL */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9A68 ORA */
    recomp_tick(14); g_set_p(g_pull8());  /* 9A6A PLP */
    recomp_tick(14); return;  /* 9A6B RTS */
}

/* $00A37A, entered with P=$00 via JSR */
void gen_00A37A(void) {
    goto L_A37A;
L_A37A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A37A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* A37C SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0400));  /* A37D SBC */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* A380 STA */
    recomp_tick(14); return;  /* A382 RTS */
}

/* $00A383, entered with P=$00 via JSR */
void gen_00A383(void) {
    goto L_A383;
L_A37A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A37A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* A37C SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0400));  /* A37D SBC */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* A380 STA */
    recomp_tick(14); return;  /* A382 RTS */
L_A383:;
    recomp_tick(16); g_sep(0x20);  /* A383 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A385 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A387 INC */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A388 AND */
    recomp_tick(24); g_wr8(g_dp(0x0D), (uint8_t)(uint8_t)g_cpu.C);  /* A38A STA */
    recomp_tick(16); g_rep(0x20);  /* A38C REP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A37A;  /* A38E BEQ */
    recomp_tick(14); return;  /* A390 RTS */
}

/* $00A391, entered with P=$00 via JSR */
void gen_00A391(void) {
    goto L_A391;
L_A391:;
    recomp_tick(16); g_sep(0x20);  /* A391 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A393 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A395 INC */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A396 AND */
    recomp_tick(24); g_wr8(g_dp(0x0D), (uint8_t)(uint8_t)g_cpu.C);  /* A398 STA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A39A LSR */
    recomp_tick(16); g_rep(0x20);  /* A39B REP */
    recomp_tick(24); { uint16_t _v = 0x0400; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A39D LDA */
    recomp_tick(16); if (g_cpu.flag_C) goto L_A3A5;  /* A3A0 BCS */
    recomp_tick(24); { uint16_t _v = 0xF400; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A3A2 LDA */
L_A3A5:;
    recomp_tick(14); g_cpu.flag_C = false;  /* A3A5 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x0E))));  /* A3A6 ADC */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* A3A8 STA */
    recomp_tick(14); return;  /* A3AA RTS */
}

/* $00AA52, entered with P=$20 via JSR */
void gen_00AA52(void) {
    goto L_AA52;
L_AA52:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x51)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA52 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x03); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA54 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AA5E;  /* AA56 BNE */
    recomp_tick(16); g_rep(0x20);  /* AA58 REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x82); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* AA5A INC */
    recomp_tick(16); g_sep(0x20);  /* AA5C SEP */
L_AA5E:;
    recomp_tick(14); return;  /* AA5E RTS */
}

/* $00ACD2, entered with P=$20 via JSR */
void gen_00ACD2(void) {
    goto L_ACD2;
L_ACD2:;
    recomp_tick(14); return;  /* ACD2 RTS */
}

/* $00AD13, entered with P=$20 via JSR */
void gen_00AD13(void) {
    goto L_AD13;
L_AD13:;
    recomp_tick(24); { uint16_t _v = 0x0012; g_cpu.X = _v; g_nz16(_v); }  /* AD13 LDX */
L_AD16:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19F6)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AD16 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AD19 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AD23;  /* AD1B BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* AD1D DEX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* AD1E DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_AD16;  /* AD1F BPL */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AD21 TDC */
    recomp_tick(14); return;  /* AD22 RTS */
L_AD23:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AD23 LDA */
    recomp_tick(14); return;  /* AD25 RTS */
}

/* $00AF87, entered with P=$20 via JSR */
void gen_00AF87(void) {
    goto L_AF87;
L_AF87:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xAA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AF87 LDA */
    recomp_tick(16); g_bit8(0x10, true);  /* AF89 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AFB4;  /* AF8B BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xCE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AF8D LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AF93;  /* AF8F BEQ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AF91 TDC */
    recomp_tick(14); return;  /* AF92 RTS */
L_AF93:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xAA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AF93 LDA */
    recomp_tick(16); g_bit8(0x80, true);  /* AF95 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AFAE;  /* AF97 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xA9)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AF99 LDA */
    recomp_tick(16); g_bit8(0x80, true);  /* AF9B BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AFAB;  /* AF9D BNE */
    recomp_tick(16); g_bit8(0x40, true);  /* AF9F BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AFB1;  /* AFA1 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0xAA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFA3 LDA */
    recomp_tick(16); g_bit8(0x20, true);  /* AFA5 BIT */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AFB7;  /* AFA7 BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AFA9 TDC */
    recomp_tick(14); return;  /* AFAA RTS */
L_AFAB:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFAB LDA */
    recomp_tick(14); return;  /* AFAD RTS */
L_AFAE:;
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFAE LDA */
    recomp_tick(14); return;  /* AFB0 RTS */
L_AFB1:;
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFB1 LDA */
    recomp_tick(14); return;  /* AFB3 RTS */
L_AFB4:;
    recomp_tick(16); { uint8_t _v = 0x04; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFB4 LDA */
    recomp_tick(14); return;  /* AFB6 RTS */
L_AFB7:;
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFB7 LDA */
    recomp_tick(14); return;  /* AFB9 RTS */
}

/* $00B154, entered with P=$20 via JSR */
void gen_00B154(void) {
    goto L_B154;
L_B154:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B154 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B169;  /* B156 BEQ */
    recomp_tick(16); g_rep(0x20);  /* B158 REP */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* B15A XBA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B15B ASL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0xFE00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B15C AND */
    recomp_tick(14); g_cpu.flag_C = false;  /* B15F CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0xE000));  /* B160 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B163 TAX */
    recomp_tick(16); g_sep(0x20);  /* B164 SEP */
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B166 LDA */
    recomp_tick(14); return;  /* B168 RTS */
L_B169:;
    recomp_tick(24); { uint16_t _v = 0x4640; g_cpu.X = _v; g_nz16(_v); }  /* B169 LDX */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B16C LDA */
    recomp_tick(14); return;  /* B16E RTS */
}

/* $00B399, entered with P=$20 via JSR */
void gen_00B399(void) {
    goto L_B399;
L_B399:;
    recomp_tick(16); g_rep(0x20);  /* B399 REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x14DE)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B39B LDA */
    recomp_tick(32); g_wr16(g_dp(0x1A), (uint16_t)g_cpu.C);  /* B39E STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* B3A0 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0010));  /* B3A1 SBC */
    recomp_tick(32); g_wr16(g_dp(0x18), (uint16_t)g_cpu.C);  /* B3A4 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x14E0)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B3A6 LDA */
    recomp_tick(32); g_wr16(g_dp(0x1E), (uint16_t)g_cpu.C);  /* B3A9 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* B3AB SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0010));  /* B3AC SBC */
    recomp_tick(32); g_wr16(g_dp(0x1C), (uint16_t)g_cpu.C);  /* B3AF STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x14E2)); g_cpu.X = _v; g_nz16(_v); }  /* B3B1 LDX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x14E4)); g_cpu.Y = _v; g_nz16(_v); }  /* B3B4 LDY */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* B3B7 STX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.Y);  /* B3B9 STY */
    recomp_tick(16); g_sep(0x20);  /* B3BB SEP */
    recomp_tick(30); g_push16(0xB3BF); func_table_call_jsr(0x00D32F); g_cpu.S += 2;  /* B3BD JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* B3C0 STA */
    recomp_tick(16); g_rep(0x20);  /* B3C2 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B3C4 LDA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3C6 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3C7 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3C8 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3C9 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B3CA TAX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B3CB LDA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3CD ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3CE ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3CF ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B3D0 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* B3D1 TAY */
    recomp_tick(16); g_sep(0x20);  /* B3D2 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3D4 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x14);  /* B3D6 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B3DF;  /* B3D8 BCS */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* B3DA LDX */
    recomp_tick(16); goto L_B40A;  /* B3DD BRA */
L_B3DF:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x16);  /* B3DF CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B3E8;  /* B3E1 BCS */
    recomp_tick(30); g_push16(0xB3E5); func_table_call_jsr(0x00BA28); g_cpu.S += 2;  /* B3E3 JSR */
    recomp_tick(16); goto L_B3FE;  /* B3E6 BRA */
L_B3E8:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x18);  /* B3E8 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B3F1;  /* B3EA BCS */
    recomp_tick(30); g_push16(0xB3EE); func_table_call_jsr(0x00BA75); g_cpu.S += 2;  /* B3EC JSR */
    recomp_tick(16); goto L_B3FE;  /* B3EF BRA */
L_B3F1:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x1A);  /* B3F1 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_B3FC;  /* B3F3 BCS */
    recomp_tick(30); g_push16(0xB3F7); func_table_call_jsr(0x00BAC7); g_cpu.S += 2;  /* B3F5 JSR */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3F8 ORA */
    recomp_tick(16); goto L_B3FE;  /* B3FA BRA */
L_B3FC:;
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3FC LDA */
L_B3FE:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* B3FE LDX */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B401 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B40A;  /* B403 BEQ */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B405 ORA */
    recomp_tick(24); g_wr8(g_dpx(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* B407 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B409 INX */
L_B40A:;
    recomp_tick(16); g_rep(0x20);  /* B40A REP */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* B40C LDY */
L_B40F:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x14ED)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B40F LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* B412 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x18))));  /* B413 SBC */
    recomp_tick(16); if (g_cpu.flag_V) goto L_B41B;  /* B415 BVS */
    recomp_tick(16); if (g_cpu.flag_N) goto L_B44C;  /* B417 BMI */
    recomp_tick(16); goto L_B41D;  /* B419 BRA */
L_B41B:;
    recomp_tick(16); if (!g_cpu.flag_N) goto L_B44C;  /* B41B BPL */
L_B41D:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x14ED)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B41D LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* B420 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x1A))));  /* B421 SBC */
    recomp_tick(16); if (g_cpu.flag_V) goto L_B429;  /* B423 BVS */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_B44C;  /* B425 BPL */
    recomp_tick(16); goto L_B42B;  /* B427 BRA */
L_B429:;
    recomp_tick(16); if (g_cpu.flag_N) goto L_B44C;  /* B429 BMI */
L_B42B:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x1517)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B42B LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* B42E SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x1C))));  /* B42F SBC */
    recomp_tick(16); if (g_cpu.flag_V) goto L_B437;  /* B431 BVS */
    recomp_tick(16); if (g_cpu.flag_N) goto L_B44C;  /* B433 BMI */
    recomp_tick(16); goto L_B439;  /* B435 BRA */
L_B437:;
    recomp_tick(16); if (!g_cpu.flag_N) goto L_B44C;  /* B437 BPL */
L_B439:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x1517)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B439 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* B43C SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* B43D SBC */
    recomp_tick(16); if (g_cpu.flag_V) goto L_B445;  /* B43F BVS */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_B44C;  /* B441 BPL */
    recomp_tick(16); goto L_B447;  /* B443 BRA */
L_B445:;
    recomp_tick(16); if (g_cpu.flag_N) goto L_B44C;  /* B445 BMI */
L_B447:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B447 TYA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* B448 LSR */
    recomp_tick(32); g_wr16(g_dpx(0x00), (uint16_t)g_cpu.C);  /* B449 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B44B INX */
L_B44C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* B44C INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* B44D INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0028);  /* B44E CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_B40F;  /* B451 BCC */
    recomp_tick(16); g_sep(0x20);  /* B453 SEP */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B455 TXA */
    recomp_tick(14); return;  /* B456 RTS */
}

/* $00BA28, entered with P=$20 via JSR */
void gen_00BA28(void) {
    goto L_BA28;
L_BA28:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* BA28 STX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.Y);  /* BA2A STY */
    recomp_tick(16); g_rep(0x20);  /* BA2C REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA2E TXA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BA2F SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0180));  /* BA30 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA36;  /* BA33 BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA35 TDC */
L_BA36:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* BA36 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA38 TYA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BA39 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0180));  /* BA3A SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA40;  /* BA3D BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA3F TDC */
L_BA40:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* BA40 STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* BA42 LDX */
L_BA45:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1A95)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA45 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* BA48 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA4E;  /* BA4A BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA68;  /* BA4C BCS */
L_BA4E:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* BA4E CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BA68;  /* BA50 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA68;  /* BA52 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1B0D)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA54 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x02)));  /* BA57 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA5D;  /* BA59 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA68;  /* BA5B BCS */
L_BA5D:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x06)));  /* BA5D CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BA68;  /* BA5F BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BA68;  /* BA61 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA63 TXA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA64 LSR */
    recomp_tick(16); g_sep(0x20);  /* BA65 SEP */
    recomp_tick(14); return;  /* BA67 RTS */
L_BA68:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* BA68 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* BA69 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0004);  /* BA6A CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BA45;  /* BA6D BCC */
    recomp_tick(24); { uint16_t _v = 0xFFFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA6F LDA */
    recomp_tick(16); g_sep(0x20);  /* BA72 SEP */
    recomp_tick(14); return;  /* BA74 RTS */
}

/* $00BA75, entered with P=$30 via JSR */
void gen_00BA75(void) {
    goto L_BA75;
L_BA75:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)g_cpu.X);  /* BA75 STX */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)g_cpu.Y);  /* BA77 STY */
    recomp_tick(16); g_rep(0x20);  /* BA79 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA7B TXA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BA7C SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BA7D SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA83;  /* BA80 BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA82 TDC */
L_BA83:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* BA83 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA85 TYA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BA86 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BA87 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA8D;  /* BA8A BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA8C TDC */
L_BA8D:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* BA8D STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1603)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA8F LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA92 DEC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA93 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA96 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* BA97 TAX */
L_BA98:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1A99)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA98 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* BA9B CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BAA1;  /* BA9D BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BABD;  /* BA9F BCS */
L_BAA1:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* BAA1 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BABD;  /* BAA3 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BABD;  /* BAA5 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1B11)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAA7 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x02)));  /* BAAA CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BAB0;  /* BAAC BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BABD;  /* BAAE BCS */
L_BAB0:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x06)));  /* BAB0 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BABD;  /* BAB2 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BABD;  /* BAB4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAB6 TXA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BAB7 LSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAB8 INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAB9 INC */
    recomp_tick(16); g_sep(0x20);  /* BABA SEP */
    recomp_tick(14); return;  /* BABC RTS */
L_BABD:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BABD DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BABE DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BA98;  /* BABF BPL */
    recomp_tick(24); { uint16_t _v = 0xFFFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAC1 LDA */
    recomp_tick(16); g_sep(0x20);  /* BAC4 SEP */
    recomp_tick(14); return;  /* BAC6 RTS */
}

/* $00BAC7, entered with P=$30 via JSR */
void gen_00BAC7(void) {
    goto L_BAC7;
L_BAC7:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)g_cpu.X);  /* BAC7 STX */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)g_cpu.Y);  /* BAC9 STY */
    recomp_tick(16); g_rep(0x20);  /* BACB REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BACD TXA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BACE SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BACF SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BAD5;  /* BAD2 BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BAD4 TDC */
L_BAD5:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* BAD5 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAD7 TYA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BAD8 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BAD9 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BADF;  /* BADC BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BADE TDC */
L_BADF:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* BADF STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1604)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAE1 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAE4 DEC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAE5 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BAE8 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BAE9 DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* BAEA TAX */
L_BAEB:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1ABD)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAEB LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* BAEE CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BAF4;  /* BAF0 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BB0E;  /* BAF2 BCS */
L_BAF4:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* BAF4 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BB0E;  /* BAF6 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BB0E;  /* BAF8 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1B35)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAFA LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x02)));  /* BAFD CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BB03;  /* BAFF BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BB0E;  /* BB01 BCS */
L_BB03:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x06)));  /* BB03 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BB0E;  /* BB05 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BB0E;  /* BB07 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BB09 TXA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BB0A LSR */
    recomp_tick(16); g_sep(0x20);  /* BB0B SEP */
    recomp_tick(14); return;  /* BB0D RTS */
L_BB0E:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BB0E DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BB0F DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BAEB;  /* BB10 BPL */
    recomp_tick(24); { uint16_t _v = 0xFFFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BB12 LDA */
    recomp_tick(16); g_sep(0x20);  /* BB15 SEP */
    recomp_tick(14); return;  /* BB17 RTS */
}

/* $00BBFB, entered with P=$00 via JSR */
void gen_00BBFB(void) {
    goto L_BBFB;
L_BBFB:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BBFB LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BBFD AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC00 ASL */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* BC01 XBA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* BC02 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC04 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC06 AND */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC09 LSR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC0A ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BC0C TAX */
    recomp_tick(14); return;  /* BC0D RTS */
}

/* $00BC0E, entered with P=$30 via JSR */
void gen_00BC0E(void) {
    goto L_BC0E;
L_BC0E:;
    recomp_tick(16); g_rep(0x20);  /* BC0E REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC10 LDA */
    recomp_tick(40); g_wr16(g_absy(0x1905), (uint16_t)g_cpu.C);  /* BC12 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC15 LDA */
    recomp_tick(40); g_wr16(g_absy(0x192D), (uint16_t)g_cpu.C);  /* BC17 STA */
    recomp_tick(16); g_sep(0x20);  /* BC1A SEP */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC1C LDA */
    recomp_tick(32); g_wr8(g_absy(0x19A6), (uint8_t)(uint8_t)g_cpu.C);  /* BC1E STA */
    recomp_tick(14); return;  /* BC21 RTS */
}

/* $00BC22, entered with P=$20 via JSR */
void gen_00BC22(void) {
    goto L_BC22;
L_BC22:;
    recomp_tick(16); g_rep(0x20);  /* BC22 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC24 LDA */
    recomp_tick(40); g_wr16(g_absy(0x1905), (uint16_t)g_cpu.C);  /* BC26 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC29 LDA */
    recomp_tick(40); g_wr16(g_absy(0x192D), (uint16_t)g_cpu.C);  /* BC2B STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC2E LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC30 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC33 ASL */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* BC34 XBA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* BC35 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC37 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC39 AND */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC3C LSR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC3D ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BC3F TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC40 TYA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* BC41 XBA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC42 LSR */
    recomp_tick(14); g_cpu.flag_C = false;  /* BC43 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x5E00));  /* BC44 ADC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* BC47 STA */
    recomp_tick(24); { uint16_t _v = 0x007E; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC49 LDA */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* BC4C STA */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E8F28u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC4E LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x7FFF);  /* BC52 CMP */
    recomp_tick(16); g_sep(0x20);  /* BC55 SEP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BC82;  /* BC57 BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* BC59 PHY */
    recomp_tick(16); g_rep(0x20);  /* BC5A REP */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* BC5C LDY */
L_BC5F:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E8F28u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC5F LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BC77;  /* BC63 BEQ */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7EAF28u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC65 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7FFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC69 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BC6C TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC6D TXA */
    recomp_tick(32); g_wr16(g_dpily(0x00), (uint16_t)g_cpu.C);  /* BC6E STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* BC70 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* BC71 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x00FE);  /* BC72 CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BC5F;  /* BC75 BCC */
L_BC77:;
    recomp_tick(16); g_sep(0x20);  /* BC77 SEP */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* BC79 PLX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.Y; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC7A TYA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* BC7B LSR */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_BC7F;  /* BC7C BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC7E INC */
L_BC7F:;
    recomp_tick(32); g_wr8(g_absx(0x19A6), (uint8_t)(uint8_t)g_cpu.C);  /* BC7F STA */
L_BC82:;
    recomp_tick(14); return;  /* BC82 RTS */
}

/* $00BD78, entered with P=$10 via JSR */
void gen_00BD78(void) {
    goto L_BD78;
L_BD78:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD78 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x7FFF);  /* BD7A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BD98;  /* BD7D BEQ */
    recomp_tick(14); g_cpu.flag_C = true;  /* BD7F SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* BD80 SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BD88;  /* BD82 BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD84 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD87 INC */
L_BD88:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* BD88 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD8A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BD8C SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* BD8D SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BD95;  /* BD8F BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD91 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD94 INC */
L_BD95:;
    recomp_tick(14); g_cpu.flag_C = false;  /* BD95 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* BD96 ADC */
L_BD98:;
    recomp_tick(14); return;  /* BD98 RTS */
}

/* $00BD99, entered with P=$00 via JSR */
void gen_00BD99(void) {
    goto L_BD99;
L_BD99:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD99 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x7FFF);  /* BD9B CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BDA9;  /* BD9E BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* BDA0 PHX */
    recomp_tick(30); g_push16(0xBDA3); func_table_call_jsr(0x00BBFB); g_cpu.S += 2;  /* BDA1 JSR */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E8F28u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BDA4 LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* BDA8 PLX */
L_BDA9:;
    recomp_tick(14); return;  /* BDA9 RTS */
}

/* $00C755, entered with P=$00 via JSR */
void gen_00C755(void) {
    goto L_C755;
L_C755:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xBD)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C755 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* C757 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0xC1))));  /* C758 SBC */
    recomp_tick(32); g_wr16(g_dp(0x7C), (uint16_t)g_cpu.C);  /* C75A STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xBF)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C75C LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* C75E SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0xC3))));  /* C75F SBC */
    recomp_tick(32); g_wr16(g_dp(0x7E), (uint16_t)g_cpu.C);  /* C761 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xBD)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C763 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C765 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0080));  /* C766 ADC */
    recomp_tick(32); g_wr16(g_dp(0x90), (uint16_t)g_cpu.C);  /* C769 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0xBF)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C76B LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C76D CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0070));  /* C76E ADC */
    recomp_tick(32); g_wr16(g_dp(0x92), (uint16_t)g_cpu.C);  /* C771 STA */
    recomp_tick(14); return;  /* C773 RTS */
}

/* $00CA6E, entered with P=$00 via JSR */
void gen_00CA6E(void) {
    goto L_CA6E;
L_CA6E:;
    recomp_tick(24); { uint16_t _v = 0x16EB; g_cpu.X = _v; g_nz16(_v); }  /* CA6E LDX */
    recomp_tick(48); { uint16_t _v = g_rd16(0x0014BFu); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CA71 LDA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CA75 LSR */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CA7E;  /* CA76 BCC */
    recomp_tick(14); g_cpu.flag_C = false;  /* CA78 CLC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CA79 TXA */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x001C));  /* CA7A ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CA7D TAX */
L_CA7E:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CA7E TYA */
    recomp_tick(32); g_wr16(g_dpx(0x01), (uint16_t)g_cpu.C);  /* CA7F STA */
    recomp_tick(32); g_wr16(g_dpx(0x16), (uint16_t)g_cpu.C);  /* CA81 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CA83 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x00E0));  /* CA84 ADC */
    recomp_tick(32); g_wr16(g_dpx(0x04), (uint16_t)g_cpu.C);  /* CA87 STA */
    recomp_tick(32); g_wr16(g_dpx(0x19), (uint16_t)g_cpu.C);  /* CA89 STA */
    recomp_tick(24); { uint16_t _v = 0xFC00; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CA8B LDA */
    recomp_tick(32); g_wr16(g_dpx(0x08), (uint16_t)g_cpu.C);  /* CA8E STA */
    recomp_tick(32); g_wr16(g_dpx(0x0F), (uint16_t)g_cpu.C);  /* CA90 STA */
    recomp_tick(24); { uint16_t _v = 0xFCE0; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CA92 LDA */
    recomp_tick(32); g_wr16(g_dpx(0x0B), (uint16_t)g_cpu.C);  /* CA95 STA */
    recomp_tick(32); g_wr16(g_dpx(0x12), (uint16_t)g_cpu.C);  /* CA97 STA */
    recomp_tick(16); g_sep(0x20);  /* CA99 SEP */
    recomp_tick(16); { uint8_t _v = 0xF0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CA9B LDA */
    recomp_tick(24); g_wr8(g_dpx(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* CA9D STA */
    recomp_tick(24); g_wr8(g_dpx(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* CA9F STA */
    recomp_tick(24); g_wr8(g_dpx(0x0E), (uint8_t)(uint8_t)g_cpu.C);  /* CAA1 STA */
    recomp_tick(24); g_wr8(g_dpx(0x15), (uint8_t)(uint8_t)g_cpu.C);  /* CAA3 STA */
    recomp_tick(16); { uint8_t _v = 0xEF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CAA5 LDA */
    recomp_tick(24); g_wr8(g_dpx(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CAA7 STA */
    recomp_tick(24); g_wr8(g_dpx(0x0A), (uint8_t)(uint8_t)g_cpu.C);  /* CAA9 STA */
    recomp_tick(24); g_wr8(g_dpx(0x11), (uint8_t)(uint8_t)g_cpu.C);  /* CAAB STA */
    recomp_tick(24); g_wr8(g_dpx(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* CAAD STA */
    recomp_tick(24); g_wr8(g_dpx(0x06), 0);  /* CAAF STZ */
    recomp_tick(24); g_wr8(g_dpx(0x0D), 0);  /* CAB1 STZ */
    recomp_tick(24); g_wr8(g_dpx(0x14), 0);  /* CAB3 STZ */
    recomp_tick(24); g_wr8(g_dpx(0x1B), 0);  /* CAB5 STZ */
    recomp_tick(16); g_rep(0x20);  /* CAB7 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CAB9 TXA */
    recomp_tick(32); g_wr16(g_dp(0xB3), (uint16_t)g_cpu.C);  /* CABA STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CABC CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0007));  /* CABD ADC */
    recomp_tick(32); g_wr16(g_dp(0xB5), (uint16_t)g_cpu.C);  /* CAC0 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CAC2 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0007));  /* CAC3 ADC */
    recomp_tick(32); g_wr16(g_dp(0xB7), (uint16_t)g_cpu.C);  /* CAC6 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CAC8 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0007));  /* CAC9 ADC */
    recomp_tick(32); g_wr16(g_dp(0xB9), (uint16_t)g_cpu.C);  /* CACC STA */
    recomp_tick(48); { uint16_t _v = g_rd16(0x0014BFu); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CACE LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0x0001); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CAD2 EOR */
    recomp_tick(48); g_wr16(0x0014BFu, (uint16_t)g_cpu.C);  /* CAD5 STA */
    recomp_tick(14); return;  /* CAD9 RTS */
}

/* $00CC4C, entered with P=$20 via JSR */
void gen_00CC4C(void) {
    goto L_CC4C;
L_CC4C:;
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* CC4C STX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x49)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CC4E LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* CC50 STA */
    recomp_tick(32); g_wr16(g_dp(0x05), (uint16_t)g_cpu.Y);  /* CC52 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x48)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CC54 LDA */
    recomp_tick(24); g_wr8(g_dp(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* CC56 STA */
    recomp_tick(16); g_rep(0x20);  /* CC58 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC5A LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC5C AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC5F ASL */
    recomp_tick(32); g_wr16(g_dp(0x14), (uint16_t)g_cpu.C);  /* CC60 STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC62 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* CC63 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x14))));  /* CC64 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CC66 TAX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC67 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC69 DEC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC6A AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC6D INC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* CC6E STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* CC70 LDY */
L_CC73:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x05)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC73 LDA */
    recomp_tick(32); g_wr16(g_dp(0x10), (uint16_t)g_cpu.C);  /* CC75 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC77 LDA */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* CC79 STA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7C00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC7B AND */
    recomp_tick(32); g_wr16(g_dp(0x12), (uint16_t)g_cpu.C);  /* CC7E STA */
    recomp_tick(48); g_wr16(g_longx(0x7E3A40u), (uint16_t)g_cpu.C);  /* CC80 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x10)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC84 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7C00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CC86 AND */
    recomp_tick(14); g_cpu.flag_C = true;  /* CC89 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x12))));  /* CC8A SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_CC9A;  /* CC8C BPL */
    recomp_tick(14); g_cpu.flag_C = true;  /* CC8E SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC8F ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CC90 SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC91 ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CC92 SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC93 ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CC94 SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC95 ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CC96 SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC97 ROR */
    recomp_tick(16); goto L_CC9F;  /* CC98 BRA */
L_CC9A:;
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC9A LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC9B LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC9C LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC9D LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CC9E LSR */
L_CC9F:;
    recomp_tick(48); g_wr16(g_longx(0x7E4040u), (uint16_t)g_cpu.C);  /* CC9F STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCA3 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x03E0); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCA5 AND */
    recomp_tick(32); g_wr16(g_dp(0x12), (uint16_t)g_cpu.C);  /* CCA8 STA */
    recomp_tick(48); g_wr16(g_longx(0x7E3A42u), (uint16_t)g_cpu.C);  /* CCAA STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x10)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCAE LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x03E0); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCB0 AND */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCB3 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x12))));  /* CCB4 SBC */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCB6 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCB7 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCB8 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCB9 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCBA LSR */
    recomp_tick(48); g_wr16(g_longx(0x7E4042u), (uint16_t)g_cpu.C);  /* CCBB STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCBF LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CCC1 XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x1F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCC2 AND */
    recomp_tick(32); g_wr16(g_dp(0x12), (uint16_t)g_cpu.C);  /* CCC5 STA */
    recomp_tick(48); g_wr16(g_longx(0x7E3A44u), (uint16_t)g_cpu.C);  /* CCC7 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x10)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCCB LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CCCD XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x1F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCCE AND */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCD1 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x12))));  /* CCD2 SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_CCE2;  /* CCD4 BPL */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCD6 SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCD7 ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCD8 SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCD9 ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCDA SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCDB ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCDC SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCDD ROR */
    recomp_tick(14); g_cpu.flag_C = true;  /* CCDE SEC */
    recomp_tick(14); { uint16_t _v = g_ror16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCDF ROR */
    recomp_tick(16); goto L_CCE7;  /* CCE0 BRA */
L_CCE2:;
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCE2 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCE3 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCE4 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCE5 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CCE6 LSR */
L_CCE7:;
    recomp_tick(48); g_wr16(g_longx(0x7E4044u), (uint16_t)g_cpu.C);  /* CCE7 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CCEB CLC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CCEC TXA */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0006));  /* CCED ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CCF0 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CCF1 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CCF2 INY */
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* CCF3 DEC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CCFA;  /* CCF5 BEQ */
    recomp_tick(24); goto L_CC73;  /* CCF7 JMP */
L_CCFA:;
    recomp_tick(16); g_sep(0x20);  /* CCFA SEP */
    recomp_tick(14); return;  /* CCFC RTS */
}

/* $00CCFD, entered with P=$20 via JSR */
void gen_00CCFD(void) {
    goto L_CCFD;
L_CCFD:;
    recomp_tick(24); { uint16_t _v = 0x4640; g_cpu.Y = _v; g_nz16(_v); }  /* CCFD LDY */
    recomp_tick(32); g_wr16(g_dp(0x0C), (uint16_t)g_cpu.Y);  /* CD00 STY */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CD02 LDA */
    recomp_tick(24); g_wr8(g_dp(0x0E), (uint8_t)(uint8_t)g_cpu.C);  /* CD04 STA */
    recomp_tick(16); g_rep(0x20);  /* CD06 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD08 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD0A AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CD0D ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* CD0E TAY */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.C);  /* CD0F STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CD11 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD12 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x0A))));  /* CD13 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CD15 TAX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD16 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD18 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CD20;  /* CD1B BNE */
    recomp_tick(24); { uint16_t _v = 0x0100; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD1D LDA */
L_CD20:;
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CD20 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD21 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x0A))));  /* CD22 ADC */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.C);  /* CD24 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD26 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD28 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CD75;  /* CD2B BNE */
L_CD2D:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3A40u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD2D LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD31 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x7E4040u))));  /* CD32 ADC */
    recomp_tick(48); g_wr16(g_longx(0x7E3A40u), (uint16_t)g_cpu.C);  /* CD36 STA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7C00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD3A AND */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.C);  /* CD3D STA */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3A42u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD3F LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD43 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x7E4042u))));  /* CD44 ADC */
    recomp_tick(48); g_wr16(g_longx(0x7E3A42u), (uint16_t)g_cpu.C);  /* CD48 STA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x03E0); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD4C AND */
    recomp_tick(48); { uint32_t _e = g_dp(0x08); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* CD4F TSB */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3A44u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD51 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD55 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x7E4044u))));  /* CD56 ADC */
    recomp_tick(48); g_wr16(g_longx(0x7E3A44u), (uint16_t)g_cpu.C);  /* CD5A STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CD5E XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD5F AND */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x08))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD62 ORA */
    recomp_tick(32); g_wr16(g_dpily(0x0C), (uint16_t)g_cpu.C);  /* CD64 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD66 CLC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD67 TXA */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0006));  /* CD68 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CD6B TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CD6C INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CD6D INY */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_dp(0x0A)));  /* CD6E CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CD2D;  /* CD70 BCC */
    recomp_tick(16); g_sep(0x20);  /* CD72 SEP */
    recomp_tick(14); return;  /* CD74 RTS */
L_CD75:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3A40u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD75 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CD79 SEC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x7E4040u))));  /* CD7A SBC */
    recomp_tick(48); g_wr16(g_longx(0x7E3A40u), (uint16_t)g_cpu.C);  /* CD7E STA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7C00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD82 AND */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.C);  /* CD85 STA */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3A42u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD87 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CD8B SEC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x7E4042u))));  /* CD8C SBC */
    recomp_tick(48); g_wr16(g_longx(0x7E3A42u), (uint16_t)g_cpu.C);  /* CD90 STA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x03E0); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD94 AND */
    recomp_tick(48); { uint32_t _e = g_dp(0x08); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* CD97 TSB */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E3A44u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CD99 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CD9D SEC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x7E4044u))));  /* CD9E SBC */
    recomp_tick(48); g_wr16(g_longx(0x7E3A44u), (uint16_t)g_cpu.C);  /* CDA2 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CDA6 XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDA7 AND */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x08))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDAA ORA */
    recomp_tick(32); g_wr16(g_dpily(0x0C), (uint16_t)g_cpu.C);  /* CDAC STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CDAE CLC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDAF TXA */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x0006));  /* CDB0 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CDB3 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CDB4 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CDB5 INY */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_dp(0x0A)));  /* CDB6 CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CD75;  /* CDB8 BCC */
    recomp_tick(16); g_sep(0x20);  /* CDBA SEP */
    recomp_tick(14); return;  /* CDBC RTS */
}

/* $00CDBD, entered with P=$20 via JSR */
void gen_00CDBD(void) {
    goto L_CDBD;
L_CDBD:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* CDBD STX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x49)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDBF LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* CDC1 STA */
    recomp_tick(32); g_wr16(g_dp(0x03), (uint16_t)g_cpu.Y);  /* CDC3 STY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x48)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDC5 LDA */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* CDC7 STA */
    recomp_tick(16); g_rep(0x20);  /* CDC9 REP */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* CDCB LDX */
L_CDCE:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* CDCE TXY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDCF LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDD1 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CDDB;  /* CDD4 BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDD6 AND */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* CDD9 STA */
L_CDDB:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDDB LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDDD AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CDE7;  /* CDE0 BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDE2 AND */
    recomp_tick(32); g_wr16(g_dp(0x0C), (uint16_t)g_cpu.C);  /* CDE5 STA */
L_CDE7:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0C)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDE7 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CDE9 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x06))));  /* CDEA SBC */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CDEC ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CDED ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CDEE ASL */
    recomp_tick(48); g_wr16(g_longx(0x7E54A0u), (uint16_t)g_cpu.C);  /* CDEF STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDF3 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CDF5 XBA */
    recomp_tick(48); g_wr16(g_longx(0x7E4F60u), (uint16_t)g_cpu.C);  /* CDF6 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CDFA INY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDFB LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CDFD AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CE07;  /* CE00 BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE02 AND */
    recomp_tick(32); g_wr16(g_dp(0x08), (uint16_t)g_cpu.C);  /* CE05 STA */
L_CE07:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE07 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE09 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CE13;  /* CE0C BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE0E AND */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* CE11 STA */
L_CE13:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE13 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CE15 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x08))));  /* CE16 SBC */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE18 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE19 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE1A ASL */
    recomp_tick(48); g_wr16(g_longx(0x7E5660u), (uint16_t)g_cpu.C);  /* CE1B STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x08)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE1F LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CE21 XBA */
    recomp_tick(48); g_wr16(g_longx(0x7E5120u), (uint16_t)g_cpu.C);  /* CE22 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CE26 CLC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE27 TYA */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x01BF));  /* CE28 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* CE2B TAY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE2C LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE2E AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CE38;  /* CE31 BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE33 AND */
    recomp_tick(32); g_wr16(g_dp(0x0A), (uint16_t)g_cpu.C);  /* CE36 STA */
L_CE38:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpily(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE38 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE3A AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CE44;  /* CE3D BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE3F AND */
    recomp_tick(32); g_wr16(g_dp(0x10), (uint16_t)g_cpu.C);  /* CE42 STA */
L_CE44:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x10)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE44 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CE46 SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x0A))));  /* CE47 SBC */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE49 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE4A ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE4B ASL */
    recomp_tick(48); g_wr16(g_longx(0x7E5820u), (uint16_t)g_cpu.C);  /* CE4C STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE50 LDA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CE52 XBA */
    recomp_tick(48); g_wr16(g_longx(0x7E52E0u), (uint16_t)g_cpu.C);  /* CE53 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CE57 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CE58 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x01C0);  /* CE59 CPX */
    recomp_tick(16); if (g_cpu.flag_C) goto L_CE61;  /* CE5C BCS */
    recomp_tick(24); goto L_CDCE;  /* CE5E JMP */
L_CE61:;
    recomp_tick(16); g_sep(0x20);  /* CE61 SEP */
    recomp_tick(14); return;  /* CE63 RTS */
}

/* $00CE64, entered with P=$20 via JSR */
void gen_00CE64(void) {
    goto L_CE64;
L_CE64:;
    recomp_tick(24); { uint16_t _v = 0x4860; g_cpu.X = _v; g_nz16(_v); }  /* CE64 LDX */
    recomp_tick(24); { uint16_t _v = 0x4A20; g_cpu.Y = _v; g_nz16(_v); }  /* CE67 LDY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x14C6)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CE6A LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CE6D AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CE77;  /* CE6F BEQ */
    recomp_tick(24); { uint16_t _v = 0x4BE0; g_cpu.X = _v; g_nz16(_v); }  /* CE71 LDX */
    recomp_tick(24); { uint16_t _v = 0x4DA0; g_cpu.Y = _v; g_nz16(_v); }  /* CE74 LDY */
L_CE77:;
    recomp_tick(32); g_wr16(g_dp(0x03), (uint16_t)g_cpu.X);  /* CE77 STX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.Y);  /* CE79 STY */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CE7B LDA */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* CE7D STA */
    recomp_tick(24); g_wr8(g_dp(0x08), (uint8_t)(uint8_t)g_cpu.C);  /* CE7F STA */
    recomp_tick(16); g_rep(0x20);  /* CE81 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE83 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE85 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE88 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CE89 TAX */
    recomp_tick(32); g_wr16(g_dp(0x09), (uint16_t)g_cpu.C);  /* CE8A STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x01)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE8C LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE8E AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CE91 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* CE92 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x09))));  /* CE93 ADC */
    recomp_tick(32); g_wr16(g_dp(0x09), (uint16_t)g_cpu.C);  /* CE95 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE97 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE99 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CEEC;  /* CE9C BNE */
L_CE9E:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E4F60u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CE9E LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CEA2 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x7E54A0u))));  /* CEA3 ADC */
    recomp_tick(48); g_wr16(g_longx(0x7E4F60u), (uint16_t)g_cpu.C);  /* CEA7 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CEAB XBA */
    recomp_tick(16); g_sep(0x20);  /* CEAC SEP */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x20); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CEAE ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* CEB0 TXY */
    recomp_tick(24); g_wr8(g_dpily(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CEB1 STA */
    recomp_tick(16); g_rep(0x20);  /* CEB3 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E5120u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CEB5 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CEB9 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x7E5660u))));  /* CEBA ADC */
    recomp_tick(48); g_wr16(g_longx(0x7E5120u), (uint16_t)g_cpu.C);  /* CEBE STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CEC2 XBA */
    recomp_tick(16); g_sep(0x20);  /* CEC3 SEP */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CEC5 ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CEC7 INY */
    recomp_tick(24); g_wr8(g_dpily(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CEC8 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* CECA DEY */
    recomp_tick(16); g_rep(0x20);  /* CECB REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E52E0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CECD LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CED1 CLC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_longx(0x7E5820u))));  /* CED2 ADC */
    recomp_tick(48); g_wr16(g_longx(0x7E52E0u), (uint16_t)g_cpu.C);  /* CED6 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CEDA XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CEDB AND */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0x0080); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CEDE ORA */
    recomp_tick(32); g_wr16(g_dpily(0x06), (uint16_t)g_cpu.C);  /* CEE1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CEE3 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CEE4 INX */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_dp(0x09)));  /* CEE5 CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CE9E;  /* CEE7 BCC */
    recomp_tick(16); g_sep(0x20);  /* CEE9 SEP */
    recomp_tick(14); return;  /* CEEB RTS */
L_CEEC:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E4F60u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CEEC LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CEF0 SEC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x7E54A0u))));  /* CEF1 SBC */
    recomp_tick(48); g_wr16(g_longx(0x7E4F60u), (uint16_t)g_cpu.C);  /* CEF5 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CEF9 XBA */
    recomp_tick(16); g_sep(0x20);  /* CEFA SEP */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x20); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CEFC ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.Y = _v; g_nz16(_v); }  /* CEFE TXY */
    recomp_tick(24); g_wr8(g_dpily(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CEFF STA */
    recomp_tick(16); g_rep(0x20);  /* CF01 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E5120u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CF03 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CF07 SEC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x7E5660u))));  /* CF08 SBC */
    recomp_tick(48); g_wr16(g_longx(0x7E5120u), (uint16_t)g_cpu.C);  /* CF0C STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CF10 XBA */
    recomp_tick(16); g_sep(0x20);  /* CF11 SEP */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF13 ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CF15 INY */
    recomp_tick(24); g_wr8(g_dpily(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CF16 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* CF18 DEY */
    recomp_tick(16); g_rep(0x20);  /* CF19 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E52E0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CF1B LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CF1F SEC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x7E5820u))));  /* CF20 SBC */
    recomp_tick(48); g_wr16(g_longx(0x7E52E0u), (uint16_t)g_cpu.C);  /* CF24 STA */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* CF28 XBA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x001F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CF29 AND */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0x0080); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* CF2C ORA */
    recomp_tick(32); g_wr16(g_dpily(0x06), (uint16_t)g_cpu.C);  /* CF2F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CF31 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CF32 INX */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_dp(0x09)));  /* CF33 CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CEEC;  /* CF35 BCC */
    recomp_tick(16); g_sep(0x20);  /* CF37 SEP */
    recomp_tick(14); return;  /* CF39 RTS */
}

/* $00D32F, entered with P=$20 via JSR */
void gen_00D32F(void) {
    goto L_D32F;
L_D32F:;
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* D32F STX */
    recomp_tick(16); g_rep(0x20);  /* D331 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D333 TXA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D334 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D335 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D336 LSR */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* D337 STA */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_abs(0x14D3)));  /* D339 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D347;  /* D33C BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D33E TYA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D33F LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D340 LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D341 LSR */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_abs(0x14D5)));  /* D342 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D34C;  /* D345 BCC */
L_D347:;
    recomp_tick(16); g_sep(0x20);  /* D347 SEP */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D349 LDA */
    recomp_tick(14); return;  /* D34B RTS */
L_D34C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D34C TYA */
    recomp_tick(24); g_bit16(0x0008, true);  /* D34D BIT */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D355;  /* D350 BEQ */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0x0400); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D352 ORA */
L_D355:;
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x07F0); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D355 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D358 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D359 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D35A ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D35B CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* D35C ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D35E TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7F8000u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D35F LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D363 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D366 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D367 ASL */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* D368 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D36A LDA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D36C LSR */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D36D LSR */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x0001); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D36E AND */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* D371 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D373 TYA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D374 LSR */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x0002); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D375 AND */
    recomp_tick(14); g_cpu.flag_C = false;  /* D378 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* D379 ADC */
    recomp_tick(14); g_cpu.flag_C = false;  /* D37B CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* D37C ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D37E TAX */
    recomp_tick(16); g_sep(0x20);  /* D37F SEP */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7FC000u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D381 LDA */
    recomp_tick(14); return;  /* D385 RTS */
}

/* $00D4FE, entered with P=$20 via JSR */
void gen_00D4FE(void) {
    goto L_D4FE;
L_D4FE:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D4FE PHA */
    recomp_tick(16); g_rep(0x20);  /* D4FF REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D501 TXA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D502 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D505 ASL */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* D506 XBA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* D507 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D509 TYA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D50A AND */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D50D LSR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D50E ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D510 TAX */
    recomp_tick(16); g_sep(0x20);  /* D511 SEP */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D513 PLA */
    recomp_tick(16); goto L_D516;  /* D514 BRA */
L_D516:;
    recomp_tick(24); g_wr8(g_dp(0x0B), (uint8_t)(uint8_t)g_cpu.C);  /* D516 STA */
    recomp_tick(32); g_wr16(g_dp(0x0C), (uint16_t)g_cpu.X);  /* D518 STX */
    recomp_tick(14); g_push8(g_cpu.DB);  /* D51A PHB */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D51B LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D51D PHA */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* D51E PLB */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D51F TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D520 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D522 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D523 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D524 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x0B)))));  /* D525 ADC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D527 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D528 ASL */
    recomp_tick(16); g_rep(0x20);  /* D529 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* D52B CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0xD7F1));  /* D52C ADC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* D52F STA */
    recomp_tick(16); g_sep(0x20);  /* D531 SEP */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D533 LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* D535 STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* D537 LDX */
L_D53A:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* D53A STX */
    recomp_tick(24); g_wr8(g_dp(0x0A), 0);  /* D53C STZ */
    recomp_tick(16); g_rep(0x20);  /* D53E REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D540 TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D541 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* D542 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D543 TAX */
    recomp_tick(16); g_sep(0x20);  /* D544 SEP */
    recomp_tick(16); { uint8_t _v = 0x04; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D546 LDA */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* D548 STA */
L_D54A:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D54A TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7FC000u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D54B LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x13);  /* D54F CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D555;  /* D551 BCC */
    recomp_tick(16); { uint8_t _v = 0x13; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D553 LDA */
L_D555:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* D555 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D556 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x0A)));  /* D558 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D55E;  /* D55A BCC */
    recomp_tick(24); g_wr8(g_dp(0x0A), (uint8_t)(uint8_t)g_cpu.C);  /* D55C STA */
L_D55E:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D55E INX */
    recomp_tick(32); { uint32_t _e = g_dp(0x06); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* D55F DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D54A;  /* D561 BNE */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* D563 LDX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D565 LDA */
    recomp_tick(32); g_wr8(g_absx(0xCF28), (uint8_t)(uint8_t)g_cpu.C);  /* D567 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D56A INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0100);  /* D56B CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D53A;  /* D56E BCC */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* D570 LDX */
    recomp_tick(16); g_rep(0x20);  /* D573 REP */
L_D575:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D575 LDA */
    recomp_tick(40); g_wr16(g_absx(0xAF28), (uint16_t)g_cpu.C);  /* D578 STA */
    recomp_tick(24); { uint16_t _v = 0x7FFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D57B LDA */
    recomp_tick(40); g_wr16(g_absx(0x8F28), (uint16_t)g_cpu.C);  /* D57E STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D581 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D582 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x2000);  /* D583 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D575;  /* D586 BNE */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0C)); g_cpu.X = _v; g_nz16(_v); }  /* D588 LDX */
    recomp_tick(40); g_wr16(g_absx(0x8F28), 0);  /* D58A STZ */
    recomp_tick(16); g_sep(0x20);  /* D58D SEP */
    recomp_tick(30); g_push16(0xD591); func_table_call_jsr(0x00D5B3); g_cpu.S += 2;  /* D58F JSR */
L_D592:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* D592 LDX */
L_D595:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* D595 PHX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0xAF28)); g_cpu.Y = _v; g_nz16(_v); }  /* D596 LDY */
    recomp_tick(16); if (g_cpu.flag_N) goto L_D5A9;  /* D599 BMI */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x8F28)); g_cpu.Y = _v; g_nz16(_v); }  /* D59B LDY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x7FFF);  /* D59E CPY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5A9;  /* D5A1 BEQ */
    recomp_tick(30); g_push16(0xD5A5); func_table_call_jsr(0x00D5B3); g_cpu.S += 2;  /* D5A3 JSR */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* D5A6 PLX */
    recomp_tick(16); goto L_D592;  /* D5A7 BRA */
L_D5A9:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* D5A9 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D5AA INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D5AB INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x2000);  /* D5AC CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D595;  /* D5AF BCC */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* D5B1 PLB */
    recomp_tick(14); return;  /* D5B2 RTS */
}

/* $00D5B3, entered with P=$20 via JSR */
void gen_00D5B3(void) {
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

/* $00D791, entered with P=$20 via JSR */
void gen_00D791(void) {
    goto L_D791;
L_D791:;
    recomp_tick(14); g_push8(g_cpu.DB);  /* D791 PHB */
    recomp_tick(16); { uint8_t _v = 0x7F; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D792 LDA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D794 PHA */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* D795 PLB */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* D796 LDX */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* D799 LDY */
L_D79C:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* D79C PHY */
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D79D LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* D79F STA */
L_D7A1:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0000)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7A1 LDA */
    recomp_tick(32); g_wr8(g_absy(0x8000), (uint8_t)(uint8_t)g_cpu.C);  /* D7A4 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D7A7 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D7A8 INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* D7A9 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D7A1;  /* D7AB BNE */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* D7AD PLY */
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7AE LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* D7B0 STA */
L_D7B2:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0000)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7B2 LDA */
    recomp_tick(32); g_wr8(g_absy(0xA000), (uint8_t)(uint8_t)g_cpu.C);  /* D7B5 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D7B8 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D7B9 INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* D7BA DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D7B2;  /* D7BC BNE */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x4000);  /* D7BE CPX */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_D79C;  /* D7C1 BCC */
    recomp_tick(14); g_cpu.DB = g_pull8(); g_nz8(g_cpu.DB);  /* D7C3 PLB */
    recomp_tick(14); return;  /* D7C4 RTS */
}

/* $00F85A, entered with P=$20 via JSR */
void gen_00F85A(void) {
    goto L_F85A;
L_F85A:;
    recomp_tick(24); { uint16_t _v = 0x007F; g_cpu.X = _v; g_nz16(_v); }  /* F85A LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F85D TDC */
L_F85E:;
    recomp_tick(40); g_wr8(g_longx(0x7E5AE0u), (uint8_t)(uint8_t)g_cpu.C);  /* F85E STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* F862 DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_F85E;  /* F863 BPL */
    recomp_tick(14); return;  /* F865 RTS */
}

/* $00F866, entered with P=$20 via JSR */
void gen_00F866(void) {
    goto L_F866;
L_F866:;
    recomp_tick(24); { uint16_t _v = 0x00FF; g_cpu.X = _v; g_nz16(_v); }  /* F866 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F869 TDC */
L_F86A:;
    recomp_tick(40); g_wr8(g_longx(0x7E59E0u), (uint8_t)(uint8_t)g_cpu.C);  /* F86A STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* F86E DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_F86A;  /* F86F BPL */
    recomp_tick(24); { uint16_t _v = 0x007F; g_cpu.X = _v; g_nz16(_v); }  /* F871 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F874 TDC */
L_F875:;
    recomp_tick(40); g_wr8(g_longx(0x7E5B60u), (uint8_t)(uint8_t)g_cpu.C);  /* F875 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* F879 DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_F875;  /* F87A BPL */
    recomp_tick(14); return;  /* F87C RTS */
}

void gen_register_bank_00(void) {
    func_table_register_flags(0x008202, gen_008202, false);
    func_table_register_flags(0x00827D, gen_00827D, false);
    func_table_register_flags(0x00855D, gen_00855D, false);
    func_table_register_flags(0x0087BD, gen_0087BD, false);
    func_table_register_flags(0x008803, gen_008803, false);
    func_table_register_flags(0x00883A, gen_00883A, false);
    func_table_register_flags(0x008914, gen_008914, false);
    func_table_register_flags(0x008B43, gen_008B43, false);
    func_table_register_flags(0x008DD2, gen_008DD2, false);
    func_table_register_flags(0x008DE3, gen_008DE3, false);
    func_table_register_flags(0x008DFB, gen_008DFB, false);
    func_table_register_flags(0x008E22, gen_008E22, false);
    func_table_register_flags(0x008E62, gen_008E62, false);
    func_table_register_flags(0x00966F, gen_00966F, false);
    func_table_register_flags(0x009709, gen_009709, false);
    func_table_register_flags(0x0099F4, gen_0099F4, false);
    func_table_register_flags(0x009A0E, gen_009A0E, false);
    func_table_register_flags(0x009A55, gen_009A55, false);
    func_table_register_flags(0x00A37A, gen_00A37A, false);
    func_table_register_flags(0x00A383, gen_00A383, false);
    func_table_register_flags(0x00A391, gen_00A391, false);
    func_table_register_flags(0x00AA52, gen_00AA52, false);
    func_table_register_flags(0x00ACD2, gen_00ACD2, false);
    func_table_register_flags(0x00AD13, gen_00AD13, false);
    func_table_register_flags(0x00AF87, gen_00AF87, false);
    func_table_register_flags(0x00B154, gen_00B154, false);
    func_table_register_flags(0x00B399, gen_00B399, false);
    func_table_register_flags(0x00BA28, gen_00BA28, false);
    func_table_register_flags(0x00BA75, gen_00BA75, false);
    func_table_register_flags(0x00BAC7, gen_00BAC7, false);
    func_table_register_flags(0x00BBFB, gen_00BBFB, false);
    func_table_register_flags(0x00BC0E, gen_00BC0E, false);
    func_table_register_flags(0x00BC22, gen_00BC22, false);
    func_table_register_flags(0x00BD78, gen_00BD78, false);
    func_table_register_flags(0x00BD99, gen_00BD99, false);
    func_table_register_flags(0x00C755, gen_00C755, false);
    func_table_register_flags(0x00CA6E, gen_00CA6E, false);
    func_table_register_flags(0x00CC4C, gen_00CC4C, false);
    func_table_register_flags(0x00CCFD, gen_00CCFD, false);
    func_table_register_flags(0x00CDBD, gen_00CDBD, false);
    func_table_register_flags(0x00CE64, gen_00CE64, false);
    func_table_register_flags(0x00D32F, gen_00D32F, false);
    func_table_register_flags(0x00D4FE, gen_00D4FE, false);
    func_table_register_flags(0x00D5B3, gen_00D5B3, false);
    func_table_register_flags(0x00D791, gen_00D791, false);
    func_table_register_flags(0x00F85A, gen_00F85A, false);
    func_table_register_flags(0x00F866, gen_00F866, false);
}
