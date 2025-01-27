#include "../../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  float dest = 0;
  s21_decimal *result_sub = init_decimal(), *result_tranc = init_decimal();
  s21_decimal *number = init_decimal(), *result_add = init_decimal();
  number->bits[0] = 1;
  int sign = get_sign(value);
  s21_truncate(value, result_tranc);
  s21_sub(value, *result_tranc, result_sub);
  set_sign(result_sub, 0);
  s21_from_decimal_to_float(*result_sub, &dest);
  if (dest >= 0.5) {
    if (sign == 0) {
      s21_add(*result_tranc, *number, result_add);
      copy_decimal(result_add, result);
    } else {
      s21_sub(*result_tranc, *number, result_sub);
      copy_decimal(result_sub, result);
    }
  } else {
    copy_decimal(result_tranc, result);
  }
  free(result_sub);
  free(result_tranc);
  free(number);
  free(result_add);
  return 0;
}
