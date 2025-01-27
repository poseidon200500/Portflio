#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "../../s21_string.h"

#if defined(__APPLE__)
#define STR_NULL "(null)"
#endif
#if defined(__linux__)
#define STR_NULL "(nil)"
#endif

typedef union {
  void *p;
  long double ld;
  long long int li;
} UnionVal;

typedef struct specif {
  char spec;
  char mod;
  int width;
  int setWidth;
  int countMod;
  char pod;
  int count;
  UnionVal val;
  int err;
  char next;
  int countB;
} Specif;

int spec_func(Specif *sp, const char *format, int countB);
int valueToString(Specif *sp, va_list ptr, const char *str, int *countB,
                  int count);
int switch_feg(char *str, Specif *sp);
int logicIDU(Specif *sp, char *str, char *suc, int count, int mark, int notion);
int set_notion(Specif *sp);
int modDIN(void *pointer, Specif *sp);
int modUXO(void *pointer, Specif *sp);
int switch_func(void *pointer, Specif *sp, va_list ptr);
int mark_set(char *str, int *mark, Specif *sp);

char toUperChar(char c);
char toLowerChar(char c);
s21_size_t strlen_mod(char *s);
int isWhiteSpace(char c);

void setValue(va_list ptr, Specif *sp);
int strToStr(char *str, Specif *sp);

int isNanInfS(const char *str);
int getIntFEG(char *str, Specif *sp);
int getIntIDU(char *str, Specif *sp);

long double getValueModDoub(Specif sp, va_list ptr);
long long getValueModInt(Specif sp, va_list ptr);
long long unsigned getValueModUInt(Specif sp, va_list ptr);

char *strchrsc(const char *str, int c);

int getValueS(char *str, Specif *sp);
int initStructS(char *str, Specif *sp);
int parseToIntS(char *str, int *val);

int s21_sscanf(const char *str, const char *format, ...) {
  int count = 0;
  int countB = 0;
  int flags = 1;
  Specif sp = {0};
  char *start = (char *)str;
  char *startf = (char *)format;
  va_list ptr;
  va_start(ptr, format);
  while (*format) {
    if (*format == '%') {
      flags = 1;
      format++;
      int a = spec_func(&sp, format, countB);
      if (-1 == a) break;
      format += a;
      int step = countB;
      count = valueToString(&sp, ptr, str, &countB, count);
      str += countB - step;
    } else {
      if ((isWhiteSpace(*format) || *format == *str) && flags) {
        if (*format != *str) {
          format++;
        } else {
          format++;
          str++;
          countB++;
        }
      } else {
        flags = 0;
        format++;
      }
    }
  }
  va_end(ptr);
  str = start;
  format = startf;
  return count;
}

int spec_func(Specif *sp, const char *format, int countB) {
  char *spec = "cdieEfgGosuxXpn%";
  int a = (long long int)s21_strpbrk(format, spec) - (long long int)format +
          1;  // + 1
  char *buf = (char *)calloc(a + 1, sizeof(char));
  s21_strncpy(buf, format, a);
  initStructS(buf, sp);
  sp->countB = countB;
  sp->next = *(format + a);
  free(buf);
  if (sp->err) {
    a = -1;
  }

  return a;
}

int valueToString(Specif *sp, va_list ptr, const char *str, int *countB,
                  int count) {
  int size = 0;
  sp->count = count;
  while (isWhiteSpace(*str) && 'c' != sp->spec) {
    str++;
    (*countB)++;
  }
  if ('\0' == *str && 'n' != sp->spec && '%' != sp->spec) {
    sp->err = -1;
  } else {
    if (sp->setWidth && !sp->width) {
      sp->width = 1;
    }
    size = getValueS((char *)str, sp);
    if ('p' == sp->spec && !size) {
      sp->spec = '%';
    }
  }
  if (sp->err) {
    if (-1 == sp->err) {
      if (!count) {
        count = -1;
      }
    }
  } else {
    str += size;
    *countB += size;
    if ('s' != sp->spec || size) {
      setValue(ptr, sp);
    }
    if (!sp->err) {
      count = sp->count;
    } else {
      count = -1;
    }
  }
  return count;
}

