#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_memcpy_test) {
    // s21_size_t n = 5;
    char src1[15] = "qwert";
    char dst1[3] = "123";
    char src2[11];
    char dst2[11] = "1234567890";
    char src3[3];
    char dst3[3] = "123";
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
//   char *src, *src1, *src2;
//   src = ;
  ck_assert_str_eq(s21_strerror(2), strerror(2));
//   free(src);

//   src1 = ;
  ck_assert_str_eq(s21_strerror(70), strerror(70));
//   free(src1);

//   src2 = ;
  ck_assert_str_eq(s21_strerror(-1500), strerror(-1500));
//   free(src2);
}
END_TEST

int main(void) {
    Suite *s21 = suite_create("s21_string");
    TCase *case_test = tcase_create("test");
    SRunner *sr = srunner_create(s21);
    int num_failed = 0;

    suite_add_tcase(s21, case_test);
    // for(int i = sizeof(S21_FUNC[])/sizeof(S21_FUNC[0]); i > 0; i--) {
        tcase_add_test(case_test, s21_memcpy_test);
        tcase_add_test(case_test, s21_strlen_test);
        tcase_add_test(case_test, s21_strerror_test);
    // }
    
    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed != 0) ? 1 : 0;
}

