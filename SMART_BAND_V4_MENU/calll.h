void call()
{
  d2 = digitalRead(s2);
  if(d2==1)
   {
      displayy();
      led.setCursor(0,0);
      led.print("CALLING...");
      led.display();
      adafruiti(1);
      delay(10000);
      adafruiti(0);
   }
}
