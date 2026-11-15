#!/usr/bin/env python3
"""
tools/crawler.py — Hybrid CDL-Guided Static Call Graph Crawler & Jump Table Extractor.
Part of Milestone 2: Empirical Profiling, CDL Logging & Static Call Graph.

Ingests:
  - ogre_battle.sfc (1.5 MB unheadered ROM)
  - ogre_battle.cdl (1.5 MB Mesen-S CDL bitmask generated from 8 canonical traces)

Outputs:
  - config/jumptables.ini (catalog of all resolved indirect jump/call dispatchers)
  - config/symbols.ini (catalog of all mapped subroutines, boundaries, and M/X flags)
"""

import sys
import os
from pathlib import Path

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "../third_party/snesrecomp/tools"))
from disasm65816 import OPCODES, rom_read, set_mapping

# CDL bitmask constants
CDL_CODE        = 0x01
CDL_DATA        = 0x02
CDL_VIDEO       = 0x04
CDL_AUDIO       = 0x08
CDL_JUMP_TARGET = 0x10
CDL_SUB_ENTRY   = 0x20
CDL_FLAG_M8     = 0x40
CDL_FLAG_X8     = 0x80

def snes_to_lorom(bank, adr, rom_size=1572864):
    bank &= 0x7F
    if adr >= 0x8000 or bank >= 0x40:
        return ((bank << 15) | (adr & 0x7FFF)) & (rom_size - 1)
    return -1

def lorom_to_snes(rom_offset):
    bank = (rom_offset >> 15) & 0x3F
    adr = 0x8000 | (rom_offset & 0x7FFF)
    return bank, adr

def rd(data, pb, pc):
    return rom_read(data, pb, pc)

def rd16(data, pb, pc):
    return rd(data, pb, pc) | (rd(data, pb, (pc + 1) & 0xFFFF) << 8)

def insn_len(name, extra, mode, m8, x8):
    if mode == "immA":
        return 1 + (1 if m8 else 2)
    if mode == "immX":
        return 1 + (1 if x8 else 2)
    return 1 + extra

