#include <stdint.h>
#include <stddef.h>
#include "include/func.h"
#include "include/util.h"

uint64_t func_seek(char *name)
{
	size_t i = 0;

	while (func_key[i].addr != NULL) {
		if (strcmp(name, func_key[i].name) == 0)
			break;
		
		++i;
	}

	return func_key[i].addr;
}

/*
 * here, args is an array of arguments
 * any ufunc called through this wrapper works like a terminal app
 * ie, takes ascii args and an argc
 */
void *fexec(void *func, int argc, char **args)
{
	void *(*pfunc)(int, char **) = func;

	return pfunc(argc, args);
}
