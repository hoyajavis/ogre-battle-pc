/* Bank $02 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 96 lifted, 244 unlifted in Bank $02 */
/* not lifted: $028000: calls unlifted target 0x028052: executes native on LakeSnes */
/* not lifted: $028014: calls unlifted target 0x028052: executes native on LakeSnes */
/* not lifted: $028052: COP at $02:806A */
/* not lifted: $028099: calls unlifted target 0x02FD30: executes native on LakeSnes */
/* not lifted: $028199: calls unlifted target 0x028426: executes native on LakeSnes */
/* not lifted: $0281DE: calls unlifted target 0x028426: executes native on LakeSnes */
/* not lifted: $0281F2: calls unlifted target 0x02DA11: executes native on LakeSnes */
/* not lifted: $028207: calls unlifted target 0x02DA1F: executes native on LakeSnes */
/* not lifted: $02828A: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $028335: BRK at $02:838C */
/* not lifted: $028400: PLA at $840B pulls below the entry stack (return-address trick) */
/* not lifted: $028505: calls unlifted target 0x02F2BD: executes native on LakeSnes */
/* not lifted: $02853A: calls unlifted target 0x02DA26: executes native on LakeSnes */
/* not lifted: $0285FB: calls unlifted target 0x02DA26: executes native on LakeSnes */
/* not lifted: $02867A: calls unlifted target 0x02DA26: executes native on LakeSnes */
/* not lifted: $028700: calls unlifted target 0x02DA1F: executes native on LakeSnes */
/* not lifted: $028757: calls unlifted target 0x02DA26: executes native on LakeSnes */
/* not lifted: $0287BC: calls unlifted target 0x02DA1F: executes native on LakeSnes */
/* not lifted: $02880D: BRK at $02:88FB */
/* not lifted: $028931: calls unlifted target 0x02893E: executes native on LakeSnes */
/* not lifted: $02893E: BRK at $02:8949 */
/* not lifted: $02894E: calls unlifted target 0x02DA1F: executes native on LakeSnes */
/* not lifted: $028A08: BRK at $02:8A1D */
/* not lifted: $028A20: calls unlifted target 0x028D4B: executes native on LakeSnes */
/* not lifted: $028A3A: BRK at $02:8A57 */
/* not lifted: $028C60: BRK at $02:8C62 */
/* not lifted: $028D4B: BRK at $02:8D59 */
/* not lifted: $028E01: calls unlifted target 0x028ECD: executes native on LakeSnes */
/* not lifted: $028E04: calls unlifted target 0x028ECD: executes native on LakeSnes */
/* not lifted: $028E6D: calls unlifted target 0x028E78: executes native on LakeSnes */
/* not lifted: $028E78: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $028EC6: BRK at $02:8ECB */
/* not lifted: $028ECD: BRK at $02:8ED2 */
/* not lifted: $028ED4: BRK at $02:8EE7 */
/* not lifted: $028EE9: calls unlifted target 0x02DA3C: executes native on LakeSnes */
/* not lifted: $02952B: RTS at $954C with 6 bytes still pushed */
/* not lifted: $02954D: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02954F: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $029556: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $029594: BRK at $02:95B3 */
/* not lifted: $0296DE: calls unlifted target 0x02AD29: executes native on LakeSnes */
/* not lifted: $029723: calls unlifted target 0x02AD29: executes native on LakeSnes */
/* not lifted: $029738: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02973B: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $0297D1: calls unlifted target 0x02AD29: executes native on LakeSnes */
/* not lifted: $0298C6: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $029943: calls unlifted target 0x02BE28: executes native on LakeSnes */
/* not lifted: $0299B5: calls unlifted target 0x028757: executes native on LakeSnes */
/* not lifted: $0299BD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $029AA1: PLB at $9AFD pulls below the entry stack (return-address trick) */
/* not lifted: $029B08: calls RAM trampoline/sub-8000 ($027CA5): executes native on LakeSnes */
/* not lifted: $029B88: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $029B99: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $029BA8: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $029BB7: calls unlifted target 0x02BAEF: executes native on LakeSnes */
/* not lifted: $029C04: BRK at $02:96CD */
/* not lifted: $029C24: calls unlifted target 0x02B828: executes native on LakeSnes */
/* not lifted: $029CB3: calls unlifted target 0x02D9B5: executes native on LakeSnes */
/* not lifted: $029E35: calls unlifted target 0x02B828: executes native on LakeSnes */
/* not lifted: $029F1C: calls unlifted target 0x02B828: executes native on LakeSnes */
/* not lifted: $02A024: calls unlifted target 0x02F965: executes native on LakeSnes */
/* not lifted: $02A599: BRK at $02:A59F */
/* not lifted: $02A724: calls unlifted target 0x02A814: executes native on LakeSnes */
/* not lifted: $02A74E: calls unlifted target 0x02A7CD: executes native on LakeSnes */
/* not lifted: $02A7CD: calls unlifted target 0x02A86C: executes native on LakeSnes */
/* not lifted: $02A814: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02A83F: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02A86C: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02A8BC: calls unlifted target 0x029594: executes native on LakeSnes */
/* not lifted: $02A9B9: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02A9E0: calls unlifted target 0x02A8BC: executes native on LakeSnes */
/* not lifted: $02AA06: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02AA27: calls unlifted target 0x029594: executes native on LakeSnes */
/* not lifted: $02AAFF: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02ACB2: BRK at $02:ACC8 */
/* not lifted: $02ACCA: BRK at $02:ACCF */
/* not lifted: $02ACD1: calls unlifted target 0x02F9B2: executes native on LakeSnes */
/* not lifted: $02ACEC: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $02AD29: PLA at $ACE1 pulls below the entry stack (return-address trick) */
/* not lifted: $02AD66: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02AD88: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02ADC2: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02AE7A: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02AEA3: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02AEC9: BRK at $02:ECEE */
/* not lifted: $02AED9: calls unlifted target 0x02EC2D: executes native on LakeSnes */
/* not lifted: $02AEE1: calls unlifted target 0x02B26B: executes native on LakeSnes */
/* not lifted: $02B26B: TXS at $02:B2CC */
/* not lifted: $02B28B: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02B297: TXS at $02:B2CC */
/* not lifted: $02B2EC: RTS at $B357 with 2 bytes still pushed */
/* not lifted: $02B358: RTS at $B3B5 with 2 bytes still pushed */
/* not lifted: $02B458: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02B504: calls unlifted target 0x02A86C: executes native on LakeSnes */
/* not lifted: $02B524: calls unlifted target 0x02B828: executes native on LakeSnes */
/* not lifted: $02B568: BRK at $02:B576 */
/* not lifted: $02B610: calls unlifted target 0x02B828: executes native on LakeSnes */
/* not lifted: $02B744: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02B786: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02B7C8: calls unlifted target 0x02DA34: executes native on LakeSnes */
/* not lifted: $02B828: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02B900: calls unlifted target 0x02B904: executes native on LakeSnes */
/* not lifted: $02B904: RTS at $B9E8 with 2 bytes still pushed */
/* not lifted: $02B9E9: calls unlifted target 0x02F70F: executes native on LakeSnes */
/* not lifted: $02BA1C: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02BAEF: calls unlifted target 0x02AD29: executes native on LakeSnes */
/* not lifted: $02BB02: BRK at $02:BBE3 */
/* not lifted: $02BC01: calls unlifted target 0x02BC28: executes native on LakeSnes */
/* not lifted: $02BC28: calls unlifted target 0x02BC3A: executes native on LakeSnes */
/* not lifted: $02BC3A: BRK at $02:BCB3 */
/* not lifted: $02BD84: BRK at $02:BD91 */
/* not lifted: $02BD9D: BRK at $02:BDA5 */
/* not lifted: $02BDC5: RTI at $BDF7 with 3 bytes still pushed */
/* not lifted: $02BDCA: calls unlifted target 0x02BDF2: executes native on LakeSnes */
/* not lifted: $02BDF2: RTI at $BDF7 with 3 bytes still pushed */
/* not lifted: $02BE09: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02BE28: calls unlifted target 0x02DA11: executes native on LakeSnes */
/* not lifted: $02BE66: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $02BE7B: tail jump at $C0AE with 2 bytes pushed */
/* not lifted: $02BF00: tail jump at $C0AE with 2 bytes pushed */
/* not lifted: $02BFFA: BRK at $02:BE8D */
/* not lifted: $02C13F: RTS at $C153 with 2 bytes still pushed */
/* not lifted: $02C220: BRK at $02:C231 */
/* not lifted: $02C245: calls unlifted target 0x029594: executes native on LakeSnes */
/* not lifted: $02C2E8: tail jump at $C0AE with 2 bytes pushed */
/* not lifted: $02C426: BRK at $02:C453 */
/* not lifted: $02C4BE: calls unlifted target 0x02B744: executes native on LakeSnes */
/* not lifted: $02C5A1: calls unlifted target 0x02C769: executes native on LakeSnes */
/* not lifted: $02C6B9: BRK at $02:C6E6 */
/* not lifted: $02C737: calls unlifted target 0x02DA11: executes native on LakeSnes */
/* not lifted: $02C74F: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $02C769: BRK at $02:C771 */
/* not lifted: $02C932: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02C952: calls unlifted target 0x02DA0E: executes native on LakeSnes */
/* not lifted: $02CD0B: calls unlifted target 0x02F34D: executes native on LakeSnes */
/* not lifted: $02D191: BRK at $02:D269 */
/* not lifted: $02D293: $02:D2A8 reached with two different M/X/stack states */
/* not lifted: $02D2D6: calls unlifted target 0x02DA26: executes native on LakeSnes */
/* not lifted: $02D2F1: BRK at $02:D2F6 */
/* not lifted: $02D31E: BRK at $02:D323 */
/* not lifted: $02D34B: BRK at $02:D356 */
/* not lifted: $02D37B: BRK at $02:D37D */
/* not lifted: $02D388: BRK at $02:D3A4 */
/* not lifted: $02D411: PLX at $D431 pulls below the entry stack (return-address trick) */
/* not lifted: $02D4F3: calls unlifted target 0x02D9B5: executes native on LakeSnes */
/* not lifted: $02D631: calls unlifted target 0x029594: executes native on LakeSnes */
/* not lifted: $02D650: calls unlifted target 0x029594: executes native on LakeSnes */
/* not lifted: $02D766: BRK at $02:D776 */
/* not lifted: $02D790: calls unlifted target 0x029594: executes native on LakeSnes */
/* not lifted: $02D852: calls unlifted target 0x02D85A: executes native on LakeSnes */
/* not lifted: $02D85A: calls unlifted target 0x02F2BD: executes native on LakeSnes */
/* not lifted: $02D861: calls unlifted target 0x02BD84: executes native on LakeSnes */
/* not lifted: $02D918: calls unlifted target 0x02D766: executes native on LakeSnes */
/* not lifted: $02D9B5: BRK at $02:D9C0 */
/* not lifted: $02DA07: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02DA0E: BRK at $02:DA16 */
/* not lifted: $02DA11: BRK at $02:DA16 */
/* not lifted: $02DA18: PLD at $DA1B pulls below the entry stack (return-address trick) */
/* not lifted: $02DA1F: BRK at $02:DA24 */
/* not lifted: $02DA26: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02DA2D: BRK at $02:DA16 */
/* not lifted: $02DA34: BRK at $02:DA16 */
/* not lifted: $02DA3C: BRK at $02:DA16 */
/* not lifted: $02DA41: BRK at $02:DF27 */
/* not lifted: $02DBF2: BRK at $02:C9AD */
/* not lifted: $02DBF9: BRK at $02:C9AD */
/* not lifted: $02E003: BRK at $02:DEE4 */
/* not lifted: $02E06A: BRK at $02:E08A */
/* not lifted: $02E1DA: PLX at $E860 pulls below the entry stack (return-address trick) */
/* not lifted: $02E424: BRK at $02:E456 */
/* not lifted: $02E6F8: RTS at $E723 with 1 bytes still pushed */
/* not lifted: $02E73C: calls unlifted target 0x02E791: executes native on LakeSnes */
/* not lifted: $02E774: calls unlifted target 0x02E79C: executes native on LakeSnes */
/* not lifted: $02E791: tail jump at $E834 with 4 bytes pushed */
/* not lifted: $02E79C: tail jump at $E834 with 4 bytes pushed */
/* not lifted: $02E841: calls unlifted target 0x02E9B2: executes native on LakeSnes */
/* not lifted: $02E845: BRK at $02:E84A */
/* not lifted: $02E87D: calls unlifted target 0x02E774: executes native on LakeSnes */
/* not lifted: $02E8A7: PLA at $E8B0 pulls below the entry stack (return-address trick) */
/* not lifted: $02E8B5: RTS at $E8CD with 2 bytes still pushed */
/* not lifted: $02E8CE: calls unlifted target 0x02F34D: executes native on LakeSnes */
/* not lifted: $02E902: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02E909: calls unlifted target 0x02E962: executes native on LakeSnes */
/* not lifted: $02E962: COP at $02:E97A */
/* not lifted: $02E9B2: calls unlifted target 0x02E9E1: executes native on LakeSnes */
/* not lifted: $02E9E1: BRK at $02:EA77 */
/* not lifted: $02EAAF: calls unlifted target 0x02EB7A: executes native on LakeSnes */
/* not lifted: $02EADB: calls unlifted target 0x02EB7A: executes native on LakeSnes */
/* not lifted: $02EAFA: calls unlifted target 0x02EB7A: executes native on LakeSnes */
/* not lifted: $02EB7A: calls unlifted target 0x02EBAA: executes native on LakeSnes */
/* not lifted: $02EBAA: BRK at $02:EBD1 */
/* not lifted: $02EBD3: BRK at $02:EBEF */
/* not lifted: $02EBF1: BRK at $02:EC0D */
/* not lifted: $02EC0F: BRK at $02:EC2B */
/* not lifted: $02EC2D: calls RAM trampoline/sub-8000 ($021199): executes native on LakeSnes */
/* not lifted: $02EC3B: calls unlifted target 0x02EC2D: executes native on LakeSnes */
/* not lifted: $02EC5C: calls unlifted target 0x02EC2D: executes native on LakeSnes */
/* not lifted: $02EC69: calls unlifted target 0x02EC2D: executes native on LakeSnes */
/* not lifted: $02EC8A: BRK at $02:ECEE */
/* not lifted: $02EC90: BRK at $02:ECEE */
/* not lifted: $02EC97: BRK at $02:ECEE */
/* not lifted: $02F004: BRK at $02:ECEE */
/* not lifted: $02F1E8: RTS at $F222 with 1 bytes still pushed */
/* not lifted: $02F1F5: calls unlifted target 0x02EBD3: executes native on LakeSnes */
/* not lifted: $02F1FA: calls unlifted target 0x02EBF1: executes native on LakeSnes */
/* not lifted: $02F223: COP at $02:F228 */
/* not lifted: $02F251: calls unlifted target 0x02EC0F: executes native on LakeSnes */
/* not lifted: $02F28A: calls unlifted target 0x02DA11: executes native on LakeSnes */
/* not lifted: $02F2A2: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $02F2BD: BRK at $02:F2C5 */
/* not lifted: $02F2CD: BRK at $02:F2D5 */
/* not lifted: $02F2DD: PLX at $F346 pulls below the entry stack (return-address trick) */
/* not lifted: $02F2ED: PLX at $F346 pulls below the entry stack (return-address trick) */
/* not lifted: $02F34D: BRK at $02:F3DE */
/* not lifted: $02F369: BRK at $02:F3DE */
/* not lifted: $02F483: calls unlifted target 0x02F9F0: executes native on LakeSnes */
/* not lifted: $02F4BE: calls unlifted target 0x02F9F0: executes native on LakeSnes */
/* not lifted: $02F4DA: calls unlifted target 0x02F9F0: executes native on LakeSnes */
/* not lifted: $02F4F6: BRK at $02:F58C */
/* not lifted: $02F5E0: calls unlifted target 0x02F8E4: executes native on LakeSnes */
/* not lifted: $02F70F: calls unlifted target 0x02F8E4: executes native on LakeSnes */
/* not lifted: $02F853: calls unlifted target 0x02F8C0: executes native on LakeSnes */
/* not lifted: $02F880: calls unlifted target 0x02F893: executes native on LakeSnes */
/* not lifted: $02F893: calls unlifted target 0x02F8E4: executes native on LakeSnes */
/* not lifted: $02F8C0: calls unlifted target 0x02F8E4: executes native on LakeSnes */
/* not lifted: $02F8E4: calls unlifted target 0x02F905: executes native on LakeSnes */
/* not lifted: $02F8EF: calls unlifted target 0x02F905: executes native on LakeSnes */
/* not lifted: $02F905: calls unlifted target 0x02DA07: executes native on LakeSnes */
/* not lifted: $02F965: calls RAM trampoline/sub-8000 ($027FA9): executes native on LakeSnes */
/* not lifted: $02F9B2: calls unlifted target 0x00A773: executes native on LakeSnes */
/* not lifted: $02F9F0: PLY at $F9F8 pulls below the entry stack (return-address trick) */
/* not lifted: $02FB1F: PLY at $FB27 pulls below the entry stack (return-address trick) */
/* not lifted: $02FBDE: PLA at $FBEC pulls below the entry stack (return-address trick) */
/* not lifted: $02FC29: calls unlifted target 0x02FC49: executes native on LakeSnes */
/* not lifted: $02FC49: calls unlifted target 0x02FCB4: executes native on LakeSnes */
/* not lifted: $02FC6E: calls unlifted target 0x02FC90: executes native on LakeSnes */
/* not lifted: $02FC90: calls unlifted target 0x02FCB4: executes native on LakeSnes */
/* not lifted: $02FCB4: calls unlifted target 0x02FCD5: executes native on LakeSnes */
/* not lifted: $02FCBF: calls unlifted target 0x02FCD5: executes native on LakeSnes */
/* not lifted: $02FCD5: calls unlifted target 0x02DA1F: executes native on LakeSnes */
/* not lifted: $02FD17: calls unlifted target 0x05CE98: executes native on LakeSnes */
/* not lifted: $02FD26: calls unlifted target 0x05CFC7: executes native on LakeSnes */
/* not lifted: $02FD2B: calls unlifted target 0x05D04E: executes native on LakeSnes */
/* not lifted: $02FD30: calls unlifted target 0x05D092: executes native on LakeSnes */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $02813E, entered with P=$20 via JSR */
void gen_02813E(void) {
    goto L_813E;
L_813E:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04E2)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 813E LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* 8141 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8149;  /* 8143 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x01);  /* 8145 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_815A;  /* 8147 BNE */
L_8149:;
    recomp_tick(24); { uint16_t _v = 0x0002; g_cpu.X = _v; g_nz16(_v); }  /* 8149 LDX */
    recomp_tick(40); g_wr16(g_abs(0x04D0), (uint16_t)g_cpu.X);  /* 814C STX */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 814F LDA */
    recomp_tick(32); g_wr8(g_abs(0x04D2), (uint8_t)(uint8_t)g_cpu.C);  /* 8151 STA */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8154 LDA */
    recomp_tick(32); g_wr8(g_abs(0x04D3), (uint8_t)(uint8_t)g_cpu.C);  /* 8156 STA */
    recomp_tick(14); return;  /* 8159 RTS */
