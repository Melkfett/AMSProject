/*
 * GccApplication1.c
 *
 * Created: 07-Feb-19 9:25:25 AM
 * Author : fenta
 */ 

#include <avr/io.h>
#include <avr/cpufunc.h>
#include "lcd162.h"

int main(void)
{
    /* Replace with your application code */
	
	LCDInit();

    while (1)
    {
			uint64_t i2;
			char test = '1';
			for(i2 = 0; i2 < 100000; i2++)
				_NOP();
				
			LCDDispChar(test);
			LCDDispChar(test);
			LCDDispChar(test);
			for(i2 = 0; i2 < 100000; i2++)
				_NOP();
				
			//LCDClear();
    }
}

