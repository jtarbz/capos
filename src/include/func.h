#ifndef FUNC_H
#define FUNC_H

#include <stdint.h>
#include <stdarg.h>

struct func {
	char name[16];
	void *addr;
};

void *func_seek(char *);
void fexec(void *, int, char **);

extern struct func func_key[];

#endif
