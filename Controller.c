/*Controller.c*/
/*Uses ASM Libraries to perform desired functions*/
/*Written by: John DeBrino*/
/*Revision Date: 1/25/2016*/

/*								Includes							*/
#include "Controller.h"
#include "Animations.h"
/*								Defines 							*/
#define LED_STRIP_SIZE	144						 /* # of LEDs in strip */
#define TRUE 1
/*								Colors								*/
/*						 (BGR Values)							*/
#define WHITE	(0x00FFFFFEu)
#define AMBER	(0x0000C2FFu)
#define	NOCOLOR	(0x00000000u)

/*								  Code								*/

/*Main code; runs on startup*/
int main(void)
{
	/*int x = 0;
	int y = 0;
	int z = 0;
	*/

	/*Board initializations*/
 	__asm("CPSID	I");

	initSPI();
	initPITInterrupt();
	initPTAInterrupt();

	__asm("CPSIE	I");

	/*Main loop*/

	/*Main is currently being used to test features as they are being developed*/
	for(;;)
	{
		/*If the bool for turning has been set for true, run the*/
		/*Sequential pattern until the bool is reset to false*/
		if (Turning == TRUE)
		{
			ReverseSequentialPattern(144,&Turning);
			setStrip(144,WHITE,0x30);
		}
		else
		{
			setStrip(144,NOCOLOR,0x71);
		}

	}
}
