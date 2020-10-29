#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void set_timer(uint16_t hertz);
void timer_handler(void);
void sleep(uint32_t delay);
uint32_t get_time(void);

extern uint32_t ticks;

#endif
