/* Bank $3D recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 2 lifted, 62 unlifted in Bank $3D */
/* not lifted: $3D828A: BRK at $3D:82A5 */
/* not lifted: $3D85EE: WAI at $3D:862B */
/* not lifted: $3D8A8A: BRK at $3D:8AA8 */
/* not lifted: $3D8AAA: BRK at $3D:8ACE */
/* not lifted: $3D9AC0: STP at $3D:9AC3 */
/* not lifted: $3D9AF1: BRK at $3D:9AF8 */
/* not lifted: $3D9CDC: WAI at $3D:9CF8 */
/* not lifted: $3DA000: PLB at $A002 pulls below the entry stack (return-address trick) */
/* not lifted: $3DA010: BRK at $3D:A010 */
/* not lifted: $3DA012: BRK at $3D:A012 */
/* not lifted: $3DA01D: tail jump at $A082 with 2 bytes pushed */
/* not lifted: $3DA228: COP at $3D:A2A3 */
/* not lifted: $3DA2AA: calls RAM trampoline/sub-8000 ($1D34CD): executes native on LakeSnes */
/* not lifted: $3DA2DF: COP at $3D:A32F */
/* not lifted: $3DA611: BRK at $3D:A61C */
/* not lifted: $3DA88B: tail jump at $A8E9 with 4 bytes pushed */
/* not lifted: $3DA8A8: $3D:A8A8 reached with two different M/X/stack states */
/* not lifted: $3DA8AA: $3D:A8B5 reached with two different M/X/stack states */
/* not lifted: $3DA9EA: XCE at $3D:AA71 */
/* not lifted: $3DAA13: BRK at $3D:AA40 */
/* not lifted: $3DAA28: XCE at $3D:AA71 */
/* not lifted: $3DAA2A: BRK at $3D:AA37 */
/* not lifted: $3DAA82: BRK at $3D:AACC */
/* not lifted: $3DAA88: BRK at $3D:AACC */
/* not lifted: $3DAA8A: BRK at $3D:AACC */
/* not lifted: $3DAA8B: BRK at $3D:AACC */
/* not lifted: $3DAAA2: BRK at $3D:AACC */
/* not lifted: $3DAAA8: BRK at $3D:AACC */
/* not lifted: $3DAAAA: BRK at $3D:AACC */
/* not lifted: $3DAAAB: BRK at $3D:AACC */
/* not lifted: $3DAAAC: BRK at $3D:AACC */
/* not lifted: $3DAABA: BRK at $3D:AACC */
/* not lifted: $3DAABE: BRK at $3D:AACC */
/* not lifted: $3DAACC: BRK at $3D:AACC */
/* not lifted: $3DAAE2: BRK at $3D:AB2E */
/* not lifted: $3DAAE8: BRK at $3D:AB2E */
/* not lifted: $3DAAEA: BRK at $3D:AB2E */
/* not lifted: $3DABAA: COP at $3D:ABB6 */
/* not lifted: $3DAE2A: PLA at $DE12 pulls below the entry stack (return-address trick) */
/* not lifted: $3DAEAA: TCS at $AEE1 with an unknown stack value */
/* not lifted: $3DB020: PLB at $2002 pulls below the entry stack (return-address trick) */
/* not lifted: $3DB0F1: PLX at $2D26 pulls below the entry stack (return-address trick) */
/* not lifted: $3DBAAA: PLY at $BAB4 pulls below the entry stack (return-address trick) */
/* not lifted: $3DBECB: BRK at $3D:BECB */
/* not lifted: $3DCB0F: BRK at $3D:CBC8 */
/* not lifted: $3DCCED: COP at $3D:CCF5 */
/* not lifted: $3DD0B4: TCS at $D0ED with an unknown stack value */
/* not lifted: $3DD1C3: BRK at $3D:D16F */
/* not lifted: $3DDA8A: COP at $3D:DA93 */
/* not lifted: $3DDB10: calls RAM trampoline/sub-8000 ($C13EC0): executes native on LakeSnes */
/* not lifted: $3DDF20: calls unlifted target 0x5DD155: executes native on LakeSnes */
/* not lifted: $3DDFE3: PLB at $E001 pulls below the entry stack (return-address trick) */
/* not lifted: $3DE3D2: PLX at $E3F0 pulls below the entry stack (return-address trick) */
/* not lifted: $3DE8AA: PLB at $E8C8 pulls below the entry stack (return-address trick) */
/* not lifted: $3DEAAA: PLX at $EB12 pulls below the entry stack (return-address trick) */
/* not lifted: $3DEE00: PLB at $76D6 pulls below the entry stack (return-address trick) */
/* not lifted: $3DF0B0: PLD at $1B6C pulls below the entry stack (return-address trick) */
/* not lifted: $3DF364: PLB at $F36F pulls below the entry stack (return-address trick) */
/* not lifted: $3DF44F: STP at $3D:9F2D */
/* not lifted: $3DFB01: PLB at $FB1E pulls below the entry stack (return-address trick) */
/* not lifted: $3DFF3F: PLB at $FF48 pulls below the entry stack (return-address trick) */
/* not lifted: $3DFF7A: PLB at $FFB3 pulls below the entry stack (return-address trick) */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $3DFFED, entered with P=$10 via JSR */
void gen_3DFFED(void) {
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

/* $3DFFEF, entered with P=$30 via JSR */
void gen_3DFFEF(void) {
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

void gen_register_bank_3D(void) {
    func_table_register_flags(0x3DFFED, gen_3DFFED, false);
    func_table_register_flags(0x3DFFEF, gen_3DFFEF, false);
}