L_815A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* 815A LDX */
    recomp_tick(40); g_wr16(g_abs(0x04D0), (uint16_t)g_cpu.X);  /* 815C STX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x04D0)); g_cpu.X = _v; g_nz16(_v); }  /* 815F LDX */
    recomp_tick(40); { uint32_t _e = g_abs(0x04D0); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8162 INC */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8165 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04D2), (uint8_t)(uint8_t)g_cpu.C);  /* 8167 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x04D0)); g_cpu.X = _v; g_nz16(_v); }  /* 816A LDX */
    recomp_tick(40); { uint32_t _e = g_abs(0x04D0); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 816D INC */
    recomp_tick(16); { uint8_t _v = 0x08; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8170 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04D2), (uint8_t)(uint8_t)g_cpu.C);  /* 8172 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8175 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_818A;  /* 8178 BEQ */
    recomp_tick(30); g_push16(0x817C); func_table_call_jsr(0x028455); g_cpu.S += 2;  /* 817A JSR */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_818A;  /* 817D BCC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x04D0)); g_cpu.X = _v; g_nz16(_v); }  /* 817F LDX */
    recomp_tick(40); { uint32_t _e = g_abs(0x04D0); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8182 INC */
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8185 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04D2), (uint8_t)(uint8_t)g_cpu.C);  /* 8187 STA */
L_818A:;
    recomp_tick(30); g_push16(0x818C); func_table_call_jsr(0x02857F); g_cpu.S += 2;  /* 818A JSR */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x04D0)); g_cpu.X = _v; g_nz16(_v); }  /* 818D LDX */
    recomp_tick(40); { uint32_t _e = g_abs(0x04D0); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 8190 INC */
    recomp_tick(16); { uint8_t _v = 0x20; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8193 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04D2), (uint8_t)(uint8_t)g_cpu.C);  /* 8195 STA */
    recomp_tick(14); return;  /* 8198 RTS */
}

/* $0283C8, entered with P=$20 via JSR */
void gen_0283C8(void) {
    goto L_83C8;
L_83C8:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 83C8 PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x14DE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83C9 LDA */
    recomp_tick(32); g_wr8(g_abs(0x174D), (uint8_t)(uint8_t)g_cpu.C);  /* 83CC STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x14E0)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83CF LDA */
    recomp_tick(32); g_wr8(g_abs(0x174F), (uint8_t)(uint8_t)g_cpu.C);  /* 83D2 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83D5 PLA */
    recomp_tick(14); return;  /* 83D6 RTS */
}

/* $0283D7, entered with P=$20 via JSR */
void gen_0283D7(void) {
    goto L_83D7;
L_83D7:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 83D7 PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x174D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83D8 LDA */
    recomp_tick(32); g_wr8(g_abs(0x14DE), (uint8_t)(uint8_t)g_cpu.C);  /* 83DB STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x174F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83DE LDA */
    recomp_tick(32); g_wr8(g_abs(0x14E0), (uint8_t)(uint8_t)g_cpu.C);  /* 83E1 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83E4 PLA */
    recomp_tick(14); return;  /* 83E5 RTS */
}

/* $0283E6, entered with P=$20 via JSR */
void gen_0283E6(void) {
    goto L_83E6;
L_83E6:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 83E6 PHX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0104)); g_cpu.X = _v; g_nz16(_v); }  /* 83E7 LDX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xE001);  /* 83EA CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_840C;  /* 83ED BEQ */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 83EF PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0300)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83F0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xF3); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83F3 AND */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x04); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83F5 ORA */
    recomp_tick(32); g_wr8(g_abs(0x0300), (uint8_t)(uint8_t)g_cpu.C);  /* 83F7 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0476)); g_cpu.Y = _v; g_nz16(_v); }  /* 83FA LDY */
    recomp_tick(40); g_wr16(g_abs(0x0467), (uint16_t)g_cpu.Y);  /* 83FD STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* 8400 LDY */
    recomp_tick(40); g_wr16(g_abs(0x0476), (uint16_t)g_cpu.Y);  /* 8402 STY */
    recomp_tick(24); { uint16_t _v = 0xE001; g_cpu.X = _v; g_nz16(_v); }  /* 8405 LDX */
    recomp_tick(40); g_wr16(g_abs(0x0104), (uint16_t)g_cpu.X);  /* 8408 STX */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 840B PLA */
L_840C:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 840C PLX */
    recomp_tick(14); return;  /* 840D RTS */
}

/* $02840E, entered with P=$20 via JSR */
void gen_02840E(void) {
    goto L_840E;
L_840E:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 840E PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0300)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 840F LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x04); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8412 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8424;  /* 8414 BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0300)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8416 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0xFB); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8419 AND */
    recomp_tick(32); g_wr8(g_abs(0x0300), (uint8_t)(uint8_t)g_cpu.C);  /* 841B STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0467)); g_cpu.Y = _v; g_nz16(_v); }  /* 841E LDY */
    recomp_tick(40); g_wr16(g_abs(0x0476), (uint16_t)g_cpu.Y);  /* 8421 STY */
L_8424:;
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8424 PLA */
    recomp_tick(14); return;  /* 8425 RTS */
}

/* $02843D, entered with P=$20 via JSR */
void gen_02843D(void) {
    goto L_843D;
L_843D:;
    recomp_tick(30); g_push16(0x843F); func_table_call_jsr(0x02D779); g_cpu.S += 2;  /* 843D JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* 8440 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8442 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8445 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8446 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x15);  /* 8449 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8453;  /* 844B BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x16);  /* 844D CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8453;  /* 844F BEQ */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8451 CLC */
    recomp_tick(14); return;  /* 8452 RTS */
L_8453:;
    recomp_tick(14); g_cpu.flag_C = true;  /* 8453 SEC */
    recomp_tick(14); return;  /* 8454 RTS */
}

/* $028455, entered with P=$20 via JSR */
void gen_028455(void) {
    goto L_8455;
L_8455:;
    recomp_tick(30); g_push16(0x8457); func_table_call_jsr(0x02D779); g_cpu.S += 2;  /* 8455 JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* 8458 LDX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 845A INX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 845B LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 845E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_847B;  /* 8460 BEQ */
    recomp_tick(24); { uint16_t _v = 0x0004; g_cpu.Y = _v; g_nz16(_v); }  /* 8462 LDY */
L_8465:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8465 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8466 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* 8469 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8477;  /* 846B BCS */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 846D PHX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 846E TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 846F LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8472 PLX */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8473 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_847D;  /* 8475 BEQ */
L_8477:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8477 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8478 DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8465;  /* 8479 BNE */
L_847B:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 847B CLC */
    recomp_tick(14); return;  /* 847C RTS */
L_847D:;
    recomp_tick(14); g_cpu.flag_C = true;  /* 847D SEC */
    recomp_tick(14); return;  /* 847E RTS */
}

/* $02847F, entered with P=$20 via JSR */
void gen_02847F(void) {
    goto L_847F;
L_847F:;
    recomp_tick(30); g_push16(0x8481); func_table_call_jsr(0x02D779); g_cpu.S += 2;  /* 847F JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* 8482 LDX */
    recomp_tick(24); { uint16_t _v = 0x0005; g_cpu.Y = _v; g_nz16(_v); }  /* 8484 LDY */
L_8487:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 8487 PHX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8488 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8489 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* 848C CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_8498;  /* 848E BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8490 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8491 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8494 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_849F;  /* 8496 BNE */
L_8498:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8498 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8499 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 849A DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_8487;  /* 849B BNE */
    recomp_tick(14); g_cpu.flag_C = false;  /* 849D CLC */
    recomp_tick(14); return;  /* 849E RTS */
L_849F:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 849F PLX */
    recomp_tick(14); g_cpu.flag_C = true;  /* 84A0 SEC */
    recomp_tick(14); return;  /* 84A1 RTS */
}

/* $0284DD, entered with P=$20 via JSR */
void gen_0284DD(void) {
    goto L_84DD;
L_84DD:;
    recomp_tick(30); g_push16(0x84DF); func_table_call_jsr(0x02D779); g_cpu.S += 2;  /* 84DD JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* 84E0 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 84E2 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 84E3 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 84E6 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 84E7 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 84EA AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_84F0;  /* 84EC BNE */
    recomp_tick(14); g_cpu.flag_C = false;  /* 84EE CLC */
    recomp_tick(14); return;  /* 84EF RTS */
L_84F0:;
    recomp_tick(14); g_cpu.flag_C = true;  /* 84F0 SEC */
    recomp_tick(14); return;  /* 84F1 RTS */
}

/* $02857F, entered with P=$20 via JSR */
void gen_02857F(void) {
    goto L_857F;
L_857F:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 857F TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8580 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8583 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8584 TAX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* 8585 STX */
    recomp_tick(16); g_rep(0x20);  /* 8587 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8589 CLC */
    recomp_tick(24); { uint16_t _v = 0x14ED; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 858A LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* 858D ADC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 858F STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8591 CLC */
    recomp_tick(24); { uint16_t _v = 0x1517; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8592 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* 8595 ADC */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.C);  /* 8597 STA */
    recomp_tick(40); g_wr16(g_abs(0x1751), 0);  /* 8599 STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* 859C LDX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* 859E LDY */
L_85A0:;
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_dp(0x04)));  /* 85A0 CPY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_85E1;  /* 85A2 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x18AF)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 85A4 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x7FFF);  /* 85A7 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_85E1;  /* 85AA BEQ */
    recomp_tick(14); g_cpu.flag_C = true;  /* 85AC SEC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x14ED)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 85AD LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpi(0x00))));  /* 85B0 SBC */
    recomp_tick(16); if (g_cpu.flag_N) goto L_85BB;  /* 85B2 BMI */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x000E);  /* 85B4 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_85C2;  /* 85B7 BCC */
    recomp_tick(16); goto L_85E1;  /* 85B9 BRA */
L_85BB:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0xFFF2);  /* 85BB CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_85C2;  /* 85BE BCS */
    recomp_tick(16); goto L_85E1;  /* 85C0 BRA */
L_85C2:;
    recomp_tick(14); g_cpu.flag_C = true;  /* 85C2 SEC */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x1517)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 85C3 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpi(0x02))));  /* 85C6 SBC */
    recomp_tick(16); if (g_cpu.flag_N) goto L_85D1;  /* 85C8 BMI */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x000E);  /* 85CA CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_85D8;  /* 85CD BCC */
    recomp_tick(16); goto L_85E1;  /* 85CF BRA */
L_85D1:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0xFFF2);  /* 85D1 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_85D8;  /* 85D4 BCS */
    recomp_tick(16); goto L_85E1;  /* 85D6 BRA */
L_85D8:;
    recomp_tick(56); { uint32_t _e = g_abs(0x1751); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 85D8 INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 85DB TYA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 85DC LSR */
    recomp_tick(40); g_wr16(g_absx(0x1753), (uint16_t)g_cpu.C);  /* 85DD STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 85E0 INX */
L_85E1:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 85E1 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 85E2 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0014);  /* 85E3 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_85A0;  /* 85E6 BNE */
    recomp_tick(16); g_sep(0x20);  /* 85E8 SEP */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1751)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 85EA LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_85FA;  /* 85ED BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x04D0)); g_cpu.X = _v; g_nz16(_v); }  /* 85EF LDX */
    recomp_tick(40); { uint32_t _e = g_abs(0x04D0); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 85F2 INC */
    recomp_tick(16); { uint8_t _v = 0x0B; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 85F5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04D2), (uint8_t)(uint8_t)g_cpu.C);  /* 85F7 STA */
L_85FA:;
    recomp_tick(14); return;  /* 85FA RTS */
}

/* $02872B, entered with P=$20 via JSR */
void gen_02872B(void) {
    goto L_872B;
L_872B:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 872B PHX */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 872C DEC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 872D ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 872E TAX */
    recomp_tick(16); g_rep(0x20);  /* 872F REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x11BA2Fu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8731 LDA */
    recomp_tick(40); g_wr16(g_absy(0x12B3), (uint16_t)g_cpu.C);  /* 8735 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8738 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8739 INY */
    recomp_tick(16); g_sep(0x20);  /* 873A SEP */
    recomp_tick(16); { uint8_t _v = 0x11; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 873C LDA */
    recomp_tick(32); g_wr8(g_absy(0x12B3), (uint8_t)(uint8_t)g_cpu.C);  /* 873E STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8741 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 8742 INY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 8743 PLX */
    recomp_tick(14); return;  /* 8744 RTS */
}

/* $0287E7, entered with P=$20 via JSR */
void gen_0287E7(void) {
    goto L_87E7;
L_87E7:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 87E7 PHX */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87E8 DEC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 87E9 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 87EA TAX */
    recomp_tick(16); g_rep(0x20);  /* 87EB REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x11BA2Fu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87ED LDA */
    recomp_tick(40); g_wr16(g_absy(0x12B3), (uint16_t)g_cpu.C);  /* 87F1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 87F4 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 87F5 INY */
    recomp_tick(16); g_sep(0x20);  /* 87F6 SEP */
    recomp_tick(16); { uint8_t _v = 0x11; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87F8 LDA */
    recomp_tick(32); g_wr8(g_absy(0x12B3), (uint8_t)(uint8_t)g_cpu.C);  /* 87FA STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 87FD INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 87FE INY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 87FF PLX */
    recomp_tick(14); return;  /* 8800 RTS */
}

/* $0289DB, entered with P=$20 via JSR */
void gen_0289DB(void) {
    goto L_89DB;
L_89DB:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 89DB PHX */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 89DC DEC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 89DD ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 89DE TAX */
    recomp_tick(16); g_rep(0x20);  /* 89DF REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x11BA2Fu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 89E1 LDA */
    recomp_tick(40); g_wr16(g_absy(0x12B3), (uint16_t)g_cpu.C);  /* 89E5 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 89E8 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 89E9 INY */
    recomp_tick(16); g_sep(0x20);  /* 89EA SEP */
    recomp_tick(16); { uint8_t _v = 0x11; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 89EC LDA */
    recomp_tick(32); g_wr8(g_absy(0x12B3), (uint8_t)(uint8_t)g_cpu.C);  /* 89EE STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 89F1 INY */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 89F2 INY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 89F3 PLX */
    recomp_tick(14); return;  /* 89F4 RTS */
}

/* $028EA8, entered with P=$20 via JSR */
void gen_028EA8(void) {
    goto L_8EA8;
L_8EA8:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 8EA8 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x18)))));  /* 8EA9 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* 8EAB STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EAD LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* 8EAF ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* 8EB1 STA */
    recomp_tick(14); return;  /* 8EB3 RTS */
}

/* $02955A, entered with P=$20 via JSR */
void gen_02955A(void) {
    goto L_955A;
L_955A:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0346)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 955A LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9569;  /* 955D BEQ */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 955F STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9561 TDC */
L_9562:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 9562 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x16)));  /* 9563 ADC */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9565 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9562;  /* 9567 BNE */
L_9569:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* 9569 LDY */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 956B TAX */
L_956C:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 956C PHX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 956D TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 956E LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9571 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_958E;  /* 9573 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9575 TAX */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 9576 PHX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9577 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 957A DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 957B TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xFF93)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 957C LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 957F PLX */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9580 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9591;  /* 9582 BNE */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 9584 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9585 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9586 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0016);  /* 9587 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_956C;  /* 958A BNE */
    recomp_tick(16); goto L_958F;  /* 958C BRA */
L_958E:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 958E PLX */
L_958F:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 958F CLC */
    recomp_tick(14); return;  /* 9590 RTS */
L_9591:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 9591 PLX */
    recomp_tick(14); g_cpu.flag_C = true;  /* 9592 SEC */
    recomp_tick(14); return;  /* 9593 RTS */
}

