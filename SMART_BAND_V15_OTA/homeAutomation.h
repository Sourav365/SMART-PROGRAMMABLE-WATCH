void hAuto(){
  int c = 1;
  int light = Firebase.getInt("light");
  int fan = Firebase.getInt("fan");
  int ac = Firebase.getInt("ac");
   while(1)
    {
      //light = Firebase.getInt("light");
      //fan = Firebase.getInt("fan");
      //ac = Firebase.getInt("ac");
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Room Light: ");
      led.print(String(light));
      led.setCursor(20,17);
      led.print("3. Fan: ");
      led.print(String(fan));
      led.setCursor(20,25);
      led.print("4. AC: ");
      led.print(String(ac));
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
            (ac == 0) ? Firebase.setInt("light",1) : Firebase.setInt("light",0);
            delay(300);
            light = Firebase.getInt("light");
            delay(300);
          }
          if(c == 17)
          {
            (ac == 0) ? Firebase.setInt("fan",1) : Firebase.setInt("fan",0);
            delay(300);
            fan = Firebase.getInt("fan");
            delay(300);
           }
          if(c == 25)
          {
            (ac == 0) ? Firebase.setInt("ac",1) : Firebase.setInt("ac",0);
            delay(300);
            ac = Firebase.getInt("ac");
            delay(300);
           }
      }       
    }
}
