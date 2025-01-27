#include "s21_string_tests.h"

START_TEST(s21_to_lower_1) {
  char str1[] = "HELLO";
  char str2[] = "hello";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_2) {
  char str1[] = "HELLO 123 567 grepkin";
  char str2[] = "hello 123 567 grepkin";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_3) {
  char str1[] = "dimon est salo";
  char str2[] = "dimon est salo";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_4) {
  char str1[] = "HELLO WORLD 816 AND 15";
  char str2[] = "hello world 816 and 15";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_5) {
  char str1[] = "HELLO \n \b \t ";
  char str2[] = "hello \n \b \t ";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_6) {
  char str1[] = "HELLO WORLD \n \b \t  816 AND 15";
  char str2[] = "hello world \n \b \t  816 and 15";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_7) {
  char *str1 = NULL;
  char *str = s21_to_lower(str1);
  ck_assert_ptr_null(str);
  free(str);
}
END_TEST

START_TEST(s21_to_lower_8) {
  char str1[] = "DDDDDDDDDDDDD \n DDDDD \b DDDD \t  816 AND 15";
  char str2[] = "ddddddddddddd \n ddddd \b dddd \t  816 and 15";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str2, str);
  free(str);
}
END_TEST

Suite *s21_to_lower_create_suite(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("Core of s21_to_lower");
  /*Tests*/
  tcase_add_test(tc, s21_to_lower_1);
  tcase_add_test(tc, s21_to_lower_2);
  tcase_add_test(tc, s21_to_lower_3);
  tcase_add_test(tc, s21_to_lower_4);
  tcase_add_test(tc, s21_to_lower_5);
  tcase_add_test(tc, s21_to_lower_6);
  tcase_add_test(tc, s21_to_lower_7);
  tcase_add_test(tc, s21_to_lower_8);

  suite_add_tcase(s, tc);
  return s;
}

int s21_to_lower_run_test(void) {
  Suite *suite = s21_to_lower_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
