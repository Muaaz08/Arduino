/*
  ==============================
        Servo Motor (SG90)
  ==============================
    Red wire(VCC)       - 5V
    Brown wire(GND)     - GND
    Orange Wire(Signal) - D2
  ==============================
*/
#include<Servo.h>

Servo servo;        //initialize a servo object for the connected servo

#define servoPin 2

int angle = 0;

void setup()
{
  servo.attach(servoPin);      // attach the signal  of servo to 9 of arduino
}

void loop()
{
  for (angle = 0; angle < 180; angle += 1)   // command to move from 0 degrees to 180 degrees
  {
    servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);
  }

  delay(1000);

  for (angle = 180; angle >= 1; angle -= 3) // command to move from 180 degrees to 0 degrees
  {
    servo.write(angle);              //command to rotate the servo to the specified angle
    delay(10);
  }

  delay(1000);
}
