/* Bank $06 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 12 lifted, 43 unlifted in Bank $06 */
/* not lifted: $069768: calls unlifted target 0x069C43: executes native on LakeSnes */
/* not lifted: $069782: COP at $06:9796 */
/* not lifted: $06984E: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $069B90: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $069C43: BRK at $06:9C4B */
/* not lifted: $069F56: COP at $06:9F5C */
/* not lifted: $06A803: BRK at $06:A820 */
/* not lifted: $06A8A7: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $06B058: BRK at $06:B05F */
/* not lifted: $06B537: COP at $06:B53C */
/* not lifted: $06B53E: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $06B54C: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $06B553: COP at $06:B558 */
/* not lifted: $06B55A: BRK at $06:B55F */
/* not lifted: $06B568: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $06B599: BRK at $06:B5C1 */
/* not lifted: $06B5D8: BRK at $06:B5DD */
/* not lifted: $06B5ED: COP at $06:B5F2 */
/* not lifted: $06B5F4: COP at $06:B62B */
/* not lifted: $06B5FD: COP at $06:B62B */
/* not lifted: $06B7A3: BRK at $06:B7A5 */
/* not lifted: $06B875: BRK at $06:B883 */
/* not lifted: $06BA69: BRK at $06:BA7A */
/* not lifted: $06BAAB: calls RAM trampoline/sub-8000 ($A01480): executes native on LakeSnes */
/* not lifted: $06BABF: RTS at $BAF8 with 1 bytes still pushed */
/* not lifted: $06BAF9: RTS at $BB83 with 1 bytes still pushed */
/* not lifted: $06BB07: calls unlifted target 0x8DA4A9: executes native on LakeSnes */
/* not lifted: $06BBC4: COP at $06:BBC9 */
/* not lifted: $06BD7B: COP at $06:BD87 */
/* not lifted: $06BD82: COP at $06:BD87 */
/* not lifted: $06BD89: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $06BD97: BRK at $06:BE1F */
/* not lifted: $06BE48: BRK at $06:BE59 */
/* not lifted: $06BE61: BRK at $06:BE68 */
/* not lifted: $06BEDF: calls unlifted target 0x06C61E: executes native on LakeSnes */
/* not lifted: $06BF04: calls unlifted target 0x06C61E: executes native on LakeSnes */
/* not lifted: $06BF29: calls unlifted target 0x06C61E: executes native on LakeSnes */
/* not lifted: $06C606: calls RAM trampoline/sub-8000 ($061199): executes native on LakeSnes */
/* not lifted: $06C60D: BRK at $06:C615 */
/* not lifted: $06C617: BRK at $06:C61C */
/* not lifted: $06C61E: BRK at $06:C615 */
/* not lifted: $06E003: PLB at $E020 pulls below the entry stack (return-address trick) */
/* not lifted: $06F207: PLP at $F27D pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $068369, entered with P=$30 via JSR */
void gen_068369(void) {
    goto L_8369;
L_8369:;
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8369 DEC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 836A TAX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 836B PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x03F6A1u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 836C LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 8370 LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF621u), (uint8_t)(uint8_t)g_cpu.C);  /* 8372 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 8376 PLX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 8377 PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x03F706u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8378 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 837C LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF685u), (uint8_t)(uint8_t)g_cpu.C);  /* 837E STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 8382 PLX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 8383 PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x03F76Bu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8384 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 8388 LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF6E9u), (uint8_t)(uint8_t)g_cpu.C);  /* 838A STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 838E PLX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 838F PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x03F7D0u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8390 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 8394 LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF74Du), (uint8_t)(uint8_t)g_cpu.C);  /* 8396 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 839A PLX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 839B PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x03F835u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 839C LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 83A0 LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF7B1u), (uint8_t)(uint8_t)g_cpu.C);  /* 83A2 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 83A6 PLX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 83A7 PHX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x03F89Au)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 83A8 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 83AC LDX */
    recomp_tick(40); g_wr8(g_longx(0x7EF815u), (uint8_t)(uint8_t)g_cpu.C);  /* 83AE STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 83B2 PLX */
    recomp_tick(14); return;  /* 83B3 RTS */
}

