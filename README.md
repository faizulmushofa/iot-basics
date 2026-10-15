# IoT Basics (Piranti Cerdas)

Repositori dokumentasi pembelajaran, praktikum laboratorium, dan eksperimen mandiri seputar Internet of Things (IoT) serta embedded systems.

## Daftar Isi
- [Materi Perkuliahan](#materi-perkuliahan)
- [Praktikum Laboratorium](#praktikum-laboratorium)
- [Eksperimen Mandiri](#eksperimen-mandiri)
- [Hardware & Software](#hardware--software)
- [Struktur Repositori](#struktur-repositori)
- [Lisensi](#lisensi)

---

## Materi Perkuliahan

Materi resmi dan panduan praktikum tersimpan di direktori [`Materi/`](Materi/):

- [`GUIDE BOOK PIRANTI CERDAS.pdf`](Materi/GUIDE%20BOOK%20PIRANTI%20CERDAS.pdf)
- [`Modul 1 - Pengenalan Mikrokontroler Input dan Output.pdf`](Materi/Modul%201%20-%20Pengenalan%20Mikrokontroler%20Input%20dan%20Output.pdf)
- [`Modul 2 - Pengenalan Digital dan Analog Input dan Output.pdf`](Materi/Modul%202%20-%20Pengenalan%20Digital%20dan%20Analog%20Input%20dan%20Output.pdf)
- [`Modul 3 - Koneksi WiFi.pdf`](Materi/Modul%203%20-%20Koneksi%20WiFi.pdf)
- [`Modul 4 - Protokol Komunikasi.pdf`](Materi/Modul%204%20-%20Protokol%20Komunikasi.pdf)
- [`Modul 5 - Internet of Things (IOT).pdf`](Materi/Modul%205%20-%20Internet%20of%20Things%20(IOT).pdf)

---

## Praktikum Laboratorium

Dokumentasi tugas terbimbing mingguan ada di [`Praktek/lab/`](Praktek/lab/).

| Modul | Topik | Status | Kode / Laporan |
|:---:|---|:---:|---|
| 01 | Pengenalan Mikrokontroler Input & Output | Belum | `Praktek/lab/modul-01/` |
| 02 | Pengenalan Digital & Analog I/O | Belum | `Praktek/lab/modul-02/` |
| 03 | Koneksi WiFi | Belum | `Praktek/lab/modul-03/` |
| 04 | Protokol Komunikasi (MQTT/HTTP) | Belum | `Praktek/lab/modul-04/` |
| 05 | Internet of Things (IoT Platform) | Belum | `Praktek/lab/modul-05/` |

---

## Eksperimen Mandiri

Eksperimen di luar modul resmi (mini-project, uji coba sensor, troubleshooting) ada di [`Praktek/mandiri/`](Praktek/mandiri/).

---

## Hardware & Software

### Hardware
- **Mikrokontroler:** ESP32 / ESP8266 / Arduino
- **Sensor:** DHT11/DHT22, LDR, Ultrasonik HC-SR04, dll.
- **Aktuator & Display:** LED, Relay 5V, LCD I2C / OLED SSD1306, Buzzer

### Software & Toolchain
- **IDE:** Arduino IDE / VS Code + PlatformIO
- **Bahasa:** C / C++ (Arduino Framework)
- **Broker / Platform IoT:** Mosquitto, EMQX, Blynk, ThingsBoard, atau Adafruit IO

---

## Struktur Repositori

```text
├── Materi/              # Panduan modul kuliah & referensi PDF
├── Praktek/
│   ├── lab/             # Praktikum terbimbing per modul
│   │   └── README.md
│   └── mandiri/         # Catatan oprek mandiri & mini-project
│       └── README.md
├── .gitignore
├── LICENSE
└── README.md
```

---

## Lisensi

Repositori ini dilisensikan di bawah [MIT License](LICENSE).
