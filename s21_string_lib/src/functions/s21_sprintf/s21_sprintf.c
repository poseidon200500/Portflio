// #include "../s21_string.h"
#include <math.h>
#include <stdarg.h>
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

typedef struct flags {
  int min;
  int pl;
  int spase;
  int grid;
  int zero;
} Flags;

typedef struct specif {
  char spec;
  char mod;
  int countMod;
  Flags flag;
  int width;
  int precision;
  int prec;
  char pod;
  int count;
} Specif;

int helpInit(const char *format, Specif *sp, va_list ptr);
int formatCase(char *buf, Specif sp);
char toLowerCharP(char c);
int specifP(char *str, Specif *sp, va_list ptr);
int specifFE(char *str, Specif *sp, va_list ptr);
int specifG(char *str, Specif *sp, va_list ptr);
void helpFormat(char *str, Specif sp);
int precisionAndWidth(char *str, Specif *sp, va_list ptr);
long double forMyRound(Specif sp, char *str, long double a, int *man);

s21_size_t stringWcharCpy(char *str, char c);
int stringToString(Specif sp, char *str, va_list ptr);
int charToString(Specif sp, char *str, va_list ptr);

int getChar(Specif sp, char *str, char c);
int getWchar(Specif sp, char *str, wchar_t c);

int stringWcpy(char *str, wchar_t *buf, Specif sp);
int stringCpy(char *str, char *buf, Specif sp);
int formatWcharString(Specif sp, char *str, wchar_t *buf);
int formatCharString(Specif sp, char *str, char *buf);

int stringDuble(Specif sp, char *str, long double a);
int getCifer(char *str, __int128_t a, int notation);
int getCiferU(char *str, long long unsigned a, int notation);
int longDefine(int a);

long double getValueModDoub(Specif sp, va_list ptr);
long long getValueModInt(Specif sp, va_list ptr);
long long unsigned getValueModUInt(Specif sp, va_list ptr);

int formatForInputFl(char *str, Specif sp);
int formatForInputInt(Specif sp, char *str);
int fillingInWidthBuffer(Specif sp, char *buf, int n);
int insertMy(char *str, int c, s21_size_t n);

int getValue(char *str, Specif *sp, va_list ptr);
int initStruct(char *str, Specif *sp, va_list ptr);
int parseToInt(char *str, int *val);

long double myRound(Specif sp, char *str, long double a, int *man);
int doubleToStringG(char *str, long double a, Specif *sp);
int doubleToString(char *str, long double a, Specif sp);
int signedToString(char *str, __int128_t a, Specif sp);
int unsignedToString(char *str, long long unsigned a, Specif sp);

int s21_sprintf(char *str, const char *format, ...) {
  int count = 0;
  Specif sp = {0};
  char *start = str;
  va_list ptr;
  va_start(ptr, format);
  while (*format) {
    if (*format == '%') {
      format++;
      format += helpInit(format, &sp, ptr);
      {
        char buf[4096] = "";
        sp.count = count;
        int size = getValue(buf, &sp, ptr);
        if (s21_strchr("iduoxXp", sp.spec)) {
          formatForInputInt(sp, buf);
        }
        int n = formatCase(buf, sp);
        size = (size > n) ? size : (int)n;
        s21_memmove(str, buf, size);
        str += size;
        count += size;
      }
    } else {
      if (*format != '\0') {
        *str = *format;
        str++;
        count++;
      }
      format++;
    }
  }
  va_end(ptr);
  *str = '\0';
  str = start;
  return count;
}

int helpInit(const char *format, Specif *sp, va_list ptr) {
  char *spec = "cdieEfgGosuxXpn%";
  int a = (long long int)s21_strpbrk(format, spec) - (long long int)format +
          1;  // + 1
  char *buf = (char *)calloc(a + 1, sizeof(char));
  s21_strncpy(buf, format, a);
  initStruct(buf, sp, ptr);
  free(buf);
  return a;
}

int formatCase(char *buf, Specif sp) {
  if (s21_strchr("xge", sp.spec)) {
    for (size_t i = 0; buf[i]; i++) {
      if (64 < buf[i] && 91 > buf[i]) {
        buf[i] += 32;
      }
    }
  }
  if (s21_strchr("XGE", sp.spec)) {
    for (size_t i = 0; buf[i]; i++) {
      if (96 < buf[i] && 123 > buf[i]) {
        buf[i] -= 32;
      }
    }
  }
  s21_size_t n = s21_strlen(buf);
  if (s21_strchr("p", sp.spec)) {
#if defined(__linux__)
    if (sp.flag.pl) {
      s21_memmove(buf + 1, buf, n);
      *buf = '+';
    } else if (sp.flag.spase) {
      s21_memmove(buf + 1, buf, n);
      *buf = ' ';
    }
#endif
    for (size_t i = 0; buf[i]; i++) {
      if (64 < buf[i] && 71 > buf[i]) {
        buf[i] += 32;
      }
    }
  }
  return n;
}

