#include <stddef.h>
#include "include/func.h"
#include "include/util.h"

struct func func_key[] = {
	{"add", add},
	{"mul", mul},
	{"help", help},
	{"", NULL}
};
