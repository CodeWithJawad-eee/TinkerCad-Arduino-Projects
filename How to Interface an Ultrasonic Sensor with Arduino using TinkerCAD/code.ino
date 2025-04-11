// C++ code
//

int trigPin=9;
  int echoPin=11;
  long time;
  int distance;

void setup()
{
  pinMode(9,OUTPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Wait for 1000 millisecond(s)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Wait for 1000 millisecond(s)
  
  
  time=pulseIn(echoPin,HIGH);
  distance=(0.03*time)/2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
  }