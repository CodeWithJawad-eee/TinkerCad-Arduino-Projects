// C++ code
//
float temp;
float vout;
float vout1;
int led = 11;
int gasSensor;
int piezo = 7;

void setup()
{
  	pinMode(A0, INPUT);  // Gas sensor pin
    pinMode(A1, INPUT);  // Temperature sensor pin
    pinMode(led,OUTPUT); 
    pinMode(piezo,OUTPUT);
    Serial.begin(9600); // Start serial communication
}

void loop()
{
  // Read temperature sensor
    vout = analogRead(A1);  
    vout1 = (vout / 1023.0) * 5000.0;  // Convert to millivolts
    temp = (vout1 - 500) / 10.0;  // Convert to Celsius

    // Read gas sensor value
    gasSensor = analogRead(A0);

    // Debugging: Print sensor values
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C");

    Serial.print("Gas Sensor Value: ");
    Serial.println(gasSensor);

    // Fire detection condition
    if (temp >= 80) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }

    // If temperature is dangerously high, activate buzzer
    if (temp >= 100) {
        digitalWrite(piezo, HIGH);
    } else {
        digitalWrite(piezo, LOW);
    }

    delay(1000);  // Wait for 1 second before next reading
}