def crawl_with_cdl(rom_bytes, cdl_bytes):
    set_mapping("lorom")
    rom_size = len(rom_bytes)

    functions = {}        # func24 -> dict of attributes
    visited_states = set()  # set of (pb, pc, m8, x8)
    jump_tables = {}      # table_key -> dict of table info
    unresolved_sites = set()
    misaligned_sites = []

    work = []  # tuples: (pb, pc, m8, x8, caller_func24)

    def push_work(pb, pc, m8, x8, func):
        if (pb, pc, m8, x8) not in visited_states:
            work.append((pb, pc, m8, x8, func))

    # 1. Harvest seeds from CPU interrupt vectors
    vector_names = [
        ("RESET", 0xFFFC), ("NMI_n", 0xFFEA), ("IRQ_n", 0xFFEE),
        ("COP_n", 0xFFE4), ("BRK_n", 0xFFE6), ("ABORT_n", 0xFFE8)
    ]
    for name, voff in vector_names:
        tgt = rd16(rom_bytes, 0x00, voff)
        if 0x8000 <= tgt <= 0xFFFF:
            f24 = (0x00 << 16) | tgt
            if f24 not in functions:
                functions[f24] = {
                    'entry': (0x00, tgt), 'name': name, 'm8': True, 'x8': True,
                    'end': None, 'callers': set(), 'type': 'RTI'
                }
                push_work(0x00, tgt, True, True, f24)

    # 2. Harvest seeds from Dynamic CDL Subroutine Entries and Opcodes
    cdl_subs_found = 0
    for offset in range(rom_size):
        c = cdl_bytes[offset]
        if c & CDL_SUB_ENTRY:
            bank, adr = lorom_to_snes(offset)
            m8 = bool(c & CDL_FLAG_M8)
            x8 = bool(c & CDL_FLAG_X8)
            f24 = (bank << 16) | adr
            if f24 not in functions:
                functions[f24] = {
                    'entry': (bank, adr), 'name': f"sub_{bank:02X}{adr:04X}",
                    'm8': m8, 'x8': x8, 'end': None, 'callers': set(), 'type': 'UNKNOWN'
                }
                push_work(bank, adr, m8, x8, f24)
                cdl_subs_found += 1

    print(f"[CRAWLER] Seeded with {len(vector_names)} CPU vectors and {cdl_subs_found} CDL subroutine targets.")

    # 3. Recursive-descent static analysis loop
    steps = 0
    while work:
        pb, pc, m8, x8, cur_func = work.pop()

        while True:
            state_key = (pb, pc, m8, x8)
            if state_key in visited_states:
                break
            visited_states.add(state_key)
            steps += 1

            op = rd(rom_bytes, pb, pc)
            if op not in OPCODES:
                rom_off = snes_to_lorom(pb, pc, rom_size)
                if rom_off >= 0 and (cdl_bytes[rom_off] & CDL_CODE):
                    misaligned_sites.append((pb, pc, op))
                break

            name, extra, mode = OPCODES[op]
            length = insn_len(name, extra, mode, m8, x8)
            nxt = (pc + length) & 0xFFFF

            # Register Flag Transitions
            if op == 0xC2:  # REP #imm
                imm = rd(rom_bytes, pb, (pc + 1) & 0xFFFF)
                if imm & 0x20: m8 = False
                if imm & 0x10: x8 = False
            elif op == 0xE2:  # SEP #imm
                imm = rd(rom_bytes, pb, (pc + 1) & 0xFFFF)
                if imm & 0x20: m8 = True
                if imm & 0x10: x8 = True

            # Direct Subroutine Calls
            elif op == 0x20:  # JSR abs
                tgt_adr = rd16(rom_bytes, pb, (pc + 1) & 0xFFFF)
                t = (pb << 16) | tgt_adr
                if t not in functions:
                    functions[t] = {
                        'entry': (pb, tgt_adr), 'name': f"sub_{pb:02X}{tgt_adr:04X}",
                        'm8': m8, 'x8': x8, 'end': None, 'callers': set(), 'type': 'RTS'
                    }
                    push_work(pb, tgt_adr, m8, x8, t)
                functions[t]['callers'].add(cur_func)

            elif op == 0x22:  # JSL long
                lo = rd16(rom_bytes, pb, (pc + 1) & 0xFFFF)
                hi = rd(rom_bytes, pb, (pc + 3) & 0xFFFF)
                t = (hi << 16) | lo
                if t not in functions:
                    functions[t] = {
                        'entry': (hi, lo), 'name': f"sub_{hi:02X}{lo:04X}",
                        'm8': m8, 'x8': x8, 'end': None, 'callers': set(), 'type': 'RTL'
                    }
                    push_work(hi, lo, m8, x8, t)
                functions[t]['callers'].add(cur_func)

            # Indirect Jump Tables: JMP ($xxxx,X) or JSR ($xxxx,X)
            elif op in (0x7C, 0xFC):
                table_site = (pb << 16) | pc
                base = rd16(rom_bytes, pb, (pc + 1) & 0xFFFF)
                targets = []

                if base >= 0x8000:
                    # In-ROM pointer table
                    for idx in range(64):
                        entry_adr = (base + idx * 2) & 0xFFFF
                        dest = rd16(rom_bytes, pb, entry_adr)
                        if not (0x8000 <= dest <= 0xFFFF):
                            break
                        first_op = rd(rom_bytes, pb, dest)
                        if first_op not in OPCODES:
                            break
                        targets.append(dest)
                        t24 = (pb << 16) | dest
                        if t24 not in functions and op == 0xFC:
                            functions[t24] = {
                                'entry': (pb, dest), 'name': f"sub_{pb:02X}{dest:04X}",
                                'm8': m8, 'x8': x8, 'end': None, 'callers': set(), 'type': 'RTS'
                            }
                        push_work(pb, dest, m8, x8, t24 if op == 0xFC else cur_func)

                jump_tables[table_site] = {
                    'bank': pb, 'site': pc, 'base': base,
                    'targets': targets, 'pattern': 'JSR_INDIRECT_X' if op == 0xFC else 'JMP_INDIRECT_X'
                }
                if op == 0x7C:  # JMP (abs,X) has no fall-through
                    break

            # Unconditional Jumps
            elif op == 0x4C:  # JMP abs
                tgt = rd16(rom_bytes, pb, (pc + 1) & 0xFFFF)
                push_work(pb, tgt, m8, x8, cur_func)
                break

            elif op == 0x5C:  # JML long
                lo = rd16(rom_bytes, pb, (pc + 1) & 0xFFFF)
                hi = rd(rom_bytes, pb, (pc + 3) & 0xFFFF)
                t = (hi << 16) | lo
                push_work(hi, lo, m8, x8, t)
                break

            elif op in (0x6C, 0xDC):  # JMP (abs) / JML [abs] single indirect
                unresolved_sites.add((pb << 16) | pc)
                break

            # Subroutine Returns / Terminal opcodes
            elif op in (0x60, 0x6B, 0x40):
                if cur_func in functions and functions[cur_func]['end'] is None:
                    functions[cur_func]['end'] = (pb, pc)
                    functions[cur_func]['type'] = 'RTS' if op == 0x60 else ('RTL' if op == 0x6B else 'RTI')
                break

            elif op == 0x80:  # BRA rel8
                rel = rd(rom_bytes, pb, (pc + 1) & 0xFFFF)
                if rel >= 0x80: rel -= 0x100
                push_work(pb, (pc + 2 + rel) & 0xFFFF, m8, x8, cur_func)
                break

            elif op == 0x82:  # BRL rel16
                rel = rd16(rom_bytes, pb, (pc + 1) & 0xFFFF)
                if rel >= 0x8000: rel -= 0x10000
                push_work(pb, (pc + 3 + rel) & 0xFFFF, m8, x8, cur_func)
                break

            # Conditional Branches
            elif op in (0x10, 0x30, 0x50, 0x70, 0x90, 0xB0, 0xD0, 0xF0):
                rel = rd(rom_bytes, pb, (pc + 1) & 0xFFFF)
                if rel >= 0x80: rel -= 0x100
                push_work(pb, (pc + 2 + rel) & 0xFFFF, m8, x8, cur_func)
                # Fallthrough to nxt

            pc = nxt

    return functions, visited_states, jump_tables, unresolved_sites, misaligned_sites

