#ifndef UTIL_H
#define UTIL_H

#include <stdarg.h>
#include <stddef.h>

void *memset(void *mem, int c, size_t n);
size_t strlen(const char *);
size_t strcmp(char *, char *);
int *add(void *);
int *mul(void *);

#endif
