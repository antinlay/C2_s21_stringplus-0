#include <check.h>
#include <string.h>
// #include <stdlib.h>

#include "s21_string.h"

START_TEST(s21_strrchr_test) {
  char *out1, *out2;
  char str[8] = "xyz_069";
  int n = '_';

  out1 = s21_strrchr(str, n);
  out2 = strrchr(str, n);
  ck_assert_str_eq(out1, out2);
} END_TEST

START_TEST(s21_strncpy_test) {
  s21_size_t n;
  char *out1, *out2;
  char src1[13] = "ONETWOFIVE\0";
  char dest1[6] = "TWO\0";
  char src2[2] = "\0";
  char dest2[2] = "\0";

  n = 3;
  out1 = s21_strncpy(dest1, src1, n);
  out2 = strncpy(dest1, src1, n);
  ck_assert_str_eq(out1, out2);

  n = 2;
  out1 = s21_strncpy(dest2, src2, n);
  out2 = strncpy(dest2, src2, n);
  ck_assert_str_eq(out1, out2);
} END_TEST

START_TEST(s21_strcspn_test) {
  s21_size_t out1, out2;
  char str1[25] = "HELLO EVERYBODY";
  char str2[6] = "ELL0H";
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
  char str1[25] = "ZELLO EVERYBODY";
  char str2[10] = "HELL0";
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
  // s21_size_t n = 5;
  char src1[15] = "gdsfa";
  char dst1[3] = "654";
  char src2[11];
  char dst2[11] = "9087654321";
  char src3[3];
  char dst3[3] = "654";
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
  out1 = s21_strlen("QWERTY\0");
  out2 = strlen("QWERTY\0");
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
}
END_TEST

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
    
    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed != 0) ? 1 : 0;
}

