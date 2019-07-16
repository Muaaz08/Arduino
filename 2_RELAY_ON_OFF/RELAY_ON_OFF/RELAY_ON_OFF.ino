//========================================================
const int relayPin1 = A4;  //A4 connected to Relay 1
const int relayPin2 = A5;   //A5 connected to Relay 2
//========================================================
void setup()
{
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  delay(3000);
}
//========================================================
void loop()
{
  digitalWrite(relayPin1, HIGH);
  delay(3000);
  digitalWrite(relayPin1, LOW);
  delay(3000);
  digitalWrite(relayPin2, HIGH);
  delay(3000);
  digitalWrite(relayPin2, LOW);
  delay(3000);
}
//========================================================
