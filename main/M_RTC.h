#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include "M_WIFI.h"
#include "M_SOLENOID.h"

tmElements_t tm;
String waktu;
int resetTime = 120;
int updatetime = 0;


void countingUP() {
  if (updatetime == resetTime) {
    if (check_alarm()){
      alarmSound();
      alarmSound();
    }
    updateTime = 0;
  } else updateTime++;
}

void Read_Time() {
  //Read RTC time
  if (RTC.read(tm)) {
    waktu = String(tm.Hour) + ":" + String(tm.Minute) + ":" + String(tm.Second);
    lcd.setCursor(0, 0);
    lcd.print("Time : " + waktu);
    countingUP();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
}


