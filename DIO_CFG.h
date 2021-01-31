/*
 * DIO_CFG.h
 *
 * Created: 1/2/2021 12:38:50 PM
 *  Author: DELL
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct{
	DIO_DirTypes ChannelDir;
	STD_LevelTypes level;
	}DIO_PinCFG;

#define PINCOUNT 32

void DIO_Init(void);

#endif /* DIO_CFG_H_ */