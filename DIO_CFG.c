/*
* DIO_CFG.c
*
* Created: 1/2/2021 12:38:37 PM
*  Author: DELL
*/

#include "DIO_CFG.h"

const DIO_PinCFG PinCFG[] = {
	//PORTA
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//PORTB
	{Input,STD_Low},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	//PORTC
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	//PORTD
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Input,STD_Low},
	{Output,STD_Low}
};

void DIO_Init(){
	Uint8 count = 0;
	DIO_PortTypes Portx;
	DIO_ChannelTypes ChannelPos;
	for(count=DIO_ChannelA0;count<PINCOUNT;count++){
		Portx = count/8;
		ChannelPos = count%8;
		switch(Portx){
			case DIO_PortA:
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRA_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRA_Reg,ChannelPos);
			}
			break;
			case DIO_PortB:
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRB_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRB_Reg,ChannelPos);
			}
			break;
			case DIO_PortC:
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRC_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRC_Reg,ChannelPos);
			}
			break;
			case DIO_PortD:
			if(PinCFG[count].ChannelDir == Output){
				SetBit(DDRD_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRD_Reg,ChannelPos);
			}
			break;	
		}
	}
}