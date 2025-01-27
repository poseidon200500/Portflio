#include "s21_string_tests.h"

START_TEST(s21_memcpy_1) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(s21_memcpy_2) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(s21_memcpy_3) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "H";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(s21_memcpy_4) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "DA";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(s21_memcpy_5) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "DA";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(s21_memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "Space";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

Suite *s21_memcpy_create_suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("Core of s21_memcpy");
  /*Tests*/
  tcase_add_test(tc, s21_memcpy_1);
  tcase_add_test(tc, s21_memcpy_2);
  tcase_add_test(tc, s21_memcpy_3);
  tcase_add_test(tc, s21_memcpy_4);
  tcase_add_test(tc, s21_memcpy_5);
  tcase_add_test(tc, s21_memcpy_6);

  suite_add_tcase(s, tc);
  return s;
}

int s21_memcpy_run_test(void) {
  Suite *suite = s21_memcpy_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
