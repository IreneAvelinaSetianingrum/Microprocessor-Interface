// Definisikan pin untuk LED
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

void setup() {
  // Setiap pin LED sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

  // Gerakan bolak-balik (kanan-kiri dan kiri-kanan)
  digitalWrite(led1, HIGH);  // Nyalakan LED 1
  delay(500);
  digitalWrite(led1, LOW);   // Matikan LED 1

  digitalWrite(led2, HIGH);  // Nyalakan LED 2
  delay(500);
  digitalWrite(led2, LOW);   // Matikan LED 2

  digitalWrite(led3, HIGH);  // Nyalakan LED 3
  delay(500);
  digitalWrite(led3, LOW);   // Matikan LED 3

  digitalWrite(led2, HIGH);  // Nyalakan LED 2
  delay(500);
  digitalWrite(led2, LOW);   // Matikan LED 2

  digitalWrite(led1, HIGH);  // Nyalakan LED 1
  delay(500);
  digitalWrite(led1, LOW);   // Matikan LED 1
}