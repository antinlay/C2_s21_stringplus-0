#include <check.h>
#include <string.h>
<<<<<<< src/s21_test.c
#include "test.h"
#include "s21_string.h"

START_TEST(s21_sprintf_test) {
    ck_assert_pstr_eq(s21_strrchr(s8, 'n'), strrchr(s8, 'n'));
  char c1[999] = "";
    ck_assert_pstr_eq(s21_strrchr(s3, '0'), strrchr(s3, '0'));
  char c2[999] = "";
    ck_assert_pstr_eq(s21_strrchr(s4, 'n'), strrchr(s4, 'n'));
  char *str_pf = "%-c%c%+d%-.d%i%e%E%f%g%%%-16.5o%+016.5o%s%u%x%X%.6f";
    ck_assert_pstr_eq(s21_strrchr(s7, '0'), strrchr(s7, '0'));
  char r[100];

  int st_x = 110;
} END_TEST

START_TEST(s21_strrchr_test) {
     
    ck_assert_str_eq(s21_strrchr(s1, 'l'), strrchr(s1, 'l'));
    ck_assert_pstr_eq(s21_strrchr(s8, 'n'), strrchr(s8, 'n'));
    ck_assert_pstr_eq(s21_strrchr(s3, '0'), strrchr(s3, '0'));
    ck_assert_pstr_eq(s21_strrchr(s4, 'n'), strrchr(s4, 'n'));
    ck_assert_pstr_eq(s21_strrchr(s7, '0'), strrchr(s7, '0'));

} END_TEST

START_TEST(s21_strncpy_test)
{
    ck_assert_str_eq(s21_strncpy(s1, s9, 2), strncpy(s1, s9, 2));
    ck_assert_str_eq(s21_strncpy(s9, s2, 1), strncpy(s9, s2, 1));
    ck_assert_str_eq(s21_strncpy(s3, s4, 6), strncpy(s3, s4, 6));
    ck_assert_str_eq(s21_strncpy(s4, s5, 3), strncpy(s4, s5, 3));
    ck_assert_str_eq(s21_strncpy(s6, s7, 3), strncpy(s6, s7, 3));
    ck_assert_str_eq(s21_strncpy(s7, s1, 3), strncpy(s7, s1, 3));
}
END_TEST

START_TEST(s21_strcspn_test) 
{
    ck_assert_int_eq(s21_strcspn(s1, s9), strcspn(s1, s9));
    ck_assert_int_eq(s21_strcspn(s9, s2), strcspn(s9, s2));
    ck_assert_int_eq(s21_strcspn(s3, s4), strcspn(s3, s4));
    ck_assert_int_eq(s21_strcspn(s4, s5), strcspn(s4, s5));
    ck_assert_int_eq(s21_strcspn(s6, s7), strcspn(s6, s7));
    ck_assert_int_eq(s21_strcspn(s7, s1), strcspn(s7, s1));
} 
END_TEST

START_TEST(s21_strcpy_test) 
{
    ck_assert_str_eq(s21_strcpy(s1, s9), strcpy(s1, s9));
    ck_assert_str_eq(s21_strcpy(s9, s2), strcpy(s9, s2));
    ck_assert_str_eq(s21_strcpy(s3, s4), strcpy(s3, s4));
    ck_assert_str_eq(s21_strcpy(s4, s5), strcpy(s4, s5));
    ck_assert_str_eq(s21_strcpy(s6, s7), strcpy(s6, s7));
    ck_assert_str_eq(s21_strcpy(s7, s1), strcpy(s7, s1));
} 
END_TEST

START_TEST(s21_memset_test) 
{
    ck_assert_pstr_eq(s21_memset(s1, 'o', 5), memset(s1, 'o', 5));
    ck_assert_pstr_eq(s21_memset(s2, 'o', 5), memset(s2, 'o', 5));
    ck_assert_pstr_eq(s21_memset(s3, 'o', 1), memset(s3, 'o', 1));
    ck_assert_pstr_eq(s21_memset(s4, '0', 1), memset(s4, '0', 1));
    ck_assert_pstr_eq(s21_memset(s5, 'n', 1), memset(s5, 'n', 1));
    ck_assert_pstr_eq(s21_memset(s6, '\n', 1), memset(s6, '\n', 1));
    ck_assert_pstr_eq(s21_memset(s7, '\0', 1), memset(s7, '\0', 1));
} 
END_TEST

