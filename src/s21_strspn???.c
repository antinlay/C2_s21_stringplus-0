#include <stdio.h>
#include <string.h>


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

int main() {
    
    char str1[20] = "hello";
    char str2[20] = "oleh";
    size_t len;
    len = strspn(str1, str2);
    printf("character of str1 and str2 differs @ %ld", len);
    
    return 0;
}
