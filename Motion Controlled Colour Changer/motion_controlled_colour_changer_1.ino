#define PIR_SENSOR 7
#define BUZZER 3
#define RED_LED 9
#define GREEN_LED 11
#define BLUE_LED 10

void setup() {
    pinMode(PIR_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
    int motion = digitalRead(PIR_SENSOR);
    
    if (motion == HIGH) { // Motion detected
        Serial.println("Motion Detected!");
        digitalWrite(BUZZER, HIGH);
        digitalWrite(RED_LED, HIGH);  // Red color to indicate alert
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        delay(1000); // Keep the buzzer on for a second
    } else {
        Serial.println("No Motion");
        digitalWrite(BUZZER, LOW);
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH); // Green color for no motion
        digitalWrite(BLUE_LED, LOW);
    }
    delay(500);
}
