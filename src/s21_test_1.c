
#include "s21_string.h"
#include "test.h"
#include <check.h>
#include <string.h>
// #include <stdio.h>



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
// есть ошибка при попытке записть в массив имеющий меньший размер массива
{
    char str1[15] = "Bom";
    char str2[15] = "Val";
    char str3[15] = "sop";
    s21_size_t n = 2;

    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
    ck_assert_str_eq(s21_strncat(str3, str2, 1), strncat(str3, str2, 1));
    ck_assert_str_eq(s21_strncat(str2, str3, 6), strncat(str2, str3, 6));
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
  char str1[4] = "Bus";
  char str2[4] = "Bus";
  char str3[4] = "Ke";

    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
    ck_assert_int_eq(s21_strncmp(str2, str3, 2), strncmp(str2, str3, 2));
    ck_assert_int_eq(s21_strncmp(str3, str2, 2), strncmp(str3, str2, 2));
    ck_assert_int_eq(s21_strncmp(s1, s8, 8), strncmp(s1, s8, 8));
    ck_assert_int_eq(s21_strncmp(s1, s2, 8), strncmp(s1, s2, 8));
    ck_assert_int_eq(s21_strncmp(s3, s4, 1), strncmp(s3, s4, 1));
    ck_assert_int_eq(s21_strncmp(s5, s6, 1), strncmp(s5, s6, 1));
    ck_assert_int_eq(s21_strncmp(s6, s7, 1), strncmp(s6, s7, 1));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str1[8] = "LCevBus";
  char str2[4] = "Bus";
  char str3[4] = "Kse";

    ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
    ck_assert_str_eq(s21_strpbrk(str2, str3), strpbrk(str2, str3));
    ck_assert_str_eq(s21_strpbrk(str3, str2), strpbrk(str3, str2));
    ck_assert_str_eq(s21_strpbrk(s2, s3), strpbrk(s2, s3));
    ck_assert_str_eq(s21_strpbrk(s4, s5), strpbrk(s4, s5));
    ck_assert_pstr_eq(s21_strpbrk(s6, s7), strpbrk(s6, s7));

}
END_TEST

START_TEST(s21_memset_test)
{
    char str[8] = "1234567";
    char str1[] = "s21_NULL";

    ck_assert_str_eq(s21_memset(str, 5, 2), memset(str, 5, 2));
    ck_assert_str_eq(s21_memset(str1, 5, 2), memset(str1, 5, 2));
    ck_assert_str_eq(s21_memset(s3, 6, 6), memset(s3, 6, 6));
    ck_assert_str_eq(s21_memset(s4, 5, 2), memset(s4, 5, 2));
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

int main(void)
{
    Suite *s21 = suite_create("s21_string");
    TCase *tc1_1 = tcase_create("test");
    SRunner *sr = srunner_create(s21);
    int num_failed = 0;

    suite_add_tcase(s21, tc1_1);
    tcase_add_test(tc1_1, s21_memchr_test);
    tcase_add_test(tc1_1, s21_memcmp_test);
    tcase_add_test(tc1_1, s21_memmove_test);
    tcase_add_test(tc1_1, s21_strncat_test);
    tcase_add_test(tc1_1, s21_strcmp_test);
    tcase_add_test(tc1_1, s21_strncmp_test);
    tcase_add_test(tc1_1, s21_strpbrk_test);
    tcase_add_test(tc1_1, s21_memset_test);    
    tcase_add_test(tc1_1, s21_strcat_test);
    tcase_add_test(tc1_1, s21_strchr_test);
    tcase_add_test(tc1_1, s21_strstr_test);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed != 0) ? 1 : 0;
}
