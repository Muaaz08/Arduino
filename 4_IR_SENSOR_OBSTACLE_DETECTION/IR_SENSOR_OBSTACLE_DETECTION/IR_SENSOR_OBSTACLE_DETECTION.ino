//===========================================================
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);
//===========================================================
const int irPin = 3; //Pin 3 connected to digital output of IR sensor
int pinNumber;
int irState = 0;
//===========================================================
void setup(){
  pinMode(irPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line
  delay(1000);
}
//===========================================================
void loop(){
  irState = digitalRead(irPin);    //Check for Obstacle Detection

  if (irState == HIGH)
  {
    lcd.clear();
    lcd.println("Obstacle Detected");   //Display this in first line
    Serial.println("Obstacle Detected");   //Send to Serial Monitor
    delay(1000);
  }

  if (irState == LOW)
  {
    lcd.clear();
    lcd.println("No Obstacle");   //Display this in first line
    Serial.println(" No Obstacle");
    delay(1000); //wait a sec 
  }

}
//========================================================
