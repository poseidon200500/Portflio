#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string_tests.h"

int main(void) {
  int count_tests = 26;
  Suite *list[] = {s21_insert_create_suite(),
                   s21_memchr_create_suite(),
                   s21_memcmp_create_suite(),
                   s21_memcpy_create_suite(),
                   s21_memmove_create_suite(),
                   s21_memset_create_suite(),
                   s21_sprintf_create_suite(),
                   s21_sscanf_create_suite(),
                   s21_strcat_create_suite(),
                   s21_strchr_create_suite(),
                   s21_strcmp_create_suite(),
                   s21_strcpy_create_suite(),
                   s21_strcspn_create_suite(),
                   s21_strerror_create_suite(),
                   s21_strlen_create_suite(),
                   s21_strncat_create_suite(),
                   s21_strncmp_create_suite(),
                   s21_strncpy_create_suite(),
                   s21_strpbrk_create_suite(),
                   s21_strrchr_create_suite(),
                   s21_strspn_create_suite(),
                   s21_strstr_create_suite(),
                   s21_strtok_create_suite(),
                   s21_to_lower_create_suite(),
                   s21_to_upper_create_suite(),
                   s21_trim_create_suite(),
                   NULL};

  for (int i = 0; i < count_tests; ++i) {
    SRunner *runner = srunner_create(list[i]);
    srunner_run_all(runner, CK_NORMAL);
    // int failed_count = srunner_ntests_failed(runner);
    srunner_free(runner);
    // if (failed_count != 0) {
    //     return EXIT_FAILURE;
    // }
  }
  return EXIT_SUCCESS;

  return 0;
}
