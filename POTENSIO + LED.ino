int potPin = A0;
int ledPin = 9; 
int potValue;

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin sebagai output
}

void loop() {
  potValue = analogRead(potPin);           // Membaca nilai dari potensiometer
  int ledBrightness = map(potValue, 0, 1023, 0, 255); // Mengubah nilai potensiometer ke nilai PWM (0-255)
  analogWrite(ledPin, ledBrightness);      // Mengatur kecerahan LED dengan nilai PWM
  delay(10);
}