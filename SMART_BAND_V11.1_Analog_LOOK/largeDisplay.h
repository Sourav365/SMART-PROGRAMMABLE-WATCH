void date_fetch();

void printTime(int hr,int mint)
{
  led.setTextSize(2);      
  led.setCursor(10, 0); 

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

  /*led.setTextSize(1);      
  led.setCursor(115, 8);     
  led.print(sec);*/

  //led.display();
}

void simple_display()
{
  led.clearDisplay();
  led.setTextColor(WHITE); // Draw white text
  led.cp437(true);

  //////////////////////////////////////////////////////////////////
  
  Time1 = get_time();
  if(Time1 > 0)
      Time = Time1;
  hr = (Time % 86400L) / 3600 ;
  mint = (Time  % 3600) / 60;
  if(counter % 10 == 0)
      tem = temp();
      
  /////////////////////////////////////////////////////////////////
  printTime(hr,mint);
  notific();
  if(counter % 10 == 0)
      date_fetch();
  led.setTextSize(1);
  led.setCursor(80,1);
  led.print(String(tem));
  led.print("'C");
  led.setTextSize(1);
  led.setCursor(2,17);
  led.print(day_date);
  led.display();
  ////DATE..........................///..................................................................
  
  /*delay(5000);
  smart_display(hr,mint,tem,pm25,pm10);  
  weather(); 
  delay(2000);*/
}



void displayy()
{
  led.clearDisplay();
  led.setTextColor(WHITE);
  led.cp437(true);
  led.setTextSize(1);
}



///////////////////////DATE/////////////////////////////////////////////////////////////

void date_fetch()
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=30V1C6KIY0VRM4A4");
   
    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        int i = 0, j = 0;
        while (payload[i] != NULL)
        {
            day_date[j] = payload[i];
            j++;
            i++;
        }
        led.setTextSize(1);
        led.setCursor(2,17);
        led.print(day_date);
        //led.display();
      } else {
        //USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    delay(500);
  }
}
