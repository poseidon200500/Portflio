#ifndef S21_TYPES
#define S21_TYPES

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define some_unsigned 4294967295

#define MAX_DECIMAL 79228162514264337593543950335.0f
#define MIN_DECIMAL -79228162514264337593543950335.0f
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#define POSITIVE_SIGN 0
#define NEGATIVE_SIGN 1

#define CONVERTATION_OK 0
#define CONVERTATION_ERROR 1

#define ARITHMETIC_OK 0
#define ARITHMETIC_ERROR_INF 1
#define ARITHMETIC_ERROR_NEGINF 2
#define ARITHMETIC_ERROR_DIV_ZERO 3

#define COMPARATION_TRUE 1
#define COMPARATION_FALSE 0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

#endif