/*
 * UARTDriver.c
 *
 * Created: 21-04-2019 14:53:19
 *  Author: frederik
 */ 

 #include "../include/UARTDriver.h"
 #include <avr/io.h>

 #define Success 0
 #define Error  -1

 //TODO: Skal vi have asynkron kommunikation? De har jo ikke samme clock.

 void UARTSetup()
 {
	UCSR0B &= 0b11110111;
	UCSR0C = 0b00000110;

	UBRR0H = 0;
	UBRR0L = 103; //Default 9600 bps.
 }

 int8_t UARTTransmitByte(uint8_t byte)
 {
	if((UCSR0A & (1<<UDRE0)) != 0)
	{
		UDR0 = byte;

		return Success;
	}

	return Error;
 }