/* $06866A, entered with P=$30 via JSR */
void gen_06866A(void) {
    goto L_866A;
L_866A:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x03C8)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 866A LDA */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* 866D STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x03C5)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 866F LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 8672 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1F06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8674 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 8677 STA */
    recomp_tick(30); g_push16(0x867B); func_table_call_jsr(0x0686A0); g_cpu.S += 2;  /* 8679 JSR */
    recomp_tick(32); g_wr8(g_abs(0x1F06), (uint8_t)(uint8_t)g_cpu.C);  /* 867C STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x03C6)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 867F LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 8682 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1F0A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8684 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 8687 STA */
    recomp_tick(30); g_push16(0x868B); func_table_call_jsr(0x0686A0); g_cpu.S += 2;  /* 8689 JSR */
    recomp_tick(32); g_wr8(g_abs(0x1F0A), (uint8_t)(uint8_t)g_cpu.C);  /* 868C STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x03C7)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 868F LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 8692 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1F0E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8694 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 8697 STA */
    recomp_tick(30); g_push16(0x869B); func_table_call_jsr(0x0686A0); g_cpu.S += 2;  /* 8699 JSR */
    recomp_tick(32); g_wr8(g_abs(0x1F0E), (uint8_t)(uint8_t)g_cpu.C);  /* 869C STA */
    recomp_tick(14); return;  /* 869F RTS */
}

/* $0686A0, entered with P=$30 via JSR */
void gen_0686A0(void) {
    goto L_86A0;
L_86A0:;
    recomp_tick(24); g_wr8(g_dp(0x01), 0);  /* 86A0 STZ */
    recomp_tick(24); g_wr8(g_dp(0x03), 0);  /* 86A2 STZ */
    recomp_tick(24); g_wr8(g_dp(0x05), 0);  /* 86A4 STZ */
    recomp_tick(16); g_rep(0x20);  /* 86A6 REP */
    recomp_tick(14); g_cpu.flag_C = true;  /* 86A8 SEC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 86A9 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* 86AB SBC */
    recomp_tick(14); g_cpu.flag_C = true;  /* 86AD SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* 86AE SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_86C3;  /* 86B0 BPL */
    recomp_tick(24); g_cmp16(g_cpu.C, 0xFFF6);  /* 86B2 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_86E4;  /* 86B5 BCS */
    recomp_tick(24); g_cmp16(g_cpu.C, 0xFFEC);  /* 86B7 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_86D8;  /* 86BA BCS */
    recomp_tick(24); g_cmp16(g_cpu.C, 0xFFE2);  /* 86BC CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_86D6;  /* 86BF BCS */
    recomp_tick(16); goto L_86D4;  /* 86C1 BRA */
L_86C3:;
    recomp_tick(24); g_cmp16(g_cpu.C, 0x000A);  /* 86C3 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_86E2;  /* 86C6 BCC */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x0014);  /* 86C8 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_86E0;  /* 86CB BCC */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x001E);  /* 86CD CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_86DE;  /* 86D0 BCC */
    recomp_tick(16); goto L_86DC;  /* 86D2 BRA */
L_86D4:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86D4 DEC */
L_86D6:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86D6 DEC */
L_86D8:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) - 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86D8 DEC */
    recomp_tick(16); goto L_86E4;  /* 86DA BRA */
L_86DC:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86DC INC */
L_86DE:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86DE INC */
L_86E0:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86E0 INC */
L_86E2:;
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 86E2 INC */
L_86E4:;
    recomp_tick(16); g_sep(0x20);  /* 86E4 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 86E6 LDA */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_86F4;  /* 86E8 BEQ */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_86F0;  /* 86EA BPL */
    recomp_tick(24); g_wr8(g_dp(0x00), 0);  /* 86EC STZ */
    recomp_tick(16); goto L_86F4;  /* 86EE BRA */
