/* Bank $09 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 5 lifted, 43 unlifted in Bank $09 */
/* not lifted: $0980A0: BRK at $09:80A0 */
/* not lifted: $098DFC: COP at $09:8E08 */
/* not lifted: $098E22: BRK at $09:8E29 */
/* not lifted: $098EEF: BRK at $09:8EF5 */
/* not lifted: $09925C: TXS at $09:9263 */
/* not lifted: $099277: TXS at $09:927E */
/* not lifted: $099292: BRK at $09:9252 */
/* not lifted: $0992BA: calls unlifted target 0x09AAC7: executes native on LakeSnes */
/* not lifted: $09987A: BRK at $09:987E */
/* not lifted: $099923: calls unlifted target 0x09AB83: executes native on LakeSnes */
/* not lifted: $099E20: BRK at $09:9E22 */
/* not lifted: $099F05: calls unlifted target 0x09AADF: executes native on LakeSnes */
/* not lifted: $099F2B: calls unlifted target 0x09AAD8: executes native on LakeSnes */
/* not lifted: $09A00D: BRK at $09:A020 */
/* not lifted: $09A025: calls unlifted target 0x09AAE6: executes native on LakeSnes */
/* not lifted: $09A0BF: calls unlifted target 0x09AAF9: executes native on LakeSnes */
/* not lifted: $09A0F3: calls unlifted target 0x09A0FE: executes native on LakeSnes */
/* not lifted: $09A0FE: calls unlifted target 0x09AAC0: executes native on LakeSnes */
/* not lifted: $09A140: TXS at $09:A157 */
/* not lifted: $09A1D4: calls RAM trampoline/sub-8000 ($091199): executes native on LakeSnes */
/* not lifted: $09A493: BRK at $09:A50A */
/* not lifted: $09A4A4: BRK at $09:A4AB */
/* not lifted: $09A50C: BRK at $09:A539 */
/* not lifted: $09A53B: calls unlifted target 0x09A55A: executes native on LakeSnes */
/* not lifted: $09A55A: BRK at $09:A581 */
/* not lifted: $09AAC0: calls RAM trampoline/sub-8000 ($091199): executes native on LakeSnes */
/* not lifted: $09AAC7: BRK at $09:AACF */
/* not lifted: $09AAD1: PLD at $AAD4 pulls below the entry stack (return-address trick) */
/* not lifted: $09AAD8: BRK at $09:AADD */
/* not lifted: $09AADF: calls RAM trampoline/sub-8000 ($091199): executes native on LakeSnes */
/* not lifted: $09AAE6: BRK at $09:AACF */
/* not lifted: $09AAF2: calls RAM trampoline/sub-8000 ($091199): executes native on LakeSnes */
/* not lifted: $09AAF9: BRK at $09:AACF */
/* not lifted: $09AB0C: calls RAM trampoline/sub-8000 ($091199): executes native on LakeSnes */
/* not lifted: $09AB13: COP at $09:AB18 */
/* not lifted: $09AB1A: calls RAM trampoline/sub-8000 ($091199): executes native on LakeSnes */
/* not lifted: $09AB36: BRK at $09:AB3B */
/* not lifted: $09AB83: BRK at $09:AB88 */
/* not lifted: $09AB8A: PLD at $AB96 pulls below the entry stack (return-address trick) */
/* not lifted: $09C0E0: BRK at $09:C0EC */
/* not lifted: $09FCFF: PLP at $FD1A pulls below the entry stack (return-address trick) */
/* not lifted: $09FF20: PLB at $FF3C pulls below the entry stack (return-address trick) */
/* not lifted: $09FFCF: PLB at $FFD0 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $098809, entered with P=$30 via JSR */
void gen_098809(void) {
    goto L_8809;
L_8809:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz8(_v); }  /* 8809 DEY */
    recomp_tick(14); return;  /* 880A RTI */
}

/* $0992F7, entered with P=$20 via JSR */
void gen_0992F7(void) {
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
    recomp_tick(30); g_push16(0x9314); func_table_call_jsr(0x09933C); g_cpu.S += 2;  /* 9312 JSR */
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

/* $09933C, entered with P=$20 via JSR */
void gen_09933C(void) {
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

/* $09A12E, entered with P=$20 via JSR */
void gen_09A12E(void) {
    goto L_A12E;
L_A12E:;
    recomp_tick(14); g_cpu.flag_C = false;  /* A12E CLC */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x18)))));  /* A12F ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* A131 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x19)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A133 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* A135 ADC */
    recomp_tick(24); g_wr8(g_dp(0x19), (uint8_t)(uint8_t)g_cpu.C);  /* A137 STA */
    recomp_tick(14); return;  /* A139 RTS */
}

/* $09A658, entered with P=$20 via JSR */
void gen_09A658(void) {
    goto L_A658;
L_A658:;
    recomp_tick(14); g_cpu.flag_C = true;  /* A658 SEC */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0xEA)));  /* A659 SBC */
    recomp_tick(14); return;  /* A65B RTS */
}

void gen_register_bank_09(void) {
    func_table_register_flags(0x098809, gen_098809, false);
    func_table_register_flags(0x0992F7, gen_0992F7, false);
    func_table_register_flags(0x09933C, gen_09933C, false);
    func_table_register_flags(0x09A12E, gen_09A12E, false);
    func_table_register_flags(0x09A658, gen_09A658, false);
}
