#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_

char s1[40] = "Hello world\0";
char s2[40] = "Hello world\n\0";
char cs2[40] = "Hello world\n\0";
char s3[15] = "a\n\0";
char cs3[15] = "a\n\0";
char s4[15] = " \n\0";
char cs4[15] = " \n\0";
char s5[15] = " \0";
char cs5[15] = " \0";
char s6[15] = "\n\0";
char cs6[15] = "\n\0";
char s7[15] = "\0";
char cs7[15] = "\0";
char s8[40] = "Hello world\0";
char s9[15] = "wo";
char s10[15] = "";
char s11[15] = " ";
char s12[15] = "  ";
char s13[40] = " test1/test2/test3/test4";
char s14[15] = "/\0";
char s15[15] = "/0000/12345";
char s16[15] = "/0000/12345";
char s17[40] = "Hello world\0";
char *s18 = s21_NULL;

#endif  // SRC_S21_STRING_TEST_H_
