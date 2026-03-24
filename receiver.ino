#include <AESLib.h>

AESLib aesLib;

byte aes_key[] = { 
  0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
  0x38,0x39,0x41,0x42,0x43,0x44,0x45,0x46
};

String receivedData = "ENCRYPTED_DATA_HERE";

void setup() {
  Serial.begin(115200);

  char decrypted[128];

  aesLib.decrypt64(receivedData.c_str(), decrypted, aes_key);

  Serial.println(decrypted);
}

void loop() {}
