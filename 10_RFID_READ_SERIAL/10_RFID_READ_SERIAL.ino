#define DEBUG true

char i;
char j;
String card;
String card1;
int count = 0;
int count1 = 0;
char c;
int cardstatus = 0;



void setup()
{
  Serial.begin(9600);
}

void loop()
{

label0:
  //=========================================
  if (Serial.available() > 0)
  {
    delay(300);
label2:
    i = Serial.read();
    delay(50);
    card = card + i;
    delay(50);
    count++;
    delay(50);
    if (count == 12)
    {
      count = 0;
      Serial.println(card);
      delay(100);
      goto checkrfid;
    }
    goto label2;
  }
  goto label0;

checkrfid:

  if (card == "1E0034DFB643")
  {

    card = "";
    Serial.flush();
    delay(1000);
    goto label0;
  }


  if (card == "1E00352A4544")
  {
    card = "";
    Serial.flush();
    delay(1000);
    goto label0;
  }



}
