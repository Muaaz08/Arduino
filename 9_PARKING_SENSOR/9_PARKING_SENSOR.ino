//Ultrasonics based parking assistance system

#define echoPin 9 // Echo Pin
#define trigPin 8 // Trigger Pin
#include <LiquidCrystal.h>

const int freq = 800;
const int dur = 20;
const int buzzer = 10;

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {

 lcd.begin(16, 2);
 lcd.clear();
 lcd.print("  ULTRASONIC ");
 lcd.setCursor(0, 1);
 lcd.print(" DISTANCEMETER");
   
 pinMode(buzzer, OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 digitalWrite(buzzer, LOW);
  
 delay(2000);

 tone(buzzer, freq, duration);
}

void loop() {

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;

  lcd.clear();
 lcd.print("Distance: ");
 lcd.print(distance);
 lcd.print(" cms");
 
  if(distance < 3){
   tone(buzzer, freq, dur);
  // digitalWrite(buzzer, HIGH);
   delay(15);
 }
 else if(distance < 5){
   tone(buzzer, freq, dur);
   delay(25);
 }
 
 else if(distance < 7){
   tone(buzzer, freq, dur);
   delay(50);
 } else if (distance < 15){
   tone(buzzer, freq, dur);
   delay(100);
 } else if (distance < 20){
   tone(buzzer, freq, dur);
   delay(150);
 } else if (distance < 25){
   tone(buzzer, freq, dur);
   delay(200);
 } else if (distance < 30){
   tone(buzzer, freq, dur);
   delay(250);
 } else if (distance < 35){
   tone(buzzer, freq, dur);
   delay(300);
 } else if (distance < 40){
   tone(buzzer, freq, dur);
   delay(350);
 } else if (distance < 45){
   tone(buzzer, freq, dur);
   delay(400);
 } else if (distance < 50){
   tone(buzzer, freq, dur);
   delay(450);
 } else if (distance < 55){
   tone(buzzer, freq, dur);
   delay(500);
 } 

 delay(200);
}
