#include "../../s21_string.h"

void *s21_to_upper(const char *str) {
  char *result;
  s21_size_t i = 0;
  if (str == S21_NULL) {
    result = S21_NULL;
  } else {
    result = malloc(((s21_strlen(str) + 1) * sizeof(char)));
    while (str[i] != '\0') {
      if (str[i] >= 97 && str[i] <= 122) {
        result[i] = str[i] - 32;
      } else {
        result[i] = str[i];
      }
      i++;
    }
    result[i] = '\0';
  }
  return result;
}