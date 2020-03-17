void menu()
 {
   int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Health");
      led.setCursor(20,17);
      led.print("3. Images");
      led.setCursor(20,25);
      led.print("4. Game");
      led.setCursor(0,c);
      led.print("=>");
      led.display();
      
      int c1 = digitalRead(s1);
      int ok = digitalRead(s2);
      if(c1 == 1)
      {
         delay(500);
         if(c==25)
            c=1;
         else
            c += 8;
      }
      if(ok == 1)
      {
        delay(500);
        /*switch(c)
        {
          case 1: break;
                  break;
          case 9: led.clearDisplay();
                  led.setCursor(0,0);
                  led.print("HEALTH");
                  delay(3000);
                  break;
          case 17:led.clearDisplay();
                  led.setCursor(0,0);
                  led.print("IMAGES");
                  delay(3000);
                  break;
          case 25:led.clearDisplay();
                  led.setCursor(0,0);
                  led.print("XXX");
                  delay(3000);
                  break;*/
          if(c == 1)
          {
            displayy();
            led.setCursor(0,0);
            led.print("GOING TO HOME PAGE...");
            led.display();
            break;
          }
          if(c == 9)
          {
            health_img();
           }
          if(c == 17)
          {
            image();
           }
          if(c == 25)
          {
            //health_img();
           }
      }       
    }
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
  tem = temp();
  pm25 = PM25();
  pm10 = PM10();
  /////////////////////////////////////////////////////////////////
  printTime(hr,mint);
  notific();
  delay(5000);
  smart_display(hr,mint,tem,pm25,pm10);  
  weather(); 
  delay(2000);
}
