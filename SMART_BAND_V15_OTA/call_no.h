void enter_no(){
   int c = 9,c1= 0, i=0;
   char number[] = "8001860831";
   while(1)
    {
      displayy();
      led.setCursor(40,1);
      led.print(number);
      
      led.setCursor(20,9);
      led.print("1");
      led.setCursor(20,17);
      led.print("4");
      led.setCursor(20,25);
      led.print("7");
      
      led.setCursor(50,9);
      led.print("2");
      led.setCursor(50,17);
      led.print("5");
      led.setCursor(50,25);
      led.print("8");
      
      led.setCursor(80,9);
      led.print("3");
      led.setCursor(80,17);
      led.print("6");
      led.setCursor(80,25);
      led.print("9");

      led.setCursor(110,9);
      led.print("Bak");
      led.setCursor(110,17);
      led.print("0");
      led.setCursor(110,25);
      led.print("Ok");
      
      led.setCursor(c1,c);
      led.print("=>");
      led.display();
      
      int co = digitalRead(s1);
      int ok = digitalRead(s2);
      if(co == 1)
      {
         delay(500);
         if(c==25)
         {
           c=9;
           c1 += 30;
           if(c1 == 120)
              c1 = 0;
         }
         else
            c += 8;
      }
      if(ok == 1)
      {
        delay(500);
          //if(c == 1)
          //{
            ////
          //}
          if(c == 9)
          {
            if(c1 == 0){
              number[i] = '1';
              i++;
            }
            if(c1 == 30){
              number[i] = '2';
              i++;
            }
            if(c1 == 60){
              number[i] = '3';
              i++;
            }
            if(c1 == 90){
              displayy();
              led.setCursor(0,0);
              led.print("GOING BACK...");
              led.display();
              break;
            }
           }
          if(c == 17)
          {
             if(c1 == 0){
              number[i] = '4';
              i++;
            }
            if(c1 == 30){
              number[i] = '5';
              i++;
            }
            if(c1 == 60){
              number[i] = '6';
              i++;
            }
            if(c1 == 90){
              number[i] = '0';
              i++;
            }
           }
          if(c == 25)
          {
            if(c1 == 0){
              number[i] = '7';
              i++;
            }
            if(c1 == 30){
              number[i] = '8';
              i++;
            }
            if(c1 == 60){
              number[i] = '9';
              i++;
            }
            if(c1 == 90){
              Firebase.setString("number",number);//okk
              delay(1000);
              //number[] = { };
            }
            if(i == 11)  i=0;
           }
      }       
    }
}




void contacts(){
  
}
