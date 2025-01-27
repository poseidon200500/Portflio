#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL && n > 0) {
    s21_size_t i = 0, j = 0;
    while (dest[i] != '\0') {
      i++;
    }
    while (src[j] != '\0') {
      dest[i] = src[j];
      i++;
      j++;
      if (j >= n) {
        break;
      }
    }
    dest[i] = '\0';
  }
  return dest;
}