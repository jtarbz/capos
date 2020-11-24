#include <stddef.h>
#include <stdint.h>
#include "include/ufunc.h"
#include "include/func.h"
#include "include/util.h"
#include "include/terminal.h"
#include "include/mem.h"
#include "include/timer.h"
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

void umem_status(void)
{
	size_t free = mem_status();
	printf("%u out of %u bytes free\n", free, mem_total);

	return;
}

void mem_hops(void)
{
	struct free_hop *p = free_origin.fw;
	for (size_t i = 0; p != NULL; ++i) {
		printf("(hop %d) base: %x, size: %x, bk: %x, fw: %x\n", i, p, p->size, p->bk, p->fw);
		p = p->fw;
	}

	return;
}

/*
 * print_mem(address, length)
 * address must be in hex; length may be in hex (starting with '0x') or decimal
 */
void print_mem(int argc, char **args)
{
	uint8_t *p = (uint8_t *)hatoi(args[0]);
	size_t size;

	if (args[1][0] == '0' && (args[1][1] == 'x' || args[1][1] == 'X'))
		size = hatoi(args[1]);
	else
		size = atoi(args[1]);

	for (size_t i = 0; i < size; ++i) {
		if ((*(p + i) & 0xff) > 0xf)
			printf("%x ", *(p + i) & 0xff);
		else
			printf("0%x ", *(p + i) & 0xff);
	}

	t_putc('\n');
	return;
}

/*
 * mem_poke(address, value)
 * address in hex; value in either hex ('0x...') or decimal
 */
void mem_poke(int argc, char **args)
{
	uint8_t *p = (uint8_t *)hatoi(args[0]);
	uint8_t set;

	if (args[1][0] == '0' && (args[1][1] == 'x' || args[1][1] == 'X'))
		set = hatoi(args[1]);
	else
		set = atoi(args[1]);
	
	*p = set;
	return;
}

void udefrag(void)
{
	struct free_hop *p = free_origin.fw;
	uint32_t i = 0;

	while (p != NULL) {
		++i;
		p = p->fw;
	}

	defragment();

	p = free_origin.fw;
	while (p != NULL) {
		--i;
		p = p->fw;
	}

	printf("%d memory hops collapsed\n", i);
	return;
}

void echo(int argc, char **args)
{
	for (int i = 0; i < argc; ++i) {
		t_puts(args[i]);
		t_putc(' ');
	}
	
	t_putc('\n');
	return;
}

void time(int argc, char **args)
{
	void *func;
	uint32_t ms;
	if (argc < 1) {
		t_puts("Usage: time [program] [args]\n");
		t_puts("NOTE: time() currently only works with standard argument form, using spaces\n");
		return;
	}

	if ((func = func_seek(args[0])) == NULL) {
		printf("Unknown routine invoked in time: %s\n", args[0]);
		return;
	}

	++args;
	ms = get_time();
	fexec(func, argc - 1, args);
	printf("Milliseconds elapsed: %d\n", get_time() - ms);
	return;
}