/* $029707, entered with P=$20 via JSR */
void gen_029707(void) {
    goto L_9707;
L_9707:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x047E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9707 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_970D;  /* 970A BNE */
    recomp_tick(14); return;  /* 970C RTS */
L_970D:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 970D TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 970E TAX */
L_970F:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x04B2)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 970F LDA */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04E2)));  /* 9712 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_971F;  /* 9715 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9717 INX */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0x0424)));  /* 9718 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_970F;  /* 971B BNE */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* 971D LDX */
L_971F:;
    recomp_tick(40); g_wr16(g_abs(0x047E), (uint16_t)g_cpu.X);  /* 971F STX */
    recomp_tick(14); return;  /* 9722 RTS */
}

/* $029988, entered with P=$20 via JSR */
void gen_029988(void) {
    goto L_9988;
L_9988:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 9988 PHX */
    recomp_tick(24); g_wr8(g_dp(0x1A), (uint8_t)(uint8_t)g_cpu.C);  /* 9989 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 998B DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 998C TAX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x14)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 998D LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AED4u)));  /* 998F CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_99B3;  /* 9993 BCC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9995 LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AFBBu)));  /* 9997 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_99B3;  /* 999B BCC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 999D LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AF21u)));  /* 999F CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_99B3;  /* 99A3 BCC */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AF6Eu)));  /* 99A5 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_99AD;  /* 99A9 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_99B3;  /* 99AB BCS */
L_99AD:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 99AD LDA */
    recomp_tick(32); g_wr8(g_absy(0x0390), (uint8_t)(uint8_t)g_cpu.C);  /* 99AF STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 99B2 INY */
L_99B3:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 99B3 PLX */
    recomp_tick(14); return;  /* 99B4 RTS */
}

/* $029B78, entered with P=$00 via JSR */
void gen_029B78(void) {
    goto L_9B78;
L_9B78:;
    recomp_tick(24); { uint16_t _v = 0x0001; g_cpu.Y = _v; g_nz16(_v); }  /* 9B78 LDY */
    recomp_tick(24); { uint16_t _v = 0x9901; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9B7B LDA */
    goto L_9B7E;
L_9B7D:;
    recomp_tick(40); g_wr16(g_absy(0x0398), (uint16_t)g_cpu.C);  /* 9B7D STA */
    goto L_9B80;
L_9B7E:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9B7E TYA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_sr(0xC8))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 9B7F ORA */
    goto L_9B81;
L_9B80:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9B80 INY */
L_9B81:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9B81 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0009);  /* 9B82 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9B7D;  /* 9B85 BNE */
    recomp_tick(14); return;  /* 9B87 RTS */
}

/* $029D3D, entered with P=$20 via JSR */
void gen_029D3D(void) {
    goto L_9D3D;
L_9D3D:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9D3D TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9D3E TAX */
L_9D3F:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D3F LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9D42 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9D49;  /* 9D44 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9D46 INX */
    recomp_tick(16); goto L_9D3F;  /* 9D47 BRA */
L_9D49:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0474)); g_cpu.Y = _v; g_nz16(_v); }  /* 9D49 LDY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D4C LDA */
    recomp_tick(32); g_wr8(g_absx(0x0F35), (uint8_t)(uint8_t)g_cpu.C);  /* 9D4F STA */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D52 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0400), (uint8_t)(uint8_t)g_cpu.C);  /* 9D54 STA */
    recomp_tick(14); return;  /* 9D57 RTS */
}

/* $029D58, entered with P=$20 via JSR */
void gen_029D58(void) {
    goto L_9D58;
L_9D58:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* 9D58 LDY */
L_9D5A:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9D5A TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D5B LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* 9D5E CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_9D6D;  /* 9D60 BCS */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 9D62 PHX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9D63 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D64 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D67 AND */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* 9D69 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 9D6C PLX */
L_9D6D:;
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D6D LDA */
    recomp_tick(32); g_wr8(g_absx(0x0E81), (uint8_t)(uint8_t)g_cpu.C);  /* 9D6F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9D72 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9D73 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* 9D74 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9D5A;  /* 9D77 BNE */
    recomp_tick(16); goto L_9DAD;  /* 9D79 BRA */
L_9DAD:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9DAD TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9DAE TAX */
L_9DAF:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DAF LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9DB2 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9DB9;  /* 9DB4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9DB6 INX */
    recomp_tick(16); goto L_9DAF;  /* 9DB7 BRA */
L_9DB9:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9DB9 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9DBA TAY */
L_9DBB:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DBB LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* 9DBE CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_9DCB;  /* 9DC0 BCS */
    recomp_tick(32); g_wr8(g_absx(0x0F35), (uint8_t)(uint8_t)g_cpu.C);  /* 9DC2 STA */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DC5 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0400), (uint8_t)(uint8_t)g_cpu.C);  /* 9DC7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9DCA INX */
L_9DCB:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9DCB INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* 9DCC CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9DBB;  /* 9DCF BNE */
    recomp_tick(14); return;  /* 9DD1 RTS */
}

/* $029D8A, entered with P=$20 via JSR */
void gen_029D8A(void) {
    goto L_9D8A;
L_9D8A:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9D8A TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9D8B TAY */
L_9D8C:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D8C LDA */
    recomp_tick(32); g_wr8(g_absy(0x0400), (uint8_t)(uint8_t)g_cpu.C);  /* 9D8F STA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9D92 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9DA6;  /* 9D94 BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 9D96 PHX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9D97 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D98 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9D9B AND */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* 9D9D STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* 9DA0 PLX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DA1 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0E81), (uint8_t)(uint8_t)g_cpu.C);  /* 9DA3 STA */
L_9DA6:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9DA6 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9DA7 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* 9DA8 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9D8C;  /* 9DAB BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9DAD TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9DAE TAX */
L_9DAF:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DAF LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9DB2 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9DB9;  /* 9DB4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9DB6 INX */
    recomp_tick(16); goto L_9DAF;  /* 9DB7 BRA */
L_9DB9:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9DB9 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 9DBA TAY */
L_9DBB:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DBB LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* 9DBE CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_9DCB;  /* 9DC0 BCS */
    recomp_tick(32); g_wr8(g_absx(0x0F35), (uint8_t)(uint8_t)g_cpu.C);  /* 9DC2 STA */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9DC5 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0400), (uint8_t)(uint8_t)g_cpu.C);  /* 9DC7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9DCA INX */
L_9DCB:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9DCB INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* 9DCC CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9DBB;  /* 9DCF BNE */
    recomp_tick(14); return;  /* 9DD1 RTS */
}

/* $029FBC, entered with P=$20 via JSR */
void gen_029FBC(void) {
    goto L_9FBC;
L_9FBC:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9FBC TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9FBD TAX */
L_9FBE:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FBE LDA */
    recomp_tick(32); g_wr8(g_absx(0x0600), (uint8_t)(uint8_t)g_cpu.C);  /* 9FC1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9FC4 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0064);  /* 9FC5 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9FBE;  /* 9FC8 BNE */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FCA LDA */
    recomp_tick(32); g_wr8(g_abs(0x0664), (uint8_t)(uint8_t)g_cpu.C);  /* 9FCC STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 9FCF TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 9FD0 TAX */
    recomp_tick(24); { uint16_t _v = 0x0001; g_cpu.Y = _v; g_nz16(_v); }  /* 9FD1 LDY */
L_9FD4:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0600)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FD4 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9FD7 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A006;  /* 9FD9 BNE */
L_9FDB:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0600)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FDB LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* 9FDE CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9FEA;  /* 9FE0 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9FE2 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0064);  /* 9FE3 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9FDB;  /* 9FE6 BNE */
    recomp_tick(16); goto L_A012;  /* 9FE8 BRA */
L_9FEA:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* 9FEA PHX */
    recomp_tick(14); g_push16((uint16_t)g_cpu.Y);  /* 9FEB PHY */
L_9FEC:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0600)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FEC LDA */
    recomp_tick(32); g_wr8(g_absx(0x0600), (uint8_t)(uint8_t)g_cpu.C);  /* 9FEF STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9FF2 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9FF3 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0064);  /* 9FF4 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9FEC;  /* 9FF7 BNE */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FF9 LDA */
L_9FFB:;
    recomp_tick(32); g_wr8(g_absx(0x0600), (uint8_t)(uint8_t)g_cpu.C);  /* 9FFB STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 9FFE INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0064);  /* 9FFF CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9FFB;  /* A002 BNE */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.Y = _v; g_nz16(_v); }  /* A004 PLY */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* A005 PLX */
L_A006:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A006 INX */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* A007 STX */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A009 INC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.Y = _v; g_nz16(_v); }  /* A00B LDY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0064);  /* A00D CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9FD4;  /* A010 BNE */
L_A012:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A012 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A013 TAX */
L_A014:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0600)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A014 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0F35), (uint8_t)(uint8_t)g_cpu.C);  /* A017 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A01A INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0064);  /* A01B CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A014;  /* A01E BNE */
    recomp_tick(30); g_push16(0xA022); func_table_call_jsr(0x02C4E4); g_cpu.S += 2;  /* A020 JSR */
    recomp_tick(14); return;  /* A023 RTS */
}

/* $02A56C, entered with P=$20 via JSR */
void gen_02A56C(void) {
    goto L_A56C;
L_A56C:;
    recomp_tick(30); g_push16(0xA56E); func_table_call_jsr(0x02B9F9); g_cpu.S += 2;  /* A56C JSR */
    recomp_tick(14); g_cpu.flag_C = false;  /* A56F CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A570 LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0474)))));  /* A572 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* A575 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A577 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* A579 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* A57B STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* A57D LDX */
    recomp_tick(40); g_wr16(g_abs(0x0380), (uint16_t)g_cpu.X);  /* A57F STX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A582 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A583 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A586 TAX */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* A587 PHX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A588 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A58B DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A58C TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xFF93)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A58D LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* A590 PLX */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A591 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A597;  /* A593 BEQ */
    recomp_tick(14); g_cpu.flag_C = true;  /* A595 SEC */
    recomp_tick(14); return;  /* A596 RTS */
L_A597:;
    recomp_tick(14); g_cpu.flag_C = false;  /* A597 CLC */
    recomp_tick(14); return;  /* A598 RTS */
}

/* $02A64C, entered with P=$20 via JSR */
void gen_02A64C(void) {
    goto L_A64C;
L_A64C:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A64C TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* A64D TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* A64E TAY */
L_A64F:;
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A64F LDA */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A651 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A654 INX */
    recomp_tick(14); g_cpu.flag_C = false;  /* A655 CLC */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A656 LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0388)))));  /* A658 ADC */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A65B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A65E INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A65F INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x005A);  /* A660 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A64F;  /* A663 BNE */
    recomp_tick(14); return;  /* A665 RTS */
}

/* $02A666, entered with P=$20 via JSR */
void gen_02A666(void) {
    goto L_A666;
L_A666:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* A666 LDX */
    recomp_tick(30); g_push16(0xA66A); func_table_call_jsr(0x02A6CF); g_cpu.S += 2;  /* A668 JSR */
    recomp_tick(16); { uint8_t _v = 0x06; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A66B LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* A66D STA */
L_A66F:;
    recomp_tick(30); g_push16(0xA671); func_table_call_jsr(0x02A6D4); g_cpu.S += 2;  /* A66F JSR */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A672 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A66F;  /* A674 BNE */
    recomp_tick(30); g_push16(0xA678); func_table_call_jsr(0x02A6D9); g_cpu.S += 2;  /* A676 JSR */
    recomp_tick(30); g_push16(0xA67B); func_table_call_jsr(0x02A6DE); g_cpu.S += 2;  /* A679 JSR */
    recomp_tick(16); { uint8_t _v = 0x5E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A67C LDA */
    recomp_tick(32); g_wr8(g_abs(0x0506), (uint8_t)(uint8_t)g_cpu.C);  /* A67E STA */
    recomp_tick(16); { uint8_t _v = 0x5F; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A681 LDA */
    recomp_tick(32); g_wr8(g_abs(0x050C), (uint8_t)(uint8_t)g_cpu.C);  /* A683 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A686 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A687 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A68A INC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A68B STA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0A);  /* A68D CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_A695;  /* A68F BCS */
    recomp_tick(16); { uint8_t _v = 0x7D; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A691 LDA */
    recomp_tick(16); goto L_A6A9;  /* A693 BRA */
L_A695:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x14);  /* A695 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_A6A2;  /* A697 BCS */
    recomp_tick(14); g_cpu.flag_C = true;  /* A699 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x0A)));  /* A69A SBC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A69C STA */
    recomp_tick(16); { uint8_t _v = 0x74; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A69E LDA */
    recomp_tick(16); goto L_A6A9;  /* A6A0 BRA */
L_A6A2:;
    recomp_tick(14); g_cpu.flag_C = true;  /* A6A2 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x14)));  /* A6A3 SBC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* A6A5 STA */
    recomp_tick(16); { uint8_t _v = 0x75; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6A7 LDA */
L_A6A9:;
    recomp_tick(32); g_wr8(g_abs(0x0508), (uint8_t)(uint8_t)g_cpu.C);  /* A6A9 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* A6AC CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6AD LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x73)));  /* A6AF ADC */
    recomp_tick(32); g_wr8(g_abs(0x050A), (uint8_t)(uint8_t)g_cpu.C);  /* A6B1 STA */
    recomp_tick(14); return;  /* A6B4 RTS */
}

/* $02A6B5, entered with P=$20 via JSR */
void gen_02A6B5(void) {
    goto L_A6B5;
L_A6B5:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* A6B5 LDX */
    recomp_tick(30); g_push16(0xA6B9); func_table_call_jsr(0x02A6CF); g_cpu.S += 2;  /* A6B7 JSR */
    recomp_tick(16); { uint8_t _v = 0x16; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6BA LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* A6BC STA */
L_A6BE:;
    recomp_tick(30); g_push16(0xA6C0); func_table_call_jsr(0x02A6D4); g_cpu.S += 2;  /* A6BE JSR */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* A6C1 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A6BE;  /* A6C3 BNE */
    recomp_tick(30); g_push16(0xA6C7); func_table_call_jsr(0x02A6D9); g_cpu.S += 2;  /* A6C5 JSR */
    recomp_tick(30); g_push16(0xA6CA); func_table_call_jsr(0x02A6DE); g_cpu.S += 2;  /* A6C8 JSR */
    recomp_tick(30); g_push16(0xA6CD); func_table_call_jsr(0x02A6DE); g_cpu.S += 2;  /* A6CB JSR */
    recomp_tick(14); return;  /* A6CE RTS */
}

/* $02A6CF, entered with P=$20 via JSR */
void gen_02A6CF(void) {
    goto L_A6CF;
L_A6CF:;
    recomp_tick(24); { uint16_t _v = 0xA6FC; g_cpu.Y = _v; g_nz16(_v); }  /* A6CF LDY */
    recomp_tick(16); goto L_A6E1;  /* A6D2 BRA */
L_A6E1:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* A6E1 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* A6E3 LDY */
L_A6E5:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6E5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6E7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6EA INX */
    recomp_tick(14); g_cpu.flag_C = false;  /* A6EB CLC */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6EC LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0388)))));  /* A6EE ADC */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6F1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6F4 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A6F5 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x000A);  /* A6F6 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A6E5;  /* A6F9 BNE */
    recomp_tick(14); return;  /* A6FB RTS */
}

/* $02A6D4, entered with P=$20 via JSR */
void gen_02A6D4(void) {
    goto L_A6D4;
L_A6D4:;
    recomp_tick(24); { uint16_t _v = 0xA706; g_cpu.Y = _v; g_nz16(_v); }  /* A6D4 LDY */
    recomp_tick(16); goto L_A6E1;  /* A6D7 BRA */
L_A6E1:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* A6E1 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* A6E3 LDY */
L_A6E5:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6E5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6E7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6EA INX */
    recomp_tick(14); g_cpu.flag_C = false;  /* A6EB CLC */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6EC LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0388)))));  /* A6EE ADC */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6F1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6F4 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A6F5 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x000A);  /* A6F6 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A6E5;  /* A6F9 BNE */
    recomp_tick(14); return;  /* A6FB RTS */
}

/* $02A6D9, entered with P=$20 via JSR */
void gen_02A6D9(void) {
    goto L_A6D9;
L_A6D9:;
    recomp_tick(24); { uint16_t _v = 0xA710; g_cpu.Y = _v; g_nz16(_v); }  /* A6D9 LDY */
    recomp_tick(16); goto L_A6E1;  /* A6DC BRA */
L_A6E1:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* A6E1 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* A6E3 LDY */
L_A6E5:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6E5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6E7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6EA INX */
    recomp_tick(14); g_cpu.flag_C = false;  /* A6EB CLC */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6EC LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0388)))));  /* A6EE ADC */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6F1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6F4 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A6F5 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x000A);  /* A6F6 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A6E5;  /* A6F9 BNE */
    recomp_tick(14); return;  /* A6FB RTS */
}

/* $02A6DE, entered with P=$20 via JSR */
void gen_02A6DE(void) {
    goto L_A6DE;
L_A6DE:;
    recomp_tick(24); { uint16_t _v = 0xA71A; g_cpu.Y = _v; g_nz16(_v); }  /* A6DE LDY */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* A6E1 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* A6E3 LDY */
L_A6E5:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6E5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6E7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6EA INX */
    recomp_tick(14); g_cpu.flag_C = false;  /* A6EB CLC */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A6EC LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0388)))));  /* A6EE ADC */
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* A6F1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* A6F4 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* A6F5 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x000A);  /* A6F6 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A6E5;  /* A6F9 BNE */
    recomp_tick(14); return;  /* A6FB RTS */
}

