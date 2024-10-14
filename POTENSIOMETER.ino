int potPin = A0; // Pin potensiometer terhubung ke A0
int potValue;

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
}

void loop() {
  potValue = analogRead(potPin); // Membaca nilai ADC dari potensiometer
  Serial.println(potValue);      // Menampilkan nilai ADC ke Serial Monitor
  delay(100);                    // Tunggu sebentar sebelum membaca lagi
}