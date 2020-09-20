#include "include/multiboot.h"
#include "include/mem.h"
#include "include/terminal.h"
#include "include/tables.h"
#include "include/util.h"
#include "include/timer.h"
#include "include/beep.h"
#include "include/printf.h"

void caposk(multiboot_info_t *mbd)
{	
	init_gdt();
	init_idt();
	init_mmap((mmap_entry_t *)mbd->mmap_addr, mbd->mmap_length);
	set_timer(1000);	// tick on millisecond
	t_init();
	init_printf(0, t_putf);

	printf("\nEnjoy the music!!\n");

	for (;;) {
		tbeep(294, 500);
		tbeep(330, 500);
		tbeep(349, 500);
		tbeep(392, 500);
		tbeep(330, 1000);
		tbeep(262,500);
		tbeep(294, 1500);
		sleep(2000);
	}
}
