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

	for (int i = 0; i < argc; ++i)
		sum += atoi(args[i]);
	
	printf("sum: %d\n", sum);
	return;
}

void mul(int argc, char **args)
{
	int product = 1;

	for (int i = 0; i < argc; ++i)
		product *= atoi(args[i]);

	printf("product: %d\n", product);
	return;
}

void help(void)
{
	printf("This is the help page for Jason Walter's Capstone OS\n");
	printf("--------\n");
	printf("The Capstone operating system is a work in progress. Its design\n"
	"is meant to highlight the user benefits of eschewing kernel level\n"
	"security concerns, such as a greater capacity for personal computing.\n"
	"Run ufuncs() for a list of available user functions!\n");

	return;
}

void ufuncs(void)
{
	for (size_t i = 0; func_key[i].addr != NULL; ++i)
		printf("%s(), %x\n", func_key[i].name, func_key[i].addr);

	return;
}

/*
 * print the amount of free memory out of the amount of total memory.
 * referenced in the function key as "mem_status"
 */
void umem_status(void)
{
	size_t free = mem_status();
	printf("%u out of %u bytes free\n", free, mem_total);

	return;
}

/*
 * print all free memory hops in the order that they appear in the free list.
 * free memory hops are the headers of available memory regions that are
 * not currently in use, maintained as a linked list (see mem.c)
 */
void mem_hops(void)
{
	struct free_hop *p = free_origin.fw;
	for (size_t i = 0; p != NULL; ++i) {
		printf("(hop %d) base: %x, size: %x, fw: %x\n", i, p, p->size, p->fw);
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

/*
 * ufunc wrapper for the defragment() function in mem.c.
 * defragments free memory hops and then reports the number of regions collapsed
 */
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

/*
 * given a ufunc invocation, report the timei n ms that it takes to execute
 */
void time(int argc, char **args)
{
	void *func;
	uint32_t ms;
	if (argc < 1) {
		t_puts("Usage: time [program] [args]\n");
		t_puts("NOTE: time() currently only works with standard"
		"argument form, using spaces\n");
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
