#include "include/beep.h"
#include "include/timer.h"
#include "include/terminal.h"
#include "include/printf.h"

void happy_birthday(void)
{
	tbeep(_C4, 700);
	sleep(50);
	tbeep(_C4, 250);
	beep_two(_D4, _F4, 1000);
	beep_three(_E4, _C4, _G4, 1000);
	beep_two(_F4, _A4, 1000);
	beep_three(_G4, _E4, _C5, 2000);
	tbeep(_C4, 700);
	sleep(50);
	tbeep(_C4, 250);
	beep_two(_D4, _G4, 1000);
	beep_three(_E4, _C4, _A4, 1000);
	beep_three(_D4, _G4, _AS4, 1000);
	beep_three(_C4, _F4, _A4, 2000);
	beep_two(_C4, _A4, 700);
	sleep(50);
	beep_two(_C4, _A4, 250);
	beep_two(_C4, _C5, 1000);
	beep_two(_C4, _A4, 1000);
	beep_three(_CS4, _F4, _A4, 1000);
	beep_three(_C4, _E4, _D5, 1000);
	beep_two(_D4, _AS4, 950);
	sleep(50);
	beep_two(_D4, _AS4, 700);
	sleep(50);
	beep_two(_E4, _AS4, 250);
	beep_three(_F4, _A4, _C5, 950);
	sleep(50);
	beep_three(_A4, _F4, _C5, 950);
	sleep(50);
	beep_three(_AS4, _G4, _C5, 950);
	sleep(50);
	beep_three(_A4, _F4, _C5, 3000);

	return;
}

/*
 * megalovania is a song by toby fox. this arrangement is covered under
 * CC BY-NC-SA 3.0 (https://creativecommons.org/licenses/by-nc-sa/3.0/)
 */
