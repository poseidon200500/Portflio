#include "s21_string_tests.h"

START_TEST(s21_strcpy_1) {
  char str1[100] = "String project";
  char str2[100] = "String project";
  char str3[] = "String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_2) {
  char str1[100] = "Das\0Fas";
  char str2[100] = "Das\0Fas";
  char str3[] = "String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_3) {
  char str1[100] = "Das\0Fas";
  char str2[100] = "Das\0Fas";
  char str3[] = "Stri";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_4) {
  char str1[100] = "String project";
  char str2[100] = "String project";
  char str3[] = "Das\0Fas";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_5) {
  char str1[100] = "\0";
  char str2[100] = "\0";
  char str3[] = "String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_6) {
  char str1[100] = "String project";
  char str2[100] = "String project";
  char str3[] = "\0";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_7) {
  char str1[100] = " ";
  char str2[100] = " ";
  char str3[] = "";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_8) {
  char str1[100] = "";
  char str2[100] = "";
  char str3[] = " ";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

START_TEST(s21_strcpy_9) {
  char str1[100] = "thi00s";
  char str2[100] = "thi00s";
  char str3[] = "\0String project";
  ck_assert_pstr_eq(strcpy(str1, str3), s21_strcpy(str2, str3));
}
END_TEST

Suite *s21_strcpy_create_suite(void) {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc = tcase_create("Core of s21_strcpy");
  /*Tests*/
  tcase_add_test(tc, s21_strcpy_1);
  tcase_add_test(tc, s21_strcpy_2);
  tcase_add_test(tc, s21_strcpy_3);
  tcase_add_test(tc, s21_strcpy_4);
  tcase_add_test(tc, s21_strcpy_5);
  tcase_add_test(tc, s21_strcpy_6);
  tcase_add_test(tc, s21_strcpy_7);
  tcase_add_test(tc, s21_strcpy_8);
  tcase_add_test(tc, s21_strcpy_9);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strcpy_run_test(void) {
  Suite *suite = s21_strcpy_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}