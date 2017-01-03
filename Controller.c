/*Controller.c*/
/*Uses ASM Libraries to perform desired functions*/
/*Written by: John DeBrino*/
/*Revision Date: 12/26/2016*/

/*								Includes							*/
#include "Controller.h"

/*								Defines 							*/
#define LED_STRIP_SIZE	30 /* # of LEDs in strip */

/*								Colors								*/
#define WHITE	(0xFFFFFFFFu)
#define AMBER	(0x00334466u)
#define	NOCOLOR	(0x00000000u)

/* 									DAC 								*/
#define EN_PTE	(0x00001000u)
#define EN_DAC	(0x80000000u)
#define DAC0_OUT (0x01000000u)
#define BUF_DISABLE (0x00u)
#define EN_C0 (0xC0u)
#define DATH_MIN (0x00u)
#define DATL_MIN (0x00u)
#define SIM (0x40047000u)
#define SCGC6 (0x103Cu)
/*								  Code								*/

/*Main code; runs on startup*/
int main(void)
{
	int x = 0;
	int y = 0;
	int z = 0;

	/*Board initializations*/
 	__asm("CPSID	I");

	/*initGPIOLightDataOut();*/
	initSPI();
	initPITInterrupt();

	__asm("CPSIE	I");

	/*Main loop*/

	/*Main is currently being used to test features as they are being developed*/
	for(;;)
	{
		/*Cycle through colors*/
		setColor(WHITE);
		wait(1000);
		setColor(AMBER);
		wait(1000);
	}

	return 0;
}
