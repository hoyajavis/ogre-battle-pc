/* Bank $1E recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 36 unlifted in Bank $1E */
/* not lifted: $1E8060: BRK at $1E:8090 */
/* not lifted: $1E840D: COP at $1E:841A */
/* not lifted: $1E8FFF: BRK at $1E:900B */
/* not lifted: $1EA5FF: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1EAA15: BRK at $1E:AA1D */
/* not lifted: $1EC00E: BRK at $1E:C07B */
/* not lifted: $1EC041: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1EC1DF: COP at $1E:C1EF */
/* not lifted: $1EC314: BRK at $1E:C323 */
/* not lifted: $1EC60F: COP at $1E:C61D */
/* not lifted: $1EC835: BRK at $1E:C905 */
/* not lifted: $1ECA05: BRK at $1E:CA18 */
/* not lifted: $1ECCC0: tail jump at $CC85 with 4 bytes pushed */
/* not lifted: $1ECF31: BRK at $1E:CF5C */
/* not lifted: $1ECFFF: tail jump at $D018 with 1 bytes pushed */
/* not lifted: $1ED181: BRK at $1E:D191 */
/* not lifted: $1ED61B: BRK at $1E:D63F */
/* not lifted: $1ED809: STP at $1E:D827 */
/* not lifted: $1EE3FF: PLP at $E411 pulls below the entry stack (return-address trick) */
/* not lifted: $1EE6C3: BRK at $1E:E6D9 */
/* not lifted: $1EE7F8: BRK at $1E:E80D */
/* not lifted: $1EF608: BRK at $1E:F60E */
/* not lifted: $1EF707: BRK at $1E:F70A */
/* not lifted: $1EF8DF: TXS at $1E:F929 */
/* not lifted: $1EF9FE: COP at $1E:F9FE */
/* not lifted: $1EFB04: PLX at $FB0F pulls below the entry stack (return-address trick) */
/* not lifted: $1EFC1F: PLP at $FC32 pulls below the entry stack (return-address trick) */
/* not lifted: $1EFC8F: STP at $1E:FCBA */
/* not lifted: $1EFE32: XCE at $1E:FE44 */
/* not lifted: $1EFF03: BRK at $1E:FF2E */
/* not lifted: $1EFF06: BRK at $1E:FF2E */
/* not lifted: $1EFF20: BRK at $1E:FF2E */
/* not lifted: $1EFF40: BRK at $1E:FF76 */
/* not lifted: $1EFFA0: BRK at $1E:FFB3 */
/* not lifted: $1EFFDD: BRK at $1E:FFE3 */
/* not lifted: $1EFFFC: XCE at $1E:000E */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $1EE178, entered with P=$30 via JSR */
void gen_1EE178(void) {
    goto L_E178;
L_E178:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sriy(0x00))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E178 AND */
    recomp_tick(14); return;  /* E17A RTS */
}

/* $1EFE20, entered with P=$30 via JSR */
void gen_1EFE20(void) {
    goto L_FE20;
L_FE20:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0x41); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FE20 EOR */
    recomp_tick(14); return;  /* FE22 RTS */
}

/* $1EFF66, entered with P=$30 via JSR */
void gen_1EFF66(void) {
    goto L_FF66;
L_FF66:;
    recomp_tick(32); { uint32_t _e = g_dp(0xFF); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* FF66 INC */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x18); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FF68 AND */
    recomp_tick(40); { uint32_t _e = g_absx(0x7DF8); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* FF6A ROL */
    recomp_tick(14); return;  /* FF6D RTS */
}

void gen_register_bank_1E(void) {
    func_table_register_flags(0x1EE178, gen_1EE178, false);
    func_table_register_flags(0x1EFE20, gen_1EFE20, false);
    func_table_register_flags(0x1EFF66, gen_1EFF66, false);
}
