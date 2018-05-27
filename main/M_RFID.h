#include <Arduino.h>
#include <SPI.h>
#include <RFID.h>
#include "M_WIFI.h"

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);
int serNum[7];
String hex1, hex2, hex3, hex4, hex5, hex6, hex7;


void setup_rfid() {
  SPI.begin();
  rfid.init();
  //Serial.begin(9600);
  //while (!Serial) ;
}

void loop_rfid() {

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      hex1 = String(rfid.serNum[0], HEX);
      hex2 = String(rfid.serNum[1], HEX);
      hex3 = String(rfid.serNum[2], HEX);
      hex4 = String(rfid.serNum[3], HEX);
      hex5 = String(rfid.serNum[4], HEX);
      hex6 = String(rfid.serNum[5], HEX);
      hex7 = String(rfid.serNum[6], HEX);
      chex = hex1 + hex2 + hex3 + hex4 + hex5 + hex6 + hex7;
      Serial.println("UID : " + chex);
      loop_wifi(chex);
    }

  }

  rfid.halt();
}



