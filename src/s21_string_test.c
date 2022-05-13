#include "s21_string.h"
#include "s21_string_test.h"

START_TEST(s21_sprintf_test) {

}
END_TEST

START_TEST(s21_insert_test) {
  char dest[] = "Hello\0";
  char insert[] = "Man\0";
  char *test01 = s21_insert(dest, insert, 2);
  ck_assert_str_eq(test01, "HeManllo\0");
  free(test01);
  char dest2[] = "Hello\n\0";
  char insert2[] = "Man\n\0";
  char *test02 = s21_insert(dest2, insert2, 1);
  ck_assert_str_eq(test02, "HMan\nello\n\0");
  free(test02);
  char dest3[] = "a\0";
  char insert3[] = "man\0";
  char *test03 = s21_insert(dest3, insert3, 1);
  ck_assert_str_eq(test03, "aman");
  free(test03);
  char dest4[] = " s\0";
  char insert4[] = " s\0";
  char *test04 = s21_insert(dest4, insert4, 1);
  ck_assert_str_eq(test04, "  ss");
  free(test04);
  char dest5[100] = "\n\0";
  char insert5[100] = "\n\0";
  char *test05 = s21_insert(dest5, insert5, 1);
  ck_assert_str_eq(test05, "\n\n");
  free(test05);
  char dest6[] = " \0";
  char insert6[] = " \0";
  char *test06 = s21_insert(dest6, insert6, 1);
  ck_assert_str_eq(test06, "  ");
  free(test06);
  char dest7[] = "\0";
  char insert7[] = "\0";
  char *test07 = s21_insert(dest7, insert7, 1);
  ck_assert_ptr_eq(test07, s21_NULL);

}
END_TEST

START_TEST(s21_trim_test) {
  char src2[50] = "llo Wollorld&lol\0";
  char trim_chars2[10] = "llo\0";
  char res[50] = " Wollorld&\0";
  void *out2;
  out2 = s21_trim(src2, trim_chars2);
  ck_assert_str_eq(out2, res);
}
END_TEST

START_TEST(s21_to_upper_test) {
  char *str_u = "aZi13E1";
  char *out4 = "AZI13E1";
  ck_assert_str_eq(s21_to_upper(str_u), out4);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *str_l = "AZI13E1";
  char *out6 = "azi13e1";
  ck_assert_str_eq(s21_to_lower(str_l), out6);
}
END_TEST

START_TEST(s21_strrchr_test) {
  ck_assert_str_eq(s21_strrchr(s1, 'l'), strrchr(s1, 'l'));
  ck_assert_pstr_eq(s21_strrchr(s8, 'n'), strrchr(s8, 'n'));
  ck_assert_pstr_eq(s21_strrchr(s3, '0'), strrchr(s3, '0'));
  ck_assert_pstr_eq(s21_strrchr(s4, 'n'), strrchr(s4, 'n'));
  ck_assert_pstr_eq(s21_strrchr(s7, '0'), strrchr(s7, '0'));
}
END_TEST

START_TEST(s21_strncpy_test) {
  ck_assert_str_eq(s21_strncpy(s1, s9, 2), strncpy(s1, s9, 2));
  ck_assert_str_eq(s21_strncpy(s9, s2, 1), strncpy(s9, s2, 1));
  ck_assert_str_eq(s21_strncpy(s3, s4, 6), strncpy(s3, s4, 6));
  ck_assert_str_eq(s21_strncpy(s4, s5, 3), strncpy(s4, s5, 3));
  ck_assert_str_eq(s21_strncpy(s6, s7, 3), strncpy(s6, s7, 3));
  ck_assert_str_eq(s21_strncpy(s7, s1, 3), strncpy(s7, s1, 3));
}
END_TEST

START_TEST(s21_strcspn_test) {
  ck_assert_int_eq(s21_strcspn(s1, s9), strcspn(s1, s9));
  ck_assert_int_eq(s21_strcspn(s9, s2), strcspn(s9, s2));
  ck_assert_int_eq(s21_strcspn(s3, s4), strcspn(s3, s4));
  ck_assert_int_eq(s21_strcspn(s4, s5), strcspn(s4, s5));
  ck_assert_int_eq(s21_strcspn(s6, s7), strcspn(s6, s7));
  ck_assert_int_eq(s21_strcspn(s7, s1), strcspn(s7, s1));
}
END_TEST

START_TEST(s21_strcpy_test) {
  ck_assert_str_eq(s21_strcpy(s1, s9), strcpy(s1, s9));
  ck_assert_str_eq(s21_strcpy(s9, s2), strcpy(s9, s2));
  ck_assert_str_eq(s21_strcpy(s3, s4), strcpy(s3, s4));
  ck_assert_str_eq(s21_strcpy(s4, s5), strcpy(s4, s5));
  ck_assert_str_eq(s21_strcpy(s6, s7), strcpy(s6, s7));
  ck_assert_str_eq(s21_strcpy(s7, s1), strcpy(s7, s1));
}
END_TEST

