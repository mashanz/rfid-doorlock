#include <Arduino.h>

SoftwareSerial sr(10, 11); // RX, TX

void setup_wifi(){
  Serial.begin(115200);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // set the data rate for the SoftwareSerial port
  sr.begin(115200);
}

void test_wifi() {
  if (sr.available()) {
    Serial.write(sr.read());
  }
//  if (Serial.available()) {
//    sr.write(Serial.read());
//  }
}

void AT(int i) {
  switch(i){
    case 0:
      sr.write("AT\r\n");
      break;
    case 1:
      sr.write("AT+GMR\r\n");
      break;
    default:
      sr.write("AT\r\n");
  }
}

