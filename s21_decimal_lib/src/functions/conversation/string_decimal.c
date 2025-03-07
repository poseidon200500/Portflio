#include "../../s21_decimal.h"

int get_scale_from_string(char* ptr) {
  int result = 0;
  while (*ptr != 'e' && *ptr != 'E') ptr++;
  ptr++;
  result = strtol(ptr, NULL, 10);
  return result;
}

int s21_from_string_to_decimal(char* str, s21_decimal* dec) {
  s21_decimal ptr_dec = {0}, ten = {{10, 0, 0, 0}},
              ten_result = {{10000000, 0, 0, 0}};
  null_decimal(dec);
  char* ptr = str;
  int exp = get_scale_from_string(str);
  while (*ptr) {
    if (*ptr == '.') {
      ++ptr;
    } else if (*ptr >= '0' && *ptr <= '9') {
      s21_decimal tmp = {0};
      s21_from_int_to_decimal(*ptr - '0', &ptr_dec);
      ten_result.bits[0] /= 10;
      s21_mul(ptr_dec, ten_result, &tmp);
      s21_add(*dec, tmp, dec);
      ++ptr;
    } else
      break;
  }
  exp = exp - 6;
  ten_result.bits[0] = 10;
  if (exp > 0) {
    while (exp) {
      s21_mul(*dec, ten, dec);
      exp--;
    }
  } else if (exp < 0) {
    while (exp) {
      s21_div(*dec, ten, dec);
      exp++;
    }
  }
  return 0;
}