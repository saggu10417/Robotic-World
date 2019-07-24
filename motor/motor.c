#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB = 0b00001111;
while(1)
{
PORTB=0b00000101; //For Forward
_delay_ms(100);
PORTB=0b00001111;
_delay_ms(10);
PORTB=0b00001010; //For Backward
_delay_ms(100);
PORTB=0b00001111;
_delay_ms(10);
PORTB=0b00001001; //For Right Turn
_delay_ms(100);
PORTB=0b00001111;
_delay_ms(10);
PORTB=0b00000110; //For Left Turn
_delay_ms(100);
PORTB=0b00001111;
_delay_ms(10);
}}
