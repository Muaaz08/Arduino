// X, Y Z values of Accelerometer are displayed in the LCD
//===========================================================
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

const int xpin = A2;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis of the accelerometer
const int zpin = A0;                  // z-axis of the accelerometer

int x;
int y;
int z;
//========================================================
void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line
  delay(1000);
}//========================================================
void loop(){
  x = analogRead(xpin);
  y = analogRead(ypin);
  z = analogRead(zpin);
  lcd.clear();
  lcd.print("X:");
  lcd.print(x);
  lcd.print("Y:");
  lcd.print(y);
  lcd.print("Z:");
  lcd.print(z);
  delay(400);

}
//========================================================
