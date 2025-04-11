int temp=A0;
float temp_celcius;
float voltage;
float analog_reading;
float  temp_far;

void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  analog_reading=analogRead(A0);
  Serial.print("Analog reading: ");
  Serial.println(analog_reading);
  voltage=analog_reading*5/1024;
  Serial.print("Voltage readings: ");
  Serial.println(voltage);
  
  temp_celcius=100*(voltage-0.5); //converting from 10mv per degree with 0.5V offset
  Serial.println("Celcius reading: "+String(temp_celcius)+(" C"));
  temp_far=(temp_celcius*9/5)+32;
  Serial.println("Fahremheit reading: "+String(temp_far)+(" F\n"));
  delay(3000); 
}