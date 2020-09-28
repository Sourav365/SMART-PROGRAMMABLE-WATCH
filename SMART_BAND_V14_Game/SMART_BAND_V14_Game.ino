 /*--FUNCTIONS--
  * 
  * getTime.h         :   get_time();
  * smartDisplay.h    :   smart_display(int Hr, int Mint,float temp,int pm25,int pm10);
  * polution.h        :   PM25(); PM10(); 
  * weather.h         :   weather();  
  * temperature.h     :   temp();
  * adfrutio.h        :   adafruiti(int data);  notific();  
  * calll.h           :   call();
  * fire.h            :   fb(); 
  * largeDisplay.h    :   printTime(int hr,int mint); simple_display(); displayy(); date_fetch();
  * message.h         :   messages(); replyy(); 
  * analogLook.h      :   analog_look();  
  * img.h             :   image();
  * healthh.h         :   health_img();
  * homeAutomation.h  :   hAuto();
  * call_no.h         :   enter_no();
  * menuu.h           :   menu(); menu2();  menu3();  call_menu();  fun();  
  * game1.h           :   game_setup(); game1();
  * calculator.h      :   calculator_menu();  calculator_no();
  * 
  */

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
#include <FirebaseArduino.h>

ESP8266WiFiMulti WiFiMulti;
Adafruit_SSD1306 led = Adafruit_SSD1306(128, 64, &Wire);

/* PINS define
*-------------------------
*      D1| D2  |D3
*      ok|down |up/back/special
*      s2| s1  |s3
*--------------------------*/
#define s1  D2  
#define s2  D1
#define s3  D3

#define sda D6
#define scl D5
#define vcc_led D7    //* Input Pins

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "Sourav1999"
#define AIO_KEY         "e74c04d97cac4962a3b1b1d6deae0570"

#define host "e-health-t3.firebaseio.com"
#define auth "76CTSpklGhGtWshWscIdEEVAoUY8iF25eOVc36G5"

char ssid[] = "sourav";   
char pass[] = "12345678";  

int d1, d2, dist, hr, mint,pm25,pm10,counter=10;
float tem;
unsigned long Time,Time1;
char *noti_prev, *notiii;
char weatherr[10],day_date[30],data[10]; /////STORES DATAS........
String bmi,o2,bp,btemp,pulse,fstep; 
int ci = 0;// interrupt counter

#include "getTime.h"
#include "smartDisplay.h"
#include "polution.h"
#include "weather.h"
#include "temperature.h"
#include "adfrutio.h"
#include "calll.h"
#include "fire.h"
#include "largeDisplay.h"
#include "message.h"
#include "analogLook.h"
#include "img.h"
#include "healthh.h"
#include "homeAutomation.h"
#include "call_no.h"
#include "calculator.h"
#include "game1.h"
#include "menuu.h"

ADC_MODE(ADC_VCC);

void interrupt()
{
  ci = 1;
}

void setup() {
  Serial.begin(115200); //// DON'T USE THIS IF WANT TO USE Rx, Tx PIN
  pinMode(s1,INPUT_PULLUP);
  pinMode(s2,INPUT_PULLUP);
  pinMode(s3,INPUT_PULLUP);
  pinMode(vcc_led, OUTPUT);
  digitalWrite(vcc_led,HIGH);
  
  Wire.begin(sda,scl);  /////I2C pins
  
  led.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  led.setTextColor(WHITE);
  led.cp437(true);
  led.clearDisplay();
  led.setTextSize(1);
  led.setCursor(0,1);
     
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
  
  //attachInterrupt(s1,interrupt,HIGH);
  
  setup_time(); 
  Firebase.begin(host,auth); 
  mqtt.subscribe(&notifi);
}

void loop() 
{
  attachInterrupt(s1,interrupt,HIGH);
  digitalWrite(vcc_led,HIGH);
  //d1 = digitalRead(s1);
  d2 = digitalRead(s2);
  
  if(ci==1)  menu();/////menu.h///////////////////

  
  if(d2==1)
  {
    displayy(); /////largeDisplay.h////////
    led.setCursor(0,0);
    led.print("Fetching data...");
    led.display();
    if(ci==1)  menu();///////////////////////
    tem = temp(); ////temperature.h/////
    pm25 = PM25();////polution.h////////
    pm10 = PM10();////polution.h////////
    smart_display(hr,mint,tem,pm25,pm10);  //////smartDisplay.h//////////////
    weather(); 
    if(ci==1)  menu();//////////////////////
    battery();
    led.display();
    delay(5000);
    }
  else
  {
    if(counter % 2 == 0)
    {    if(ci==1)  menu();//////////////////
         simple_display();///////largeDisplay.h////////
         if(ci==1)  menu();//////////////////
         delay(1000);
    }
    else
        if(ci==1)  menu();//////////////////
        analog_look();//////analogLook.h//////
        if(ci==1)  menu();//////////////////
  }
  counter++;
  //if(counter % 6 == 0)
    //  ESP.deepSleep(30e6); ////////// Deep Sleep in loop for 30 Secs.*/
}


void battery(){
  float voltage=0.0f;
  voltage = ESP.getVcc();
  float vcc = (voltage/1024.0f);
  int batt = map(vcc,0,3.5,0,100);
  led.setCursor(107,1);
  led.print(batt);
}
