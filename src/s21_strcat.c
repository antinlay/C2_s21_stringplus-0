#include <stdio.h>
// #include <string.h>
#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    char* begin = dest;
    while (*dest)
        dest++;
 
    while(*src)
        {
            *dest = *src;
            dest++;
            src++;
        }
    *dest = '\0';
    return begin;
}

// int main() {
    
//     char str[100]= "hello everybody";
//     char str2[]= " clap your hands";
//     printf(strcat(str, str2));
    
//     return 0;
// }
