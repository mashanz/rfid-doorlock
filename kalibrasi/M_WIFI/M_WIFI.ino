#include "M_WIFI.h"

void setup() {
  setup_wifi();
}

void loop() {
  Serial.println(F("Request Ulang"));
  delay(2000);
  if (request_permission("040D3782253980")){
    Serial.println("Boleh masuk");
  } else {
    Serial.println("Ga buleeeh");
  }
}