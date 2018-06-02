#include "M_lcd.h"
#include "M_RTC.h"
#include "M_RFID.h"

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
}
