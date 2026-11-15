/* Bank $01 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 6 lifted, 46 unlifted in Bank $01 */
/* not lifted: $018000: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $018067: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $018092: COP at $01:8092 */
/* not lifted: $018093: PLA at $80B6 pulls below the entry stack (return-address trick) */
/* not lifted: $0180C9: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $018651: BRK at $01:8651 */
/* not lifted: $0186C0: BRK at $01:8748 */
/* not lifted: $018900: BRK at $01:8902 */
/* not lifted: $018908: BRK at $01:8908 */
/* not lifted: $0189F0: BRK at $01:89F2 */
/* not lifted: $019110: BRK at $01:9112 */
/* not lifted: $019200: BRK at $01:920D */
/* not lifted: $019210: BRK at $01:9215 */
/* not lifted: $019861: BRK at $01:9861 */
/* not lifted: $01A089: BRK at $01:A08A */
/* not lifted: $01A0BD: BRK at $01:A0BF */
/* not lifted: $01A2AA: BRK at $01:A2AD */
/* not lifted: $01A57B: BRK at $01:A57B */
/* not lifted: $01A8A5: BRK at $01:2EC7 */
/* not lifted: $01BD04: BRK at $01:BD07 */
/* not lifted: $01C092: BRK at $01:C097 */
/* not lifted: $01C093: BRK at $01:C095 */
/* not lifted: $01C764: BRK at $01:C767 */
/* not lifted: $01C918: BRK at $01:C91A */
/* not lifted: $01C93C: BRK at $01:C93C */
/* not lifted: $01C958: BRK at $01:C958 */
/* not lifted: $01C976: BRK at $01:C976 */
/* not lifted: $01C99F: BRK at $01:C99F */
/* not lifted: $01C9C5: BRK at $01:C9C5 */
/* not lifted: $01C9EB: BRK at $01:C9EB */
/* not lifted: $01C9F6: BRK at $01:C9F6 */
/* not lifted: $01CA03: BRK at $01:CA03 */
/* not lifted: $01CA19: BRK at $01:CA19 */
/* not lifted: $01D946: BRK at $01:D947 */
/* not lifted: $01E053: BRK at $01:E053 */
/* not lifted: $01EA00: tail jump at $EA4D with 2 bytes pushed */
/* not lifted: $01F000: BRK at $01:F000 */
/* not lifted: $01F4A7: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $01F4D0: BRK at $01:F51B */
/* not lifted: $01F800: BRK at $01:F803 */
/* not lifted: $01F818: BRK at $01:F81F */
/* not lifted: $01F97C: BRK at $01:F9A4 */
/* not lifted: $01F99D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $01FB45: PLB at $FB71 pulls below the entry stack (return-address trick) */
/* not lifted: $01FC00: PLX at $FC47 pulls below the entry stack (return-address trick) */
/* not lifted: $01FD41: COP at $01:FD6C */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $01F4C3, entered with P=$20 via JSR */
void gen_01F4C3(void) {
    goto L_F4C3;
L_F4C3:;
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F4C3 LDA */
    recomp_tick(24); g_wr8(g_dp(0xCC), (uint8_t)(uint8_t)g_cpu.C);  /* F4C5 STA */
    recomp_tick(32); g_wr8(g_abs(0x0620), 0);  /* F4C7 STZ */
    recomp_tick(32); g_wr8(g_abs(0x0621), 0);  /* F4CA STZ */
    recomp_tick(32); { uint32_t _e = g_dp(0xCB); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* F4CD INC */
    recomp_tick(14); return;  /* F4CF RTS */
}

/* $01F4CF, entered with P=$00 via JSR */
void gen_01F4CF(void) {
    goto L_F4CF;
L_F4CF:;
    recomp_tick(14); return;  /* F4CF RTS */
}

/* $01F808, entered with P=$20 via JSR */
void gen_01F808(void) {
    goto L_F808;
L_F808:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ 0x20); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F808 EOR */
    recomp_tick(32); g_wr8(g_absy(0x2B11), (uint8_t)(uint8_t)g_cpu.C);  /* F80A STA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpxi(0x00)))));  /* F80D SBC */
    recomp_tick(32); { uint32_t _e = g_dp(0xCB); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* F80F INC */
    recomp_tick(14); return;  /* F811 RTS */
}

/* $01F9BC, entered with P=$20 via JSR */
void gen_01F9BC(void) {
    goto L_F9BC;
L_F9BC:;
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* F9BC TDC */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0660)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9BD LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F9C0 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xFA90)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9C1 LDA */
    recomp_tick(40); g_wr8(0x7F0000u, (uint8_t)(uint8_t)g_cpu.C);  /* F9C4 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0661)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9C8 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F9CB TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xFA90)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9CC LDA */
    recomp_tick(40); g_wr8(0x7F000Cu, (uint8_t)(uint8_t)g_cpu.C);  /* F9CF STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0662)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9D3 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F9D6 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xFA90)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9D7 LDA */
    recomp_tick(40); g_wr8(0x7F0018u, (uint8_t)(uint8_t)g_cpu.C);  /* F9DA STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0663)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9DE LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* F9E1 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0xFA90)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9E2 LDA */
    recomp_tick(40); g_wr8(0x7F0024u, (uint8_t)(uint8_t)g_cpu.C);  /* F9E5 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0690)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9E9 LDA */
    recomp_tick(24); { uint16_t _v = 0x0002; g_cpu.X = _v; g_nz16(_v); }  /* F9EC LDX */
    recomp_tick(30); g_push16(0xF9F1); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* F9EF JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0691)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9F2 LDA */
    recomp_tick(24); { uint16_t _v = 0x000E; g_cpu.X = _v; g_nz16(_v); }  /* F9F5 LDX */
    recomp_tick(30); g_push16(0xF9FA); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* F9F8 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0692)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* F9FB LDA */
    recomp_tick(24); { uint16_t _v = 0x001A; g_cpu.X = _v; g_nz16(_v); }  /* F9FE LDX */
    recomp_tick(30); g_push16(0xFA03); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA01 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0693)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA04 LDA */
    recomp_tick(24); { uint16_t _v = 0x0026; g_cpu.X = _v; g_nz16(_v); }  /* FA07 LDX */
    recomp_tick(30); g_push16(0xFA0C); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA0A JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0460)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA0D LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA10 SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0461)))));  /* FA11 SBC */
    recomp_tick(24); { uint16_t _v = 0x0006; g_cpu.X = _v; g_nz16(_v); }  /* FA14 LDX */
    recomp_tick(30); g_push16(0xFA19); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA17 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04C0)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA1A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA1D SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04C1)))));  /* FA1E SBC */
    recomp_tick(24); { uint16_t _v = 0x000A; g_cpu.X = _v; g_nz16(_v); }  /* FA21 LDX */
    recomp_tick(30); g_push16(0xFA26); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA24 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0460)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA27 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA2A SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0463)))));  /* FA2B SBC */
    recomp_tick(24); { uint16_t _v = 0x0012; g_cpu.X = _v; g_nz16(_v); }  /* FA2E LDX */
    recomp_tick(30); g_push16(0xFA33); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA31 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04C0)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA34 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA37 SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04C3)))));  /* FA38 SBC */
    recomp_tick(24); { uint16_t _v = 0x0016; g_cpu.X = _v; g_nz16(_v); }  /* FA3B LDX */
    recomp_tick(30); g_push16(0xFA40); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA3E JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0460)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA41 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA44 SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0465)))));  /* FA45 SBC */
    recomp_tick(24); { uint16_t _v = 0x001E; g_cpu.X = _v; g_nz16(_v); }  /* FA48 LDX */
    recomp_tick(30); g_push16(0xFA4D); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA4B JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04C0)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA4E LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA51 SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04C5)))));  /* FA52 SBC */
    recomp_tick(24); { uint16_t _v = 0x0022; g_cpu.X = _v; g_nz16(_v); }  /* FA55 LDX */
    recomp_tick(30); g_push16(0xFA5A); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA58 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x0460)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA5B LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA5E SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x0467)))));  /* FA5F SBC */
    recomp_tick(24); { uint16_t _v = 0x002A; g_cpu.X = _v; g_nz16(_v); }  /* FA62 LDX */
    recomp_tick(30); g_push16(0xFA67); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA65 JSR */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x04C0)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA68 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* FA6B SEC */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_abs(0x04C7)))));  /* FA6C SBC */
    recomp_tick(24); { uint16_t _v = 0x002E; g_cpu.X = _v; g_nz16(_v); }  /* FA6F LDX */
    recomp_tick(30); g_push16(0xFA74); func_table_call_jsr(0x01FA76); g_cpu.S += 2;  /* FA72 JSR */
    recomp_tick(14); return;  /* FA75 RTS */
}

