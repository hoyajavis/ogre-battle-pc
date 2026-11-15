/* Bank $39 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 11 unlifted in Bank $39 */
/* not lifted: $39925C: TXS at $39:9263 */
/* not lifted: $399277: TXS at $39:927E */
/* not lifted: $3992BA: calls unlifted target 0x39AAC7: executes native on LakeSnes */
/* not lifted: $39AAC0: calls RAM trampoline/sub-8000 ($391199): executes native on LakeSnes */
/* not lifted: $39AAC7: BRK at $39:AACF */
/* not lifted: $39AAD8: BRK at $39:AADD */
/* not lifted: $39AAED: BRK at $39:AACF */
/* not lifted: $39AAF2: calls RAM trampoline/sub-8000 ($391199): executes native on LakeSnes */
/* not lifted: $39E020: PLP at $E03F pulls below the entry stack (return-address trick) */
/* not lifted: $39E9A9: TXS at $39:E9AA */
/* not lifted: $39FE07: PLP at $FE12 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $3992F7, entered with P=$20 via JSR */
void gen_3992F7(void) {
    goto L_92F7;
L_92F7:;
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 92F7 LDY */
    recomp_tick(32); g_wr16(g_dp(0x14), (uint16_t)g_cpu.Y);  /* 92FA STY */
    recomp_tick(24); { uint16_t _v = 0x0008; g_cpu.Y = _v; g_nz16(_v); }  /* 92FC LDY */
    recomp_tick(32); g_wr16(g_dp(0x16), (uint16_t)g_cpu.Y);  /* 92FF STY */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 9301 LDY */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* 9304 LDX */
L_9307:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x10)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9307 LDA */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 9309 STA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_932B;  /* 930B BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x19);  /* 930D CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9317;  /* 930F BNE */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 9311 INY */
    recomp_tick(30); g_push16(0x9314); func_table_call_jsr(0x39933C); g_cpu.S += 2;  /* 9312 JSR */
    recomp_tick(16); goto L_9319;  /* 9315 BRA */
L_9317:;
    recomp_tick(16); { uint8_t _v = 0x20; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9317 LDA */
L_9319:;
    recomp_tick(24); g_wr8(g_dpi(0x14), (uint8_t)(uint8_t)g_cpu.C);  /* 9319 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x13)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 931B LDA */
    recomp_tick(24); g_wr8(g_dpi(0x16), (uint8_t)(uint8_t)g_cpu.C);  /* 931D STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 931F INY */
    recomp_tick(32); { uint32_t _e = g_dp(0x14); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9320 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x16); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9322 INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x14)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9324 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x08);  /* 9326 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_9307;  /* 9328 BNE */
    recomp_tick(14); return;  /* 932A RTS */
L_932B:;
    recomp_tick(16); { uint8_t _v = 0x20; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 932B LDA */
    recomp_tick(24); g_wr8(g_dpi(0x14), (uint8_t)(uint8_t)g_cpu.C);  /* 932D STA */
    recomp_tick(24); g_wr8(g_dpi(0x16), (uint8_t)(uint8_t)g_cpu.C);  /* 932F STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x14); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9331 INC */
    recomp_tick(32); { uint32_t _e = g_dp(0x16); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 9333 INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x14)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9335 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x08);  /* 9337 CMP */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_932B;  /* 9339 BNE */
    recomp_tick(14); return;  /* 933B RTS */
}

/* $39933C, entered with P=$20 via JSR */
void gen_39933C(void) {
    goto L_933C;
L_933C:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 933C CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x10)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 933D LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x2F);  /* 933F CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_9393;  /* 9341 BEQ */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0A);  /* 9343 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_934B;  /* 9345 BCC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x0F);  /* 9347 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_939A;  /* 9349 BCC */
L_934B:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x10);  /* 934B CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9353;  /* 934D BCC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x15);  /* 934F CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9373;  /* 9351 BCC */
L_9353:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x30);  /* 9353 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_935B;  /* 9355 BCC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x35);  /* 9357 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_937B;  /* 9359 BCC */
L_935B:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x18);  /* 935B CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9363;  /* 935D BCC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x1D);  /* 935F CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_9383;  /* 9361 BCC */
L_9363:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x38);  /* 9363 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_936B;  /* 9365 BCC */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x3D);  /* 9367 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_938B;  /* 9369 BCC */
L_936B:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 936B CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x96)));  /* 936C ADC */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 936E STA */
    recomp_tick(16); { uint8_t _v = 0xDE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9370 LDA */
    recomp_tick(14); return;  /* 9372 RTS */
L_9373:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 9373 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0xDA)));  /* 9374 ADC */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 9376 STA */
    recomp_tick(16); { uint8_t _v = 0xDE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9378 LDA */
    recomp_tick(14); return;  /* 937A RTS */
L_937B:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 937B CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x9A)));  /* 937C ADC */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 937E STA */
    recomp_tick(16); { uint8_t _v = 0xDE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9380 LDA */
    recomp_tick(14); return;  /* 9382 RTS */
L_9383:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 9383 CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0xD2)));  /* 9384 ADC */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 9386 STA */
    recomp_tick(16); { uint8_t _v = 0xDF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9388 LDA */
    recomp_tick(14); return;  /* 938A RTS */
L_938B:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 938B CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x92)));  /* 938C ADC */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 938E STA */
    recomp_tick(16); { uint8_t _v = 0xDF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9390 LDA */
    recomp_tick(14); return;  /* 9392 RTS */
L_9393:;
    recomp_tick(16); { uint8_t _v = 0xB3; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9393 LDA */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 9395 STA */
    recomp_tick(16); { uint8_t _v = 0xDE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9397 LDA */
    recomp_tick(14); return;  /* 9399 RTS */
L_939A:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 939A CLC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0xD6)));  /* 939B ADC */
    recomp_tick(24); g_wr8(g_dp(0x13), (uint8_t)(uint8_t)g_cpu.C);  /* 939D STA */
    recomp_tick(16); { uint8_t _v = 0xDE; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 939F LDA */
    recomp_tick(14); return;  /* 93A1 RTS */
}

void gen_register_bank_39(void) {
    func_table_register_flags(0x3992F7, gen_3992F7, false);
    func_table_register_flags(0x39933C, gen_39933C, false);
}
