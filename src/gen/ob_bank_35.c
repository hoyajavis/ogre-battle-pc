/* Bank $35 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 1 lifted, 16 unlifted in Bank $35 */
/* not lifted: $35807A: BRK at $35:807A */
/* not lifted: $35827E: COP at $35:8296 */
/* not lifted: $358361: COP at $35:8361 */
/* not lifted: $35A87F: BRK at $35:A87F */
/* not lifted: $35ADFD: COP at $35:AE15 */
/* not lifted: $35C0A0: BRK at $35:C0A0 */
/* not lifted: $35C0FF: calls unlifted target 0x358CA2: executes native on LakeSnes */
/* not lifted: $35C612: calls unlifted target 0x35BAD4: executes native on LakeSnes */
/* not lifted: $35D67E: PLD at $D682 pulls below the entry stack (return-address trick) */
/* not lifted: $35E05D: COP at $35:E098 */
/* not lifted: $35E500: BRK at $35:E504 */
/* not lifted: $35E807: BRK at $35:E80C */
/* not lifted: $35F0DF: PLY at $F0E7 pulls below the entry stack (return-address trick) */
/* not lifted: $35FE27: PLX at $FE27 pulls below the entry stack (return-address trick) */
/* not lifted: $35FF50: PLB at $FF58 pulls below the entry stack (return-address trick) */
/* not lifted: $35FF83: PLB at $FF8F pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $35CF79, entered with P=$00 via JSR */
void gen_35CF79(void) {
    goto L_CF79;
L_CF79:;
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CF79 ASL */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* CF7A ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* CF7B CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* CF7C ADC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* CF7E TAY */
    recomp_tick(16); g_sep(0x20);  /* CF7F SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* CF81 TDC */
    recomp_tick(24); g_wr8(g_dp(0x02), 0);  /* CF82 STZ */
    recomp_tick(16); { uint8_t _v = 0x09; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF84 LDA */
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CF86 STA */
    recomp_tick(16); { uint8_t _v = 0x05; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF88 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* CF8A STA */
L_CF8C:;
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.X = _v; g_nz16(_v); }  /* CF8C TYX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF8D LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* CF90 INY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0xFF);  /* CF91 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_CFC0;  /* CF93 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CF95 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x08FA)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF96 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* CF99 LSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x085A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF9A LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF9D DEC */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* CF9E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02FD9Au)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CF9F LDA */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CFA8;  /* CFA3 BCC */
    recomp_tick(24); { uint16_t _v = 0x0020; g_cpu.X = _v; g_nz16(_v); }  /* CFA5 LDX */
L_CFA8:;
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)));  /* CFA8 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_CFC0;  /* CFAA BCC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CFB8;  /* CFAC BNE */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02FD35u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CFAE LDA */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x03)));  /* CFB2 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_CFC0;  /* CFB4 BCS */
    recomp_tick(16); goto L_CFBE;  /* CFB6 BRA */
L_CFB8:;
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* CFB8 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x02FD35u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CFBA LDA */
L_CFBE:;
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* CFBE STA */
L_CFC0:;
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* CFC0 DEC */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_CF8C;  /* CFC2 BNE */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* CFC4 LDA */
    recomp_tick(14); return;  /* CFC6 RTL */
}

void gen_register_bank_35(void) {
    func_table_register_flags(0x35CF79, gen_35CF79, false);
}
