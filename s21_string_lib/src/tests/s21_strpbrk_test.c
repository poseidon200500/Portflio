#include "s21_string_tests.h"

START_TEST(s21_strpbrk_1) {
  char *str1 = "Hello";
  char *str2 = "erio";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_2) {
  char *str1 = "Hello";
  char *str2 = "olleH";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_3) {
  char *str1 = "Hello";
  char *str2 = "Hello";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_4) {
  char *str1 = "Hello";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_5) {
  char *str1 = "Hello";
  char *str2 = "bup";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *s21_strpbrk_create_suite(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("Core of s21_strpbrk");
  /*Tests*/
  tcase_add_test(tc, s21_strpbrk_1);
  tcase_add_test(tc, s21_strpbrk_2);
  tcase_add_test(tc, s21_strpbrk_3);
  tcase_add_test(tc, s21_strpbrk_4);
  tcase_add_test(tc, s21_strpbrk_5);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strpbrk_run_test(void) {
  Suite *suite = s21_strpbrk_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}