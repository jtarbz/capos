#include <stdint.h>
#include "include/keyboard.h"
#include "include/terminal.h"
#include "include/func.h"
#include "include/util.h"

/*
 * send keystrokes to the display and also push them to the terminal bufffer,
 * controlling terminal execution. called when irq1 is fired
 */
void keyboard_handler(void)
{
	static int8_t shift = 0;
	static uint32_t i = 0;
	uint8_t scan = inb(0x60);

	if (scan == 0x2a || scan == 0xaa) {
		shift = ~shift;
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
	case -1:				// shiftkey held
		t_putc(shift_scan_key[scan]);
		terminal_buffer[i] = shift_scan_key[scan];
		++i;
	}

	/* handle backspaces in terminal buffer */
	if (scan_key[scan] == '\b' && i > 0) {
		i -= 2;
		memset(terminal_buffer + i, '\0', 2);
	}

	/* to avoid crash, limit buffer size to 80 for now ... will change */
	if (scan_key[scan] == '\n' || i == (TBUF_SIZE - 1)) {
		terminal_buffer[i - 1] = '\0';	// delete line feed
		terminal();
		memset(terminal_buffer, '\0', TBUF_SIZE);
		i = 0;
	}

	return;
}
