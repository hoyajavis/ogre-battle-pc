/* Bank $2D recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 67 unlifted in Bank $2D */
/* not lifted: $2D828A: BRK at $2D:829D */
/* not lifted: $2D85EE: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2D8607: BRK at $2D:8607 */
/* not lifted: $2D8A11: BRK at $2D:8A3C */
/* not lifted: $2D8A8A: tail jump at $8AB3 with 2 bytes pushed */
/* not lifted: $2D8AAA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2D9AC0: BRK at $2D:9AC0 */
/* not lifted: $2D9AF1: BRK at $2D:9AF5 */
/* not lifted: $2D9CDC: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2DA01D: tail jump at $A053 with 2 bytes pushed */
/* not lifted: $2DA228: XCE at $2D:A23A */
/* not lifted: $2DA2AA: BRK at $2D:A2FA */
/* not lifted: $2DA2DF: BRK at $2D:A2FA */
/* not lifted: $2DA611: TCS at $A61E with an unknown stack value */
/* not lifted: $2DA88B: BRK at $2D:A88E */
/* not lifted: $2DA8A8: BRK at $2D:A8B4 */
/* not lifted: $2DA8AA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2DA9EA: PLP at $AA2B without a matching PHP */
/* not lifted: $2DAA13: PLP at $AA2B pulls below the entry stack (return-address trick) */
/* not lifted: $2DAA28: PLP at $AA2B pulls below the entry stack (return-address trick) */
/* not lifted: $2DAA2A: PLY at $AA2E pulls below the entry stack (return-address trick) */
/* not lifted: $2DAA82: PLA at $AAA8 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAA88: PLA at $AAA8 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAA8A: PLA at $AAA8 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAA8B: PLA at $AAA8 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAAA2: PLA at $AAA8 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAAA8: PLA at $AAA8 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAAAA: COP at $2D:AAB5 */
/* not lifted: $2DAAAB: COP at $2D:AAB5 */
/* not lifted: $2DAAAC: COP at $2D:AAB5 */
/* not lifted: $2DAABA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2DAABE: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2DAACC: PLP at $AACE pulls below the entry stack (return-address trick) */
/* not lifted: $2DAAE2: BRK at $2D:AAF5 */
/* not lifted: $2DAAE8: BRK at $2D:AAF5 */
/* not lifted: $2DAAEA: BRK at $2D:AAF5 */
/* not lifted: $2DABAA: PLA at $ABB9 pulls below the entry stack (return-address trick) */
/* not lifted: $2DAE2A: calls RAM trampoline/sub-8000 ($2D694C): executes native on LakeSnes */
/* not lifted: $2DAEAA: tail jump at $AF2D with 5 bytes pushed */
/* not lifted: $2DB020: BRK at $2D:B022 */
/* not lifted: $2DB0F1: PLX at $B0F5 pulls below the entry stack (return-address trick) */
/* not lifted: $2DBAAA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2DBECB: BRK at $2D:BEF0 */
/* not lifted: $2DCB0F: tail jump at $CB51 with 2 bytes pushed */
/* not lifted: $2DCCED: tail jump at $CD24 with 2 bytes pushed */
/* not lifted: $2DD1C3: PLA at $D1EB pulls below the entry stack (return-address trick) */
/* not lifted: $2DD4DA: BRK at $2D:D4EB */
/* not lifted: $2DD594: RTS at $D59E with 2 bytes still pushed */
/* not lifted: $2DDA8A: TXS at $2D:DA9C */
/* not lifted: $2DDB10: COP at $2D:DB19 */
/* not lifted: $2DDF20: BRK at $2D:DF23 */
/* not lifted: $2DDFE3: BRK at $2D:DFE3 */
/* not lifted: $2DE3D2: STP at $2D:E40E */
/* not lifted: $2DE8AA: COP at $2D:E8AF */
/* not lifted: $2DEAAA: BRK at $2D:EAD1 */
/* not lifted: $2DEE00: BRK at $2D:EE0A */
/* not lifted: $2DEEEF: PLA at $EF13 pulls below the entry stack (return-address trick) */
/* not lifted: $2DF01F: PLX at $F021 pulls below the entry stack (return-address trick) */
/* not lifted: $2DF0B0: PLA at $ACE2 pulls below the entry stack (return-address trick) */
/* not lifted: $2DF0DE: PLD at $F0EA pulls below the entry stack (return-address trick) */
/* not lifted: $2DF44F: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2DFB01: PLD at $FB0F pulls below the entry stack (return-address trick) */
/* not lifted: $2DFF11: tail jump at $FF39 with 3 bytes pushed */
/* not lifted: $2DFF3F: COP at $2D:FF52 */
/* not lifted: $2DFF7A: BRK at $2D:FF7E */
/* not lifted: $2DFFED: BRK at $2D:0019 */
/* not lifted: $2DFFEF: BRK at $2D:0019 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2DA000, entered with P=$30 via JSR */
void gen_2DA000(void) {
    goto L_A000;
L_A000:;
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)))));  /* A000 ADC */
    recomp_tick(14); return;  /* A002 RTI */
}

/* $2DA010, entered with P=$30 via JSR */
void gen_2DA010(void) {
    goto L_A010;
L_A010:;
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(0x10046Du))));  /* A010 ADC */
    recomp_tick(14); return;  /* A014 RTI */
}

/* $2DA012, entered with P=$30 via JSR */
void gen_2DA012(void) {
    goto L_A012;
L_A012:;
    recomp_tick(32); { uint32_t _e = g_dp(0x10); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v | (uint8_t)g_cpu.C)); }  /* A012 TSB */
    recomp_tick(14); return;  /* A014 RTI */
}

void gen_register_bank_2D(void) {
    func_table_register_flags(0x2DA000, gen_2DA000, false);
    func_table_register_flags(0x2DA010, gen_2DA010, false);
    func_table_register_flags(0x2DA012, gen_2DA012, false);
}
