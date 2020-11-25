#include <stdint.h>
#include <stddef.h>
#include "include/func.h"
#include "include/util.h"

/*
 * find the first user function in the function key that
 * matches the given string completely up to its length
 * this is "fuzzy" matching but allows for shortcuts if you know
 * the order of ufuncs
 */
void *func_seek(char *name)
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
void fexec(void *func, int argc, char **args)
{
	void (*pfunc)(int, char **) = func;

	pfunc(argc, args);
	return;
}
