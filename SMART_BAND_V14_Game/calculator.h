int calculator_no(){
   int c = 9,c1= 0, i=0;
   char num[] = "0";
   while(1)
    {
      displayy();
      led.setCursor(50,40);
      led.print(atoi(num));
      
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
      
      int ok = digitalRead(s2);
      int co = digitalRead(s1);
      int cob = digitalRead(s3);
      /////////////////////////////////////////////////////////////////////
      if(co == 1)
      {
         delay(300);
         if(c==25)
         {
           c=9;
           c1 += 30;
           if(c1 == 120)
              c1 = 0;
         }
         else
            c += 8;
         Serial.print(c1);
         Serial.print(", ");
         Serial.println(c);
      }
      
      if(cob == 0)
      {
         delay(300);
         if(c==9 && c1!=0)
         {
           c=25;
           c1 -=30;
         }
         else if(c==9 && c1==0)
         {
          c = 25;
          c1 = 90;
         }
         else
         {
          c -= 8;
         }
         Serial.print(c1);
         Serial.print(", ");
         Serial.println(c);
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
              num[i] = '1';
              i++;
            }
            if(c1 == 30){
              num[i] = '2';
              i++;
            }
            if(c1 == 60){
              num[i] = '3';
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
              num[i] = '4';
              i++;
            }
            if(c1 == 30){
              num[i] = '5';
              i++;
            }
            if(c1 == 60){
              num[i] = '6';
              i++;
            }
            if(c1 == 90){
              num[i] = '0';
              i++;
            }
           }
          if(c == 25)
          {
            if(c1 == 0){
              num[i] = '7';
              i++;
            }
            if(c1 == 30){
              num[i] = '8';
              i++;
            }
            if(c1 == 60){
              num[i] = '9';
              i++;
            }
            if(c1 == 90){
              return atoi(num);////////okk
              delay(1000);
              //num[] = { };
            }
           }
      }///////////////////////////////////////////////////////////////////       
    }
}



/*
 * +=1;   ln=2;    e^=3;    cot=0;
 * -=4;   log=5;   sin=6;   root=14;
 * *=7;   x^2=8;   cos=9;   inv=15;
 * /=11;  x^y=12;  tan=13;  dB=16;
 */
int calculator_operations(){    //// +=1; -=4; *=7; /=2; log=5; ln=8;
   int c = 9,c1= 10, i=0;
   while(1)
    {
      displayy();
      led.setCursor(20,9);
      led.print("+");
      led.setCursor(20,17);
      led.print("-");
      led.setCursor(20,25);
      led.print("*");
      led.setCursor(20,33);
      led.print("/");
      
      led.setCursor(50,9);
      led.print("ln");
      led.setCursor(50,17);
      led.print("log");
      led.setCursor(50,25);
      led.print("x^2");
      led.setCursor(50,33);
      led.print("x^y");
      
      led.setCursor(80,9);
      led.print("e^x");
      led.setCursor(80,17);
      led.print("sin");
      led.setCursor(80,25);
      led.print("cos");
      led.setCursor(80,33);
      led.print("tan");

      led.setCursor(110,9);
      led.print("cot");
      led.setCursor(110,17);
      led.print("rot");
      led.setCursor(110,25);
      led.print("inv");
      led.setCursor(110,33);
      led.print("dB");
      
      led.setCursor(c1,c);
      led.print(">");
      led.display();
      
      int co = digitalRead(s1);
      int ok = digitalRead(s2);
      if(co == 1)
      {
         delay(100);
         if(c==33)
         {
           c=9;
           c1 += 30;
           if(c1 == 130)
              c1 = 10;
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
            //10,40,70,100
            switch(c1){
              case 10: return 1; 
              case 40: return 2; 
              case 70: return 3; 
              case 100: return 0; 
            }
           }
          if(c == 17)
          {
            switch(c1){
              case 10: return 4; 
              case 40: return 5; 
              case 70: return 6; 
              case 100: return 14; 
            }
           }
          if(c == 25)
          {
            switch(c1){
              case 10: return 7; 
              case 40: return 8; 
              case 70: return 9; 
              case 100: return 15; 
            }
           }
          if(c == 33)
          {
            switch(c1){
              case 10: return 11;
              case 40: return 12;
              case 70: return 13;
              case 100: return 16;
            }
            if(i == 11)  i=0;
           }
      }       
    }
}

void result(){
  while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
            }
}

