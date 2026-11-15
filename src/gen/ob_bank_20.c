/* Bank $20 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 79 unlifted in Bank $20 */
/* not lifted: $208009: BRK at $20:806F */
/* not lifted: $20809E: PLD at $80A4 pulls below the entry stack (return-address trick) */
/* not lifted: $2080C6: BRK at $20:4643 */
/* not lifted: $208202: BRK at $20:8208 */
/* not lifted: $20827D: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2083E1: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2083F2: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $20844E: XCE at $20:8455 */
/* not lifted: $208470: COP at $20:8474 */
/* not lifted: $2084A2: BRK at $20:84E0 */
/* not lifted: $208DE7: BRK at $20:8DF1 */
/* not lifted: $2093A5: BRK at $20:93AB */
/* not lifted: $209402: COP at $20:940E */
/* not lifted: $209A95: PLP at $9A95 pulls below the entry stack (return-address trick) */
/* not lifted: $209B21: TCS at $9B33 with an unknown stack value */
/* not lifted: $209B45: PLA at $9B56 pulls below the entry stack (return-address trick) */
/* not lifted: $209C23: PLX at $9C4D pulls below the entry stack (return-address trick) */
/* not lifted: $209E7B: PLX at $9E7F pulls below the entry stack (return-address trick) */
/* not lifted: $209E86: COP at $20:9E86 */
/* not lifted: $209E87: XCE at $20:B628 */
/* not lifted: $209E93: XCE at $20:B628 */
/* not lifted: $209E9B: BRK at $20:9EB7 */
/* not lifted: $209EA2: BRK at $20:9EB7 */
/* not lifted: $209EAA: BRK at $20:9EAE */
/* not lifted: $209EB6: BRK at $20:9ED3 */
/* not lifted: $209EC2: BRK at $20:9ED3 */
/* not lifted: $209ED1: BRK at $20:9ED3 */
/* not lifted: $209EE0: XCE at $20:9EEC */
/* not lifted: $209F0F: BRK at $20:9F0F */
/* not lifted: $209F1E: WAI at $20:9F27 */
/* not lifted: $209F3C: calls RAM trampoline/sub-8000 ($20182B): executes native on LakeSnes */
/* not lifted: $209F6B: tail jump at $9F9F with 2 bytes pushed */
/* not lifted: $20A024: TXS at $20:A095 */
/* not lifted: $20A0E3: BRK at $20:A0E9 */
/* not lifted: $20A0EC: BRK at $20:A0F3 */
/* not lifted: $20A0F2: BRK at $20:A0FA */
/* not lifted: $20A113: BRK at $20:A117 */
/* not lifted: $20A125: BRK at $20:A15E */
/* not lifted: $20A2BD: BRK at $20:A2BD */
/* not lifted: $20A2CA: BRK at $20:A2CE */
/* not lifted: $20A2DC: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $20A2EE: XCE at $20:A33B */
/* not lifted: $20A30A: XCE at $20:A33B */
/* not lifted: $20A37A: calls RAM trampoline/sub-8000 ($D2075E): executes native on LakeSnes */
/* not lifted: $20A383: tail jump at $A35B with 2 bytes pushed */
/* not lifted: $20A391: tail jump at $A35B with 2 bytes pushed */
/* not lifted: $20A44A: BRK at $20:A5FC */
/* not lifted: $20A456: BRK at $20:A5FC */
/* not lifted: $20A468: BRK at $20:A5FC */
/* not lifted: $20A5B7: STP at $20:A5C0 */
/* not lifted: $20A5C4: tail jump at $A5A4 with 2 bytes pushed */
/* not lifted: $20A5D6: BRK at $20:A5EB */
/* not lifted: $20A5E8: BRK at $20:A5F8 */
/* not lifted: $20A604: calls RAM trampoline/sub-8000 ($5D5E5D): executes native on LakeSnes */
/* not lifted: $20A6D1: COP at $20:A6D4 */
/* not lifted: $20A80D: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $20A88C: BRK at $20:A8A7 */
/* not lifted: $20A8AF: XCE at $20:A8B8 */
/* not lifted: $20C0D1: STP at $20:C0E3 */
/* not lifted: $20C0D8: STP at $20:C0E3 */
/* not lifted: $20E181: COP at $20:E185 */
/* not lifted: $20E228: XCE at $20:E228 */
/* not lifted: $20E240: PLP at $E240 pulls below the entry stack (return-address trick) */
/* not lifted: $20E29D: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $20EB30: PLY at $EB30 pulls below the entry stack (return-address trick) */
/* not lifted: $20EB50: PLY at $EB67 pulls below the entry stack (return-address trick) */
/* not lifted: $20EC23: BRK at $20:006F */
/* not lifted: $20EC7F: PLY at $EC92 pulls below the entry stack (return-address trick) */
/* not lifted: $20EC97: PLY at $75D1 pulls below the entry stack (return-address trick) */
/* not lifted: $20ECA6: BRK at $20:ECA6 */
/* not lifted: $20ECB5: PLY at $75D1 pulls below the entry stack (return-address trick) */
/* not lifted: $20EDA8: PLY at $EE04 pulls below the entry stack (return-address trick) */
/* not lifted: $20EFEF: BRK at $20:EFF8 */
/* not lifted: $20F087: BRK at $20:F08C */
/* not lifted: $20F122: BRK at $20:F13C */
/* not lifted: $20F1CB: BRK at $20:F1DC */
/* not lifted: $20F1F4: BRK at $20:F20D */
/* not lifted: $20F24E: PLP at $F253 pulls below the entry stack (return-address trick) */
/* not lifted: $20FFF0: BRK at $20:FFFD */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $209B04, entered with P=$20 via JSR */
void gen_209B04(void) {
    goto L_9B04;
L_9B04:;
    recomp_tick(32); { uint32_t _e = g_dp(0xF9); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9B04 DEC */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9B06 DEC */
    recomp_tick(14); return;  /* 9B07 RTI */
}

/* $20A18C, entered with P=$20 via JSR */
void gen_20A18C(void) {
    goto L_A18C;
L_A18C:;
    recomp_tick(32); { uint32_t _e = g_dp(0xDA); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* A18C INC */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0x3D67))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A18E ORA */
    goto L_A191;
L_A18F:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpil(0x3D)))));  /* A18F ADC */
L_A191:;
    recomp_tick(16); goto L_A18F;  /* A191 BRA */
}

/* $20F46D, entered with P=$20 via JSR */
void gen_20F46D(void) {
    goto L_F46D;
L_F46D:;
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x03867Du)))));  /* F46D ADC */
    recomp_tick(14); return;  /* F471 RTS */
}

void gen_register_bank_20(void) {
    func_table_register_flags(0x209B04, gen_209B04, false);
    func_table_register_flags(0x20A18C, gen_20A18C, false);
    func_table_register_flags(0x20F46D, gen_20F46D, false);
}
