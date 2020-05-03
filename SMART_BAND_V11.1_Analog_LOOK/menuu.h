void menu2();
void menu3();
void cricket();
void fetchCric();
void fun();
void hAuto();
void call_menu();


String score;
String statuss;
String teams;
   
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
      led.print("3. Find device");
      led.setCursor(20,25);
      led.print("4. Call");
      led.setCursor(20,33);
      led.print("5. Home Automation");
      led.setCursor(20,41);
      led.print("6. Gallery");
      led.setCursor(20,49);
      led.print("7. Funs & Games");
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
            call();
           }
          if(c == 25)
          {
            call_menu();
           }
           if(c == 33)
          {
            hAuto();
           }
           if(c == 41)
          {
            image();
           }
           if(c == 49)
          {
            menu3();
           }
           if(c == 57)
          {
            menu2();
           }
      }       
    }
 }



void menu2()
 {
   int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. abc");
      led.setCursor(20,17);
      led.print("3. def");
      led.setCursor(20,25);
      led.print("4. More");
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
            led.print("GOING BACK...");
            led.display();
            break;
          }
          if(c == 9)
          {
            //call_menu();
           }
          if(c == 17)
          {
            //hAuto();
           }
          if(c == 25)
          {
            //menu2_5();
           }
      }       
    }
 }


void menu3()
 {
   int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Cricket");
      led.setCursor(20,17);
      led.print("3. Dares");
      led.setCursor(20,25);
      led.print("4. abc");
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
            led.print("GOING BACK...");
            led.display();
            break;
          }
          if(c == 9)
          {
            cricket();
           }
          if(c == 17)
          {
            fun();
           }
          if(c == 25)
          {
            ///menu2();
           }
      }       
    }
 }


//////////////////////////////////.............................................................///////////////////////////////
void cricket()
 {
   int c = 1;
   fetchCric();
   score = "190/5";
   statuss = "Six!!!";
   teams = "IND Vs ENG";
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Status");
      led.setCursor(20,17);
      led.print("3. Score");
      led.setCursor(20,25);
      led.print("4. Teams");
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
            led.print("GOING BACK...");
            led.display();
            break;
          }
          if(c == 9)
          {
            displayy();
            led.setCursor(0,0);
            led.print(statuss);
            led.display();
            delay(2000);
           }
          if(c == 17)
          {
            displayy();
            led.setCursor(0,0);
            led.print(score);
            led.display();
            delay(2000);
           }
          if(c == 25)
          {
            displayy();
            led.setCursor(0,0);
            led.print(teams);
            led.display();
            delay(2000);
           }
      }       
    }
 }


void fetchCric()
{
  displayy();
  led.setCursor(0,0);
  led.print("Fetching datas...");
  led.display();
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    {
      http.begin("http://cricapi.com/api/cricketScore/COoffORMrJUjgxERepSmy2pudPu1?unique_id=918033");
    }
    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        int i = 0, j = 0;
        while (payload[i] != NULL)
        {

          if (payload[i] == 'm') {
            i=i+6;
            while (payload[i + 1] != '"') {
              //data[j] = payload[i + 1];
              j++;
              i++;
            }
            break;
          }
          i++;
        }
      } else {
        //USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    
    delay(100);
  }
}













void fun(){
   int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Count");
      led.setCursor(20,17);
      led.print("3. Dares");
      //led.setCursor(20,25);
      //led.print("4. More");
      led.setCursor(0,c);
      led.print("=>");
      led.display();
      
      int c1 = digitalRead(s1);
      int ok = digitalRead(s2);
      if(c1 == 1)
      {
         delay(500);
         if(c==17) //25)
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
            while(1){
              for(int i = 1;i<=9;i++)
               {  int esc = digitalRead(s1);
                  if(esc == 1){
                    delay(1000);
                    break;
                  }
                  led.clearDisplay();
                  led.setTextColor(WHITE);
                  led.cp437(true);
                  led.setTextSize(3);
                  led.setCursor(50,5);
                  led.print(i);
                  led.display();
                  delay(300);
               }break;
           }
          }
          if(c == 17)
          {
            displayy();
            led.setCursor(0,0);
            led.print("Take ur dare according to ur selected no.");
            led.display();
            delay(3000);
            
            displayy();
            led.setCursor(0,0);
            led.print("1. Display ur BF/GF/Crush Name on LCD(16*2)");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("2. Ask me any question");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("3. Burn Capacitor/Resistor,send video");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("4. Draw a Custom Char of LOVE on LCD(16*2)");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("5. Blink an LED without using 'delay()' function");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("6. Do a small project as my wish");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("7. Control LED's brightness according to room-light");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("8. Call ur GF/BF/crush using GSM module");
            led.display();
            delay(2000);

            displayy();
            led.setCursor(0,0);
            led.print("9. Display on LCD,live no. of Corona affected in IND & ur state");
            led.display();
            delay(2000);
           }
          /*if(c == 25)
          {
            menu2();
           }*/
      }       
    }
 }


 void call_menu()
 {
   int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. Back");
      led.setCursor(20,9);
      led.print("2. Contacts");
      led.setCursor(20,17);
      led.print("3. Enter No.");
      led.setCursor(20,25);
      led.print("4. More");
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
            led.print("GOING BACK...");
            led.display();
            break;
          }
          if(c == 9)
          {
            contacts();
           }
          if(c == 17)
          {
            enter_no();
           }
          if(c == 25)
          {
            //menu3();
           }
      }       
    }
 }
