/* Bank $23 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 14 unlifted in Bank $23 */
/* not lifted: $239083: COP at $23:9099 */
/* not lifted: $23BCD9: PLX at $BCDF pulls below the entry stack (return-address trick) */
/* not lifted: $23BF51: COP at $23:BF59 */
/* not lifted: $23BFB8: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $23BFB9: BRK at $23:BFB9 */
/* not lifted: $23BFBA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $23C1AA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $23C1D5: PLY at $C1D5 pulls below the entry stack (return-address trick) */
/* not lifted: $23C265: tail jump at $809D with 2 bytes pushed */
/* not lifted: $23E21F: XCE at $23:E22F */
/* not lifted: $23E423: BRK at $23:E44B */
/* not lifted: $23E569: TCS at $E57E with an unknown stack value */
/* not lifted: $23E96F: PLX at $E97A pulls below the entry stack (return-address trick) */
/* not lifted: $23E993: COP at $23:E9C7 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $23C194, entered with P=$30 via JSR */
void gen_23C194(void) {
    goto L_C194;
L_C194:;
    recomp_tick(14); return;  /* C194 RTI */
}

/* $23C24F, entered with P=$30 via JSR */
void gen_23C24F(void) {
    goto L_C24F;
L_C24F:;
    recomp_tick(40); { uint32_t _e = g_absx(0x2107); uint8_t _v = g_ror8(g_rd8(_e)); g_wr8(_e, _v); }  /* C24F ROR */
    recomp_tick(32); { uint32_t _e = g_dpx(0x83); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* C252 ASL */
    recomp_tick(40); { uint32_t _e = g_absx(0x16DE); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* C254 ROL */
    recomp_tick(14); return;  /* C257 RTI */
}

void gen_register_bank_23(void) {
    func_table_register_flags(0x23C194, gen_23C194, false);
    func_table_register_flags(0x23C24F, gen_23C24F, false);
}
