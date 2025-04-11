#include <Servo.h>

Servo myservo;
#define trigpin 2
#define echopin 3

float duration, distance;

void setup() {
  myservo.attach(8);
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  // Ultrasonic Sensor Trigger
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  // Measuring Echo Duration
  duration = pulseIn(echopin, HIGH);
  
  // Converting time to distance
  distance = (duration / 2) * 0.034; // Speed of sound = 343 m/s = 0.034 cm/µs

  Serial.print("Distance: ");

  // Checking if object is within range
  if (distance > 4 || distance < 2) {  // Changed condition
    Serial.println("Out of range");
    myservo.detach();
  } else {
    myservo.attach(8);
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);

    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }

  delay(500);
  myservo.detach();
}
