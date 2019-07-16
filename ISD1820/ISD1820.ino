/*
 =========================
  Voice Recorder (ISD1820)
 =========================
    VCC    -  5V
    GND    -  GND 
    REC    -  D8
    PLAY   -  D9
    SENSOR -  D3
 =========================
*/
#define rec  8
#define play 9
#define sensor 3

void setup() {
  // put your setup code here, to run once:
  pinMode(rec, OUTPUT);
  pinMode(play, OUTPUT);
  pinMode(sensor, INPUT);

  digitalWrite(rec, LOW);
  digitalWrite(play, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(sensor)) {
    digitalWrite(rec, HIGH);
    delay(5000);
    digitalWrite(rec, LOW);
    delay(1000);
    digitalWrite(play,HIGH);
    delay(6000);
    digitalWrite(play,LOW);
  }
}
