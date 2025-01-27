#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int i = 0, j = 0;
  int marker = 0;
  if (haystack != S21_NULL && needle != S21_NULL) {
    if (!s21_strcmp(needle, "")) {
      result = (char *)haystack;
    } else {
      while (haystack[i] != '\0') {
        j = 0;
        while (needle[j] != '\0') {
          if (needle[j] != haystack[i + j]) {
            break;
          }
          if (haystack[i + j] == '\0') {
            break;
          }
          j++;
        }
        if (needle[j] == '\0') {
          marker += 1;
          break;
        }
        i++;
      }
      if (marker != 0) {
        result = (char *)haystack + i;
      }
    }
  }
  return result;
}