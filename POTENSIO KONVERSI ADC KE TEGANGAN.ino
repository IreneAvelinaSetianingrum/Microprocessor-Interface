int potPin = A0;
int potValue;
float voltage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  voltage = (potValue * 5.0) / 1023.0; // Konversi nilai ADC ke tegangan
  Serial.print("ADC Value: ");
  Serial.print(potValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage, 2); // Menampilkan tegangan dengan 2 digit desimal
  delay(100);
}