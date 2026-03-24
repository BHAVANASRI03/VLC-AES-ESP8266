#include <ESP8266WiFi.h>
#include <AESLib.h>

AESLib aesLib;

String data = "HELLO_VLC";

byte aes_key[] = { 
  0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
  0x38,0x39,0x41,0x42,0x43,0x44,0x45,0x46
};

int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  char encrypted[128];

  aesLib.encrypt64(data.c_str(), encrypted, aes_key);

  for (int i = 0; i < strlen(encrypted); i++) {
    digitalWrite(ledPin, encrypted[i] % 2);
    delay(100);
  }

  delay(2000);
}
