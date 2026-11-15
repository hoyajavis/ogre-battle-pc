/* Bank $38 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 63 unlifted in Bank $38 */
/* not lifted: $3882AA: XCE at $38:82AA */
/* not lifted: $388432: BRK at $38:8458 */
/* not lifted: $3888A0: COP at $38:88C2 */
/* not lifted: $38898A: BRK at $38:89AE */
/* not lifted: $388FF7: BRK at $38:9067 */
/* not lifted: $3890FC: COP at $38:3D6E */
/* not lifted: $38A1AA: BRK at $38:A1BE */
/* not lifted: $38A22A: BRK at $38:A252 */
/* not lifted: $38A2AA: COP at $38:A327 */
/* not lifted: $38A43F: BRK at $38:A463 */
/* not lifted: $38A5BE: $38:A5BE reached with two different M/X/stack states */
/* not lifted: $38A834: BRK at $38:A854 */
/* not lifted: $38AA22: STP at $38:AA40 */
/* not lifted: $38AA6A: BRK at $38:AA82 */
/* not lifted: $38AA8A: BRK at $38:AAB8 */
/* not lifted: $38AAAA: BRK at $38:AAB8 */
/* not lifted: $38ABA6: BRK at $38:ABE5 */
/* not lifted: $38AD88: BRK at $38:AD88 */
/* not lifted: $38B00C: COP at $38:B076 */
/* not lifted: $38B01D: COP at $38:B076 */
/* not lifted: $38B020: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $38B40F: BRK at $38:B43B */
/* not lifted: $38B41D: BRK at $38:B43B */
/* not lifted: $38BF3F: WAI at $38:BF6D */
/* not lifted: $38C01F: COP at $38:C07C */
/* not lifted: $38C020: COP at $38:C07C */
/* not lifted: $38C03F: COP at $38:C07C */
/* not lifted: $38C0D1: PLD at $C0EA pulls below the entry stack (return-address trick) */
/* not lifted: $38C0E1: PLD at $C0EA pulls below the entry stack (return-address trick) */
/* not lifted: $38C5F3: XCE at $38:C646 */
/* not lifted: $38CBED: RTI at $CC0F with 2 bytes still pushed */
/* not lifted: $38CBFF: BRK at $38:8458 */
/* not lifted: $38CCDF: tail jump at $CD38 with 1 bytes pushed */
/* not lifted: $38CEB0: COP at $38:CEFA */
/* not lifted: $38D202: WAI at $38:D211 */
/* not lifted: $38D3A0: BRK at $38:D3D5 */
/* not lifted: $38D5B0: XCE at $38:D5B0 */
/* not lifted: $38DBF2: COP at $38:DC38 */
/* not lifted: $38E20E: BRK at $38:E216 */
/* not lifted: $38E2CE: TXS at $38:E2CF */
/* not lifted: $38E464: PLP at $E469 pulls below the entry stack (return-address trick) */
/* not lifted: $38E4F4: COP at $38:8E3A */
/* not lifted: $38E4FC: PLP at $E4FF pulls below the entry stack (return-address trick) */
/* not lifted: $38E71E: PLP at $E726 pulls below the entry stack (return-address trick) */
/* not lifted: $38ED1E: PLB at $ED20 pulls below the entry stack (return-address trick) */
/* not lifted: $38EE0F: PLP at $EE11 pulls below the entry stack (return-address trick) */
/* not lifted: $38EFEE: COP at $38:F011 */
/* not lifted: $38F01E: PLD at $1DD0 pulls below the entry stack (return-address trick) */
/* not lifted: $38F1C0: $38:F1C0 reached with two different M/X/stack states */
/* not lifted: $38F1F0: $38:F1F0 reached with two different M/X/stack states */
/* not lifted: $38F1F4: PLP at $F1A1 pulls below the entry stack (return-address trick) */
/* not lifted: $38F312: TXS at $38:F2BC */
/* not lifted: $38F32F: TXS at $38:F2BC */
/* not lifted: $38F331: BRK at $38:F333 */
/* not lifted: $38F400: COP at $38:A29A */
/* not lifted: $38FC15: COP at $38:FC22 */
/* not lifted: $38FD00: COP at $38:FD0B */
/* not lifted: $38FE3F: PLB at $FE40 pulls below the entry stack (return-address trick) */
/* not lifted: $38FEC5: COP at $38:FECB */
/* not lifted: $38FF3A: PLB at $FF6D pulls below the entry stack (return-address trick) */
/* not lifted: $38FF4F: PLB at $FF6D pulls below the entry stack (return-address trick) */
/* not lifted: $38FFF8: PLB at $FFFB pulls below the entry stack (return-address trick) */
/* not lifted: $38FFFC: BRK at $38:0004 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $38A42D, entered with P=$00 via JSR */
void gen_38A42D(void) {
    goto L_A42D;
L_A42D:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dpxi(0xA0)));  /* A42D CMP */
    recomp_tick(14); return;  /* A42F RTI */
}

/* $38BBB0, entered with P=$30 via JSR */
void gen_38BBB0(void) {
    goto L_BBB0;
L_BBB0:;
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_absx(0xE0B4))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BBB0 EOR */
    recomp_tick(40); { uint32_t _e = g_abs(0x11EE); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BBB3 INC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpiy(0x0F)))));  /* BBB6 SBC */
    recomp_tick(14); return;  /* BBB8 RTS */
}

/* $38DFC0, entered with P=$30 via JSR */
void gen_38DFC0(void) {
    goto L_DFC0;
L_DFC0:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0xB0)));  /* DFC0 CPX */
    recomp_tick(14); return;  /* DFC2 RTI */
}

void gen_register_bank_38(void) {
    func_table_register_flags(0x38A42D, gen_38A42D, false);
    func_table_register_flags(0x38BBB0, gen_38BBB0, false);
    func_table_register_flags(0x38DFC0, gen_38DFC0, false);
}
