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
