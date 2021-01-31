/*
* DIO.c
*
* Created: 1/2/2021 11:38:56 AM
*  Author: DELL
*/

#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes level){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		if (level == STD_High){
			SetBit(PORTA_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTA_Reg,ChannelPos);
		}
		break;
		case DIO_PortB:
		if (level == STD_High){
			SetBit(PORTB_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTB_Reg,ChannelPos);
		}
		break;
		case DIO_PortC:
		if (level == STD_High){
			SetBit(PORTC_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTC_Reg,ChannelPos);
		}
		break;
		case DIO_PortD:
		if (level == STD_High){
			SetBit(PORTD_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTD_Reg,ChannelPos);
		}
		break;
	}
}

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId){
	Uint8 data = 0xFF;
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		data = GetBit(PINA_Reg,ChannelPos);
		break;
		case DIO_PortB:
		data = GetBit(PINB_Reg,ChannelPos);
		break;
		case DIO_PortC:
		data = GetBit(PINC_Reg,ChannelPos);
		break;
		case DIO_PortD:
		data = GetBit(PIND_Reg,ChannelPos);
		break;
	}
	return data;
}

void DIO_ToggleChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		ToggleBit(PORTA_Reg,ChannelPos);
		break;
		case DIO_PortB:
		ToggleBit(PORTB_Reg,ChannelPos);
		break;
		case DIO_PortC:
		ToggleBit(PORTC_Reg,ChannelPos);
		break;
		case DIO_PortD:
		ToggleBit(PORTD_Reg,ChannelPos);
		break;
	}
}

void DIO_WritePort(DIO_PortTypes PortId,Uint8 data){
  switch(PortId)
  {
	  case DIO_PortA:
	  PORTA_Reg = data;
	  break;
	  case DIO_PortB:
	  PORTB_Reg = data;
	  break;
	  case DIO_PortC:
	  PORTC_Reg = data;
	  break;
      case DIO_PortD:
      PORTD_Reg = data;
	  break;
  }
}

Uint8 DIO_ReadPort(DIO_PortTypes PortId){
	Uint8 data = 0xFF;
	switch(PortId){
		case DIO_PortA:
		data = PORTA_Reg;
		break;
		case DIO_PortB:
		data = PORTB_Reg;
		break;
		case DIO_PortC:
		data = PORTC_Reg;
		break;
		case DIO_PortD:
		data = PORTD_Reg;
		break;
	}
	return data;
}
