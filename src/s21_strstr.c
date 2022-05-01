#include <stdio.h>
// #include <string.h>
#include "s21_string.h"


char *s21_strstr(const char *s, const char *find)
{
	char c, sc;
	s21_size_t len;
    int z = 0;

	if ((c = *find++) != '\0') {
		len = s21_strlen(find);
		do {
			do {
				if ((sc = *s++) == '\0')
                {
                    z = 1;
                    break; 
                }
			} while (sc != c);
                if(z == 1) break;
		} while (s21_strncmp(s, find, len) != 0);
		s--;
	}
	return (z == 1) ? s21_NULL : ((char *)s);
    
}

// int main() {
//     char str[100]= "hello everybody";
//     char str2[]= "eve";
//     printf(s21_strstr(str, str2));
//     return 0;
// }

// char *s21_strstr(const char *haystack, const char *needle) 
// {
// char* a, *b;
// b = needle;
// if (*b == 0) {
// return haystack;
// }
// for ( ; *haystack != 0; haystack += 1) {
// if (*haystack != *b) {
// continue;
// }
// a = haystack;
// while (1) {
//        if (*b == 0) {
//        return haystack;
//        }
//        if (*a++ != *b++) {
//        break;
//        }
// }
//        b = needle;
// }
//     return NULL;
// }



