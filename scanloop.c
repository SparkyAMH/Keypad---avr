char scanKey()
{
	for (j=0x0; j<0x3; j++)//set column - test row
		{
			//set column high
			PORTD = j;
			for (i=0x00; i<0x04; i++) //check for row
			{
				temp = scankey(i);
				if (temp != 0x00)
				{
					KeyPressed = getCase(j,i); //send position for decoding
					return (KeyPressed); //return pointer to array with column and row
				}
			}
		}
	}

/* Keypad pattern r c
// 00 01 02		1 2 3
// 10 11 12		4 5 6
// 20 21 22		7 8 9
// 30 31 32		* 0 #
*/
char getCase(int column, int row)
	{
		char key = 'Q';

		if (column = 0)
		{
			switch(row)
				 {
					case 0x00 :
					key = '1';
					break;
					case 0x01 :
					key = '4';
					break;
					case 0x02 :
					key = '7';
					break;
					case 0x03 :
					key = '*';
					break;
				} 
		}	
		if (column = 1)
		{
			switch(row)
				 {
					case 0x00 :
					key = '2';
					break;
					case 0x01 :
					key = '5';
					break;
					case 0x02 :
					key = '8';
					break;
					case 0x03 :
					key = '0';
					break;
				} 
		}
		if (column = 2)
		{
			switch(row)
				 {
					case 0x00 :
					key = '3';
					break;
					case 0x01 :
					key = '6';
					break;
					case 0x02 :
					key = '9';
					break;
					case 0x03 :
					key = '#';
					break;
				} 
		}
		return key;
	}