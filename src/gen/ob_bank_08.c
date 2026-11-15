/* Bank $08 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 4 lifted, 72 unlifted in Bank $08 */
/* not lifted: $0882AA: XCE at $08:82AA */
/* not lifted: $088432: BRK at $08:8458 */
/* not lifted: $0888A0: COP at $08:88C2 */
/* not lifted: $08898A: BRK at $08:89AE */
/* not lifted: $088FF7: BRK at $08:9067 */
/* not lifted: $0890FC: COP at $08:3D6E */
/* not lifted: $08A1AA: BRK at $08:A1BE */
/* not lifted: $08A22A: BRK at $08:A252 */
/* not lifted: $08A2AA: COP at $08:A327 */
/* not lifted: $08A43F: BRK at $08:A463 */
/* not lifted: $08A5BE: $08:A5BE reached with two different M/X/stack states */
/* not lifted: $08A834: BRK at $08:A854 */
/* not lifted: $08A921: BRK at $08:A935 */
/* not lifted: $08AA22: STP at $08:AA40 */
/* not lifted: $08AA6A: BRK at $08:AA82 */
/* not lifted: $08AA8A: BRK at $08:AAB8 */
/* not lifted: $08AAAA: BRK at $08:AAB8 */
/* not lifted: $08ABA6: BRK at $08:ABE5 */
/* not lifted: $08AD88: BRK at $08:AD88 */
/* not lifted: $08B00C: COP at $08:B076 */
/* not lifted: $08B01D: COP at $08:B076 */
/* not lifted: $08B020: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $08B0F3: COP at $08:B0F6 */
/* not lifted: $08B40F: BRK at $08:B43B */
/* not lifted: $08B415: BRK at $08:B43B */
/* not lifted: $08B41D: BRK at $08:B43B */
/* not lifted: $08BF3F: WAI at $08:BF6D */
/* not lifted: $08C01F: COP at $08:C07C */
/* not lifted: $08C020: COP at $08:C07C */
/* not lifted: $08C03F: COP at $08:C07C */
/* not lifted: $08C0D1: PLD at $C0EA pulls below the entry stack (return-address trick) */
/* not lifted: $08C0E1: PLD at $C0EA pulls below the entry stack (return-address trick) */
/* not lifted: $08C5F3: XCE at $08:C646 */
/* not lifted: $08CBED: RTI at $CC0F with 2 bytes still pushed */
/* not lifted: $08CBFF: BRK at $08:8458 */
/* not lifted: $08CCDF: tail jump at $CD38 with 1 bytes pushed */
/* not lifted: $08CEB0: COP at $08:CEFA */
/* not lifted: $08D0B3: BRK at $08:D0FF */
/* not lifted: $08D202: WAI at $08:D211 */
/* not lifted: $08D3A0: BRK at $08:D3D5 */
/* not lifted: $08D51E: COP at $08:D526 */
/* not lifted: $08D5B0: XCE at $08:D5B0 */
/* not lifted: $08DBF2: COP at $08:DC38 */
/* not lifted: $08DF09: COP at $08:DED3 */
/* not lifted: $08E0F1: BRK at $08:CD57 */
/* not lifted: $08E20E: BRK at $08:E216 */
/* not lifted: $08E2CE: TXS at $08:E2CF */
/* not lifted: $08E464: PLP at $E469 pulls below the entry stack (return-address trick) */
/* not lifted: $08E4F4: COP at $08:8E3A */
/* not lifted: $08E4FC: PLP at $E4FF pulls below the entry stack (return-address trick) */
/* not lifted: $08E71E: PLP at $E726 pulls below the entry stack (return-address trick) */
/* not lifted: $08ED1E: PLB at $ED20 pulls below the entry stack (return-address trick) */
/* not lifted: $08EE0F: PLP at $EE11 pulls below the entry stack (return-address trick) */
/* not lifted: $08EFEE: COP at $08:F011 */
/* not lifted: $08F01E: PLD at $1DD0 pulls below the entry stack (return-address trick) */
/* not lifted: $08F1C0: $08:F1C0 reached with two different M/X/stack states */
/* not lifted: $08F1F0: $08:F1F0 reached with two different M/X/stack states */
/* not lifted: $08F1F4: PLP at $F1A1 pulls below the entry stack (return-address trick) */
/* not lifted: $08F2EB: PLD at $9DD0 pulls below the entry stack (return-address trick) */
/* not lifted: $08F312: TXS at $08:F2BC */
/* not lifted: $08F32F: TXS at $08:F2BC */
/* not lifted: $08F331: BRK at $08:F333 */
/* not lifted: $08F400: COP at $08:A29A */
/* not lifted: $08FC15: COP at $08:FC22 */
/* not lifted: $08FCFF: COP at $08:FD0B */
/* not lifted: $08FD00: COP at $08:FD0B */
/* not lifted: $08FEC5: COP at $08:FECB */
/* not lifted: $08FF3A: PLB at $FF6D pulls below the entry stack (return-address trick) */
/* not lifted: $08FF4F: PLB at $FF6D pulls below the entry stack (return-address trick) */
/* not lifted: $08FFDF: PLB at $FFFB pulls below the entry stack (return-address trick) */
/* not lifted: $08FFF8: PLB at $FFFB pulls below the entry stack (return-address trick) */
/* not lifted: $08FFFC: BRK at $08:0004 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $08A42D, entered with P=$00 via JSR */
void gen_08A42D(void) {
    goto L_A42D;
L_A42D:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dpxi(0xA0)));  /* A42D CMP */
    recomp_tick(14); return;  /* A42F RTI */
}

/* $08BBB0, entered with P=$30 via JSR */
void gen_08BBB0(void) {
    goto L_BBB0;
L_BBB0:;
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_absx(0xE0B4))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BBB0 EOR */
    recomp_tick(40); { uint32_t _e = g_abs(0x11EE); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BBB3 INC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpiy(0x0F)))));  /* BBB6 SBC */
    recomp_tick(14); return;  /* BBB8 RTS */
}

/* $08DFC0, entered with P=$30 via JSR */
void gen_08DFC0(void) {
    goto L_DFC0;
L_DFC0:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.X, g_rd8(g_dp(0xB0)));  /* DFC0 CPX */
    recomp_tick(14); return;  /* DFC2 RTI */
}

/* $08E01D, entered with P=$20 via JSR */
void gen_08E01D(void) {
    goto L_E01D;
L_E01D:;
    recomp_tick(40); { uint32_t _e = g_abs(0x02E2); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* E01D TSB */
    recomp_tick(14); return;  /* E020 RTI */
}

void gen_register_bank_08(void) {
    func_table_register_flags(0x08A42D, gen_08A42D, false);
    func_table_register_flags(0x08BBB0, gen_08BBB0, false);
    func_table_register_flags(0x08DFC0, gen_08DFC0, false);
    func_table_register_flags(0x08E01D, gen_08E01D, false);
}