START_TEST(s21_memset_test) {
  ck_assert_pstr_eq(s21_memset(s1, 'o', 5), memset(s1, 'o', 5));
  ck_assert_pstr_eq(s21_memset(s2, 'o', 5), memset(s2, 'o', 5));
  ck_assert_pstr_eq(s21_memset(s3, 'o', 1), memset(s3, 'o', 1));
  ck_assert_pstr_eq(s21_memset(s4, '0', 1), memset(s4, '0', 1));
  ck_assert_pstr_eq(s21_memset(s5, 'n', 1), memset(s5, 'n', 1));
  ck_assert_pstr_eq(s21_memset(s6, '\n', 1), memset(s6, '\n', 1));
  ck_assert_pstr_eq(s21_memset(s7, '\0', 1), memset(s7, '\0', 1));
}
END_TEST

START_TEST(s21_memcpy_test) {
  ck_assert_pstr_eq(s21_memcpy(s1, s2, 5), memcpy(s1, s2, 5));
  ck_assert_pstr_eq(s21_memcpy(s2, s3, 5), memcpy(s2, s3, 5));
  ck_assert_pstr_eq(s21_memcpy(s3, s4, 1), memcpy(s3, s4, 1));
  ck_assert_pstr_eq(s21_memcpy(s4, s5, 1), memcpy(s4, s5, 1));
  ck_assert_pstr_eq(s21_memcpy(s5, s6, 1), memcpy(s5, s6, 1));
  ck_assert_pstr_eq(s21_memcpy(s6, s7, 1), memcpy(s6, s7, 1));
  ck_assert_pstr_eq(s21_memcpy(s7, s1, 1), memcpy(s7, s1, 1));
}
END_TEST

