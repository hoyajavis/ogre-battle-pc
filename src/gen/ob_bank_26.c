/* Bank $26 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 3 lifted, 54 unlifted in Bank $26 */
/* not lifted: $268369: PLA at $8397 pulls below the entry stack (return-address trick) */
/* not lifted: $26866A: TCS at $8673 with an unknown stack value */
/* not lifted: $2686A0: WAI at $26:86D1 */
/* not lifted: $2686F7: WAI at $26:8723 */
/* not lifted: $268E7F: COP at $26:4347 */
/* not lifted: $269768: PLX at $977B pulls below the entry stack (return-address trick) */
/* not lifted: $269782: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $26984E: PLY at $9865 pulls below the entry stack (return-address trick) */
/* not lifted: $269B90: PLA at $9B9A pulls below the entry stack (return-address trick) */
/* not lifted: $269C43: TCS at $9C43 with an unknown stack value */
/* not lifted: $269F56: XCE at $26:9F67 */
/* not lifted: $26A803: PLD at $A80D pulls below the entry stack (return-address trick) */
/* not lifted: $26A86F: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $26A8A7: STP at $26:A8E7 */
/* not lifted: $26AA22: STP at $26:FC1B */
/* not lifted: $26B058: BRK at $26:B05C */
/* not lifted: $26B537: BRK at $26:B547 */
/* not lifted: $26B53E: BRK at $26:B547 */
/* not lifted: $26B54C: BRK at $26:B55D */
/* not lifted: $26B553: BRK at $26:B55D */
/* not lifted: $26B55A: COP at $26:B562 */
/* not lifted: $26B561: COP at $26:C46A */
/* not lifted: $26B568: TCS at $AFD2 with an unknown stack value */
/* not lifted: $26B599: PLX at $B5A2 pulls below the entry stack (return-address trick) */
/* not lifted: $26B5D8: calls RAM trampoline/sub-8000 ($266CFC): executes native on LakeSnes */
/* not lifted: $26B5ED: calls RAM trampoline/sub-8000 ($266CFC): executes native on LakeSnes */
/* not lifted: $26B5F4: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $26B5FD: TCS at $B616 with an unknown stack value */
/* not lifted: $26B7A3: COP at $26:B7B3 */
/* not lifted: $26B7D4: BRK at $26:B7D5 */
/* not lifted: $26B875: COP at $26:B88F */
/* not lifted: $26B8C9: COP at $26:B88F */
/* not lifted: $26BA00: BRK at $26:BA00 */
/* not lifted: $26BA69: BRK at $26:BA92 */
/* not lifted: $26BAAB: PLB at $BAD0 pulls below the entry stack (return-address trick) */
/* not lifted: $26BAB5: PLB at $BAD0 pulls below the entry stack (return-address trick) */
/* not lifted: $26BABF: PLB at $BAD0 pulls below the entry stack (return-address trick) */
/* not lifted: $26BAF9: BRK at $26:BB09 */
/* not lifted: $26BB07: BRK at $26:BB09 */
/* not lifted: $26BB84: RTS at $BBBF with 1 bytes still pushed */
/* not lifted: $26BBC4: BRK at $26:BBC6 */
/* not lifted: $26BC78: BRK at $26:BC84 */
/* not lifted: $26BD7B: BRK at $26:BDAD */
/* not lifted: $26BD82: BRK at $26:BDAD */
/* not lifted: $26BD89: BRK at $26:BDAD */
/* not lifted: $26BDFF: XCE at $26:BE31 */
/* not lifted: $26E003: COP at $26:E003 */
/* not lifted: $26E0FF: BRK at $26:E10A */
/* not lifted: $26F7D9: BRK at $26:F7F1 */
/* not lifted: $26F907: BRK at $26:F89A */
/* not lifted: $26FA0E: PLY at $FA14 pulls below the entry stack (return-address trick) */
/* not lifted: $26FF1F: BRK at $26:FF22 */
/* not lifted: $26FFFC: WAI at $26:0012 */
/* not lifted: $26FFFD: WAI at $26:0012 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $2687AE, entered with P=$30 via JSR */
void gen_2687AE(void) {
    goto L_87AE;
L_87AE:;
    recomp_tick(14); return;  /* 87AE RTI */
}

/* $268F0F, entered with P=$30 via JSR */
void gen_268F0F(void) {
    goto L_8F0F;
L_8F0F:;
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x7492))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F0F ORA */
    recomp_tick(32); { uint32_t _e = g_dp(0xD5); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* 8F12 ROL */
    recomp_tick(16); goto L_8F4C;  /* 8F14 BRA */
L_8F4C:;
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_absx(0x020D)));  /* 8F4C CMP */
    recomp_tick(32); { uint32_t _e = g_dp(0x7B); uint8_t _v = g_rd8(_e); g_cpu.flag_Z = ((uint8_t)g_cpu.C & _v) == 0; g_wr8(_e, (uint8_t)(_v & ~(uint8_t)g_cpu.C)); }  /* 8F4F TRB */
    recomp_tick(24); g_wr8(g_dp(0x87), (uint8_t)g_cpu.Y);  /* 8F51 STY */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_abs(0x1244))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F53 ORA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F56 INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sriy(0x10))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F57 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpx(0xC5))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F59 ORA */
    recomp_tick(16); goto L_8F6A;  /* 8F5B BRA */
L_8F6A:;
    recomp_tick(24); g_wr8(g_dpx(0x74), 0);  /* 8F6A STZ */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x3E))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F6C ORA */
    recomp_tick(32); { uint32_t _e = g_dpx(0x58); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* 8F6E ASL */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_sr(0x06))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F70 ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x80)))));  /* 8F72 SBC */
    recomp_tick(24); g_wr8(g_sr(0x15), (uint8_t)(uint8_t)g_cpu.C);  /* 8F74 STA */
    recomp_tick(40); { uint32_t _e = g_abs(0xF9FC); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* 8F76 ASL */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0xF60E))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F79 ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dp(0x38))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F7C ORA */
    recomp_tick(40); { uint32_t _e = g_absx(0x1918); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* 8F7E ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8F81 CLC */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_longx(0xC5151Eu))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F82 ORA */
    recomp_tick(14); return;  /* 8F86 RTL */
}

/* $26F87D, entered with P=$00 via JSR */
void gen_26F87D(void) {
    goto L_F87D;
L_F87D:;
    recomp_tick(48); { uint32_t _e = g_dp(0xF1); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* F87D ASL */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dpxi(0x07)));  /* F87F CMP */
    recomp_tick(56); { uint32_t _e = g_absx(0xF8E2); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* F881 INC */
    recomp_tick(14); { uint16_t _v = g_rol16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* F884 ROL */
    recomp_tick(14); return;  /* F885 RTI */
}

void gen_register_bank_26(void) {
    func_table_register_flags(0x2687AE, gen_2687AE, false);
    func_table_register_flags(0x268F0F, gen_268F0F, false);
    func_table_register_flags(0x26F87D, gen_26F87D, false);
}
