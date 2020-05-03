#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiUdp.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

ESP8266WiFiMulti WiFiMulti;
Adafruit_SSD1306 led = Adafruit_SSD1306(128, 64, &Wire);

char ssid[] = "sourav";   
char pass[] = "12345678";  

int dist, hr, mint,pm25,pm10,counter=10;
int d1, d2;
float tem;
unsigned long Time,Time1;
int s1 = 3;
int s2 = 1;
char *noti_prev, *notiii;
char weatherr[10],day_date[30]; /////STORES DATAS........


#include "getTime.h"
#include "smartDisplay.h"
#include "polution.h"
#include "weather.h"
#include "temperature.h"
#include "adfrutio.h"
#include "calll.h"
#include "fire.h"
#include "largeDisplay.h"
#include "analogLook.h"
#include "img.h"
#include "healthh.h"
#include "homeAutomation.h"
#include "call_no.h"
#include "menuu.h"

void setup() {
  ////Serial.begin(115200); //// DON'T USE THIS IF WANT TO USE Rx, Tx PIN
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
     delay(250);
    }   
  led.setCursor(40,55);
  led.print("CONNECTED");
  led.display();
  delay(500);

  setup_time(); 
  Firebase.begin(host,auth); 
  mqtt.subscribe(&notifi);
}

void loop() 
{
  d1 = digitalRead(s1);
  d2 = digitalRead(s2);
  if(d1==1)
      menu();
  if(d2==1)
  {
    displayy();
    led.setCursor(0,0);
    led.print("Fetching data...");
    led.display();
    tem = temp();
    pm25 = PM25();
    pm10 = PM10();
    smart_display(hr,mint,tem,pm25,pm10);  
    weather(); 
    led.display();
    delay(5000);
    }
  else
  {
    if(counter % 2 == 0)
    {    simple_display();
         delay(1000);
    }
    else
        analog_look();
  }
  counter++;
}
