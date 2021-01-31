/*
 * LCD.h
 *
 * Created: 1/8/2021 10:20:01 AM
 *  Author: Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCDPort DIO_PortA 

#define RS DIO_ChannelB1
#define RW DIO_ChannelB2
#define E DIO_ChannelB3 

#define CLR 0x01
#define D1C1 0x0E
#define D0C0 0x08 
#define D1C0 0x0C   
#define SEDR 0x1C
#define SEDL 0x18
#define CL 0x10
#define CR 0x14
#define Move_Cursor_R 0x14
#define Move_Cursor_L 0x10

void LCD_Init();
void LCD_Cmd(Uint8 cmd);
void LCD_Char(Uint8 data);
void LCD_String(Sint8 * string);
void LCD_Custom(Uint8 loc , Uint8 *msg);
void LCD_CharCalc(Uint8 data);
void LCD_StringPos(Sint8 * string , Uint8 line , Uint8 pos);
void LCD_CharPos(Uint8 data , Uint8 line , Uint8 pos);
void LCD_CharCalc(Uint8 data);

#endif /* LCD_H_ */