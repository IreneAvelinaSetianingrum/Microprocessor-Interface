const int ledPins[] = {2, 3, 4};  // Pin LED
const int button1Pin = 7;         // Pin tombol 1 (kanan ke kiri)
const int button2Pin = 8;         // Pin tombol 2 (kiri ke kanan)

int button1State = 0;             // Status tombol 1
int button2State = 0;             // Status tombol 2
bool direction = true;            // True = kiri ke kanan, False = kanan ke kiri
bool isRunning = false;           // Mengatur apakah LED berjalan

void setup() {
  // Atur pin LED sebagai output
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Atur pin tombol sebagai input
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  // Baca status kedua tombol
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // Jika tombol 1 ditekan, arahkan dari kanan ke kiri
  if (button1State == HIGH) {
    direction = false;   // Atur arah ke kanan ke kiri
    isRunning = true;    // Mulai LED berjalan
    delay(500);         // Jeda 2 detik untuk mengubah arah
  }

  // Jika tombol 2 ditekan, arahkan dari kiri ke kanan
  if (button2State == HIGH) {
    direction = true;    // Atur arah ke kiri ke kanan
    isRunning = true;    // Mulai LED berjalan
    delay(500);         // Jeda 2 detik untuk mengubah arah
  }

  // Jalankan LED hanya jika tombol sudah ditekan dan isRunning true
  if (isRunning) {
    if (direction) {
      // Kiri ke kanan
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPins[i], HIGH);   // Nyalakan LED
        delay(300);                       // Tunggu 300ms
        digitalWrite(ledPins[i], LOW);    // Matikan LED
      }
    } else {
      // Kanan ke kiri
      for (int i = 2; i >= 0; i--) {
        digitalWrite(ledPins[i], HIGH);   // Nyalakan LED
        delay(300);                       // Tunggu 300ms
        digitalWrite(ledPins[i], LOW);    // Matikan LED
      }
    }
  }
}
