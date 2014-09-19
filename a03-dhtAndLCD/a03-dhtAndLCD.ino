//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 4//put the sensor in the digital pin 4  

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
int flag=0;

void setup()
{
  //dht
  Serial.begin(9600);

  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}


void loop()
{
  //lcd.clear();
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case 0:
      Serial.print("OK,\t");
      // DISPLAT DATA
      Serial.print(DHT.humidity, 1);
      Serial.print(",\t");
      Serial.println(DHT.temperature, 1);

      lcd.setCursor(0, 0);
      lcd.print("RH:");
      lcd.setCursor(5, 0);
      lcd.print(DHT.humidity);

      lcd.setCursor(0, 1);
      lcd.print("TEMP:");
      lcd.setCursor(5, 1);
      lcd.print(DHT.temperature);
       break;
    case -1: Serial.print("Checksum error,\t"); break;
    case -2: Serial.print("Time out error,\t"); break;
    default: Serial.print("Unknown error,\t"); break;
  }
  if( chk != 0)
  {
    lcd.print("ERROR");
  }
   lcd.setCursor(19, 3);
   lcd.print( flag? ":":" ");
   flag = !flag;
  delay(1000);
}
