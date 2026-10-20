#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

const char* ssid = "TULIS NAMA SSID HOTSPOT KALIAN";
const char* password = "TULIS PASSWORD DARI HOTSPOT KALIAN";

// Ganti IP di bawah dengan IP komputer/server lokal kamu
const char* serverName = "http://192.168.1.10/Piranti"; 

void setup() {
  Serial.begin(9600);
  delay(1000);

  if (!mpu.begin()) {
    Serial.println("MPU6050 tidak ditemukan!");
    while (1) delay(10);
  }

  // Koneksi ke Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float sumbu_x = a.acceleration.x;
  float sumbu_y = a.acceleration.y;
  String arah = "netral";

  // Menentukan kondisi arah sesuai modul
  if (sumbu_x > 10) {
    arah = "kiri";
  } else if (sumbu_x < -10) {
    arah = "kanan";
  } else if (sumbu_y > 10) {
    arah = "depan";
  } else if (sumbu_y < -10) {
    arah = "belakang";
  }

  // Kirim data jika posisinya tidak netral (atau dikirim berkala)
  if (WiFi.status() == WL_CONNECTED) {
    String url = serverName;
    url += "?arah_sumbu=";
    url += arah;

    HTTPClient http;
    http.begin(url);
    
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(5000); // Kirim data setiap 5 detik
}