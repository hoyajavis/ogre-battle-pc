/* Bank $1D recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 4 lifted, 36 unlifted in Bank $1D */
/* not lifted: $1D802D: BRK at $1D:8036 */
/* not lifted: $1D8055: BRK at $1D:9D0B */
/* not lifted: $1D9642: calls RAM trampoline/sub-8000 ($1D2DCD): executes native on LakeSnes */
/* not lifted: $1DA0A2: BRK at $1D:A0A2 */
/* not lifted: $1DA108: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1DA609: calls unlifted target 0xFFAB07: executes native on LakeSnes */
/* not lifted: $1DA9A0: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1DB327: WAI at $1D:B36F */
/* not lifted: $1DB7FF: PLA at $B758 pulls below the entry stack (return-address trick) */
/* not lifted: $1DBB63: tail jump at $BB75 with 2 bytes pushed */
/* not lifted: $1DBF43: BRK at $1D:BF5F */
/* not lifted: $1DC227: COP at $1D:C22B */
/* not lifted: $1DCC05: TCS at $CC0B with an unknown stack value */
/* not lifted: $1DD901: STP at $1D:D938 */
/* not lifted: $1DE00E: COP at $1D:E01E */
/* not lifted: $1DE0F0: COP at $1D:E0F3 */
/* not lifted: $1DE539: COP at $1D:E551 */
/* not lifted: $1DE82F: BRK at $1D:E88C */
/* not lifted: $1DE863: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1DF30F: COP at $1D:F32F */
/* not lifted: $1DF837: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1DF880: XCE at $1D:F880 */
/* not lifted: $1DFB06: TCS at $FB50 with an unknown stack value */
/* not lifted: $1DFB72: COP at $1D:FBF8 */
/* not lifted: $1DFCDD: BRK at $1D:FCDD */
/* not lifted: $1DFD69: WAI at $1D:FD8A */
/* not lifted: $1DFE37: BRK at $1D:FE37 */
/* not lifted: $1DFE57: STP at $1D:4C85 */
/* not lifted: $1DFE69: TCS at $FF52 with an unknown stack value */
/* not lifted: $1DFF34: COP at $1D:FF3E */
/* not lifted: $1DFF35: COP at $1D:FF37 */
/* not lifted: $1DFF42: COP at $1D:FF49 */
/* not lifted: $1DFF4B: TCS at $FF52 with an unknown stack value */
/* not lifted: $1DFF61: BRK at $1D:FF82 */
/* not lifted: $1DFF6F: BRK at $1D:FF82 */
/* not lifted: $1DFF74: WAI at $1D:FF78 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $1DA017, entered with P=$00 via JSR */
void gen_1DA017(void) {
    goto L_A017;
L_A017:;
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(0x770FF0u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A017 ORA */
    goto L_A01B;
L_A019:;
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(0x870477u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A019 ORA */
    goto L_A01D;
L_A01B:;
    recomp_tick(48); { uint32_t _e = g_dp(0x87); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* A01B TSB */
L_A01D:;
    recomp_tick(48); { uint32_t _e = g_dp(0x1F); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* A01D ASL */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0xE098)); g_cpu.X = _v; g_nz16(_v); }  /* A01F LDX */
    recomp_tick(56); { uint32_t _e = g_absx(0x9E2F); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* A022 INC */
    recomp_tick(56); { uint32_t _e = g_abs(0x4E18); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* A025 DEC */
    recomp_tick(16); goto L_A029;  /* A028 BRA */
L_A029:;
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x9E1FFEu))));  /* A029 SBC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x6036); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A02D AND */
    recomp_tick(16); goto L_A019;  /* A030 BRA */
}

/* $1DC062, entered with P=$00 via JSR */
void gen_1DC062(void) {
    goto L_C062;
L_C062:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpxi(0xB8))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C062 ORA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(0x2404D4u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C064 ORA */
    recomp_tick(14); return;  /* C068 RTI */
}

/* $1DDDC0, entered with P=$00 via JSL */
void gen_1DDDC0(void) {
    goto L_DDC0;
L_DDC0:;
    recomp_tick(14); return;  /* DDC0 RTI */
}

/* $1DEA07, entered with P=$20 via JSL */
void gen_1DEA07(void) {
    goto L_EA07;
L_EA07:;
    recomp_tick(14); return;  /* EA07 RTS */
}

void gen_register_bank_1D(void) {
    func_table_register_flags(0x1DA017, gen_1DA017, false);
    func_table_register_flags(0x1DC062, gen_1DC062, false);
    func_table_register_flags(0x1DDDC0, gen_1DDDC0, true);
    func_table_register_flags(0x1DEA07, gen_1DEA07, true);
}
