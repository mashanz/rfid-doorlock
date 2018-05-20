#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);
int serNum[5];
String kartu;
String id1, id2, id3, id4, id5;
String hex1,hex2,hex3,hex4,hex5;
String chex;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  while (!Serial) ;
}
void loop() {

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      id1 = rfid.serNum[0];
      id2 = rfid.serNum[1];
      id3 = rfid.serNum[2];
      id4 = rfid.serNum[3];
      id5 = rfid.serNum[4];
      hex1= String(rfid.serNum[0],HEX);
      hex2= String(rfid.serNum[1],HEX);
      hex3= String(rfid.serNum[2],HEX);
      hex4= String(rfid.serNum[3],HEX);
      hex5= String(rfid.serNum[4],HEX);
      chex= hex1+hex2+hex3+hex4+hex5;
      
      kartu = id1 + id2 + id3 + id4 + id5;
      Serial.println("UID : " + kartu);
      Serial.println("UID HEX : " + chex);

    }

  }

  rfid.halt();
}



