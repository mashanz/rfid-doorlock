#include <Arduino.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup_wifi(){
  Serial.begin(115200);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
}

void test_wifi() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

