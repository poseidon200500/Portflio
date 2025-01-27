#include "s21_string_tests.h"

START_TEST(s21_trim_1) {
  char s1[30] = "-?String project!";
  char s3[] = "!?-";
  char s4[] = "String project";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_4) {
  char s1[30] = "-?String -!?!- project!";
  char s3[] = "!?-";
  char s4[] = "String -!?!- project";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_5) {
  char s1[30] = "String project";
  char s3[] = "das";
  char s4[] = "String project";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_6) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_7) {
  char s1[] = " Test ";
  char *s3 = S21_NULL;
  char *s4 = "Test";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_8) {
  char s1[] = " Test ";
  char *s3 = "";
  char *s4 = "Test";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *s21_trim_create_suite(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("Core of s21_trim");
  /*Tests*/
  tcase_add_test(tc, s21_trim_1);
  tcase_add_test(tc, s21_trim_2);
  tcase_add_test(tc, s21_trim_3);
  tcase_add_test(tc, s21_trim_4);
  tcase_add_test(tc, s21_trim_5);
  tcase_add_test(tc, s21_trim_6);
  tcase_add_test(tc, s21_trim_7);
  tcase_add_test(tc, s21_trim_8);
  suite_add_tcase(s, tc);
  return s;
}

int s21_trim_run_test(void) {
  Suite *suite = s21_trim_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}