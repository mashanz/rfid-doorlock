/*
 * default esp8266 black baudrate is 115200
 * change it to 9600 with command AT+UART_DEF=9600,8,1,0,0
 * data will be garbage not slowing down to 9600
 */

#include <Arduino.h>
SoftwareSerial sr(10, 11); // RX, TX

void wifi() {
  while (sr.available()) {
    Serial.print(sr.readString());
  }
}

void wifiRead() {
  if (sr.available()) {
    Serial.write(sr.read());
  }
  if (Serial.available()) {
    sr.write(Serial.read());
  }
}

void AT(int i) {
  switch(i){
    case 0: sr.write("AT\r\n"); break;
    case 1: sr.write("AT+GMR\r\n"); break;
    case 2: sr.write("AT+CIPSTATUS\r\n"); break;
    case 3: sr.write("AT+CWMODE=3\r\n"); break;
    case 4: sr.write("AT+CWLAP\r\n"); break;
    case 5: sr.write("AT+CWJAP=\"PONDOK DR LT 1\",\"bulanpuasa\"\r\n"); break;
    case 6: sr.write("AT+CIFSR\r\n"); break;
    default: sr.write("AT\r\n");
  }
}

void setup_wifi(){
  Serial.begin(9600);
  while (!Serial) {;}
  sr.begin(9600);
  AT(0); wifi(); delay(250);
  AT(1); wifi(); delay(250);
  AT(2); wifi(); delay(250);
  AT(3); wifi(); delay(250);
  AT(4); wifi(); delay(5000);
  AT(5); wifi(); delay(250);
  AT(2); wifi(); delay(250);
  AT(6); wifi(); delay(250);
}
