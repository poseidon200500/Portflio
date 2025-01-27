#include "s21_string_tests.h"

START_TEST(s21_memset_1) {
  char s1[] = "Strng project";
  char s2[] = "Strng project";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(s21_memset_2) {
  char s1[] = "Strng project";
  char s2[] = "Strng project";
  int ch = ' ';
  s21_size_t n = 4;
  ck_assert_pstr_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(s21_memset_3) {
  char s1[] = "Strng project";
  char s2[] = "Strng project";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  ck_assert_pstr_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(s21_memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '0';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(s21_memset_5) {
  char s1[] = "";
  char s2[] = "";
  int ch = '0';
  s21_size_t n = strlen(s1);
  ck_assert_pstr_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(s21_memset_6) {
  char s1[] = "Strng project";
  char s2[] = "Strng project";
  int ch = 65;
  s21_size_t n = 7;
  ck_assert_pstr_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

Suite *s21_memset_create_suite(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("Core of s21_memset");
  /*Tests*/
  tcase_add_test(tc, s21_memset_1);
  tcase_add_test(tc, s21_memset_2);
  tcase_add_test(tc, s21_memset_3);
  tcase_add_test(tc, s21_memset_4);
  tcase_add_test(tc, s21_memset_5);
  tcase_add_test(tc, s21_memset_6);

  suite_add_tcase(s, tc);
  return s;
}

int s21_memset_run_test(void) {
  Suite *suite = s21_memset_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}