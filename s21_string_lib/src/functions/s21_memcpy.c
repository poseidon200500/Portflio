#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t j = 0;
  char *d = (char *)dest;
  char *s = (char *)src;
  while (j < n) {
    d[j] = s[j];
    j++;
  }
  dest = d;
  return dest;
}