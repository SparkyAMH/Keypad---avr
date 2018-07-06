/*
 * Keys - real.c
 *
 * Created: 2018-07-03 9:35:11 AM
 * Author : hinza
 */ 
#define DEBUG


#include <avr/io.h>

#include <util/delay.h>
//#include <avr/macros.h>
#include <stdio.h>

/**********************************************************
*	Circuit connections:
*	
***NOT USED********
*	I2C EEPROM:
*	PC4 - SDA
*	PC5 - SCL
****************
*	RELAY CONTROL
*	Relay 1 - PC0
*	Relay 2 - PC1
*	Relay 3 - PC2
*	Relay 4 - PC3
*
*   KEYPAD
*
*       COL1 ->  PD0
*       COL2 ->  PD1
*       COL3 ->  PD2
*
*       ROW1 ->  PD3
*       ROW2 ->  PD4
*       ROW3 ->  PD5
*       ROW4 ->  PD6
*/
/*******************************************
*/

void setup(void);

int temp;
char key;
int flag;
int number;
int column;
int key_temp;
int column_scan;


int main(void)
	{
	key = 'Q';
		flag = 0x00;
//setup keypad data direction register
		DDRD = 0x07;	
		column_scan = 0;
		column = 0x01;
	
		while (1)
			{

			key = scankeys();
			putchar( key );
			
			}



	}


/************************************************************************/
/* Setup and initilization function										*/
/* DDR(X) = Data direction registers for port (X)						*/
/* I = Input, O = Output		set in binary, MSB X X X X X X X X LSB	*/
/************************************************************************/
void setup(void)
{
	DDRA = 0x00;		// Set port A as inputs
	DDRB = 0x00;		// Set port B as inputs
	DDRC = 0x0F;		// Set port C as IIIIOOOO
	DDRD = 0x07;		// Set port D as IIIIIOOO
}