#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "s21_string.h"

#define	UPREFIX	"Unknown error: "

int main(void) {
    FILE *fp=0;     // Определяем переменную указателя файла fp
    // Открываем файл /tmp/book1.c как доступный только для чтения
    if ( (fp=fopen("/tmp/book1.c","r")) == 0 )
    {
        printf("Не удалось открыть файл /tmp/book1.c (%d:%s). \n", errno, s21_strerror(errno)); 
		puts(s21_strerror(errno));
    }
    if ((fp = fopen("/tmp/book1.c","r")) == NULL) printf(" %s \n", strerror(errno));
    // закрываем файл
    if ( fp!=0 ) fclose(fp);
    return 0;
}

static char ebuf[40] = UPREFIX;

char *s21_strerror(int errnum) {
	const char *const drw_sys_errlist[] = {
		"Undefined error: 0",			/*  0 - ENOERROR */
		"Operation not permitted",		/*  1 - EPERM */
		"No such FUCK file or directory",		/*  2 - ENOENT */
		"No such process",			/*  3 - ESRCH */
		"Interrupted system call",		/*  4 - EINTR */
		"Input/output error",			/*  5 - EIO */
		"Device not configured",		/*  6 - ENXIO */
		"Argument list too long",		/*  7 - E2BIG */
		"Exec format error",			/*  8 - ENOEXEC */
		"Bad file descriptor",			/*  9 - EBADF */
		"No child processes",			/* 10 - ECHILD */
		"Resource deadlock avoided",		/* 11 - EDEADLK */
		"Cannot allocate memory",		/* 12 - ENOMEM */
		"Permission denied",			/* 13 - EACCES */
		"Bad address",				/* 14 - EFAULT */
		"Block device required",		/* 15 - ENOTBLK */
		"Resource busy",			/* 16 - EBUSY */
		"File exists",				/* 17 - EEXIST */
		"Cross-device link",			/* 18 - EXDEV */
		"Operation not supported by device",	/* 19 - ENODEV */
		"Not a directory",			/* 20 - ENOTDIR */
		"Is a directory",			/* 21 - EISDIR */
		"Invalid argument",			/* 22 - EINVAL */
		"Too many open files in system",	/* 23 - ENFILE */
		"Too many open files",			/* 24 - EMFILE */
		"Inappropriate ioctl for device",	/* 25 - ENOTTY */
		"Text file busy",			/* 26 - ETXTBSY */
		"File too large",			/* 27 - EFBIG */
		"No space left on device",		/* 28 - ENOSPC */
		"Illegal seek",				/* 29 - ESPIPE */
		"Read-only file system",		/* 30 - EROFS */
		"Too many links",			/* 31 - EMLINK */
		"Broken pipe",				/* 32 - EPIPE */

		/* math software */
		"Numerical argument out of domain",	/* 33 - EDOM */
		"Result too large",			/* 34 - ERANGE */

		/* non-blocking and interrupt i/o */
		"Resource temporarily unavailable",	/* 35 - EAGAIN */
							/* 35 - EWOULDBLOCK */
		"Operation now in progress",		/* 36 - EINPROGRESS */
		"Operation already in progress",	/* 37 - EALREADY */

		/* ipc/network software -- argument errors */
		"Socket operation on non-socket",	/* 38 - ENOTSOCK */
		"Destination address required",		/* 39 - EDESTADDRREQ */
		"Message too long",			/* 40 - EMSGSIZE */
		"Protocol wrong type for socket",	/* 41 - EPROTOTYPE */
		"Protocol not available",		/* 42 - ENOPROTOOPT */
		"Protocol not supported",		/* 43 - EPROTONOSUPPORT */
		"Socket type not supported",		/* 44 - ESOCKTNOSUPPORT */
		"Operation not supported",		/* 45 - ENOTSUP */
		"Protocol family not supported",	/* 46 - EPFNOSUPPORT */
							/* 47 - EAFNOSUPPORT */
		"Address family not supported by protocol family",
		"Address already in use",		/* 48 - EADDRINUSE */
		"Can't assign requested address",	/* 49 - EADDRNOTAVAIL */

		/* ipc/network software -- operational errors */
		"Network is down",			/* 50 - ENETDOWN */
		"Network is unreachable",		/* 51 - ENETUNREACH */
		"Network dropped connection on reset",	/* 52 - ENETRESET */
		"Software caused connection abort",	/* 53 - ECONNABORTED */
		"Connection reset by peer",		/* 54 - ECONNRESET */
		"No buffer space available",		/* 55 - ENOBUFS */
		"Socket is already connected",		/* 56 - EISCONN */
		"Socket is not connected",		/* 57 - ENOTCONN */
		"Can't send after socket shutdown",	/* 58 - ESHUTDOWN */
		"Too many references: can't splice",	/* 59 - ETOOMANYREFS */
		"Operation timed out",			/* 60 - ETIMEDOUT */
		"Connection refused",			/* 61 - ECONNREFUSED */

		"Too many levels of symbolic links",	/* 62 - ELOOP */
		"File name too long",			/* 63 - ENAMETOOLONG */

		/* should be rearranged */
		"Host is down",				/* 64 - EHOSTDOWN */
		"No route to host",			/* 65 - EHOSTUNREACH */
		"Directory not empty",			/* 66 - ENOTEMPTY */

		/* quotas & mush */
		"Too many processes",			/* 67 - EPROCLIM */
		"Too many users",			/* 68 - EUSERS */
		"Disc quota exceeded",			/* 69 - EDQUOT */

		/* Network File System */
		"Stale NFS file handle",		/* 70 - ESTALE */
		"Too many levels of remote in path",	/* 71 - EREMOTE */
		"RPC struct is bad",			/* 72 - EBADRPC */
		"RPC version wrong",			/* 73 - ERPCMISMATCH */
		"RPC prog. not avail",			/* 74 - EPROGUNAVAIL */
		"Program version wrong",		/* 75 - EPROGMISMATCH */
		"Bad procedure for program",		/* 76 - EPROCUNAVAIL */

		"No locks available",			/* 77 - ENOLCK */
		"Function not implemented",		/* 78 - ENOSYS */
		"Inappropriate file type or format",	/* 79 - EFTYPE */
		"Authentication error",			/* 80 - EAUTH */
		"Need authenticator",			/* 81 - ENEEDAUTH */

		"Device power is off",			/* 82 - EPWROFF */
		"Device error",                         /* 83 - EDEVERR */
		"Value too large to be stored in data type",	/* 84 - EOVERFLOW */

		/* program loading errors */
		"Bad executable (or shared library)",   /* 85 - EBADEXEC */
		"Bad CPU type in executable",		/* 86 - EBADARCH */
		"Shared library version mismatch",	/* 87 - ESHLIBVERS */
		"Malformed Mach-o file",		/* 88 - EBADMACHO */
		"Operation canceled",			/* 89 - ECANCELED */
		"Identifier removed",			/* 90 - EIDRM */
		"No message of desired type",		/* 91 - ENOMSG */
		"Illegal byte sequence",		/* 92 - EILSEQ */
		"Attribute not found",			/* 93 - ENOATTR */
		"Bad message",				/* 94 - EBADMSG */
		"EMULTIHOP (Reserved)",			/* 95 - EMULTIHOP */
		"No message available on STREAM",	/* 96 - ENODATA */
		"ENOLINK (Reserved)",			/* 97 - ENOLINK */
		"No STREAM resources",			/* 98 - ENOSR */
		"Not a STREAM",				/* 99 - ENOSTR */
		"Protocol error",			/* 100 - EPROTO */
		"STREAM ioctl timeout",			/* 101 - ETIME */
		"Operation not supported on socket",	/* 102 - EOPNOTSUPP */
		"Policy not found",			/* 103 - ENOPOLICY */
		"State not recoverable",		/* 104 - ENOTRECOVERABLE */
		"Previous owner died",			/* 105 - EOWNERDEAD */

		"Interface output queue is full",	/* 106 - EQFULL */
	};
	const char *const lnx_sys_errlist[] = {
	#define	EPERM		1		" Operation not permitted "
#define	ENOENT		2		" No such file or directory "
#define	ESRCH		3		" No such process "
#define	EINTR		4		" Interrupted system call "
#define	EIO		5		" Input/output error "
#define	ENXIO		6		" Device not configured "
#define	E2BIG		7		" Argument list too long "
#define	ENOEXEC		8		" Exec format error "
#define	EBADF		9		" Bad file descriptor "
#define	ECHILD		10		" No child processes "
#define	EDEADLK		11		" Resource deadlock avoided "
					" 11 was EAGAIN "
#define	ENOMEM		12		" Cannot allocate memory "
#define	EACCES		13		" Permission denied "
#define	EFAULT		14		" Bad address "
#ifndef _POSIX_SOURCE
#define	ENOTBLK		15		" Block device required "
#endif
#define	EBUSY		16		" Device busy "
#define	EEXIST		17		" File exists "
#define	EXDEV		18		" Cross-device link "
#define	ENODEV		19		" Operation not supported by device "
#define	ENOTDIR		20		" Not a directory "
#define	EISDIR		21		" Is a directory "
#define	EINVAL		22		" Invalid argument "
#define	ENFILE		23		" Too many open files in system "
#define	EMFILE		24		" Too many open files "
#define	ENOTTY		25		" Inappropriate ioctl for device "
#ifndef _POSIX_SOURCE
#define	ETXTBSY		26		" Text file busy "
#endif
#define	EFBIG		27		" File too large "
#define	ENOSPC		28		" No space left on device "
#define	ESPIPE		29		" Illegal seek "
#define	EROFS		30		" Read-only file system "
#define	EMLINK		31		" Too many links "
#define	EPIPE		32		" Broken pipe "

" math software "
#define	EDOM		33		" Numerical argument out of domain "
#define	ERANGE		34		" Result too large "

" non-blocking and interrupt i/o "
#define	EAGAIN		35		" Resource temporarily unavailable "
#ifndef _POSIX_SOURCE
#define	EWOULDBLOCK	EAGAIN		" Operation would block "
#define	EINPROGRESS	36		" Operation now in progress "
#define	EALREADY	37		" Operation already in progress "

" ipc/network software -- argument errors "
#define	ENOTSOCK	38		" Socket operation on non-socket "
#define	EDESTADDRREQ	39		" Destination address required "
#define	EMSGSIZE	40		" Message too long "
#define	EPROTOTYPE	41		" Protocol wrong type for socket "
#define	ENOPROTOOPT	42		" Protocol not available "
#define	EPROTONOSUPPORT	43		" Protocol not supported "
#define	ESOCKTNOSUPPORT	44		" Socket type not supported "
#endif " ! _POSIX_SOURCE "
#define ENOTSUP	45		" Operation not supported "
#ifndef _POSIX_SOURCE
#define	EOPNOTSUPP	 ENOTSUP		" Operation not supported "
#define	EPFNOSUPPORT	46		" Protocol family not supported "
#define	EAFNOSUPPORT	47		" Address family not supported by protocol family "
#define	EADDRINUSE	48		" Address already in use "
#define	EADDRNOTAVAIL	49		" Can't assign requested address "

/* ipc/network software -- operational errors */
#define	ENETDOWN	50		" Network is down "
#define	ENETUNREACH	51		" Network is unreachable "
#define	ENETRESET	52		" Network dropped connection on reset "
#define	ECONNABORTED	53		" Software caused connection abort "
#define	ECONNRESET	54		" Connection reset by peer "
#define	ENOBUFS		55		" No buffer space available "
#define	EISCONN		56		" Socket is already connected "
#define	ENOTCONN	57		" Socket is not connected "
#define	ESHUTDOWN	58		" Can't send after socket shutdown "
#define	ETOOMANYREFS	59		" Too many references: can't splice "
#define	ETIMEDOUT	60		" Operation timed out "
#define	ECONNREFUSED	61		" Connection refused "

#define	ELOOP		62		" Too many levels of symbolic links "
#endif /* _POSIX_SOURCE */
#define	ENAMETOOLONG	63		" File name too long "

/* should be rearranged */
#ifndef _POSIX_SOURCE
#define	EHOSTDOWN	64		" Host is down "
#define	EHOSTUNREACH	65		" No route to host "
#endif /* _POSIX_SOURCE */
#define	ENOTEMPTY	66		" Directory not empty "

/* quotas & mush */
#ifndef _POSIX_SOURCE
#define	EPROCLIM	67		" Too many processes "
#define	EUSERS		68		" Too many users "
#define	EDQUOT		69		" Disc quota exceeded "

/* Network File System */
#define	ESTALE		70		" Stale NFS file handle "
#define	EREMOTE		71		" Too many levels of remote in path "
#define	EBADRPC		72		" RPC struct is bad "
#define	ERPCMISMATCH	73		" RPC version wrong "
#define	EPROGUNAVAIL	74		" RPC prog. not avail "
#define	EPROGMISMATCH	75		" Program version wrong "
#define	EPROCUNAVAIL	76		" Bad procedure for program "
#endif /* _POSIX_SOURCE */

#define	ENOLCK		77		" No locks available "
#define	ENOSYS		78		" Function not implemented "

#ifndef _POSIX_SOURCE
#define	EFTYPE		79		" Inappropriate file type or format "
#define	EAUTH		80		" Authentication error "
#define	ENEEDAUTH	81		" Need authenticator "
#endif /* _POSIX_SOURCE */

/* Intelligent device errors */
#define	EPWROFF		82	" Device power is off "
#define	EDEVERR		83	" Device error, e.g. paper out "

#ifndef _POSIX_SOURCE
#define	EOVERFLOW	84		" Value too large to be stored in data type "

/* Program loading errors */
#define EBADEXEC	85	" Bad executable "
#define EBADARCH	86	" Bad CPU type in executable "
#define ESHLIBVERS	87	" Shared library version mismatch "
#define EBADMACHO	88	" Malformed Macho file "

#define	ELAST		88		" Must be equal largest errno "
#endif /* _POSIX_SOURCE */

#ifdef KERNEL
/* pseudo-errors returned inside kernel to modify return to process */
#define	ERESTART	-1		" restart syscall "
#define	EJUSTRETURN	-2		" don't modify regs, just return " };
	const int sys_nerr = sizeof(sys_errlist) / sizeof(sys_errlist[0]);
	register char *p, *t;
	char tmp[40];
	int res = 0;

	if (errnum < sys_nerr) {
		res = 1;
	} else {
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
	}
	return(res = 1) ? ((char*)sys_errlist[errnum]) : (ebuf);
}