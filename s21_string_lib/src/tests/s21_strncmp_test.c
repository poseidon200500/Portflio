#include "s21_string_tests.h"

START_TEST(s21_strncmp_1) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_2) {
  char s1[] = "String project";
  char s2[] = "String projecd";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_3) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_4) {
  char s1[] = "f";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_5) {
  char s1[] = "";
  char s2[] = "f";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_6) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 10;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_7) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_8) {
  char s1[] = "123456789";
  char s2[] = "123456789";
  s21_size_t n = 10;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *s21_strncmp_create_suite(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("Core of s21_strncmp");
  /*Tests*/
  tcase_add_test(tc, s21_strncmp_1);
  tcase_add_test(tc, s21_strncmp_2);
  tcase_add_test(tc, s21_strncmp_3);
  tcase_add_test(tc, s21_strncmp_4);
  tcase_add_test(tc, s21_strncmp_5);
  tcase_add_test(tc, s21_strncmp_6);
  tcase_add_test(tc, s21_strncmp_7);
  tcase_add_test(tc, s21_strncmp_8);
  tcase_add_test(tc, s21_strncmp_9);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strncmp_run_test(void) {
  Suite *suite = s21_strncmp_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}