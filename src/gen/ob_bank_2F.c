/* Bank $2F recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 6 unlifted in Bank $2F */
/* not lifted: $2F8AB4: tail jump at $8AF7 with 2 bytes pushed */
/* not lifted: $2F8BAA: BRK at $2F:8BD6 */
/* not lifted: $2FAAAA: XCE at $2F:AABE */
/* not lifted: $2FAB2A: PLP at $AB2F pulls below the entry stack (return-address trick) */
/* not lifted: $2FDA2F: calls RAM trampoline/sub-8000 ($555917): executes native on LakeSnes */
/* not lifted: $2FEF41: PLB at $EF67 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2F8431, entered with P=$00 via JSL */
void gen_2F8431(void) {
    goto L_8431;
L_8431:;
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xE340);  /* 8431 CPX */
    recomp_tick(14); return;  /* 8434 RTI */
}

void gen_register_bank_2F(void) {
    func_table_register_flags(0x2F8431, gen_2F8431, true);
}
