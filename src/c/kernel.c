#include <stddef.h>
#include <stdint.h>
#include "include/printf.h"
#include "include/terminal.h"
#include "include/tables.h"

void caposk(void)
{	
	t_init();
	init_printf(0, t_putf);

	init_gdt();
	init_idt();

	for (;;) {

	}
}
