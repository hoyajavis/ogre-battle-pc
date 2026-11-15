/* Bank $00 recompiled routines for Ogre Battle: The March of the Black Queen.
 * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */

/* Statistics: 11 lifted, 308 unlifted in Bank $00 */
/* not lifted: $008000: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008009: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00809E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0080C6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008146: calls unlifted target 0x0083E1: executes native on LakeSnes */
/* not lifted: $00827D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0082AA: BRK at $00:82A5 */
/* not lifted: $008386: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083BE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083C8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083D5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083E1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0083F2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00844E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008470: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0084A2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00855D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0085B7: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00867B: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $008782: calls unlifted target 0x0085B7: executes native on LakeSnes */
/* not lifted: $0087BD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008803: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00883A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00889F: BRK at $00:88B8 */
/* not lifted: $008914: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008AA2: STP at $00:8AC3 */
/* not lifted: $008AAA: STP at $00:8AC3 */
/* not lifted: $008B43: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008BAA: BRK at $00:8BCD */
/* not lifted: $008D6D: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $008D9E: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $008DD2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008DE3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008DFB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008E22: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $008E62: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0090B0: BRK at $00:90B0 */
/* not lifted: $00966F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0096C8: BRK at $00:96C8 */
/* not lifted: $0096FB: BRK at $00:96FE */
/* not lifted: $009795: COP at $00:97FE */
/* not lifted: $00981D: COP at $00:9824 */
/* not lifted: $009843: WAI at $00:987D */
/* not lifted: $009893: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $0099F4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009A0E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009A55: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009A6C: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $009A95: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B03: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B04: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B21: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B45: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B58: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009B5F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BC2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BC5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BC8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BCB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BCE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BD1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BD4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BD7: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BDA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BDD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BE9: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BEC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BEF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BF2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BF5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BF8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BFB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009BFE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C01: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C04: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C07: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C0A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C0D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C10: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C13: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C16: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C19: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C1C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C1F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C22: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C23: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009C6C: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $009CC4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E7B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E86: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E87: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E93: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009E9B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EA2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EAA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EB6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EC2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009ED1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009EE0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F0F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F1E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F3C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F6B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009F8B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $009FBD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A00D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A024: $00:A0B3 reached with two different M/X/stack states */
/* not lifted: $00A088: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A0E3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A0EC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A0F2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A113: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A125: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A18C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A22A: BRK at $00:A22A */
/* not lifted: $00A28A: BRK at $00:A291 */
/* not lifted: $00A2A2: $00:A2AE reached with two different M/X/stack states */
/* not lifted: $00A2AA: $00:A2AA reached with two different M/X/stack states */
/* not lifted: $00A2BD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A2CA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A2DC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A2EE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A30A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A44A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A456: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A468: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A5B7: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $00A5C4: RTS at $A6B8 with 1 bytes still pushed */
/* not lifted: $00A5D6: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $00A5E8: RTS at $A6B8 with 1 bytes still pushed */
/* not lifted: $00A604: calls unlifted target 0x009C23: executes native on LakeSnes */
/* not lifted: $00A6D1: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A6DF: calls unlifted target 0x00A6F8: executes native on LakeSnes */
/* not lifted: $00A6F8: TXS at $00:A739 */
/* not lifted: $00A773: calls unlifted target 0x00A789: executes native on LakeSnes */
/* not lifted: $00A789: TXS at $00:A7D3 */
/* not lifted: $00A80D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A82B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A831: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A83B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A83F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A845: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A862: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A868: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A87B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A888: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A88C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A898: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A8A2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A8AA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A8AF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00A909: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00A940: calls unlifted target 0x00F5D2: executes native on LakeSnes */
/* not lifted: $00AA0C: BRK at $00:AA0C */
/* not lifted: $00AA1F: calls unlifted target 0x00DED6: executes native on LakeSnes */
/* not lifted: $00AA2A: BRK at $00:AA2E */
/* not lifted: $00AA52: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AA5F: PLA at $AA69 pulls below the entry stack (return-address trick) */
/* not lifted: $00AA60: BRK at $00:AA7A */
/* not lifted: $00AA88: BRK at $00:AA95 */
/* not lifted: $00AA8A: BRK at $00:AA95 */
/* not lifted: $00AA9D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA5: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAA8: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAAA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAAB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AAEA: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AB01: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ACD2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ACD3: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00AD13: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AEAE: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00AEF4: calls unlifted target 0x00B7C0: executes native on LakeSnes */
/* not lifted: $00AF03: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AF33: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AF5C: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00AF87: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00AFBA: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00B020: BRK at $00:B022 */
/* not lifted: $00B041: calls unlifted target 0x00CE64: executes native on LakeSnes */
/* not lifted: $00B154: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00B16F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00B1E0: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00B282: calls unlifted target 0x00CADA: executes native on LakeSnes */
/* not lifted: $00B399: calls unlifted target 0x00D32F: executes native on LakeSnes */
/* not lifted: $00B457: calls unlifted target 0x00C755: executes native on LakeSnes */
/* not lifted: $00B47C: calls unlifted target 0x00B6A8: executes native on LakeSnes */
/* not lifted: $00B4C6: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00B542: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00B56E: BRK at $00:B56F */
/* not lifted: $00B590: calls unlifted target 0x00B64A: executes native on LakeSnes */
/* not lifted: $00B5FD: calls unlifted target 0x00B64A: executes native on LakeSnes */
/* not lifted: $00B64A: calls unlifted target 0x00867B: executes native on LakeSnes */
/* not lifted: $00B6A8: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00B77A: calls unlifted target 0x00DF16: executes native on LakeSnes */
/* not lifted: $00B7C0: $00:B83F reached with two different M/X/stack states */
/* not lifted: $00B8B3: calls unlifted target 0x00F5E6: executes native on LakeSnes */
/* not lifted: $00B8FA: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00B931: calls unlifted target 0x00C980: executes native on LakeSnes */
/* not lifted: $00B97D: calls unlifted target 0x00CC03: executes native on LakeSnes */
/* not lifted: $00B9AB: DMA transfer / trigger routine: executes native on LakeSnes */
/* not lifted: $00BA22: PLX at $BA17 pulls below the entry stack (return-address trick) */
/* not lifted: $00BA28: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00BACA: COP at $00:BACA */
/* not lifted: $00BB69: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00BB84: calls unlifted target 0x0085B7: executes native on LakeSnes */
/* not lifted: $00BC22: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00BCAA: calls unlifted target 0x00D4FE: executes native on LakeSnes */
/* not lifted: $00BDAA: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $00C0BC: BRK at $00:C0CC */
/* not lifted: $00C11B: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $00C48C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00C50F: BRK at $00:C54E */
/* not lifted: $00C558: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00C5C5: calls unlifted target 0x00C5EC: executes native on LakeSnes */
/* not lifted: $00C5EC: calls unlifted target 0x00A18C: executes native on LakeSnes */
/* not lifted: $00C614: calls unlifted target 0x00A18C: executes native on LakeSnes */
/* not lifted: $00C619: BRK at $00:C623 */
/* not lifted: $00C635: calls unlifted target 0x009A55: executes native on LakeSnes */
/* not lifted: $00C6A7: calls unlifted target 0x009A55: executes native on LakeSnes */
/* not lifted: $00C755: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00C774: calls unlifted target 0x008B43: executes native on LakeSnes */
/* not lifted: $00C980: calls unlifted target 0x00966F: executes native on LakeSnes */
/* not lifted: $00C9E8: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CA6E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00CADA: calls unlifted target 0x00966F: executes native on LakeSnes */
/* not lifted: $00CB22: calls unlifted target 0x00889F: executes native on LakeSnes */
/* not lifted: $00CBAE: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CC03: calls unlifted target 0x008782: executes native on LakeSnes */
/* not lifted: $00CC4C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00CCFD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00CDBD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00CE64: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00CF3A: calls unlifted target 0x009893: executes native on LakeSnes */
/* not lifted: $00D32F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D386: calls unlifted target 0x00D394: executes native on LakeSnes */
/* not lifted: $00D394: calls unlifted target 0x00D4BD: executes native on LakeSnes */
/* not lifted: $00D4BD: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00D4FE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D5B3: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D620: BRK at $00:D62D */
/* not lifted: $00D6A1: calls unlifted target 0x009893: executes native on LakeSnes */
/* not lifted: $00D776: calls unlifted target 0x00A0EC: executes native on LakeSnes */
/* not lifted: $00D791: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D7C5: calls unlifted target 0x00F5D2: executes native on LakeSnes */
/* not lifted: $00D7FC: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D867: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D95B: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00D979: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00DBAF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DC89: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DDB2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DE0D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DEBE: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DED6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DEE6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DF16: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DF4C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00DF54: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00DFF5: Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes */
/* not lifted: $00E01A: $00:E128 reached with two different M/X/stack states */
/* not lifted: $00E12B: calls unlifted target 0x00E3CD: executes native on LakeSnes */
/* not lifted: $00E181: calls RAM trampoline/sub-8000 ($001199): executes native on LakeSnes */
/* not lifted: $00E228: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00E235: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00E240: calls unlifted target 0x00E181: executes native on LakeSnes */
/* not lifted: $00E29D: RTS at $E2AD with 2 bytes still pushed */
/* not lifted: $00E2AA: RTS at $E2AD with 1 bytes still pushed */
/* not lifted: $00E3CD: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00E538: PLX at $E567 pulls below the entry stack (return-address trick) */
/* not lifted: $00E56C: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00EA2A: $00:A5A8 reached with two different M/X/stack states */
/* not lifted: $00EAAA: BRK at $00:EAB6 */
/* not lifted: $00EB50: $00:A5A8 reached with two different M/X/stack states */
/* not lifted: $00EC23: calls unlifted target 0x00ECA6: executes native on LakeSnes */
/* not lifted: $00EC7F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00EC97: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ECA6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00ECB5: calls unlifted target 0x00ECA6: executes native on LakeSnes */
/* not lifted: $00EDA8: $00:A5A8 reached with two different M/X/stack states */
/* not lifted: $00EFEF: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F00F: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F087: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F122: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F1CB: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F1F4: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F24E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F26C: indirect jump table dispatch: executes native on LakeSnes */
/* not lifted: $00F3E0: calls unlifted target 0x009893: executes native on LakeSnes */
/* not lifted: $00F423: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F46D: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F5D2: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F5E6: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F65E: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F790: $00:F7FC reached with two different M/X/stack states */
/* not lifted: $00F801: calls unlifted target 0x00F866: executes native on LakeSnes */
/* not lifted: $00F85A: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F866: hardware timing / wait loop (executes genuine on LakeSnes) */
/* not lifted: $00F87D: tail jump at $F8BB with 3 bytes pushed */
/* not lifted: $00FAA2: COP at $00:FAA2 */
/* not lifted: $00FAAA: PLB at $FB3E pulls below the entry stack (return-address trick) */
/* not lifted: $00FFBF: BRK at $00:FFBF */
/* not lifted: $00FFFF: TXS at $00:0011 */

