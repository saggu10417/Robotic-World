#include<avr/io.h>
#include<util/delay.h>
void main()
{
int i=0;
DDRC=0xff;
DDRA=0b00110011;
PORTA=0b10000000;
while(1)
{
if(PINA==0b00000100)
{
i++;
_delay_ms(50);


PORTA=0B00000001;
_delay_ms(100);
PORTA=0B00000000;
}
if(PINA==0b00001000)
{


PORTA=0B00000010;
_delay_ms(100);
PORTA=0B00000000;


}
if(PINA==0b01000000)
{


PORTA=0B00010000;
_delay_ms(100);
PORTA=0B00000000;


}




else if(PINA==0b10000000)
{
i--;
_delay_ms(50);

PORTA=0B00100000;
_delay_ms(100);
PORTA=0B00000000;
}
if(i==1)
{
PORTC=0b11110010;
}
if(i==2)
{
PORTC=0b01001000;
}
if(i==3)
{
PORTC=0b01100000;
}
if(i==4)
{
PORTC=0b00110010;
}
if(i==5)
{
PORTC=0b00100100;
}
if(i==6)
{
PORTC=0b00000100;
}
if(i==7)
{
PORTC=0b11110000;
}
if(i==8)
{
PORTC=0b00000000;
}
if(i==9)
{
PORTC=0b10000000;
}
}
}
