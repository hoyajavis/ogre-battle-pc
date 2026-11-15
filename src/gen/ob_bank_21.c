/* Bank $21 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 33 unlifted in Bank $21 */
/* not lifted: $218092: BRK at $21:8099 */
/* not lifted: $218093: BRK at $21:8099 */
/* not lifted: $218651: PLY at $8655 pulls below the entry stack (return-address trick) */
/* not lifted: $2186C0: XCE at $21:86E6 */
/* not lifted: $218908: COP at $21:8908 */
/* not lifted: $218A23: COP at $21:8A3C */
/* not lifted: $219110: BRK at $21:9118 */
/* not lifted: $219200: BRK at $21:924F */
/* not lifted: $219210: BRK at $21:924B */
/* not lifted: $21A0BD: BRK at $21:A0D0 */
/* not lifted: $21B800: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $21C092: BRK at $21:C099 */
/* not lifted: $21C093: BRK at $21:C0A0 */
/* not lifted: $21C918: PLA at $C91B pulls below the entry stack (return-address trick) */
/* not lifted: $21C93C: BRK at $21:C948 */
/* not lifted: $21C958: BRK at $21:C964 */
/* not lifted: $21C976: BRK at $21:C98E */
/* not lifted: $21C99F: BRK at $21:C9A9 */
/* not lifted: $21C9C5: COP at $21:C9CC */
/* not lifted: $21C9EB: COP at $21:C9F8 */
/* not lifted: $21C9F6: BRK at $21:C9FF */
/* not lifted: $21CA03: PLA at $CA07 pulls below the entry stack (return-address trick) */
/* not lifted: $21CA19: COP at $21:CA25 */
/* not lifted: $21D041: calls RAM trampoline/sub-8000 ($535051): executes native on LakeSnes */
/* not lifted: $21D946: WAI at $21:D946 */
/* not lifted: $21E0EC: COP at $21:E0F8 */
/* not lifted: $21EA00: COP at $21:EA08 */
/* not lifted: $21F000: PLP at $F00E pulls below the entry stack (return-address trick) */
/* not lifted: $21F3EE: PLB at $F48B pulls below the entry stack (return-address trick) */
/* not lifted: $21F800: BRK at $21:F811 */
/* not lifted: $21F808: BRK at $21:F811 */
/* not lifted: $21FC00: XCE at $21:FC1B */
/* not lifted: $21FFFF: BRK at $21:000D */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $219861, entered with P=$30 via JSR */
void gen_219861(void) {
    goto L_9861;
L_9861:;
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xED30FCu)))));  /* 9861 ADC */
    recomp_tick(14); return;  /* 9865 RTS */
}

/* $21A089, entered with P=$30 via JSR */
void gen_21A089(void) {
    goto L_A089;
L_A089:;
    recomp_tick(24); g_wr8(g_dpy(0x89), (uint8_t)g_cpu.X);  /* A089 STX */
    recomp_tick(40); g_wr8(0x811F89u, (uint8_t)(uint8_t)g_cpu.C);  /* A08B STA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpxi(0xFD))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A08F ORA */
    recomp_tick(14); return;  /* A091 RTI */
}

void gen_register_bank_21(void) {
    func_table_register_flags(0x219861, gen_219861, false);
    func_table_register_flags(0x21A089, gen_21A089, false);
}
