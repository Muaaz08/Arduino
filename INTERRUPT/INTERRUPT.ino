
/*ARDUIO_I0T_DEVELOPMENT KIT__ SAMPLE PROGRAM_RELAY_CONTROLS_DIGITAL_I/O_ -- version 1.2
  -- www.techgraylogix.com */
//===========================================================

#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

const int ledPin = 13;  //A4 connected to Relay 1

volatile int ledState = 0;
int states = 0;

const int s1 = 2;

void setup()
{
  pinMode(s1,INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  //pinMode(relay2Pin, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line
  delay(3000);

  attachInterrupt(digitalPinToInterrupt(2),bl,LOW);
}

void loop()
{
//  states = digitalRead(s1);
//
//  lcd.clear();
//  lcd.print("LOOP");
//  Serial.println(states);
//  lcd.clear();
 
  digitalWrite(13,0);  
  //digitalWrite(13,ledState);
  delay(10000);
}

void bl(){
//  lcd.clear();
//  lcd.print("ISR");
  //ledState = !ledState;
  digitalWrite(13,1);
}
//========================================================
