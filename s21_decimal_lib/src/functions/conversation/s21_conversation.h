#ifndef S21_CONVERSATION
#define S21_CONVERSATION

#include "../../s21_types.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_string_to_decimal(char *str, s21_decimal *dec);
int get_scale_from_string(char* ptr);

#endif