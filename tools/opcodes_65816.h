#ifndef OPCODES_65816_H
#define OPCODES_65816_H

#include <stdbool.h>
#include <stdint.h>

static inline int get_65816_insn_len(uint8_t opcode, bool mf, bool xf) {
    switch (opcode) {
        case 0x09: return mf ? 2 : 3;
        case 0x29: return mf ? 2 : 3;
        case 0x49: return mf ? 2 : 3;
        case 0x69: return mf ? 2 : 3;
        case 0x89: return mf ? 2 : 3;
        case 0xA0: return xf ? 2 : 3;
        case 0xA2: return xf ? 2 : 3;
        case 0xA9: return mf ? 2 : 3;
        case 0xC0: return xf ? 2 : 3;
        case 0xC9: return mf ? 2 : 3;
        case 0xE0: return xf ? 2 : 3;
        case 0xE9: return mf ? 2 : 3;
        default: {
            static const uint8_t base_len[256] = {
                2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4,
                3, 2, 4, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4,
                1, 2, 2, 2, 3, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 3, 2, 2, 2, 1, 3, 1, 1, 4, 3, 3, 4,
                1, 2, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4,
                2, 2, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4,
                1, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4,
                1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4,
                1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 4,
                2, 2, 2, 2, 3, 2, 2, 2, 1, 3, 1, 1, 3, 3, 3, 4
            };
            return base_len[opcode];
        }
    }
}

#endif
