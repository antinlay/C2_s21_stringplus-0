#include "s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
    int i, j, k = 0;
    size_t m = 0;
    for(i=0; str1[i]!= '\0'; i++) {
        for(j=0; str2[j]!='\0'; j++) {
            if(str1[i]==str2[j])
            {
                k++;
                break;
            } else k = 0;
        }
        if(k == 0) break;
        for(j=0; str2[j]!='\0'; j++)
        {
            if(str1[i]==str2[j]) {
                m++;
                break;
            }
        }
    }
    return m;
    }