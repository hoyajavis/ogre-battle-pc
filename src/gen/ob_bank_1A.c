/* Bank $1A recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 5 lifted, 35 unlifted in Bank $1A */
/* not lifted: $1A8060: BRK at $1A:8073 */
/* not lifted: $1A8080: COP at $1A:808A */
/* not lifted: $1A80C0: BRK at $1A:80CB */
/* not lifted: $1A80FE: COP at $1A:810B */
/* not lifted: $1A817F: BRK at $1A:8185 */
/* not lifted: $1A88DF: BRK at $1A:88F4 */
/* not lifted: $1A9F7F: BRK at $1A:9F94 */
/* not lifted: $1AA059: PLY at $A068 pulls below the entry stack (return-address trick) */
/* not lifted: $1AA09E: WAI at $1A:A0AB */
/* not lifted: $1AA8AA: $1A:316B reached with two different M/X/stack states */
/* not lifted: $1AAD08: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AB004: calls unlifted target 0x1A88DF: executes native on LakeSnes */
/* not lifted: $1AB0F0: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AB13E: BRK at $1A:B146 */
/* not lifted: $1ABAEB: PLA at $BB00 pulls below the entry stack (return-address trick) */
/* not lifted: $1AC080: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AC718: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AD82F: BRK at $1A:D833 */
/* not lifted: $1AD8FF: COP at $1A:D8DE */
/* not lifted: $1ADC0F: PLY at $DC0F pulls below the entry stack (return-address trick) */
/* not lifted: $1ADCFF: XCE at $1A:DD4D */
/* not lifted: $1AE237: XCE at $1A:E249 */
/* not lifted: $1AE82F: COP at $1A:7829 */
/* not lifted: $1AEE0F: BRK at $1A:EE26 */
/* not lifted: $1AEE10: BRK at $1A:EE26 */
/* not lifted: $1AEF00: XCE at $1A:EF22 */
/* not lifted: $1AF0C0: XCE at $1A:F0C7 */
/* not lifted: $1AF1FF: BRK at $1A:F20E */
/* not lifted: $1AFF07: XCE at $1A:FF0B */
/* not lifted: $1AFF11: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AFF20: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AFF21: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $1AFF68: PLY at $FF9B pulls below the entry stack (return-address trick) */
/* not lifted: $1AFF7B: PLY at $FF9B pulls below the entry stack (return-address trick) */
/* not lifted: $1AFF85: PLY at $FF9B pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $1A8000, entered with P=$30 via JSR */
void gen_1A8000(void) {
    goto L_8000;
L_8000:;
    recomp_tick(14); return;  /* 8000 RTS */
}

/* $1ABA05, entered with P=$10 via JSR */
void gen_1ABA05(void) {
    goto L_BA05;
L_BA05:;
    recomp_tick(48); { uint32_t _e = g_dp(0xA7); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v | g_cpu.C)); }  /* BA05 TSB */
    recomp_tick(48); { uint32_t _e = g_dp(0x0F); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* BA07 ASL */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_sriy(0x0D))));  /* BA09 SBC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x0B4204u))));  /* BA0B SBC */
    recomp_tick(48); { uint32_t _e = g_dp(0x5F); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* BA0F INC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0xFFFFBBu))));  /* BA11 SBC */
    recomp_tick(40); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_absy(0xF2FF))));  /* BA15 ADC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x09C4B7u))));  /* BA18 SBC */
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_absy(0xBCFF))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA1C AND */
    recomp_tick(14); return;  /* BA1F RTS */
}

/* $1AC892, entered with P=$30 via JSR */
void gen_1AC892(void) {
    goto L_C892;
L_C892:;
    recomp_tick(40); g_wr8(g_longx(0xFF3008u), (uint8_t)(uint8_t)g_cpu.C);  /* C892 STA */
    recomp_tick(40); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x0FF080u)))));  /* C896 ADC */
    recomp_tick(40); { uint32_t _e = g_absx(0xBD01); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* C89A INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sr(0x7F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C89D AND */
    recomp_tick(16); g_bit8(0x07, true);  /* C89F BIT */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dpi(0x9F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* C8A1 EOR */
    recomp_tick(14); return;  /* C8A3 RTS */
}

/* $1AE86A, entered with P=$30 via JSR */
void gen_1AE86A(void) {
    goto L_E86A;
L_E86A:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpi(0x1A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E86A LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_sriy(0xFF)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E86C LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E86E INC */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0x1A)); g_cpu.Y = _v; g_nz8(_v); }  /* E86F LDY */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpx(0x1A)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E871 LDA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpy(0x1A)); g_cpu.X = _v; g_nz8(_v); }  /* E873 LDX */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0xFE)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E875 LDA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpily(0x00))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* E877 ORA */
    recomp_tick(14); return;  /* E879 RTI */
}

/* $1AFB6C, entered with P=$30 via JSR */
void gen_1AFB6C(void) {
    goto L_FB6C;
L_FB6C:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x38E470u)))));  /* FB6C SBC */
L_FB70:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_sriy(0x1C)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FB70 LDA */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0xB67F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FB72 ORA */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0x3B5B47u)))));  /* FB75 SBC */
    recomp_tick(14); g_cpu.flag_V = false;  /* FB79 CLV */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_absy(0x1CCD))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FB7A ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dpil(0xFF))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FB7D EOR */
    recomp_tick(32); g_wr8(g_abs(0xC727), (uint8_t)g_cpu.X);  /* FB7F STX */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_sriy(0x83)))));  /* FB82 ADC */
    recomp_tick(32); g_wr8(g_absy(0x1400), (uint8_t)(uint8_t)g_cpu.C);  /* FB84 STA */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absx(0x2FA8)))));  /* FB87 SBC */
    recomp_tick(16); { uint8_t _v = 0x00; g_cpu.Y = _v; g_nz8(_v); }  /* FB8A LDY */
    recomp_tick(40); { uint32_t _e = g_absx(0xDF00); uint8_t _v = g_rol8(g_rd8(_e)); g_wr8(_e, _v); }  /* FB8C ROL */
    recomp_tick(16); goto L_FB70;  /* FB8F BRA */
}

void gen_register_bank_1A(void) {
    func_table_register_flags(0x1A8000, gen_1A8000, false);
    func_table_register_flags(0x1ABA05, gen_1ABA05, false);
    func_table_register_flags(0x1AC892, gen_1AC892, false);
    func_table_register_flags(0x1AE86A, gen_1AE86A, false);
    func_table_register_flags(0x1AFB6C, gen_1AFB6C, false);
}
