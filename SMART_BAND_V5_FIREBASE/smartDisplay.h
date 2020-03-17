void smart_display(int Hr, int Mint,float temp,int pm25,int pm10)
{
   led.clearDisplay();
   
 ////////////////////TIME/////////////////////////////////////////////
  led.setTextSize(1);      
  led.setCursor(50,0); 

  if(Hr < 10)
  {
    led.print(0);
    led.print(Hr);
    led.print(":");
  }
  else
  {
    led.print(Hr);
    led.print(":");
  }
  
  if(Mint < 10)
  {
    led.print(0);
    led.print(Mint);
  }
  else
  {
    led.print(Mint);
  }

  /*led.setTextSize(1);      
  led.setCursor(115, 8);     
  led.print(sec);*/

  led.display();
  
 //////////////////TEMP//////////////////////////
   led.setTextSize(1); 
   led.setCursor(20,8);
   //lcd.print("T=");
   //lcd.setCursor(8,0);
   led.print("Temp : ");
   led.print(String(temp));
   led.print("'C");
   
////////////////POLUTION////////////////////////
   led.setCursor(2,17);
   led.print("PM2.5= ");
   led.print(pm25);
   led.setCursor(70,17);
   led.print("PM10= ");
   led.print(pm10);

   led.display();
}
