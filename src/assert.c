#include "mini_common.h"
#include "hw_common.h"
#include <stdio.h>

#include "assert.h"

__attribute__((__weak__))
void AssertHandler(const char *file, int line, const char *fn,
		const char *expression)
{
	while (1)
	{
		iprintf("Assertion(%s) failed in %s:%s at line %d\n", expression, file,
				fn, line);
		DELAY_MS(250);
	}
}
