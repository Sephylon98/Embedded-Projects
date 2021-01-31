/*
 * Casters.c
 *
 * Created: 1/14/2021 6:53:24 AM
 *  Author: Mohamed
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include "STD_Types.h"
#include "LCD.h"

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char* res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;
	
	// Extract floating part
	float fpart = n - (float)ipart;
	
	// convert integer part to string
	int i = intToStr(ipart, res, 0);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot
		
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

int get_num(char ch)         //convert char into int
{
	switch(ch)
	{
		case '0': return 0; break;
		case '1': return 1; break;
		case '2': return 2; break;
		case '3': return 3; break;
		case '4': return 4; break;
		case '5': return 5; break;
		case '6': return 6; break;
		case '7': return 7; break;
		case '8': return 8; break;
		case '9': return 9; break;
	}
	return 0;
}

void disp_num(float num)            //displays number on LCD
{
	unsigned char UnitDigit  = 0;  //It will contain unit digit of numb
	unsigned char TenthDigit = 0;  //It will contain 10th position digit of numb
	unsigned char decimal = 0;
	int j;
	int numb;
	j=(int)(num*10);
	numb=(int)num;
	if(numb<0)
	{
		numb = -1*numb;  // Make number positive
		LCD_Char('-');	// Display a negative sign on LCD
	}

	TenthDigit = (numb/10);	         // Findout Tenth Digit

	if( TenthDigit != 0)	         // If it is zero, then don't display
	LCD_Char(TenthDigit+0x30);	 // Make Char of TenthDigit and then display it on LCD

	UnitDigit = numb - TenthDigit*10;

	LCD_Char(UnitDigit+0x30);	 // Make Char of UnitDigit and then display it on LCD
	LCD_Char('.');
	decimal=(j%10)+0x30;
	LCD_Char(decimal);
	_delay_us(2000000);
}