START_TEST(s21_strlen_test) {
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

START_TEST(s21_strerror_test) {
  for (int n = 0; n <= 140; n++) {
    char *out1 = s21_strerror(n);
    char *out2 = strerror(n);
    ck_assert_str_eq(out1, out2);
  }
}
END_TEST

START_TEST(s21_memchr_test) {
  ck_assert_pstr_eq(s21_memchr(s1, 5, 5), memchr(s1, 5, 5));
  ck_assert_pstr_eq(s21_memchr(s2, 5, 2), memchr(s2, 5, 2));
  ck_assert_pstr_eq(s21_memchr(s3, 1, 1), memchr(s3, 1, 1));
  ck_assert_pstr_eq(s21_memchr(s4, 1, 1), memchr(s4, 1, 1));
  ck_assert_pstr_eq(s21_memchr(s5, 2, 2), memchr(s5, 2, 2));
  ck_assert_pstr_eq(s21_memchr(s6, 1, 1), memchr(s6, 1, 1));
  ck_assert_pstr_eq(s21_memchr(s7, '\0', 1), memchr(s7, '\0', 1));
}
END_TEST

START_TEST(s21_memcmp_test) {
  ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
  ck_assert_int_ne(s21_memcmp(s2, s3, 5), 0);
  ck_assert_int_ne(memcmp(s2, s3, 5), 0);
  ck_assert_int_eq(s21_memcmp(s3, s4, 1), memcmp(s3, s4, 1));
  ck_assert_int_eq(s21_memcmp(s4, s5, 1), memcmp(s4, s5, 1));
  ck_assert_int_eq(s21_memcmp(s5, s6, 1), memcmp(s5, s6, 1));
  ck_assert_int_eq(s21_memcmp(s6, s7, 1), memcmp(s6, s7, 1));
  ck_assert_int_eq(s21_memcmp(s7, s1, 1), memcmp(s7, s1, 1));
}
END_TEST

START_TEST(s21_memmove_test) {
  ck_assert_str_eq(s21_memmove(s1, s2, 3), memmove(s1, s2, 3));
  ck_assert_str_eq(s21_memmove(&s1[4], &s1[3], 3), memmove(&s1[4], &s1[3], 3));
  ck_assert_str_eq(s21_memmove(&s1[3], &s1[4], 3), memmove(&s1[3], &s1[4], 3));
  ck_assert_str_eq(s21_memmove(s2, s3, 1), memmove(s2, s3, 1));
  ck_assert_str_eq(s21_memmove(s4, s5, 1), memmove(s4, s5, 1));
  ck_assert_str_eq(s21_memmove(s6, s7, 1), memmove(s6, s7, 1));
}
END_TEST

START_TEST(s21_strncat_test) {
  ck_assert_str_eq(s21_strncat(s1, s9, 2), strncat(s1, s9, 2));
  ck_assert_str_eq(s21_strncat(s9, s2, 1), strncat(s9, s2, 1));
  ck_assert_str_eq(s21_strncat(s3, s4, 6), strncat(s3, s4, 6));
  ck_assert_str_eq(s21_strncat(s4, s5, 1), strncat(s4, s5, 1));
  ck_assert_str_eq(s21_strncat(s6, s7, 1), strncat(s6, s7, 1));
  ck_assert_str_eq(s21_strncat(s7, s1, 1), strncat(s7, s1, 1));
}
END_TEST

START_TEST(s21_strcmp_test) {
  ck_assert_int_ne(s21_strcmp(s1, s9), 0);
  ck_assert_int_ne(strcmp(s1, s9), 0);
  ck_assert_int_ne(s21_strcmp(s2, s9), 0);
  ck_assert_int_ne(strcmp(s2, s9), 0);
  ck_assert_int_ne(s21_strcmp(s3, s9), 0);
  ck_assert_int_ne(strcmp(s3, s9), 0);
  ck_assert_int_ne(s21_strcmp(s4, s9), 0);
  ck_assert_int_ne(strcmp(s4, s9), 0);
  ck_assert_int_ne(s21_strcmp(s5, s9), 0);
  ck_assert_int_ne(strcmp(s5, s9), 0);
  ck_assert_int_ne(s21_strcmp(s6, s9), 0);
  ck_assert_int_ne(strcmp(s6, s9), 0);
  ck_assert_int_ne(s21_strcmp(s7, s9), 0);
  ck_assert_int_ne(strcmp(s7, s9), 0);
}
END_TEST

START_TEST(s21_strncmp_test) {
  ck_assert_int_ne(s21_strncmp(s1, s9, 3), 0);
  ck_assert_int_ne(strncmp(s1, s9, 3), 0);
  ck_assert_int_ne(s21_strncmp(s2, s9, 2), 0);
  ck_assert_int_ne(strncmp(s2, s9, 2), 0);
  ck_assert_int_ne(s21_strncmp(s3, s9, 2), 0);
  ck_assert_int_ne(strncmp(s3, s9, 2), 0);
  ck_assert_int_ne(s21_strncmp(s4, s9, 8), 0);
  ck_assert_int_ne(strncmp(s4, s9, 8), 0);
  ck_assert_int_ne(s21_strncmp(s5, s9, 8), 0);
  ck_assert_int_ne(strncmp(s5, s9, 8), 0);
  ck_assert_int_ne(s21_strncmp(s6, s9, 1), 0);
  ck_assert_int_ne(strncmp(s6, s9, 1), 0);
  ck_assert_int_ne(s21_strncmp(s7, s9, 1), 0);
  ck_assert_int_ne(strncmp(s7, s9, 1), 0);
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

START_TEST(s21_strchr_test) {
  ck_assert_str_eq(s21_strchr(s1, 'o'), strchr(s1, 'o'));
  ck_assert_pstr_eq(s21_strchr(s2, 'o'), strchr(s2, 'o'));
  ck_assert_pstr_eq(s21_strchr(s3, 'a'), strchr(s3, 'a'));
  ck_assert_pstr_eq(s21_strchr(s4, 'n'), strchr(s4, 'n'));
  ck_assert_pstr_eq(s21_strchr(s5, ' '), strchr(s5, ' '));
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
  char dest[] = "Hell0 world\0";
  char orig[] = "Hell0 world\0";
  ck_assert_str_eq(s21_strtok(dest, " "), strtok(orig, " "));
  char dest2[] = "Hell0 world\n\0";
  char orig2[] = "Hell0 world\n\0";
  ck_assert_str_eq(s21_strtok(dest2, " "), strtok(orig2, " "));
  char dest3[] = "a\n\0";
  char orig3[] = "a\n\0";
  ck_assert_str_eq(s21_strtok(dest3, " "), strtok(orig3, " "));
  char dest4[] = " s\0";
  char orig4[] = " s\0";
  ck_assert_str_eq(s21_strtok(dest4, " "), strtok(orig4, " "));
  char dest5[] = " \0";
  char orig5[] = " \0";
  ck_assert_ptr_eq(s21_strtok(dest5, " "), strtok(orig5, " "));
  char dest6[] = "\n\0";
  char orig6[] = "\n\0";
  ck_assert_str_eq(s21_strtok(dest6, " "), strtok(orig6, " "));
  char dest7[] = "\0";
  char orig7[] = "\0";
  ck_assert_ptr_eq(s21_strtok(dest7, " "), strtok(orig7, " "));
  char dest8[] = "test1/test2/test3/test4";
  char orig8[] = "test1/test2/test3/test4";
  ck_assert_str_eq(s21_strtok(dest8, "/"), strtok(orig8, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  char dest9[] = "test1/test2/test3///";
  char orig9[] = "test1/test2/test3///";
  ck_assert_str_eq(s21_strtok(dest9, "/"), strtok(orig9, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  char dest10[] = "///test1///test2/test3/";
  char orig10[] = "///test1///test2/test3/";
  ck_assert_str_eq(s21_strtok(dest10, "/"), strtok(orig10, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
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
