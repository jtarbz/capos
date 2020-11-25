#include <stdint.h>
#include <stddef.h>
#include "include/keyboard.h"
#include "include/terminal.h"
#include "include/util.h"
#include "include/mem.h"

/*
 * send keystrokes to the display and also push them to the terminal bufffer,
 * controlling terminal execution. called when irq1 is fired
 */
void keyboard_handler(void)
{
	static uint8_t shift = 0;
	static size_t i = 0;
	static size_t tbuf_size = 80;
	uint8_t scan = inb(0x60);

	if (scan == 0x2a) {
		shift = 1;
		return;
	}
	else if (scan == 0xaa) {
		shift = 0;
		return;
	}

	if (scan > 0xba || scan_key[scan] == 0)
		return;

	switch (shift) {
	case 0:					// shiftkey not held
		t_putc(scan_key[scan]);
		terminal_buffer[i] = scan_key[scan];
		++i;
		break;
	case 1:				// shiftkey held
		t_putc(shift_scan_key[scan]);
		terminal_buffer[i] = shift_scan_key[scan];
		++i;
	}

	/* handle backspaces in terminal buffer */
	if (scan_key[scan] == '\b' && i > 1) {
		i -= 2;
		memset(terminal_buffer + i, '\0', 2);
	}
	else if (scan_key[scan] == '\b') {
		--i;
		terminal_buffer[i] = '\0';
	}

	if (i == (tbuf_size - 1)) {
		tbuf_size += 0x20;
		terminal_buffer = crealloc(terminal_buffer, tbuf_size);
		memset(terminal_buffer + i, '\0', tbuf_size - i);
	}

	if (scan_key[scan] == '\n') {
		terminal_buffer[i - 1] = '\0';	// delete line feed
		terminal_ready = 1;
		i = 0;
	}

	return;
}
