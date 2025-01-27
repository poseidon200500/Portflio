#include "s21_string_tests.h"

START_TEST(s21_strncpy_1) {
  char s1[20] = "String project";
  char s2[20] = "String project";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy_2) {
  char s1[20] = "String project";
  char s2[20] = "String project";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy_3) {
  char s1[30] = "String project";
  char s2[30] = "String project";
  char s3[] = "DAS";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy_6) {
  char s1[30] = "String project";
  char s2[30] = "String project";
  char s3[] = "DAS";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy_5) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy_7) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

Suite *s21_strncpy_create_suite(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("Core of s21_strncpy");
  /*Tests*/
  tcase_add_test(tc, s21_strncpy_1);
  tcase_add_test(tc, s21_strncpy_2);
  tcase_add_test(tc, s21_strncpy_3);
  tcase_add_test(tc, s21_strncpy_4);
  tcase_add_test(tc, s21_strncpy_5);
  tcase_add_test(tc, s21_strncpy_6);
  tcase_add_test(tc, s21_strncpy_7);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strncpy_run_test(void) {
  Suite *suite = s21_strncpy_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}