
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

//The TMP102 has 4 addresses. 
struct tmp102 {
	uint8_t address;
	tmp102(uint8_t addr) {
		address = addr;
	}
}

static void tmp102Init() {
	i2cInit();
}

static void writePointerRegister(uint8_t pointerReg) {
	i2cStart();
	i2cWrite(address);
	i2cWrite(pointerReg);
	i2cStop();
}

uint8_t readPointerRegister(int registerByte_) {
	i2cReceive(uint8_t registerByte[2], 2);

	return registerByte[registerByte_]
}

float readTemp() {
	uint8_t readByte[2];
	int16_t digitalTemp;

	writePointerRegister(TEMP_REGISTER); //Write to the Pointer Register with the Temperature address
	readByte[0] = readPointerRegister(0);
	readByte[1] = readPointerRegister(1);

	//Check for 13 bit mode
	if(readByte[1] & 0x01) {

	}


	return digitalTemp*0.0625


}