#include<avr/io.h>
#include<util/delay.h>
void main()
{
int i=0;
DDRB=0xfe;
DDRA=0xff;
PORTA=0b10000000;
while(1)
{
if(PINB==0b00000001)
{
i++;
_delay_ms(50);
}
if(i==1)
{
PORTA=0b11110010;
}
if(i==2)
{
PORTA=0b01001000;
}
if(i==3)
{
PORTA=0b01100000;
}
if(i==4)
{
PORTA=0b00110010;
}
if(i==5)
{
PORTA=0b00100100;
}
if(i==6)
{
PORTA=0b00000100;
}
if(i==7)
{
PORTA=0b11110000;
}
if(i==8)
{
PORTA=0b00000000;
}
if(i==9)
{
PORTA=0b10000000;
}
}
}