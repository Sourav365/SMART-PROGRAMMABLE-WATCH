void printTime(int hr,int mint)
{
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

  /*led.setTextSize(1);      
  led.setCursor(115, 8);     
  led.print(sec);*/

  led.display();

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
