/* Bank $0A recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 40 unlifted in Bank $0A */
/* not lifted: $0A8000: BRK at $0A:8000 */
/* not lifted: $0A8080: BRK at $0A:8086 */
/* not lifted: $0A8100: BRK at $0A:8100 */
/* not lifted: $0A8200: TCS at $8209 with an unknown stack value */
/* not lifted: $0A8300: BRK at $0A:8314 */
/* not lifted: $0A8400: BRK at $0A:8410 */
/* not lifted: $0A8500: BRK at $0A:8510 */
/* not lifted: $0A8A0A: BRK at $0A:8A12 */
/* not lifted: $0A8AAB: BRK at $0A:8AB0 */
/* not lifted: $0AA09E: BRK at $0A:A0A1 */
/* not lifted: $0AA28A: BRK at $0A:A291 */
/* not lifted: $0AA404: BRK at $0A:A404 */
/* not lifted: $0AAA2A: BRK at $0A:AA3F */
/* not lifted: $0AAA8A: BRK at $0A:AA9D */
/* not lifted: $0AAAA2: COP at $0A:AAB0 */
/* not lifted: $0AAAA8: COP at $0A:AAB0 */
/* not lifted: $0AAAAA: COP at $0A:AAB0 */
/* not lifted: $0AB0F0: BRK at $0A:B0F0 */
/* not lifted: $0AB13E: BRK at $0A:B151 */
/* not lifted: $0ABA05: BRK at $0A:BA0C */
/* not lifted: $0AC080: BRK at $0A:C084 */
/* not lifted: $0AC718: BRK at $0A:C71E */
/* not lifted: $0AC892: TXS at $0A:C8EA */
/* not lifted: $0AD82F: XCE at $0A:D82F */
/* not lifted: $0AD8FF: XCE at $0A:D90A */
/* not lifted: $0ADC10: BRK at $0A:DC10 */
/* not lifted: $0ADCFF: BRK at $0A:DD01 */
/* not lifted: $0ADDFE: BRK at $0A:DDFE */
/* not lifted: $0AE237: WAI at $0A:E246 */
/* not lifted: $0AE82F: BRK at $0A:E82F */
/* not lifted: $0AE86A: BRK at $0A:E86A */
/* not lifted: $0AEF00: BRK at $0A:EF06 */
/* not lifted: $0AF0C0: BRK at $0A:F0C7 */
/* not lifted: $0AF1FF: BRK at $0A:F1FF */
/* not lifted: $0AFB6C: BRK at $0A:FB6C */
/* not lifted: $0AFE0F: BRK at $0A:FE4D */
/* not lifted: $0AFF07: BRK at $0A:FF11 */
/* not lifted: $0AFF68: BRK at $0A:FF68 */
/* not lifted: $0AFF7B: BRK at $0A:FF7E */
/* not lifted: $0AFF85: BRK at $0A:FF8E */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $0AC005, entered with P=$10 via JSR */
void gen_0AC005(void) {
    goto L_C005;
L_C005:;
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C ^ g_rd16(g_longx(0x8F6080u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* C005 EOR */
    recomp_tick(14); return;  /* C009 RTS */
}

/* $0AFF20, entered with P=$10 via JSR */
void gen_0AFF20(void) {
    goto L_FF20;
L_FF20:;
    recomp_tick(40); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_abs(0x18CB))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FF20 AND */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dpiy(0x2D)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FF23 LDA */
    recomp_tick(48); { uint16_t _v = (uint16_t)(g_cpu.C & g_rd16(g_longx(0x2D7236u))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FF25 AND */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x9F56)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FF29 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dpil(0x13))));  /* FF2C ADC */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpiy(0xE5))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FF2E ORA */
    recomp_tick(56); { uint32_t _e = g_abs(0x5105); uint16_t _v = g_rd16(_e); g_cpu.flag_Z = (g_cpu.C & _v) == 0; g_wr16(_e, (uint16_t)(_v & ~g_cpu.C)); }  /* FF30 TRB */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_sriy(0x5E))));  /* FF33 ADC */
    recomp_tick(48); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_longx(0x40C67Fu))));  /* FF35 SBC */
    recomp_tick(16); ;  /* FF39 WDM */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dpxi(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FF3B ORA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dpil(0x00))));  /* FF3D SBC */
    recomp_tick(14); return;  /* FF3F RTL */
}

void gen_register_bank_0A(void) {
    func_table_register_flags(0x0AC005, gen_0AC005, false);
    func_table_register_flags(0x0AFF20, gen_0AFF20, false);
}
