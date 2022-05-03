#include <check.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

START_TEST(s21_sprintf_test) {
  char c1[999] = "";
  char c2[999] = "";
  char *str_pf = "%-c%c%+d%-.d%i%e%E%f%g%%%-16.5o%+016.5o%s%u%x%X%.6f";
  char r[100];
  int st_x = 110;
// c1 == "8     #+6111001.000000e-031.110000E-010.0009991.12353%4171731                  4171731Hello9940A16.160000"
// c2 == "8      #+6111001.000000e-031.110000E-010.0009991.12353%4171731                  4171731Hello9940A16.160000"
  //   %p
  // char str2[200] = "%.*d %d % f %+-*d %% %n %*.*s";
  s21_sprintf(c1, str_pf, '8', '#', 6, 11, 100, 0.001, 0.111, 0.000999, 1.12354, 1111001, 1111001, "Hello\0", 99, 16.16, 64, 10, 11.3);
  sprintf(c2, str_pf, '8', '#', 6, 11, 100, 0.001, 0.111, 0.000999, 1.12353, 1111001, 1111001, "Hello\0", 99, 16.16, 64, 10, 11.3);
  ck_assert_str_eq(c1, c2);
  ck_assert_int_eq(s21_sprintf(r, "%x", st_x), sprintf(r, "%x", st_x));
  ck_assert_int_eq(s21_sprintf(r, "%16.5x", st_x), sprintf(r, "%16.5x", st_x));
  // ck_assert_int_ne(s21_sprintf(r, "%+16.5x", st_x), sprintf(r, "%+16.5x", st_x));
  ck_assert_int_eq(s21_sprintf(r, "%-16.5x", st_x), sprintf(r, "%-16.5x", st_x));
  // ck_assert_int_ne(s21_sprintf(r, "%016.5x", st_x), sprintf(r, "%016.5x", st_x));
  // ck_assert_int_ne(s21_sprintf(r, "% 16.5x", st_x), sprintf(r, "% 16.5x", st_x));
  ck_assert_int_eq(s21_sprintf(r, "%#16.5x", st_x), sprintf(r, "%#16.5x", st_x));
  int n28 = 0;

  ck_assert_int_eq(s21_sprintf(r, "%n"), sprintf(r, "%n", &n28));

  ck_assert_int_eq(s21_sprintf(r, "%%"), sprintf(r, "%%"));
} END_TEST

START_TEST(s21_insert_test) {
  char src1[30] = "He Wollorld&llo\0";
  char trim_chars1[6] = "llo\0";
  void *out1;

  out1 = s21_insert(src1, trim_chars1, 2);
  ck_assert_str_eq(out1, "Hello Wollorld&llo\0");
  // free(out1);
} END_TEST

START_TEST(s21_trim_test) {
  char src2[50] = "llo Wollorld&lol\0";
  char trim_chars2[10] = "llo\0";
  char res[50] = " Wollorld&\0";
  void *out2;
  out2 = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(out2, res);
  // free(out);
} END_TEST

START_TEST(s21_to_upper_test) {
  char *str_u = "aZi13E1";
  char *out4 = "AZI13E1";
  ck_assert_str_eq(s21_to_upper(str_u), out4);

  // free(out1);
} END_TEST

START_TEST(s21_to_lower_test) {
  char *str_l = "AZI13E1";
  char *out6 = "azi13e1";
  ck_assert_str_eq(s21_to_lower(str_l), out6);
  // free(out1);
} END_TEST

START_TEST(s21_strrchr_test) {
  // char out7[50], out8[50];
  char str_s[15] = "xyz_069\0";
  int n = '_';

  ck_assert_str_eq(s21_strrchr(str_s, n), strrchr(str_s, n));
} END_TEST

START_TEST(s21_strncpy_test) {
  s21_size_t n;
  char *out9 = s21_NULL; char *out2 = s21_NULL;
  char src1[13] = "ONETWOFIVE\0";
  char dest1[6] = "TWO\0";
  char src2[2] = "\0";
  char dest2[2] = "\0";

  n = 3;
  out9 = s21_strncpy(dest1, src1, n);
  out2 = strncpy(dest1, src1, n);
  ck_assert_str_eq(out9, out2);

  n = 2;
  out9 = s21_strncpy(dest2, src2, n);
  out2 = strncpy(dest2, src2, n);
  ck_assert_str_eq(out9, out2);
} END_TEST

