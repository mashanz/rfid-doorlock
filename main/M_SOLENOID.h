#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "lib.h"

int pushButton = 2;
const int buzzer = 7;   //Passive buzzer ke Pin D7 dan GND
const int doorLock = 8; //Driver Selenoid Door Lock/Relay input ke pin D8

void setup_selenoid() {
  pinMode(pushButton, INPUT);
  pinMode(doorLock, OUTPUT);
  digitalWrite(doorLock, LOW);
  tone (buzzer, 1200);
  noTone (buzzer);
  }

void ACCEPT () {
  digitalWrite(doorLock, HIGH);
  tone (buzzer, 900);
  delay(200);
  noTone(buzzer);
  delay(200);
  tone (buzzer, 900);
  delay(200);
  noTone(buzzer);
  delay(600);
  lcd.setCursor(0, 1);
  lcd.print("UID : " + chex);
  digitalWrite(doorLock, LOW);
  lcd.clear();
}

void REJECT () {
  tone (buzzer, 1800);
  delay(100);
  tone (buzzer, 1200);
  delay(100);
  tone (buzzer, 900);
  delay(200);
  noTone (buzzer);
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("Access Deny");
  lcd.clear();
  digitalWrite(doorLock, LOW);
  
}

void loop_solenoid() {
  int buttonState = digitalRead(pushButton);
  if (buttonState == HIGH) {
    ACCEPT();
  } else {
    buttonState = 0;
  }
}



