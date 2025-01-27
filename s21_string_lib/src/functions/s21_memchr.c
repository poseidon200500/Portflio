#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *buf = (unsigned char *)str;
  s21_size_t i = 0;
  unsigned char *ans = S21_NULL;
  while (i < n && buf) {
    if (*buf == (unsigned char)c) {
      ans = buf;
      i = n;
    }
    buf++;
    i++;
  }
  return ans;
}
