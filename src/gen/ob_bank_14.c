/* Bank $14 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 18 unlifted in Bank $14 */
/* not lifted: $14833F: BRK at $14:8343 */
/* not lifted: $14906E: BRK at $14:9070 */
/* not lifted: $14940E: BRK at $14:3E69 */
/* not lifted: $14A040: BRK at $14:A042 */
/* not lifted: $14A0E0: BRK at $14:A0EB */
/* not lifted: $14B0D0: BRK at $14:B114 */
/* not lifted: $14C6C5: COP at $14:C6C5 */
/* not lifted: $14D32E: PLA at $D2DA pulls below the entry stack (return-address trick) */
/* not lifted: $14DE0D: calls RAM trampoline/sub-8000 ($184AFF): executes native on LakeSnes */
/* not lifted: $14DF11: BRK at $14:DF2D */
/* not lifted: $14E00F: TCS at $E013 with an unknown stack value */
/* not lifted: $14E0D7: PLP at $E0D9 pulls below the entry stack (return-address trick) */
/* not lifted: $14F4BB: BRK at $14:F4CB */
/* not lifted: $14F8F7: PLY at $F909 pulls below the entry stack (return-address trick) */
/* not lifted: $14FE07: WAI at $14:FE16 */
/* not lifted: $14FF40: BRK at $14:FF55 */
/* not lifted: $14FF97: TXS at $14:FFAA */
/* not lifted: $14FFEF: BRK at $14:FFF1 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $14800F, entered with P=$00 via JSR */
void gen_14800F(void) {
    goto L_800F;
L_800F:;
    recomp_tick(24); { uint16_t _v = 0xE040; g_cpu.Y = _v; g_nz16(_v); }  /* 800F LDY */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x90F060u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8012 LDA */
    recomp_tick(14); g_cpu.flag_I = true;  /* 8016 SEI */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8017 TAY */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.X, 0xA400);  /* 8018 CPX */
    recomp_tick(14); return;  /* 801B RTI */
}

/* $14A890, entered with P=$00 via JSR */
void gen_14A890(void) {
    goto L_A890;
L_A822:;
    recomp_tick(48); { uint32_t _e = g_dp(0x7C); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* A822 ROR */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x204933u))));  /* A824 SBC */
    recomp_tick(56); { uint32_t _e = g_absx(0x2338); uint16_t _v = g_lsr16(g_rd16(_e)); g_wr16(_e, _v); }  /* A828 LSR */
    recomp_tick(14); return;  /* A82B RTS */
L_A890:;
    recomp_tick(16); goto L_A822;  /* A890 BRA */
}

/* $14B20F, entered with P=$00 via JSR */
void gen_14B20F(void) {
    goto L_B20F;
L_B20F:;
    recomp_tick(32); g_bit16(g_rd16(g_dp(0xFD)), false);  /* B20F BIT */
    recomp_tick(40); g_cmp16(g_cpu.C, g_rd16(g_absx(0x5E19)));  /* B211 CMP */
    recomp_tick(48); { uint32_t _e = g_dpx(0x0A); uint16_t _v = g_ror16(g_rd16(_e)); g_wr16(_e, _v); }  /* B214 ROR */
    recomp_tick(16); if (g_cpu.flag_N) goto L_B21E;  /* B216 BMI */
    recomp_tick(14); g_cpu.flag_I = true;  /* B218 SEI */
    recomp_tick(48); { uint32_t _e = g_dp(0xBF); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* B219 ASL */
    recomp_tick(14); g_cpu.flag_I = true;  /* B21B SEI */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0x68))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B21C ORA */
L_B21E:;
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpil(0x68))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B21E ORA */
    recomp_tick(48); { uint32_t _e = g_dpx(0x11); uint16_t _v = g_rol16(g_rd16(_e)); g_wr16(_e, _v); }  /* B220 ROL */
    recomp_tick(56); { uint32_t _e = g_absx(0xFFA0); uint16_t _v = g_lsr16(g_rd16(_e)); g_wr16(_e, _v); }  /* B222 LSR */
    recomp_tick(14); return;  /* B225 RTI */
}

void gen_register_bank_14(void) {
    func_table_register_flags(0x14800F, gen_14800F, false);
    func_table_register_flags(0x14A890, gen_14A890, false);
    func_table_register_flags(0x14B20F, gen_14B20F, false);
}
