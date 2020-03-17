void call()
{
  d1 = digitalRead(s1);
  d2 = digitalRead(s2);
  if(d1==1)
  {
      led.clearDisplay();
      led.setCursor(0,0);
      led.print("CALLING...");
      led.display();
      adafruiti(1);
      delay(10000);
      adafruiti(0);
  }
  if(d2==1)
  {
      led.clearDisplay();
      led.setCursor(0,0);
      led.print("DDD");
      led.display();
  }
}
