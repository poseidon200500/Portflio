#include "s21_string_tests.h"

START_TEST(s21_memchr_1) {
  char str[] = "String project!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_2) {
  char str[] = "String project!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_3) {
  char str[] = "String project!";
  int ch = '!';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_4) {
  char str[] = "String project!";
  int ch = 'S';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_5) {
  char str[] = "12345671";
  int ch = '1';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_6) {
  char str[] = "12345678";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_7) {
  char str[] = "12345678";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

Suite *s21_memchr_create_suite(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("Core of s21_memchr");
  /*Tests*/
  tcase_add_test(tc, s21_memchr_1);
  tcase_add_test(tc, s21_memchr_2);
  tcase_add_test(tc, s21_memchr_3);
  tcase_add_test(tc, s21_memchr_4);
  tcase_add_test(tc, s21_memchr_5);
  tcase_add_test(tc, s21_memchr_6);
  tcase_add_test(tc, s21_memchr_7);

  suite_add_tcase(s, tc);
  return s;
}

int s21_memchr_run_test(void) {
  Suite *suite = s21_memchr_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