/* $01FA76, entered with P=$20 via JSR */
void gen_01FA76(void) {
    goto L_FA76;
L_FA76:;
    recomp_tick(14); g_push8((uint8_t)g_cpu.C);  /* FA76 PHA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* FA77 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* FA78 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* FA79 LSR */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* FA7A LSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* FA7B TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xFA90)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA7C LDA */
    recomp_tick(40); g_wr8(g_longx(0x7F0000u), (uint8_t)(uint8_t)g_cpu.C);  /* FA7F STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* FA83 INX */
    recomp_tick(14); { uint8_t _v = g_pull8(); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA84 PLA */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x0F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA85 AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* FA87 TAY */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0xFA90)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FA88 LDA */
    recomp_tick(40); g_wr8(g_longx(0x7F0000u), (uint8_t)(uint8_t)g_cpu.C);  /* FA8B STA */
    recomp_tick(14); return;  /* FA8F RTS */
}

/* $01FFFF, entered with P=$30 via JSR */
void gen_01FFFF(void) {
    goto L_FFFF;
L_0000:;
    recomp_tick(16); g_sep(0x30);  /* 0000 SEP */
    recomp_tick(32); { uint8_t _v = g_rd8(g_abs(0x07A1)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0002 LDA */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_0008;  /* 0005 BNE */
    recomp_tick(14); return;  /* 0007 RTS */
L_0008:;
    recomp_tick(16); { uint8_t _v = 0x16; g_cpu.X = _v; g_nz8(_v); }  /* 0008 LDX */
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)g_cpu.X);  /* 000A STX */
L_000C:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0770)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 000C LDA */
    recomp_tick(24); g_wr8(g_dp(0x03), (uint8_t)(uint8_t)g_cpu.C);  /* 000F STA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 0011 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 0012 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0441)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0013 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 0016 LSR */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 0017 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x04A1)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0019 LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 001C SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)))));  /* 001D SBC */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 001F STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0021 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0023 DEC */
    recomp_tick(24); g_wr8(g_dp(0x01), (uint8_t)(uint8_t)g_cpu.C);  /* 0024 STA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 0026 TAX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0770)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0027 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 002A ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* 002B TAY */
    recomp_tick(16); goto L_0045;  /* 002C BRA */
