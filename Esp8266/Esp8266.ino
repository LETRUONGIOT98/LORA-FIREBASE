const char* ssid = "linhkien2t.com";
const char* password = "865khavancan";
// Firebase Realtime Database
const char* host = "https://thong-bao-chuyen-dong-default-rtdb.firebaseio.com";
const char* auth = "sKCs8s3AGPmYzY4YAi8K8gfd41szy07ge9UHjDo5";
#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"
#include <ArduinoJson.h>
FirebaseData firebaseData;
FirebaseJson json;

#define coi 5
#define in 4
void setup() {
  Serial.begin(9600);
  pinMode(coi, OUTPUT);
  pinMode(in, INPUT);
  // Kết nối đến mạng Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Firebase.begin(host,auth);
Firebase.reconnectWiFi(true);
}

void loop() {firebaseData.intData();
  // Ghi dữ liệu vào Firebase Realtime Database
  Firebase.setInt(firebaseData, "data/sensorValue", digitalRead(in));
  // Đọc dữ liệu từ Firebase Realtime Database

  if(Firebase.getInt(firebaseData,("data/buzz"))){
    int val = firebaseData.intData();
  Serial.println("Buzz: " + String(val));
  digitalWrite(coi, val);
  delay(1000); // Đọc dữ liệu sau mỗi giây
}
}
