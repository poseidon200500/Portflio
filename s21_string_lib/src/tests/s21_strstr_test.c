#include "s21_string_tests.h"

START_TEST(s21_strstr_1) {
  char s1[] = "String project";
  char s2[] = "String project";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_2) {
  char s1[] = "String project";
  char s2[] = "String!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_3) {
  char s1[] = "String project";
  char s2[] = "t";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_4) {
  char s1[] = "String project String project";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_6) {
  char s1[] = "";
  char s2[] = "String";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr_7) {
  char s1[] = "String project";
  char s2[] = "S";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

Suite *s21_strstr_create_suite(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("Core of s21_strstr");
  /*Tests*/
  tcase_add_test(tc, s21_strstr_1);
  tcase_add_test(tc, s21_strstr_2);
  tcase_add_test(tc, s21_strstr_3);
  tcase_add_test(tc, s21_strstr_4);
  tcase_add_test(tc, s21_strstr_5);
  tcase_add_test(tc, s21_strstr_6);
  tcase_add_test(tc, s21_strstr_7);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strstr_run_test(void) {
  Suite *suite = s21_strstr_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}