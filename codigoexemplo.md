/* 
  Tinkercad BME280 Simulation Equivalent
  - Potentiometer (A0): Simulates Barometric Pressure (hPa)
  - TMP36 Sensor (A1): Simulates Temperature (C)
*/

const int pressurePin = A0; 
const int tempPin = A1;     

void setup() {
  Serial.begin(9600);
  Serial.println("--- Weather Station Simulation ---");
}

void loop() {
  // 1. Simulate Pressure (Mapping 0-1023 to 950-1050 hPa)
  int rawPressure = analogRead(pressurePin);
  float pressureHectopascals = map(rawPressure, 0, 1023, 950, 1050);

  // 2. Simulate Temperature (TMP36 standard math)
  int rawTemp = analogRead(tempPin);
  float voltage = rawTemp * (5.0 / 1024.0);
  float tempC = (voltage - 0.5) * 100;

  // Print results to Serial Monitor
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" C | Pressure: ");
  Serial.print(pressureHectopascals);
  Serial.println(" hPa");

  delay(1000); // 1-second update interval
}