def main():
    rom_path = "ogre_battle.sfc"
    cdl_path = "ogre_battle.cdl"

    if len(sys.argv) > 1: rom_path = sys.argv[1]
    if len(sys.argv) > 2: cdl_path = sys.argv[2]

    rom_bytes = Path(rom_path).read_bytes()
    cdl_bytes = Path(cdl_path).read_bytes()

    print("====================================================================")
    print("Ogre Battle Call Graph Crawler & Jump Table Extractor")
    print(f"ROM: {rom_path} ({len(rom_bytes)} bytes)")
    print(f"CDL: {cdl_path} ({len(cdl_bytes)} bytes)")
    print("====================================================================\n")

    functions, visited, tables, unresolved, misaligned = crawl_with_cdl(rom_bytes, cdl_bytes)

    # Write config/jumptables.ini (canonicalized)
    jt_path = Path("config/jumptables.ini")
    canon_tables = {}
    for site, info in tables.items():
        pb = ((site >> 16) & 0xFF) & 0x3F
        pc = site & 0xFFFF
        canon_key = (pb << 16) | pc
        if canon_key not in canon_tables:
            canon_tables[canon_key] = {
                'bank': pb, 'site': pc, 'base': info['base'],
                'pattern': info['pattern'], 'targets': info['targets']
            }

    with open(jt_path, "w") as f:
        f.write("# Ogre Battle PC Port - Canonical Jump Table Catalog\n")
        f.write(f"# Auto-generated by tools/crawler.py (Total Tables: {len(canon_tables)})\n\n")
        for key, info in sorted(canon_tables.items()):
            pb = info['bank']
            pc = info['site']
            f.write(f"[table_{pb:02X}_{pc:04X}]\n")
            f.write(f"bank = 0x{pb:02X}\n")
            f.write(f"site = 0x{pc:04X}\n")
            f.write(f"base_address = 0x{info['base']:04X}\n")
            f.write(f"pattern = {info['pattern']}\n")
            f.write(f"entries = {len(info['targets'])}\n")
            f.write(f"targets = {', '.join(f'0x{t:04X}' for t in info['targets'])}\n\n")

    # Canonicalize and deduplicate ROM functions
    canon_funcs = {}
    for f24, info in functions.items():
        raw_pb, pc = info['entry']
        if pc >= 0x8000:
            pb = raw_pb & 0x3F
            key = (pb << 16) | pc
            if key not in canon_funcs:
                canon_funcs[key] = {
                    'entry': (pb, pc),
                    'name': info.get('name', f"sub_{pb:02X}{pc:04X}"),
                    'end': info['end'],
                    'type': info['type'],
                    'm8': info['m8'],
                    'x8': info['x8'],
                    'callers': set(info['callers'])
                }
            else:
                canon_funcs[key]['callers'].update(info['callers'])

    # Write config/symbols.ini
    sym_path = Path("config/symbols.ini")
    with open(sym_path, "w") as f:
        f.write("# Ogre Battle PC Port - Subroutine Symbols Database\n")
        f.write(f"# Auto-generated by tools/crawler.py (Total ROM Functions: {len(canon_funcs)})\n\n")
        for key, info in sorted(canon_funcs.items()):
            pb, pc = info['entry']
            name = info['name']
            if name.startswith("sub_") and len(name) == 10:
                name = f"sub_{pb:02X}{pc:04X}"
            end_str = f"0x{info['end'][0] & 0x3F:02X}:{info['end'][1]:04X}" if info['end'] else "UNKNOWN"
            f.write(f"[{name}]\n")
            f.write(f"address = 0x{pb:02X}:{pc:04X}\n")
            f.write(f"bank = 0x{pb:02X}\n")
            f.write(f"entry_adr = 0x{pc:04X}\n")
            f.write(f"end_adr = {end_str}\n")
            f.write(f"return_type = {info['type']}\n")
            f.write(f"m8 = {info['m8']}\n")
            f.write(f"x8 = {info['x8']}\n")
            f.write(f"caller_count = {len(info['callers'])}\n\n")

    # Write config/symbols.sym (Mesen-S / WLA-DX standard symbol format)
    sym_standard_path = Path("config/symbols.sym")
    with open(sym_standard_path, "w") as f:
        f.write("; Ogre Battle USA - Symbols Map\n")
        f.write("[labels]\n")
        for key, info in sorted(canon_funcs.items()):
            pb, pc = info['entry']
            name = info['name']
            if name.startswith("sub_") and len(name) == 10:
                name = f"sub_{pb:02X}{pc:04X}"
            f.write(f"{pb:02X}:{pc:04X} {name}\n")

    # Summary Statistics
    bank_funcs = {}
    for key, info in canon_funcs.items():
        pb, _ = info['entry']
        bank_funcs[pb] = bank_funcs.get(pb, 0) + 1

    print("\n====================================================================")
    print("CALL GRAPH CRAWLER & SYMBOL EXTRACTION SUMMARY")
    print("====================================================================")
    print(f"Total Canonical ROM Subroutines Mapped: {len(canon_funcs)}")
    print(f"Total Unique States Visited:           {len(visited)}")
    print(f"Canonical Jump Tables Resolved:        {len(canon_tables)}")
    print(f"Total Jump Table Targets Extracted:    {sum(len(t['targets']) for t in canon_tables.values())}")
    print(f"Unresolved Indirect Sites:             {len(unresolved)}")
    print(f"Misaligned Opcode Anomaly Sites:       {len(misaligned)}")
    print("\nSubroutines by Bank Breakdown (Active Banks):")
    for b in sorted(bank_funcs.keys()):
        print(f"  Bank ${b:02X}: {bank_funcs[b]:4d} functions")

    print(f"\nSaved Jump Table Catalog:    {jt_path}")
    print(f"Saved Symbol Database:       {sym_path}")
    print(f"Saved Emulator Symbols (.sym): {sym_standard_path}")
    print("====================================================================")


if __name__ == "__main__":
    main()
