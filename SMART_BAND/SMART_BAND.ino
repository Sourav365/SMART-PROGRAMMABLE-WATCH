#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 led = Adafruit_SSD1306(128, 32, &Wire);

 int data;
  ////String hr,mint;
 int hr,mint,sec = 0;
 int date = 10,month = 03,year = 2020,day = 2;/////////////////////SET//////////////////
 
 String dayy[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
 
 
void setup() {
  Serial.begin(115200); 
  Wire.begin(0,2);
  led.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //led.display();
  //delay(2000); 
  //led.clearDisplay();
  }
  
  
void loop() {
  if(Serial.available()>0)
  {
    data = Serial.parseInt(); //HHMM          /////data = Serial.readString();
    Serial.println(data);
   /// Serial.println(Serial.available());
    /*hrr = data[0]+data[1];
    minn = data[3]+data[4];*/
    if(data != 0)
    {
      hr = data/100;
      //Serial.println(hr);
      mint = data%100;
      //Serial.println(mint);
    }
  }
  
  
  /*hr = String(hrr);
    mint = String(minn);
    Serial.println(hr);
    Serial.println(mint);*/

    
  led.clearDisplay();
  led.setTextColor(WHITE); // Draw white text
  led.cp437(true);         // Use full 256 char 'Code Page 437' font

//..............................................................................................  
  led.setTextSize(3);      
  led.setCursor(20, 1); 

  if(hr < 10)
  {
    led.print(0);
    led.print(hr);
    led.print(":");
  }
  else
  {
    led.print(hr);
    led.print(":");
  }
  
  if(mint < 10)
  {
    led.print(0);
    led.print(mint);
  }
  else
  {
    led.print(mint);
  }

  led.setTextSize(1);      
  led.setCursor(115, 8);     
  led.print(sec);

  led.setCursor(20, 25); 
  if(date < 10)
  {
    led.print(0);
    led.print(date);
  }
  else led.print(date);
  led.print("/");
  if(month < 10)
  {
    led.print(0);
    led.print(month);
  }
  else led.print(month);
  led.print("/");
  led.print(year);
  led.print("  ");
  
  led.print(dayy[day]);


//....................................................................................................
  led.display();
  delay(1000);
  sec += 1;
//..................TIME..........................................................



//...................................

   
  if(sec == 60)
  {
     mint += 1;
     sec = 00;
   }

   if(mint == 60)
  {
     hr += 1;
     mint = 00;
   }

   if(hr == 24)
  {
     hr = 00;
     date += 1;
     day += 1;
   }
////////////////////////////////////////////////////////////////////////////////////////////////////
   if(date == 32)
  {
     month += 1;
     date = 01;
   }

   if(month == 13)
  {
     year += 1;
     month = 01;
     //"HAPPY NEW YEAR"..................................................
     //nyear(year);
     //testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT);
     //sec = 35;
   }

   
  if(day == 7)
  {
     day = 0;
   }  
}
