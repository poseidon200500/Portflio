#include "../s21_string.h"

int str_null(const char *delim);
int new_str(char *str, const char *delim);

static char *pointer = S21_NULL;
// указатель на элемент после делимитера найденного в прошлом цикле
static char *mem = S21_NULL;  // указатель на возвращаемую лексему
static int flag = 0;  // флаг, поднимаемый после первого выполнения функции

char *s21_strtok(char *str, const char *delim) {
  if (str != S21_NULL) {  // подаётся строка - либо первое выполнение, либо
    mem = S21_NULL;  // выполнение для новой строки(опять же, первое)
    flag = 0;        // начало работы
    if (delim != S21_NULL) {
      new_str(str, delim);
    }
  } else if (str == S21_NULL) {  // либо вывод новых лексем, либо выход
    if (flag != 0) {  // новые лексемы
      if (delim != S21_NULL && *pointer != '\0') {
        str_null(delim);
      } else {
        mem = S21_NULL;
      }
    } else {  // выход
      ;
    }
  }
  return mem;
}

int new_str(char *str, const char *delim) {
  int flag_break = 0;
  s21_size_t step = s21_strspn(str, delim);
  str += step;
  s21_size_t n = s21_strlen(str);
  for (s21_size_t i = 0; i < n; i++) {
    int delim_n = (int)s21_strlen(delim);
    for (int j = 0; j < delim_n; j++) {
      if (str[i] == delim[j]) {
        str[i] = '\0';
        mem = str;
        pointer = str + i + 1;
        flag = 1;
        flag_break = 1;
        break;
      }
    }
    if (delim_n == 0) {
      mem = str;
      pointer = str + s21_strlen(str);
      flag = 1;
      break;
    }
    if (flag_break == 1) {
      break;
    }
  }
  return 0;
}

int str_null(const char *delim) {
  s21_size_t step = s21_strspn(pointer, delim);
  if (step == 0) {
    mem = pointer;
  } else {
    pointer += step;
    mem = pointer;
  }
  int n_poin = (int)s21_strlen(pointer);
  char *p = S21_NULL;
  p = s21_strpbrk(pointer, delim);
  if (p != S21_NULL) {
    *p = '\0';
    pointer = pointer + (p - pointer) + 1;
  } else {
    pointer = pointer + n_poin;
  }
  if (!s21_strlen(mem)) {
    mem = S21_NULL;
  }
  return 0;
}