L_86F0:;
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 86F0 LDA */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 86F2 STA */
L_86F4:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 86F4 LDA */
    recomp_tick(14); return;  /* 86F6 RTS */
}

/* $0686F7, entered with P=$30 via JSR */
void gen_0686F7(void) {
    goto L_86F7;
L_86F7:;
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF148u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 86F7 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F00), (uint8_t)(uint8_t)g_cpu.C);  /* 86FB STA */
    recomp_tick(32); g_wr8(g_abs(0x1F01), 0);  /* 86FE STZ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF24Cu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8701 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F06), (uint8_t)(uint8_t)g_cpu.C);  /* 8705 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF38Cu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8708 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F0E), (uint8_t)(uint8_t)g_cpu.C);  /* 870C STA */
    recomp_tick(32); g_wr8(g_abs(0x1F07), 0);  /* 870F STZ */
    recomp_tick(32); g_wr8(g_abs(0x1F0F), 0);  /* 8712 STZ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF2ECu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8715 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F0A), (uint8_t)(uint8_t)g_cpu.C);  /* 8719 STA */
    recomp_tick(32); g_wr8(g_abs(0x1F0B), 0);  /* 871C STZ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF42Cu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 871F LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F08), (uint8_t)(uint8_t)g_cpu.C);  /* 8723 STA */
    recomp_tick(32); g_wr8(g_abs(0x1F09), 0);  /* 8726 STZ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x000C1Au)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8729 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F0C), (uint8_t)(uint8_t)g_cpu.C);  /* 872D STA */
    recomp_tick(32); g_wr8(g_abs(0x1F0D), 0);  /* 8730 STZ */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF490u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8733 LDA */
    recomp_tick(32); g_wr8(g_abs(0x1F10), (uint8_t)(uint8_t)g_cpu.C);  /* 8737 STA */
    recomp_tick(32); g_wr8(g_abs(0x1F11), 0);  /* 873A STZ */
    recomp_tick(14); g_cpu.flag_C = true;  /* 873D SEC */
    recomp_tick(16); { uint8_t _v = 0x64; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 873E LDA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x7EF1E8u)))));  /* 8740 SBC */
    recomp_tick(32); g_wr8(g_abs(0x1F18), (uint8_t)(uint8_t)g_cpu.C);  /* 8744 STA */
    recomp_tick(32); g_wr8(g_abs(0x1F19), 0);  /* 8747 STZ */
    recomp_tick(16); g_rep(0x20);  /* 874A REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 874C TXA */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 874D ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 874E TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7EF4F4u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 874F LDA */
    recomp_tick(40); g_wr16(g_abs(0x1F12), (uint16_t)g_cpu.C);  /* 8753 STA */
    recomp_tick(16); g_sep(0x20);  /* 8756 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1E)); g_cpu.X = _v; g_nz8(_v); }  /* 8758 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 875A TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0E81)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 875B LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 875E TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF5BCu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 875F LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8763 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 8764 TAX */
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 8765 PHX */
    recomp_tick(16); g_rep(0x20);  /* 8766 REP */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x07BD44u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8768 LDA */
    recomp_tick(40); g_wr16(g_abs(0x12C7), (uint16_t)g_cpu.C);  /* 876C STA */
    recomp_tick(16); g_sep(0x20);  /* 876F SEP */
    recomp_tick(16); { uint8_t _v = 0x07; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8771 LDA */
    recomp_tick(32); g_wr8(g_abs(0x12C9), (uint8_t)(uint8_t)g_cpu.C);  /* 8773 STA */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 8776 PLX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.X; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8777 TXA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 8778 LSR */
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* 8779 PHA */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 877A TDC */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 877B PLA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 877C TAX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 877D TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C518u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 877E LDA */
    recomp_tick(16); g_rep(0x20);  /* 8782 REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 8784 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 8785 TAX */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x06806Bu)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8786 LDA */
    recomp_tick(40); g_wr16(g_abs(0x12CF), (uint16_t)g_cpu.C);  /* 878A STA */
    recomp_tick(16); g_sep(0x20);  /* 878D SEP */
    recomp_tick(16); { uint8_t _v = 0x06; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 878F LDA */
    recomp_tick(32); g_wr8(g_abs(0x12D1), (uint8_t)(uint8_t)g_cpu.C);  /* 8791 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x1E)); g_cpu.X = _v; g_nz8(_v); }  /* 8794 LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8796 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x000E81u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8797 LDA */
    recomp_tick(16); g_rep(0x20);  /* 879B REP */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* 879D ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 879E TAX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x099A)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 879F LDA */
    recomp_tick(40); g_wr16(g_abs(0x1F02), (uint16_t)g_cpu.C);  /* 87A2 STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x0ADA)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 87A5 LDA */
    recomp_tick(40); g_wr16(g_abs(0x1F04), (uint16_t)g_cpu.C);  /* 87A8 STA */
    recomp_tick(16); g_sep(0x20);  /* 87AB SEP */
    recomp_tick(14); return;  /* 87AD RTS */
}