#include <snesrecomp/snesrecomp.h>
#include <snesrecomp/gen_ops.h>
#include "ob_recomp.h"

#if defined(_MSC_VER)
#pragma warning(disable: 4102)
#endif

/* $008202, entered with P=$20 via JSR */
void gen_008202(void) {
    goto L_8202;
L_8202:;
    recomp_tick(24); { uint16_t _v = 0x0006; g_cpu.Y = _v; g_nz16(_v); }  /* 8202 LDY */
    recomp_tick(16); g_cmp8((uint8_t)g_cpu.C, 0x00);  /* 8205 CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8212;  /* 8207 BEQ */
    recomp_tick(24); { uint16_t _v = 0x0AB0; g_cpu.Y = _v; g_nz16(_v); }  /* 8209 LDY */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C - 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 820C DEC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8212;  /* 820D BEQ */
    recomp_tick(24); { uint16_t _v = 0x155A; g_cpu.Y = _v; g_nz16(_v); }  /* 820F LDY */
L_8212:;
    recomp_tick(32); g_wr16(g_dp(0x03), (uint16_t)g_cpu.Y);  /* 8212 STY */
    recomp_tick(16); { uint8_t _v = 0x70; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8214 LDA */
    recomp_tick(24); g_wr8(g_dp(0x05), (uint8_t)(uint8_t)g_cpu.C);  /* 8216 STA */
    recomp_tick(16); { uint8_t _v = 0x7E; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8218 LDA */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)(uint8_t)g_cpu.C);  /* 821A STA */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.X = _v; g_nz16(_v); }  /* 821C LDX */
    recomp_tick(16); g_rep(0x20);  /* 821F REP */
