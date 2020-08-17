#include <stdint.h>
#include "include/keyboard.h"
#include "include/vga.h"
#include "include/printf.h"

void keyboard_handler(void)
{
	static shift = 0;
	uint8_t scan = inb(0x60);

	if (scan == 0x2a || scan == 0xaa) {
		shift = ~shift;
		return;
	}

	if (scan > 0xba || scan_key[scan] == 0)
		return;

	switch (shift) {
	case 0:
		t_putc(scan_key[scan]);
		break;
	case -1:
		t_putc(shift_scan_key[scan]);
	}

	return;
}
