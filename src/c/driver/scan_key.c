/* non-shift scan translation key, control keys marked 0 */
char scan_key[0xba] = {
	0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
	'\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
	0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
	'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*',
	0, ' ', 0
};

/* shifted scan translation key */
char shift_scan_key[0xba] = {
	0, 0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
	'\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
	0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~', 0, '|',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, '*',
	0, ' ', 0
};

/*
 * the above arrays define a (limited) set of keyboard scancodes, which are the
 * signals that a keyboard sends to a computer when a key is struck or released.
 * scancode 1 is used here; on most pc-compatible systems today, keyboards talk
 * in scancode 2 but have a controller translate it into scancode 1 for
 * compatibility reasons. these sets can be expanded in concert with the
 * keyboard handler in keyboard.c to add greater functionality (tracking the
 * state of all keys, control key support, caps lock, et cetera)
 */
