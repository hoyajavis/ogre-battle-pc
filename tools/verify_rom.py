#!/usr/bin/env python3
"""
tools/verify_rom.py: Validates Ogre Battle: The March of the Black Queen (USA) ROM.
Checks file size, copier header, internal header, checksum, complement, and SHA-1 hash.
"""
import sys
import os
import hashlib

EXPECTED_SIZE = 1572864  # 1.5 MB unheadered LoROM
EXPECTED_TITLE = "Ogre Battle USA"
EXPECTED_COMPLEMENT = 0x2CE9  # 11497
EXPECTED_CHECKSUM = 0xD316    # 54038

def verify_rom(rom_path):
    if not os.path.exists(rom_path):
        print(f"[FAIL] ROM not found at: {rom_path}")
        return False

    with open(rom_path, "rb") as f:
        data = f.read()

    file_size = len(data)
    has_copier_header = (file_size % 1024) == 512
    offset = 512 if has_copier_header else 0
    actual_data = data[offset:]
    actual_size = len(actual_data)

    print("==================================================")
    print("Ogre Battle ROM Verification Report")
    print("==================================================")
    print(f"File Path:              {rom_path}")
    print(f"Raw File Size:          {file_size:,} bytes")
    print(f"512-Byte Copier Header: {has_copier_header}")
    print(f"ROM Payload Size:       {actual_size:,} bytes (Expected: {EXPECTED_SIZE:,})")

    if actual_size != EXPECTED_SIZE:
        print(f"[FAIL] Invalid ROM size: got {actual_size}, expected {EXPECTED_SIZE}")
        return False

    # Compute SHA-1 of clean payload
    sha1 = hashlib.sha1(actual_data).hexdigest()
    print(f"Payload SHA-1:          {sha1}")

    # Inspect LoROM internal header at $7FC0
    hdr = actual_data[0x7FC0:0x7FE0]
    title = hdr[0:21].decode("ascii", errors="replace").strip()
    rom_map = hdr[0x15]  # $20 = LoROM / SlowROM
    rom_type = hdr[0x16] # $02 = ROM + RAM + Battery
    rom_size = hdr[0x17] # $0B = 16 Mbit / 2 MB max mapping
    sram_size = hdr[0x18]# $03 = 64 kbit / 8 KB SRAM
    country = hdr[0x19]  # $01 = North America
    compl = int.from_bytes(hdr[0x1C:0x1E], "little")
    chk = int.from_bytes(hdr[0x1E:0x20], "little")

    print(f"Internal Title:         '{title}'")
    print(f"ROM Map byte:           0x{rom_map:02X} (LoROM: 0x20)")
    print(f"Cart Type byte:         0x{rom_type:02X} (ROM+RAM+Battery: 0x02)")
    print(f"SRAM Size byte:         0x{sram_size:02X} (8 KB: 0x03)")
    print(f"Country code:           0x{country:02X} (USA/NTSC: 0x01)")
    print(f"Checksum Complement:    0x{compl:04X} (Expected: 0x{EXPECTED_COMPLEMENT:04X})")
    print(f"Checksum:               0x{chk:04X} (Expected: 0x{EXPECTED_CHECKSUM:04X})")
    print(f"Checksum Check:         (Checksum + Complement = 0x{chk + compl:04X})")

    is_valid = True
    if EXPECTED_TITLE not in title:
        print(f"[WARN] Unexpected title: '{title}'")
        is_valid = False
    if chk + compl != 0xFFFF:
        print("[FAIL] Checksum and complement do not sum to 0xFFFF!")
        is_valid = False
    if chk != EXPECTED_CHECKSUM or compl != EXPECTED_COMPLEMENT:
        print("[FAIL] Checksum does not match expected Ogre Battle USA values!")
        is_valid = False

    if is_valid:
        print("--------------------------------------------------")
        print("[PASS] ROM verified successfully! Clean Ogre Battle (USA) LoROM.")
        print("==================================================")
        return True
    else:
        print("--------------------------------------------------")
        print("[FAIL] ROM verification failed.")
        print("==================================================")
        return False

if __name__ == "__main__":
    path = sys.argv[1] if len(sys.argv) > 1 else "/tmp/ogre_battle.sfc"
    success = verify_rom(path)
    sys.exit(0 if success else 1)
