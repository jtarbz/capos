#include <stdint.h>
#include <stddef.h>
#include "include/vga.h"
#include "include/util.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t *)0xb8000;

static size_t t_row;
static size_t t_column;
static uint8_t t_color;
static uint16_t *t_buffer;

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

void t_init(void)
{
	t_row = 0;
	t_column = 0;
	t_color = vga_entry_color(LIGHT_GREY, BLACK);
	t_buffer = VGA_MEMORY;

	for (size_t y = 0; y < VGA_HEIGHT; ++y) {
		for (size_t x = 0; x < VGA_WIDTH; ++x) {
			const size_t index = y * VGA_WIDTH + x;
			t_buffer[index] = vga_entry(' ', t_color);
		}
	}

	return;
}

void t_setcolor(uint8_t color)
{
	t_color = color;
	
	return;
}

void t_putat(unsigned char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	t_buffer[index] = vga_entry(c, color);

	return;
}

void t_putc(char c)
{
	switch (c) {
	case '\n':
		t_column = 0;
		++t_row ;
		break;
	case '\b':
		if (t_column != 0) {
			--t_column;
			t_putat(' ', t_color, t_column, t_row);
		} else if (t_row > 0) {
			--t_row;
			t_column = 79;
			t_putat(' ', t_color, t_column, t_row);
		}

		break;
	default:
		t_putat(c, t_color, t_column, t_row);
		++t_column;
	}

	if (t_column == VGA_WIDTH) {
		t_column = 0;
		++t_row;
	}

	if (t_row == VGA_HEIGHT) {
		/* copy all data back one line */
		for (size_t y = 0; y < VGA_HEIGHT; ++y) {
			for (size_t x = 0; x < VGA_WIDTH; ++x) {
				const size_t index = y * VGA_WIDTH + x;
				t_buffer[index] = t_buffer[index + VGA_WIDTH];
			}
		}

		/* clear last line */
		for (size_t x = 0; x < VGA_WIDTH; ++x) {
			const size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH + x;
			t_buffer[index] = vga_entry(' ', t_color);
		}

		--t_row;
	}


	return;
}

void t_write(const char *data, size_t size)
{
	for (size_t i = 0; i < size; ++i) 
		t_putc(data[i]);

	return;
}

void t_puts(const char *data)
{
	t_write(data, strlen(data));

	return;
}

/*
 * wrapper for printf(), wish i could have rolled my own
 */
void t_putf(void *x, char c)
{
	t_putc(c);
	
	return;
}
