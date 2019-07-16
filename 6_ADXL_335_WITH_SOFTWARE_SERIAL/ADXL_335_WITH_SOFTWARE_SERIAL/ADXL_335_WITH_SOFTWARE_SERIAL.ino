//===========================================================
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

const int xpin = A2;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis of the accelerometer
const int zpin = A0;                  // z-axis of the accelerometer
int x;
int y;
int z;

SoftwareSerial bluetooth(12, 13); // RX, TX --Bluetooth TX to pin12(RX) - crosspaired

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line
  delay(3000);
}

void loop(){
  x = analogRead(xpin);
  y = analogRead(ypin);
  z = analogRead(zpin);
  lcd.clear();
  // print the number of seconds since reset:
  lcd.print("X:");
  lcd.print(x);
  lcd.print("Y:");
  lcd.print(y);
  lcd.print("Z:");
  lcd.print(z);

  //================================
  bluetooth.print("X:");
  bluetooth.print(x);
  bluetooth.print("Y:");
  bluetooth.print(y);
  bluetooth.print("Z:");
  bluetooth.print(z);
  bluetooth.println();

  //=======================

  Serial.print("X:");
  Serial.print(x);
  Serial.print("Y:");
  Serial.print(y);
  Serial.print("Z:");
  Serial.print(z);
  Serial.println(z);

delay(800);
}
//========================================================
