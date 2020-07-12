#include <stddef.h>
#include <stdint.h>
#include "include/printf.h"
#include "include/vga.h"
#include "include/tables.h"
#include "include/util.h"

void caposk(void)
{	
	t_init();
	init_printf(0, t_putf);

	init_gdt();
	init_idt();

	printf("Hello world!\n");
	printf("Test\n");
	for (;;) {

	}
}