START_TEST(s21_memcpy_test) 
{
    ck_assert_pstr_eq(s21_memcpy(s1, s2, 5), memcpy(s1, s1, 5));
    ck_assert_pstr_eq(s21_memcpy(s2, s3, 5), memcpy(s2, s3, 5));
    ck_assert_pstr_eq(s21_memcpy(s3, s4, 1), memcpy(s3, s4, 1));
    ck_assert_pstr_eq(s21_memcpy(s4, s5, 1), memcpy(s4, s5, 1));
    ck_assert_pstr_eq(s21_memcpy(s5, s6, 1), memcpy(s5, s6, 1));
    ck_assert_pstr_eq(s21_memcpy(s6, s7, 1), memcpy(s6, s7, 1));
    ck_assert_pstr_eq(s21_memcpy(s7, s1, 1), memcpy(s7, s1, 1));
} 
END_TEST

START_TEST(s21_strlen_test) 
{
  ck_assert_int_eq(s21_strlen(s1), strlen(s1));
  ck_assert_int_eq(s21_strlen(s2), strlen(s2));
  ck_assert_int_eq(s21_strlen(s3), strlen(s3));
  ck_assert_int_eq(s21_strlen(s4), strlen(s4));
  ck_assert_int_eq(s21_strlen(s5), strlen(s5));
  ck_assert_int_eq(s21_strlen(s6), strlen(s6));
  ck_assert_int_eq(s21_strlen(s7), strlen(s7));
  ck_assert_int_eq(s21_strlen(s8), strlen(s8));
  ck_assert_int_eq(s21_strlen(s9), strlen(s9));
  ck_assert_int_eq(s21_strlen(s10), strlen(s10));
  ck_assert_int_eq(s21_strlen(s11), strlen(s11));
  ck_assert_int_eq(s21_strlen(s12), strlen(s12));
} 
END_TEST

START_TEST(s21_strerror_test) 
{
  for(int n = 0; n <= 90; n++) 
  {
  char *out1 = s21_strerror(n);
  char *out2 = strerror(n);
  ck_assert_str_eq(out1, out2);
  }
}
END_TEST

START_TEST(s21_memchr_test)
{
    ck_assert_pstr_eq(s21_memchr(s1, 5, 5), memchr(s1, 5, 5));
    ck_assert_pstr_eq(s21_memchr(s2, 5, 2), memchr(s2, 5, 2));
    ck_assert_pstr_eq(s21_memchr(s3, 1, 1), memchr(s3, 1, 1));
    ck_assert_pstr_eq(s21_memchr(s4, 1, 1), memchr(s4, 1, 1));
    ck_assert_pstr_eq(s21_memchr(s5, 2, 2), memchr(s5, 2, 2));
    ck_assert_pstr_eq(s21_memchr(s6, 1, 1), memchr(s6, 1, 1));
    ck_assert_pstr_eq(s21_memchr(s7, '\0', 1), memchr(s7, '\0', 1));
}
END_TEST

START_TEST(s21_memcmp_test)
{
    ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s1, 5));
    ck_assert_int_eq(s21_memcmp(s2, s3, 5), memcmp(s2, s3, 5));
    ck_assert_int_eq(s21_memcmp(s3, s4, 1), memcmp(s3, s4, 1));
    ck_assert_int_eq(s21_memcmp(s4, s5, 1), memcmp(s4, s5, 1));
    ck_assert_int_eq(s21_memcmp(s5, s6, 1), memcmp(s5, s6, 1));
    ck_assert_int_eq(s21_memcmp(s6, s7, 1), memcmp(s6, s7, 1));
    ck_assert_int_eq(s21_memcmp(s7, s1, 1), memcmp(s7, s1, 1));
}
END_TEST