char toLowerCharP(char c) { return (64 < c && 91 > c) ? c + 32 : c; }

int getValue(char *str, Specif *sp, va_list ptr) {
  int count = 0;
  switch (toLowerCharP(sp->spec)) {
    case 'i':
    case 'd': {
      signedToString(str, getValueModInt(*sp, ptr), *sp);
    } break;
    case 'o':
    case 'x':
    case 'u': {
      unsignedToString(str, getValueModUInt(*sp, ptr), *sp);
    } break;
    case 'c': {
      count = charToString(*sp, str, ptr);
    } break;
    case 's': {
      count = stringToString(*sp, str, ptr);
    } break;
    case 'n': {
      *(va_arg(ptr, int *)) = sp->count;
    } break;
    case '%': {
      *str = '%';
      str++;
      count++;
    } break;
    case 'p': {
      count = specifP(str, sp, ptr);
    } break;
    case 'f':
    case 'e': {
      count = specifFE(str, sp, ptr);
    } break;
    case 'g': {
      count = specifG(str, sp, ptr);
    } break;
  }
  return count;
}

int specifP(char *str, Specif *sp, va_list ptr) {
  int count = 0;
  sp->flag.grid = 1;
  long long unsigned int a = (long long unsigned)va_arg(ptr, void *);
#if defined(__linux__)
  if (0 == a) {
    sp->spec = 's';
    count = formatCharString(*sp, str, STR_NULL);
  } else {
#endif
    count = unsignedToString(str, a, *sp);
#if defined(__linux__)
  }
#endif
  return count;
}

int specifFE(char *str, Specif *sp, va_list ptr) {
  int count = 0;
  long double a = getValueModDoub(*sp, ptr);
  if (isnan(a)) {
    if (a < 0) {
      s21_strcpy(str, "-nan");
    } else {
      s21_strcpy(str, "nan");
    }
  } else if (isinf(a)) {
    if (a < 0) {
      s21_strcpy(str, "-inf");
    } else {
      s21_strcpy(str, "inf");
    }
  } else {
    count = doubleToString(str, a, *sp);
    if (s21_strchr("feEgG", sp->spec)) {
      formatForInputInt(*sp, str);
    }
  }
  return count;
}

int specifG(char *str, Specif *sp, va_list ptr) {
  int count = 0;
  long double a = getValueModDoub(*sp, ptr);
  if (isnan(a)) {
    if (a < 0) {
      s21_strcpy(str, "-nan");
    } else {
      s21_strcpy(str, "nan");
    }
  } else if (isinf(a)) {
    if (a < 0) {
      s21_strcpy(str, "-inf");
    } else {
      s21_strcpy(str, "inf");
    }
  } else {
    count = doubleToStringG(str, a, sp);
    if (s21_strchr("feEgG", sp->spec)) {
      formatForInputInt(*sp, str);
    }
  }
  return count;
}

int charToString(Specif sp, char *str, va_list ptr) {
  int count = 0;
  if ('l' == sp.mod) {
    wchar_t buf = va_arg(ptr, wchar_t);
    count = getWchar(sp, str, buf);
  } else {
    char buf = va_arg(ptr, int);
    count = getChar(sp, str, buf);
  }
  return count;
}

int getWchar(Specif sp, char *str, wchar_t c) {
  int count = 0;
  char buf[256] = {'\0'};
  wctomb(buf, c);
  char dop = ' ';
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
  s21_size_t n = s21_strlen(buf);
  if ((int)n < sp.width) {
    if (sp.flag.min) {
      // |<-
      s21_strcpy(str, buf);
      for (int i = (int)n; i < sp.width; i++) {
        str[i] = dop;
      }
      str[sp.width] = '\0';
    } else {
      // ->|
      for (int i = 0; i < sp.width - (int)n; i++) {
        str[i] = dop;
      }
      s21_strcpy(str + (sp.width - (int)n), buf);
    }
    count = sp.width;
  } else {
    s21_strcpy(str, buf);
    count = (int)n;
  }
  return count;
}

int getChar(Specif sp, char *str, char c) {
  int count = 0;
  char dop = ' ';
#if defined(__APPLE__)
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
#endif
  if (1 < sp.width) {
    if (sp.flag.min) {
      // |<-
      *str = c;
      for (int i = 1; i < sp.width; i++) {
        str[i] = dop;
      }
      str[sp.width] = '\0';
    } else {
      // ->|
      for (int i = 0; i < sp.width - 1; i++) {
        str[i] = dop;
      }
      str[sp.width - 1] = c;
    }
    count = sp.width;
  } else {
    *str = c;
    count++;
  }
  return count;
}

