#include "s21_string_tests.h"

START_TEST(s21_memmove_1) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "Life";
  s21_size_t n = 4;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_2) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "Life";
  s21_size_t n = 0;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_3) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 0;
  memmove(s1, s1, n);
  s21_memmove(s2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_4) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 4;
  memmove(s1, s1, n);
  s21_memmove(s2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_5) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 0;
  memmove(s1, s1 + 2, n);
  s21_memmove(s2, s2 + 2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_6) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 4;
  memmove(s1, s1, n);
  s21_memmove(s2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_7) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 0;
  memmove(s1 + 2, s1, n);
  s21_memmove(s2 + 2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_memmove_8) {
  char s1[] = "String project";
  char s2[] = "String project";
  s21_size_t n = 4;
  memmove(s1 + 2, s1, n);
  s21_memmove(s2 + 2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

Suite *s21_memmove_create_suite(void) {
  Suite *s = suite_create("s21_memmove");
  TCase *tc = tcase_create("Core of s21_memmove");
  /*Tests*/
  tcase_add_test(tc, s21_memmove_1);
  tcase_add_test(tc, s21_memmove_2);
  tcase_add_test(tc, s21_memmove_3);
  tcase_add_test(tc, s21_memmove_4);
  tcase_add_test(tc, s21_memmove_5);
  tcase_add_test(tc, s21_memmove_6);
  tcase_add_test(tc, s21_memmove_7);
  tcase_add_test(tc, s21_memmove_8);

  suite_add_tcase(s, tc);
  return s;
}

int s21_memmove_run_test(void) {
  Suite *suite = s21_memmove_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
