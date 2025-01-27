#include "s21_string_tests.h"

START_TEST(s21_strcat_1) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = " World";
  ck_assert_pstr_eq(s21_strcat(str_dest_as, str_src),
                    strcat(str_dest_eq, str_src));
}
END_TEST

START_TEST(s21_strcat_2) {
  char str_dest_as[100] = "\0";
  char str_dest_eq[100] = "\0";
  const char *str_src = "Hello";
  ck_assert_pstr_eq(s21_strcat(str_dest_as, str_src),
                    strcat(str_dest_eq, str_src));
}
END_TEST

START_TEST(s21_strcat_3) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = " \0";
  ck_assert_pstr_eq(s21_strcat(str_dest_as, str_src),
                    strcat(str_dest_eq, str_src));
}
END_TEST

START_TEST(s21_strcat_4) {
  char str_dest_as[100] = "Hello";
  char str_dest_eq[100] = "Hello";
  const char str_src[] = "\0";
  ck_assert_pstr_eq(s21_strcat(str_dest_as, str_src),
                    strcat(str_dest_eq, str_src));
}
END_TEST

START_TEST(s21_strcat_5) {
  char str_dest_as[100] = "\0";
  char str_dest_eq[100] = "\0";
  const char str_src[] = "\0";
  ck_assert_pstr_eq(s21_strcat(str_dest_as, str_src),
                    strcat(str_dest_eq, str_src));
}
END_TEST

START_TEST(s21_strcat_6) {
  char str_dest_as[100] = "\n\t\b\b\b\b\b\b\b\b\b\b\b";
  char str_dest_eq[100] = "\n\t\b\b\b\b\b\b\b\b\b\b\b";
  const char str_src[] = "\b\b\b\b\t\n World";
  ck_assert_pstr_eq(s21_strcat(str_dest_as, str_src),
                    strcat(str_dest_eq, str_src));
}
END_TEST

Suite *s21_strcat_create_suite(void) {
  Suite *s = suite_create("s21_strcat");
  TCase *tc = tcase_create("Core of s21_strcat");
  /*Tests*/
  tcase_add_test(tc, s21_strcat_1);
  tcase_add_test(tc, s21_strcat_2);
  tcase_add_test(tc, s21_strcat_3);
  tcase_add_test(tc, s21_strcat_4);
  tcase_add_test(tc, s21_strcat_5);
  tcase_add_test(tc, s21_strcat_6);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strcat_run_test(void) {
  Suite *suite = s21_strcat_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}