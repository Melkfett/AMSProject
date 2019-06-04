/*
 * temperatureModule.c
 *
 * Created: 03-Jun-19 1:43:01 PM
 *  Author: fenta
 */ 
#include <stdint.h>
#include <stdlib.h>
#include "../include/temperatureModule.h"
#include "../include/tmp102drv.h"
#include "../include/UARTDriver.h"

void runTemperatureModule()
{
	int16_t temp = 0;
		
	char buffer[16] = "Temperature: ";
	temp = readTemp();
	uint8_t i = 0;
		
		
		
	itoa((int)temp, buffer+14, 10);
		
	for(i = 0; i<16; i++)
	{
		UARTTransmitByte(buffer[i]);
	}
	UARTTransmitByte('\n');
}