#include "s21_string.h"
#define UNK_ERR "Unknown error: "

char *s21_strerror(int errnum) {
    char *resnum[] = S21_ERRLIST;
    static char ebuf[40] = UNK_ERR;
    int n = sizeof(resnum) / sizeof(resnum[0]);
    char *res = s21_NULL;
    char tmp[100] = "\0";
    if (errnum < 0 || errnum > n) {
        s21_itoa(errnum, tmp);
        res = s21_strcat(ebuf, tmp);
    } else
        res = resnum[errnum];
    return res;
}

// int main(void) {
//     for (int k = -5; k < 5; k++) {
//         printf("%s\n", s21_strerror(k));
//     }
    
//     return 0;
// }