START_TEST(s21_strcspn_test) {
  s21_size_t out1, out2;
  char str1[25] = "HELLO EVERYBODY\0";
  char str2[6] = "ELL0H\0";
  char str3[2] = "\0";

  out1 = s21_strcspn(str1, str2);
  out2 = strcspn(str1, str2);
  ck_assert_int_eq(out1, out2);

  out1 = s21_strcspn(str3, str2);
  out2 = strcspn(str3, str2);
  ck_assert_int_eq(out1, out2);

  out1 = s21_strcspn(str2, str3);
  out2 = strcspn(str2, str3);
  ck_assert_int_eq(out1, out2);
} END_TEST

START_TEST(s21_strcpy_test) {
  char src1[13] = "ONETWOFIVE\0";
  char dest1[6] = "Two\0";
  char src2[2] = "\0";
  char dest2[2] = "\0";
  char *out1, *out2;

  out1 = s21_strcpy(dest1, src1);
  out2 = strcpy(dest1, src1);
  ck_assert_str_eq(out1, out2);

  out1 = s21_strcpy(dest2, src2);
  out2 = strcpy(dest2, src2);
  ck_assert_str_eq(out1, out2);
} END_TEST

START_TEST(s21_memset_test) {
  void *out1, *out2;
  char str1[25] = "ZELLO EVERYBODY\0";
  char str2[10] = "HELL0\0";
  char str3[3];
  int c = 'H';
  s21_size_t n = 1;

  out1 = s21_memset(str1, c, n);
  out2 = memset(str1, c, n);
  ck_assert_str_eq(out1, out2);

  n = 5;
  out1 = s21_memset(str2, c, n);
  out2 = memset(str2, c, n);
  ck_assert_str_eq(out1, out2);

  n = 2; c = '\0';
  out1 = s21_memset(str3, c, n);
  out2 = memset(str3, c, n);
  ck_assert_str_eq(out1, out2);
} END_TEST

START_TEST(s21_memcpy_test) {
  char src1[15] = "gdsfa\0";
  char dst1[5] = "654\0";
  char src2[11];
  char dst2[11] = "9087654321\0";
  char src3[3];
  char dst3[5] = "654\0";
  void *out1, *out2;
  out1 = s21_memcpy(dst1, src1, 3);
  out2 = memcpy(dst1, src1, 3);
  ck_assert_str_eq(out1, out2);

  out1 = s21_memcpy(dst2, src2, 10);
  out2 = memcpy(dst2, src2, 10);
  ck_assert_str_eq(out1, out2);

  out1 = s21_memcpy(dst3, src3, 3);
  out2 = memcpy(dst3, src3, 3);
  ck_assert_str_eq(out1, out2);
} END_TEST

START_TEST(s21_strlen_test) {
  s21_size_t out1, out2;
  out1 = s21_strlen("QWER\0");
  out2 = strlen("QWER\0");
  ck_assert_int_eq(out1, out2);
  out1 = s21_strlen("\0");
  out2 = strlen("\0");
  ck_assert_int_eq(out1, out2);
} END_TEST

START_TEST(s21_strerror_test) {
  int n = 2;
  char *out1 = s21_strerror(n);
  char *out2 = strerror(n);
  ck_assert_str_eq(out1, out2);
  n = 96;
  ck_assert_str_eq(out1, out2);
  n = -96;
  ck_assert_str_eq(out1, out2);
} END_TEST

int main(void) {
    Suite *s21 = suite_create("s21_string");
    TCase *case_test = tcase_create("test");
    SRunner *sr = srunner_create(s21);
    int num_failed = 0;

    suite_add_tcase(s21, case_test);
    tcase_add_test(case_test, s21_strcpy_test);
    tcase_add_test(case_test, s21_memset_test);
    tcase_add_test(case_test, s21_memcpy_test);
    tcase_add_test(case_test, s21_strlen_test);
    tcase_add_test(case_test, s21_strcspn_test);
    tcase_add_test(case_test, s21_strncpy_test);
    tcase_add_test(case_test, s21_strrchr_test);
    tcase_add_test(case_test, s21_strerror_test);
    tcase_add_test(case_test, s21_sprintf_test);
    tcase_add_test(case_test, s21_to_upper_test);
    tcase_add_test(case_test, s21_to_lower_test);
    tcase_add_test(case_test, s21_trim_test);
    tcase_add_test(case_test, s21_insert_test);
    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed != 0) ? 1 : 0;
}
// "Hello Wollorld&llo" == 
// "Hello Wollorld&llo"
// out1 == "GFDKHJGFKJGFD"
// out2 == "GFDKHJGFKJGFD"

// 'out1 == out2' failed: out1 == "A2I_test.c", out2 == "AZI13E"