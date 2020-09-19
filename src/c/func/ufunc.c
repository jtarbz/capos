#include <stddef.h>
#include "include/ufunc.h"
#include "include/util.h"
#include "include/printf.h"

void add(int argc, char **args)
{
	int sum = 0;

	for (size_t i = 0; i < argc; ++i)
		sum += atoi(args[i]);
	
	printf("sum: %d\n", sum);
	return;
}

void mul(int argc, char **args)
{
	int product = 1;

	for (size_t i = 0; i < argc; ++i)
		product *= atoi(args[i]);

	printf("product: %d\n", product);
	return;
}

void help(void)
{
	printf("This is the help page for Jason Walter's Capstone OS\n");
	printf("--------\n");
	printf("[Help text goes here]\n");

	return;
}
