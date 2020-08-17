#include <stddef.h>
#include <stdint.h>
#include "include/printf.h"
#include "include/vga.h"
#include "include/tables.h"

void caposk(void)
{	
	t_init();
	init_printf(0, t_putf);

	init_gdt();
	init_idt();

	printf("Welcome to Jason Walter's Capstone OS!\n");
	printf("Please enjoy your stay, and mind the dust (:\n");

	for (;;) {

	}
}
