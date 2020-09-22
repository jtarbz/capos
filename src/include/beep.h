#ifndef BEEP_H
#define BEEP_H

#include <stdint.h>

enum music_notes {
	_C2	= 65,
	_CS2	= 69,
	_DF2	= 69,
	_D2	= 73,
	_E2	= 82,
	_F2	= 87,
	_FS2	= 92,
	_GF2	= 92,
	_G2	= 98,
	_GS2	= 104,
	_AF2	= 104,
	_A2	= 110,
	_AS2	= 117,
	_BF2	= 117,
	_B2	= 123,
	_C3	= 131,
	_CS3	= 139,
	_DF3	= 139,
	_D3	= 147,
	_DS3	= 156,
	_EF3	= 156,
	_E3	= 165,
	_F3	= 175,
	_FS3	= 185,
	_GF3	= 185,
	_G3	= 196,
	_GS3	= 208,
	_AF3	= 208,
	_A3	= 220,
	_AS3	= 233,
	_BF3	= 233,
	_B3	= 247,
	_C4	= 262,
	_CS4	= 277,
	_DF4	= 277,
	_D4	= 294,
	_DS4	= 311,
	_EF4	= 311,
	_E4	= 330,
	_F4	= 349,
	_FS4	= 370,
	_GF4	= 370,
	_G4	= 392,
	_GS4	= 415,
	_AF4	= 415,
	_A4	= 440,
	_AS4	= 466,
	_BF4	= 466,
	_B4	= 494,
	_C5	= 523,
	_CS5	= 554,
	_DF5	= 554,
	_D5	= 587,
	_DS5	= 622,
	_EF5	= 622,
	_E5	= 659,
	_F5	= 698,
	_FS5	= 740,
	_GF5	= 740,
	_G5	= 784,
	_GS5	= 831,
	_AF5	= 831,
	_A5	= 880,
	_AS5	= 932,
	_BF5	= 932,
	_B5	= 988,
	_C6	= 1047,
	_CS6	= 1109,
	_DF6	= 1109,
	_D6	= 1175,
	_DS6	= 1245,
	_EF6	= 1245,
	_E6	= 1319,
	_F6	= 1397,
	_FS6	= 1480,
	_GF6	= 1480,
	_G6	= 1568,
	_GS6	= 1661,
	_AF6	= 1661,
	_A6	= 1760
};

void beep(uint32_t freq);
void unbeep(void);
void tbeep(uint32_t freq, uint32_t ms);
void beep_two(uint32_t freq1, uint32_t freq2, uint32_t ms);
void beep_three(uint32_t freq1, uint32_t freq2, uint32_t freq3, uint32_t ms);
void beep_note(uint32_t freq, uint32_t ms);
void beep_twon(uint32_t freq1, uint32_t freq2, uint32_t ms);
void beep_threen(uint32_t freq1, uint32_t freq2, uint32_t freq3, uint32_t ms);

#endif
