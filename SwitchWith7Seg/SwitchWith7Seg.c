#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=0x00;
DDRA=0xff;
while(1)
{
if(PINB==0b00000001)
{
PORTA=0b11110010;
_delay_ms(5);
}
else if(PINB==0b00000010)
{
PORTA=0b01001000;
_delay_ms(5);
}
else if(PINB==0b00000100)
{
PORTA=0b01100000;
_delay_ms(5);
}
else if(PINB==0b00001000)
{
PORTA=0b00110010;
_delay_ms(5);
}
else if(PINB==0b00010000)
{
PORTA=0b00100100;
_delay_ms(5);
}
else if(PINB==0b00100000)
{
PORTA=0b00000100;
_delay_ms(5);
}
else if(PINB==0b01000000)
{
PORTA=0b11110000;
_delay_ms(5);
}
else if(PINB==0b10000000)
{
PORTA=0b00000000;
_delay_ms(5);
}
else
{
PORTA=0b10000000;
}
}}
