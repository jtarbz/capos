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
		tbeep(262, 700);
		sleep(50);
		tbeep(262, 250);
		beep_two(294, 349, 1000);
		beep_three(330, 262, 392, 1000);
		beep_two(349, 440, 1000);
		beep_three(392, 329, 523, 2000);
		tbeep(262, 700);
		sleep(50);
		tbeep(262, 250);
		beep_two(294, 392, 1000);
		beep_three(330, 262, 440, 1000);
		beep_three(294, 392, 466, 1000);
		beep_three(262, 349, 440, 2000);
		beep_two(262, 440, 700);
		sleep(50);
		beep_two(262, 440, 250);
		beep_two(262, 523, 1000);
		beep_two(262, 440, 1000);
		beep_three(277, 349, 440, 1000);
		beep_three(262, 330, 587, 1000);
		beep_two(294, 466, 950);
		sleep(50);
		beep_two(294, 466, 700);
		sleep(50);
		beep_two(330, 466, 250);
		beep_three(349, 440, 523, 950);
		sleep(50);
		beep_three(440, 349, 523, 950);
		sleep(50);
		beep_three(466, 392, 523, 950);
		sleep(50);
		beep_three(440, 349, 523, 3000);
		sleep(2000);
	}
}