/* $0687AE, entered with P=$30 via JSR */
void gen_0687AE(void) {
    goto L_87AE;
L_87AE:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.X);  /* 87AE PHX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 87AF TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF5BCu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87B0 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 87B4 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C7A2u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87B5 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_87CC;  /* 87B9 BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87BB EOR */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87BD INC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 87BE STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 87C0 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1F06)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87C1 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* 87C4 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_87D4;  /* 87C6 BCS */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87C8 LDA */
    recomp_tick(16); goto L_87D4;  /* 87CA BRA */
L_87CC:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 87CC CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x1F06)))));  /* 87CD ADC */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_87D4;  /* 87D0 BCC */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87D2 LDA */
L_87D4:;
    recomp_tick(32); g_wr8(g_abs(0x1F06), (uint8_t)(uint8_t)g_cpu.C);  /* 87D4 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C807u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87D7 LDA */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_87EE;  /* 87DB BPL */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0xFF); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87DD EOR */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87DF INC */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 87E0 STA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 87E2 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x1F0E)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87E3 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x00)))));  /* 87E6 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_87F6;  /* 87E8 BCS */
    recomp_tick(16); { uint8_t _v = 0x00; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87EA LDA */
    recomp_tick(16); goto L_87F6;  /* 87EC BRA */
L_87EE:;
    recomp_tick(14); g_cpu.flag_C = false;  /* 87EE CLC */
    recomp_tick(32); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x1F0E)))));  /* 87EF ADC */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_87F6;  /* 87F2 BCC */
    recomp_tick(16); { uint8_t _v = 0xFF; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 87F4 LDA */
L_87F6:;
    recomp_tick(32); g_wr8(g_abs(0x1F0E), (uint8_t)(uint8_t)g_cpu.C);  /* 87F6 STA */
    recomp_tick(32); g_wr8(g_abs(0x1F07), 0);  /* 87F9 STZ */
    recomp_tick(32); g_wr8(g_abs(0x1F0F), 0);  /* 87FC STZ */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.X = _v; g_nz8(_v); }  /* 87FF PLX */
    recomp_tick(14); return;  /* 8800 RTS */
}

