/*
* Ultrasonic.c
*
* Created: 1/31/2021 1:43:59 PM
* Author : Mohamed
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "DIO.h"
#include "LCD.h"
#include "Casters.h"

unsigned short OVF_Counter = 0; //	0 to 65535 = 65536 value

ISR(TIMER1_OVF_vect)
{
	OVF_Counter++;
}

int main(void)
{
	
	char data[10];
	long TIMER = 0;
	double distance = 0;
	DIO_Init();
	LCD_Init();
	sei(); //Enable Global Interrupt
	TCCR1A = 0; //Normal Mode
	TCCR1B |= (1<<CS10)|(1<<CS11)|(1<<ICES1); //PRESCALER = 64 , Select Positive-Edge
	TIMSK |= (1<<TOIE1); //Timer/Counter1, Overflow Interrupt Enable
	//_delay_ms(1000);
	while (1)
	{
		DIO_WriteChannel(DIO_ChannelD7,STD_High);
		_delay_us(10);
		DIO_WriteChannel(DIO_ChannelD7,STD_Low);
		TCNT1 = 0;	//Clear Timer Counter
		TIFR = 1<<ICF1;	// Clear ICP flag (Input Capture flag)
		TIFR = 1<<TOV1;	//Clear Timer Overflow flag
		while((TIFR & (1<<ICF1))==0); //Wait for Positive-Edge
		TCNT1 = 0; //Clear Timer Counter
		TCCR1B &= ~(1<<ICES1); //Select Negative-Edge
		TIFR = 1<<ICF1;	// Clear ICP flag (Input Capture flag)
		TIFR = 1<<TOV1;	//Clear Timer Overflow flag
		OVF_Counter = 0; //Clear Timer Overflow Counter
		while((TIFR & (1<<ICF1))==0);
		TIMER = ICR1  + (65536 * OVF_Counter);
		distance = (double)TIMER/14.575; // 58.30/4
                dtostrf(distance, 2, 2, data); //Convert double to string
		strcat(data, " cm   "); //concatenate the two strings and place new string into data
		LCD_StringPos("Ultrasonic",1,0);     
		LCD_StringPos("Dist = ",2,0);
		LCD_String(data);
	}
}