int strToStr(char *str, Specif *sp) {
  s21_size_t counter = 0;
  s21_size_t size = 0;
  if (isWhiteSpace(*str)) {
    str++;
    counter++;
  }
  s21_size_t len = strlen_mod(str);
  size = sp->setWidth ? (unsigned long)sp->width : len;
  char *string = calloc(size + 1, sizeof(char));
  char spase[7] = {9, 10, 11, 12, 13, 32, 0};
  if (len) {
    for (s21_size_t i = 0; i < size && *str && !s21_strchr(spase, *str); ++i) {
      string[i] = *(str);
      str++;
      counter++;
    }
  }
  sp->val.p = string;
  return counter < size ? counter : size;
}

s21_size_t strlen_mod(char *s) {
  s21_size_t len = 0;
  while (*s != 0 && isWhiteSpace(*s) == 0) {
    s++;
    len++;
  }
  return len;
}

int isWhiteSpace(char c) {
  char spase[7] = {9, 10, 11, 12, 13, 32, 0};
  return strchrsc(spase, c) ? 1 : 0;
}

int strToChar(const char *str, Specif *sp) {
  s21_size_t len = s21_strlen(str);
  s21_size_t size =
      sp->setWidth ? (sp->width < (int)len ? (s21_size_t)sp->width : len) : 1;
  char *pointer = malloc(size * sizeof(char));
  int spa = 0;
  s21_memcpy(pointer, str, size);
  if (isWhiteSpace(sp->next)) {
    spa += size;
    while (isWhiteSpace(*(str + size))) {
      str++;
      spa++;
    }
  }
  sp->val.p = pointer;
  return (int)size > spa ? (int)size : spa;
}

int getValueS(char *str, Specif *sp) {
  int count = 0;
  switch (toLowerChar(sp->spec)) {
    case 'i':
    case 'd':
    case 'u':
    case 'x':
    case 'o':
      count = getIntIDU(str, sp);
      break;
    case 'p':
      count = getIntIDU(str, sp);
      break;
    case 'n':
      sp->val.li = sp->countB;
      break;
    case 'c':
      count = strToChar(str, sp);
      break;
    case 's':
      count = strToStr(str, sp);
      break;
    case '%':
      if ('%' == *str) {
        count = 1;
      } else {
        sp->err = 1;
      }
      break;
    case 'f':
    case 'e':
    case 'g':;
      count = switch_feg(str, sp);
      break;
  }
  return count;
}

int switch_feg(char *str, Specif *sp) {
  int count = 0;
  int res = isNanInfS(str);
  if (1 == res) {
    if ('-' == *str) {
      sp->val.ld = -NAN;
      count += 4;
    } else if ('+' == *str) {
      sp->val.ld = NAN;
      count += 4;
    } else {
      sp->val.ld = NAN;
      count += 3;
    }
  } else if (2 == res) {
    if ('-' == *str) {
      sp->val.ld = -INFINITY;
      count += 4;
    } else if ('+' == *str) {
      sp->val.ld = INFINITY;
      count += 4;
    } else {
      sp->val.ld = INFINITY;
      count += 3;
    }
  } else {
    count = getIntFEG(str, sp);
  }
  return count;
}

int set_notion(Specif *sp) {
  int notion = 10;
  if (strchrsc("xXp", sp->spec)) {
    notion = 16;
  }
  if (strchrsc("o", sp->spec)) {
    notion = 8;
  }
  if (strchrsc("i", sp->spec)) {
    notion = 0;
  }
  return notion;
}

