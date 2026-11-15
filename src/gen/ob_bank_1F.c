/* Bank $1F recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 12 unlifted in Bank $1F */
/* not lifted: $1F91FF: COP at $1F:9205 */
/* not lifted: $1F9202: calls RAM trampoline/sub-8000 ($040E02): executes native on LakeSnes */
/* not lifted: $1F99F0: COP at $1F:99F0 */
/* not lifted: $1FA600: XCE at $1F:A601 */
/* not lifted: $1FB5EF: BRK at $1F:B603 */
/* not lifted: $1FCF00: BRK at $1F:CF04 */
/* not lifted: $1FDCFE: BRK at $1F:EA10 */
/* not lifted: $1FE21A: BRK at $1F:E306 */
/* not lifted: $1FE600: XCE at $1F:E600 */
/* not lifted: $1FE6E0: BRK at $1F:E6E0 */
/* not lifted: $1FF000: BRK at $1F:F000 */
/* not lifted: $1FFFE2: PLY at $FFE4 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $1F84B4, entered with P=$00 via JSR */
void gen_1F84B4(void) {
    goto L_84B4;
L_84B4:;
    recomp_tick(14); return;  /* 84B4 RTS */
}

/* $1FF799, entered with P=$00 via JSR */
void gen_1FF799(void) {
    goto L_F799;
L_F799:;
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.X, g_rd16(g_abs(0x201C)));  /* F799 CPX */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x19FF20u))));  /* F79C SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0xFF00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* F7A0 INC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(0xD6FF89u)));  /* F7A3 SBC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C ^ g_rd16(g_dp(0x3C))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7A7 EOR */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absy(0xD2DA)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7A9 LDA */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C ^ g_rd16(g_dpi(0x21))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7AC EOR */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x5FF738u))));  /* F7AE SBC */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_longx(0x8E4FD2u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7B2 AND */
    recomp_tick(48); { uint32_t _e = g_dpx(0xBF); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* F7B6 ROR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C ^ g_rd16(g_sr(0xB8))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* F7B8 EOR */
    recomp_tick(48); { uint32_t _e = g_dpx(0xC0); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* F7BA ROL */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_abs(0x1C21)));  /* F7BC CPY */
    recomp_tick(14); g_cpu.flag_I = false;  /* F7BF CLI */
    recomp_tick(14); return;  /* F7C0 RTI */
}

void gen_register_bank_1F(void) {
    func_table_register_flags(0x1F84B4, gen_1F84B4, false);
    func_table_register_flags(0x1FF799, gen_1FF799, false);
}
