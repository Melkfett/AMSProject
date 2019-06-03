/*
 * lm75.c
 *
 * Created: 28-04-2015 11:53:56
 *  Author: hh
 */ 

#include "../include/i2c.h"

#define LM75_BASE_ADDRESS 0b01001000
#define READ_MASK         0b00000001

// Reads the temperature register from specified sensor
// SensorAddress is between 0 and 7
int LM75_temperature(unsigned char SensorAddress)
{
	int temperature;

	i2c_start();
	i2c_write(((LM75_BASE_ADDRESS + SensorAddress)<<1) | READ_MASK);
	// Read temperature high byte and ACK
    temperature = i2c_read(0);
	// Shift data to high byte
	temperature = temperature << 8 ;
	// Read temperature low byte and NACK
	// Merge to temperature variable
	temperature = temperature + i2c_read(1);
	i2c_stop();
	// Return right adjusted data (see LM75 data sheet)
	return (temperature>>7);
}