#include "s21_string.h"
#define UPREFIX "Unknown error: "

static char ebuf[40] = UPREFIX;

char *s21_strerror(int errnum) {
    char *resnum[] = S21_ERRLIST;
    int n = sizeof(resnum)/sizeof(resnum[0]);
    char *res[40];
    if (errnum < 0 || errnum > n) res[40] = ebuf;
    else
        res[40] = resnum[errnum];
    return res[40];
}
