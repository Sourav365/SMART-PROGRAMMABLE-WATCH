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

  /*
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

   */
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
  //pm25 = PM25();
  //pm10 = PM10();
  /////////////////////////////////////////////////////////////////
  printTime(hr,mint);
  notific();
  led.setTextSize(1);
  led.setCursor(80,1);
  led.print(String(tem));
  led.print("'C");
  led.display();
  ////DATE..........................///...........................................................................................
  led.setTextSize(1);
  led.setCursor(80,9);
  led.print("12/12/20");
  led.display();
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

void scroll()
{
  led.startscrollright(0x00, 0x0F);
  delay(2000);
  led.stopscroll();
  delay(1000);
  led.startscrollleft(0x00, 0x0F);
  delay(2000);
  led.stopscroll();
  delay(1000);
  led.startscrolldiagright(0x00, 0x07);
  delay(2000);
  led.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  led.stopscroll();
  delay(1000);
}
