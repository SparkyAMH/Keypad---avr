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
*
*
*	Circuit connections:
*	
*	I2C EEPROM:
*	PC4 - SDA
*	PC5 - SCL
*
*	RELAY CONTROL
*	Relay 1 - PC0
*	Relay 2 - PC1
*	Relay 3 - PC2
*	Relay 4 - PC3
*
*	USB UART connection:
*	RXD - PA0
*	TXD - PA1
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

    Function return the keycode of keypressed
    on the Keypad. Keys are numbered as follows

    [00] [01] [02]
    [03] [04] [05]
    [06] [07] [08]
    [09] [10] [11]

Port D register for each key: (Binary) assuming that PIND also gets the output pin status. 
If not, mask lower 3 bits. xiiiiooo (x - no connect i - input o - out)
00 - 00001001 - 09h
01 - 00001010 - 0Ah
02 - 00001100 - 0Ch
03 - 00010001 - 11h
04 - 00010010 - 12h
05 - 00010100 - 14h
06 - 00100001 - 21h
07 - 00100010 - 22h
08 - 00100100 - 24h
09 - 01000001 - 41h
10 - 01000010 - 42h
11 - 01000100 - 44h
*/
// *******************************************/

char scankeys(void);

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



char scankeys()
{
	//************ keypad scan routine ***********
// Column 1 scan:  Potential keys, 1, 4, 7, *

	PORTD = 0x01;
				
	#ifndef DEBUG
		_delay_us(2);	 //settling time
	#endif				
				temp=PIND;

	temp = PIND;
			if (temp != 0x00)
			{
				switch(temp)
				 {
					case 0x08 : //8
					key = '1';
					break;
					case 0x10 : //16
					key = '4';
					break;
					case 0x20 : //32
					key = '7';
					break;
					case 0x30 : //64
					key = '*';
					break;
				} 
			PORTD = 0x02;
	#ifndef DEBUG
		_delay_us(2);	 //settling time
	#endif			
			}

			temp=PIND;
			if (temp != 0x00)
			{
				switch(temp)
				{
					case 0x0A : //10
					key = '2';
					break;
					case 0x12 : //18
					key = '5';
					break;
					case 0x22 : //34
					key = '8';
					break;
					case 0x32 : //66
					key = '0';
					break;
				}
				PORTD = 0x04;
	#ifndef DEBUG
		_delay_us(2);	 //settling time
	#endif	
			}
			temp=PIND;
			if (temp != 0x00)
			{
				switch(temp)
				{
					case 0x0C : //12
					key = '3';
					break;
					case 0x14 : //20
					key = '6';
					break;
					case 0x24 : //36
					key = '9';
					break;
					case 0x34 : //68
					key = '#';
					break;
				}
	#ifndef DEBUG
		_delay_us(2);	 //settling time
	#endif	

				temp = 0x00;
			}
		
	#ifndef DEBUG
		_delay_us(2);	 //settling time
	#endif	
//				CLEAR(D,0)	;
	#ifndef DEBUG
		_delay_us(2);	 //settling time
	#endif	
				return(key);
}
