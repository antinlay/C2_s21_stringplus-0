
#include "s21_string.h"
#include <check.h>
#include <string.h>
// #include <stdio.h>



START_TEST(s21_memchr_test)
{
    char str1[15] = "1234567890";
    char str2[3] = {'\0', '\0', '\0'};
    char str3[0] = "";
    int c = '5';
    s21_size_t n = 5;

    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
    ck_assert_ptr_eq(s21_memchr(str2, '\0', 2), memchr(str2, '\0', 2));
    ck_assert_ptr_eq(s21_memchr(str3, c, n), memchr(str3, c, n));
}
END_TEST

START_TEST(s21_memcmp_test)
{
    char str1[10] = "12345";
    char dst1[10] = "12345";
    char str2[10] = "\0";
    char dst2[10] = "\0";
    char str3[10] = "abc";
    char dst3[10] = "ABC";

    s21_size_t n = 5;

    ck_assert_int_eq(s21_memcmp(str1, dst1, n), memcmp(str1, dst1, n));
    ck_assert_int_eq(s21_memcmp(str2, dst2, 1), memcmp(str2, dst2, 1));
    ck_assert_int_eq(s21_memcmp(str3, dst3, 1), memcmp(str3, dst3, 1));
}
END_TEST

START_TEST(s21_memmove_test)
{
    char str1[7] = "abcdef";
    char dst1[3] = "123";
    // char str2[10] = "";
    char dst2[4] = "123";
    char str3[3] = "";
    char dst3[3] = "ABC";
    // char str4[3] = "";
    // char dst4[3] = "ABC";

    void *res1, *res2;

    // s21_size_t n = 5;

    res1 = s21_memmove(str1, dst1, 3);
    res2 = memmove(str1, dst1, 3);

    ck_assert_str_eq(res1, res2);
    ck_assert_str_eq(s21_memmove(&str1[4], &str1[3], 3), memmove(&str1[4], &str1[3], 3));
    ck_assert_str_eq(s21_memmove(&str1[3], &str1[4], 3), memmove(&str1[3], &str1[4], 3));
    ck_assert_str_eq(s21_memmove(str3, dst3, 3), memmove(str3, dst3, 3));
    ck_assert_str_eq(s21_memmove(dst2, str1, 2), memmove(dst2, str1, 2)); 
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
}
END_TEST

START_TEST(s21_strcmp_test) {
  char str1[4] = "Bus";
  char str2[4] = "Bus";
  char str3[4] = "Ke";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
    ck_assert_int_eq(s21_strcmp(str2, str3), strcmp(str2, str3));
    ck_assert_int_eq(s21_strcmp(str3, str2), strcmp(str3, str2));
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[4] = "Bus";
  char str2[4] = "Bus";
  char str3[4] = "Ke";

    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
    ck_assert_int_eq(s21_strncmp(str2, str3, 2), strncmp(str2, str3, 2));
    ck_assert_int_eq(s21_strncmp(str3, str2, 2), strncmp(str3, str2, 2));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str1[8] = "LCevBus";
  char str2[4] = "Bus";
  char str3[4] = "Kse";

    ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
    ck_assert_str_eq(s21_strpbrk(str2, str3), strpbrk(str2, str3));
    ck_assert_str_eq(s21_strpbrk(str3, str2), strpbrk(str3, str2));
}
END_TEST

START_TEST(s21_memset_test) {
    char str[8] = "1234567";
    int c = '5';
    s21_size_t n = 2;
 
    ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}    
END_TEST

START_TEST(s21_strcat_test) {
  char str1[15] = "LCevBus";
  char str2[5] = "Bus\0";
  char str3[15] = "";
  char str4[5] = "Bus\0";
  char str5[30] = "LCevBus";
  char str6[30] = "Bus\0";

    ck_assert_str_eq(s21_strcat(str1, str2), strcat(str1, str2));
    ck_assert_str_eq(s21_strcat(str3, str4), strcat(str3, str4));
    ck_assert_str_eq(s21_strcat(str6, str5), strcat(str6, str5));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[30] = "LCevBus";
  int n = 'e';
  // char str2[30] = "Bus\0";
  // char str3[60] = "";

    ck_assert_str_eq(s21_strchr(str1, n), strchr(str1, n));
    // ck_assert_str_eq(s21_strchr(str2, str1), strchr(str2, str1));
    // ck_assert_str_eq(s21_strchr(str3, str2), strchr(str3, str2));
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

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed != 0) ? 1 : 0;
}
