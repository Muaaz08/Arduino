//===========================================================

//3. If obstacle is detected, a message will be displayed in the LCD +   Data will be sent through Wi-Fi
//4. Relays can be controlled through Wi-Fi and Bluetooth connected Smart devices by sending commands $1, $2, $3, $4, $5, $6

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define DEBUG true

LiquidCrystal lcd(10, 11, 4, 5, 6, 7);

SoftwareSerial esp8266(8, 9); // RX, TX --ESP8266 TX to pin8(RX) - crosspaired

const int irPin = 3; //Pin 3 connected to digital output of IR sensor
int pinNumber;
int irState = 0;

const int relay1Pin = A4;  //A4 connected to Relay 1
const int relay2Pin = A5;   //A5 connected to Relay 1

int relay1State = 0;
int relay2State = 0;

int count = 0;

void setup()
{
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(irPin, INPUT);
  relay1State = LOW;
  relay2State = LOW;
  digitalWrite(relay1Pin, relay1State);
  digitalWrite(relay2Pin, relay2State);
  Serial.begin(9600);
  esp8266.begin(9600);

  lcd.begin(16, 2);
  lcd.print(" Arduino - IoT");  //Display this in first line
  lcd.setCursor(0, 1);
  lcd.print("Development Kit");   //Display this in second line

  sendData("AT+RST\r\n", 2000, DEBUG); // reset module
  delay(3000);
  sendData("AT+CWMODE=2\r\n", 1000, DEBUG); // configure as access point
  delay(1000);
  sendData("AT+CIPMODE=0\r\n", 1000, DEBUG); // configure as access point
  delay(1000);
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG); // configure for multiple connections
  delay(1000);
  sendData("AT+CIFSR\r\n", 1000, DEBUG); // get ip address
  delay(1000);
  sendData("AT+CIPSERVER=1,81\r\n", 1000, DEBUG); // turn on server on port 80
  delay(2000);

  lcd.clear();
  lcd.print(" Initializing  ");
  lcd.setCursor(0, 1);
  lcd.print("    Over");
  delay(1000);
  lcd.clear();
  lcd.print("System Ready");
  delay(1000);
}

void loop()
{
  //==============Wi-Fi receiving relay controls----------------------------
  
  while (esp8266.available())  //check if any data received in rx(Pin 0) pin from ESP8266-----
  {
    if (esp8266.find("$"))
    {

      char c = esp8266.read();
      if (c == '1')
      {
        relay1State = HIGH;
        digitalWrite(relay1Pin, relay1State);   //switch ON relay 1
        c = 0;
      }
      if (c == '2')
      {
        relay1State = LOW;
        digitalWrite(relay1Pin, relay1State);    //switch OFF relay 1
        c = 0;
      }
      if (c == '3')
      {
        relay2State = HIGH;
        digitalWrite(relay2Pin, relay2State);   //switch ON relay 2
        c = 0;
      }
      if (c == '4')
      {
        relay2State = LOW;
        digitalWrite(relay2Pin, relay2State);    //switch OFF relay 2
        c = 0;
      }
      if (c == '5')
      {
        relay1State = HIGH;
        digitalWrite(relay1Pin, relay1State);
        delay(200);
        relay2State = HIGH;
        digitalWrite(relay2Pin, relay2State);   //switch ON relay 1 and relay 2
        c = 0;
      }

      if (c == '6')
      {
        relay1State = LOW;
        digitalWrite(relay1Pin, relay1State);
        relay2State = LOW;
        digitalWrite(relay2Pin, relay2State);   //switch OFF relay 1 and relay 2
        c = 0;
      }
    }



  }



  //==============================================================


  irState = digitalRead(irPin);    //Check for Obstacle Detection----

  if (irState == HIGH)
  {
    lcd.clear();
    lcd.println("Obstacle Detected");   //Display this in first line
   delay(100);
esp8266.begin(9600);
      delay(100);
    sendData("AT+CIPSEND=0,17\r\n", 1000, DEBUG);
    delay(100);
    sendData("Obstacle Detected", 1000, DEBUG); //Send to Wi-Fi---
    delay(1000);
  }
}
//========================================================


String sendData(String command, const int timeout, boolean debug)
{

  String response = "";
  esp8266.print(command); // send the read character to the esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (esp8266.available())
    {
      // The esp has data so display its output to the serial window
      char c = esp8266.read(); // read the next character.
      response += c;
    }
  }

  return response;
}
