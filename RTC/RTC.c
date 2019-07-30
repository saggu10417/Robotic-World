#include <Wire.h>
#include RTClib.h
#include <LiquidCrystal_I2C.h>
RTC_DS1307 RTC;
LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setup () 
{
    Serial.begin(9600);
    Wire.begin();
    pinMode(22,OUTPUT);
    RTC.begin();

    if (! RTC.isrunning()) 
    {
       Serial.println("RTC is NOT running!");
       RTC.adjust(DateTime(__DATE__,__TIME__));
    }

    RTC.adjust(DateTime(__DATE__,__TIME__));   // remove it after upload first time then again upload without this line.
    lcd.begin();
    lcd.backlight();
    digitalWrite(22,HIGH);                    
    lcd.setCursor(0,1);
    lcd.print("Ready ......");
}

void loop () {
    DateTime now = RTC.now(); 
    lcd.setCursor(0,0);
    lcd.print(now.day());

    lcd.setCursor(2,0);
    lcd.print("-");

    lcd.setCursor(3,0);
    lcd.print(now.month());

    lcd.setCursor(5,0);
    lcd.print("-");

    lcd.setCursor(6,0);
    lcd.print(now.year());

    lcd.setCursor(11,0);
    lcd.print("     ");

    lcd.setCursor(11,0);
    lcd.print(now.hour());

    lcd.setCursor(13,0);
    lcd.print(":");

    lcd.setCursor(14,0);
    lcd.print(now.minute());

    if (now.hour()==9)
    {
      if (now.minute()==0)
      {
         if (now.second()<5)
         {
            digitalWrite(22,LOW);          
            lcd.setCursor(0,1);
            lcd.print("Watering....");
         }
         else
         {
            digitalWrite(22,HIGH);                    
            lcd.setCursor(0,1);
            lcd.print("Ready ......");
         }
      }
    }
    if (now.hour()==17)
    {
      if (now.minute()==0)
      {
         if (now.second()<5)
         {
            digitalWrite(22,LOW);          
            lcd.setCursor(0,1);
            lcd.print("Watering....");
         }
         else
         {
            digitalWrite(22,HIGH);                    
            lcd.setCursor(0,1);
            lcd.print("Ready ......");
         }
      }
    }
    delay(1000);
}
