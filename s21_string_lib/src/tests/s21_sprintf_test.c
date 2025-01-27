#include "s21_string_tests.h"

START_TEST(s21_sprintf_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%c>|<%c>";
  int a = 9;
  int b = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%c>|<%c>";
  int a = -6;
  int b = -10;
  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%c>|<%c>";
  int c = 1744;
  int d = 386;
  ck_assert_int_eq(sprintf(str1, str3, c, d), s21_sprintf(str2, str3, c, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_4) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%c>|<%c>";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a, a), s21_sprintf(str2, str3, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_5) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%05c>|<% 5c>|<%lc>";
  int a = 70;
  unsigned long int b = 70;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_6) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%-010c>|<% -10c>|<%-lc>";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_7) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%+010.5c>|<% +10.5c>|<%-10lc>|<%-10lc>|<%+10lc>";
  char a = 92;
  unsigned long int b = 92;
  unsigned long int c = 92;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_8) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%6.4c>|<%-6.4c>|<%4.10lc>|<%-4.10lc>|<%-0lc>";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_9) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.7c>|<%-7c>|<%-50c>|<% 54c>|<%0188c>";
  int a = 112;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_10) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%70c>|<%-90c>|<%080c>|<%-065c>|<%- 60c>";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_11) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%c>|<%lc>|<%hc>";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_12) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%d>|<%d>";
  int val = 01225;
  int val2 = -017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_13) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%ld>|<%ld>|<%hd>|<%hd>";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_14) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3d>|<%5d>";
  int val = -3015;
  int val2 = -11234;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_15) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5d>|<%.23d>|<%3.d>|<%.d>|<%.6d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_16) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5d>|<%-.8d>|<%-7d>|<%-.d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_17) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0d>|<%0.d>|<%0.0d>|<%0d>|<%.d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_18) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+d>|<%+3.d>|<%+5.7d>|<%+10d>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_19) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%d>|<%3.d>|<%5.7d>|<%10d>|<%#d>|<%-d>|<%+d>|<%.d>|<% .d>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_20) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% d>|<% 3.d>|<% 5.7d>|<% 10d>|<%.d>";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_21) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+d>|<%+3.d>|<%+5.7d>|<%+10d>|<%+.d>";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_22) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%#d>|<%#3d>|<%#5.7d>|<%#.7d Oof %#.d>";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_23) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0d>|<%06d>|<%05.7d>|<%0.7d Oof %0.d>";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_24) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%*d>|<%-*d>|<%*.*d>|<%.*d>";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_25) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%e>|<%5e>|<%5.e>";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_26) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%e>|<%.e>|<%4e>|<%4.e>|<%5.10e>";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_27) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%#e>|<%#.e>|<%#5.e>|<%#.0e>|<%#0.0e>";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_28) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "<% 013.E>|<%#4.9E>|<%016.2E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_29) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "<%20.E>|<%-20.E>";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_30) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "<% 30.1E>|<% 30.E>|<%030.0E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_31) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "<%- 17.1E>|<% -17.1E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_32) {
  char str1[300] = "";
  char str2[300] = "";
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "<%# 10.2E>|<% #10.0E>|<%010.E>";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_33) {
  char str1[600] = "";
  char str2[600] = "";
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "<% 10.1E>|<%- 10.1E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_34) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%.e>|<%.2e>|<%.5E>|<%.9E>|<%.13E>";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_35) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%e>|<%.e>|<%.5e>|<%.9e>|<%.15E>";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_36) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%060Le!>|<%.14Le>";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_37) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%4f>|<%4.f>|<%5.10f>";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_38) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%3f>|<%4.f>|<%5.10f>";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_39) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lf>|<%.Lf>|<%+-#Lf>|<%+#.Lf>|<%-#.Lf>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_40) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%5f>|<%6.1f>|<%8.2f>";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_41) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+15.f>|<%+#16.f>|<%+#18.0f>";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_42) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%15.13f>|<%26.15f>";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_43) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+- 14f>|<%+ 10f>|<% +25f>";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_44) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+- 010.2f>|<%- 025.7f>|<%+- 18.4f>";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_45) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<% 15.1Lf>|<% -26.13Lf>|<%- 30.8Lf>";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_46) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_47) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_48) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_49) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_50) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+ 0Lf>|<%.6Lf>|<%.15Lf>";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_51) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+ 0Lf>|<%060Lf>|<%.15Lf>";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_52) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-+.1Lf>|<%- .2Lf>|<%-0.3Lf>";
  long double num = -0.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_53) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.g>|<%4g>|<%4.g>|<%5.10g>";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_54) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.g>|<%4g>|<%4.g>|<%#5.10g>";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_55) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.g>|<%4g>|<%4.g>|<%#5.10g>";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_56) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.0g>|<%4.2g>|<%4.g>|<%5.10g>";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_57) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%#-10.g>|<%-+25.g>";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_58) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lg>|<%.Lg>";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_59) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lg>|<%.Lg>|<%+-#Lg>|<%+#.Lg>|<%-#.Lg>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_60) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%15.13g>|<%26.15g>";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_61) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-+ 025.5g>|<%- 020.4g>";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_62) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lg>|<%.2Lg>|<%.3Lg>";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_63) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.6Lg>|<%.Lg>";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_64) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.g>|<%.2g>|<%.3g>";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_65) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-20.13g>|<%-25.7g>";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_66) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+20.13g>|<%+25.7g>";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_67) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lg>";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_68) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lg>|<%Lg>";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_69) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%x><%x><%x>";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_70) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%lx><%lx><%hx><%hx>";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_71) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3x><%5x><%10x>";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_72) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5x><%.23x><%3.x><%.x>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_73) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5x><%-.8x><%-7x><%-.x>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_74) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0x><%0.x><%0.0x><%0x><%.x>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_75) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+x><%+3.x><%+5.7x><%+10x>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_76) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%x><%3.x><%5.7x><%10x><%#x><%-x><%+x><%.x><% .x>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_77) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% x><% 3.x><% 5.7x><% 10x><%.x>";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_78) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+x><%+3.x><%+5.7x><%+10x><%+.x>";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_79) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%#x><%#3x><%#5.7x><%#.7x><Oof %#.x>";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_80) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0x><%06x><%05.7x><%0.7x><Oof %0.x>";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_81) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%i><%i><%i>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_82) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%li><%li><%hi><%hi>";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_83) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5i><%.23i><%3.i><%.i>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_84) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5i><%-.8i><%-7i><%-.i>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_85) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+i><%+3.i><%+5.7i><%+10i>";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_86) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%i><%3.i><%5.7i><%10i><%#i><%-i><%+i><%.i><% .i>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_87) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% i><% 3.i><% 5.7i><% 10i><%.i>";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_88) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+i><%+3.i><%+5.7i><%+10i><%+.i>";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_89) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0d><%06i><%05.7i><%0.7i><%0.i>";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_90) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "text %n text";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1),
                   s21_sprintf(str2, str3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(s21_sprintf_91) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "text %o %n  %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(s21_sprintf_92) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%o><%o><%o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_93) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%lo><%lo><%ho><%ho>";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_94) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3o><%5o><%10o>";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_95) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5o><%.23o><%3.o><%.o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_96) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5o><%-.8o><%-7o><%-.o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_97) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0o><%0.o><%0.0o><%0o><%.o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_98) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+o><%+3.o><%+5.7o><%+10o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_99) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%o><%3.o><%5.7o><%10o %#o %-o %+o %.o % .o>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_100) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+o><%+3.o><%+5.7o><%+10o><%+.o>";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_101) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%*o><%-*o><%*.*o><%.*o>";
  int val = 362;
  int val2 = 88299;
  int val3 = 9119;
  int val4 = 3231311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_102) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = " %o %%%% %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_103) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%p><%p><%p>";
  char *val = "0p3015";
  char *val2 = "0p712";
  char *val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_104) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%p><%p><%p><%p>";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_105) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3p><%5p><%12p>";
  char *val = "3015";
  char *val2 = "01234";
  char *val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_106) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5p><%.23p><%3.p><%.p>";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_107) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0p><%0.p><%0.0p><%0p><%.p>";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  char *val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_108) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+p><%+3.p><%+5.7p><%+10p>";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_109) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% p><% 3.p><% 5.7p><% 10p><%.p>";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_110) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%#p><%#3p><%#5.7p><%#.7p Oof %#.p>";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_111) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0p><%06p><%05.7p><%0.7p Oof %0.p>";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_112) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%s><%s><%s>";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks>";
  char *val3 = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_113) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%ls>";
  wchar_t *val = L"3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_114) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%3s><%5s><%10s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_115) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5s><%.23s><%3.s><%.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_116) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5s><%-.8s><%-7s><%-.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_117) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0s><%0.s><%0.0s><%0s GOD %.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_118) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+s><%+3.s><%5.7s><%10s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "abcd";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_119) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%s><%3.s><%5.7s><%10s %#s %-s %+s %.s % .s>";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_120) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% s><% 3.s><% 5.7s><% 10s GOD %.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_121) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+s><%+3.s><%+5.7s><%+10s GOD %+.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_122) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%#s><%#3s><%#5.7s><%#.7s Oof %#.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_123) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%*s><%-*s><%*.*s><%.*s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_124) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%u><%u><%u>";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_125) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%lu><%lu><%hu><%hu>";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_126) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3u><%5u><%10u>";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_127) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5u><%.23u><%3.u><%.u>";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_128) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+u><%+3.u><%+5.7u><%+10u>";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_129) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%u><%3.u><%5.7u><%10u><%#u><%-u><%+u><%.u><% .u>";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_130) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% u><% 3.u><% 5.7u><% 10u><%.u>";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_131) {
  char str1[200];
  char str2[200];
  char *str3 = "<%#s><%#3s><%#5.7s><%#.7s Oof %#.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(s21_sprintf_) {
