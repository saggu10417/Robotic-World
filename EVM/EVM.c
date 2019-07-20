#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lcd_hd44780_avr.h"

int main(void)
{
DDRA=0x0f;
DDRD=0x00;
int i,j,k,l;
LCDInit(LS_NONE);
_delay_ms(50);
LCDClear();
LCDWriteFStringXY(2,0,PSTR("ELECTRONIC"));
LCDWriteFStringXY(0,1,PSTR("VOTING MACHINE"));
_delay_ms(50);
LCDClear();
while(1)
{
if(PIND==0b00010000)//TOGGLE MASTER
{
LCDClear();
LCDWriteFStringXY(4,0,PSTR("WELCOME"));
	
PORTA=0b00000001;
_delay_ms(20);
if(PIND==0b00010001) //A SELECTION
{
PORTA=0b00000010;
LCDWriteFStringXY(0,0,PSTR("YOU CHOSE A"));
_delay_ms(500);
i++;
}
if(PIND==0b00010010)//B SELECTION
{
PORTA=0b00000010;
LCDWriteFStringXY(0,0,PSTR("YOU CHOSE B"));
_delay_ms(20);
j++;
}
if(PIND==0b00010100) //C SELECTION
{
PORTA=0b00000010;
LCDWriteFStringXY(0,0,PSTR("YOU CHOSE C"));
_delay_ms(20);
k++;
}
if(PIND==0b00011000) //D SELECTION
{
PORTA=0b00000010;
LCDWriteFStringXY(0,0,PSTR("YOU CHOSE D"));
_delay_ms(20);
l++;
}
}
if(PIND==0b00100000)
{
LCDClear();
LCDWriteFStringXY(0,0,PSTR("A="));
LCDWriteIntXY(2,0,i,3);
LCDWriteFStringXY(9,0,PSTR("B="));
LCDWriteIntXY(11,0,j,3);
LCDWriteFStringXY(0,1,PSTR("C="));
LCDWriteIntXY(2,1,k,3);
LCDWriteFStringXY(9,1,PSTR("D="));
LCDWriteIntXY(11,1,l,3);
_delay_ms(20);
}

}}
