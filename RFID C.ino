#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// Pin untuk RFID
#define SS_PIN 10
#define RST_PIN 9

// Pin untuk LED dan buzzer
#define LED_PIN 8
#define BUZZER_PIN 7

// Inisialisasi RFID
MFRC522 mfrc522(SS_PIN, RST_PIN); 

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Daftar UID kartu yang diizinkan
byte allowedCards[][7] = {
  {0x04, 0x36, 0x44, 0xB2, 0x4F, 0x63, 0x80},  // Contoh UID kartu terdaftar
};

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);
  Serial.println("Siapkan RFID Reader");

  // Memulai SPI
  SPI.begin();

  // Memulai modul RFID
  mfrc522.PCD_Init();

  lcd.init();
  lcd.backlight();
  // Mengatur pin LED dan buzzer sebagai output
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Mematikan LED dan buzzer
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  // Periksa apakah ada kartu baru yang tersedia
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Periksa apakah kartu dapat dibaca
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Tampilkan UID kartu yang ditemukan
  Serial.print("UID Kartu: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Periksa apakah kartu terdaftar
  if (isCardAllowed(mfrc522.uid.uidByte)) {
    Serial.println("Allow");
    lcd.clear();
    lcd.setCursor(0, 0); // Baris pertama
    lcd.print("Allow");
  
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    Serial.println("Deny");
    lcd.clear();
    lcd.setCursor(0, 0); // Baris pertama
    lcd.print("Deny");
    // Nyalakan LED dan buzzer (akses ditolak)
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);  // Buzzer menyala selama 1 detik
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Hentikan komunikasi dengan kartu
  mfrc522.PICC_HaltA();
}

// Fungsi untuk memeriksa apakah kartu terdaftar
bool isCardAllowed(byte *cardUID) {
  for (int i = 0; i < sizeof(allowedCards) / sizeof(allowedCards[0]); i++) {
    bool match = true;
    for (int j = 0; j < 4; j++) {
      if (allowedCards[i][j] != cardUID[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return true;  // Kartu ditemukan dalam daftar
    }
  }
  return false;  // Kartu tidak ditemukan
}#include <Wire.h>;
 
void setup(){
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C Scanner");
}
 
void loop(){
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
   
  nDevices = 0;
  for(address = 1; address < 127; address++ ){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
     
    if (error == 0){
      Serial.print("ditemukan Perangkat i2C pada alamat 0x");
      if (address<16)
      Serial.print("0");
      Serial.print(address,HEX);
      Serial.println(" !");
       
      nDevices++;
    }
    else if (error==4){
      Serial.print("tidak ditemukan alamat 0x");
      if (address<16)
      Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("Tidak Ditemukan Alamat i2c\n");
    else
    Serial.println("selesai\n");
     
    delay(5000);
}
