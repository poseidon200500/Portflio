#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  if (str && src) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    int size = src_len + str_len;  // + 1
    s21_size_t i = start_index;
    s21_size_t j = str_len;
    s21_size_t g = src_len - i;
    if (src_len >= start_index) {
      result = (char *)calloc(size + 2, sizeof(char));
      s21_memmove(result, src, i);
      s21_memmove(result + i, str, j);
      s21_memmove(result + i + j, src + i, g);
      result[size] = '\0';
    } else {
      result = S21_NULL;
    }
  }

  return result;
}