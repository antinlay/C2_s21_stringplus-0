#include <check.h>
#include <string.h>
#include <stdio.h>

#include "s21_string.h"


START_TEST(s21_strlen_test) {
    char str1[] = "QWERTY\0";
    char str2[] = "QWERTY1";
    ck_assert_int_eq(s21_strlen(str1), strlen(str2));
    ck_assert_int_eq(s21_strlen(str1), strlen(str1));
} END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf = 0;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_strlen_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    if (nf == 0) nf = 0;
    else nf = 1;
    return nf;
}