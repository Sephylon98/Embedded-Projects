/*
 * DIO.h
 *
 * Created: 1/2/2021 11:38:46 AM
 *  Author: DELL
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId);
void DIO_ToggleChannel(DIO_ChannelTypes ChannelId);
Uint8 DIO_ReadPort(DIO_PortTypes PortId);
void DIO_WritePort(DIO_PortTypes PortId,Uint8 data);

#endif /* DIO_H_ */