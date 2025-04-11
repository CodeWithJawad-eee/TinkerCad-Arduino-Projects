int potPin = A0;
int LEDPin = 10;
int readValue;
int writeValue;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(potPin);
  writeValue = map(readValue, 0, 1023, 0, 255); // Correct scaling
  analogWrite(LEDPin, writeValue);
  
  Serial.print("You are writing a value of ");
  Serial.println(writeValue);
}