/* $02AB9E, entered with P=$20 via JSR */
void gen_02AB9E(void) {
    goto L_AB9E;
L_AB9E:;
    recomp_tick(16); { uint8_t _v = 0x19; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AB9E LDA */
    recomp_tick(24); g_wr8(g_dp(0x1A), (uint8_t)(uint8_t)g_cpu.C);  /* ABA0 STA */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABA2 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1778), (uint8_t)(uint8_t)g_cpu.C);  /* ABA4 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* ABA7 LDY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* ABA9 LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABAB LDA */
L_ABAD:;
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ABAD STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* ABB0 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0030);  /* ABB1 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_ABAD;  /* ABB4 BNE */
L_ABB6:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1778)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABB6 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* ABB9 CLC */
    recomp_tick(24); g_wr8(g_dp(0x1C), (uint8_t)(uint8_t)g_cpu.C);  /* ABBA STA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* ABBC ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* ABBD ASL */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1C)))));  /* ABBE ADC */
    recomp_tick(24); g_wr8(g_dp(0x1C), (uint8_t)(uint8_t)g_cpu.C);  /* ABC0 STA */
    recomp_tick(24); g_wr8(g_dp(0x1D), 0);  /* ABC2 STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1C)); g_cpu.X = _v; g_nz16(_v); }  /* ABC4 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABC6 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* ABC9 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_ABD4;  /* ABCB BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1778)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABCD LDA */
    recomp_tick(32); g_wr8(g_absy(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ABD0 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* ABD3 INY */
L_ABD4:;
    recomp_tick(40); { uint32_t _e = g_abs(0x1778); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* ABD4 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x1A); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* ABD7 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_ABB6;  /* ABD9 BNE */
    recomp_tick(32); g_wr16(g_dp(0x1A), (uint16_t)g_cpu.Y);  /* ABDB STY */
    recomp_tick(24); g_wr8(g_dp(0x1B), 0);  /* ABDD STZ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABDF LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_ABE6;  /* ABE1 BNE */
    recomp_tick(24); goto L_AC45;  /* ABE3 JMP */
L_ABE6:;
    recomp_tick(32); { uint32_t _e = g_dp(0x1B); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* ABE6 INC */
    recomp_tick(14); g_cpu.flag_C = true;  /* ABE8 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x03)));  /* ABE9 SBC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_ABF0;  /* ABEB BNE */
    recomp_tick(24); goto L_AC45;  /* ABED JMP */
L_ABF0:;
    recomp_tick(16); if (g_cpu.flag_C) goto L_ABE6;  /* ABF0 BCS */
    recomp_tick(24); goto L_AC45;  /* ABF2 JMP */
L_AC45:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC45 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* AC47 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* AC48 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1B)))));  /* AC49 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1A), (uint8_t)(uint8_t)g_cpu.C);  /* AC4B STA */
    recomp_tick(24); g_wr8(g_dp(0x1B), 0);  /* AC4D STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* AC4F LDX */
L_AC51:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC51 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AC54 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AC6C;  /* AC56 BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* AC58 PHX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* AC59 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AC5A TDC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC5B PLA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* AC5C TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC5D LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC60 AND */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* AC62 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AC65 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC66 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0064);  /* AC67 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC51;  /* AC6A BNE */
L_AC6C:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* AC6C STX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC6E LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* AC70 STZ */
L_AC72:;
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AC72 INC */
    recomp_tick(14); g_cpu.flag_C = true;  /* AC74 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x16)));  /* AC75 SBC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AC7B;  /* AC77 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_AC72;  /* AC79 BCS */
L_AC7B:;
    recomp_tick(24); g_wr8(g_dp(0x04), 0);  /* AC7B STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1A)); g_cpu.X = _v; g_nz16(_v); }  /* AC7D LDX */
L_AC7F:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC7F LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AC82 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AC9F;  /* AC84 BEQ */
    recomp_tick(14); g_cpu.flag_C = false;  /* AC86 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC87 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0xF0)));  /* AC89 ADC */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC8B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC8E INX */
    recomp_tick(16); { uint8_t _v = 0xFD; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC8F LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC91 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC94 INX */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC95 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC98 INX */
    recomp_tick(32); { uint32_t _e = g_dp(0x04); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AC99 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* AC9B DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC7F;  /* AC9D BNE */
L_AC9F:;
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC9F LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ACA1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* ACA4 INX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ACA5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ACA7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* ACAA INX */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ACAB STA */
    recomp_tick(30); g_push16(0xACB0); func_table_call_jsr(0x02C4E4); g_cpu.S += 2;  /* ACAE JSR */
    recomp_tick(14); return;  /* ACB1 RTS */
}

/* $02ABF5, entered with P=$20 via JSR */
void gen_02ABF5(void) {
    goto L_ABF5;
L_ABF5:;
    recomp_tick(30); g_push16(0xABF7); func_table_call_jsr(0x02AB9E); g_cpu.S += 2;  /* ABF5 JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* ABF8 LDX */
L_ABFA:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABFA LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xF0);  /* ABFD CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_AC0F;  /* ABFF BCC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC0A;  /* AC01 BNE */
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC03 LDA */
    recomp_tick(16); goto L_AC0C;  /* AC05 BRA */
L_AC0A:;
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC0A LDA */
L_AC0C:;
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC0C STA */
L_AC0F:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC0F INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0030);  /* AC10 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_ABFA;  /* AC13 BNE */
    recomp_tick(24); { uint16_t _v = 0x0003; g_cpu.X = _v; g_nz16(_v); }  /* AC15 LDX */
L_AC18:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC18 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AC1B CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC24;  /* AC1D BNE */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC1F DEC */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC20 STA */
    recomp_tick(14); return;  /* AC23 RTS */
L_AC24:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC24 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC25 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC26 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0030);  /* AC27 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC18;  /* AC2A BNE */
    recomp_tick(14); return;  /* AC2C RTS */
}

/* $02AC2D, entered with P=$20 via JSR */
void gen_02AC2D(void) {
    goto L_AC2D;
L_AC2D:;
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC2D LDA */
    recomp_tick(32); g_wr8(g_abs(0x1778), (uint8_t)(uint8_t)g_cpu.C);  /* AC2F STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* AC32 LDY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* AC34 LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC36 LDA */
L_AC38:;
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC38 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC3B INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0030);  /* AC3C CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC38;  /* AC3F BNE */
    recomp_tick(24); g_wr8(g_dp(0x1B), 0);  /* AC41 STZ */
    recomp_tick(24); g_wr8(g_dp(0x1A), 0);  /* AC43 STZ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1B)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC45 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* AC47 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* AC48 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1B)))));  /* AC49 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1A), (uint8_t)(uint8_t)g_cpu.C);  /* AC4B STA */
    recomp_tick(24); g_wr8(g_dp(0x1B), 0);  /* AC4D STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* AC4F LDX */
L_AC51:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC51 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AC54 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AC6C;  /* AC56 BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* AC58 PHX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* AC59 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* AC5A TDC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC5B PLA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* AC5C TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC5D LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC60 AND */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* AC62 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* AC65 PLX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC66 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0064);  /* AC67 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC51;  /* AC6A BNE */
L_AC6C:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* AC6C STX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC6E LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* AC70 STZ */
L_AC72:;
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AC72 INC */
    recomp_tick(14); g_cpu.flag_C = true;  /* AC74 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x16)));  /* AC75 SBC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AC7B;  /* AC77 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_AC72;  /* AC79 BCS */
L_AC7B:;
    recomp_tick(24); g_wr8(g_dp(0x04), 0);  /* AC7B STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1A)); g_cpu.X = _v; g_nz16(_v); }  /* AC7D LDX */
L_AC7F:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC7F LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* AC82 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_AC9F;  /* AC84 BEQ */
    recomp_tick(14); g_cpu.flag_C = false;  /* AC86 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC87 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0xF0)));  /* AC89 ADC */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC8B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC8E INX */
    recomp_tick(16); { uint8_t _v = 0xFD; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC8F LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC91 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC94 INX */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* AC95 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AC98 INX */
    recomp_tick(32); { uint32_t _e = g_dp(0x04); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* AC99 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* AC9B DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AC7F;  /* AC9D BNE */
L_AC9F:;
    recomp_tick(16); { uint8_t _v = 0xFE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AC9F LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ACA1 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* ACA4 INX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ACA5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ACA7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* ACAA INX */
    recomp_tick(32); g_wr8(g_absx(0x0350), (uint8_t)(uint8_t)g_cpu.C);  /* ACAB STA */
    recomp_tick(30); g_push16(0xACB0); func_table_call_jsr(0x02C4E4); g_cpu.S += 2;  /* ACAE JSR */
    recomp_tick(14); return;  /* ACB1 RTS */
}

/* $02AE4A, entered with P=$00 via JSR */
void gen_02AE4A(void) {
    goto L_AE4A;
L_AE4A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* AE4A LDY */
L_AE4C:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x0500)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AE4C LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AE4F AND */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0x1200); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AE52 ORA */
    recomp_tick(48); g_wr16(g_longx(0x7F0000u), (uint16_t)g_cpu.C);  /* AE55 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AE59 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AE5A INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* AE5B INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0080);  /* AE5C CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AE4C;  /* AE5F BNE */
    recomp_tick(14); return;  /* AE61 RTS */
}

/* $02AE62, entered with P=$00 via JSR */
void gen_02AE62(void) {
    goto L_AE62;
L_AE62:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* AE62 LDY */
L_AE64:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0x0580)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AE64 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AE67 AND */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0x1200); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AE6A ORA */
    recomp_tick(48); g_wr16(g_longx(0x7F0000u), (uint16_t)g_cpu.C);  /* AE6D STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AE71 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* AE72 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* AE73 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0080);  /* AE74 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_AE64;  /* AE77 BNE */
    recomp_tick(14); return;  /* AE79 RTS */
}

/* $02AFC9, entered with P=$20 via JSR */
void gen_02AFC9(void) {
    goto L_AFC9;
L_AFC9:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x09);  /* AFC9 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_AFCF;  /* AFCB BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFCD INC */
    recomp_tick(14); return;  /* AFCE RTS */
L_AFCF:;
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AFCF LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* AFD1 SEC */
    recomp_tick(14); return;  /* AFD2 RTS */
}

/* $02B267, entered with P=$20 via JSR */
void gen_02B267(void) {
    goto L_B267;
L_B267:;
    recomp_tick(14); ;  /* B267 NOP */
    recomp_tick(14); ;  /* B268 NOP */
    recomp_tick(14); ;  /* B269 NOP */
    recomp_tick(14); return;  /* B26A RTS */
}

/* $02B3B6, entered with P=$20 via JSR */
void gen_02B3B6(void) {
    goto L_B3B6;
L_B3B6:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* B3B6 LDX */
L_B3B8:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02B437u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3B8 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0424), (uint8_t)(uint8_t)g_cpu.C);  /* B3BC STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02B442u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3BF LDA */
    recomp_tick(32); g_wr8(g_absx(0x0444), (uint8_t)(uint8_t)g_cpu.C);  /* B3C3 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02B44Du)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3C6 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04B0), (uint8_t)(uint8_t)g_cpu.C);  /* B3CA STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B3CD INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000B);  /* B3CE CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B3B8;  /* B3D1 BNE */
    recomp_tick(24); g_wr8(g_dp(0x05), 0);  /* B3D3 STZ */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3D5 LDA */
    recomp_tick(30); g_push16(0xB3D9); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3D7 JSR */
    recomp_tick(16); { uint8_t _v = 0x02; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3DA LDA */
    recomp_tick(30); g_push16(0xB3DE); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3DC JSR */
    recomp_tick(16); { uint8_t _v = 0x03; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3DF LDA */
    recomp_tick(30); g_push16(0xB3E3); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3E1 JSR */
    recomp_tick(16); { uint8_t _v = 0x04; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3E4 LDA */
    recomp_tick(30); g_push16(0xB3E8); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3E6 JSR */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3E9 LDA */
    recomp_tick(30); g_push16(0xB3ED); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3EB JSR */
    recomp_tick(16); { uint8_t _v = 0x06; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3EE LDA */
    recomp_tick(30); g_push16(0xB3F2); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3F0 JSR */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3F3 LDA */
    recomp_tick(30); g_push16(0xB3F7); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3F5 JSR */
    recomp_tick(16); { uint8_t _v = 0x08; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B3F8 LDA */
    recomp_tick(30); g_push16(0xB3FC); func_table_call_jsr(0x02B40E); g_cpu.S += 2;  /* B3FA JSR */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0474)); g_cpu.X = _v; g_nz16(_v); }  /* B3FD LDX */
L_B400:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B400 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B403 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B40A;  /* B405 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* B407 DEX */
    recomp_tick(16); goto L_B400;  /* B408 BRA */
L_B40A:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* B40A STX */
    recomp_tick(14); return;  /* B40D RTS */
}

/* $02B40E, entered with P=$20 via JSR */
void gen_02B40E(void) {
    goto L_B40E;
L_B40E:;
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* B40E STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1777)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B410 LDA */
    recomp_tick(14); g_cpu.flag_C = false;  /* B413 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)))));  /* B414 ADC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* B416 STA */
    recomp_tick(24); g_wr8(g_dp(0x01), 0);  /* B418 STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* B41A LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B41C LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFD);  /* B41F CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B42C;  /* B421 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* B423 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B42C;  /* B425 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B427 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B42C;  /* B429 BEQ */
    recomp_tick(14); return;  /* B42B RTS */
L_B42C:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* B42C LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B42E LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* B430 STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* B433 STA */
    recomp_tick(14); return;  /* B436 RTS */
}

/* $02B62D, entered with P=$20 via JSR */
void gen_02B62D(void) {
    goto L_B62D;
L_B62D:;
    recomp_tick(30); g_push16(0xB62F); func_table_call_jsr(0x0283E6); g_cpu.S += 2;  /* B62D JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* B630 LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B632 LDA */
L_B634:;
    recomp_tick(32); g_wr8(g_absx(0x04B2), (uint8_t)(uint8_t)g_cpu.C);  /* B634 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B637 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x001E);  /* B638 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B634;  /* B63B BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B63D TDC */
    recomp_tick(14); g_cpu.flag_C = false;  /* B63E CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1777)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B63F LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0474)))));  /* B642 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B645 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B646 LDA */
    recomp_tick(30); g_push16(0xB64B); func_table_call_jsr(0x02D99A); g_cpu.S += 2;  /* B649 JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* B64C LDY */
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.Y);  /* B64E STY */
    recomp_tick(40); g_wr16(g_abs(0x0420), (uint16_t)g_cpu.Y);  /* B651 STY */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B654 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* B656 STA */
L_B658:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* B658 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B65B LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B65E CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B687;  /* B660 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0420)); g_cpu.Y = _v; g_nz16(_v); }  /* B662 LDY */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* B665 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B668 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0DCD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B669 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B66C AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B66E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02B694u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B66F LDA */
    recomp_tick(32); g_wr8(g_absy(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* B673 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02B69Eu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B676 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* B67A STA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0420); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B67D INC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0422); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B680 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* B683 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B658;  /* B685 BNE */
L_B687:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0420)); g_cpu.X = _v; g_nz16(_v); }  /* B687 LDX */
    recomp_tick(40); g_wr16(g_abs(0x0424), (uint16_t)g_cpu.X);  /* B68A STX */
    recomp_tick(40); g_wr16(g_abs(0x0444), (uint16_t)g_cpu.X);  /* B68D STX */
    recomp_tick(40); g_wr16(g_abs(0x04B0), (uint16_t)g_cpu.X);  /* B690 STX */
    recomp_tick(14); return;  /* B693 RTS */
}

/* $02B6A8, entered with P=$20 via JSR */
void gen_02B6A8(void) {
    goto L_B6A8;
L_B6A8:;
    recomp_tick(30); g_push16(0xB6AA); func_table_call_jsr(0x0283E6); g_cpu.S += 2;  /* B6A8 JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* B6AB LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6AD LDA */
L_B6AF:;
    recomp_tick(32); g_wr8(g_absx(0x04B2), (uint8_t)(uint8_t)g_cpu.C);  /* B6AF STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B6B2 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x001E);  /* B6B3 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B6AF;  /* B6B6 BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B6B8 TDC */
    recomp_tick(14); g_cpu.flag_C = false;  /* B6B9 CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1777)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6BA LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0474)))));  /* B6BD ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B6C0 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6C1 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6C4 AND */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* B6C6 ASL */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* B6C7 STA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* B6C9 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* B6CA ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* B6CB ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* B6CC CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* B6CD ADC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* B6CF ADC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* B6D1 ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B6D3 TAX */
    recomp_tick(40); g_wr16(g_abs(0x0422), (uint16_t)g_cpu.X);  /* B6D4 STX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* B6D7 LDY */
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.Y);  /* B6D9 STY */
    recomp_tick(40); g_wr16(g_abs(0x0420), (uint16_t)g_cpu.Y);  /* B6DC STY */
    recomp_tick(16); { uint8_t _v = 0x16; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6DF LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* B6E1 STA */
L_B6E3:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* B6E3 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6E6 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* B6E9 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_B709;  /* B6EB BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0420)); g_cpu.Y = _v; g_nz16(_v); }  /* B6ED LDY */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* B6F0 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xB716)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6F3 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* B6F6 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xB72E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B6F9 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* B6FC STA */
    recomp_tick(40); { uint32_t _e = g_abs(0x0420); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B6FF INC */
    recomp_tick(40); { uint32_t _e = g_abs(0x0422); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* B702 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* B705 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B6E3;  /* B707 BNE */
L_B709:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0420)); g_cpu.X = _v; g_nz16(_v); }  /* B709 LDX */
    recomp_tick(40); g_wr16(g_abs(0x0424), (uint16_t)g_cpu.X);  /* B70C STX */
    recomp_tick(40); g_wr16(g_abs(0x0444), (uint16_t)g_cpu.X);  /* B70F STX */
    recomp_tick(40); g_wr16(g_abs(0x04B0), (uint16_t)g_cpu.X);  /* B712 STX */
    recomp_tick(14); return;  /* B715 RTS */
}

