#ifndef OB_RECOMP_H
#define OB_RECOMP_H

#include <snesrecomp/func_table.h>

#ifdef __cplusplus
extern "C" {
#endif

void gen_register_bank_00(void);
void gen_register_bank_01(void);
void gen_register_bank_02(void);
void gen_register_bank_03(void);
void gen_register_bank_05(void);
void gen_register_bank_06(void);
void gen_register_bank_08(void);
void gen_register_bank_09(void);
void gen_register_bank_0A(void);
void gen_register_bank_0D(void);
void gen_register_bank_0E(void);
void gen_register_bank_0F(void);
void gen_register_bank_12(void);
void gen_register_bank_13(void);
void gen_register_bank_14(void);
void gen_register_bank_16(void);
void gen_register_bank_19(void);
void gen_register_bank_1A(void);
void gen_register_bank_1B(void);
void gen_register_bank_1C(void);
void gen_register_bank_1D(void);
void gen_register_bank_1E(void);
void gen_register_bank_1F(void);
void gen_register_bank_20(void);
void gen_register_bank_21(void);
void gen_register_bank_22(void);
void gen_register_bank_23(void);
void gen_register_bank_24(void);
void gen_register_bank_25(void);
void gen_register_bank_26(void);
void gen_register_bank_27(void);
void gen_register_bank_29(void);
void gen_register_bank_2A(void);
void gen_register_bank_2C(void);
void gen_register_bank_2D(void);
void gen_register_bank_2F(void);
void gen_register_bank_30(void);
void gen_register_bank_32(void);
void gen_register_bank_33(void);
void gen_register_bank_34(void);
void gen_register_bank_35(void);
void gen_register_bank_37(void);
void gen_register_bank_38(void);
void gen_register_bank_39(void);
void gen_register_bank_3C(void);
void gen_register_bank_3D(void);
void gen_register_bank_3E(void);

void gen_register_all(void);
void ob_recomp_register_all(void);

#ifdef __cplusplus
}
#endif

#endif // OB_RECOMP_H
