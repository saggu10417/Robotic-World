/******************************************************************************

Title:
	ATmega8 Based Smart Code Lock.

Description:
	A simple project for making a digital code lock. The main input device is
	a 4x4 Matrix Keypad. The main output is a 16x2 LCD Module.

	The user has to enter a correct password to gain access. On receipt of
	correct password the relay is energised, which can be used to operate
	and device like an electronic door.

	Their is facility for changing password. 


******************************************************************************/

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#include "lcd.h"
#include "keypad.h"
#include "user_interface.h"
#include "password_manager.h"


//LCD Backlight i/o configuration
#define LCDBL_PORT 	PORB
#define LCDBL_DDR	DDRB
#define	LCDBL_PIN	PB1

//Output relay i/o configuration
#define RELAY_PORT 	PORTC
#define RELAY_DDR 	DDRC
#define RELAY_PIN 	PC0


//Simple Delay Function
void Wait(uint8_t n);

//Relay Control Functions
void RelayOn();
void RelayOff();

//System Functions
void SystemInit();

void main()
{
 	uint16_t password;

	//Initialize the system
	SystemInit();

	while(1)
	{
		password=InputNumber("Enter Password");

		//Match Password
		if(password==ReadPassFromEEPROM())
		{
			LCDClear();
			LCDWriteString("Access Granted");
			
			//Now Activate Relay
			RelayOn();

			Wait(15);

			LCDClear();
			LCDWriteString("Press Any Key");

			//Now wait for any key
			while(GetKeyPressed()==255)
			{
				_delay_loop_2(10);
			}

			//Now DeActivate Relay
			RelayOff();

			Wait(2);

		}
		else if(password==0)
		{
			/*
			
			If user enters 0000 as password it
			indicates a request to change password
			
			*/
			LCDClear();
			password=InputNumber("Old Password");

			if(password==ReadPassFromEEPROM())
			{
				//Allowed to change password
				uint16_t NewPassword;
				NewPassword=InputNumber("New Password");
				WritePassToEEPROM(NewPassword);

				LCDClear();
				LCDWriteString("Success !");

				Wait(15);
			}
			else
			{
				//Not Allowed to change password
				LCDClear();
				LCDWriteString("Wrong Password !");

				Wait(15);
				
			}
		}			
		else
		{
			LCDClear();
			LCDWriteString("Access Denied");
			RelayOff();

			Wait(15);
		}
		
						
	}
						
		
	
}

void SystemInit()
{
	//Set LCD Backlight Pin as output
	LCDBL_DDR|=(1<<LCDBL_PIN);

	//Set Relay Pin as output
	RELAY_DDR|=(1<<RELAY_PIN);

  	//Wait for LCD To Start
   	_delay_loop_2(0);

   	//Now initialize the lcd module
	LCDInit(LS_NONE);
	LCDClear();
	LCDBacklightOn();
	LCDWriteString("SMART DOOR LOCK");
	Wait(5);
	LCDClear();
    LCDWriteString("DESIGNED BY");
	Wait(5);
	LCDClear();
    LCDWriteString("SAGAR KANSAL");
	Wait(5);
	LCDClear();
	

	//Check if the EEPROM has a valid password or is blank
	if(ReadPassFromEEPROM()==25755)
	{
		//Password is blank so store a default password
		WritePassToEEPROM(5555);
	}

}

void Wait(uint8_t n)
{
	uint8_t i;
	for(i=0;i<n;i++)
		_delay_loop_2(0);
}
void RelayOn()
{
	RELAY_PORT|=(1<<RELAY_PIN);
}

void RelayOff()
{
	RELAY_PORT&=(~(1<<RELAY_PIN));
}
