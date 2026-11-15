/* Bank $25 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 6 lifted, 42 unlifted in Bank $25 */
/* not lifted: $2581CF: PLX at $F9B3 pulls below the entry stack (return-address trick) */
/* not lifted: $258299: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2583EF: tail jump at $898B with 1 bytes pushed */
/* not lifted: $258C7A: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $258CA2: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $259261: PLA at $9261 pulls below the entry stack (return-address trick) */
/* not lifted: $2592B4: PLY at $92C4 pulls below the entry stack (return-address trick) */
/* not lifted: $25942D: XCE at $25:E817 */
/* not lifted: $2594FA: STP at $25:955B */
/* not lifted: $25953D: STP at $25:955B */
/* not lifted: $259565: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $259598: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $2595A8: XCE at $25:95B6 */
/* not lifted: $2595CE: tail jump at $43FA with 2 bytes pushed */
/* not lifted: $2595FE: tail jump at $43FA with 2 bytes pushed */
/* not lifted: $25993B: BRK at $25:996A */
/* not lifted: $259A68: TCS at $8E7F with an unknown stack value */
/* not lifted: $259A7C: BRK at $25:9A93 */
/* not lifted: $259E55: PLA at $9E6F pulls below the entry stack (return-address trick) */
/* not lifted: $259ECC: RTI at $9ED9 with 1 bytes still pushed */
/* not lifted: $259F2D: tail jump at $9F62 with 2 bytes pushed */
/* not lifted: $259F54: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $25A8E1: COP at $25:A90B */
/* not lifted: $25A9B5: TCS at $A9B7 with an unknown stack value */
/* not lifted: $25A9C6: BRK at $25:A9C8 */
/* not lifted: $25AA7F: PLY at $AA81 pulls below the entry stack (return-address trick) */
/* not lifted: $25AA89: PLP at $AA97 pulls below the entry stack (return-address trick) */
/* not lifted: $25AA99: RTI at $AAB3 with 1 bytes still pushed */
/* not lifted: $25AAC3: COP at $25:AACD */
/* not lifted: $25AB80: PLD at $AB88 pulls below the entry stack (return-address trick) */
/* not lifted: $25AB8F: COP at $25:AC19 */
/* not lifted: $25ABDD: COP at $25:AC19 */
/* not lifted: $25ABEA: COP at $25:AC19 */
/* not lifted: $25AC12: COP at $25:AC19 */
/* not lifted: $25AC6C: PLX at $AC7A pulls below the entry stack (return-address trick) */
/* not lifted: $25BAAC: tail jump at $BAF3 with 3 bytes pushed */
/* not lifted: $25BF5A: RTI at $BF8E with 1 bytes still pushed */
/* not lifted: $25C059: BRK at $25:5C0E */
/* not lifted: $25C0AD: PLP at $C0CC pulls below the entry stack (return-address trick) */
/* not lifted: $25C0FF: COP at $25:C13A */
/* not lifted: $25C8C8: STP at $25:C963 */
/* not lifted: $25FFA9: indirect jump table dispatch: executes native on LakeSnes */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $25822F, entered with P=$20 via JSR */
void gen_25822F(void) {
    goto L_822F;
L_8216:;
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8216 INX */
    recomp_tick(16); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, 0xEB)));  /* 8217 SBC */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_longx(0xC0CAEDu)))));  /* 8219 SBC */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x4C7D);  /* 821D CPY */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_sr(0x01))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8220 EOR */
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(0x4A4B42u))));  /* 8222 SBC */
    recomp_tick(32); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_abs(0xED07))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8226 EOR */
    recomp_tick(32); g_cmp8((uint8_t)g_cpu.C, g_rd8(g_abs(0xD1CE)));  /* 8229 CMP */
    recomp_tick(32); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_absx(0x07D2)))));  /* 822C SBC */
L_822F:;
    recomp_tick(40); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(0x32C034u))));  /* 822F SBC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpiy(0x7E))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8233 AND */
    recomp_tick(16); if (g_cpu.flag_N) goto L_8216;  /* 8235 BMI */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpily(0x38))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8237 AND */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_sriy(0x80))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8239 AND */
    recomp_tick(24); g_wr8(g_sr(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* 823B STA */
    recomp_tick(32); { uint32_t _e = g_dpx(0x7D); uint8_t _v = (uint8_t)(g_rd8(_e) + 1); g_wr8(_e, _v); g_nz8(_v); }  /* 823D INC */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C ^ g_rd8(g_dpil(0x5F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 823F EOR */
    recomp_tick(14); return;  /* 8241 RTI */
}

/* $258241, entered with P=$20 via JSR */
void gen_258241(void) {
    goto L_8241;
L_8241:;
    recomp_tick(14); return;  /* 8241 RTI */
}

/* $259E11, entered with P=$20 via JSR */
void gen_259E11(void) {
    goto L_9E11;
L_9E11:;
    recomp_tick(14); { uint8_t _v = g_ror8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* 9E11 ROR */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x01)));  /* 9E12 ADC */
    recomp_tick(14); return;  /* 9E14 RTI */
}

/* $259F97, entered with P=$20 via JSR */
void gen_259F97(void) {
    goto L_9F97;
L_9F97:;
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x2F); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9F97 AND */
    recomp_tick(14); return;  /* 9F99 RTL */
}

/* $259FCE, entered with P=$20 via JSR */
void gen_259FCE(void) {
    goto L_9FCE;
L_9FCE:;
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0x6F))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 9FCE ORA */
    recomp_tick(24); g_seta8((uint8_t)(g_sbc8((uint8_t)g_cpu.C, g_rd8(g_dpil(0xC8)))));  /* 9FD0 SBC */
    recomp_tick(24); g_cmp16((uint16_t)g_cpu.Y, 0x76C0);  /* 9FD2 CPY */
    recomp_tick(24); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, g_rd8(g_dpily(0x1F)))));  /* 9FD5 ADC */
    recomp_tick(14); return;  /* 9FD7 RTI */
}

/* $25AA52, entered with P=$20 via JSR */
void gen_25AA52(void) {
    goto L_AA52;
L_AA52:;
    recomp_tick(32); g_wr8(g_absx(0xDA17), (uint8_t)(uint8_t)g_cpu.C);  /* AA52 STA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpil(0x94))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA55 AND */
    recomp_tick(32); { uint32_t _e = g_dpx(0xFB); uint8_t _v = g_asl8(g_rd8(_e)); g_wr8(_e, _v); }  /* AA57 ASL */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(g_dpil(0xC1))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA59 ORA */
    recomp_tick(40); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C | g_rd8(0xAD0F80u)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA5B ORA */
    recomp_tick(24); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & g_rd8(g_dpil(0xE2))); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* AA5F AND */
    recomp_tick(14); return;  /* AA61 RTS */
}

void gen_register_bank_25(void) {
    func_table_register_flags(0x25822F, gen_25822F, false);
    func_table_register_flags(0x258241, gen_258241, false);
    func_table_register_flags(0x259E11, gen_259E11, false);
    func_table_register_flags(0x259F97, gen_259F97, false);
    func_table_register_flags(0x259FCE, gen_259FCE, false);
    func_table_register_flags(0x25AA52, gen_25AA52, false);
}
