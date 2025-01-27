#include "s21_string_tests.h"

START_TEST(s21_strcspn_1) {
  char *str = "Hello World";
  char *search = "Wight";
  ck_assert_int_eq(s21_strcspn(str, search), strcspn(str, search));
}
END_TEST

START_TEST(s21_strcspn_2) {
  char *str = "Hello World";
  char *search = "Light";
  ck_assert_int_eq(s21_strcspn(str, search), strcspn(str, search));
}
END_TEST

START_TEST(s21_strcspn_3) {
  char *str = "Hello World";
  char *search = "";
  ck_assert_int_eq(s21_strcspn(str, search), strcspn(str, search));
}
END_TEST

START_TEST(s21_strcspn_4) {
  char *str = "Hello\n World";
  char *search = "\n";
  ck_assert_int_eq(s21_strcspn(str, search), strcspn(str, search));
}
END_TEST

START_TEST(s21_strcspn_5) {
  char *str = "Hello World";
  char *search = "\0";
  ck_assert_int_eq(s21_strcspn(str, search), strcspn(str, search));
}
END_TEST

Suite *s21_strcspn_create_suite(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("Core of s21_strcspn");
  /*Tests*/
  tcase_add_test(tc, s21_strcspn_1);
  tcase_add_test(tc, s21_strcspn_2);
  tcase_add_test(tc, s21_strcspn_3);
  tcase_add_test(tc, s21_strcspn_4);
  tcase_add_test(tc, s21_strcspn_5);

  suite_add_tcase(s, tc);
  return s;
}

int s21_strcspn_run_test(void) {
  Suite *suite = s21_strcspn_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}