/* $068E7F, entered with P=$20 via JSR */
void gen_068E7F(void) {
    goto L_8E7F;
L_8E7F:;
    recomp_tick(30); g_push16(0x8E81); func_table_call_jsr(0x068F0F); g_cpu.S += 2;  /* 8E7F JSR */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* 8E82 LDX */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8E84 CLC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF621u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E85 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x06)))));  /* 8E89 ADC */
    recomp_tick(40); g_wr8(g_longx(0x7EF621u), (uint8_t)(uint8_t)g_cpu.C);  /* 8E8B STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8E8F CLC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF685u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E90 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x08)))));  /* 8E94 ADC */
    recomp_tick(40); g_wr8(g_longx(0x7EF685u), (uint8_t)(uint8_t)g_cpu.C);  /* 8E96 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8E9A CLC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF6E9u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8E9B LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x0A)))));  /* 8E9F ADC */
    recomp_tick(40); g_wr8(g_longx(0x7EF6E9u), (uint8_t)(uint8_t)g_cpu.C);  /* 8EA1 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8EA5 CLC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF74Du)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EA6 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x0C)))));  /* 8EAA ADC */
    recomp_tick(40); g_wr8(g_longx(0x7EF74Du), (uint8_t)(uint8_t)g_cpu.C);  /* 8EAC STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8EB0 CLC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF7B1u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EB1 LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x0E)))));  /* 8EB5 ADC */
    recomp_tick(40); g_wr8(g_longx(0x7EF7B1u), (uint8_t)(uint8_t)g_cpu.C);  /* 8EB7 STA */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8EBB CLC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF815u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8EBC LDA */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x10)))));  /* 8EC0 ADC */
    recomp_tick(40); g_wr8(g_longx(0x7EF815u), (uint8_t)(uint8_t)g_cpu.C);  /* 8EC2 STA */
    recomp_tick(14); return;  /* 8EC6 RTS */
}

/* $068F0F, entered with P=$20 via JSR */
void gen_068F0F(void) {
    goto L_8F0F;
L_8F0F:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x1E)); g_cpu.X = _v; g_nz16(_v); }  /* 8F0F LDX */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8F11 TDC */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x7EF5BCu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F12 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* 8F16 TAX */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C86Cu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F17 LDA */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8F1B STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C8D1u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F1D LDA */
    recomp_tick(24); g_wr8(g_dp(0x08), (uint8_t)(uint8_t)g_cpu.C);  /* 8F21 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C936u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F23 LDA */
    recomp_tick(24); g_wr8(g_dp(0x0A), (uint8_t)(uint8_t)g_cpu.C);  /* 8F27 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07C99Bu)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F29 LDA */
    recomp_tick(24); g_wr8(g_dp(0x0C), (uint8_t)(uint8_t)g_cpu.C);  /* 8F2D STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07CA00u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F2F LDA */
    recomp_tick(24); g_wr8(g_dp(0x0E), (uint8_t)(uint8_t)g_cpu.C);  /* 8F33 STA */
    recomp_tick(40); { uint8_t _v = g_rd8(g_longx(0x07CA65u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8F35 LDA */
    recomp_tick(24); g_wr8(g_dp(0x10), (uint8_t)(uint8_t)g_cpu.C);  /* 8F39 STA */
    recomp_tick(14); return;  /* 8F3B RTS */
}

/* $06A86F, entered with P=$30 via JSR */
void gen_06A86F(void) {
    goto L_A86F;
L_A86F:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x03AC)); g_cpu.Y = _v; g_nz8(_v); }  /* A86F LDY */
    recomp_tick(14); g_cpu.flag_C = true;  /* A872 SEC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x157F)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A873 LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0x01)));  /* A876 SBC */
    recomp_tick(32); g_wr8(g_absy(0x157F), (uint8_t)(uint8_t)g_cpu.C);  /* A878 STA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_A881;  /* A87B BNE */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* A87D TDC */
    recomp_tick(32); g_wr8(g_absy(0x157E), (uint8_t)(uint8_t)g_cpu.C);  /* A87E STA */
L_A881:;
    recomp_tick(14); return;  /* A881 RTS */
}

/* $06B8C9, entered with P=$30 via JSR */
void gen_06B8C9(void) {
    goto L_B8C9;
L_B8C9:;
    recomp_tick(16); { uint8_t _v = 0x27; g_cpu.X = _v; g_nz8(_v); }  /* B8C9 LDX */
    recomp_tick(16); g_rep(0xA9);  /* B8CB REP */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x4985); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* B8CD AND */
    recomp_tick(16); { uint8_t _v = 0x00; g_cpu.Y = _v; g_nz8(_v); }  /* B8D0 LDY */
    recomp_tick(14); return;  /* B8D2 RTI */
}

