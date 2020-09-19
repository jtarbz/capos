#include "include/multiboot.h"
#include "include/mem.h"
#include "include/printf.h"
#include "include/terminal.h"
#include "include/tables.h"
#include "include/util.h"

void caposk(multiboot_info_t *mbd)
{	
	init_gdt();
	init_idt();
	init_mmap((mmap_entry_t *)mbd->mmap_addr, mbd->mmap_length);
	t_init();
	init_printf(0, t_putf);


	for (;;) {

	}
}