int stringToString(Specif sp, char *str, va_list ptr) {
  int count = 0;
  char *null = (char *)calloc(7, sizeof(char));
  s21_strncpy(null, STR_NULL, 7);
  if ('l' == sp.mod) {
    wchar_t *buf = va_arg(ptr, wchar_t *);
    if (buf == S21_NULL) {
      count = formatCharString(sp, str, null);
    } else {
      count = formatWcharString(sp, str, buf);
    }
  } else {
    char *buf = va_arg(ptr, char *);
    if (buf == S21_NULL) {
      buf = null;
    }
    count = formatCharString(sp, str, buf);
  }
  free(null);
  return count;
}

int formatWcharString(Specif sp, char *str, wchar_t *buf) {
  int count = 0;
  char bus[4096] = "";
  stringWcpy(bus, buf, sp);
  int size = (sp.precision && sp.prec) ? sp.precision : (int)s21_strlen(bus);
  char dop = ' ';
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
  if (size < sp.width) {
    if (sp.flag.min) {
      // |<-
      s21_strcpy(str, bus);
      for (int i = size; i < sp.width; i++) {
        str[i] = dop;
      }
      str[sp.width] = '\0';
    } else {
      // ->|
      for (int i = 0; i < sp.width - size; i++) {
        str[i] = dop;
      }
      s21_strcpy(str + (sp.width - size), bus);
    }
    count = sp.width;
  } else {
    s21_strcpy(str, bus);
    count = size;
  }
  return count;
}

int formatCharString(Specif sp, char *str, char *buf) {
  int count = 0;
  s21_size_t n = s21_strlen(buf);
  int size =
      (sp.prec) ? (sp.precision > (int)n ? (int)n : sp.precision) : (int)n;
  char dop = ' ';
#if defined(__APPLE__)
  if (sp.flag.zero && !sp.flag.min) {
    dop = '0';
  }
#endif
  if (size < sp.width) {
    if (sp.flag.min) {
      // |<-
      stringCpy(str, buf, sp);
      for (int i = size; i < sp.width; i++) {
        str[i] = dop;
      }
      str[sp.width] = '\0';
    } else {
      // ->|
      for (int i = 0; i < sp.width - size; i++) {
        str[i] = dop;
      }
      stringCpy(str + (sp.width - size), buf, sp);
    }
    count = sp.width;
  } else {
    stringCpy(str, buf, sp);
    count = size;
  }
  return count;
}

int stringCpy(char *str, char *buf, Specif sp) {
  if (sp.prec) {
    s21_strncpy(str, buf, sp.precision);
  } else {
    s21_strcpy(str, buf);
  }
  return 0;
}

int stringWcpy(char *str, wchar_t *buf, Specif sp) {
  if (sp.precision && sp.prec) {
    for (int i = 0; i < sp.precision; i++) {
      str += stringWcharCpy(str, buf[i]);
    }
  } else {
    for (int i = 0; buf[i] != '\0'; i++) {
      str += stringWcharCpy(str, buf[i]);
    }
  }
  return 0;
}

s21_size_t stringWcharCpy(char *str, char c) {
  char bus[256] = {'\0'};
  wctomb(bus, c);
  s21_strcpy(str, bus);
  return s21_strlen(bus);
}

//////////////////// init my struct /////////////

int initStruct(char *str, Specif *sp, va_list ptr) {
  char *flag = "-+ #0";
  char *modif = "hlL";
  Specif qwer = {0};
  qwer.precision = 1;
  *sp = qwer;
  while (*str != '\0') {
    while (s21_strchr(flag, *str)) {
      int *p = (int *)&(sp->flag);
      *(p + (s21_strchr(flag, *str) - flag)) = 1;
      str++;
    }
    str += precisionAndWidth(str, sp, ptr);
    while (s21_strchr(modif, *str)) {
      sp->mod = *str;
      sp->countMod++;
      str++;
    }
    sp->spec = *str;
    sp->pod = *str;
    str++;
  }
  if (!sp->prec && s21_strchr("eEfgG", sp->spec)) {
    sp->precision = 6;
  }
  if (!sp->prec && !(s21_strchr("eEfgG", sp->spec))) {
    sp->precision = 1;
  }
  return 0;
}

