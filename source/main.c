/*
 * AMSproject.c
 *
 * Created: 14-Mar-19 8:50:37 AM
 * Author : fenta
 */ 

#include <avr/io.h>
#include "../include/UARTDriver.h"

int main(void)
{
    /* Replace with your application code */

	UARTSetup();

	uint8_t msg1 = 'S';

	UARTTransmitByte(msg1);

	uint8_t msg2 = '\0';

	UARTTransmitByte(msg2);

	UARTTransmitByte(msg1);

    while (1) 
    {
    }
}

