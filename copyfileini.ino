#define BLYNK_TEMPLATE_ID “isidisini” // ini sesuai template
#define BLYNK_TEMPLATE_NAME “isidisini” // ini sesuai template
#define BLYNK_AUTH_TOKEN “isidisini” // ganti token kalian ges

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Ultrasonic.h>

// WiFi Credentials
char ssid[] = “isidisini”;     // ganti ke wifi kalian
char pass[] = “isidisini”; // ganti password wifi kalian

// Pin untuk Ultrasonic
#define TRIG_PIN 2 // Pin TRIG sensor HC-SR04
#define ECHO_PIN 4 // Pin ECHO sensor HC-SR04

Ultrasonic ultrasonic(TRIG_PIN, ECHO_PIN); // Inisialisasi objek ultrasonic
BlynkTimer timer;

// Fungsi untuk membaca data jarak
void sendUltrasonicData() {
  long distance = ultrasonic.read(); // Mengukur jarak dalam cm
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  Blynk.virtualWrite(V0, distance); // Kirim data ke Virtual Pin V0
}

void setup() {
  // Setup serial monitor
  Serial.begin(115200);

  // Koneksi ke Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Timer untuk membaca data setiap 1 detik
  timer.setInterval(1000L, sendUltrasonicData);
}

void loop() {
  Blynk.run(); // Jalankan koneksi Blynk
  timer.run(); // Jalankan timer untuk membaca data
}

