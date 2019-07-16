//========================================================
//       LCD CHARACTER DISPLAY
//===========================================================
//    rs     -  D10
//    en     -  D11
//    LCD d4 -  D4
//    LCD d5 -  D5
//    LCD d6 -  D6
//    LCD d7 -  D7
//========================================================
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);
//========================================================
void setup() {
  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line
  delay(4000);
}
//========================================================
void loop() {
  lcd.clear();
  lcd.print(" Arduino Development Kit");  //Display this in first line

  for (int scrollCounter = 0; scrollCounter < 24; scrollCounter++) {
    lcd.scrollDisplayLeft();
    delay(800);
  }
}
//========================================================
