#ifndef S21_HELPERS
#define S21_HELPERS

#include "../../s21_types.h"

s21_decimal *init_decimal();     //инициализация
int is_zero(s21_decimal value);  //проверяет, что число ноль
void null_decimal(s21_decimal *value);              //делает нулем
int get_sign(s21_decimal value);                    //выдает знак
void set_sign(s21_decimal *value, int sign_value);  //меняет знак
int get_scale(s21_decimal *dec);           //выдает порядок
int set_scale(s21_decimal *dec, int exp);  //меняет порядок
unsigned get_bit(s21_decimal value, int bit);  //выдает бит на конкретном месте
int is_correct(s21_decimal *value);  //проверяет корректность decimal
// void print_bit(int bit);                  //вывод int по битам
// void print_decimal_bit(s21_decimal dec);  //выводит по битам
void copy_decimal(s21_decimal *src, s21_decimal *dest);  //копирование decimal
int decimal_mult_positive(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result);
//служебки для big_dec
s21_big_decimal *init_big_decimal();  //инициализация
void dec_to_big(s21_decimal *dst,
                s21_big_decimal *big_dst);  //переводит из decimal в big decimal
                                            //(и инициализирует big dec)
int big_to_dec(s21_big_decimal *big_dst,
               s21_decimal *dst);  //переводит из big dec в dec
void null_big_dec(s21_big_decimal *value);      //делает нулем
// void print_dec_big_bit(s21_big_decimal dec);
unsigned get_sign_big(s21_big_decimal *value);  //выдает знак
void set_sign_big(s21_big_decimal *value, unsigned sign_value);  //меняет знак
int get_scale_big(s21_big_decimal *dec);  //выдает порядок
int set_scale_big(s21_big_decimal *dec, int scale_value);  //меняет порядок
unsigned get_bit_big(s21_big_decimal value,
                     int position);  //возвращает нужный бит
void set_bit_big(s21_big_decimal *value, int position,
                 unsigned bit_val);  // устанавливает бит
int shift_left_big(s21_big_decimal *value,
                   int shift_value);  //сдвиг влево = * на 2
int shift_right_big(s21_big_decimal *value,
                    int shift_value);         //сдвиг влево = / на 2
void normalization_big(s21_big_decimal *val1,
                       s21_big_decimal *val2);  //нормализация
void copy_big_decimal(s21_big_decimal *sourse,
                      s21_big_decimal *copy);  //копирование
int overflow(s21_big_decimal *big_dec, s21_decimal *dec);
void overflow_help1(s21_big_decimal trunc, s21_big_decimal big_result);
void overflow_help2(s21_big_decimal *mode, int sign, s21_big_decimal *trunc, s21_big_decimal *big_result);
int check_inf(s21_big_decimal *trunc, int sign);

//арифметика
int bitwise_add(s21_big_decimal value1, s21_big_decimal value2,
                s21_big_decimal *res);  //битовое сложение
int bitwise_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);  //битовое вычитание
int add_big(s21_big_decimal value1, s21_big_decimal value2,
            s21_big_decimal *res);  // сложение больших dec
void great_scale(s21_big_decimal *val1, int scale2);  //умножение на 10
int compare_big(s21_big_decimal *, s21_big_decimal *);
int good_big(s21_big_decimal);  // проверка на правильное состояние big_dec
int is_zero_big(s21_big_decimal *);  // проверка на ноль
void division(s21_big_decimal val1, s21_big_decimal val2, s21_big_decimal *res);
int get_first_bit(s21_big_decimal value);
int mod(s21_decimal v1, s21_decimal v2, s21_decimal *result);
float get_rand_float(float left, float right);

#endif