START_TEST(s21_memmove_test)
{
    ck_assert_str_eq(s21_memmove(s1, s2, 3), memmove(s1, s2, 3));
    ck_assert_str_eq(s21_memmove(&s1[4], &s1[3], 3), memmove(&s1[4], &s1[3], 3));
    ck_assert_str_eq(s21_memmove(&s1[3], &s1[4], 3), memmove(&s1[3], &s1[4], 3));
    ck_assert_str_eq(s21_memmove(s2, s3, 1), memmove(s2, s3, 1));
    ck_assert_str_eq(s21_memmove(s4, s5, 1), memmove(s4, s5, 1));
    ck_assert_str_eq(s21_memmove(s6, s7, 1), memmove(s6, s7, 1)); 
}
END_TEST

START_TEST(s21_strncat_test)
{
    ck_assert_str_eq(s21_strncat(s1, s9, 2), strncat(s1, s9, 2));
    ck_assert_str_eq(s21_strncat(s9, s2, 1), strncat(s9, s2, 1));
    ck_assert_str_eq(s21_strncat(s3, s4, 6), strncat(s3, s4, 6));
    ck_assert_str_eq(s21_strncat(s4, s5, 1), strncat(s4, s5, 1));
    ck_assert_str_eq(s21_strncat(s6, s7, 1), strncat(s6, s7, 1));
    ck_assert_str_eq(s21_strncat(s7, s1, 1), strncat(s7, s1, 1));
}
END_TEST

START_TEST(s21_strcmp_test) 
{
    ck_assert_int_eq(s21_strcmp(s1, s8), strcmp(s1, s8));
    ck_assert_int_eq(s21_strcmp(s2, s2), strcmp(s2, s2));
    ck_assert_int_eq(s21_strcmp(s3, s3), strcmp(s3, s3));
    ck_assert_int_eq(s21_strcmp(s4, s4), strcmp(s4, s4));
    ck_assert_int_eq(s21_strcmp(s5, s5), strcmp(s5, s5));
    ck_assert_int_eq(s21_strcmp(s6, s6), strcmp(s6, s6));
    ck_assert_int_eq(s21_strcmp(s7, s7), strcmp(s7, s7));
}
END_TEST

START_TEST(s21_strncmp_test) {

    ck_assert_int_eq(s21_strncmp(s1, s9, 3), strncmp(s1, s9, 3));
    ck_assert_int_eq(s21_strncmp(s1, s8, 2), strncmp(s1, s8, 2));
    ck_assert_int_eq(s21_strncmp(s8, s1, 2), strncmp(s8, s1, 2));
    ck_assert_int_eq(s21_strncmp(s1, s8, 8), strncmp(s1, s8, 8));
    ck_assert_int_eq(s21_strncmp(s1, s2, 8), strncmp(s1, s2, 8));
    ck_assert_int_eq(s21_strncmp(s3, s4, 1), strncmp(s3, s4, 1));
    ck_assert_int_eq(s21_strncmp(s5, s6, 1), strncmp(s5, s6, 1));
    ck_assert_int_eq(s21_strncmp(s6, s7, 1), strncmp(s6, s7, 1));
}
END_TEST

START_TEST(s21_strpbrk_test) {
 
    ck_assert_str_eq(s21_strpbrk(s1, s9), strpbrk(s1, s9));
    ck_assert_str_eq(s21_strpbrk(s1, s8), strpbrk(s1, s8));
    ck_assert_str_eq(s21_strpbrk(s8, s1), strpbrk(s8, s1));
    ck_assert_str_eq(s21_strpbrk(s2, s3), strpbrk(s2, s3));
    ck_assert_str_eq(s21_strpbrk(s4, s5), strpbrk(s4, s5));
    ck_assert_pstr_eq(s21_strpbrk(s6, s7), strpbrk(s6, s7));

}
END_TEST

START_TEST(s21_strcat_test) {

    ck_assert_str_eq(s21_strcat(s1, s9), strcat(s1, s9));
    ck_assert_str_eq(s21_strcat(s10, s9), strcat(s10, s9));
    ck_assert_str_eq(s21_strcat(s2, s3), strcat(s2, s3));
    ck_assert_str_eq(s21_strcat(s6, s7), strcat(s6, s7));
    ck_assert_str_eq(s21_strcat(s8, s9), strcat(s8, s9));
    ck_assert_str_eq(s21_strcat(s3, s4), strcat(s3, s4));
    ck_assert_str_eq(s21_strcat(s5, s6), strcat(s5, s6));
}
END_TEST

