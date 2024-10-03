const int ledPins[] = {2, 3, 4};  // Pin LED
const int buttonPin = 7;          // Pin tombol
int buttonState = 0;              // Status tombol
bool isRunning = false;           // Status apakah LED bergerak

void setup() {
  // Atur pin LED sebagai output
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Atur pin tombol sebagai input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Baca status tombol
  buttonState = digitalRead(buttonPin);

  // Jika tombol ditekan, aktifkan running LED
  if (buttonState == HIGH) {
    isRunning = !isRunning;   // Toggle status running saat tombol ditekan
    delay(200);               // Debounce untuk menghindari multiple input
  }

  // Jalankan LED jika isRunning true
  if (isRunning) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], HIGH);   // Nyalakan LED
      delay(300);                       // Tunggu 300ms
      digitalWrite(ledPins[i], LOW);    // Matikan LED
    }
  }
}
