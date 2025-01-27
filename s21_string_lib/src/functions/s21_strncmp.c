#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  s21_size_t i = 0;

  while (i < n) {
    if (str1[i] == '\0') break;
    if (str2[i] == '\0') break;
    if (str1[i] != str2[i]) break;
    i++;
  }

  if (0 == n || i == n)
    result = 0;
  else if (str1[i] != str2[i])
    result = str1[i] - str2[i];

  return result;
}