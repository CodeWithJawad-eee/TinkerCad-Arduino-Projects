// C++ code
//

int ledPin=12;
void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  for(int i=0;i<=255;i++)
  {
    analogWrite(ledPin,i);
    delay(20);
  }
  for(int i=255;i>=0;i--)
  {
    analogWrite(ledPin,i);
    delay(20);
  }
  delay(200);
}