#include <stdint.h>
#include "include/func.h"
#include "include/util.h"
#include "include/printf.h"

void *memset(void *mem, int c, size_t n)
{
	while (n--)
		((char *) mem)[n] = c;

	return mem;
}

size_t strlen(const char *str)
{
	size_t len = 0;
	while (str[len] != '\0')
		++len;
	
	return len;
}

/*
 * it's strcmp. for this implementation i am most interested in if the two
 * strings are the same, and so i worry less about being accurate with the
 * actual diff between the two
 */
size_t strcmp(char *str1, char *str2)
{
	size_t diff = 0;
	size_t i = 0;

	while (str1[i] != '\0') {
		if (str1[i] != str2[i])
			++diff;

		++i;
	}

	return diff;
}

/*
 * standard atoi implementation; it should be easy enough to see how it works
 * referenced from this stackoverflow discussion:
 * https://stackoverflow.com/questions/12791077/atoi-implementation-in-c
 * does not work for negative numbers
 */
int atoi(char *p)
{
	int k = 0;
	while (*p) {
		k = (k * 10) + (*p - '0');
		++p; 
	}

	return k;
}

int *add(void *args)
{
	int *fargs = args;
	int sum = 0;

	for (size_t i = 0; fargs[i]; ++i)
		sum += fargs[i];
	
	return &sum;
}

int *mul(void *args)
{
	int *fargs = args;
	int product = 1;

	for (size_t i = 0; fargs[i]; ++i)
		product *= fargs[i];

	return &product;
}

void help(void)
{
	printf("This is the help page for Jason Walter's Capstone OS\n");
	printf("--------\n");
	printf("[Help text goes here]\n");

	return;
}
