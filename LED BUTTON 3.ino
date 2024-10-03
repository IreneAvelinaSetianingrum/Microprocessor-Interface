const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3 = 10;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);

  if (buttonState1 == LOW) {
    // Tombol 1 ditekan, nyalakan LED ke kanan
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay(300);  // Tunda selama 500ms
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(300);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    delay(300);
  } 
  else if (buttonState2 == LOW) {
    // Tombol 2 ditekan, matikan semua LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    delay(300);  // Tunda selama 500ms
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(300);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay(500);
  }
    else if (buttonState3 == LOW) {
    // Tombol 2 ditekan, matikan semua LED
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay(300);  // Tunda selama 500ms
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(500);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    delay(300);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    delay(300);  // Tunda selama 500ms
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    delay(300);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    delay(300);
  }
    if (digitalRead(buttonState1) == LOW) {
    buttonState1 = 1;
    return true; // Menghentikan loop dan beralih ke kondisi lain
  }
  if (digitalRead(buttonState2) == LOW) {
    buttonState2 = 2;
    return true;
  }
  if (digitalRead(buttonState3) == LOW) {
    buttonState3 = 3;
    return true;
  }
  return false; // Tidak ada tombol yang ditekan
}
