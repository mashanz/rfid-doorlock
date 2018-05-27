#include "lib.h"


void setup() {
setup_wifi();
setup_lcd();
setup_rfid();
setup_selenoid();
 
}

void loop() {
Read_Time();
loop_rfid();
loop_solenoid();

//Serial.println(F("Request Ulang"));
//  delay(2000);
//  if (request_permission(chex)){
//    Serial.println("Boleh masuk");
//  } else {
//    Serial.println("Ga buleeeh");
//  }
}
