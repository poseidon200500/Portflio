#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = CONVERTATION_OK;
  if (!dst) {
    code = CONVERTATION_ERROR;
  } else {
    int sign = POSITIVE_SIGN;
    null_decimal(dst);
    if (src < 0) {
      sign = NEGATIVE_SIGN;
      if (src != MIN_INT) {
        src = -src;
      }
    }
    dst->bits[0] = src;
    set_sign(dst, sign);
  }
  return code;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = 0;
  if (dst == NULL || !is_correct(&src)) return 1;
  s21_decimal *tmp = init_decimal();
  s21_truncate(src, tmp);
  if (tmp->bits[1] != 0 || tmp->bits[2] != 0) {
    code = 1;
  } else {
    int sign = get_sign(*tmp) ? -1 : 1;
    *dst = tmp->bits[0] * sign;
  }
  free(tmp);
  return code;
}
