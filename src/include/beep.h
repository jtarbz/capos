#ifndef BEEP_H
#define BEEP_H

#include <stdint.h>

void beep(uint32_t freq);
void unbeep(void);
void tbeep(uint32_t freq, uint32_t ms);
void beep_two(uint32_t freq1, uint32_t freq2, uint32_t ms);
void beep_three(uint32_t freq1, uint32_t freq2, uint32_t freq3, uint32_t ms);

#endif
