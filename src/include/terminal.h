#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stddef.h>

#define ARGC_INIT 5

enum vga_color {
	BLACK		= 0,
	BLUE		= 1,
	GREEN		= 2,
	CYAN		= 3,
	RED		= 4,
	MAGENTA		= 5,
	BROWN		= 6,
	LIGHT_GREY	= 7,
	DARK_GREY	= 8,
	LIGHT_BLUE	= 9,
	LIGHT_GREEN	= 10,
	LIGHT_CYAN	= 11,
	LIGHT_RED	= 12,
	LIGHT_MAGENTA	= 13,
	LIGHT_BROWN	= 14,
	WHITE		= 15
};

uint8_t vga_entry_color(enum vga_color, enum vga_color);
uint16_t vga_entry(unsigned char, uint8_t);
void t_init(void);
void t_putc(char);
void t_write(const char *, size_t);
void t_puts(const char *);
void t_putf(void *, char);
void t_clear(void);
void terminal(void);

extern char *terminal_buffer;
extern uint8_t terminal_ready;

#endif
