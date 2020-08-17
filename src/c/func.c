#include <stdint.h>
#include <stddef.h>
#include "include/func.h"
#include "include/util.h"
#include "include/printf.h"

char terminal_buffer[TBUF_SIZE];

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
 * final element in the array is set to NULL by wrapper
 * type is defined on-the-fly by the called function
 * string / array support? i'll worry about that later
 * multiple type support? i'll worry about that later
 * this will work for now, at least to get user interaction up and running
 */
void *fexec(void *func, void *args)
{
	void *(*pfunc)(void *) = func;

	return pfunc(args);
}

void terminal(void)
{
	char *buf = terminal_buffer;
	void *func;

	terminal_buffer[TBUF_SIZE - 1] = '\0';

	while (*buf != '(' && *buf != '\0' && *buf != ' ')
		buf++;
	
	*buf = '\0';

	if ((func = func_seek(terminal_buffer)) == NULL) {
		printf("Unknown routine invoked: %s\n", terminal_buffer);
		return;
	}
	
	fexec(func, NULL);

	return;
}