/* $02B813, entered with P=$20 via JSR */
void gen_02B813(void) {
    goto L_B813;
L_B813:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* B813 LDX */
    recomp_tick(16); g_rep(0x20);  /* B815 REP */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B817 LDA */
L_B81A:;
    recomp_tick(48); g_wr16(g_longx(0x7F0000u), (uint16_t)g_cpu.C);  /* B81A STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B81E INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* B81F INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0800);  /* B820 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B81A;  /* B823 BNE */
    recomp_tick(16); g_sep(0x20);  /* B825 SEP */
    recomp_tick(14); return;  /* B827 RTS */
}

/* $02B8E7, entered with P=$20 via JSR */
void gen_02B8E7(void) {
    goto L_B8E7;
L_B8E7:;
    recomp_tick(30); g_push16(0xB8E9); func_table_call_jsr(0x02B9ED); g_cpu.S += 2;  /* B8E7 JSR */
    recomp_tick(14); g_cpu.flag_C = false;  /* B8EA CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B8EB LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0474)))));  /* B8ED ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* B8F0 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B8F2 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* B8F4 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* B8F6 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* B8F8 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* B8FA TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B8FB LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* B8FE TAX */
    recomp_tick(14); return;  /* B8FF RTS */
}

/* $02B9ED, entered with P=$20 via JSR */
void gen_02B9ED(void) {
    goto L_B9ED;
L_B9ED:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0347)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9ED LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_B9F9;  /* B9F0 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0346)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9F2 LDA */
    recomp_tick(30); g_push16(0xB9F7); func_table_call_jsr(0x02D99A); g_cpu.S += 2;  /* B9F5 JSR */
    recomp_tick(14); return;  /* B9F8 RTS */
L_B9F9:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0346)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9F9 LDA */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* B9FC STA */
    recomp_tick(24); g_wr8(g_dp(0x1F), 0);  /* B9FE STZ */
    recomp_tick(16); g_rep(0x20);  /* BA00 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA02 LDA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA04 ASL */
    recomp_tick(32); g_wr16(g_dp(0x1E), (uint16_t)g_cpu.C);  /* BA05 STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA07 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA08 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA09 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* BA0A CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* BA0B ADC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* BA0D ADC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* BA0F ADC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x00B4));  /* BA11 ADC */
    recomp_tick(32); g_wr16(g_dp(0x1E), (uint16_t)g_cpu.C);  /* BA14 STA */
    recomp_tick(40); g_wr16(g_abs(0x0422), (uint16_t)g_cpu.C);  /* BA16 STA */
    recomp_tick(16); g_sep(0x20);  /* BA19 SEP */
    recomp_tick(14); return;  /* BA1B RTS */
}

/* $02B9F9, entered with P=$20 via JSR */
void gen_02B9F9(void) {
    goto L_B9F9;
L_B9F9:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0346)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* B9F9 LDA */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* B9FC STA */
    recomp_tick(24); g_wr8(g_dp(0x1F), 0);  /* B9FE STZ */
    recomp_tick(16); g_rep(0x20);  /* BA00 REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA02 LDA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA04 ASL */
    recomp_tick(32); g_wr16(g_dp(0x1E), (uint16_t)g_cpu.C);  /* BA05 STA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA07 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA08 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA09 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* BA0A CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* BA0B ADC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* BA0D ADC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x1E))));  /* BA0F ADC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x00B4));  /* BA11 ADC */
    recomp_tick(32); g_wr16(g_dp(0x1E), (uint16_t)g_cpu.C);  /* BA14 STA */
    recomp_tick(40); g_wr16(g_abs(0x0422), (uint16_t)g_cpu.C);  /* BA16 STA */
    recomp_tick(16); g_sep(0x20);  /* BA19 SEP */
    recomp_tick(14); return;  /* BA1B RTS */
}

/* $02BCCB, entered with P=$20 via JSR */
void gen_02BCCB(void) {
    goto L_BCCB;
L_BCCB:;
    recomp_tick(14); ;  /* BCCB NOP */
    recomp_tick(14); return;  /* BCCC RTS */
}

/* $02BDB3, entered with P=$20 via JSR */
void gen_02BDB3(void) {
    goto L_BDB3;
L_BDB3:;
    recomp_tick(16); g_rep(0x20);  /* BDB3 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BDB5 TXA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BDB6 DEC */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BDB7 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BDB8 TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x11D32Cu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BDB9 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BDBD TAX */
    recomp_tick(16); g_sep(0x20);  /* BDBE SEP */
    recomp_tick(16); { uint8_t _v = 0x11; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BDC0 LDA */
    recomp_tick(24); g_wr8(g_dp(0x49), (uint8_t)(uint8_t)g_cpu.C);  /* BDC2 STA */
    recomp_tick(14); return;  /* BDC4 RTS */
}

/* $02BE10, entered with P=$20 via JSR */
void gen_02BE10(void) {
    goto L_BE10;
L_BE10:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BE10 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1779)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BE11 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BE14 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0350)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BE15 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* BE18 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BE27;  /* BE1A BCC */
    recomp_tick(32); g_wr8(g_abs(0x1779), 0);  /* BE1C STZ */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BE1F TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BE20 TAX */
    recomp_tick(40); g_wr16(g_abs(0x177D), (uint16_t)g_cpu.X);  /* BE21 STX */
    recomp_tick(40); g_wr16(g_abs(0x03BA), (uint16_t)g_cpu.X);  /* BE24 STX */
L_BE27:;
    recomp_tick(14); return;  /* BE27 RTS */
}

/* $02C3B3, entered with P=$20 via JSR */
void gen_02C3B3(void) {
    goto L_C3B3;
L_C3B3:;
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* C3B3 STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* C3B5 LDY */
L_C3B7:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C3B7 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3B8 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* C3BB CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C3D1;  /* C3BD BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C3BF TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3C0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3C3 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C3C9;  /* C3C5 BEQ */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C3C7 INC */
L_C3C9:;
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C3C9 INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* C3CB INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* C3CC CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C3B7;  /* C3CF BNE */
L_C3D1:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3D1 LDA */
    recomp_tick(14); return;  /* C3D3 RTS */
}

/* $02C3D4, entered with P=$20 via JSR */
void gen_02C3D4(void) {
    goto L_C3D4;
L_C3D4:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* C3D4 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C3D7 TDC */
L_C3D8:;
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* C3D8 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C3DB INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000A);  /* C3DC CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C3D8;  /* C3DF BNE */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* C3E1 LDY */
L_C3E3:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3E3 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* C3E6 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C415;  /* C3E8 BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x040A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3EA LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3ED AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C3EF TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C3F0 LDA */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0000);  /* C3F2 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C404;  /* C3F5 BEQ */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0004);  /* C3F7 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C409;  /* C3FA BEQ */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0005);  /* C3FC CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C404;  /* C3FF BEQ */
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* C401 STA */
L_C404:;
    recomp_tick(32); g_wr8(g_absx(0x0427), (uint8_t)(uint8_t)g_cpu.C);  /* C404 STA */
    recomp_tick(16); goto L_C40C;  /* C407 BRA */
L_C409:;
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* C409 STA */
L_C40C:;
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* C40C STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* C40F INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* C410 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C3E3;  /* C413 BNE */
L_C415:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* C415 LDY */
L_C417:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C417 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C424;  /* C41A BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* C41C INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x000A);  /* C41D CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C417;  /* C420 BNE */
    recomp_tick(14); g_cpu.flag_C = true;  /* C422 SEC */
    recomp_tick(14); return;  /* C423 RTS */
L_C424:;
    recomp_tick(14); g_cpu.flag_C = false;  /* C424 CLC */
    recomp_tick(14); return;  /* C425 RTS */
}

/* $02C4AB, entered with P=$20 via JSR */
void gen_02C4AB(void) {
    goto L_C4AB;
L_C4AB:;
    recomp_tick(32); g_wr8(g_abs(0x03A1), 0);  /* C4AB STZ */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* C4AE LDY */
    recomp_tick(40); g_wr16(g_abs(0x177B), (uint16_t)g_cpu.Y);  /* C4B1 STY */
    recomp_tick(40); g_wr16(g_abs(0x03C0), (uint16_t)g_cpu.Y);  /* C4B4 STY */
    recomp_tick(40); g_wr16(g_abs(0x03C2), (uint16_t)g_cpu.Y);  /* C4B7 STY */
    recomp_tick(40); g_wr16(g_abs(0x177F), (uint16_t)g_cpu.Y);  /* C4BA STY */
    recomp_tick(14); return;  /* C4BD RTS */
}

/* $02C4E4, entered with P=$20 via JSR */
void gen_02C4E4(void) {
    goto L_C4E4;
L_C4E4:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C4E4 TDC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C4E5 TAX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* C4E6 TAY */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* C4E7 STX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* C4E9 STX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* C4EB STX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* C4ED STX */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C4EF INC */
L_C4F1:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* C4F1 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C4F3 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4F4 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* C4F7 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C53D;  /* C4F9 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C4FB TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C4FC LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* C4FF STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* C501 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C503 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C504 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* C507 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C53D;  /* C509 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C50B TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C50C LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)));  /* C50F CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C53E;  /* C511 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C533;  /* C513 BCS */
L_C515:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* C515 LDX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.Y = _v; g_nz16(_v); }  /* C517 LDY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C519 LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* C51C STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C51E LDA */
    recomp_tick(32); g_wr8(g_absx(0x0F35), (uint8_t)(uint8_t)g_cpu.C);  /* C521 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C524 LDA */
    recomp_tick(32); g_wr8(g_absy(0x0F35), (uint8_t)(uint8_t)g_cpu.C);  /* C526 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C529 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C533;  /* C52B BEQ */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* C52D DEC */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* C52F DEC */
    recomp_tick(16); goto L_C4F1;  /* C531 BRA */
L_C533:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C533 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C535 INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C537 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x64);  /* C539 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C4F1;  /* C53B BNE */
L_C53D:;
    recomp_tick(14); return;  /* C53D RTS */
L_C53E:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* C53E LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C540 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C541 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C544 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF148u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C545 LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* C549 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* C54B LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C54D TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C54E LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C551 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF148u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C552 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)));  /* C556 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C55E;  /* C558 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C533;  /* C55A BCS */
    recomp_tick(16); goto L_C515;  /* C55C BRA */
L_C55E:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* C55E LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C560 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C561 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* C564 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C565 TAX */
    recomp_tick(16); g_rep(0x20);  /* C566 REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0ADA)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C568 LDA */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* C56B STA */
    recomp_tick(16); g_sep(0x20);  /* C56D SEP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* C56F LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C571 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C572 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* C575 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* C576 TAX */
    recomp_tick(16); g_rep(0x20);  /* C577 REP */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0ADA)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C579 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* C57C CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C586;  /* C57E BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C58A;  /* C580 BCS */
    recomp_tick(16); g_sep(0x20);  /* C582 SEP */
    recomp_tick(16); goto L_C515;  /* C584 BRA */
L_C586:;
    recomp_tick(16); g_sep(0x20);  /* C586 SEP */
    recomp_tick(16); goto L_C58E;  /* C588 BRA */
L_C58A:;
    recomp_tick(16); g_sep(0x20);  /* C58A SEP */
    recomp_tick(16); goto L_C533;  /* C58C BRA */
L_C58E:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.X = _v; g_nz16(_v); }  /* C58E LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C590 LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* C593 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* C595 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0F35)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C597 LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)));  /* C59A CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_C533;  /* C59C BCS */
    recomp_tick(24); goto L_C515;  /* C59E JMP */
}

/* $02C665, entered with P=$20 via JSR */
void gen_02C665(void) {
    goto L_C665;
L_C665:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1751)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C665 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C6B7;  /* C668 BEQ */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1753)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C66A LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x14);  /* C66D CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_C683;  /* C66F BCC */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* C671 LDX */
L_C674:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x1754)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C674 LDA */
    recomp_tick(32); g_wr8(g_absx(0x1753), (uint8_t)(uint8_t)g_cpu.C);  /* C677 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C67A INX */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0x1751)));  /* C67B CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C674;  /* C67E BNE */
    recomp_tick(40); { uint32_t _e = g_abs(0x1751); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* C680 DEC */
L_C683:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* C683 LDX */
L_C686:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* C686 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x1753)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C687 LDA */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04EE)));  /* C68A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_C691;  /* C68D BEQ */
    recomp_tick(16); goto L_C6A2;  /* C68F BRA */
L_C691:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x1754)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C691 LDA */
    recomp_tick(32); g_wr8(g_absx(0x1753), (uint8_t)(uint8_t)g_cpu.C);  /* C694 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C697 INX */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0x1751)));  /* C698 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C691;  /* C69B BNE */
    recomp_tick(40); { uint32_t _e = g_abs(0x1751); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* C69D DEC */
    recomp_tick(16); goto L_C6A8;  /* C6A0 BRA */
L_C6A2:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* C6A2 INX */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0x1751)));  /* C6A3 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C686;  /* C6A6 BNE */
L_C6A8:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1751)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C6A8 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x01);  /* C6AB CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_C6B5;  /* C6AD BNE */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* C6AF LDX */
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* C6B2 STX */
L_C6B5:;
    recomp_tick(14); g_cpu.flag_C = false;  /* C6B5 CLC */
    recomp_tick(14); return;  /* C6B6 RTS */
L_C6B7:;
    recomp_tick(14); g_cpu.flag_C = true;  /* C6B7 SEC */
    recomp_tick(14); return;  /* C6B8 RTS */
}

/* $02C718, entered with P=$20 via JSR */
void gen_02C718(void) {
    goto L_C718;
L_C718:;
    recomp_tick(14); g_cpu.flag_C = false;  /* C718 CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x041F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C719 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x03)));  /* C71C ADC */
    recomp_tick(32); g_wr8(g_abs(0x041F), (uint8_t)(uint8_t)g_cpu.C);  /* C71E STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x041E)); g_cpu.Y = _v; g_nz16(_v); }  /* C721 LDY */
    recomp_tick(32); g_wr16(g_dp(0x18), (uint16_t)g_cpu.Y);  /* C724 STY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0470)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C726 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* C729 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* C72C CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0471)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C72D LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x18)));  /* C730 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* C732 STA */
    recomp_tick(14); return;  /* C735 RTS */
}

/* $02CBA0, entered with P=$20 via JSR */
void gen_02CBA0(void) {
    goto L_CBA0;
L_CBA0:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* CBA0 LDX */
L_CBA2:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x157E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CBA2 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CBB0;  /* CBA5 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CBA7 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* CBA8 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x007E);  /* CBA9 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CBA2;  /* CBAC BNE */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CBAE LDA */
L_CBB0:;
    recomp_tick(14); return;  /* CBB0 RTS */
}

/* $02CD90, entered with P=$20 via JSR */
void gen_02CD90(void) {
    goto L_CD90;
L_CD90:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CD90 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x80);  /* CD93 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_CDBB;  /* CD95 BCS */
    recomp_tick(14); g_cpu.flag_C = true;  /* CD97 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0477)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CD98 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x34)));  /* CD9B SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* CD9D CLC */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CD9E LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CD9F LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CDA0 LSR */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* CDA1 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CDA3 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDA4 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x30)));  /* CDA7 SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* CDA9 CLC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CDAA ASL */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* CDAB STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CDAD CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDAE LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x10)));  /* CDB0 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* CDB2 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDB4 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x51)));  /* CDB6 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* CDB8 STA */
    recomp_tick(14); return;  /* CDBA RTS */
L_CDBB:;
    recomp_tick(14); g_cpu.flag_C = true;  /* CDBB SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0477)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDBC LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x34)));  /* CDBF SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* CDC1 CLC */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CDC2 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CDC3 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CDC4 LSR */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* CDC5 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* CDC7 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDC8 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x90)));  /* CDCB SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* CDCD CLC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CDCE ASL */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* CDCF STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* CDD1 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDD2 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x10)));  /* CDD4 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* CDD6 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CDD8 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x59)));  /* CDDA ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* CDDC STA */
    recomp_tick(14); return;  /* CDDE RTS */
}

/* $02D0A7, entered with P=$20 via JSR */
void gen_02D0A7(void) {
    goto L_D0A7;
L_D0A7:;
    recomp_tick(30); g_push16(0xD0A9); func_table_call_jsr(0x02D11B); g_cpu.S += 2;  /* D0A7 JSR */
    recomp_tick(30); g_push16(0xD0AC); func_table_call_jsr(0x02D779); g_cpu.S += 2;  /* D0AA JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), 0);  /* D0AD STZ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* D0AF LDX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* D0B2 STX */
L_D0B4:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* D0B4 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D0B6 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0B7 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D0BA CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D0DB;  /* D0BC BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D0BE TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0BF LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0C2 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D0D1;  /* D0C4 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0C6 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D0C8 TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0C9 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D0CB STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D0CE STA */
L_D0D1:;
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D0D1 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D0D3 INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0D5 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x05);  /* D0D7 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D0B4;  /* D0D9 BNE */
L_D0DB:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D0DB LDX */
L_D0DD:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0DD LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D0E0 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D0E7;  /* D0E2 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D0E4 INX */
    recomp_tick(16); goto L_D0DD;  /* D0E5 BRA */