L_8221:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x82C0)); g_cpu.Y = _v; g_nz16(_v); }  /* 8221 LDY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_827A;  /* 8224 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8226 INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 8227 INX */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x82C0)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8228 LDA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* 822B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 822D INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.X + 1); g_cpu.X = _v; g_nz16(_v); }  /* 822E INX */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 822F TYA */
    recomp_tick(16); if (g_cpu.flag_N) goto L_824D;  /* 8230 BMI */
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.Y);  /* 8232 STY */
    recomp_tick(24); { uint16_t _v = 0x0000; g_cpu.Y = _v; g_nz16(_v); }  /* 8234 LDY */
    recomp_tick(16); g_sep(0x20);  /* 8237 SEP */
L_8239:;
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpily(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8239 LDA */
    recomp_tick(24); g_wr8(g_dpily(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 823B STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y + 1); g_cpu.Y = _v; g_nz16(_v); }  /* 823D INY */
    recomp_tick(32); g_cmp16((uint16_t)g_cpu.Y, g_rd16(g_dp(0x06)));  /* 823E CPY */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_8239;  /* 8240 BCC */
    recomp_tick(16); g_rep(0x20);  /* 8242 REP */
    recomp_tick(14); g_cpu.flag_C = false;  /* 8244 CLC */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x03)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8245 LDA */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x06))));  /* 8247 ADC */
    recomp_tick(32); g_wr16(g_dp(0x03), (uint16_t)g_cpu.C);  /* 8249 STA */
    recomp_tick(16); goto L_8221;  /* 824B BRA */