int getIntIDU(char *str, Specif *sp) {
  int count = 0;
  int notion = set_notion(sp);
  char spase[7] = {9, 10, 11, 12, 13, 32, 0};
  while (strchrsc(spase, *str)) {
    str++;
    count++;
  }
  if ('p' == sp->spec && '0' == *str && 'x' == *(str + 1)) {
    str += 2;
    count += 2;
    if (sp->setWidth) {
      sp->width -= 2;
      if (!sp->width) {
        sp->err = 1;
      }
    }
  }
  int mark = 1;
  int step = mark_set(str, &mark, sp);
  count += step;
  str += step;
  char *suc = S21_NULL;
  if ('o' == sp->spec) {
    suc = "01234567";
  } else if ('x' == toLowerChar(sp->spec) || 'i' == sp->spec ||
             'p' == sp->spec) {
    suc = "0123456789abcdefABCDEF";
  } else {
    suc = "0123456789";
  }
  return logicIDU(sp, str, suc, count, mark, notion);
}

int logicIDU(Specif *sp, char *str, char *suc, int count, int mark,
             int notion) {
  long long int result = 0;
  if (!sp->err && strchrsc(suc, *str)) {
    if (sp->setWidth) {
      int size = (int)s21_strspn(str, "0123456789abcdefABCDEFx");
      sp->width = sp->width > size ? size : sp->width;
      char *buf = (char *)calloc((sp->width + 1), sizeof(char));
      s21_strncpy(buf, str, sp->width);
      result = strtoll(buf, S21_NULL, notion);
      count += sp->width;
      free(buf);
    } else {
      char *st = str;
      result = strtoll(str, &str, notion);
      count += str - st;
    }
    if (errno == ERANGE && 0 > mark && result == INT64_MAX) {
      result *= mark;
      result -= 1;
    } else {
      result *= mark;
    }
    sp->val.li = result;
  } else {
    if ('p' != sp->spec && !sp->err) {
      if ('\0' != *str) {
        sp->err = 1;
      } else {
        sp->err = -1;
      }
    }
  }
  return count;
}

char toUperChar(char c) { return (96 < c && 123 > c) ? c - 32 : c; }

char toLowerChar(char c) { return (64 < c && 91 > c) ? c + 32 : c; }

void setValue(va_list ptr, Specif *sp) {
  if ('*' != sp->pod) {
    void *pointer = S21_NULL;
    if ('p' != sp->spec && '%' != sp->spec) {
      pointer = va_arg(ptr, void *);
    }
    switch_func(pointer, sp, ptr);
    if ('n' != sp->spec && '%' != sp->spec) {
      sp->count += 1;
    }
  }
  if ('c' == sp->spec || 's' == sp->spec) {
    free(sp->val.p);
  }
}

int modDIN(void *pointer, Specif *sp) {
  if (2 == sp->countMod) {
    if ('l' == sp->mod) {
      *(long long *)pointer = (long long)sp->val.li;
    } else if ('h' == sp->mod) {
      *(signed char *)pointer = (signed char)(long int)sp->val.li;
    }
  } else {
    if ('l' == sp->mod) {
      *(long *)pointer = (long)sp->val.li;
    } else if ('h' == sp->mod) {
      *(short *)pointer = (short)(long int)lroundl(sp->val.li);
    } else {
      *(int *)pointer = (int)sp->val.li;
    }
  }
  return 0;
}

int modUXO(void *pointer, Specif *sp) {
  if (2 == sp->countMod) {
    if ('l' == sp->mod) {
      *(unsigned long long *)pointer = (unsigned long long)sp->val.li;
    } else if ('h' == sp->mod) {
      *(unsigned char *)pointer = (unsigned char)(long int)(double)sp->val.li;
    }
  } else {
    if ('l' == sp->mod) {
      *(unsigned long *)pointer = (unsigned long)sp->val.li;
    } else if ('h' == sp->mod) {
      *(unsigned short *)pointer = (unsigned short)(long int)(double)sp->val.li;
    } else {
      *(unsigned int *)pointer = (unsigned int)sp->val.li;
    }
  }
  return 0;
}