int precisionAndWidth(char *str, Specif *sp, va_list ptr) {
  int step = 0;
  if ((*str >= '0' && *str <= '9') || *str == '*') {  // если цифра
    if (*str == '*') {
      sp->width = va_arg(ptr, int);
    } else {
      step +=
          parseToInt(str, &(sp->width));  // то забираю все цифры в число width
      str += step;
    }
  }
  if (*str == '.') {  // если точка то после число точности
    str++;
    step++;
    sp->prec = 1;
    if (*str == '*') {
      sp->precision = va_arg(ptr, int);
    } else {
      if ('9' >= *str && '0' <= *str) {
        int by = parseToInt(
            str, &(sp->precision));  // то забираю все цифры в число precision
        str += by;
        step += by;
      } else {
        sp->precision = 0;
      }
    }
  }
  return step;
}

int parseToInt(char *str, int *val) {
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

//////////////////////////////////////////////////////

////////////////////// Number to String///////////////////////////

int doubleToStringG(char *str, long double a, Specif *sp) {
  char bufE[4096] = "";
  if (!sp->precision) {
    sp->precision = 1;
  }
  int man = 0;
  sp->spec = 'e';
  myRound(*sp, bufE, a, &man);
  sp->spec = 'g';
  if (-4 <= man && man < sp->precision) {
    sp->spec = 'f';
    sp->precision = sp->precision - (man + 1);
  } else {
    sp->spec = 'e';
    sp->precision = sp->precision - 1;
  }
  doubleToString(str, a, *sp);
  sp->spec = 'g';
  return 0;
}

long double myRound(Specif sp, char *str, long double a, int *man) {
  int round = 5;
  if (0 > a) {
    round *= -1;
  }
  a = forMyRound(sp, str, a, man);
  if (a != 0) {
    double vr = pow(0.1, sp.precision + 1);
    a += round * vr;
  }
  a = forMyRound(sp, str, a, man);
  return a;
}

long double forMyRound(Specif sp, char *str, long double a, int *man) {
  if (s21_strchr("eE", sp.spec)) {
    if (a == 0) {
      *str = '0';
      if (sp.precision) {
        *(str + 1) = '.';
        *(str + 2) = '0';
      }
    } else {
      if ((long long int)(a) == 0) {
        while ((long long int)a == 0) {
          a *= 10;
          (*man)--;
        }
      } else {
        while (9 < (long long int)a || -9 > (long long int)a) {
          a /= 10;
          (*man)++;
        }
      }
    }
  }
  return a;
}

int getCifer(char *str, __int128_t a, int notation) {
  int count = 0;
  if (9 < a) {
    count += getCifer(str, a / notation, notation);
    str += count;
  }
  int buf = a % notation;
  *str = buf + '0';
  count++;
  return count;
}

int getCiferU(char *str, long long unsigned a, int notation) {
  int count = 0;
  if ((long long unsigned)(notation - 1) < a) {
    count += getCiferU(str, a / notation, notation);
    str += count;
  }
  int buf = a % notation;
  if (buf > 9 && notation == 16) {
    *str = buf + 55;
  } else {
    *str = buf + '0';
  }
  count++;
  return count;
}

int doubleToString(char *str, long double a, Specif sp) {
  if (sp.flag.min) {
    sp.flag.zero = 0;
  }
  if (sp.flag.pl) {
    sp.flag.spase = 0;
  }
  int count = 0;
  char mark = '+';
  int man = 0;
  a = myRound(sp, str, a, &man);
  stringDuble(sp, str, a);
  if ('e' == sp.spec || 'E' == sp.spec) {
    if (man < 0) {
      man *= -1;
      mark = '-';
    }

    str += s21_strlen(str);
    *str = sp.spec;
    *(str + 1) = mark;
    if (man < 10) {
      *(str + 2) = '0';
      *(str + 3) = '0' + man;
      count += 2;
    } else {
      count += getCifer(str + 2, man, 10);
    }
    count += 2;
  }

  return count;
}

int stringDuble(Specif sp, char *str, long double a) {
  __int128_t whole = (__int128_t)a;
  char *buf = str;
  long double fractional;
  if (0 > a) {
    fractional = whole - a;
  } else {
    fractional = a - whole;
  }
  str += signedToString(str, whole, sp);
  if (sp.precision || sp.flag.grid) {
    *str = '.';
    str++;

    for (int i = 0; i < sp.precision; i++) {
      fractional = (fractional - (int)fractional) * 10;
      int buf = (int)fractional;
      *str = buf % 10 + '0';
      str++;
    }
    if (s21_strcmp(str, "0")) {
      if (s21_strchr("gG", sp.pod) && !sp.flag.grid) {
        formatForInputFl(buf, sp);
      };
    }
  }
  return 0;
}

int unsignedToString(char *str, long long unsigned a, Specif sp) {
  int count = 0;
  int notation = 10;
  if (sp.spec == 'o') {
    notation = 8;
  } else if ('x' == sp.spec || 'X' == sp.spec || 'p' == sp.spec) {
    notation = 16;
  }
  if (0 == a) {
    *str = '0';
    count++;
  } else {
    int step = getCiferU(str, a, notation);
    str += step;
    count += step;
  }
  return count;
}

int signedToString(char *str, __int128_t a, Specif sp) {
  int count = 0;
  if (sp.flag.pl && 0 <= a) {
    *str = '+';
    str++;
    count++;
  }
  if (0 > a) {
    *str = '-';
    str++;
    count++;
    a *= -1;
  } else {
    if (!sp.flag.pl && sp.flag.spase) {
      *str = ' ';
      str++;
      count++;
    }
  }
  if (0 == a) {
    *str = '0';
    count++;
  } else {
    int step = getCifer(str, a, 10);
    str += step;
    count += step;
  }
  return count;
}

/////////////////////////////////////////////////

/////////////////////modificator l L ll h///////////////////////////

long double getValueModDoub(Specif sp, va_list ptr) {
  long double result = 0;

  if (sp.mod == '\0') {
    result = va_arg(ptr, double);
  }
  if (sp.mod == 'L') {
    result = va_arg(ptr, long double);
  }
  if (sp.mod == 'h') {
    result = va_arg(ptr, double);
  }
  if (sp.mod == 'l') {
    result = va_arg(ptr, double);
  }
  return result;
}

long long getValueModInt(Specif sp, va_list ptr) {
  long long result = 0;
  if (sp.mod == 'h') {
    result = (short int)va_arg(ptr, int);
  }
  if (sp.mod == 'l') {
    if (1 < sp.countMod) {
      result = (long long int)va_arg(ptr, long long int);
    } else {
      result = (long int)va_arg(ptr, long int);
    }
  }
  if (sp.mod == '\0') {
    result = (int)va_arg(ptr, int);
  }
  return result;
}

long long unsigned getValueModUInt(Specif sp, va_list ptr) {
  long long unsigned result = 0;
  if (sp.mod == 'h') {
    result = (unsigned short int)va_arg(ptr, unsigned int);
  }
  if (sp.mod == 'l') {
    if (1 < sp.countMod) {
      result = (long long unsigned)va_arg(ptr, long long unsigned int);
    } else {
      result = (long unsigned)va_arg(ptr, long unsigned int);
    }
  }
  if (sp.mod == '\0') {
    result = (unsigned)va_arg(ptr, unsigned int);
  }
  return result;
}

///////////////////////////////////////////////

//////////////////////// format for input ///////////////

int formatForInputFl(char *str, Specif sp) {
  int n = (int)s21_strlen(str);
  for (int i = n - 1; str[i] == '0'; i--) {
    str[i] = '\0';
  }
  int m = (int)s21_strlen(str);
  if (str[m - 1] == '.' && !sp.flag.grid) {
    str[m - 1] = '\0';
  }
  return 0;
}

int formatForInputInt(Specif sp, char *str) {
  if (0 == sp.precision && (!s21_strcmp(str, " 0") || !s21_strcmp(str, "0"))) {
    if (!s21_strchr("fgG", sp.spec)) {
      *(s21_strchr(str, '0')) = '\0';
    }
  }
  if (sp.flag.grid && 'o' == sp.spec) {
    if (s21_strcmp(str, " 0") && s21_strcmp(str, "0")) {
      insertMy(str, '0', 1);
    }
  }
  helpFormat(str, sp);
  int nn = (int)s21_strlen(str);
  if ((int)nn < sp.width) {
    if (sp.flag.min) {
      //  |<-
      s21_memset(str + nn, ' ', sp.width - nn);
    } else {
      //  ->|
      if (s21_strchr("eEfdgG", sp.spec)) {
        int n = sp.width - nn;
        if (('+' == *str || '-' == *str || ' ' == *str) && sp.flag.zero) {
          s21_memmove(str + n + 1, str + 1, nn);
          fillingInWidthBuffer(sp, str + 1, n);
        } else {
          s21_memmove(str + n, str, nn);
          fillingInWidthBuffer(sp, str, n);
        }
      } else {
        int n = sp.width - nn;
        s21_memmove(str + n, str, nn);
        fillingInWidthBuffer(sp, str, n);
      }
    }
  }
  return 0;
}

void helpFormat(char *str, Specif sp) {
  int m = (int)s21_strlen(str);
  if ('+' == *str || '-' == *str || ' ' == *str) {
    if ((m - 1) < sp.precision) {
      if (!s21_strchr("gG", sp.spec)) {
        insertMy(str + 1, '0', sp.precision - (m - 1));
      }
    }
    if (sp.flag.grid && ('x' == sp.spec || 'X' == sp.spec || 'p' == sp.spec)) {
      if ((s21_strcmp(str, " 0") && s21_strcmp(str, "0")) || 'p' == sp.spec) {
        insertMy(str, 'x', 1);
        insertMy(str, '0', 1);
      }
    }
  } else {
#if defined(__linux__)
    if (m < sp.precision &&
        (s21_strcmp(str, "0") ||
         s21_strchr("ouxXid", sp.spec))) {  // зануление перед нулём
      insertMy(str, '0', sp.precision - m);
    }
#endif
#if defined(__APPLE__)
    if (m < sp.precision &&
        (s21_strcmp(str, "0") ||
         s21_strchr("ouxXidp", sp.spec))) {  // зануление перед нулём
      if (!s21_strchr("gG", sp.spec)) {
        insertMy(str, '0', sp.precision - m);
      }
    }
#endif
    if (sp.flag.grid && ('x' == sp.spec || 'X' == sp.spec || 'p' == sp.spec)) {
      if ((s21_strcmp(str, " 0") && s21_strcmp(str, "0") &&
           (m != (int)s21_strspn(str, "0"))) ||
          'p' == sp.spec) {
        insertMy(str, 'x', 1);
        insertMy(str, '0', 1);
      }
    }
  }
}

int insertMy(char *str, int c, s21_size_t n) {
  s21_memmove(str + n, str, s21_strlen(str));
  s21_memset(str, c, n);
  return 0;
}

int fillingInWidthBuffer(Specif sp, char *buf, int n) {
  if (sp.flag.zero) {
    s21_memset(buf, '0', n);
  } else {
    s21_memset(buf, ' ', n);
  }
  return 0;
}

//////////////////////////////////////////
// #include <ctype.h>
// #include <stdarg.h>
// #include <stdlib.h>
// #include <math.h>
// #include <stdio.h>
// #include "../../s21_string.h"

// typedef struct {
//     char flags[5];   // Флаги форматирования
//     int width;       // Ширина поля
//     int precision;   // Точность
//     char length[3];  // Модификатор длины ("h", "l")
//     char type;       // Спецификатор типа
// } FormatSpec;

// void get_format_specifier(int *i, const char *format, FormatSpec *specifier,
// va_list *args);  // парсит спецификатор в строке и записвает в структуру
// FormatSpec specifier) void process_specifier(char *str, FormatSpec specifier,
// va_list *args, int *counter);  // обрабатывает аргумент по спецификатору void
// add_padding(char *str, FormatSpec specifier, unsigned long num_len, int
// is_negative, char pad_char, int *counter, int left_justify);  // для флагов -
// 0 void reverse(char *buffer, unsigned long length);  // доп функция для
// реверса строки, нужна в двух функциях ниже unsigned long
// integer_to_string(char *str, long long value, FormatSpec spec, int *counter);
// // перевод int и unsigned в строки unsigned long float_to_string(char *str,
// double value, FormatSpec spec, int *counter);  // перевод float в строки

// int s21_sprintf(char *str, const char *format, ...) {
//     va_list args;
//     va_start(args, format);

//     int counter = 0;
//     int format_len = (int)s21_strlen(format);

//     for (int i = 0; i < format_len; i++) {
//         if (format[i] == '%') {
//             i++;
//             FormatSpec specifier = {{0}, 0, 0, {'\0'}, '\0'};
//             get_format_specifier(&i, format, &specifier, &args);
//             process_specifier(str, specifier, &args, &counter);
//         } else {
//             str[counter++] = format[i];
//         }
//         str[counter] = '\0';
//     }
//     va_end(args);
//     return counter; // Возвращаем количество записанных символов
// }

// void get_format_specifier(int *i, const char *format, FormatSpec *specifier,
// va_list *args) {
//     // Сброс флагов
//     for (int j = 0; j < 5; j++) {
//         specifier->flags[j] = '\0';
//     }

//     // Обработка флагов
//     const char *valid_flags = "-+ #0";
//     for (; s21_strchr(valid_flags, format[*i]) != NULL; (*i)++) {
//         switch (format[*i]) {
//             case '-': specifier->flags[0] = '-'; break;
//             case '+': specifier->flags[1] = '+'; break;
//             case ' ': specifier->flags[2] = ' '; break;
//             case '#': specifier->flags[3] = '#'; break;
//             case '0': specifier->flags[4] = '0'; break;
//         }
//     }

//     // Обработка ширины
//     if (isdigit(format[*i])) {
//         for (; isdigit(format[*i]); (*i)++) {
//             specifier->width = specifier->width * 10 + (format[*i] - '0');
//         }
//     } else if (format[*i] == '*') {
//         specifier->width = va_arg(*args, int);
//         (*i)++;
//     }

//     // Обработка точности
//     if (format[*i] == '.') {
//         (*i)++;
//         if (isdigit(format[*i])) {
//             for (; isdigit(format[*i]); (*i)++) {
//                 specifier->precision = specifier->precision * 10 +
//                 (format[*i] - '0');
//             }
//         } else if (format[*i] == '*') {
//             specifier->precision = va_arg(*args, int);
//             (*i)++;
//         }
//     }

//     // Обработка модификаторов длины
//     if (format[*i] == 'h' || format[*i] == 'l') {
//         specifier->length[0] = format[*i];
//         (*i)++;
//         if (specifier->length[0] == format[*i] && (format[*i] == 'h' ||
//         format[*i] == 'l')) {
//             // Для hh и ll
//             specifier->length[1] = format[*i];
//             (*i)++;
//         }
//     }

//     // Обработка типа
//     const char *valid_types = "diufFeEgGxXoscpn%";
//     if (s21_strchr(valid_types, format[*i]) != NULL)
//         specifier->type = format[*i];
// }

// // Основная функция обработки спецификатора
// void process_specifier(char *str, FormatSpec specifier, va_list *args, int
// *counter) {
//     int left_justify = s21_strchr(specifier.flags, '-') != NULL ? 1 : 0;
//     unsigned long var_len = 0;
//     int is_negative = 0;

//     switch (specifier.type) {
//         case 'c': {
//             char value = (char)va_arg(*args, int);
//             var_len = 1;
//             str[*counter] = value;
//             str[*counter + 1] = '\0';
//             *counter += 1;
//             break;
//         }
//         case 'd':
//         case 'i': {
//             long long value;
//             if (s21_strcmp(specifier.length, "hh") == 0) {
//                 value = (signed char)va_arg(*args, int); // Обработка как
//                 signed char
//             } else if (s21_strcmp(specifier.length, "h") == 0) {
//                 value = (short int)va_arg(*args, int); // Обработка как short
//                 int
//             } else if (s21_strcmp(specifier.length, "l") == 0) {
//                 value = va_arg(*args, long int); // Обработка как long int
//             } else if (s21_strcmp(specifier.length, "ll") == 0) {
//                 value = va_arg(*args, long long int); // Обработка как long
//                 long int
//             } else {
//                 value = va_arg(*args, int); // Стандартный int
//             }
//             is_negative = value < 0;
//             var_len = integer_to_string(str, value, specifier, counter);
//             break;
//         }
//         case 'f': {
//             // Спецификатор 'f' принимает 'double' или 'long double'
//             double value;
//             if (s21_strcmp(specifier.length, "L") == 0) {
//                 value = va_arg(*args, long double); // Обработка как long
//                 double
//             } else {
//                 value = va_arg(*args, double); // Стандартный double
//             }
//             is_negative = value < 0;
//             var_len = float_to_string(str, value, specifier, counter);
//             break;
//         }
//         case 's': {
//             char *value = va_arg(*args, char *);
//             var_len = s21_strlen(value);
//             if (specifier.precision > 0) var_len = specifier.precision;
//             specifier.flags[1] = '\0';
//             specifier.flags[3] = '\0';
//             specifier.flags[4] = '\0';

//             s21_strncpy(str + *counter, value, var_len);
//             *counter += var_len;

//             str[*counter] = '\0'; // Обеспечиваем нуль-терминацию
//             break;
//         }
//         case 'u': {
//             unsigned long long value;
//             if (s21_strcmp(specifier.length, "hh") == 0) {
//                 value = (unsigned char)va_arg(*args, unsigned int); // hh для
//                 unsigned char
//             } else if (s21_strcmp(specifier.length, "h") == 0) {
//                 value = (unsigned short)va_arg(*args, unsigned int); // h для
//                 unsigned short
//             } else if (s21_strcmp(specifier.length, "l") == 0) {
//                 value = va_arg(*args, unsigned long); // l для unsigned long
//             } else if (s21_strcmp(specifier.length, "ll") == 0) {
//                 value = va_arg(*args, unsigned long long); // ll для unsigned
//                 long long
//             } else {
//                 value = va_arg(*args, unsigned int); // Стандартный unsigned
//                 int
//             }
//             is_negative = 0; // Беззнаковые числа всегда неотрицательные
//             var_len = integer_to_string(str, value, specifier, counter);
//             break;
//         }
//         case '%': {
//             str[*counter] = '%';
//             *counter += 1;
//             break;
//         }
//     }

//     char pad_char = ' ';
//     if (specifier.flags[4] == '0') pad_char = '0';

//     add_padding(str, specifier, var_len, is_negative, pad_char, counter,
//     left_justify);

//     // Установка конечного указателя после добавленного значения
//     *counter += s21_strlen(&str[*counter]);
// }

// void add_padding(char *str, FormatSpec specifier, unsigned long var_len, int
// is_negative, char pad_char, int *counter, int left_justify) {
//     unsigned long padding_size = specifier.width - var_len; // Вычисляем
//     количество необходимых символов заполнения

//     if ((is_negative || specifier.flags[1]) && pad_char == '0') --var_len;
//     if (specifier.flags[2] == ' ' && padding_size <= 0 && !is_negative)
//     padding_size = 1;

//     if ((int)padding_size > 0 && !left_justify) {
//         // Сдвигаем число вправо, чтобы сделать место для нулей
//         for (unsigned long i = *counter - 1; i >= *counter - var_len; --i) {
//             str[i + padding_size] = str[i];
//         }

//         // Заполняем нулями пространство перед числом
//         for (unsigned long i = *counter - var_len; i < *counter - var_len +
//         padding_size; ++i) {
//             str[i] = pad_char;
//         }

//         *counter += padding_size; // Обновляем счетчик, так как добавили нули
//     } else if ((int)padding_size > 0 && left_justify) {
//         // Добавляем пробелы после числа, если установлен флаг выравнивания
//         по левому краю for (int i = 0; i < (int)padding_size; ++i) {
//             str[*counter + i] = ' ';
//         }
//         *counter += (int)padding_size; // Обновляем счетчик, так как добавили
//         пробелы
//     }
// }

// // Вспомогательная функция для реверсирования строки
// void reverse(char *buffer, unsigned long length) {
//     for (unsigned long i = 0, j = length - 1; i < j; i++, j--) {
//         char temp = buffer[i];
//         buffer[i] = buffer[j];
//         buffer[j] = temp;
//     }
// }

// // Основная функция для преобразования целого числа в строку
// unsigned long integer_to_string(char *str, long long value, FormatSpec spec,
// int *counter) {
//     char num_buffer[64]; // буфер для строки с числом
//     int is_negative = value < 0;
//     unsigned long num_len = 0;
//     unsigned long long abs_value = is_negative ? -value : value;

//     // конвертация числа в строку
//     do {
//         num_buffer[num_len++] = (abs_value % 10) + '0';
//         abs_value /= 10;
//     } while (abs_value > 0);

//     // добавление - или +
//     if (is_negative) {
//         num_buffer[num_len++] = '-';
//     } else if (spec.flags[1] == '+') {
//         num_buffer[num_len++] = '+';
//     }

//     reverse(num_buffer, num_len);

//     // копирования в строку числа
//     for (int i = 0; i < (int)num_len; i++) {
//         str[*counter + i] = num_buffer[i];
//     }
//     *counter += (int)num_len;

//     return num_len;
// }

// unsigned long float_to_string(char *str, double num, FormatSpec spec, int
// *counter) {
//     char num_buffer[1024] = {0};
//     int is_negative = num < 0;
//     unsigned long num_len = 0;

//     if (is_negative) num = -num;

//     // отделение целой и дробной часть
//     double int_part;
//     num = modf(num, &int_part);  // в num теперь хранится дробная часть

//     // Обработка дробной части
//     if (spec.precision <= 0) spec.precision = 6;
//     if (spec.precision > 0) {
//         // Конвертация дробной части в строку
//         char curr_char = '\0';
//         while ((int)num_len < spec.precision) {
//             num *= 10;
//             curr_char = (long long)num + '0';
//             num_buffer[num_len++] = curr_char;
//             num -= (long long)num;
//         }
//         num *= 10;
//         if (num >= 5) num_buffer[num_len - 1] = curr_char - '0' + 1 + '0';
//     }
//     reverse(num_buffer, num_len);

//     // Конвертация целой части в строку
//     num_buffer[num_len++] = '.';
//     while (int_part > 0) {
//         double curr_num = fmod(int_part, 10);
//         int_part = floor(int_part / 10);
//         num_buffer[num_len++] = (int)curr_num + '0';
//     }

//     // Добавление знака
//     if (is_negative) num_buffer[num_len++] = '-';
//     else if (spec.flags[1] == '+') num_buffer[num_len++] = '+';
//     reverse(num_buffer, num_len);

//     // Копирование в итоговую строку
//     for (int i = 0; i < (int)num_len; i++) str[*counter + i] = num_buffer[i];
//     *counter += num_len;

//     return num_len;
// }