L_824D:;
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x7FFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 824D AND */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.Y = _v; g_nz16(_v); }  /* 8250 TAY */
L_8251:;
    recomp_tick(16); g_sep(0x20);  /* 8251 SEP */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8253 LDA */
    recomp_tick(24); g_wr8(g_dp(0x06), (uint8_t)(uint8_t)g_cpu.C);  /* 8255 STA */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dpil(0x03)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* 8257 LDA */
    recomp_tick(24); g_wr8(g_dp(0x07), (uint8_t)(uint8_t)g_cpu.C);  /* 8259 STA */
    recomp_tick(16); g_rep(0x20);  /* 825B REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x03); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 825D INC */
L_825F:;
    recomp_tick(48); { uint32_t _e = g_dp(0x06); uint16_t _v = g_asl16(g_rd16(_e)); g_wr16(_e, _v); }  /* 825F ASL */
    recomp_tick(16); g_sep(0x20);  /* 8261 SEP */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* 8263 TDC */
    recomp_tick(16); g_seta8((uint8_t)(g_adc8((uint8_t)g_cpu.C, 0x00)));  /* 8264 ADC */
    recomp_tick(24); g_wr8(g_dpil(0x00), (uint8_t)(uint8_t)g_cpu.C);  /* 8266 STA */
    recomp_tick(16); g_rep(0x20);  /* 8268 REP */
    recomp_tick(48); { uint32_t _e = g_dp(0x00); uint16_t _v = (uint16_t)(g_rd16(_e) + 1); g_wr16(_e, _v); g_nz16(_v); }  /* 826A INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.Y - 1); g_cpu.Y = _v; g_nz16(_v); }  /* 826C DEY */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_8278;  /* 826D BEQ */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 826F LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* 8271 AND */
    recomp_tick(16); if (!g_cpu.flag_Z) goto L_825F;  /* 8274 BNE */
    recomp_tick(16); goto L_8251;  /* 8276 BRA */
L_8278:;
    recomp_tick(16); goto L_8221;  /* 8278 BRA */
L_827A:;
    recomp_tick(16); g_sep(0x20);  /* 827A SEP */
    recomp_tick(14); return;  /* 827C RTS */
}

/* $009709, entered with P=$20 via JSR */
void gen_009709(void) {
    goto L_9709;
L_9709:;
    recomp_tick(14); return;  /* 9709 RTS */
}

/* $00A37A, entered with P=$00 via JSR */
void gen_00A37A(void) {
    goto L_A37A;
L_A37A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A37A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* A37C SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0400));  /* A37D SBC */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* A380 STA */
    recomp_tick(14); return;  /* A382 RTS */
}

