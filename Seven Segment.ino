// Pin untuk setiap segmen dp, G, F, E, D, C, B, A (dp tidak digunakan)
const int segmentPins[8] = {5, 9, 8, 7, 6, 4, 3, 2};

// Pola biner untuk setiap angka 0-9
const byte digits[10] = {
  B11111101,  // angka 0
  B01100001,  // angka 1
  B11011011,  // angka 2
  B11110011,  // angka 3
  B01100111,  // angka 4
  B10110111,  // angka 5
  B10111111,  // angka 6
  B11100001,  // angka 7
  B11111111,  // angka 8
  B11110111   // angka 9
};

void setup() {
  // Inisialisasi semua pin segmen sebagai OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Perulangan dari angka 1 hingga 9, kemudian 0, lalu berulang
  for (int i = 1; i <= 9; i++) {
    tampilkanAngka(i);
    delay(1000);  // Jeda 1 detik sebelum menampilkan angka berikutnya
  }
  // Menampilkan angka 0 setelah 9
  tampilkanAngka(0);
  delay(1000);  // Jeda 1 detik sebelum memulai dari angka 1 lagi
}

// Fungsi untuk menampilkan angka pada seven-segment
void tampilkanAngka(int num) {
  boolean segState;

  for (int seg = 1; seg < 8; seg++) {
    // Cek status bit untuk setiap segmen berdasarkan angka
    segState = bitRead(digits[num], seg);
    
    // Aktifkan atau matikan segmen sesuai pola biner angka
    digitalWrite(segmentPins[seg], !segState);
  }
}