L_D0E7:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* D0E7 STX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x071A)); g_cpu.X = _v; g_nz16(_v); }  /* D0EA LDX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xFFFF);  /* D0ED CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D115;  /* D0F0 BEQ */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xF0F0);  /* D0F2 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D112;  /* D0F5 BEQ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D0F7 LDX */
L_D0F9:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D0F9 LDA */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_abs(0x071C)));  /* D0FC CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D109;  /* D0FF BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0446)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D101 LDA */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_abs(0x071D)));  /* D104 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D112;  /* D107 BEQ */
L_D109:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D109 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x001E);  /* D10A CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D0F9;  /* D10D BNE */
    recomp_tick(24); goto L_D116;  /* D10F JMP */
L_D112:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* D112 STX */
L_D115:;
    recomp_tick(14); return;  /* D115 RTS */
L_D116:;
    recomp_tick(14); ;  /* D116 NOP */
    recomp_tick(14); ;  /* D117 NOP */
    recomp_tick(14); ;  /* D118 NOP */
    recomp_tick(16); goto L_D116;  /* D119 BRA */
}

/* $02D11B, entered with P=$20 via JSR */
void gen_02D11B(void) {
    goto L_D11B;
L_D116:;
    recomp_tick(14); ;  /* D116 NOP */
    recomp_tick(14); ;  /* D117 NOP */
    recomp_tick(14); ;  /* D118 NOP */
    recomp_tick(16); goto L_D116;  /* D119 BRA */
L_D11B:;
    recomp_tick(30); g_push16(0xD11D); func_table_call_jsr(0x02D77F); g_cpu.S += 2;  /* D11B JSR */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D11E LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* D120 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* D122 LDX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* D125 STX */
L_D127:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* D127 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D129 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D12A LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D12D CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D14E;  /* D12F BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D131 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D132 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D135 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D144;  /* D137 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D139 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D13B TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D13C LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D13E STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D141 STA */
L_D144:;
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D144 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D146 INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D148 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0A);  /* D14A CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D127;  /* D14C BNE */
L_D14E:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D14E LDX */
L_D150:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D150 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D153 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D160;  /* D155 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D157 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000A);  /* D158 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D150;  /* D15B BNE */
    recomp_tick(24); goto L_D116;  /* D15D JMP */
L_D160:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* D160 STX */
    recomp_tick(14); return;  /* D163 RTS */
}

/* $02D495, entered with P=$20 via JSR */
void gen_02D495(void) {
    goto L_D495;
L_D495:;
    recomp_tick(24); { uint16_t _v = 0x0400; g_cpu.Y = _v; g_nz16(_v); }  /* D495 LDY */
    recomp_tick(30); g_push16(0xD49A); func_table_call_jsr(0x02D56B); g_cpu.S += 2;  /* D498 JSR */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D4B1;  /* D49B BCS */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D49D LDX */
L_D49F:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD471)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D49F LDA */
    recomp_tick(32); g_wr8(g_absx(0x0424), (uint8_t)(uint8_t)g_cpu.C);  /* D4A2 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD489)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D4A5 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0444), (uint8_t)(uint8_t)g_cpu.C);  /* D4A8 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D4AB INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000C);  /* D4AC CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D49F;  /* D4AF BNE */
L_D4B1:;
    recomp_tick(24); { uint16_t _v = 0xD473; g_cpu.X = _v; g_nz16(_v); }  /* D4B1 LDX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* D4B4 STX */
    recomp_tick(24); { uint16_t _v = 0xD48B; g_cpu.X = _v; g_nz16(_v); }  /* D4B6 LDX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* D4B9 STX */
    recomp_tick(24); { uint16_t _v = 0x0400; g_cpu.X = _v; g_nz16(_v); }  /* D4BB LDX */
    recomp_tick(24); { uint16_t _v = 0x040A; g_cpu.Y = _v; g_nz16(_v); }  /* D4BE LDY */
    recomp_tick(24); goto L_D5AC;  /* D4C1 JMP */
L_D5AC:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* D5AC STX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.Y);  /* D5AE STY */
    recomp_tick(16); g_sep(0x10);  /* D5B0 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x4A)); g_cpu.Y = _v; g_nz8(_v); }  /* D5B2 LDY */
L_D5B4:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D5B4 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5B5 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D5B7 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D617;  /* D5B9 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* D5BB CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D617;  /* D5BD BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5BF TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C3 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5D2;  /* D5C5 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C7 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5C9 TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5CA LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D5CC STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D5CF STA */
L_D5D2:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5D2 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5D4 TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5D5 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x00);  /* D5D7 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5E9;  /* D5D9 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x04);  /* D5DB CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5F1;  /* D5DD BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x05);  /* D5DF CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5E9;  /* D5E1 BEQ */
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* D5E3 STA */
    recomp_tick(32); g_wr8(g_absx(0x0445), (uint8_t)(uint8_t)g_cpu.C);  /* D5E6 STA */
L_D5E9:;
    recomp_tick(32); g_wr8(g_absx(0x0427), (uint8_t)(uint8_t)g_cpu.C);  /* D5E9 STA */
    recomp_tick(32); g_wr8(g_absx(0x0447), (uint8_t)(uint8_t)g_cpu.C);  /* D5EC STA */
    recomp_tick(16); goto L_D5F7;  /* D5EF BRA */
L_D5F1:;
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* D5F1 STA */
    recomp_tick(32); g_wr8(g_absx(0x0445), (uint8_t)(uint8_t)g_cpu.C);  /* D5F4 STA */
L_D5F7:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* D5F7 PHX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D5F8 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5F9 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5FB TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5FC LDA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* D5FF PLX */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D600 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D617;  /* D602 BNE */
    recomp_tick(14); g_push8((uint8_t)g_cpu.Y);  /* D604 PHY */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D605 TXA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* D606 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D607 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D609 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D60C LDA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D60E STA */
    recomp_tick(16); { uint8_t _v = 0xF0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D611 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04B2), (uint8_t)(uint8_t)g_cpu.C);  /* D613 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.Y = _v; g_nz8(_v); }  /* D616 PLY */
L_D617:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz8(_v); }  /* D617 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.Y, 0x05);  /* D618 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D5B4;  /* D61A BNE */
    recomp_tick(16); g_rep(0x10);  /* D61C REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D61E LDX */
L_D620:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D620 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D623 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D62D;  /* D625 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D627 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000A);  /* D628 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D620;  /* D62B BNE */
L_D62D:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* D62D STX */
    recomp_tick(14); return;  /* D630 RTS */
}

/* $02D4C4, entered with P=$20 via JSR */
void gen_02D4C4(void) {
    goto L_D4C4;
L_D4C4:;
    recomp_tick(24); { uint16_t _v = 0x0405; g_cpu.Y = _v; g_nz16(_v); }  /* D4C4 LDY */
    recomp_tick(30); g_push16(0xD4C9); func_table_call_jsr(0x02D56B); g_cpu.S += 2;  /* D4C7 JSR */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D4E0;  /* D4CA BCS */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D4CC LDX */
L_D4CE:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD47D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D4CE LDA */
    recomp_tick(32); g_wr8(g_absx(0x0424), (uint8_t)(uint8_t)g_cpu.C);  /* D4D1 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xD489)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D4D4 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0444), (uint8_t)(uint8_t)g_cpu.C);  /* D4D7 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D4DA INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000C);  /* D4DB CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D4CE;  /* D4DE BNE */
L_D4E0:;
    recomp_tick(24); { uint16_t _v = 0xD47F; g_cpu.X = _v; g_nz16(_v); }  /* D4E0 LDX */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.X);  /* D4E3 STX */
    recomp_tick(24); { uint16_t _v = 0xD48B; g_cpu.X = _v; g_nz16(_v); }  /* D4E5 LDX */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.X);  /* D4E8 STX */
    recomp_tick(24); { uint16_t _v = 0x0405; g_cpu.X = _v; g_nz16(_v); }  /* D4EA LDX */
    recomp_tick(24); { uint16_t _v = 0x040F; g_cpu.Y = _v; g_nz16(_v); }  /* D4ED LDY */
    recomp_tick(24); goto L_D5AC;  /* D4F0 JMP */
L_D5AC:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* D5AC STX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.Y);  /* D5AE STY */
    recomp_tick(16); g_sep(0x10);  /* D5B0 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x4A)); g_cpu.Y = _v; g_nz8(_v); }  /* D5B2 LDY */
L_D5B4:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D5B4 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5B5 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D5B7 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D617;  /* D5B9 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* D5BB CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D617;  /* D5BD BEQ */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5BF TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C0 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C3 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5D2;  /* D5C5 BEQ */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5C7 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5C9 TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5CA LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D5CC STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D5CF STA */
L_D5D2:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x02)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5D2 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5D4 TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5D5 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x00);  /* D5D7 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5E9;  /* D5D9 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x04);  /* D5DB CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5F1;  /* D5DD BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x05);  /* D5DF CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D5E9;  /* D5E1 BEQ */
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* D5E3 STA */
    recomp_tick(32); g_wr8(g_absx(0x0445), (uint8_t)(uint8_t)g_cpu.C);  /* D5E6 STA */
L_D5E9:;
    recomp_tick(32); g_wr8(g_absx(0x0427), (uint8_t)(uint8_t)g_cpu.C);  /* D5E9 STA */
    recomp_tick(32); g_wr8(g_absx(0x0447), (uint8_t)(uint8_t)g_cpu.C);  /* D5EC STA */
    recomp_tick(16); goto L_D5F7;  /* D5EF BRA */
L_D5F1:;
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* D5F1 STA */
    recomp_tick(32); g_wr8(g_absx(0x0445), (uint8_t)(uint8_t)g_cpu.C);  /* D5F4 STA */
L_D5F7:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* D5F7 PHX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D5F8 TDC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5F9 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D5FB TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D5FC LDA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* D5FF PLX */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D600 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D617;  /* D602 BNE */
    recomp_tick(14); g_push8((uint8_t)g_cpu.Y);  /* D604 PHY */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D605 TXA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* D606 TAY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D607 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D609 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D60C LDA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D60E STA */
    recomp_tick(16); { uint8_t _v = 0xF0; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D611 LDA */
    recomp_tick(32); g_wr8(g_absx(0x04B2), (uint8_t)(uint8_t)g_cpu.C);  /* D613 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.Y = _v; g_nz8(_v); }  /* D616 PLY */
L_D617:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz8(_v); }  /* D617 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.Y, 0x05);  /* D618 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D5B4;  /* D61A BNE */
    recomp_tick(16); g_rep(0x10);  /* D61C REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D61E LDX */
L_D620:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D620 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* D623 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D62D;  /* D625 BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D627 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000A);  /* D628 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D620;  /* D62B BNE */
L_D62D:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* D62D STX */
    recomp_tick(14); return;  /* D630 RTS */
}

/* $02D56B, entered with P=$20 via JSR */
void gen_02D56B(void) {
    goto L_D56B;
L_D56B:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D56B LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D56D LDA */
L_D56F:;
    recomp_tick(32); g_wr8(g_absx(0x04B2), (uint8_t)(uint8_t)g_cpu.C);  /* D56F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D572 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x001E);  /* D573 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D56F;  /* D576 BNE */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.Y);  /* D578 STY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* D57A LDY */
L_D57C:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpiy(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D57C LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* D57E CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D5AA;  /* D580 BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* D582 INY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x0005);  /* D583 CPY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D57C;  /* D586 BNE */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D588 LDX */
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D58A LDA */
    recomp_tick(32); g_wr8(g_absx(0x0424), (uint8_t)(uint8_t)g_cpu.C);  /* D58C STA */
    recomp_tick(32); g_wr8(g_absx(0x0444), (uint8_t)(uint8_t)g_cpu.C);  /* D58F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D592 INX */
    recomp_tick(32); g_wr8(g_absx(0x0424), 0);  /* D593 STZ */
    recomp_tick(32); g_wr8(g_absx(0x0444), 0);  /* D596 STZ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D599 INX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D59A LDA */
L_D59C:;
    recomp_tick(32); g_wr8(g_absx(0x0424), (uint8_t)(uint8_t)g_cpu.C);  /* D59C STA */
    recomp_tick(32); g_wr8(g_absx(0x0444), (uint8_t)(uint8_t)g_cpu.C);  /* D59F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D5A2 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x000C);  /* D5A3 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D59C;  /* D5A6 BNE */
    recomp_tick(14); g_cpu.flag_C = true;  /* D5A8 SEC */
    recomp_tick(14); return;  /* D5A9 RTS */
L_D5AA:;
    recomp_tick(14); g_cpu.flag_C = false;  /* D5AA CLC */
    recomp_tick(14); return;  /* D5AB RTS */
}

/* $02D6E2, entered with P=$20 via JSR */
void gen_02D6E2(void) {
    goto L_D6E2;
L_D6E2:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D6E2 PHA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D6E3 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D6E4 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x40)));  /* D6E6 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* D6E8 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D6EA LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D6EC ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* D6EE STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D6F0 CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0419)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D6F1 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* D6F4 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* D6F6 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D6F9 PLA */
    recomp_tick(16); goto L_D704;  /* D6FA BRA */
L_D704:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D704 PHA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D705 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D706 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D707 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D708 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x34)));  /* D709 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* D70B STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D70E PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D70F CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x19)))));  /* D710 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* D712 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D714 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D715 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* D717 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* D719 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D71C LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D71E ADC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* D720 STA */
    recomp_tick(14); return;  /* D723 RTS */
}

/* $02D6FC, entered with P=$20 via JSR */
void gen_02D6FC(void) {
    goto L_D6FC;
L_D6FC:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D6FC PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0419)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D6FD LDA */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* D700 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D703 PLA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D704 PHA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D705 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D706 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D707 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D708 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x34)));  /* D709 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* D70B STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D70E PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D70F CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x19)))));  /* D710 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* D712 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D714 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D715 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* D717 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* D719 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D71C LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D71E ADC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* D720 STA */
    recomp_tick(14); return;  /* D723 RTS */
}

/* $02D724, entered with P=$20 via JSR */
void gen_02D724(void) {
    goto L_D724;
L_D724:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0420)); g_cpu.X = _v; g_nz16(_v); }  /* D724 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x040A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D727 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D72A AND */
    recomp_tick(14); return;  /* D72C RTS */
}

/* $02D72D, entered with P=$30 via JSR */
void gen_02D72D(void) {
    goto L_D72D;
L_D72D:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D72D TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D72E LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D731 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D732 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D733 LDA */
    recomp_tick(32); g_wr8(g_abs(0x04F4), (uint8_t)(uint8_t)g_cpu.C);  /* D736 STA */
    recomp_tick(14); return;  /* D739 RTS */
}

/* $02D747, entered with P=$20 via JSR */
void gen_02D747(void) {
    goto L_D747;
L_D747:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* D747 LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D749 LDA */
L_D74B:;
    recomp_tick(32); g_wr8(g_absx(0x04B2), (uint8_t)(uint8_t)g_cpu.C);  /* D74B STA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* D74E STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* D751 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* D754 INX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x001E);  /* D755 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D74B;  /* D758 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04F4)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D75A LDA */
    recomp_tick(24); goto L_D99A;  /* D75D JMP */
L_D99A:;
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* D99A STA */
    recomp_tick(24); g_wr8(g_dp(0x1F), 0);  /* D99C STZ */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D99E ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x1F); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D99F ROL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D9A1 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x1F); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D9A2 ROL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D9A4 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1E)))));  /* D9A5 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* D9A7 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9A9 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D9AB ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* D9AD STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* D9AF LDX */
    recomp_tick(40); g_wr16(g_abs(0x0422), (uint16_t)g_cpu.X);  /* D9B1 STX */
    recomp_tick(14); return;  /* D9B4 RTS */
}

/* $02D75A, entered with P=$20 via JSR */
void gen_02D75A(void) {
    goto L_D75A;
L_D75A:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04F4)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D75A LDA */
    recomp_tick(24); goto L_D99A;  /* D75D JMP */
L_D99A:;
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* D99A STA */
    recomp_tick(24); g_wr8(g_dp(0x1F), 0);  /* D99C STZ */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D99E ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x1F); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D99F ROL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D9A1 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x1F); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D9A2 ROL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D9A4 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1E)))));  /* D9A5 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* D9A7 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9A9 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D9AB ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* D9AD STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* D9AF LDX */
    recomp_tick(40); g_wr16(g_abs(0x0422), (uint16_t)g_cpu.X);  /* D9B1 STX */
    recomp_tick(14); return;  /* D9B4 RTS */
}

/* $02D779, entered with P=$20 via JSR */
void gen_02D779(void) {
    goto L_D779;
L_D779:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D779 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D77A LDA */
    recomp_tick(16); goto L_D783;  /* D77D BRA */
L_D783:;
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D783 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D784 TAX */
    recomp_tick(16); g_sep(0x10);  /* D785 SEP */
    recomp_tick(16); g_rep(0x10);  /* D787 REP */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D789 LDA */
    recomp_tick(30); g_push16(0xD78E); func_table_call_jsr(0x02D99A); g_cpu.S += 2;  /* D78C JSR */
    recomp_tick(14); return;  /* D78F RTS */
}

/* $02D77F, entered with P=$20 via JSR */
void gen_02D77F(void) {
    goto L_D77F;
L_D77F:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D77F TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04DF)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D780 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D783 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D784 TAX */
    recomp_tick(16); g_sep(0x10);  /* D785 SEP */
    recomp_tick(16); g_rep(0x10);  /* D787 REP */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D789 LDA */
    recomp_tick(30); g_push16(0xD78E); func_table_call_jsr(0x02D99A); g_cpu.S += 2;  /* D78C JSR */
    recomp_tick(14); return;  /* D78F RTS */
}

