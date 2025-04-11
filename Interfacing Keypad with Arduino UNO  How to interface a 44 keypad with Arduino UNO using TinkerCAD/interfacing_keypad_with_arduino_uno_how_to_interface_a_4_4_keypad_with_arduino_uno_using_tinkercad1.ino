#include<Keypad.h>

const byte row=4;
const byte col=4;

char keys[row][col]
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[row]={11,10,9,8};
byte colPins[col]={7,6,5,4};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,row,col);

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  char key=keypad.getKey();
  if(key)
  {
    Serial.print("Key pressed: ");
    Serial.println(key);
  }
}