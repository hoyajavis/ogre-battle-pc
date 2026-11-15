/* Master recompiled function dispatcher registration */
#include "ob_recomp.h"

void gen_register_all(void) {
    gen_register_bank_00();
    gen_register_bank_01();
    gen_register_bank_02();
    gen_register_bank_03();
    gen_register_bank_05();
    gen_register_bank_06();
    gen_register_bank_08();
    gen_register_bank_09();
    gen_register_bank_0A();
    gen_register_bank_0D();
    gen_register_bank_0E();
    gen_register_bank_0F();
    gen_register_bank_12();
    gen_register_bank_13();
    gen_register_bank_14();
    gen_register_bank_16();
    gen_register_bank_19();
    gen_register_bank_1A();
    gen_register_bank_1B();
    gen_register_bank_1C();
    gen_register_bank_1D();
    gen_register_bank_1E();
    gen_register_bank_1F();
    gen_register_bank_20();
    gen_register_bank_21();
    gen_register_bank_22();
    gen_register_bank_23();
    gen_register_bank_24();
    gen_register_bank_25();
    gen_register_bank_26();
    gen_register_bank_27();
    gen_register_bank_29();
    gen_register_bank_2A();
    gen_register_bank_2C();
    gen_register_bank_2D();
    gen_register_bank_2F();
    gen_register_bank_30();
    gen_register_bank_32();
    gen_register_bank_33();
    gen_register_bank_34();
    gen_register_bank_35();
    gen_register_bank_37();
    gen_register_bank_38();
    gen_register_bank_39();
    gen_register_bank_3C();
    gen_register_bank_3D();
    gen_register_bank_3E();
}

void ob_recomp_register_all(void) {
    gen_register_all();
}
