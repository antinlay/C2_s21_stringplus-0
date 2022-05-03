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