/* Bank $29 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 11 unlifted in Bank $29 */
/* not lifted: $29925C: BRK at $29:9260 */
/* not lifted: $299277: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2992BA: XCE at $29:92BA */
/* not lifted: $29933C: BRK at $29:933E */
/* not lifted: $299B4F: TCS at $9B4F with an unknown stack value */
/* not lifted: $29A2AA: BRK at $29:A2BB */
/* not lifted: $29AAC0: COP at $29:AACA */
/* not lifted: $29AAC7: XCE at $29:AB0E */
/* not lifted: $29AAD8: XCE at $29:AB0E */
/* not lifted: $29AB21: STP at $29:AB2B */
/* not lifted: $29AB36: PLP at $AB6A pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2992F7, entered with P=$30 via JSR */
void gen_2992F7(void) {
    goto L_92F7;
L_92F7:;
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0x3B)))));  /* 92F7 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sr(0xBF)))));  /* 92F9 SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpil(0xFE)))));  /* 92FB SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpil(0xFF)))));  /* 92FD SBC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0xEA)))));  /* 92FF SBC */
    recomp_tick(32); { uint32_t _e = g_dp(0xF6); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9301 DEC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0xE7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9303 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpil(0xC7))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9305 AND */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x07C307u)))));  /* 9307 SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0x83)));  /* 930B CMP */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_sr(0xE3)));  /* 930D CMP */
    recomp_tick(16); g_rep(0xFF);  /* 930F REP */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpil(0xE2))));  /* 9311 SBC */
    recomp_tick(48); g_cmp16(g_cpu.C, g_rd16(0x40B0E6u));  /* 9313 CMP */
    recomp_tick(40); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_abs(0xFF60)));  /* 9317 CPY */
    recomp_tick(56); { uint32_t _e = g_absx(0x7FFC); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* 931A ROR */
    recomp_tick(56); { uint32_t _e = g_absx(0x7EFF); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 931D INC */
    recomp_tick(56); { uint32_t _e = g_absx(0xFD7F); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 9320 ROL */
    recomp_tick(56); { uint32_t _e = g_absx(0xC300); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* 9323 ROL */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0xF000);  /* 9326 CPY */
    recomp_tick(14); return;  /* 9329 RTI */
}

/* $29E9A9, entered with P=$10 via JSR */
void gen_29E9A9(void) {
    goto L_E9A9;
L_E9A9:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.Y, g_rd8(g_dp(0x80)));  /* E9A9 CPY */
    recomp_tick(14); return;  /* E9AB RTI */
}

void gen_register_bank_29(void) {
    func_table_register_flags(0x2992F7, gen_2992F7, false);
    func_table_register_flags(0x29E9A9, gen_29E9A9, false);
}
