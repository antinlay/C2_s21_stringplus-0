#include "s21_string.h"

char *s21_strerror(int errnum) {
  char *resnum[] = S21_ERRLIST;
  char ebuf[100] = UNK_ERR;
  int n = sizeof(resnum) / sizeof(resnum[0]);
  static char res[100] = "";
  char buf[100] = "\0";
  if (errnum >= 0 && errnum < n) {
    s21_memmove(res, resnum[errnum], 100);
  } else {
    s21_itoa(errnum, 10, buf);
    s21_strcat(ebuf, buf);
    s21_memmove(res, ebuf, 100);
  }
  return res;
}