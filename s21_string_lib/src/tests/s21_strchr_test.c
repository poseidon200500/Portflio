#include "s21_string_tests.h"

START_TEST(s21_strchr_1) {
  char s[] = "String project";
  int ch = 'S';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_2) {
  char s[] = "String project";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_3) {
  char s[] = "String project";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_4) {
  char s[] = "String project";
  int ch = 't';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_5) {
  char s[] = "String project";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_6) {
  char s[] = "String project";
  int ch = -5;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_7) {
  char s[] = "String project";
  int ch = 130;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

Suite *s21_strchr_create_suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("Core of s21_strchr");
  /*Tests*/
  tcase_add_test(tc, s21_strchr_1);
  tcase_add_test(tc, s21_strchr_2);
  tcase_add_test(tc, s21_strchr_3);
  tcase_add_test(tc, s21_strchr_4);
  tcase_add_test(tc, s21_strchr_5);
  tcase_add_test(tc, s21_strchr_6);
  tcase_add_test(tc, s21_strchr_7);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strchr_run_test(void) {
  Suite *suite = s21_strchr_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}