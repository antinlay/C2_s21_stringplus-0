#include <check.h>
#include <string.h>
#include <stdio.h>

#include "s21_string.h"

START_TEST(s21_memchr_test)
{
    char str1[] = "QWERTY\0";
    char str2[] = "QWETY1";
    char str3[] = "";
    int c = 'R';
    s21_size_t n = 5;

    ck_assert_str_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
    ck_assert_str_eq(s21_memchr(str2, c, n), memchr(str2, c, n));
    ck_assert_str_eq(s21_memchr(str3, c, n), memchr(str3, c, n));
}
END_TEST

START_TEST(s21_memcmp_test)
{
    char str1[] = "1234567890";
    char str2[] = "1234567890";
    char str3[] = "123\0";
    char str4[] = "";
    s21_size_t n = 5;

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
    ck_assert_int_eq(s21_memcmp(str2, str3, n), memcmp(str2, str3, n));
    ck_assert_int_eq(s21_memcmp(str3, str4, n), memcmp(str3, str4, n));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf = 0;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_memchr_test);
    tcase_add_test(tc1_1, s21_memcmp_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    if (nf == 0)
        nf = 0;
    else
        nf = 1;
    return nf;
}
