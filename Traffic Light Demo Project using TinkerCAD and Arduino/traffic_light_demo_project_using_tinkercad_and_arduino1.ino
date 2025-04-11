// Define LED pins
const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 8;
const int buttonPin = 2;

// Variable to store button state
int buttonState = 0;

void setup() {
  // Set LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  // Set button pin as input
  pinMode(buttonPin, INPUT);
  
  // Start Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    // Red LED ON
    digitalWrite(redLED, HIGH);
    Serial.println("STOP - Red Light ON");
    delay(3000);
    digitalWrite(redLED, LOW);

    // Yellow LED ON
    digitalWrite(yellowLED, HIGH);
    Serial.println("READY - Yellow Light ON");
    delay(2000);
    digitalWrite(yellowLED, LOW);

    // Green LED ON
    digitalWrite(greenLED, HIGH);
    Serial.println("GO - Green Light ON");
    delay(3000);
    digitalWrite(greenLED, LOW);
  }
}