//   char str1[400] = "";
//   char str2[400] = "";
//   char *str3 = "<%+ 0Lf>|<%.6Lf>|<%.15Lf>";
//   long double num = -236310753.6495633;
//   ck_assert_int_eq(sprintf(str1, str3, num, num, num),
//                    s21_sprintf(str2, str3, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

Suite *s21_sprintf_create_suite(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("Core of s21_sprintf");
  /*Tests*/
  tcase_add_test(tc, s21_sprintf_1);
  tcase_add_test(tc, s21_sprintf_2);
  tcase_add_test(tc, s21_sprintf_3);
  tcase_add_test(tc, s21_sprintf_4);
  tcase_add_test(tc, s21_sprintf_5);
  tcase_add_test(tc, s21_sprintf_6);
  tcase_add_test(tc, s21_sprintf_7);
  tcase_add_test(tc, s21_sprintf_8);
  tcase_add_test(tc, s21_sprintf_9);
  tcase_add_test(tc, s21_sprintf_10);
  tcase_add_test(tc, s21_sprintf_11);
  tcase_add_test(tc, s21_sprintf_12);
  tcase_add_test(tc, s21_sprintf_13);
  tcase_add_test(tc, s21_sprintf_14);
  tcase_add_test(tc, s21_sprintf_15);
  tcase_add_test(tc, s21_sprintf_16);
  tcase_add_test(tc, s21_sprintf_17);
  tcase_add_test(tc, s21_sprintf_18);
  tcase_add_test(tc, s21_sprintf_19);
  tcase_add_test(tc, s21_sprintf_20);
  tcase_add_test(tc, s21_sprintf_21);
  tcase_add_test(tc, s21_sprintf_22);
  tcase_add_test(tc, s21_sprintf_23);
  tcase_add_test(tc, s21_sprintf_24);
  tcase_add_test(tc, s21_sprintf_25);
  tcase_add_test(tc, s21_sprintf_26);
  tcase_add_test(tc, s21_sprintf_27);
  tcase_add_test(tc, s21_sprintf_28);
  tcase_add_test(tc, s21_sprintf_29);
  tcase_add_test(tc, s21_sprintf_30);
  tcase_add_test(tc, s21_sprintf_31);
  tcase_add_test(tc, s21_sprintf_32);
  tcase_add_test(tc, s21_sprintf_33);
  tcase_add_test(tc, s21_sprintf_34);
  tcase_add_test(tc, s21_sprintf_35);
  tcase_add_test(tc, s21_sprintf_36);
  tcase_add_test(tc, s21_sprintf_37);
  tcase_add_test(tc, s21_sprintf_38);
  tcase_add_test(tc, s21_sprintf_39);
  tcase_add_test(tc, s21_sprintf_40);
  tcase_add_test(tc, s21_sprintf_41);
  tcase_add_test(tc, s21_sprintf_42);
  tcase_add_test(tc, s21_sprintf_43);
  tcase_add_test(tc, s21_sprintf_44);
  tcase_add_test(tc, s21_sprintf_45);
  tcase_add_test(tc, s21_sprintf_46);
  tcase_add_test(tc, s21_sprintf_47);
  tcase_add_test(tc, s21_sprintf_48);
  tcase_add_test(tc, s21_sprintf_49);
  tcase_add_test(tc, s21_sprintf_50);
  tcase_add_test(tc, s21_sprintf_51);
  tcase_add_test(tc, s21_sprintf_52);
  tcase_add_test(tc, s21_sprintf_53);
  tcase_add_test(tc, s21_sprintf_54);
  tcase_add_test(tc, s21_sprintf_55);
  tcase_add_test(tc, s21_sprintf_56);
  tcase_add_test(tc, s21_sprintf_57);
  tcase_add_test(tc, s21_sprintf_58);
  tcase_add_test(tc, s21_sprintf_59);
  tcase_add_test(tc, s21_sprintf_60);
  tcase_add_test(tc, s21_sprintf_61);
  tcase_add_test(tc, s21_sprintf_62);
  tcase_add_test(tc, s21_sprintf_63);
  tcase_add_test(tc, s21_sprintf_64);
  tcase_add_test(tc, s21_sprintf_65);
  tcase_add_test(tc, s21_sprintf_66);
  tcase_add_test(tc, s21_sprintf_67);
  tcase_add_test(tc, s21_sprintf_68);
  tcase_add_test(tc, s21_sprintf_69);
  tcase_add_test(tc, s21_sprintf_70);
  tcase_add_test(tc, s21_sprintf_71);
  tcase_add_test(tc, s21_sprintf_72);
  tcase_add_test(tc, s21_sprintf_73);
  tcase_add_test(tc, s21_sprintf_74);
  tcase_add_test(tc, s21_sprintf_75);
  tcase_add_test(tc, s21_sprintf_76);
  tcase_add_test(tc, s21_sprintf_77);
  tcase_add_test(tc, s21_sprintf_78);
  tcase_add_test(tc, s21_sprintf_79);
  tcase_add_test(tc, s21_sprintf_80);
  tcase_add_test(tc, s21_sprintf_81);
  tcase_add_test(tc, s21_sprintf_82);
  tcase_add_test(tc, s21_sprintf_83);
  tcase_add_test(tc, s21_sprintf_84);
  tcase_add_test(tc, s21_sprintf_85);
  tcase_add_test(tc, s21_sprintf_86);
  tcase_add_test(tc, s21_sprintf_87);
  tcase_add_test(tc, s21_sprintf_88);
  tcase_add_test(tc, s21_sprintf_89);
  tcase_add_test(tc, s21_sprintf_90);
  tcase_add_test(tc, s21_sprintf_91);
  tcase_add_test(tc, s21_sprintf_92);
  tcase_add_test(tc, s21_sprintf_93);
  tcase_add_test(tc, s21_sprintf_94);
  tcase_add_test(tc, s21_sprintf_95);
  tcase_add_test(tc, s21_sprintf_96);
  tcase_add_test(tc, s21_sprintf_97);
  tcase_add_test(tc, s21_sprintf_98);
  tcase_add_test(tc, s21_sprintf_99);
  tcase_add_test(tc, s21_sprintf_100);
  tcase_add_test(tc, s21_sprintf_101);
  tcase_add_test(tc, s21_sprintf_102);
  tcase_add_test(tc, s21_sprintf_103);
  tcase_add_test(tc, s21_sprintf_104);
  tcase_add_test(tc, s21_sprintf_105);
  tcase_add_test(tc, s21_sprintf_106);
  tcase_add_test(tc, s21_sprintf_107);
  tcase_add_test(tc, s21_sprintf_108);
  tcase_add_test(tc, s21_sprintf_109);
  tcase_add_test(tc, s21_sprintf_110);
  tcase_add_test(tc, s21_sprintf_111);
  tcase_add_test(tc, s21_sprintf_112);
  tcase_add_test(tc, s21_sprintf_113);
  tcase_add_test(tc, s21_sprintf_114);
  tcase_add_test(tc, s21_sprintf_115);
  tcase_add_test(tc, s21_sprintf_116);
  tcase_add_test(tc, s21_sprintf_117);
  tcase_add_test(tc, s21_sprintf_118);
  tcase_add_test(tc, s21_sprintf_119);
  tcase_add_test(tc, s21_sprintf_120);
  tcase_add_test(tc, s21_sprintf_121);
  tcase_add_test(tc, s21_sprintf_122);
  tcase_add_test(tc, s21_sprintf_123);
  tcase_add_test(tc, s21_sprintf_124);
  tcase_add_test(tc, s21_sprintf_125);
  tcase_add_test(tc, s21_sprintf_126);
  tcase_add_test(tc, s21_sprintf_127);
  tcase_add_test(tc, s21_sprintf_128);
  tcase_add_test(tc, s21_sprintf_129);
  tcase_add_test(tc, s21_sprintf_130);
  tcase_add_test(tc, s21_sprintf_131);

  // tcase_add_test(tc, sprintf_53);

  suite_add_tcase(s, tc);
  return s;
}

int s21_sprintf_run_test(void) {
  Suite *suite = s21_sprintf_create_suite();
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}