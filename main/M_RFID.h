#include <Arduino.h>
#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);
int serNum[5];
String hex1, hex2, hex3, hex4, hex5;
String chex;

void setup_rfid() {
  SPI.begin();
  rfid.init();
  Serial.begin(9600);
   while (!Serial) ;
}

void loop_rfid() {

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      hex1 = String(rfid.serNum[0], HEX);
      hex2 = String(rfid.serNum[1], HEX);
      hex3 = String(rfid.serNum[2], HEX);
      hex4 = String(rfid.serNum[3], HEX);
      hex5 = String(rfid.serNum[4], HEX);
      chex = hex1 + hex2 + hex3 + hex4 + hex5;
      lcd.setCursor(0, 1);
      lcd.print("UID : " + chex);
      Serial.println("UID : " + chex);

    }

  }

  rfid.halt();
}



