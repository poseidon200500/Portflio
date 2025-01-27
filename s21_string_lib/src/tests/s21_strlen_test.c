#include "../s21_string.h"
#include "s21_string_tests.h"

START_TEST(s21_strlen_1) {
  char base[] = "Hello";
  int ac = s21_strlen(base);
  int ex = strlen(base);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strlen_2) {
  char base[] = "faddddddfgafgafdgadfgafga";
  int ac = s21_strlen(base);
  int ex = (int)strlen(base);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strlen_3) {
  char base[] = "dfgsdgsfdb";
  int ac = s21_strlen(base);
  int ex = (int)strlen(base);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strlen_4) {
  char base[] =
      "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
      "sssssssssssssssssssssssssssssssss";
  int ac = s21_strlen(base);
  int ex = (int)strlen(base);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strlen_5) {
  char base[] = "Hello World";
  int ac = s21_strlen(base);
  int ex = (int)strlen(base);
  ck_assert_int_eq(ac, ex);
}
END_TEST

START_TEST(s21_strlen_6) {
  char base[] = "";
  int ac = s21_strlen(base);
  int ex = (int)strlen(base);
  ck_assert_int_eq(ac, ex);
}
END_TEST

Suite *s21_strlen_create_suite(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("Core of s21_strlen");
  /*Tests*/
  tcase_add_test(tc, s21_strlen_1);
  tcase_add_test(tc, s21_strlen_2);
  tcase_add_test(tc, s21_strlen_3);
  tcase_add_test(tc, s21_strlen_4);
  tcase_add_test(tc, s21_strlen_5);
  tcase_add_test(tc, s21_strlen_6);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strlen_run_test(void) {
  Suite *suite = s21_strlen_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}