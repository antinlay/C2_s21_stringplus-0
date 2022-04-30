#include <stdio.h>
#include <string.h>


char *s21_strchr(const char *str, int c) {
    char ct;
    ct = c;
    for (;; ++str) {
        if (*str == ct)
            return ((char *)str);
        if (*str == '\0')
            return (NULL);
    }
}

char * s21_strtok(char * str, const char * delim) {
    static char * next;
    
    if ( str ) {
        next = str;
        while ( *next && s21_strchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! s21_strchr(delim, *next) )
        ++next;
    while ( *next && s21_strchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}

int main() {
    
    char buf[BUFSIZ], *p;
        
        while ( printf("String: ") && fgets(buf, BUFSIZ, stdin) && *buf != '\n' && printf("By words:\n") )
            for ( p = s21_strtok(buf, " "); p; p = s21_strtok(NULL, " ") )
                printf("%s\n", p);
        
        return 0;
}
