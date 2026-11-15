/* Bank $0E recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 25 unlifted in Bank $0E */
/* not lifted: $0E82AA: TXS at $0E:82B0 */
/* not lifted: $0E8BAA: TXS at $0E:8BC3 */
/* not lifted: $0EA2AA: XCE at $0E:A327 */
/* not lifted: $0EA2EA: XCE at $0E:A327 */
/* not lifted: $0EA8A8: PLX at $A8C5 pulls below the entry stack (return-address trick) */
/* not lifted: $0EA8AA: PLX at $A8C5 pulls below the entry stack (return-address trick) */
/* not lifted: $0EAA2A: PLX at $AA31 pulls below the entry stack (return-address trick) */
/* not lifted: $0EAA2B: PLX at $AA8F pulls below the entry stack (return-address trick) */
/* not lifted: $0EAA8A: PLX at $AA8F pulls below the entry stack (return-address trick) */
/* not lifted: $0EAAA2: WAI at $0E:AAE2 */
/* not lifted: $0EAAAA: WAI at $0E:AAE2 */
/* not lifted: $0EAAAB: WAI at $0E:AAE2 */
/* not lifted: $0EAABA: WAI at $0E:AAE2 */
/* not lifted: $0EAAE9: XCE at $0E:AB0C */
/* not lifted: $0EAAEA: XCE at $0E:AB0C */
/* not lifted: $0EAEAA: STP at $0E:AECA */
/* not lifted: $0EB166: BRK at $0E:B183 */
/* not lifted: $0EBA88: XCE at $0E:BAC5 */
/* not lifted: $0EBA8B: XCE at $0E:BAC5 */
/* not lifted: $0EE2AA: PLB at $E2D0 pulls below the entry stack (return-address trick) */
/* not lifted: $0EE8EA: PLA at $E904 pulls below the entry stack (return-address trick) */
/* not lifted: $0EEAAA: PLP at $EABD pulls below the entry stack (return-address trick) */
/* not lifted: $0EEF75: PLB at $EF93 pulls below the entry stack (return-address trick) */
/* not lifted: $0EF077: PLD at $F0E0 pulls below the entry stack (return-address trick) */
/* not lifted: $0EFF0C: PLP at $FF7F pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $0EABAA, entered with P=$20 via JSR */
void gen_0EABAA(void) {
    goto L_ABAA;
L_ABAA:;
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_longx(0x6D1807u))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABAA EOR */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpxi(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABAE LDA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_absx(0xB7A4))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* ABB0 EOR */
    recomp_tick(14); return;  /* ABB3 RTS */
}

void gen_register_bank_0E(void) {
    func_table_register_flags(0x0EABAA, gen_0EABAA, false);
}
