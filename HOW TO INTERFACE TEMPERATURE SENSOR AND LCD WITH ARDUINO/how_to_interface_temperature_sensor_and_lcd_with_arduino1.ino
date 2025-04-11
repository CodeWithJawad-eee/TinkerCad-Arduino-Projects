#include <LiquidCrystal.h>  

// Initialize the LCD with RS, E, D4, D5, D6, D7 pins  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

int sensorPin = A0;  // Temperature sensor connected to analog pin A0  
float degree;  
float realDegree;  
float temperatureC;  
float temperatureF;  

void setup() {  
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows  
  lcd.setCursor(0, 0);  
  lcd.print("Temperature:");  
}  

void loop() {  
  degree = analogRead(0);  // Read analog value from the sensor  
  realDegree = degree / 1024.0;  // Normalize value (range: 0 to 1)  
  realDegree = realDegree * 5.0;  // Convert to voltage scale  
  temperatureC = realDegree * 100.0;  // Convert voltage to Celsius  

  lcd.setCursor(0, 1);  // Move to the second line  
  lcd.print(temperatureC);  
  lcd.print(" C  ");  

  temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;  // Convert Celsius to Fahrenheit  
  lcd.print(temperatureF);  
  lcd.print(" F");  

  delay(1000);  // Wait for 1 second before updating the display  
}  
