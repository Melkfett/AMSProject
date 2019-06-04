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
 #define XTAL 16000000

 void UARTSetup()
 {
	UCSR0A = 0b00100000;
	UCSR0B = 0b00011000;
	UCSR0C = 0b00000110;

	UBRR0 = 103;
 }

 int8_t UARTTransmitByte(uint8_t byte)
 {
	while((UCSR0A & (1<<UDRE0)) == 0);

	UDR0 = byte;

	return Success;
 }