#include <stdint.h>
#include "include/timer.h"
#include "include/util.h"
#include "include/printf.h"

uint32_t ticks;

void timer_handler(void)
{
	++ticks;
	return;
}

void set_timer(uint16_t hertz)
{
	uint32_t divisor = 1193180 / hertz;
	outb(0x43, 0x36);		// set command byte (16-bit, square wave)
	outb(0x40, divisor & 0xff);	// send divisor high byte to channel 0
	outb(0x40, divisor >> 8);	// send divisor low byte to channel 0
	return;
}

void sleep(uint32_t delay)
{
	uint32_t tick_sum = ticks + delay;
	while (tick_sum > ticks) {
		asm volatile ("nop");
	}

	return;
}

uint32_t get_time(void)
{
	return ticks;
}
