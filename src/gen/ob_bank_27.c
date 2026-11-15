/* Bank $27 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 28 unlifted in Bank $27 */
/* not lifted: $278177: RTS at $8193 with 3 bytes still pushed */
/* not lifted: $27818D: RTS at $8193 with 1 bytes still pushed */
/* not lifted: $2781C0: XCE at $27:81C4 */
/* not lifted: $27820A: COP at $27:B81C */
/* not lifted: $27824D: BRK at $27:824F */
/* not lifted: $278343: BRK at $27:834C */
/* not lifted: $278400: BRK at $27:8401 */
/* not lifted: $279920: TXS at $27:9927 */
/* not lifted: $27A518: XCE at $27:A549 */
/* not lifted: $27A7A5: PLX at $A7A7 pulls below the entry stack (return-address trick) */
/* not lifted: $27A943: XCE at $27:A96E */
/* not lifted: $27AD0B: WAI at $27:ACD8 */
/* not lifted: $27C502: PLA at $C50C pulls below the entry stack (return-address trick) */
/* not lifted: $27DCD3: XCE at $27:DCD7 */
/* not lifted: $27E07E: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $27E18C: COP at $27:E191 */
/* not lifted: $27E24B: calls RAM trampoline/sub-8000 ($691CFF): executes native on LakeSnes */
/* not lifted: $27E284: BRK at $27:E303 */
/* not lifted: $27E290: BRK at $27:E303 */
/* not lifted: $27E2A9: BRK at $27:E2CD */
/* not lifted: $27E558: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $27E56A: $27:E571 reached with two different M/X/stack states */
/* not lifted: $27E57E: $27:E57E reached with two different M/X/stack states */
/* not lifted: $27E59A: BRK at $27:E5B7 */
/* not lifted: $27E62C: BRK at $27:E632 */
/* not lifted: $27E633: BRK at $27:E63E */
/* not lifted: $27F800: COP at $27:F81D */
/* not lifted: $27FE07: indirect jump table dispatch: executes native on LakeSnes */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $27E511, entered with P=$00 via JSR */
void gen_27E511(void) {
    goto L_E511;
L_E511:;
    recomp_tick(14); return;  /* E511 RTS */
}

void gen_register_bank_27(void) {
    func_table_register_flags(0x27E511, gen_27E511, false);
}
