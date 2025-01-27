#include "s21_string_tests.h"

START_TEST(s21_strtok_1) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_2) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_3) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_4) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "String project";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_5) {
  char s1[] = "String project";
  char s2[] = "String project";
  char s3[] = "t";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_6) {
  char s1[] = "qwqwqwqwqwqwqwqwqwqwqwqwq";
  char s2[] = "qwqwqwqwqwqwqwqwqwqwqwqwq";
  char s3[] = "q";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
}
END_TEST

START_TEST(s21_strtok_7) {
  char s1[] = "qwqwqwqwqwqwqwqwqwqwqwqwq";
  char s2[] = "qwqwqwqwqwqwqwqwqwqwqwqwq";
  char s3[] = "w";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
  ck_assert_pstr_eq(strtok(S21_NULL, s3), s21_strtok(S21_NULL, s3));
}
END_TEST

START_TEST(s21_strtok_8) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

Suite *s21_strtok_create_suite(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("Core of s21_strtok");
  /*Tests*/
  tcase_add_test(tc, s21_strtok_1);
  tcase_add_test(tc, s21_strtok_2);
  tcase_add_test(tc, s21_strtok_3);
  tcase_add_test(tc, s21_strtok_4);
  tcase_add_test(tc, s21_strtok_5);
  tcase_add_test(tc, s21_strtok_6);
  tcase_add_test(tc, s21_strtok_7);
  tcase_add_test(tc, s21_strtok_8);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strtok_run_test(void) {
  Suite *suite = s21_strtok_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}