int switch_func(void *pointer, Specif *sp, va_list ptr) {
  switch (toLowerChar(sp->spec)) {
    case 'd':
    case 'i':
    case 'n':
      modDIN(pointer, sp);
      break;
    case 'u':
    case 'x':
    case 'o':
      modUXO(pointer, sp);
      break;
    case 'p':
      *(va_arg(ptr, void **)) = (void *)sp->val.li;
      break;
    case 'f':
    case 'e':
    case 'g':
      if ('l' == sp->mod) {
        *(double *)pointer = (double)sp->val.ld;
      } else if ('L' == sp->mod) {
        *(long double *)pointer = sp->val.ld;
      } else {
        *(float *)pointer = (float)sp->val.ld;
      }
      break;
    case 'c':
      s21_memcpy(pointer, sp->val.p, sp->setWidth ? sp->width : 1);
      break;
    case 's':
      s21_strcpy((char *)pointer, (char *)(sp->val.p));
      break;
  }
  return 0;
}

//////////////////// init my struct /////////////

int initStructS(char *str, Specif *sp) {
  int err = 0;
  char *modif = "hlL";
  char *spec = "cdieEfgGosuxXpn%";
  Specif qwer = {0};
  *sp = qwer;
  while (*str != '\0' && !err) {
    if (*str == '*') {
      sp->pod = '*';
      str++;
    } else if (*str >= '0' && *str <= '9') {
      str += parseToIntS(str, &(sp->width));
      sp->setWidth = 1;
    }
    while (strchrsc(modif, *str) && !err) {
      if ('\0' == sp->mod) {
        sp->mod = *str;
        sp->countMod = 1;
        str++;
      } else if (sp->mod == *str && sp->countMod < 2) {
        sp->countMod = 2;
        str++;
      } else {
        err = 1;
      }
    }
    if (!sp->spec) {
      if (strchrsc(spec, *str) && !err) {
        sp->spec = *str;
        str++;
      }
    } else {
      err = 1;
    }
  }
  return err;
}

int parseToIntS(char *str, int *val) {
  int count = 0;
  *val = 0;
  while (*str >= '0' && *str <= '9') {
    *val *= 10;
    *val += *str - '0';
    str++;
    count++;
  }

  return count;
}

char *strchrsc(const char *str, int c) {
  char *res = S21_NULL;
  int size = (int)s21_strlen(str);
  if (0 <= c && 127 >= c) {
    for (int i = 0; i < size; i++) {
      if (str[i] == c) {
        res = (char *)str + i;
        break;
      }
    }
  }
  return res;
}

int getIntFEG(char *str, Specif *sp) {
  long double result = 0;
  int count = 0;
  char spase[7] = {9, 10, 11, 12, 13, 32, 0};
  while (strchrsc(spase, *str)) {
    str++;
    count++;
  }
  int mark = 1;
  int step = mark_set(str, &mark, sp);
  count += step;
  str += step;
  if ('.' == *str && !strchrsc("0123456789", *(str + 1))) {
    sp->err = 1;
  }
  if (!sp->err && strchrsc("0123456789.", *str)) {
    if (sp->setWidth) {
      int size = (int)s21_strspn(str, "0123456789e-+.");
      sp->width = sp->width > size ? size : sp->width;
      char *buf = (char *)calloc((sp->width + 1), sizeof(char));
      s21_strncpy(buf, str, sp->width);
      result = strtold(buf, S21_NULL);
      count += sp->width;
      free(buf);
    } else {
      char *st = str;
      result = strtold(str, &str);
      count += str - st;
    }
    result *= mark;
    sp->val.ld = result;
  } else {
    if (!sp->err) {
      sp->err = 1;
    }
  }
  return count;
}

int mark_set(char *str, int *mark, Specif *sp) {
  int count = 0;
  if ('+' == *str || '-' == *str) {
    if ('-' == *str) {
      *mark = -1;
    }
    if (sp->setWidth) {
      sp->width--;
      if (!sp->width) {
        sp->err = 1;
      }
    }
    str++;
    count++;
  }
  return count;
}

int isNanInfS(const char *str) {
  int result = 0;
  if ('-' == *str || '+' == *str) {
    str++;
  }
  char *buf = s21_to_lower(str);
  if (!s21_strncmp(buf, "nan", 3)) {
    result = 1;
  }
  if (!s21_strncmp(buf, "inf", 3)) {
    result = 2;
  }
  free(buf);
  return result;
}
