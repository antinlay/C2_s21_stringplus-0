#include <stdio.h>
#include <string.h>


char* s21_strstr(char *haystack, char *needle) {
char* a, *b;
b = needle;
if (*b == 0) {
return haystack;
}
for ( ; *haystack != 0; haystack += 1) {
if (*haystack != *b) {
continue;
}
a = haystack;
while (1) {
       if (*b == 0) {
       return haystack;
       }
       if (*a++ != *b++) {
       break;
       }
}
       b = needle;
}
    return NULL;
}




int main() {
    
    char str[100]= "hello everybody";
    char str2[]= "eve";
    
    printf(s21_strstr(str, str2));
    
    return 0;
}
