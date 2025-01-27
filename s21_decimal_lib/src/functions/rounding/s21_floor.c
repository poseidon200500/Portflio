#include "../../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_decimal *result_sub = init_decimal(), *result_tranc = init_decimal();
  s21_decimal *number = init_decimal();
  number->bits[0] = 1;
  int sign = get_sign(value);
  s21_truncate(value, result_tranc);
  if (sign == 0) {
    copy_decimal(result_tranc, result);
  } else {
    s21_sub(*result_tranc, *number, result_sub);
    copy_decimal(result_sub, result);
  }
  free(result_sub);
  free(result_tranc);
  free(number);
  return 0;
}