void calculator(){
  int no1 = 0, no2 = 0, reslt = 1;
  no1 = calculator_no();
  int op  =  calculator_operations();
  if(op==1 || op==4 || op==7 || op==11 || op==12) 
    no2 = calculator_no();
  switch(op){
    case 0: displayy();
            led.setCursor(4,28);
            led.print("cot ("+String(no1)+") = ");
            led.print(String(cos(no1)/sin(no1)));
            result();
            break;
    case 1: displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" + "+String(no2)+" = ");
            led.print(String(no1 + no2));
            result();
            break;
    case 2: displayy();
            led.setCursor(4,28);
            led.print("ln ("+String(no1)+") = ");
            led.print(log(no1));
            result();
            break;
    case 3: displayy();
            led.setCursor(4,28);
            led.print("e^ "+String(no1)+" = ");
            led.print(String(exp(no1)));
            result();
            break;
     case 4: displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" - "+String(no2)+" = ");
            led.print(String(no1 - no2));
            result();
            break;
    case 5: displayy();
            led.setCursor(4,28);
            led.print("log ("+String(no1)+") = ");
            led.print(String(log(no1)/2.30f));
            result();
            break;
    case 6: displayy();
            led.setCursor(4,28);
            led.print("sin("+String(no1)+") = ");
            led.print(String(sin(no1)));
            result();
            break;
    case 7: displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" * "+String(no2)+" = ");
            led.print(String(no1 * no2));
            result();
            break;
    case 8: displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" ^ 2 = ");
            led.print(String(no1*no1));
            result();
            break;
    case 9: displayy();
            led.setCursor(4,28);
            led.print("cos ("+String(no1)+") = ");
            led.print(String(cos(no1)));
            result();
            break;
    case 11: displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" / "+String(no2)+" = ");
            led.print(String((no1*1.00f) / no2));
            result();
            break;
    case 12: displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" ^ "+String(no2)+" = ");/////////////////////////////////////////////////
            for(int i=1; i<=no2; i++)
              reslt *= no1;
            led.print(String(reslt));
            result();
            break;
    case 13: displayy();
            led.setCursor(4,28);
            led.print("tan ("+String(no1)+") = ");
            led.print(String(sin(no1)/cos(no1)));
            result();
            break;
    case 14: displayy();
            led.setCursor(4,28);
            led.print("root ("+String(no1)+") = ");
            led.print(String(sqrt(no1))); 
            result();
            break;
    case 15: displayy();
            led.setCursor(4,28);
            led.print("inv ("+String(no1)+") = ");
            led.print(String(1.00f / no1));
            result();
            break;
    case 16: displayy();
            led.setCursor(4,28);
            led.print("dB ("+String(no1)+") = ");
            led.print(String(20 * (log(no1)/2.30f)));
            result();
            break;
  }
}


 
/*void calculator_menu()
 {
   int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Addition");
      led.setCursor(20,17);
      led.print("3. Subtraction");
      led.setCursor(20,25);
      led.print("4. Multipication");
      led.setCursor(20,33);
      led.print("5. Division");
      led.setCursor(20,41);
      led.print("6. log");
      led.setCursor(20,49);
      led.print("7. ln");
      led.setCursor(20,57);
      led.print("8. More");
      led.setCursor(0,c);
      led.print("=>");
      led.display();
      
      int c1 = digitalRead(s1);
      int ok = digitalRead(s2);
      
      if(c1 == 1)
      {
         delay(500);
         if(c==57)
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
            led.setCursor(0,30);
            led.print("GOING BACK...");
            led.display();
            ci = 0;
            break;
          }
          if(c == 9)
          {
            int no1 = calculator_no();
            int no2 = calculator_no();
            displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" + "+String(no2)+" = ");
            led.print(String(no1 + no2));
            while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
            }
           }
          if(c == 17)
          {
            int no1 = calculator_no();
            int no2 = calculator_no();
            displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" - "+String(no2)+" = ");
            led.print(String(no1 - no2));
            while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
            }
           }
          if(c == 25)
          {
            int no1 = calculator_no();
            int no2 = calculator_no();
            displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" * "+String(no2)+" = ");
            led.print(String(no1 * no2));
            while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
            }
           }
           if(c == 33)
          {
            int no1 = calculator_no();
            int no2 = calculator_no();
            displayy();
            led.setCursor(4,28);
            led.print(String(no1)+" / "+String(no2)+" = ");
            led.print(String((no1*1.00f) / no2));
            while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
            }
           }
           if(c == 41)
          {
            int no1 = calculator_no();
            displayy();
            led.setCursor(4,28);
            led.print("log (" + String(no1) + ") = ");
            led.print(String(log(no1)/2.30f));
            while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
              }
           }
           if(c == 49)
          {
            int no1 = calculator_no();
            displayy();
            led.setCursor(4,28);
            led.print("ln (" + String(no1) + ") = ");
            led.print(String(log(no1)));
            while(1){
              led.display();
              if(digitalRead(s1) == 1)
                  {
                    delay(500);
                    break;
                  }
              }
           }
           if(c == 57)
          {
            //menu2();
           }
      }       
    }
 }*/
