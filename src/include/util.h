#ifndef UTIL_H
#define UTIL_H

#include <stdarg.h>
#include <stddef.h>

void *memset(void *mem, int c, size_t n);
size_t strlen(const char *str);
size_t strcmp(char *str1, char *str2);
int atoi(char *p);
void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);
int *add(void *);
int *mul(void *);
void help(void);

#endif