/* $02D7BC, entered with P=$20 via JSR */
void gen_02D7BC(void) {
    goto L_D7BC;
L_D7BC:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D7BC PHA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7BD CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7BE LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x40)));  /* D7C0 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* D7C2 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7C4 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D7C6 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* D7C8 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7CA CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0419)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7CB LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* D7CE ADC */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* D7D0 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7D3 PLA */
    recomp_tick(16); goto L_D7DE;  /* D7D4 BRA */
L_D7DE:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D7DE PHA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D7DF ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D7E0 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D7E1 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7E2 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x34)));  /* D7E3 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* D7E5 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7E8 PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7E9 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x19)))));  /* D7EA ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* D7EC STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7EE CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7EF LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* D7F1 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* D7F3 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7F6 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D7F8 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* D7FA STA */
    recomp_tick(14); return;  /* D7FD RTS */
}

/* $02D7D6, entered with P=$20 via JSR */
void gen_02D7D6(void) {
    goto L_D7D6;
L_D7D6:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D7D6 PHA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0419)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7D7 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* D7DA STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7DD PLA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* D7DE PHA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D7DF ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D7E0 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D7E1 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7E2 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x34)));  /* D7E3 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* D7E5 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7E8 PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7E9 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x19)))));  /* D7EA ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* D7EC STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* D7EE CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7EF LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* D7F1 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* D7F3 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D7F6 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D7F8 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* D7FA STA */
    recomp_tick(14); return;  /* D7FD RTS */
}

/* $02D89A, entered with P=$20 via JSR */
void gen_02D89A(void) {
    goto L_D89A;
L_D89A:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* D89A TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0400)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D89B LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFE);  /* D89E CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_D8AE;  /* D8A0 BCS */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* D8A2 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D8A3 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x40); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D8A6 AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_D8AC;  /* D8A8 BEQ */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D8AA INC */
L_D8AC:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* D8AC INC */
L_D8AE:;
    recomp_tick(14); return;  /* D8AE RTS */
}

/* $02D999, entered with P=$30 via JSR */
void gen_02D999(void) {
    goto L_D999;
L_D999:;
    recomp_tick(14); return;  /* D999 RTS */
}

/* $02D99A, entered with P=$20 via JSR */
void gen_02D99A(void) {
    goto L_D99A;
L_D99A:;
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* D99A STA */
    recomp_tick(24); g_wr8(g_dp(0x1F), 0);  /* D99C STZ */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D99E ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x1F); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D99F ROL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D9A1 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x1F); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* D9A2 ROL */
    recomp_tick(14); g_cpu.flag_C = false;  /* D9A4 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1E)))));  /* D9A5 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* D9A7 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9A9 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* D9AB ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* D9AD STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* D9AF LDX */
    recomp_tick(40); g_wr16(g_abs(0x0422), (uint16_t)g_cpu.X);  /* D9B1 STX */
    recomp_tick(14); return;  /* D9B4 RTS */
}

/* $02D9C2, entered with P=$20 via JSR */
void gen_02D9C2(void) {
    goto L_D9C2;
L_D9C2:;
    recomp_tick(24); { uint16_t _v = 0x001E; g_cpu.X = _v; g_nz16(_v); }  /* D9C2 LDX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9C5 LDA */
L_D9C7:;
    recomp_tick(32); g_wr8(g_absx(0x0425), (uint8_t)(uint8_t)g_cpu.C);  /* D9C7 STA */
    recomp_tick(32); g_wr8(g_absx(0x0445), (uint8_t)(uint8_t)g_cpu.C);  /* D9CA STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz16(_v); }  /* D9CD DEX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_D9C7;  /* D9CE BNE */
    recomp_tick(14); return;  /* D9D0 RTS */
}

/* $02D9D1, entered with P=$30 via JSR */
void gen_02D9D1(void) {
    goto L_D9D1;
L_D9D1:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* D9D1 PHX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9D2 TXA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D9D3 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D9D4 TAX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* D9D5 PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07DB4Fu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9D6 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D9DA ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D9DB TAX */
    recomp_tick(16); g_rep(0x20);  /* D9DC REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x07DC49u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D9DE LDA */
    recomp_tick(40); g_wr16(g_abs(0x12BB), (uint16_t)g_cpu.C);  /* D9E2 STA */
    recomp_tick(24); { uint16_t _v = 0x0007; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D9E5 LDA */
    recomp_tick(40); g_wr16(g_abs(0x12BD), (uint16_t)g_cpu.C);  /* D9E8 STA */
    recomp_tick(16); g_sep(0x20);  /* D9EB SEP */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* D9ED PLX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07DB50u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* D9EE LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* D9F2 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* D9F3 TAX */
    recomp_tick(16); g_rep(0x20);  /* D9F4 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x07DC49u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D9F6 LDA */
    recomp_tick(40); g_wr16(g_abs(0x12BF), (uint16_t)g_cpu.C);  /* D9FA STA */
    recomp_tick(24); { uint16_t _v = 0x0007; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* D9FD LDA */
    recomp_tick(40); g_wr16(g_abs(0x12C1), (uint16_t)g_cpu.C);  /* DA00 STA */
    recomp_tick(16); g_sep(0x20);  /* DA03 SEP */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* DA05 PLX */
    recomp_tick(14); return;  /* DA06 RTS */
}

/* $02DDB6, entered with P=$20 via JSR */
void gen_02DDB6(void) {
    goto L_DDB6;
L_DDB6:;
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* DDB6 PHX */
    recomp_tick(24); g_wr8(g_dp(0x1A), (uint8_t)(uint8_t)g_cpu.C);  /* DDB7 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDB9 DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* DDBA TAX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x14)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDBB LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AED4u)));  /* DDBD CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_DDE1;  /* DDC1 BCC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDC3 LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AFBBu)));  /* DDC5 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_DDE1;  /* DDC9 BCC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x16)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDCB LDA */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AF21u)));  /* DDCD CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_DDE1;  /* DDD1 BCC */
    recomp_tick(40); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_longx(0x09AF6Eu)));  /* DDD3 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_DDDB;  /* DDD7 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_DDE1;  /* DDD9 BCS */
L_DDDB:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* DDDB LDA */
    recomp_tick(32); g_wr8(g_absy(0x0390), (uint8_t)(uint8_t)g_cpu.C);  /* DDDD STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* DDE0 INY */
L_DDE1:;
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* DDE1 PLX */
    recomp_tick(14); return;  /* DDE2 RTS */
}

/* $02E309, entered with P=$20 via JSR */
void gen_02E309(void) {
    goto L_E309;
L_E309:;
    recomp_tick(30); g_push16(0xE30B); func_table_call_jsr(0x02B9ED); g_cpu.S += 2;  /* E309 JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* E30C LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E30E TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E30F LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* E312 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0DCD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E314 LDA */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* E317 STA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.X);  /* E319 STX */
    recomp_tick(14); g_cpu.flag_C = false;  /* E31B CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E31C LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0474)))));  /* E31E ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* E321 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E323 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* E325 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* E327 STA */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* E329 PHX */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* E32A LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E32C LDA */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* E32F STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0DCD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E331 LDA */
    recomp_tick(24); g_wr8(g_dp(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* E334 STA */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* E336 STX */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* E338 PLX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E339 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0E81), (uint8_t)(uint8_t)g_cpu.C);  /* E33B STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x07)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E33E LDA */
    recomp_tick(32); g_wr8(g_absx(0x0DCD), (uint8_t)(uint8_t)g_cpu.C);  /* E340 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* E343 LDX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E345 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0E81), (uint8_t)(uint8_t)g_cpu.C);  /* E347 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x05)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E34A LDA */
    recomp_tick(32); g_wr8(g_absx(0x0DCD), (uint8_t)(uint8_t)g_cpu.C);  /* E34C STA */
    recomp_tick(24); g_wr8(g_dp(0x05), 0);  /* E34F STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.X = _v; g_nz16(_v); }  /* E351 LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E353 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x7F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E356 AND */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* E358 STA */
    recomp_tick(24); g_wr8(g_dp(0x07), 0);  /* E35B STZ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.X = _v; g_nz16(_v); }  /* E35D LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E35F LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E362 ORA */
    recomp_tick(32); g_wr8(g_absx(0x08FA), (uint8_t)(uint8_t)g_cpu.C);  /* E364 STA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E367 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E368 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E36B ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E36C TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x1A45)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E36D LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x09);  /* E370 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E37A;  /* E372 BNE */
    recomp_tick(32); g_wr8(g_absx(0x19A6), 0);  /* E374 STZ */
    recomp_tick(32); g_wr8(g_absx(0x1A45), 0);  /* E377 STZ */
L_E37A:;
    recomp_tick(14); return;  /* E37A RTS */
}

/* $02E4B2, entered with P=$20 via JSR */
void gen_02E4B2(void) {
    goto L_E4B2;
L_E4B2:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4B2 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x80);  /* E4B5 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_E4DD;  /* E4B7 BCS */
    recomp_tick(14); g_cpu.flag_C = true;  /* E4B9 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0477)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4BA LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x34)));  /* E4BD SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* E4BF CLC */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4C0 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4C1 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4C2 LSR */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* E4C3 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* E4C5 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4C6 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x30)));  /* E4C9 SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* E4CB CLC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4CC ASL */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* E4CD STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E4CF CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4D0 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x10)));  /* E4D2 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* E4D4 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4D6 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x51)));  /* E4D8 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* E4DA STA */
    recomp_tick(14); return;  /* E4DC RTS */
L_E4DD:;
    recomp_tick(14); g_cpu.flag_C = true;  /* E4DD SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0477)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4DE LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x34)));  /* E4E1 SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* E4E3 CLC */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4E4 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4E5 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4E6 LSR */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* E4E7 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* E4E9 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4EA LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x90)));  /* E4ED SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* E4EF CLC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E4F0 ASL */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* E4F1 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E4F3 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4F4 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x10)));  /* E4F6 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* E4F8 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E4FA LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x59)));  /* E4FC ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* E4FE STA */
    recomp_tick(14); return;  /* E500 RTS */
}

/* $02E549, entered with P=$20 via JSR */
void gen_02E549(void) {
    goto L_E549;
L_E549:;
    recomp_tick(14); g_cpu.flag_C = true;  /* E549 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0477)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E54A LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x24)));  /* E54D SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* E54F CLC */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E550 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E551 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E552 LSR */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* E553 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* E555 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0476)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E556 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x60)));  /* E559 SBC */
    recomp_tick(14); g_cpu.flag_C = false;  /* E55B CLC */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E55C ASL */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* E55D STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E55F CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E560 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x10)));  /* E562 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* E564 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E566 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x51)));  /* E568 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* E56A STA */
    recomp_tick(14); return;  /* E56C RTS */
}

/* $02E66F, entered with P=$20 via JSR */
void gen_02E66F(void) {
    goto L_E66F;
L_E66F:;
    recomp_tick(30); g_push16(0xE671); func_table_call_jsr(0x02D779); g_cpu.S += 2;  /* E66F JSR */
    recomp_tick(24); g_wr8(g_dp(0x00), 0);  /* E672 STZ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* E674 LDX */
    recomp_tick(32); g_wr16(g_dp(0x02), (uint16_t)g_cpu.X);  /* E677 STX */
L_E679:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.X = _v; g_nz16(_v); }  /* E679 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E67B TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E67C LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* E67F CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E6A7;  /* E681 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E683 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E684 LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E687 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E692;  /* E689 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E68B LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x80); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E68E AND */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_E69D;  /* E690 BEQ */
L_E692:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E692 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E694 TAX */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E695 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0426), (uint8_t)(uint8_t)g_cpu.C);  /* E697 STA */
    recomp_tick(32); g_wr8(g_absx(0x0446), (uint8_t)(uint8_t)g_cpu.C);  /* E69A STA */
L_E69D:;
    recomp_tick(32); { uint32_t _e = g_dp(0x02); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* E69D INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* E69F INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E6A1 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x05);  /* E6A3 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E679;  /* E6A5 BNE */
L_E6A7:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.X = _v; g_nz16(_v); }  /* E6A7 LDX */
L_E6A9:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0426)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E6A9 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* E6AC CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_E6B3;  /* E6AE BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* E6B0 INX */
    recomp_tick(16); goto L_E6A9;  /* E6B1 BRA */
L_E6B3:;
    recomp_tick(40); g_wr16(g_abs(0x0474), (uint16_t)g_cpu.X);  /* E6B3 STX */
    recomp_tick(14); return;  /* E6B6 RTS */
}

/* $02E724, entered with P=$20 via JSR */
void gen_02E724(void) {
    goto L_E724;
L_E724:;
    recomp_tick(30); g_push16(0xE726); func_table_call_jsr(0x02B9ED); g_cpu.S += 2;  /* E724 JSR */
    recomp_tick(14); g_cpu.flag_C = false;  /* E727 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E728 LDA */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0474)))));  /* E72A ADC */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* E72D STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E72F LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* E731 ADC */
    recomp_tick(24); g_wr8(g_dp(0x1F), (uint8_t)(uint8_t)g_cpu.C);  /* E733 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* E735 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E737 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E738 LDA */
    recomp_tick(14); return;  /* E73B RTS */
}

/* $02E968, entered with P=$20 via JSR */
void gen_02E968(void) {
    goto L_E968;
L_E968:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E968 TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04EE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E969 LDA */
    recomp_tick(16); goto L_E972;  /* E96C BRA */
L_E972:;
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E972 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E973 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E974 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x19);  /* E977 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_E97D;  /* E979 BCC */
    recomp_tick(14); g_cpu.flag_C = true;  /* E97B SEC */
    recomp_tick(14); return;  /* E97C RTS */
L_E97D:;
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E97D INC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* E97E STA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0A);  /* E980 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_E988;  /* E982 BCS */
    recomp_tick(16); { uint8_t _v = 0x7D; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E984 LDA */
    recomp_tick(16); goto L_E99C;  /* E986 BRA */
L_E988:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x14);  /* E988 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_E995;  /* E98A BCS */
    recomp_tick(14); g_cpu.flag_C = true;  /* E98C SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x0A)));  /* E98D SBC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* E98F STA */
    recomp_tick(16); { uint8_t _v = 0x74; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E991 LDA */
    recomp_tick(16); goto L_E99C;  /* E993 BRA */
L_E995:;
    recomp_tick(14); g_cpu.flag_C = true;  /* E995 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x14)));  /* E996 SBC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* E998 STA */
    recomp_tick(16); { uint8_t _v = 0x75; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E99A LDA */
L_E99C:;
    recomp_tick(32); g_wr8(g_abs(0x1789), (uint8_t)(uint8_t)g_cpu.C);  /* E99C STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E99F CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E9A0 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x73)));  /* E9A2 ADC */
    recomp_tick(32); g_wr8(g_abs(0x178A), (uint8_t)(uint8_t)g_cpu.C);  /* E9A4 STA */
    recomp_tick(16); { uint8_t _v = 0x5E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E9A7 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1788), (uint8_t)(uint8_t)g_cpu.C);  /* E9A9 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E9AC INC */
    recomp_tick(32); g_wr8(g_abs(0x178B), (uint8_t)(uint8_t)g_cpu.C);  /* E9AD STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E9B0 CLC */
    recomp_tick(14); return;  /* E9B1 RTS */
}

/* $02E96E, entered with P=$20 via JSR */
void gen_02E96E(void) {
    goto L_E96E;
L_E96E:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* E96E TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04DF)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E96F LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* E972 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* E973 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x19CD)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E974 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x19);  /* E977 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_E97D;  /* E979 BCC */
    recomp_tick(14); g_cpu.flag_C = true;  /* E97B SEC */
    recomp_tick(14); return;  /* E97C RTS */
L_E97D:;
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E97D INC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* E97E STA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0A);  /* E980 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_E988;  /* E982 BCS */
    recomp_tick(16); { uint8_t _v = 0x7D; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E984 LDA */
    recomp_tick(16); goto L_E99C;  /* E986 BRA */
L_E988:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x14);  /* E988 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_E995;  /* E98A BCS */
    recomp_tick(14); g_cpu.flag_C = true;  /* E98C SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x0A)));  /* E98D SBC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* E98F STA */
    recomp_tick(16); { uint8_t _v = 0x74; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E991 LDA */
    recomp_tick(16); goto L_E99C;  /* E993 BRA */
L_E995:;
    recomp_tick(14); g_cpu.flag_C = true;  /* E995 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x14)));  /* E996 SBC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* E998 STA */
    recomp_tick(16); { uint8_t _v = 0x75; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E99A LDA */
L_E99C:;
    recomp_tick(32); g_wr8(g_abs(0x1789), (uint8_t)(uint8_t)g_cpu.C);  /* E99C STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E99F CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E9A0 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x73)));  /* E9A2 ADC */
    recomp_tick(32); g_wr8(g_abs(0x178A), (uint8_t)(uint8_t)g_cpu.C);  /* E9A4 STA */
    recomp_tick(16); { uint8_t _v = 0x5E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E9A7 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1788), (uint8_t)(uint8_t)g_cpu.C);  /* E9A9 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E9AC INC */
    recomp_tick(32); g_wr8(g_abs(0x178B), (uint8_t)(uint8_t)g_cpu.C);  /* E9AD STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* E9B0 CLC */
    recomp_tick(14); return;  /* E9B1 RTS */
}

