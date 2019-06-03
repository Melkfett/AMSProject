
/*
 * tmp102.c
 *
 * Created: 07-04-2019 12:13:42
 *  Author: Anton
 */

#include "../include/i2cDriver.h"
#include "../include/tmp102drv.h"

#define F_CPU 16000000

#define TEMP_REGISTER  0x0
#define CONFIG_REGISTER 0x1
#define T_LOW_REGISTER 0x2
#define T_HIGH_REGISTER 0x3
#define READ 1
#define WRITE 0

static uint8_t address = 0b10010000;

void writePointerRegister(uint8_t pointerReg) {
	i2cStart();
	i2cWrite(address+WRITE);
	i2cWrite(pointerReg);
	i2cStop();
	
}

void readPointerRegister(uint8_t* registerByte) {
	
	uint8_t* temp = registerByte;
	
	i2cStart();
	i2cWrite(address+READ);
	i2cReceive(temp, 2);
	i2cStop();
}

float readTemp(){
	uint8_t readByte[2];
	int16_t digitalTemp;

	writePointerRegister(TEMP_REGISTER); //Write to the Pointer Register with the Temperature address
	readPointerRegister(readByte); //Receive temperature in two bytes

	
	// //Check for 13 bit mode
	// if(readByte[1] & 0x01) {

	// }

	digitalTemp = ((uint16_t)(readByte[0] << 8) | (readByte[1])); //Bitshifting because the received bytes are not formatted as digital temperature
	digitalTemp = (digitalTemp>>4);
	if(digitalTemp > 0x7FF) { //Check if temperature is negative
		digitalTemp |= 0xF000;
		digitalTemp = digitalTemp+1;
	}


	return digitalTemp*0.0625;


}