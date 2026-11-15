/* Bank $0D recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 65 unlifted in Bank $0D */
/* not lifted: $0D828A: BRK at $0D:82A5 */
/* not lifted: $0D85EE: WAI at $0D:862B */
/* not lifted: $0D8A8A: BRK at $0D:8AA8 */
/* not lifted: $0D8AAA: BRK at $0D:8ACE */
/* not lifted: $0D9AC0: STP at $0D:9AC3 */
/* not lifted: $0D9AF1: BRK at $0D:9AF8 */
/* not lifted: $0D9CDC: WAI at $0D:9CF8 */
/* not lifted: $0DA000: PLB at $A002 pulls below the entry stack (return-address trick) */
/* not lifted: $0DA010: BRK at $0D:A010 */
/* not lifted: $0DA012: BRK at $0D:A012 */
/* not lifted: $0DA01D: tail jump at $A082 with 2 bytes pushed */
/* not lifted: $0DA228: COP at $0D:A2A3 */
/* not lifted: $0DA2AA: calls RAM trampoline/sub-8000 ($1D34CD): executes native on LakeSnes */
/* not lifted: $0DA2DF: COP at $0D:A32F */
/* not lifted: $0DA4A9: BRK at $0D:A4DE */
/* not lifted: $0DA611: BRK at $0D:A61C */
/* not lifted: $0DA88B: tail jump at $A8E9 with 4 bytes pushed */
/* not lifted: $0DA8A8: $0D:A8A8 reached with two different M/X/stack states */
/* not lifted: $0DA8AA: $0D:A8B5 reached with two different M/X/stack states */
/* not lifted: $0DA9EA: XCE at $0D:AA71 */
/* not lifted: $0DAA13: BRK at $0D:AA40 */
/* not lifted: $0DAA28: BRK at $0D:AA40 */
/* not lifted: $0DAA2A: BRK at $0D:AA37 */
/* not lifted: $0DAA82: BRK at $0D:AACC */
/* not lifted: $0DAA88: BRK at $0D:AACC */
/* not lifted: $0DAA8A: BRK at $0D:AACC */
/* not lifted: $0DAA8B: BRK at $0D:AACC */
/* not lifted: $0DAA8E: BRK at $0D:AACC */
/* not lifted: $0DAAA2: BRK at $0D:AACC */
/* not lifted: $0DAAA8: BRK at $0D:AACC */
/* not lifted: $0DAAAA: BRK at $0D:AACC */
/* not lifted: $0DAAAB: BRK at $0D:AACC */
/* not lifted: $0DAAAC: BRK at $0D:AACC */
/* not lifted: $0DAABA: BRK at $0D:AACC */
/* not lifted: $0DAABE: BRK at $0D:AACC */
/* not lifted: $0DAAC8: BRK at $0D:AACC */
/* not lifted: $0DAACC: BRK at $0D:AACC */
/* not lifted: $0DAAE2: BRK at $0D:AB2E */
/* not lifted: $0DAAE8: BRK at $0D:AB2E */
/* not lifted: $0DAAEA: BRK at $0D:AB2E */
/* not lifted: $0DABAA: COP at $0D:ABB6 */
/* not lifted: $0DAE2A: PLA at $DE12 pulls below the entry stack (return-address trick) */
/* not lifted: $0DAEAA: TCS at $AEE1 with an unknown stack value */
/* not lifted: $0DB020: PLB at $2002 pulls below the entry stack (return-address trick) */
/* not lifted: $0DB0BA: TCS at $B0BE with an unknown stack value */
/* not lifted: $0DB0F1: PLX at $2D26 pulls below the entry stack (return-address trick) */
/* not lifted: $0DBAAA: PLY at $BAB4 pulls below the entry stack (return-address trick) */
/* not lifted: $0DBD04: COP at $0D:BD21 */
/* not lifted: $0DBECB: BRK at $0D:BECB */
/* not lifted: $0DCB0F: BRK at $0D:CBC8 */
/* not lifted: $0DCCED: COP at $0D:CCF5 */
/* not lifted: $0DD1C3: BRK at $0D:D16F */
/* not lifted: $0DDA8A: COP at $0D:DA93 */
/* not lifted: $0DDB10: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $0DDF20: calls unlifted target 0x5DD155: executes native on LakeSnes */
/* not lifted: $0DDFE3: PLB at $E001 pulls below the entry stack (return-address trick) */
/* not lifted: $0DE3D2: PLX at $E3F0 pulls below the entry stack (return-address trick) */
/* not lifted: $0DE8AA: PLB at $E8C8 pulls below the entry stack (return-address trick) */
/* not lifted: $0DEAAA: PLX at $EB12 pulls below the entry stack (return-address trick) */
/* not lifted: $0DEE00: PLB at $76D6 pulls below the entry stack (return-address trick) */
/* not lifted: $0DF0B0: PLD at $1B6C pulls below the entry stack (return-address trick) */
/* not lifted: $0DF44F: STP at $0D:9F2D */
/* not lifted: $0DFB01: PLB at $FB1E pulls below the entry stack (return-address trick) */
/* not lifted: $0DFF3F: PLB at $FF48 pulls below the entry stack (return-address trick) */
/* not lifted: $0DFF7A: PLB at $FFB3 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $0DFFED, entered with P=$10 via JSR */
void gen_0DFFED(void) {
    goto L_FFED;
L_0000:;
    recomp_tick(14); return;  /* 0000 RTI */
L_FFED:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* FFED TAY */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* FFEE TAY */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFEF TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF0 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF1 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.S; g_cpu.X = _v; g_nz8(_v); }  /* FFF2 TSX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF3 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF4 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* FFF5 TAY */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF6 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF7 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF8 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.S; g_cpu.X = _v; g_nz8(_v); }  /* FFF9 TSX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFFA TAX */
    recomp_tick(14); ;  /* FFFB NOP */
    recomp_tick(24); { uint16_t _v = 0xAAAA; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* FFFC LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFFF TAX */
    goto L_0000;
}

/* $0DFFEF, entered with P=$30 via JSR */
void gen_0DFFEF(void) {
    goto L_FFEF;
L_0000:;
    recomp_tick(14); return;  /* 0000 RTI */
L_FFEF:;
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFEF TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF0 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF1 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.S; g_cpu.X = _v; g_nz8(_v); }  /* FFF2 TSX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF3 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF4 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.Y = _v; g_nz8(_v); }  /* FFF5 TAY */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF6 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF7 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFF8 TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.S; g_cpu.X = _v; g_nz8(_v); }  /* FFF9 TSX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFFA TAX */
    recomp_tick(14); ;  /* FFFB NOP */
    recomp_tick(16); { uint8_t _v = 0xAA; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* FFFC LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFFE TAX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* FFFF TAX */
    goto L_0000;
}

void gen_register_bank_0D(void) {
    func_table_register_flags(0x0DFFED, gen_0DFFED, false);
    func_table_register_flags(0x0DFFEF, gen_0DFFEF, false);
}
