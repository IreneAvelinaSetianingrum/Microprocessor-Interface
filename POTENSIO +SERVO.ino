#include <Servo.h>

Servo myServo;  // Buat objek Servo

void setup() {
  myServo.attach(9);  // Hubungkan servo ke pin D9
}

void loop() {
  int sensorValue = analogRead(A0);  // Baca nilai ADC dari potensiometer
  int servoPosition = map(sensorValue, 0, 1023, 0, 180);  // Konversi nilai ADC ke posisi servo
  myServo.write(servoPosition);        // Atur posisi servo
  delay(15);                            // Delay untuk memberi waktu servo bergerak
}
