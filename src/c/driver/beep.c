#include <stdint.h>
#include "include/beep.h"
#include "include/timer.h"
#include "include/util.h"

void beep(uint32_t freq)
{
	uint32_t divisor = 1193180 / freq;
	outb(0x43, 0xb6);		// set command byte
	outb(0x42, divisor & 0xff);	// first half of divisor
	outb(0x42, divisor >> 8);	// second half

	uint8_t tmp = inb(0x61);
	if (tmp != (tmp | 3))
		outb(0x61, tmp | 3);
	return;
}

void unbeep(void)
{
	uint8_t tmp = inb(0x61) & 0xfc;
	outb(0x61, tmp);
	return;
}
void tbeep(uint32_t freq, uint32_t ms)
{
	beep(freq);
	sleep(ms);
	unbeep();
	return;
}