/* $00A383, entered with P=$00 via JSR */
void gen_00A383(void) {
    goto L_A383;
L_A37A:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x0E)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A37A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* A37C SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0400));  /* A37D SBC */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* A380 STA */
    recomp_tick(14); return;  /* A382 RTS */
L_A383:;
    recomp_tick(16); g_sep(0x20);  /* A383 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A385 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A387 INC */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A388 AND */
    recomp_tick(24); g_wr8(g_dp(0x0D), (uint8_t)(uint8_t)g_cpu.C);  /* A38A STA */
    recomp_tick(16); g_rep(0x20);  /* A38C REP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_A37A;  /* A38E BEQ */
    recomp_tick(14); return;  /* A390 RTS */
}

/* $00A391, entered with P=$00 via JSR */
void gen_00A391(void) {
    goto L_A391;
L_A391:;
    recomp_tick(16); g_sep(0x20);  /* A391 SEP */
    recomp_tick(24); { uint8_t _v = g_rd8(g_dp(0x0D)); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A393 LDA */
    recomp_tick(14); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C + 1); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A395 INC */
    recomp_tick(16); { uint8_t _v = (uint8_t)((uint8_t)g_cpu.C & 0x01); g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* A396 AND */
    recomp_tick(24); g_wr8(g_dp(0x0D), (uint8_t)(uint8_t)g_cpu.C);  /* A398 STA */
    recomp_tick(14); { uint8_t _v = g_lsr8((uint8_t)g_cpu.C); g_seta8((uint8_t)(_v)); }  /* A39A LSR */
    recomp_tick(16); g_rep(0x20);  /* A39B REP */
    recomp_tick(24); { uint16_t _v = 0x0400; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A39D LDA */
    recomp_tick(16); if (g_cpu.flag_C) goto L_A3A5;  /* A3A0 BCS */
    recomp_tick(24); { uint16_t _v = 0xF400; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* A3A2 LDA */
L_A3A5:;
    recomp_tick(14); g_cpu.flag_C = false;  /* A3A5 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x0E))));  /* A3A6 ADC */
    recomp_tick(32); g_wr16(g_dp(0x0E), (uint16_t)g_cpu.C);  /* A3A8 STA */
    recomp_tick(14); return;  /* A3AA RTS */
}

/* $00BA75, entered with P=$30 via JSR */
void gen_00BA75(void) {
    goto L_BA75;
L_BA75:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)g_cpu.X);  /* BA75 STX */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)g_cpu.Y);  /* BA77 STY */
    recomp_tick(16); g_rep(0x20);  /* BA79 REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA7B TXA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BA7C SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BA7D SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA83;  /* BA80 BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA82 TDC */
L_BA83:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* BA83 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA85 TYA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BA86 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BA87 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BA8D;  /* BA8A BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BA8C TDC */
L_BA8D:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* BA8D STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1603)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA8F LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA92 DEC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA93 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BA96 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* BA97 TAX */
L_BA98:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1A99)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BA98 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* BA9B CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BAA1;  /* BA9D BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BABD;  /* BA9F BCS */
L_BAA1:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* BAA1 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BABD;  /* BAA3 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BABD;  /* BAA5 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1B11)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAA7 LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x02)));  /* BAAA CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BAB0;  /* BAAC BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BABD;  /* BAAE BCS */
L_BAB0:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x06)));  /* BAB0 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BABD;  /* BAB2 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BABD;  /* BAB4 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAB6 TXA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BAB7 LSR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAB8 INC */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAB9 INC */
    recomp_tick(16); g_sep(0x20);  /* BABA SEP */
    recomp_tick(14); return;  /* BABC RTS */
L_BABD:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BABD DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BABE DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BA98;  /* BABF BPL */
    recomp_tick(24); { uint16_t _v = 0xFFFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAC1 LDA */
    recomp_tick(16); g_sep(0x20);  /* BAC4 SEP */
    recomp_tick(14); return;  /* BAC6 RTS */
}