void sans_undertale(void)
{
	t_clear();
	printf("wanna have a bad time ? \n");

	beep_note(_D4, 125);			// measure 1
	beep_note(_D4, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_C4, 125);			// 2
	beep_note(_C4, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_B3, 125);			// 3
	beep_note(_B3, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_AS3, 125);			// 4
	beep_note(_AS3, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_twon(_D3, _D4, 125);		// 5
	beep_note(_D4, 125);
	beep_twon(_D3, _D5, 250);
	beep_twon(_D3, _A4, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_twon(_D3, _GS4, 125);
	sleep(125);
	beep_twon(_D3, _G4, 125);
	sleep(125);
	beep_two(_D3, _F4, 100);
	tbeep(_F4, 25);
	beep_twon(_D3, _F4, 125);
	beep_twon(_D3, _D4, 125);
	beep_twon(_D3, _F4, 125);
	beep_note(_G4, 125);

	beep_twon(_C3, _C4, 125);		// 6
	beep_note(_C4, 125);
	beep_twon(_C3, _D5, 250);
	beep_twon(_C3, _A4, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_twon(_C3, _GS4, 125);
	sleep(125);
	beep_twon(_C3, _G4, 125);
	sleep(125);
	beep_two(_C3, _F4, 100);
	tbeep(_F4, 25);
	beep_twon(_C3, _F4, 125);
	beep_twon(_C3, _D4, 125);
	beep_twon(_C3, _F4, 125);
	beep_note(_G4, 125);

	beep_twon(_B2, _B3, 125);		// 7
	beep_note(_B3, 125);
	beep_twon(_B2, _D5, 250);
	beep_twon(_B2, _A4, 125);
	beep_note(_B2, 125);
	sleep(125);
	beep_twon(_B2, _GS4, 125);
	sleep(125);
	beep_twon(_B2, _G4, 125);
	sleep(125);
	beep_two(_B2, _F4, 100);
	tbeep(_F4, 25);
	beep_twon(_B2, _F4, 125);
	beep_twon(_B2, _D4, 125);
	beep_twon(_B2, _F4, 125);
	beep_note(_G4, 125);

	beep_twon(_BF2, _AS3, 125);		// 8
	beep_note(_AS3, 125);
	beep_twon(_BF2, _D5, 250);
	beep_twon(_BF2, _A4, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_twon(_C3, _GS4, 125);
	sleep(125);
	beep_twon(_C3, _G4, 125);
	sleep(125);
	beep_two(_C3, _F4, 100);
	tbeep(_F4, 25);
	beep_twon(_C3, _F4, 125);
	beep_twon(_C3, _D4, 125);
	beep_twon(_C3, _F4, 125);
	beep_note(_G4, 125);

	beep_twon(_D3, _D5, 125);		// 9
	beep_note( _D5, 125);
	beep_twon(_D3, _D6, 250);
	beep_twon(_D3, _A5, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_twon(_D3, _GS5, 125);
	sleep(125);
	beep_twon(_D3, _G5, 125);
	sleep(125);
	beep_two(_D3, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_D3, _F5, 125);
	beep_twon(_D3, _D5, 125);
	beep_twon(_D3, _F5, 125);
	beep_twon(_D3, _G5, 125);

	beep_twon(_C3, _C5, 125);		// 10
	beep_note(_C5, 125);
	beep_twon(_C3, _D6, 250);
	beep_twon(_C3, _A5, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_twon(_C3, _GS5, 125);
	sleep(125);
	beep_twon(_C3, _G5, 125);
	sleep(125);
	beep_two(_C3, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_C3, _F5, 125);
	beep_twon(_C3, _D5, 125);
	beep_twon(_C3, _F5, 125);
	beep_note(_G5, 125);

	beep_twon(_B2, _B4, 125);		// 11
	beep_note(_B4, 125);
	beep_twon(_B2, _D6, 250);
	beep_twon(_B2, _A5, 125);
	beep_note(_B2, 125);
	sleep(125);
	beep_twon(_B2, _GS5, 125);
	sleep(125);
	beep_twon(_B2, _G5, 125);
	sleep(125);
	beep_two(_B2, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_B2, _F5, 125);
	beep_twon(_B2, _D5, 125);
	beep_twon(_B2, _F5, 125);
	beep_note(_G5, 125);

	beep_twon(_BF2, _AS4, 125);		// 12
	beep_note(_AS4, 125);
	beep_twon(_BF2, _D6, 250);
	beep_twon(_BF2, _A5, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_twon(_C3, _GS5, 125);
	sleep(125);
	beep_twon(_C3, _G5, 125);
	sleep(125);
	beep_two(_C3, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_C3, _F5, 125);
	beep_twon(_C3, _D5, 125);
	beep_twon(_C3, _F5, 125);
	beep_note(_G5, 125);

	beep_twon(_D3, _D5, 125);		// 13
	beep_note( _D5, 125);
	beep_twon(_D3, _D6, 250);
	beep_twon(_D3, _A5, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_twon(_D3, _GS5, 125);
	sleep(125);
	beep_twon(_D3, _G5, 125);
	sleep(125);
	beep_two(_D3, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_D3, _F5, 125);
	beep_twon(_D3, _D5, 125);
	beep_twon(_D3, _F5, 125);
	beep_twon(_D3, _G5, 125);

	beep_twon(_C3, _C5, 125);		// 14
	beep_note(_C5, 125);
	beep_twon(_C3, _D6, 250);
	beep_twon(_C3, _A5, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_twon(_C3, _GS5, 125);
	sleep(125);
	beep_twon(_C3, _G5, 125);
	sleep(125);
	beep_two(_C3, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_C3, _F5, 125);
	beep_twon(_C3, _D5, 125);
	beep_twon(_C3, _F5, 125);
	beep_note(_G5, 125);

	beep_twon(_B2, _B4, 125);		// 15
	beep_note(_B4, 125);
	beep_twon(_B2, _D6, 250);
	beep_twon(_B2, _A5, 125);
	beep_note(_B2, 125);
	sleep(125);
	beep_twon(_B2, _GS5, 125);
	sleep(125);
	beep_twon(_B2, _G5, 125);
	sleep(125);
	beep_two(_B2, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_B2, _F5, 125);
	beep_twon(_B2, _D5, 125);
	beep_twon(_B2, _F5, 125);
	beep_note(_G5, 125);

	beep_twon(_BF2, _AS4, 125);		// 16
	beep_note(_AS4, 125);
	beep_twon(_BF2, _D6, 250);
	beep_twon(_BF2, _A5, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_twon(_C3, _GS5, 125);
	sleep(125);
	beep_twon(_C3, _G5, 125);
	sleep(125);
	beep_two(_C3, _F5, 100);
	tbeep(_F5, 25);
	beep_twon(_C3, _F5, 125);
	beep_twon(_C3, _D5, 125);
	beep_two(_C3, _C5, 125);
	beep_two(_C3, _D5, 63);
	beep_twon(_C3, _E5, 62);

	tbeep(_E5, 25);				// 17
	beep_twon(_D3, _F5, 225);
	beep_twon(_D3, _F5, 125);
	beep_note(_F5, 125);
	beep_note(_D3, 125);
	beep_twon(_D3, _F5, 125);
	sleep(100);
	tbeep(_E5, 25);
	beep_two(_D3, _F5, 125);
	tbeep(_F5, 125);
	beep_twon(_D3, _D5, 125);
	sleep(125);
	beep_two(_D3, _D5, 500);
	beep_twon(_D3, _D5, 125);

	beep_twon(_C3, _F5, 250);		// 18
	beep_twon(_C3, _F5, 125);
	beep_note(_F5, 125);
	beep_note(_C3, 125);
	beep_twon(_C3, _G5, 125);
	sleep(125);
	beep_two(_C3, _GS5, 125);
	beep_twon(_C3, _GS5, 125);
	beep_two(_C3, _G5, 63);
	beep_twon(_C3, _GS5, 62);
	beep_note(_G5, 125);
	beep_twon(_C3, _D5, 125);
	beep_twon(_C3, _F5, 125);
	beep_twon(_C3, _G5, 125);
	tbeep(_C4, 125);
	beep_note(_C3, 125);

	beep_twon(_B2, _F5, 250);		// 19
	beep_twon(_B2, _F5, 125);
	beep_note(_F5, 125);
	beep_note(_B2, 125);
	beep_twon(_B2, _G5, 125);
	sleep(125);
	beep_twon(_B2, _GS5, 125);
	sleep(125);
	beep_twon(_B2, _A5, 125);
	sleep(125);
	beep_twon(_B2, _C6, 125);
	beep_note(_B2, 125);
	beep_two(_B2, _A5, 125);
	beep_threen(_B2, _B3, _A5, 250);

	beep_twon(_BF2, _D6, 250);		// 20
	beep_twon(_BF2, _D6, 250);
	beep_twon(_BF2, _D6, 125);
	beep_twon(_BF2, _A5, 125);
	beep_note(_D6, 125);
	beep_two(_C3, _C6, 500);
	beep_three(_C3, _C6, _G6, 375);
	beep_three(_C4, _C6, _G6, 125);
	beep_threen(_C3, _C6, _G6, 125);

	beep_threen(_D4, _F5, _A5, 250);	// 21
	beep_threen(_D5,_F5, _A5, 125);
	beep_twon(_F5, _A5, 125);
	beep_note(_A4, 125);
	beep_twon(_F5, _A5, 125);
	sleep(100);
	beep_two(_E4, _GS5, 25);
	beep_three(_GS4, _F5, _A5, 125);
	beep_twon(_F5, _A5, 125);
	beep_threen(_G4, _D5, _G5, 125);
	sleep(125);
	beep_three(_F4, _D5, _G5, 250);
	beep_three(_D4, _D5, _G5, 125);
	beep_three(_F4, _D5, _G5, 125);
	beep_threen(_G4, _D5, _G5, 125);

	beep_threen(_C4, _F5, _A5, 250);	// 22
	beep_threen(_D5, _F5, _A5, 250);
	beep_threen(_A4, _F5, _A5, 125);
	beep_twon(_F5, _A5, 125);
	sleep(125);
	beep_threen(_GS4, _D5, _G5, 125);
	sleep(125);
	beep_threen(_G4, _F5, _A5, 125);
	sleep(125);
	beep_threen(_F4, _E5, _D6, 250);
	beep_threen(_D4, _D5, _A5, 125);
	beep_three(_F4, _C5, _G5, 125);
	beep_threen(_G4, _C5, _G5, 125);

	beep_threen(_B3, _F5, _D6, 250);	// 23
	beep_twon(_D5, _A5, 250);
	beep_twon(_A4, _G5, 250);
	tbeep(_F5, 125);
	beep_twon(_GS4, _F5, 125);
	beep_two(_E5, _C6, 125);
	beep_threen(_G4, _E5, _C6, 125);
	tbeep(_G5, 125);
	beep_twon(_F4, _G5, 125);
	tbeep(_F5, 125);
	beep_twon(_D4, _F5, 125);
	beep_two(_F4, _E5, 125);
	beep_twon(_G4, _E5, 125);

	beep_threen(_AS3, _G4, _AS4, 250);	// 24
	beep_twon(_AS4, _D5, 125);
	beep_two(_C5, _E5, 125);
	beep_threen(_G4, _C5, _E5, 125);
	beep_twon(_D5, _F5, 250);
	beep_two(_E5, _C6, 250);
	beep_three(_G4, _E5, _C6, 125);
	beep_two(_E5, _C6, 125);
	beep_three(_F4, _E5, _C6, 250);
	beep_three(_D4, _E5, _C6, 125);
	beep_three(_F4, _E5, _C6, 125);
	beep_threen(_G4, _E5, _C6, 125);

	for (int i = 0; i < 2; ++i) {
		beep_note(_BF2, 250);			// 25
		beep_note(_BF2, 250);
		beep_note(_BF2, 125);
		beep_note(_BF2, 125);
		sleep(125);
		beep_note(_BF2, 125);
		beep_twon(_D5, _F5, 125);
		beep_threen(_BF2, _BF4, _D5, 125);
		beep_twon(_D5, _F5, 125);
		beep_threen(_BF2, _D5, _G5, 125);
		beep_threen(_BF2, _D5, _AF5, 125);
		beep_threen(_BF2, _D5, _G5, 125);
		beep_threen(_BF2, _D5, _F5, 125);
		beep_twon(_BF4, _D5, 125);

		beep_threen(_C3, _F5, _AF5, 63);	// 26
		beep_twon(_E5, _G5, 62);
		beep_note(_D5, 125);
		beep_threen(_C3, _D5, _F5, 250);
		beep_three(_C3, _E5, _G5, 115);
		beep_two(_E5, _G5, 10);
		beep_three(_C3, _E5, _G5, 125);
		beep_two(_E5, _G5, 125);
		beep_three(_C3, _E5, _G5, 125);
		beep_two(_E5, _G5, 125);
		beep_three(_C3, _E5, _G5, 125);
		beep_two(_E5, _G5, 125);
		beep_three(_C3, _E5, _G5, 115);
		beep_two(_E5, _G5, 10);
		beep_twon(_C3, _G5, 125);
		beep_two(_C3, _GS5, 115);
		tbeep(_GS5, 10);
		beep_two(_C3, _GS5, 125);
		tbeep(_A5, 125);

		beep_twon(_D3, _C6, 125);		// 27
		sleep(125);
		beep_twon(_D3, _A5, 125);
		beep_note(_GS5, 125);
		beep_twon(_D3, _G5, 125);
		beep_twon(_D3, _F5, 125);
		beep_note(_D5, 125);
		beep_twon(_D3, _E5, 125);
		tbeep(_F5, 125);
		beep_twon(_D3, _F5, 125);
		tbeep(_G5, 125);
		beep_twon(_D3, _G5, 125);
		beep_two(_D3, _A5, 115);
		tbeep(_A5, 10);
		beep_twon(_D3, _A5, 125);
		beep_twon(_D3, _C6, 250);

		beep_twon(_CS3, _DF6, 250);		// 28
		beep_twon(_CS3, _AF5, 125);
		sleep(125);
		beep_twon(_CS3, _AF5, 125);
		beep_twon(_CS3, _G5, 125);
		beep_note(_F5, 125);
		beep_two(_DS3, _G5, 240);
		tbeep(_G5, 10);
		beep_two(_DS3, _G5, 125);
		tbeep(_G5, 125);
		beep_two(_DS3, _G5, 115);
		tbeep(_G5, 10);
		beep_two(_DS3, _G5, 115);
		tbeep(_G5, 10);
		beep_two(_DS3, _G5, 115);
		tbeep(_G5, 10);
		beep_twon(_DS3, _G5, 63);
		beep_note(_GF5, 62);
		beep_note(_F5, 63);
		beep_note(_E5, 62);

		beep_threen(_BF2, _F4, _D5, 250);	// 29
		beep_threen(_BF2, _G4, _E5, 250);
		beep_threen(_BF2, _A4, _F5, 250);
		beep_two(_A5, _F6, 125);
		beep_threen(_BF2, _A5, _F6, 125);
		beep_two(_G5, _E6, 125);
		beep_three(_BF2, _G5, _E6, 125);
		beep_two(_G5, _E6, 125);
		beep_threen(_BF2, _G5, _E6, 125);
		beep_three(_BF2, _F5, _D6, 500);

		beep_threen(_C3, _G5, _E6, 500);	// 30
		beep_three(_C3, _A5, _F6, 250);
		beep_two(_A5, _F6, 125);
		beep_threen(_C3, _A5, _F6, 125);
		beep_two(_C6, _G6, 125);
		beep_three(_C3, _C6, _G6, 125);
		beep_two(_C6, _G6, 125);
		beep_threen(_C3, _C6, _G6, 125);
		beep_three(_C6, _A5, _E6, 125);
		beep_two(_A5, _E6, 125);
		beep_threen(_C3, _A5, _E6, 250);

		beep_three(_D3, _D6, _A6, 250);		// 31
		beep_two(_D6, _A6, 375);
		beep_three(_D3, _D6, _A6, 125);
		beep_two(_D6, _A6, 125);
		beep_three(_D3, _D6, _A6, 125);
		beep_two(_D6, _A6, 125);
		beep_three(_D3, _D6, _GS6, 125);
		beep_two(_D6, _G6, 125);
		beep_three(_D3, _D6, _FS6, 125);
		beep_two(_D6, _F6, 125);
		beep_two(_D6, _E6, 125);
		beep_three(_D3, _D6, _DS6, 125);
		beep_twon(_D3, _D6, 125);

		beep_three(_CS3, _GS5, _CS6, 250);	// 32
		beep_two(_GS5, _CS6, 375);
		beep_three(_CS3, _GS5, _CS6, 125);
		beep_two(_GS5, _CS6, 125);
		beep_three(_DS3, _GS5, _D6, 125);
		beep_two(_BF5, _EF6, 125);
		beep_three(_DS3, _BF5, _EF6, 125);
		beep_two(_BF5, _EF6, 125);
		beep_three(_DS3, _BF5, _EF6, 125);
		beep_two(_BF5, _EF6, 125);
		beep_threen(_DS3, _BF5, _EF6, 375);
	}

	beep_two(_BF2, _BF3, 1500);		// 33
	beep_twon(_BF2, _F4, 500);

	beep_two(_C3, _E4, 1000);		// 34
	beep_twon(_C3, _D4, 1000);

	beep_twon(_B2, _F4, 2000);		// 35

	beep_note(_B2, 250);			// 36
	beep_note(_B2, 250);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	beep_note(_B2, 250);

	beep_two(_BF2, _BF3, 1500);		// 37
	beep_twon(_BF2, _F4, 500);

	beep_two(_C3, _E4, 1000);		// 38
	beep_twon(_C3, _D4, 1000);

	beep_two(_D3, _D4, 3500);		// 39 + 40
	beep_two(_D3, _DF4, 40);
	beep_two(_D3, _C4, 40);
	beep_two(_D3, _B3, 40);
	beep_two(_D3, _BF3, 40);
	beep_two(_D3, _A3, 40);
	beep_two(_D3, _AF3, 40);
	beep_two(_D3, _G3, 40);
	beep_two(_D3, _FS3, 40);
	beep_two(_D3, _F3, 40);
	beep_two(_D3, _E3, 40);
	beep_two(_D3, _EF3, 40);
	beep_twon(_D3, _D3, 60);

	tbeep(_BF3, 125);			// 41
	beep_two(_D3, _BF3, 125);
	beep_two(_D4, _BF3, 250);
	beep_two(_A3, _BF3, 250);
	tbeep(_BF3, 125);
	beep_two(_AF3, _BF3, 125);
	tbeep(_BF3, 125);
	beep_two(_G3, _BF3, 125);
	tbeep(_BF3, 125);
	beep_two(_F3, _BF3, 125);
	beep_two(_F3, _F4, 125);
	beep_two(_D3, _F4, 125);
	beep_two(_F3, _F4, 125);
	beep_twon(_G3, _F4, 125);

	beep_two(_C3, _E4, 250);		// 42
	beep_two(_D4, _E4, 250);
	beep_two(_A3, _E4, 125);
	tbeep(_E4, 125);
	beep_two(_AF3, _E4, 125);
	tbeep(_D4, 125);
	beep_two(_G3, _D4, 125);
	tbeep(_D4, 125);
	beep_two(_F3, _D4, 250);
	beep_two(_D3, _D4, 125);
	beep_two(_F3, _D4, 125);
	beep_twon(_G3, _D4, 125);

	beep_two(_B2, _F4, 250);		// 43
	beep_two(_D4,_F4, 250);
	beep_two(_A3, _F4, 250);
	tbeep(_F4, 125);
	beep_two(_AF3, _F4, 125);
	tbeep(_F4, 125);
	beep_two(_G3, _F4, 125);
	tbeep(_F4, 125);
	beep_two(_F3, _F4, 250);
	beep_two(_D3, _F4, 125);
	beep_two(_F3, _F4, 125);
	beep_twon(_G3, _F4, 125);

	beep_twon(_B2, _G5, 125);		// 44
	beep_twon(_B2, _D6, 125);
	beep_twon(_D4, _F6, 125);
	beep_note(_D6, 125);
	beep_twon(_A3, _G6, 250);
	beep_note(_F6, 125);
	beep_note(_AF3, 125);
	beep_note(_D6, 125);
	beep_twon(_G3, _C6, 125);
	sleep(125);
	beep_twon(_F3, _A5, 250);
	beep_twon(_D3, _G5, 125);
	beep_twon(_F3, _A5, 125);
	beep_twon(_G3, _C6, 125);

	tbeep(_BF3, 125);			// 45
	beep_two(_D3, _BF3, 125);
	beep_two(_D4, _BF3, 250);
	beep_two(_A3, _BF3, 250);
	tbeep(_BF3, 125);
	beep_two(_AF3, _BF3, 125);
	tbeep(_BF3, 125);
	beep_two(_G3, _BF3, 125);
	tbeep(_BF3, 125);
	beep_two(_F3, _BF3, 125);
	beep_two(_F3, _F4, 125);
	beep_two(_D3, _F4, 125);
	beep_two(_F3, _F4, 125);
	beep_twon(_G3, _F4, 125);

	beep_two(_C3, _E4, 250);		// 46
	beep_two(_D4, _E4, 250);
	beep_two(_A3, _E4, 125);
	tbeep(_E4, 125);
	beep_two(_AF3, _E4, 125);
	tbeep(_D4, 125);
	beep_two(_G3, _D4, 125);
	tbeep(_D4, 125);
	beep_two(_F3, _D4, 250);
	beep_two(_D3, _D4, 125);
	beep_two(_F3, _D4, 125);
	beep_twon(_G3, _D4, 125);

	beep_twon(_D3, _D4, 125);		// 47
	beep_note(_D3, 125);
	beep_twon(_D4, _F5, 250);
	beep_twon(_A3, _E5, 250);
	sleep(125);
	beep_twon(_AF3, _C5, 125);
	sleep(125);
	beep_twon(_G3, _E5, 125);
	sleep(125);
	beep_twon(_F3, _D5, 250);
	beep_twon(_D3, _G4, 125);
	beep_twon(_F3, _A4, 125);
	beep_twon(_G3, _C5, 125);

	beep_note(_D3, 125);			// 48
	beep_note(_D3, 125);
	beep_twon(_D4, _F5, 250);
	beep_twon(_A3, _E5, 250);
	sleep(125);
	beep_twon(_AF3, _C5, 125);
	sleep(125);
	beep_twon(_G3, _E5, 125);
	sleep(125);
	beep_twon(_F3, _D5, 250);
	beep_twon(_D3, _G4, 125);
	beep_twon(_F3, _A4, 125);
	beep_twon(_G3, _C5, 125);

	beep_note(_BF2, 250);			// 49
	beep_note(_BF2, 250);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 250);

	beep_note(_C3, 250);			// 50
	beep_note(_C3, 250);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);

	beep_note(_D3, 250);			// 51
	beep_note(_D3, 250);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_CS3, 125);
	sleep(125);
	beep_note(_CS3, 125);
	sleep(125);
	beep_note(_CS3, 125);
	beep_note(_CS3, 125);
	beep_note(_CS3, 125);
	beep_note(_CS3, 250);

	beep_note(_C3, 250);			// 52
	beep_note(_C3, 250);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	beep_note(_B2, 250);

	beep_note(_BF2, 250);			// 53
	beep_note(_BF2, 250);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 250);

	beep_note(_C3, 250);			// 54
	beep_note(_C3, 250);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);

	beep_note(_D3, 250);			// 55
	beep_note(_D3, 250);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	beep_note(_D3, 250);

	beep_note(_D3, 250);			// 56
	beep_note(_D3, 250);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	beep_note(_D3, 250);

	beep_note(_BF2, 250);			// 57
	beep_note(_BF2, 250);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 250);

	beep_note(_C3, 250);			// 58
	beep_note(_C3, 250);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);

	beep_note(_D3, 250);			// 59
	beep_note(_D3, 250);
	beep_note(_D3, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_note(_CS3, 125);
	sleep(125);
	beep_note(_CS3, 125);
	sleep(125);
	beep_note(_CS3, 125);
	beep_note(_CS3, 125);
	beep_note(_CS3, 125);
	beep_note(_CS3, 250);

	beep_note(_C3, 250);			// 60
	beep_note(_C3, 250);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	sleep(125);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	beep_note(_B2, 125);
	beep_note(_B2, 250);

	beep_note(_BF2, 250);			// 61
	beep_note(_BF2, 250);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	sleep(125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 125);
	beep_note(_BF2, 250);

	beep_note(_C3, 250);			// 62
	beep_note(_C3, 250);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	sleep(125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);
	beep_note(_C3, 125);

	beep_twon(_D3, _D4, 125);		// 63
	beep_note(_D4, 125);
	beep_twon(_D3, _D5, 250);
	beep_twon(_D3, _A4, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_twon(_D3, _GS4, 125);
	sleep(125);
	beep_twon(_D3, _G4, 125);
	sleep(125);
	beep_two(_D3, _F4, 100);
	tbeep(_F4, 25);
	beep_twon(_D3, _F4, 125);
	beep_twon(_D3, _D4, 125);
	beep_twon(_D3, _F4, 125);
	beep_note(_G4, 125);

	beep_twon(_D3, _D4, 125);		// 64
	beep_note(_D4, 125);
	beep_twon(_D3, _D5, 250);
	beep_twon(_D3, _A4, 125);
	beep_note(_D3, 125);
	sleep(125);
	beep_twon(_D3, _GS4, 125);
	sleep(125);
	beep_twon(_D3, _G4, 125);
	sleep(125);
	beep_two(_D3, _F4, 100);
	tbeep(_F4, 25);
	beep_twon(_D3, _F4, 125);
	beep_twon(_D3, _D4, 125);
	beep_twon(_D3, _F4, 125);
	beep_note(_G4, 125);

	beep_note(_BF3, 125);			// 65
	beep_note(_BF3, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_C4, 125);			// 66
	beep_note(_C4, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_D4, 125);			// 67
	beep_note(_D4, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_D4, 125);			// 68
	beep_note(_D4, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_BF3, 125);			// 69
	beep_note(_BF3, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_C4, 125);			// 70
	beep_note(_C4, 125);
	beep_note(_D5, 250);
	beep_note(_A4, 250);
	sleep(125);
	beep_note(_GS4, 125);
	sleep(125);
	beep_note(_G4, 125);
	sleep(125);
	beep_note(_F4, 250);
	beep_note(_D4, 125);
	beep_note(_F4, 125);
	beep_note(_G4, 125);

	beep_note(_D4, 500);
	t_clear();

	return;
}
