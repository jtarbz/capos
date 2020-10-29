#include <stddef.h>
#include "include/func.h"
#include "include/ufunc.h"
#include "include/terminal.h"

struct func func_key[] = {
	{"clear", t_clear},
	{"add", add},
	{"mul", mul},
	{"help", help},
	{"sans_undertale", sans_undertale},	// in music.c
	{"happy_birthday", happy_birthday},	// in music.c
	{"mem_status", umem_status},
	{"echo", echo},
	{"time", time},
	{"", NULL}
};
