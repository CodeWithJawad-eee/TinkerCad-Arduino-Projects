#define PB0 0
#define PB2 2

float realDegree = 0.0;

void setup() {
  pinMode(PB0, OUTPUT);
  pinMode(PB2, INPUT);
  realDegree = 0.0;
}

void loop() {
  int degree = analogRead(PB2);
  realDegree = (degree / 1024.0) * 5.0;
  float temperatureC = realDegree * 100;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  if (temperatureC < 20) {
    digitalWrite(PB0, LOW); // Turn off LED
  } 
  else if (temperatureC >= 20 && temperatureC < 30) {
    digitalWrite(PB0, HIGH);
    delay(1000);
    digitalWrite(PB0, LOW);
    delay(1000); // Blink slowly
  } 
  else if (temperatureC >= 30 && temperatureC < 40) {
    digitalWrite(PB0, HIGH);
    delay(500);
    digitalWrite(PB0, LOW);
    delay(500); // Blink fast
  } 
  else {
    digitalWrite(PB0, HIGH); // LED remains steady
  }
}
