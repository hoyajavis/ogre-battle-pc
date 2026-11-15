#!/usr/bin/env python3
"""
lift_all_banks.py - Automated static lifting for Ogre Battle SNES.
Consumes config/routines_to_lift.txt and generates partitioned C translation units
under src/gen/ (ob_bank_XX.c and ob_recomp_all.c).
"""

import os
import sys
import collections
import re

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "../third_party/snesrecomp/tools"))
from disasm65816 import detect_mapping
from autogen import emit_function, Unsupported

def main():
    repo_root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
    rom_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(repo_root, "ogre_battle.sfc")
    manifest_path = os.path.join(repo_root, "config/routines_to_lift.txt")
    out_dir = os.path.join(repo_root, "src/gen")

    os.makedirs(out_dir, exist_ok=True)

    data = open(rom_path, "rb").read()
    if len(data) % 1024 == 512:
        data = data[512:]
    detect_mapping(data)

    # Read routine manifest
    bank_entries = collections.defaultdict(list)
    total_manifest = 0
    with open(manifest_path, "r") as f:
        for line in f:
            line = line.split("#")[0].strip()
            if not line:
                continue
            parts = line.split()
            addr24 = int(parts[0], 16)
            P = int(parts[1], 16)
            is_long = (parts[2].upper() == "JSL")
            bank = addr24 >> 16
            bank_entries[bank].append((addr24, P, is_long))
            total_manifest += 1

    print(f"Total routines in manifest: {total_manifest} across {len(bank_entries)} banks")

    # Routines with multi-frame wait loops or APU boot handshake that must run genuine on LakeSnes
    EXCLUDED_HARDWARE_ROUTINES = {
        0x00809E, 0x0080C6, 0x008386, 0x0083BE, 0x0083C8, 0x0083D5, 0x0083E1, 0x00D95B,
        0x0083F2, 0x00844E, 0x008470, 0x0084A2, 0x009A95, 0x009B03, 0x00A113, 0x00A125,
        0x009B04, 0x009B21, 0x009CC4, 0x009F6B, 0x009FBD, 0x00A6D1, 0x009893, 0x00A0EC,
        0x009B45, 0x00A0E3, 0x009EE0,
        0x009B58, 0x009B5F, 0x009C23,
        *range(0x009BC2, 0x009C25, 3),
        0x009E7B, 0x009E86, 0x009E87, 0x009E93, 0x009E9B, 0x009EA2, 0x009EAA, 0x009EB6, 0x009EC2, 0x009ED1,
        0x009F0F, 0x009F1E, 0x009F3C, 0x009F8B, 0x00A00D, 0x00A088, 0x00A0F2, 0x00A18C,
        0x00A2BD, 0x00A2CA, 0x00A2DC, 0x00A2EE, 0x00A30A, 0x00A44A, 0x00A456, 0x00A468,
        0x00A80D, 0x00A82B, 0x00A831, 0x00A83B, 0x00A83F, 0x00A845, 0x00A862, 0x00A868, 0x00A87B, 0x00A888, 0x00A88C, 0x00A898, 0x00A8A2, 0x00A8AA, 0x00A8AF,
        0x00AF03, 0x00AF33, 0x00E228, 0x00E235,
        # Bank 00 text window and font tile blitter routines (executes genuine on LakeSnes)
        0x00E3CD, 0x00E56C, 0x00EC7F, 0x00EC97, 0x00ECA6, 0x00EFEF, 0x00F00F,
        0x00F087, 0x00F122, 0x00F1CB, 0x00F1F4, 0x00F24E, 0x00F46D,
        0x008000, 0x008009, 0x00AA9D, 0x00AAA0, 0x00AAA2, 0x00AAA5, 0x00AAA8, 0x00AAAA, 0x00AAAB, 0x00AAEA,
        0x00AB01, 0x00B16F, 0x00B1E0, 0x00C48C, 0x00C558, 0x00D7FC, 0x00D867, 0x00DBAF, 0x00DC89, 0x00DDB2,
        0x00DE0D, 0x00DEBE, 0x00DED6,
        0x00DEE6, 0x00DF16, 0x00DF4C,
        0x00F5D2, 0x00F5E6, 0x00F65E,
        0x01F99D, 0x018000, 0x018067,
        # Bank 03 unit generation & stat calculation routines (executes genuine on LakeSnes)
        0x03EBBB, 0x03EC06, 0x03EEB9, 0x03EF19, 0x03EF3B, 0x03EF5B, 0x03EF5C, 0x03EF88,
        # Bank 05 unit stat calculation & math coprocessor routines (executes genuine on LakeSnes)
        0x058299, 0x0583EF, 0x058400, 0x0586D1, 0x05879F,
        0x05AA52, 0x05AA7F, 0x05AA89, 0x05AA99, 0x05AAC3,
        0x05AD18, 0x05AD3E, 0x05AD61, 0x05AD6D, 0x05AD7F, 0x05AD8F, 0x05AD9F, 0x05ADB2, 0x05ADE7, 0x05ADFA,
        0x05AE0A, 0x05AE1A, 0x05AE6A, 0x05AE76, 0x05AE90,
        0x05AF60, 0x05AFD9, 0x05AFE6, 0x05B034, 0x05B06C, 0x05B079, 0x05B08A,
        0x05B107, 0x05B142, 0x05B177, 0x05B1A9, 0x05B2E3, 0x05B2E8, 0x05B37D, 0x05B391,
        0x0780DE, 0x078177, 0x07818D, 0x0781C0, 0x07820A, 0x07824D, 0x078343,
        0x0C8000, 0x0C8062, 0x0C80C2, 0x0C8157,
        0x1096C8, 0x1096FB, 0x109709, 0x109795, 0x10981D, 0x109843,
        0x0299BD, 0x3299BD, 0x05942D, 0x05B391,
        # Bank 04 scene loader & PPU setup routines (executed genuine on LakeSnes)
        0x048000, 0x048037, 0x048074, 0x0480C2, 0x048530, 0x04855D, 0x048946,
        0x0489A2, 0x0489B9, 0x0489E3, 0x00F423, 0x00D707,
        0x04E95F, 0x04E9BF, 0x04E9D0,
        # Bank 04 routines calling RAM syscall trampoline $1199 (rewrites stack return address)
        0x048123, 0x0488CD, 0x0488D8, 0x0488F4, 0x04AC55, 0x04B20E, 0x04B25F, 0x04B28C,
        0x04B2B9, 0x04B400, 0x04B482, 0x04EF7F, 0x04F452, 0x04F594, 0x04F5EF,
        # Bank 00 384-iteration WRAM clear loop, VBlank frame-counter tick, & 32-bit division (NMI-boundary sensitive)
        0x00F866, 0x00AA52, 0x00855D, 0x0087BD, 0x00D791, 0x00D32F,
        0x0099F4, 0x009A0E, 0x00B154, 0x00C755, 0x00CA6E, 0x00CC4C, 0x00CCFD, 0x00F85A,
        0x00CDBD, 0x00CE64, 0x009A55, 0x008803, 0x00883A, 0x00966F, 0x008E62,
        0x008914, 0x008B43, 0x008DD2, 0x008DE3, 0x008DFB, 0x008E22, 0x00AF87,
        0x00827D, 0x00AD13, 0x00ACD2, 0x00BA28, 0x00D4FE, 0x00D5B3, 0x00BC22,
        # Bank 02 NMI-boundary / timing-sensitive routines (trace_07 frames 9537-9543, 9562, 9592, 9598-9599, 9621)
        0x0283C8, 0x0283E6, 0x02EB20, 0x02F5C2, 0x02F817, 0x02F936, 0x02EDF8, 0x02D779,
        0x02D99A, 0x02E968, 0x02F417, 0x02F42D, 0x02F469, 0x02F479, 0x02F9BD, 0x02FB1D,
        0x0283D7, 0x02840E,
    }

    # Step 1: Initial candidate generation and filtering
    candidates = {}
    skipped = {}

    for bank in sorted(bank_entries.keys()):
        for addr24, P, is_long in bank_entries[bank]:
            if addr24 in EXCLUDED_HARDWARE_ROUTINES:
                skipped[addr24] = "hardware timing / wait loop (executes genuine on LakeSnes)"
                continue
            try:
                code = emit_function(data, addr24, P, is_long)
                # Check if routine calls Low RAM / RAM trampoline ($1199, etc.) or sub-8000 address
                targets = [int(t, 16) for t in re.findall(r"func_table_call(?:_jsr)?\(0x([0-9A-Fa-f]{6})u?\)", code)]
                sub8000 = [t for t in targets if (t & 0xFFFF) < 0x8000]
                if sub8000:
                    skipped[addr24] = f"calls RAM trampoline/sub-8000 (${sub8000[0]:06X}): executes native on LakeSnes"
                    continue
                # Check for indirect jump tables: JMP ($xxxx,X), JMP ($xxxx), JML [$xxxx], variable calls
                all_calls = re.findall(r"func_table_call(?:_jsr)?\(([^)]+)\)", code)
                if any(not re.match(r"^0x[0-9A-Fa-f]{6}u?$", c.strip()) for c in all_calls):
                    skipped[addr24] = "indirect jump table dispatch: executes native on LakeSnes"
                    continue
                # Check for tail JML calls
                if re.search(r"func_table_call\(0x[0-9A-Fa-f]{6}u\);\s*return;", code):
                    skipped[addr24] = "tail JML dispatch: executes native on LakeSnes"
                    continue
                # Check for DMA transfer / trigger registers ($4300-$437F, $4200, $420B, $420C)
                if re.search(r"g_wr.*0x43[0-7]", code) or re.search(r"g_wr.*0x420[0BCbc]", code):
                    skipped[addr24] = "DMA transfer / trigger routine: executes native on LakeSnes"
                    continue
                # Check for hardware math multiplier / divider registers ($4202-$4206, $4214-$4217)
                if re.search(r"0x420[2-6]", code) or re.search(r"0x421[4-7]", code):
                    skipped[addr24] = "Hardware math coprocessor routine ($4202-$4217): executes native on LakeSnes"
                    continue
                # Check for APU sound communication registers ($2140-$2143), Bank 07 (sound), or Bank 04 (Tarot)
                if re.search(r"0x214[0-3]", code) or bank in (0x04, 0x07):
                    skipped[addr24] = "Sound driver / Tarot scene routine: executes native on LakeSnes"
                    continue
                candidates[addr24] = {
                    "bank": bank,
                    "is_long": is_long,
                    "code": code,
                    "targets": targets,
                }
            except Unsupported as e:
                skipped[addr24] = str(e)

    # Step 2: Iterative fixed-point pruning to guarantee a closed call graph.
    # No recompiled C function will ever call an unlifted routine via recomp_interp.
    prune_pass = 1
    while True:
        to_prune = []
        for addr24, info in candidates.items():
            bad_callees = [t for t in info["targets"] if t not in candidates]
            if bad_callees:
                to_prune.append((addr24, f"calls unlifted target 0x{bad_callees[0]:06X}: executes native on LakeSnes"))
        if not to_prune:
            break
        for addr24, why in to_prune:
            skipped[addr24] = why
            del candidates[addr24]
        prune_pass += 1

    total_lifted = len(candidates)
    total_skipped = len(skipped)
    active_banks = []

    # Step 3: Emit translation units for active banks
    for bank in sorted(bank_entries.keys()):
        done = [(a, c["is_long"], c["code"]) for a, c in candidates.items() if c["bank"] == bank]
        done.sort(key=lambda x: x[0])
        bank_skipped = [(a, skipped[a]) for a in skipped if (a >> 16) == bank]
        bank_skipped.sort(key=lambda x: x[0])

        if not done:
            continue

        active_banks.append(bank)
        bank_c_path = os.path.join(out_dir, f"ob_bank_{bank:02X}.c")
        with open(bank_c_path, "w", newline="\n") as f:
            f.write(f"/* Bank ${bank:02X} recompiled routines for Ogre Battle: The March of the Black Queen.\n")
            f.write(f" * Generated automatically by tools/lift_all_banks.py. DO NOT COMMIT DERIVED CODE. */\n\n")
            f.write(f"/* Statistics: {len(done)} lifted, {len(bank_skipped)} unlifted in Bank ${bank:02X} */\n")
            for a, why in bank_skipped:
                f.write(f"/* not lifted: ${a:06X}: {why} */\n")
            f.write("\n")
            f.write("#include <snesrecomp/snesrecomp.h>\n")
            f.write("#include <snesrecomp/gen_ops.h>\n")
            f.write('#include "ob_recomp.h"\n\n')
            f.write("#if defined(_MSC_VER)\n#pragma warning(disable: 4102)\n#endif\n\n")

            for addr24, _, code in done:
                f.write(code + "\n\n")

            f.write(f"void gen_register_bank_{bank:02X}(void) {{\n")
            for addr24, is_long, _ in done:
                is_long_str = "true" if is_long else "false"
                f.write(f"    func_table_register_flags(0x{addr24:06X}, gen_{addr24:06X}, {is_long_str});\n")
            f.write("}\n")

        print(f"Bank ${bank:02X}: {len(done)} lifted, {len(bank_skipped)} skipped -> ob_bank_{bank:02X}.c")

    # Generate master header
    header_path = os.path.join(out_dir, "ob_recomp.h")
    with open(header_path, "w", newline="\n") as f:
        f.write("#ifndef OB_RECOMP_H\n#define OB_RECOMP_H\n\n")
        f.write("#include <snesrecomp/func_table.h>\n\n")
        f.write("#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n")
        for bank in active_banks:
            f.write(f"void gen_register_bank_{bank:02X}(void);\n")
        f.write("\nvoid gen_register_all(void);\nvoid ob_recomp_register_all(void);\n\n")
        f.write("#ifdef __cplusplus\n}\n#endif\n\n")
        f.write("#endif // OB_RECOMP_H\n")

    # Generate master registration unit
    all_c_path = os.path.join(out_dir, "ob_recomp_all.c")
    with open(all_c_path, "w", newline="\n") as f:
        f.write("/* Master recompiled function dispatcher registration */\n")
        f.write('#include "ob_recomp.h"\n\n')
        f.write("void gen_register_all(void) {\n")
        for bank in active_banks:
            f.write(f"    gen_register_bank_{bank:02X}();\n")
        f.write("}\n\n")
        f.write("void ob_recomp_register_all(void) {\n")
        f.write("    gen_register_all();\n")
        f.write("}\n")

    print(f"\n=======================================================")
    print(f"Lifting Complete: {total_lifted} lifted, {total_skipped} skipped")
    print(f"Active bank translation units: {len(active_banks)}")
    print(f"Master registration written to ob_recomp_all.c")
    print(f"=======================================================\n")

if __name__ == "__main__":
    main()
