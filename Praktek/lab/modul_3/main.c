#include <WiFi.h>
#include <Wire.h>
#include <MPU6050_tockn.h>

// Definisi PIN LED
#define PIN_LED 19

// Konfigurasi Wi-Fi Utama
const char* SSID = "itsme20";
const char* PASSWORD = "@Faizul54321";

// Inisialisasi MPU6050 menggunakan Wire
MPU6050 mpu6050(Wire);

// Variabel penanda apakah posisi sukses sudah berhasil di-capture sekali
bool posisiTercapture = false; 

void setup() {
  Serial.begin(9600); 
  delay(1000); 

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW); 

  // 1. Memulai Komunikasi I2C dan Sensor MPU6050
  Wire.begin(21, 22); 
  mpu6050.begin();
  
  Serial.println("\nMemulai Kalibrasi MPU6050... Jangan digerakkan!");
  mpu6050.calcGyroOffsets(true); 
  Serial.println("Kalibrasi Selesai!");

  // 2. Mulai Koneksi Wi-Fi Utama (itsme20) secara Background
  Serial.print("Mencoba koneksi ke Wifi: ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);
}

void loop() {
  // Cek Status Koneksi Wi-Fi saat ini
  if (WiFi.status() == WL_CONNECTED) {
    // KONDISI TERSAMBUNG:
    digitalWrite(PIN_LED, HIGH); // LED menyala konstan

    // Jalankan blok ini HANYA SEKALI tepat saat pertama kali terhubung
    if (!posisiTercapture) {
      mpu6050.update(); // Update data posisi terakhir saat terhubung
      
      Serial.println("\n=========================================");
      Serial.println("Wifi Terhubung Sukses!");
      Serial.print("[POSISI CAPTURED] ");
      Serial.print(" || Angle X: "); Serial.print(mpu6050.getAngleX());
      Serial.print(" | Y: "); Serial.print(mpu6050.getAngleY());
      Serial.print(" | Z: "); Serial.println(mpu6050.getAngleZ());
      Serial.println("=========================================");
      Serial.println("Serial monitor dihentikan karena sudah terhubung.");
      
      posisiTercapture = true; // Kunci agar tidak melakukan print lagi
    }
    
    delay(100); // Beri jeda kecil agar ESP32 tetap stabil
  } 
  else {
    // KONDISI BELUM TERSAMBUNG / GAGAL:
    posisiTercapture = false; // Reset penanda jika tiba-tiba Wi-Fi terputus
    
    // A. Membaca & terus menampilkan data XYZ ke serial monitor
    mpu6050.update();
    Serial.print("[Mencari Wi-Fi...]");
    Serial.print(" || Angle X: "); Serial.print(mpu6050.getAngleX());
    Serial.print(" | Y: "); Serial.print(mpu6050.getAngleY());
    Serial.print(" | Z: "); Serial.println(mpu6050.getAngleZ());

    // B. Membuat LED berkedip-kedip cepat (sekaligus memberi jeda print data)
    digitalWrite(PIN_LED, HIGH);
    delay(250);
    digitalWrite(PIN_LED, LOW);
    delay(250);
  }
}