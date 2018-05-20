#include "M_lcd.h"
#include "M_RTC.h"
#include "M_RFID.h"

void setup() {
setup_lcd();
setup_rfid();
}

void loop() {
Read_Time();
loop_rfid();
}
