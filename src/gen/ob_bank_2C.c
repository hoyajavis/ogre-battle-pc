/* Bank $2C recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 15 unlifted in Bank $2C */
/* not lifted: $2C832E: COP at $2C:833B */
/* not lifted: $2C8479: COP at $2C:8487 */
/* not lifted: $2CC915: STP at $2C:C915 */
/* not lifted: $2CCC6D: calls RAM trampoline/sub-8000 ($2C6967): executes native on LakeSnes */
/* not lifted: $2CCD07: BRK at $2C:F722 */
/* not lifted: $2CCF79: calls RAM trampoline/sub-8000 ($2C6154): executes native on LakeSnes */
/* not lifted: $2CD375: RTL at $D382 with 2 bytes still pushed */
/* not lifted: $2CD800: BRK at $2C:D892 */
/* not lifted: $2CDC00: BRK at $2C:DC18 */
/* not lifted: $2CDEB3: BRK at $2C:DED7 */
/* not lifted: $2CDF15: COP at $2C:DF29 */
/* not lifted: $2CE732: TXS at $2C:E768 */
/* not lifted: $2CFA36: tail jump at $FA74 with 3 bytes pushed */
/* not lifted: $2CFF73: PLP at $FF73 pulls below the entry stack (return-address trick) */
/* not lifted: $2CFF74: BRK at $2C:FF9E */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2CAA01, entered with P=$10 via JSR */
void gen_2CAA01(void) {
    goto L_AA01;
L_AA01:;
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C | 0x665E); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* AA01 ORA */
    recomp_tick(14); return;  /* AA04 RTS */
}

/* $2CF907, entered with P=$10 via JSL */
void gen_2CF907(void) {
    goto L_F907;
L_F907:;
    recomp_tick(14); return;  /* F907 RTL */
}

void gen_register_bank_2C(void) {
    func_table_register_flags(0x2CAA01, gen_2CAA01, false);
    func_table_register_flags(0x2CF907, gen_2CF907, true);
}
