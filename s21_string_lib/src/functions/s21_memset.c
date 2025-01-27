#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *res = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    res[i] = c;
  }
  str = (void *)res;
  return str;
}