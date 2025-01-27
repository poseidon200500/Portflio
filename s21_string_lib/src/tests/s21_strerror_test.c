#include "s21_string_tests.h"

#if defined(__APPLE__)
#define N 107
#endif
#if defined(__linux__)
#define N 134
#endif

START_TEST(s21_strerror_1) {
  char *p1 = S21_NULL;
  char *p2 = S21_NULL;
  for (int i = 0; i < 150; i++) {
    p1 = s21_strerror(i);
    p2 = strerror(i);
    ck_assert_str_eq(p1, p2);
    if (p1 && i >= N) {
      free(p1);
      p1 = S21_NULL;
    }
  }
}
END_TEST

START_TEST(s21_strerror_2) {
  int n = -1;
  char *p1 = S21_NULL;
  char *p2 = S21_NULL;
  p1 = s21_strerror(n);
  p2 = strerror(n);
  ck_assert_str_eq(p1, p2);
  if (p1) {
    free(p1);
    p1 = S21_NULL;
  }
}
END_TEST

Suite *s21_strerror_create_suite(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("Core of s21_strerror");
  /*Tests*/
  tcase_add_test(tc, s21_strerror_1);
  tcase_add_test(tc, s21_strerror_2);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strerror_run_test(void) {
  Suite *suite = s21_strerror_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}