#include "common.h"
#include <assert.h>
#include <errno.h>

#include <sys/stat.h>

#include "syscall.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

FwriteHandler __g_fwrite_handler = NULL;

void __attribute__((__used__)) _exit(int status)
{
	while (1)
	{}
}

int __attribute__((__used__)) _open(const char *name, int flags, int mode)
{
	return -1;
}

int __attribute__((__used__)) _fstat(int file, struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int __attribute__((__used__)) _isatty(int file)
{
	return 1;
}

int __attribute__((__used__)) _lseek(int file, int ptr, int dir)
{
	return 0;
}

int __attribute__((__used__)) _read(int file, char *ptr, int len)
{
	return 0;
}

int __attribute__((__used__)) _write(int file, char *ptr, int len)
{
	// This function won't fail even if __g_fwrite_handler is not set, it will
	// simply ignore the string in such case
	return __g_fwrite_handler ? __g_fwrite_handler(file, ptr, len) : len;
}

int __attribute__((__used__)) _close(int file)
{
	return -1;
}

caddr_t __attribute__((__used__)) _sbrk(int incr)
{
	extern char _end;		/* Defined by the linker */
	extern uint32_t __stack_end;
	static char *heap_end;
	char *prev_heap_end;

	if (heap_end == 0)
	{
		heap_end = &_end;
	}
	prev_heap_end = heap_end;
	if ((uint32_t)(heap_end + incr) > __stack_end)
	{
		//write(1, "Heap and stack collision\n", 25);
		//abort();
		assert(1);
	}

	heap_end += incr;
	return (caddr_t)prev_heap_end;
}

int __attribute__((__used__)) _getpid(void)
{
	return 1;
}

#undef errno
int __attribute__((__used__)) _kill(int pid, int sig)
{
	extern int errno;
	errno = EINVAL;
	return -1;
}
