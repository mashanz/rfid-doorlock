#include <SoftwareSerial.h>
#include "M_WIFI.h"

void setup() {
  setup_wifi();
  AT(1);
}

void loop() {
  test_wifi();
}
