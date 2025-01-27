#ifndef _S21_STRING_TESTS_H_
#define _S21_STRING_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

/*Создание тестовых кейсов*/
Suite *s21_insert_create_suite(void);
Suite *s21_memchr_create_suite(void);
Suite *s21_memcmp_create_suite(void);
Suite *s21_memcpy_create_suite(void);
Suite *s21_memmove_create_suite(void);
Suite *s21_memset_create_suite(void);
Suite *s21_sprintf_create_suite(void);
Suite *s21_sscanf_create_suite(void);
Suite *s21_strcat_create_suite(void);
Suite *s21_strchr_create_suite(void);
Suite *s21_strcmp_create_suite(void);
Suite *s21_strcpy_create_suite(void);
Suite *s21_strcspn_create_suite(void);
Suite *s21_strerror_create_suite(void);
Suite *s21_strlen_create_suite(void);
Suite *s21_strncat_create_suite(void);
Suite *s21_strncmp_create_suite(void);
Suite *s21_strncpy_create_suite(void);
Suite *s21_strpbrk_create_suite(void);
Suite *s21_strrchr_create_suite(void);
Suite *s21_strspn_create_suite(void);
Suite *s21_strstr_create_suite(void);
Suite *s21_strtok_create_suite(void);
Suite *s21_to_lower_create_suite(void);
Suite *s21_to_upper_create_suite(void);
Suite *s21_trim_create_suite(void);

/* Запуск тестов соло */

int s21_insert_run_test(void);
int s21_memchr_run_test(void);
int s21_memcmp_run_test(void);
int s21_memcpy_run_test(void);
int s21_memmove_run_test(void);
int s21_memset_run_test(void);
int s21_sprintf_run_test(void);
int s21_sscanf_run_test(void);
int s21_strcat_run_test(void);
int s21_strchr_run_test(void);
int s21_strcmp_run_test(void);
int s21_strcpy_run_test(void);
int s21_strcspn_run_test(void);
int s21_strerror_run_test(void);
int s21_strlen_run_test(void);
int s21_strncat_run_test(void);
int s21_strncmp_run_test(void);
int s21_strncpy_run_test(void);
int s21_strpbrk_run_test(void);
int s21_strrchr_run_test(void);
int s21_strspn_run_test(void);
int s21_strstr_run_test(void);
int s21_strtok_run_test(void);
int s21_to_lower_run_test(void);
int s21_to_upper_run_test(void);
int s21_trim_run_test(void);

#endif  // _S21_STRING_TESTS_H_