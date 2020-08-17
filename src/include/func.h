#ifndef FUNC_H
#define FUNC_H

#include <stdint.h>
#include <stdarg.h>

#define TBUF_SIZE 80

struct func {
	char name[16];
	void *addr;
};

uint64_t func_seek(char *);
void *fexec(void *, void *);

extern struct func func_key[];

#endif