/* $00BAC7, entered with P=$30 via JSR */
void gen_00BAC7(void) {
    goto L_BAC7;
L_BAC7:;
    recomp_tick(24); g_wr8(g_dp(0x00), (uint8_t)g_cpu.X);  /* BAC7 STX */
    recomp_tick(24); g_wr8(g_dp(0x02), (uint8_t)g_cpu.Y);  /* BAC9 STY */
    recomp_tick(16); g_rep(0x20);  /* BACB REP */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BACD TXA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BACE SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BACF SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BAD5;  /* BAD2 BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BAD4 TDC */
L_BAD5:;
    recomp_tick(32); g_wr16(g_dp(0x04), (uint16_t)g_cpu.C);  /* BAD5 STA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.Y; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAD7 TYA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BAD8 SEC */
    recomp_tick(24); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, 0x0100));  /* BAD9 SBC */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BADF;  /* BADC BCS */
    recomp_tick(14); g_cpu.C = g_cpu.DP; g_nz16(g_cpu.C);  /* BADE TDC */
L_BADF:;
    recomp_tick(32); g_wr16(g_dp(0x06), (uint16_t)g_cpu.C);  /* BADF STA */
    recomp_tick(40); { uint16_t _v = g_rd16(g_abs(0x1604)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAE1 LDA */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C - 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAE4 DEC */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x00FF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAE5 AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BAE8 ASL */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BAE9 DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)g_cpu.C; g_cpu.X = _v; g_nz8(_v); }  /* BAEA TAX */
L_BAEB:;
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1ABD)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAEB LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x00)));  /* BAEE CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BAF4;  /* BAF0 BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BB0E;  /* BAF2 BCS */
L_BAF4:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x04)));  /* BAF4 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BB0E;  /* BAF6 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BB0E;  /* BAF8 BEQ */
    recomp_tick(40); { uint16_t _v = g_rd16(g_absx(0x1B35)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BAFA LDA */
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x02)));  /* BAFD CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BB03;  /* BAFF BEQ */
    recomp_tick(16); if (g_cpu.flag_C) goto L_BB0E;  /* BB01 BCS */
L_BB03:;
    recomp_tick(32); g_cmp16(g_cpu.C, g_rd16(g_dp(0x06)));  /* BB03 CMP */
    recomp_tick(16); if (!g_cpu.flag_C) goto L_BB0E;  /* BB05 BCC */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BB0E;  /* BB07 BEQ */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.X; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BB09 TXA */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BB0A LSR */
    recomp_tick(16); g_sep(0x20);  /* BB0B SEP */
    recomp_tick(14); return;  /* BB0D RTS */
L_BB0E:;
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BB0E DEX */
    recomp_tick(14); { uint8_t _v = (uint8_t)(g_cpu.X - 1); g_cpu.X = _v; g_nz8(_v); }  /* BB0F DEX */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BAEB;  /* BB10 BPL */
    recomp_tick(24); { uint16_t _v = 0xFFFF; g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BB12 LDA */
    recomp_tick(16); g_sep(0x20);  /* BB15 SEP */
    recomp_tick(14); return;  /* BB17 RTS */
}

