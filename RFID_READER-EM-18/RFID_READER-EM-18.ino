/*
  ===========================
    RFID Reader ( EM-18 )
  ===========================
      VCC - 5V
      GND - GND
      Tx  - Rx 
  ===========================
*/

int count = 0;
int inc = 0;
int i;
char input[12];

char card1[12] = {"1E0031A6B23B"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9660);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    count = 0;
    while (Serial.available() && count < 12) {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    Serial.println(input);
    delay(10);
    for (i = 0; i < 12; i++) {
      if (input[i] == card1[i] ) {
        inc++;
        if (inc == 12) {
          Serial.println("OK");
          inc = 0;
        }
      }
      // here add other cards using elseif
    }
  }
}
