#include "include/multiboot.h"
#include "include/mmap.h"
#include "include/printf.h"
#include "include/terminal.h"
#include "include/tables.h"
#include "include/util.h"

void caposk(multiboot_info_t *mbd)
{	
	t_init();
	init_printf(0, t_putf);

	init_gdt();
	init_idt();

	mmap_init((mmap_entry_t *)mbd->mmap_addr, mbd->mmap_length);

	for (;;) {

	}
}
