#include "include/multiboot.h"
#include "include/mem.h"
#include "include/terminal.h"
#include "include/tables.h"
#include "include/util.h"
#include "include/timer.h"
#include "include/beep.h"
#include "include/ufunc.h"
#include "include/printf.h"

void caposk(multiboot_info_t *mbd)
{	
	init_gdt();
	init_idt();
	init_mmap((mmap_entry_t *)mbd->mmap_addr, mbd->mmap_length);
	set_timer(1000);	// tick on millisecond
	t_init();
	init_printf(0, t_putf);

	umem_status();
	t_putc('\r');

	for (;;) {
		asm volatile ("nop");	// conditional ignored without this ...
		if (terminal_ready)
			terminal();
	}
}