START_TEST(s21_strchr_test)
{
    ck_assert_str_eq(s21_strchr(s1, 'o'), strchr(s1, 'o'));
    ck_assert_str_eq(s21_strchr(s2, 'o'), strchr(s2, 'o'));
    ck_assert_str_eq(s21_strchr(s3, 'a'), strchr(s3, 'a'));
    ck_assert_pstr_eq(s21_strchr(s4, 'n'), strchr(s4, 'n'));
    ck_assert_str_eq(s21_strchr(s5, ' '), strchr(s5, ' '));
    ck_assert_str_eq(s21_strchr(s6, '\0'), strchr(s6, '\0'));
    ck_assert_pstr_eq(s21_strchr(s7, '0'), strchr(s7, '0'));
}
END_TEST

START_TEST(s21_strstr_test) {
    ck_assert_str_eq(s21_strstr(s1, s9), strstr(s1, s9));
    ck_assert_pstr_eq(s21_strstr(s2, s3), strstr(s2, s3));
    ck_assert_pstr_eq(s21_strstr(s3, s4), strstr(s3, s4));
    ck_assert_pstr_eq(s21_strstr(s5, s6), strstr(s5, s6));
    ck_assert_pstr_eq(s21_strstr(s6, s7), strstr(s6, s7));
    ck_assert_pstr_eq(s21_strstr(s7, s8), strstr(s7, s8));
}
END_TEST

START_TEST(s21_strspn_test) {
    ck_assert_int_eq(s21_strspn(s1, s1), strspn(s1, s1));
    ck_assert_int_eq(s21_strspn(s1, s9), strspn(s1, s9));
    ck_assert_int_eq(s21_strspn(s2, s9), strspn(s2, s9));
    ck_assert_int_eq(s21_strspn(s3, s4), strspn(s3, s4));
    ck_assert_int_eq(s21_strspn(s5, s6), strspn(s5, s6));
    ck_assert_int_eq(s21_strspn(s6, s7), strspn(s6, s7));
    ck_assert_int_eq(s21_strspn(s8, s7), strspn(s8, s7));
    ck_assert_int_eq(s21_strspn(s8, s10), strspn(s8, s10));
}
END_TEST

START_TEST(s21_strtok_test) {

    ck_assert_str_eq(s21_strtok(s1, s14), strtok(s17, s14));
    ck_assert_pstr_eq(s21_strtok(s8, s7), strtok(s8, s7));
    ck_assert_str_eq(s21_strtok(s8, s10), strtok(s8, s10));
    ck_assert_str_eq(s21_strtok(s6, s7), strtok(s6, s7));
    ck_assert_str_eq(s21_strtok(s8, s9), strtok(s8, s9));
    ck_assert_pstr_eq(s21_strtok(s10, s14), strtok(s10, s14));
    ck_assert_str_eq(s21_strtok(s9, s14), strtok(s9, s14));
    ck_assert_str_eq(s21_strtok(s15, s14), strtok(s16, s14));
}
END_TEST
=======
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
>>>>>>> src/s21_test.c

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
<<<<<<< src/s21_test.c
    tcase_add_test(case_test, s21_memchr_test);
    tcase_add_test(case_test, s21_memcmp_test);
    tcase_add_test(case_test, s21_memmove_test);
    tcase_add_test(case_test, s21_strncat_test);
    tcase_add_test(case_test, s21_strcmp_test);
    tcase_add_test(case_test, s21_strncmp_test);
    tcase_add_test(case_test, s21_strpbrk_test);
    tcase_add_test(case_test, s21_strcat_test);
    tcase_add_test(case_test, s21_strchr_test);
    tcase_add_test(case_test, s21_strstr_test);
    tcase_add_test(case_test, s21_strspn_test);
    tcase_add_test(case_test, s21_strtok_test);
    
    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (num_failed != 0) ? 1 : 0;
}

=======
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
>>>>>>> src/s21_test.c