L_002E:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_cpu.X = _v; g_nz8(_v); }  /* 002E LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0770)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0030 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0771), (uint8_t)(uint8_t)g_cpu.C);  /* 0033 STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x01); uint8_t _v = (uint8_t)(g_rd8(_e) - 1); g_wr8(_e, _v); g_nz8(_v); }  /* 0036 DEC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0038 LDA */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x16);  /* 003A CMP */
    recomp_tick(16); if (g_cpu.flag_N) goto L_0055;  /* 003C BMI */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_cpu.X = _v; g_nz8(_v); }  /* 003E LDX */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absx(0x0770)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0040 LDA */
    recomp_tick(14); { uint8_t _v = g_asl8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 0043 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* 0044 TAY */
L_0045:;
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x0441)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0045 LDA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 0048 LSR */
    recomp_tick(24); g_wr8(g_dp(0x04), (uint8_t)(uint8_t)g_cpu.C);  /* 0049 STA */
    recomp_tick(32); { uint8_t _v = g_rd8(g_absy(0x04A1)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 004B LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* 004E SEC */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dp(0x04)))));  /* 004F SBC */
    recomp_tick(24); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_dp(0x02)));  /* 0051 CMP */
    recomp_tick(16); if (g_cpu.flag_N) goto L_002E;  /* 0053 BMI */
L_0055:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x01)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0055 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0057 INC */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* 0058 TAX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 0059 LDA */
    recomp_tick(32); g_wr8(g_absx(0x0770), (uint8_t)(uint8_t)g_cpu.C);  /* 005B STA */
    recomp_tick(32); { uint32_t _e = g_dp(0x00); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 005E INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x00)); g_cpu.X = _v; g_nz8(_v); }  /* 0060 LDX */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.X, 0x23);  /* 0062 CPX */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_000C;  /* 0064 BNE */
    recomp_tick(14); return;  /* 0066 RTS */
L_FFFF:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFFF TAX */
    goto L_0000;
}

void gen_register_bank_01(void) {
    func_table_register_flags(0x01F4C3, gen_01F4C3, false);
    func_table_register_flags(0x01F4CF, gen_01F4CF, false);
    func_table_register_flags(0x01F808, gen_01F808, false);
    func_table_register_flags(0x01F9BC, gen_01F9BC, false);
    func_table_register_flags(0x01FA76, gen_01FA76, false);
    func_table_register_flags(0x01FFFF, gen_01FFFF, false);
}
