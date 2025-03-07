#include "../../s21_decimal.h"

//умножение на -1
int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  null_decimal(result);
  error = !is_correct(&value);
  if (error != 1) {
    copy_decimal(&value, result);
    int exp = get_sign(value);
    int flag = is_zero(value);  // 1 - yes
    if (exp == 1 || flag == 1)
      set_sign(result, 0);
    else
      set_sign(result, 1);
  }
  return error;
}