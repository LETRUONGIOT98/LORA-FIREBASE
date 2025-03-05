#include <SPI.h>
#include <LoRa.h> 
int LED = 3;
String inString = "";    // string to hold input
int val = 0;
#define relay 4
#define coi 5
#define xn 6
#define tr A0
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(coi, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(xn, INPUT_PULLUP);
  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) { // or 915E6
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() {
  
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) { 
    // read packet    
    while (LoRa.available())
    {
      int inChar = LoRa.read();
      inString += (char)inChar;
      val = inString.toInt();       
    }
    inString = "";     
    LoRa.packetRssi();  
     delay(50);  
  }
  Serial.println(val);  
  analogWrite(LED, val);
  digitalWrite(relay,val);
  digitalWrite(tr, val);
  
}
