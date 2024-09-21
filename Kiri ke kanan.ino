const int jumlahLampu = 3; // Jumlah LED
const int pinLampu[] = {2, 3, 4}; // Pin digital untuk masing-masing LED

void setup() {
  for (int i = 0; i < jumlahLampu; i++) {
    pinMode(pinLampu[i], OUTPUT);
  }
}

void loop() {
  // Lampu bergerak dari kiri ke kanan
  for (int i = 0; i < jumlahLampu; i++) {
    digitalWrite(pinLampu[i], HIGH);
    delay(700); 
    digitalWrite(pinLampu[i], LOW);
  }
}