/* $06BAB5, entered with P=$30 via JSR */
void gen_06BAB5(void) {
    goto L_BAB5;
L_BAB5:;
    recomp_tick(16); { uint8_t _v = 0x60; g_cpu.Y = _v; g_nz8(_v); }  /* BAB5 LDY */
    recomp_tick(24); g_mvn(0xAD, 0x59);  /* BAB7 MVN */
    recomp_tick(32); { uint32_t _e = g_dpx(0xD0); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* BABA ASL */
    recomp_tick(14); g_cpu.flag_C = false;  /* BABC CLC */
    recomp_tick(16); goto L_BAC9;  /* BABD BRA */
L_BAC9:;
    recomp_tick(16); { uint8_t _v = 0x8C; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BAC9 LDA */
    recomp_tick(32); g_wr8(g_abs(0x0390), (uint8_t)(uint8_t)g_cpu.C);  /* BACB STA */
    recomp_tick(16); { uint8_t _v = 0xA2; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BACE LDA */
    recomp_tick(32); g_wr8(g_abs(0x0391), (uint8_t)(uint8_t)g_cpu.C);  /* BAD0 STA */
    recomp_tick(16); goto L_BADF;  /* BAD3 BRA */
L_BADF:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.Y);  /* BADF PHY */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)g_cpu.Y);  /* BAE0 STY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0390)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BAE2 LDA */
    recomp_tick(30); g_push16(0xBAE7); func_table_call_jsr(0x06BB84); g_cpu.S += 2;  /* BAE5 JSR */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_cpu.Y = _v; g_nz8(_v); }  /* BAE8 PLY */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)g_cpu.Y);  /* BAE9 STY */
    recomp_tick(14); g_cpu.flag_C = false;  /* BAEB CLC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x18)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BAEC LDA */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x20)));  /* BAEE ADC */
    recomp_tick(24); g_wr8(g_dp(0x18), (uint8_t)(uint8_t)g_cpu.C);  /* BAF0 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0391)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BAF2 LDA */
    recomp_tick(30); g_push16(0xBAF7); func_table_call_jsr(0x06BB84); g_cpu.S += 2;  /* BAF5 JSR */
    recomp_tick(14); return;  /* BAF8 RTS */
}

/* $06BB84, entered with P=$30 via JSR */
void gen_06BB84(void) {
    goto L_BB84;
L_BB84:;
    recomp_tick(16); { uint8_t _v = 0x00; g_cpu.Y = _v; g_nz8(_v); }  /* BB84 LDY */
    recomp_tick(14); return;  /* BB86 RTI */
}

/* $06BC78, entered with P=$30 via JSR */
void gen_06BC78(void) {
    goto L_BC78;
L_BC78:;
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x18);  /* BC78 CMP */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BC7E;  /* BC7A BCS */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC7C INC */
    recomp_tick(14); return;  /* BC7D RTS */
L_BC7E:;
    recomp_tick(16); { uint8_t _v = 0x14; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC7E LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BC80 SEC */
    recomp_tick(14); return;  /* BC81 RTS */
}

void gen_register_bank_06(void) {
    func_table_register_flags(0x068369, gen_068369, false);
    func_table_register_flags(0x06866A, gen_06866A, false);
    func_table_register_flags(0x0686A0, gen_0686A0, false);
    func_table_register_flags(0x0686F7, gen_0686F7, false);
    func_table_register_flags(0x0687AE, gen_0687AE, false);
    func_table_register_flags(0x068E7F, gen_068E7F, false);
    func_table_register_flags(0x068F0F, gen_068F0F, false);
    func_table_register_flags(0x06A86F, gen_06A86F, false);
    func_table_register_flags(0x06B8C9, gen_06B8C9, false);
    func_table_register_flags(0x06BAB5, gen_06BAB5, false);
    func_table_register_flags(0x06BB84, gen_06BB84, false);
    func_table_register_flags(0x06BC78, gen_06BC78, false);
}
