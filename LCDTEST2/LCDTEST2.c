
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lcd_hd44780_avr.h"

int main(void)
{
	LCDInit(LS_NONE);
_delay_ms(50);
while(1){
	LCDWriteFString(PSTR("WELCOME TO"));
	_delay_ms(50);
LCDClear();
 
 LCDWriteFString(PSTR("Smart Parking System"));
	_delay_ms(50);
LCDClear();

	LCDWriteFStringXY(1,1,PSTR("By Sagar"));
	_delay_ms(50);
LCDClear();
}}
