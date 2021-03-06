#include <Arduino.h>
#include "ESP8266.h"
#include <SoftwareSerial.h>
#include "M_SOLENOID.h"

#define ARD_RX_ESP_TX   4
#define ARD_TX_ESP_RX   5
#define ESP_RST         3
#define ESP_SSID        "WIFI"
#define ESP_PASS        "password"
#define HOST            "HOST
#define PORT            80
String BOOK             = "/room/index.php/Rfidbooked?rfid=";
String ALRM             = "/room/index.php/Rfidalarm?roomid=";
String CDID             = "040D3782253980";
String RMID             = "15";

SoftwareSerial softser(ARD_RX_ESP_TX, ARD_TX_ESP_RX);
Adafruit_ESP8266 wifi(&softser, &Serial, ESP_RST);

void setup_wifi(){
  char buffer[50];
  softser.begin(9600);
  Serial.begin(9600); while(!Serial);
  Serial.println(F("initial ESP8266"));
  Serial.print(F("Soft reset..."));
  if(!wifi.softReset()) {
    Serial.println(F("no response from module."));
    for(;;);
  }
  Serial.println(F("OK."));

  Serial.print(F("Checking firmware version..."));
  wifi.println(F("AT+GMR"));
  if(wifi.readLine(buffer, sizeof(buffer))) {
    Serial.println(buffer);
    wifi.find();
  } else {
    Serial.println(F("error"));
  }

  Serial.print(F("Connecting to WiFi..."));
  if(wifi.connectToAP(F(ESP_SSID), F(ESP_PASS))) {
    Serial.print(F("OK\nChecking IP addr..."));
    wifi.println(F("AT+CIFSR"));
    if(wifi.readLine(buffer, sizeof(buffer))) {
      Serial.println(buffer);
      wifi.find();
    } else {
      Serial.println(F("error"));
    }
  } else {
    Serial.println(F("FAIL"));
  }  
}

// Permission for ID CARD
bool request_permission(String CDID){
    bool data = false;
    if(wifi.connectTCP(F(HOST), PORT)) {
    Serial.print(F("OK\nRequesting page..."));
    String API = BOOK + CDID + "&roomid=" + RMID;
    char* capi = API.c_str();
    if(wifi.requestURL(capi)) {
      Serial.println("OK\nSearching for string...");
      if(wifi.find(F("{\"status\":\"failed\"}"), false)) {
        data = true;
      } 
    } else {
      Serial.println(F("error"));
    }
    wifi.closeTCP();
  } else {
    Serial.println(F("elah -_- !"));
  }
  return data;
}

// Check Alarm
bool check_alarm(){
    bool data = false;
    if(wifi.connectTCP(F(HOST), PORT)) {
    Serial.print(F("OK\nRequesting page..."));
    String API = ALRM + RMID;
    char* capi = API.c_str();
    if(wifi.requestURL(capi)) {
      Serial.println("OK\nSearching for string...");
      if(wifi.find(F("{\"status\":\"failed\"}"), false)) {
        data = true;
      } 
    } else {
      Serial.println(F("error"));
    }
    wifi.closeTCP();
  } else {
    Serial.println(F("elah -_- !"));
  }
  return data;
}
void loop_wifi(String chx){
  if (request_permission(chx)) {
    ACCEPT ();
    Serial.println("Boleh Masuk");
  } else {
    REJECT ();
    Serial.println("Tidak Boleh Masuk");
  }
}
      
