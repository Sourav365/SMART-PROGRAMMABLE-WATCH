#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

Adafruit_SSD1306 led = Adafruit_SSD1306(128, 32, &Wire);

char ssid[] = "sourav";   
char pass[] = "12345678";  

int dist, hr, mint,pm25,pm10;
int d1, d2;
float tem;
unsigned long Time,Time1;
int s1 = 3;
int s2 = 1;
char* noti;

#include "largeDisplay.h"
#include "getTime.h"
#include "smartDisplay.h"
#include "polution.h"
#include "weather.h"
#include "temperature.h"
#include "adfrutio.h"
#include "calll.h"
#include "menuu.h"


void setup() {
  Serial.begin(115200); //// DON'T USE THIS IF WANT TO USE Rx, Tx PIN
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  Wire.begin(0,2);
  
  led.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  led.setTextColor(WHITE);
  led.cp437(true);
  led.clearDisplay();
  led.setTextSize(1);
  led.setCursor(0,0);
     
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, pass);
  led.print("CONNECTING TO SSID : ");
  led.print(ssid);
  led.display();
  while(WiFi.status() != WL_CONNECTED)
  {
     led.print(". ");
     led.display();
     delay(500);
    }   
  led.setCursor(40,25);
  led.print("CONNECTED");
  led.display();
  delay(2000);

  setup_time(); 
  mqtt.subscribe(&notification);
}

void loop() 
{
  d1 = digitalRead(s1);
  d2 = digitalRead(s2);
  
  menu();
  call();
  simple_display(); ////IN MENUU.H
}
