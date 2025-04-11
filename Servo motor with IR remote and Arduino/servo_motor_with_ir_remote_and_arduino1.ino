#include <IRremote.h>
#include <Servo.h>

int RECV_PIN = 6;   // IR receiver pin
IRrecv irrecv(RECV_PIN);  // Create IR receiver object

decode_results results;  // Create decode_results object

Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IR input");
  
  irrecv.enableIRIn();  // Enable IR receiver
  Serial.println("Enabled IR receiver");

  myservo.attach(9);  // Servo should be attached to a different pin
  myservo.write(pos);
}

void loop() {
  if (irrecv.decode(&results)) {  // Corrected function call
    Serial.println(results.value, DEC);

    if (results.value == 4043091356) {
      myservo.write(45);
      delay(1000);
    }
    else if (results.value ==3992758501) {  // Fixed 'result' typo
      myservo.write(90);
      delay(1000);
    }
    else if (results.value == 16599223) {
      myservo.write(135);
      delay(1000);
    }
    
    myservo.write(0); // Reset servo position after input handling
    irrecv.resume();  // Resume IR signal reception
    delay(1000);
  }
}
