/* Bank $3C recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 57 unlifted in Bank $3C */
/* not lifted: $3C80C2: Sound driver / Tarot scene routine: executes native on LakeSnes */
/* not lifted: $3C882A: BRK at $3C:882A */
/* not lifted: $3C8A10: RTS at $8A1A with 4 bytes still pushed */
/* not lifted: $3C8A32: BRK at $3C:8A3A */
/* not lifted: $3C8A8A: calls unlifted target 0x149560: executes native on LakeSnes */
/* not lifted: $3C8AF0: PLA at $8AED pulls below the entry stack (return-address trick) */
/* not lifted: $3C8B08: calls RAM trampoline/sub-8000 ($D405E4): executes native on LakeSnes */
/* not lifted: $3C8E8A: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $3C9A00: PLX at $9A02 pulls below the entry stack (return-address trick) */
/* not lifted: $3C9CFF: BRK at $3C:9CE8 */
/* not lifted: $3C9DCA: PLX at $9DCF pulls below the entry stack (return-address trick) */
/* not lifted: $3CA2AA: BRK at $3C:A2B2 */
/* not lifted: $3CA8AA: BRK at $3C:A8B5 */
/* not lifted: $3CAA8A: BRK at $3C:AA8A */
/* not lifted: $3CAA8B: BRK at $3C:AA91 */
/* not lifted: $3CAAA8: BRK at $3C:AAB0 */
/* not lifted: $3CAAAA: PLP at $AAAA pulls below the entry stack (return-address trick) */
/* not lifted: $3CAAAC: BRK at $3C:AAB0 */
/* not lifted: $3CAABE: PLY at $AAC1 pulls below the entry stack (return-address trick) */
/* not lifted: $3CAB4B: PLX at $AB60 pulls below the entry stack (return-address trick) */
/* not lifted: $3CABD7: BRK at $3C:AC24 */
/* not lifted: $3CADEC: XCE at $3C:ADFF */
/* not lifted: $3CAEAA: COP at $3C:AEAE */
/* not lifted: $3CB01C: COP at $3C:B074 */
/* not lifted: $3CC409: BRK at $3C:C432 */
/* not lifted: $3CCA7A: PLY at $CA8E pulls below the entry stack (return-address trick) */
/* not lifted: $3CD0ED: PLY at $D0F4 pulls below the entry stack (return-address trick) */
/* not lifted: $3CDD7A: BRK at $3C:DD8D */
/* not lifted: $3CDDFE: WAI at $3C:DE0C */
/* not lifted: $3CDE09: BRK at $3C:DE0F */
/* not lifted: $3CDFED: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $3CDFFE: calls unlifted target 0x3CF0FE: executes native on LakeSnes */
/* not lifted: $3CDFFF: calls unlifted target 0x3CF0FE: executes native on LakeSnes */
/* not lifted: $3CE098: WAI at $3C:E0C3 */
/* not lifted: $3CE0B8: WAI at $3C:E0C3 */
/* not lifted: $3CE116: BRK at $3C:E13C */
/* not lifted: $3CE1C2: PLY at $E1D4 pulls below the entry stack (return-address trick) */
/* not lifted: $3CE2D0: COP at $3C:E2F1 */
/* not lifted: $3CE3DC: COP at $3C:E3E6 */
/* not lifted: $3CEAAA: PLD at $14CA pulls below the entry stack (return-address trick) */
/* not lifted: $3CEAAE: PLD at $14CA pulls below the entry stack (return-address trick) */
/* not lifted: $3CEC1E: STP at $3C:EC25 */
/* not lifted: $3CECDD: BRK at $3C:ED06 */
/* not lifted: $3CECE1: BRK at $3C:ED06 */
/* not lifted: $3CECEE: BRK at $3C:ED06 */
/* not lifted: $3CECFE: BRK at $3C:ED06 */
/* not lifted: $3CEECC: PLB at $EEE5 pulls below the entry stack (return-address trick) */
/* not lifted: $3CEF1F: calls unlifted target 0x10C02F: executes native on LakeSnes */
/* not lifted: $3CEFEF: PLD at $F00A pulls below the entry stack (return-address trick) */
/* not lifted: $3CF0FE: COP at $3C:F107 */
/* not lifted: $3CF1FD: TXS at $3C:F21B */
/* not lifted: $3CF3EE: PLY at $F464 pulls below the entry stack (return-address trick) */
/* not lifted: $3CF509: COP at $3C:F520 */
/* not lifted: $3CF5FD: COP at $3C:F62E */
/* not lifted: $3CFECE: PLB at $FED4 pulls below the entry stack (return-address trick) */
/* not lifted: $3CFEFF: PLB at $FF15 pulls below the entry stack (return-address trick) */
/* not lifted: $3CFF7A: RTL at $0022 with 2 bytes still pushed */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $3C88AA, entered with P=$00 via JSR */
void gen_3C88AA(void) {
    goto L_88AA;
L_88AA:;
    recomp_tick(14); return;  /* 88AA RTS */
}

/* $3CBA00, entered with P=$00 via JSR */
void gen_3CBA00(void) {
    goto L_BA00;
L_BA00:;
    recomp_tick(16); g_sep(0x0A);  /* BA00 SEP */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x63))));  /* BA02 SBC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_dpi(0x21))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA04 AND */
    recomp_tick(56); { uint32_t _e = g_absx(0x9AFF); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* BA06 INC */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absx(0x04EE)));  /* BA09 CMP */
    recomp_tick(14); return;  /* BA0C RTS */
}

/* $3CBA01, entered with P=$20 via JSR */
void gen_3CBA01(void) {
    goto L_BA01;
L_BA01:;
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* BA01 ASL */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x63)))));  /* BA02 SBC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpi(0x21))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BA04 AND */
    recomp_tick(40); { uint32_t _e = g_absx(0x9AFF); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* BA06 INC */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_absx(0x04EE)));  /* BA09 CMP */
    recomp_tick(14); return;  /* BA0C RTS */
}

void gen_register_bank_3C(void) {
    func_table_register_flags(0x3C88AA, gen_3C88AA, false);
    func_table_register_flags(0x3CBA00, gen_3CBA00, false);
    func_table_register_flags(0x3CBA01, gen_3CBA01, false);
}