/* $00BBFB, entered with P=$00 via JSR */
void gen_00BBFB(void) {
    goto L_BBFB;
L_BBFB:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BBFB LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BBFD AND */
    recomp_tick(14); { uint16_t _v = g_asl16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC00 ASL */
    recomp_tick(14); g_cpu.C = (uint16_t)((g_cpu.C >> 8) | (g_cpu.C << 8)); g_nz8((uint8_t)g_cpu.C);  /* BC01 XBA */
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* BC02 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC04 LDA */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C & 0x3F00); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC06 AND */
    recomp_tick(14); { uint16_t _v = g_lsr16(g_cpu.C); g_cpu.C = (uint16_t)(_v); }  /* BC09 LSR */
    recomp_tick(32); { uint16_t _v = (uint16_t)(g_cpu.C | g_rd16(g_dp(0x00))); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC0A ORA */
    recomp_tick(14); { uint16_t _v = (uint16_t)g_cpu.C; g_cpu.X = _v; g_nz16(_v); }  /* BC0C TAX */
    recomp_tick(14); return;  /* BC0D RTS */
}

/* $00BC0E, entered with P=$30 via JSR */
void gen_00BC0E(void) {
    goto L_BC0E;
L_BC0E:;
    recomp_tick(16); g_rep(0x20);  /* BC0E REP */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC10 LDA */
    recomp_tick(40); g_wr16(g_absy(0x1905), (uint16_t)g_cpu.C);  /* BC12 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x02)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BC15 LDA */
    recomp_tick(40); g_wr16(g_absy(0x192D), (uint16_t)g_cpu.C);  /* BC17 STA */
    recomp_tick(16); g_sep(0x20);  /* BC1A SEP */
    recomp_tick(16); { uint8_t _v = 0x01; g_seta8((uint8_t)(_v)); g_nz8(_v); }  /* BC1C LDA */
    recomp_tick(32); g_wr8(g_absy(0x19A6), (uint8_t)(uint8_t)g_cpu.C);  /* BC1E STA */
    recomp_tick(14); return;  /* BC21 RTS */
}

/* $00BD78, entered with P=$10 via JSR */
void gen_00BD78(void) {
    goto L_BD78;
L_BD78:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD78 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x7FFF);  /* BD7A CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BD98;  /* BD7D BEQ */
    recomp_tick(14); g_cpu.flag_C = true;  /* BD7F SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x04))));  /* BD80 SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BD88;  /* BD82 BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD84 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD87 INC */
L_BD88:;
    recomp_tick(32); g_wr16(g_dp(0x00), (uint16_t)g_cpu.C);  /* BD88 STA */
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x06)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD8A LDA */
    recomp_tick(14); g_cpu.flag_C = true;  /* BD8C SEC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_sbc16(g_cpu.C, g_rd16(g_dp(0x02))));  /* BD8D SBC */
    recomp_tick(16); if (!g_cpu.flag_N) goto L_BD95;  /* BD8F BPL */
    recomp_tick(24); { uint16_t _v = (uint16_t)(g_cpu.C ^ 0xFFFF); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD91 EOR */
    recomp_tick(14); { uint16_t _v = (uint16_t)(g_cpu.C + 1); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD94 INC */
L_BD95:;
    recomp_tick(14); g_cpu.flag_C = false;  /* BD95 CLC */
    recomp_tick(32); g_cpu.C = (uint16_t)(g_adc16(g_cpu.C, g_rd16(g_dp(0x00))));  /* BD96 ADC */
L_BD98:;
    recomp_tick(14); return;  /* BD98 RTS */
}

/* $00BD99, entered with P=$00 via JSR */
void gen_00BD99(void) {
    goto L_BD99;
L_BD99:;
    recomp_tick(32); { uint16_t _v = g_rd16(g_dp(0x00)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BD99 LDA */
    recomp_tick(24); g_cmp16(g_cpu.C, 0x7FFF);  /* BD9B CMP */
    recomp_tick(16); if (g_cpu.flag_Z) goto L_BDA9;  /* BD9E BEQ */
    recomp_tick(14); g_push16((uint16_t)g_cpu.X);  /* BDA0 PHX */
    recomp_tick(30); g_push16(0xBDA3); func_table_call_jsr(0x00BBFB); g_cpu.S += 2;  /* BDA1 JSR */
    recomp_tick(48); { uint16_t _v = g_rd16(g_longx(0x7E8F28u)); g_cpu.C = (uint16_t)(_v); g_nz16(_v); }  /* BDA4 LDA */
    recomp_tick(14); { uint16_t _v = g_pull16(); g_cpu.X = _v; g_nz16(_v); }  /* BDA8 PLX */
L_BDA9:;
    recomp_tick(14); return;  /* BDA9 RTS */
}

void gen_register_bank_00(void) {
    func_table_register_flags(0x008202, gen_008202, false);
    func_table_register_flags(0x009709, gen_009709, false);
    func_table_register_flags(0x00A37A, gen_00A37A, false);
    func_table_register_flags(0x00A383, gen_00A383, false);
    func_table_register_flags(0x00A391, gen_00A391, false);
    func_table_register_flags(0x00BA75, gen_00BA75, false);
    func_table_register_flags(0x00BAC7, gen_00BAC7, false);
    func_table_register_flags(0x00BBFB, gen_00BBFB, false);
    func_table_register_flags(0x00BC0E, gen_00BC0E, false);
    func_table_register_flags(0x00BD78, gen_00BD78, false);
    func_table_register_flags(0x00BD99, gen_00BD99, false);
}
