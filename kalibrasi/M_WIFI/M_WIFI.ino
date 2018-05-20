#include <SoftwareSerial.h>
#include "M_WIFI.h"

void setup() {
  setup_wifi();
}

void loop() {
  wifiRead();
}
