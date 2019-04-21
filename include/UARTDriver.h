/*
 * UARTDriver.h
 *
 * Created: 21-04-2019 14:53:05
 *  Author: frederik
 */ 


#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_

#include <stdint.h>

void UARTSetup();
int8_t UARTTransmitByte(uint8_t byte);



#endif /* UARTDRIVER_H_ */