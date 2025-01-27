#include "../../s21_decimal.h"

int s21_is_equal(s21_decimal decimal_1, s21_decimal decimal_2) {
  int result = 0;
  result = (s21_compare(&decimal_1, &decimal_2) == 0) ? 1 : 0;
  return result;
}