/* $02EB20, entered with P=$20 via JSR */
void gen_02EB20(void) {
    goto L_EB20;
L_EB20:;
    recomp_tick(32); g_wr8(g_absx(0x0500), (uint8_t)(uint8_t)g_cpu.C);  /* EB20 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* EB23 INX */
    recomp_tick(32); { uint32_t _e = g_dp(0x15); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* EB24 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_EB20;  /* EB26 BNE */
    recomp_tick(14); return;  /* EB28 RTS */
}

/* $02EDF8, entered with P=$20 via JSR */
void gen_02EDF8(void) {
    goto L_EDF8;
L_EDF8:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0E);  /* EDF8 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_EDFE;  /* EDFA BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* EDFC INC */
    recomp_tick(14); return;  /* EDFD RTS */
L_EDFE:;
    recomp_tick(16); { uint8_t _v = 0x0A; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* EDFE LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* EE00 SEC */
    recomp_tick(14); return;  /* EE01 RTS */
}

/* $02F417, entered with P=$20 via JSR */
void gen_02F417(void) {
    goto L_F417;
L_F417:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F417 PHA */
    recomp_tick(14); g_cpu.flag_C = false;  /* F418 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F419 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x40)));  /* F41B ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* F41D STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F41F LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* F421 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* F423 STA */
    recomp_tick(16); { uint8_t _v = 0x80; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F425 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* F427 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F42A PLA */
    recomp_tick(16); goto L_F434;  /* F42B BRA */
L_F434:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F434 PHA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F435 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F436 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F437 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* F438 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x34)));  /* F439 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* F43B STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F43E PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* F43F CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x19)))));  /* F440 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* F442 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0473)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F444 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F459;  /* F447 BNE */
    recomp_tick(14); g_cpu.flag_C = false;  /* F449 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F44A LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* F44C ADC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* F44E STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F451 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* F453 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* F455 STA */
    recomp_tick(14); return;  /* F458 RTS */
L_F459:;
    recomp_tick(14); g_cpu.flag_C = true;  /* F459 SEC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F45A LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x20)));  /* F45C SBC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* F45E STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F461 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x00)));  /* F463 SBC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* F465 STA */
    recomp_tick(14); return;  /* F468 RTS */
}

/* $02F42D, entered with P=$20 via JSR */
void gen_02F42D(void) {
    goto L_F42D;
L_F42D:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F42D PHA */
    recomp_tick(16); { uint8_t _v = 0x60; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F42E LDA */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* F430 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F433 PLA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F434 PHA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F435 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F436 ASL */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F437 ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* F438 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x34)));  /* F439 ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* F43B STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F43E PLA */
    recomp_tick(14); g_cpu.flag_C = false;  /* F43F CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x19)))));  /* F440 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* F442 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0473)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F444 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F459;  /* F447 BNE */
    recomp_tick(14); g_cpu.flag_C = false;  /* F449 CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F44A LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* F44C ADC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* F44E STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F451 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* F453 ADC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* F455 STA */
    recomp_tick(14); return;  /* F458 RTS */
L_F459:;
    recomp_tick(14); g_cpu.flag_C = true;  /* F459 SEC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F45A LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x20)));  /* F45C SBC */
    recomp_tick(32); g_wr8(g_abs(0x047C), (uint8_t)(uint8_t)g_cpu.C);  /* F45E STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F461 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x00)));  /* F463 SBC */
    recomp_tick(32); g_wr8(g_abs(0x047D), (uint8_t)(uint8_t)g_cpu.C);  /* F465 STA */
    recomp_tick(14); return;  /* F468 RTS */
}

/* $02F469, entered with P=$20 via JSR */
void gen_02F469(void) {
    goto L_F469;
L_F469:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0473)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F469 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_F479;  /* F46C BEQ */
    recomp_tick(30); g_push16(0xF470); func_table_call_jsr(0x02F479); g_cpu.S += 2;  /* F46E JSR */
    recomp_tick(24); g_wr8(g_dp(0x1E), (uint8_t)(uint8_t)g_cpu.C);  /* F471 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* F473 SEC */
    recomp_tick(16); { uint8_t _v = 0x09; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F474 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x1E)))));  /* F476 SBC */
    recomp_tick(14); return;  /* F478 RTS */
L_F479:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* F479 LDX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x000DCDu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F47C LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F480 AND */
    recomp_tick(14); return;  /* F482 RTS */
}

/* $02F479, entered with P=$20 via JSR */
void gen_02F479(void) {
    goto L_F479;
L_F479:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x0422)); g_cpu.X = _v; g_nz16(_v); }  /* F479 LDX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x000DCDu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F47C LDA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F480 AND */
    recomp_tick(14); return;  /* F482 RTS */
}

/* $02F5C2, entered with P=$20 via JSR */
void gen_02F5C2(void) {
    goto L_F5C2;
L_F5C2:;
    recomp_tick(14); g_cpu.flag_C = false;  /* F5C2 CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x041F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F5C3 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x03)));  /* F5C6 ADC */
    recomp_tick(32); g_wr8(g_abs(0x041F), (uint8_t)(uint8_t)g_cpu.C);  /* F5C8 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x041E)); g_cpu.Y = _v; g_nz16(_v); }  /* F5CB LDY */
    recomp_tick(32); g_wr16(g_dp(0x18), (uint16_t)g_cpu.Y);  /* F5CE STY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0470)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F5D0 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0472), (uint8_t)(uint8_t)g_cpu.C);  /* F5D3 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* F5D6 CLC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0471)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F5D7 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x18)));  /* F5DA ADC */
    recomp_tick(32); g_wr8(g_abs(0x0471), (uint8_t)(uint8_t)g_cpu.C);  /* F5DC STA */
    recomp_tick(14); return;  /* F5DF RTS */
}

/* $02F7A7, entered with P=$20 via JSR */
void gen_02F7A7(void) {
    goto L_F7A7;
L_F7A7:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F7A7 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F7A8 TDC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F7A9 PLA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F7AA PHA */
    recomp_tick(16); g_rep(0x20);  /* F7AB REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F7AD ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F7AE ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F7AF ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F7B0 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F7B1 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F7B2 TAX */
    recomp_tick(16); g_sep(0x20);  /* F7B3 SEP */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* F7B5 PHX */
    recomp_tick(24); { uint16_t _v = 0x0020; g_cpu.Y = _v; g_nz16(_v); }  /* F7B6 LDY */
L_F7B9:;
    recomp_tick(24); g_wr8(g_dp(0x00), 0);  /* F7B9 STZ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x0AA000u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F7BB LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7BF ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7C0 ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7C2 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7C3 ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7C5 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7C6 ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7C8 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7C9 ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7CB ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7CC ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7CE ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7CF ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7D1 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7D2 ROR */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* F7D4 ASL */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* F7D5 ROR */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F7D7 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7F6000u), (uint8_t)(uint8_t)g_cpu.C);  /* F7D9 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* F7DD INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* F7DE DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F7B9;  /* F7DF BNE */
    recomp_tick(16); { uint8_t _v = 0x7F; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F7E1 LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* F7E3 STA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* F7E5 PLX */
    recomp_tick(16); g_rep(0x20);  /* F7E6 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7E8 TXA */
    recomp_tick(14); g_cpu.flag_C = false;  /* F7E9 CLC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, 0x6000));  /* F7EA ADC */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* F7ED STA */
L_F7EF:;
    recomp_tick(24); { uint16_t _v = 0x0010; g_cpu.Y = _v; g_nz16(_v); }  /* F7EF LDY */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpil(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7F2 LDA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpily(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7F4 ORA */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* F7F6 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x4A)); g_cpu.Y = _v; g_nz16(_v); }  /* F7F8 LDY */
    recomp_tick(16); g_sep(0x20);  /* F7FA SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x04)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F7FC LDA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x05))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F7FE ORA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F800 EOR */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x00))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F802 ORA */
    recomp_tick(24); g_wr8(g_dpily(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* F804 STA */
    recomp_tick(16); g_rep(0x20);  /* F806 REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* F808 INC */
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* F80A INC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F80C LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x000F); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F80E AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F7EF;  /* F811 BNE */
    recomp_tick(16); g_sep(0x20);  /* F813 SEP */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F815 PLA */
    recomp_tick(14); return;  /* F816 RTS */
}

/* $02F817, entered with P=$20 via JSR */
void gen_02F817(void) {
    goto L_F817;
L_F817:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F817 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F818 TDC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F819 PLA */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* F81A PHA */
    recomp_tick(16); g_rep(0x20);  /* F81B REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F81D ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F81E ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F81F ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F820 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F821 ASL */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F822 TAX */
    recomp_tick(24); { uint16_t _v = 0x0008; g_cpu.Y = _v; g_nz16(_v); }  /* F823 LDY */
L_F826:;
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x0AA000u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F826 LDA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_longx(0x0AA010u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F82A ORA */
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* F82E STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x04)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F830 LDA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x05))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F832 ORA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F834 EOR */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F837 AND */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_longx(0x0AA000u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F83A ORA */
    recomp_tick(48); g_wr16(g_longx(0x7F2000u), (uint16_t)g_cpu.C);  /* F83E STA */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x0AA010u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F842 LDA */
    recomp_tick(48); g_wr16(g_longx(0x7F2010u), (uint16_t)g_cpu.C);  /* F846 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* F84A INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* F84B INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* F84C DEY */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F826;  /* F84D BNE */
    recomp_tick(16); g_sep(0x20);  /* F84F SEP */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F851 PLA */
    recomp_tick(14); return;  /* F852 RTS */
}

/* $02F936, entered with P=$20 via JSR */
void gen_02F936(void) {
    goto L_F936;
L_F936:;
    recomp_tick(14); g_cpu.flag_C = false;  /* F936 CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x18)))));  /* F937 ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* F939 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F93B LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* F93D ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* F93F STA */
    recomp_tick(14); return;  /* F941 RTS */
}

/* $02F9BD, entered with P=$20 via JSR */
void gen_02F9BD(void) {
    goto L_F9BD;
L_F9BD:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F9BD TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9BE LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F9C1 TAX */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0x0064);  /* F9C2 CPX */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_F9E3;  /* F9C5 BEQ */
L_F9C7:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9C7 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9CA DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F9CB TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x01E068u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9CC LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x26);  /* F9D0 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F9E0;  /* F9D2 BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(0x7EF620u); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9D4 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_F9DE;  /* F9D8 BEQ */
    recomp_tick(16); { uint8_t _v = 0x27; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9DA LDA */
    recomp_tick(16); goto L_F9E0;  /* F9DC BRA */
L_F9DE:;
    recomp_tick(16); { uint8_t _v = 0x26; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9DE LDA */
L_F9E0:;
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9E0 DEC */
    recomp_tick(16); goto L_F9EF;  /* F9E1 BRA */
L_F9E3:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1630)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9E3 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_F9C7;  /* F9E6 BNE */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9E8 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_F9C7;  /* F9EB BPL */
    recomp_tick(16); { uint8_t _v = 0x3E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9ED LDA */
L_F9EF:;
    recomp_tick(14); return;  /* F9EF RTS */
}

/* $02FB1D, entered with P=$20 via JSR */
void gen_02FB1D(void) {
    goto L_FB1D;
L_FB1D:;
    recomp_tick(14); ;  /* FB1D NOP */
    recomp_tick(14); return;  /* FB1E RTS */
}

void gen_register_bank_02(void) {
    func_table_register_flags(0x02813E, gen_02813E, false);
    func_table_register_flags(0x0283C8, gen_0283C8, false);
    func_table_register_flags(0x0283D7, gen_0283D7, false);
    func_table_register_flags(0x0283E6, gen_0283E6, false);
    func_table_register_flags(0x02840E, gen_02840E, false);
    func_table_register_flags(0x02843D, gen_02843D, false);
    func_table_register_flags(0x028455, gen_028455, false);
    func_table_register_flags(0x02847F, gen_02847F, false);
    func_table_register_flags(0x0284DD, gen_0284DD, false);
    func_table_register_flags(0x02857F, gen_02857F, false);
    func_table_register_flags(0x02872B, gen_02872B, false);
    func_table_register_flags(0x0287E7, gen_0287E7, false);
    func_table_register_flags(0x0289DB, gen_0289DB, false);
    func_table_register_flags(0x028EA8, gen_028EA8, false);
    func_table_register_flags(0x02955A, gen_02955A, false);
    func_table_register_flags(0x029707, gen_029707, false);
    func_table_register_flags(0x029988, gen_029988, false);
    func_table_register_flags(0x029B78, gen_029B78, false);
    func_table_register_flags(0x029D3D, gen_029D3D, false);
    func_table_register_flags(0x029D58, gen_029D58, false);
    func_table_register_flags(0x029D8A, gen_029D8A, false);
    func_table_register_flags(0x029FBC, gen_029FBC, false);
    func_table_register_flags(0x02A56C, gen_02A56C, false);
    func_table_register_flags(0x02A64C, gen_02A64C, false);
    func_table_register_flags(0x02A666, gen_02A666, false);
    func_table_register_flags(0x02A6B5, gen_02A6B5, false);
    func_table_register_flags(0x02A6CF, gen_02A6CF, false);
    func_table_register_flags(0x02A6D4, gen_02A6D4, false);
    func_table_register_flags(0x02A6D9, gen_02A6D9, false);
    func_table_register_flags(0x02A6DE, gen_02A6DE, false);
    func_table_register_flags(0x02AB9E, gen_02AB9E, false);
    func_table_register_flags(0x02ABF5, gen_02ABF5, false);
    func_table_register_flags(0x02AC2D, gen_02AC2D, false);
    func_table_register_flags(0x02AE4A, gen_02AE4A, false);
    func_table_register_flags(0x02AE62, gen_02AE62, false);
    func_table_register_flags(0x02AFC9, gen_02AFC9, false);
    func_table_register_flags(0x02B267, gen_02B267, false);
    func_table_register_flags(0x02B3B6, gen_02B3B6, false);
    func_table_register_flags(0x02B40E, gen_02B40E, false);
    func_table_register_flags(0x02B62D, gen_02B62D, false);
    func_table_register_flags(0x02B6A8, gen_02B6A8, false);
    func_table_register_flags(0x02B813, gen_02B813, false);
    func_table_register_flags(0x02B8E7, gen_02B8E7, false);
    func_table_register_flags(0x02B9ED, gen_02B9ED, false);
    func_table_register_flags(0x02B9F9, gen_02B9F9, false);
    func_table_register_flags(0x02BCCB, gen_02BCCB, false);
    func_table_register_flags(0x02BDB3, gen_02BDB3, false);
    func_table_register_flags(0x02BE10, gen_02BE10, false);
    func_table_register_flags(0x02C3B3, gen_02C3B3, false);
    func_table_register_flags(0x02C3D4, gen_02C3D4, false);
    func_table_register_flags(0x02C4AB, gen_02C4AB, false);
    func_table_register_flags(0x02C4E4, gen_02C4E4, false);
    func_table_register_flags(0x02C665, gen_02C665, false);
    func_table_register_flags(0x02C718, gen_02C718, false);
    func_table_register_flags(0x02CBA0, gen_02CBA0, false);
    func_table_register_flags(0x02CD90, gen_02CD90, false);
    func_table_register_flags(0x02D0A7, gen_02D0A7, false);
    func_table_register_flags(0x02D11B, gen_02D11B, false);
    func_table_register_flags(0x02D495, gen_02D495, false);
    func_table_register_flags(0x02D4C4, gen_02D4C4, false);
    func_table_register_flags(0x02D56B, gen_02D56B, false);
    func_table_register_flags(0x02D6E2, gen_02D6E2, false);
    func_table_register_flags(0x02D6FC, gen_02D6FC, false);
    func_table_register_flags(0x02D724, gen_02D724, false);
    func_table_register_flags(0x02D72D, gen_02D72D, false);
    func_table_register_flags(0x02D747, gen_02D747, false);
    func_table_register_flags(0x02D75A, gen_02D75A, false);
    func_table_register_flags(0x02D779, gen_02D779, false);
    func_table_register_flags(0x02D77F, gen_02D77F, false);
    func_table_register_flags(0x02D7BC, gen_02D7BC, false);
    func_table_register_flags(0x02D7D6, gen_02D7D6, false);
    func_table_register_flags(0x02D89A, gen_02D89A, false);
    func_table_register_flags(0x02D999, gen_02D999, false);
    func_table_register_flags(0x02D99A, gen_02D99A, false);
    func_table_register_flags(0x02D9C2, gen_02D9C2, false);
    func_table_register_flags(0x02D9D1, gen_02D9D1, false);
    func_table_register_flags(0x02DDB6, gen_02DDB6, false);
    func_table_register_flags(0x02E309, gen_02E309, false);
    func_table_register_flags(0x02E4B2, gen_02E4B2, false);
    func_table_register_flags(0x02E549, gen_02E549, false);
    func_table_register_flags(0x02E66F, gen_02E66F, false);
    func_table_register_flags(0x02E724, gen_02E724, false);
    func_table_register_flags(0x02E968, gen_02E968, false);
    func_table_register_flags(0x02E96E, gen_02E96E, false);
    func_table_register_flags(0x02EB20, gen_02EB20, false);
    func_table_register_flags(0x02EDF8, gen_02EDF8, false);
    func_table_register_flags(0x02F417, gen_02F417, false);
    func_table_register_flags(0x02F42D, gen_02F42D, false);
    func_table_register_flags(0x02F469, gen_02F469, false);
    func_table_register_flags(0x02F479, gen_02F479, false);
    func_table_register_flags(0x02F5C2, gen_02F5C2, false);
    func_table_register_flags(0x02F7A7, gen_02F7A7, false);
    func_table_register_flags(0x02F817, gen_02F817, false);
    func_table_register_flags(0x02F936, gen_02F936, false);
    func_table_register_flags(0x02F9BD, gen_02F9BD, false);
    func_table_register_flags(0x02FB1D, gen_02FB1D, false);
}
