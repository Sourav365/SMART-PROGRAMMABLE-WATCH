#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 led = Adafruit_SSD1306(128, 32, &Wire);

#include "largeDisplay.h"
#include "getTime.h"
#include "smartDisplay.h"
#include "polution.h"
#include "weather.h"
#include "temperature.h"

char ssid[] = "sourav";   
char pass[] = "12345678";  

int dist, hr, mint,pm25,pm10;
float tem;
unsigned long Time,Time1;
int s1 = 1;
int s2 = 3;
void setup() {
  ////Serial.begin(115200); //// DON'T USE THIS IF WANT TO USE Rx, Tx PIN
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  Wire.begin(0,2);
  
  led.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  led.setTextColor(WHITE); // Draw white text
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
     //Serial.print(".");
     led.print(". ");
     led.display();
     delay(500);
    }   
  led.setCursor(40,25);
  led.print("CONNECTED");
  led.display();
  delay(2000);

  setup_time(); 
}

void loop() 
{
  int d1 = digitalRead(s1);
  int d2 = digitalRead(s2);
  if(d2==1)
  {
      led.clearDisplay();
      led.print("SSSSSSsSSSS");
      led.display();
  }
  if(d1==1)
  {
      led.clearDisplay();
      led.print("DDD");
      led.display();
  }
  
  led.clearDisplay();
  led.setTextColor(WHITE); // Draw white text
  led.cp437(true);

  //////////////////////////////////////////////////////////////////
  
  Time1 = get_time();
  if(Time1 > 0)
      Time = Time1;
  hr = (Time % 86400L) / 3600 ;
  mint = (Time  % 3600) / 60;
  float tem = temp();
  pm25 = PM25();
  pm10 = PM10();
  /////////////////////////////////////////////////////////////////
  printTime(hr,mint);
  delay(5000);
    //Serial.println(dist);
     //Serial.println(pm25);
     //Serial.println(pm10);
     smart_display(hr,mint,tem,pm25,pm10);  
     weather(); 
  delay(2000);
}
