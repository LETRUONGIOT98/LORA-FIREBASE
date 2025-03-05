#include <SPI.h>
#include <LoRa.h> 
int but = 3;
 
void setup() {
  Serial.begin(9600);
  pinMode(but,INPUT);
  
  while (!Serial);  
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) { // or 915E6, the MHz speed of yout module
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() {
  int val = digitalRead(but);
  Serial.println(val);
  LoRa.beginPacket();  
  LoRa.print(val);
  LoRa.endPacket();
  delay(50);
}
