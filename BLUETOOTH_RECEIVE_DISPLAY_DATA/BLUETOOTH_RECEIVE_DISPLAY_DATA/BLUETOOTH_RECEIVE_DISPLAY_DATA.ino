//===========================================================

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

const int xpin = A2;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis of the accelerometer
const int zpin = A0;                    // z-axis of the accelerometer

SoftwareSerial bluetooth(12, 13); // RX, TX --Bluetooth TX to pin12(RX) - crosspaired

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line

}

void loop()
{

  lcd.clear();
  lcd.print("Checking Data...");
  delay(200);

  //======Bluetooth receive ===================

  while (bluetooth.available())  //check if any data received in rx(Pin 0) pin from ESP8266-----
  {
    if (bluetooth.find("$"))
    {

      char d = bluetooth.read();
      lcd.clear();
      lcd.print(d);
      delay(3000);
      d = 0;
    }
  }
}
//========================================================
