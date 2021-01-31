/*
 * LCD.c
 *
 * Created: 1/8/2021 10:19:46 AM
 *  Author: Mohamed
 */

#include "LCD.h"
#include <string.h>

void LCD_Init()
{
	DIO_WriteChannel(RW,STD_Low);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(100);
	LCD_Cmd(0x32); //LCD Initialization
	LCD_Cmd(0x28); //Function Set
	LCD_Cmd(0x06); //Entry Mode
	LCD_Cmd(0x0C); //Display ON/OFF
	LCD_Cmd(0x01); //Clear Display
	_delay_ms(2);
}

void LCD_Cmd(Uint8 cmd)
{   
	Uint8 PortData = 0;
	PortData = DIO_ReadPort(LCDPort);
	PortData = (PortData & 0x0F)|(cmd & 0xF0); //send high nibble
	DIO_WritePort(LCDPort,PortData);
 	DIO_WriteChannel(RS,STD_Low);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	
	_delay_ms(5);
	PortData = DIO_ReadPort(LCDPort);
	PortData = (PortData & 0x0F)|(cmd <<4); //send low nibble
	DIO_WritePort(LCDPort,PortData);
	DIO_WriteChannel(RS,STD_Low);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(2);
}

void LCD_Char(Uint8 data)
{
	Uint8 PortData = 0;
	PortData = DIO_ReadPort(LCDPort);
	PortData = (PortData & 0x0F)|(data & 0xF0); //send high nibble
	DIO_WritePort(LCDPort,PortData);
	DIO_WriteChannel(RS,STD_High);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
		
	_delay_ms(5);
	
	PortData = DIO_ReadPort(LCDPort);
	PortData = (PortData & 0x0F)|(data << 4); //send low nibble
	DIO_WritePort(LCDPort,PortData);
	DIO_WriteChannel(RS,STD_High);
	DIO_WriteChannel(E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(E,STD_High);
	_delay_ms(2);
}


void LCD_String(Sint8 * string)
{
	volatile Uint8 i = 0; 
	for(i; i<strlen(string); i++)
	{
		LCD_Char(string[i]);
	}
	
}

void LCD_Custom(Uint8 loc , Uint8 *msg)
{
	volatile Uint8 i=0;
	if(loc<8)
    LCD_Cmd(0x40 + (loc*8));
	for(i; i<8; i++) 
	{
		LCD_Char(msg[i]);
	} 
}

void LCD_StringPos(Sint8 * string , Uint8 line , Uint8 pos)
{
	switch(line){
		case 1:
		       LCD_Cmd(0x80 | (pos & 0x0F));
			   LCD_String(string);
		break;
		case 2:
		       LCD_Cmd(0xC0 | (pos & 0x0F));
		       LCD_String(string);
		break;
	}
}

void LCD_CharPos(Uint8 data , Uint8 line , Uint8 pos)
{
	switch(line){
		case 1:
		LCD_Cmd(0x80 | (pos & 0x0F));
		LCD_Char(data);
		break;
		case 2:
		LCD_Cmd(0xC0 | (pos & 0x0F));
		LCD_Char(data);
		break;
	}
}