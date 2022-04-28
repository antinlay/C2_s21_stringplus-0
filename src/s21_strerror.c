#include <string.h>
#include <errno.h>
#include "s21_string.h"

#define	UPREFIX	"Unknown error: "

int main(void) {
    FILE *fp=0;     // Определяем переменную указателя файла fp
    // Открываем файл /tmp/book1.c как доступный только для чтения
    if ( (fp=fopen("/tmp/book1.c","r")) == 0 )
    {
        printf("Не удалось открыть файл /tmp/book1.c (%d:%s). \n", errno, s21_strerror(errno)); 
    }
    
    // закрываем файл
    if ( fp!=0 ) fclose(fp);
    return 0;
}

static char ebuf[40] = UPREFIX;

char *s21_strerror(int errnum) {
    extern const int sys_nerr;
	extern const char *const sys_errlist[

		
	];
	register char *p, *t;
	char tmp[40];
	int res = 0;

	if (errnum < sys_nerr) res = 1;

	/* Do this by hand, so we don't include stdio(3). */
	t = tmp;
	do {
		*t++ = "0123456789"[errnum % 10];
	} while (errnum /= 10);
	for (p = ebuf + sizeof(UPREFIX) - 1;;) {
		*p++ = *--t;
		if (t <= tmp)
			break;
	}
	return(res = 0) ? (ebuf) : ((char*)sys_errlist[errnum]);
}