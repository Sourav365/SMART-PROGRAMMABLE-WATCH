void replyy();
String rec_msg, sent_msg; 

void messages()
{   
  rec_msg = Firebase.getString("msg_send");
  while(1){
    int i = 0;
    
    if(i%3 == 0)  {
      rec_msg = Firebase.getString("msg_send");
      sent_msg = Firebase.getString("msg_rec");
    }
    
    displayy();
    led.setCursor(0,0); 
    led.print("< ");
    led.print(rec_msg);
    
    led.setCursor(0,38); 
    led.print(sent_msg);
    led.setCursor(50,55);
    led.print("Reply");
    led.display();
    
    int reply_b = digitalRead(s2);
    int esc = digitalRead(s1);
    if(reply_b == 1)
    {
      delay(500);
      replyy();
    }
    if(esc == 1)
    {
      delay(500);
      break;
    }    
    i++;
  }
}

void replyy(){
  int c = 1;
   while(1)
    {
      displayy();
      led.setCursor(20,1);
      led.print("1. I'm busy.");
      led.setCursor(20,9);
      led.print("2. Now at college.");
      led.setCursor(20,17);
      led.print("3. Calling later.");
      led.setCursor(20,25);
      led.print("4. Plz come.");
      led.setCursor(20,33);
      led.print("5. Emergency case.");
      led.setCursor(20,41);
      led.print("6. Bye, take care.");
      led.setCursor(20,49);
      led.print("7. I miss U.");
      led.setCursor(20,57);
      led.print("8. More");
      led.setCursor(0,c);
      led.print("=>");
      led.display();
      delay(700);
      
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
        switch(c){
          case 1: Firebase.setString("msg_rec", "> I'm busy.");  /// Can u go for outing now?/////Can u come here now?
                  break;
          case 9: Firebase.setString("msg_rec", "> Now I'm at college."); /// Oiiii, kothay re?///Where r u now?
                  break;
          case 17: Firebase.setString("msg_rec", "> Calling you later."); /// I've something to discuss.....
                   break;
          case 25: Firebase.setString("msg_rec", "> Plz come here asap."); //// Oiii....
                   break;
          case 33: Firebase.setString("msg_rec", "> Emergency case.....HELP!!!"); /// What happened!!??
                   break;
          case 41: Firebase.setString("msg_rec", "> Bye, take care."); ///Tata I'm going...
                   break;
          case 49: Firebase.setString("msg_rec", "> I miss you toooooo much."); /// I'am also missing u.....
                   break;
          case 57: //rply_menu2();
                   break;
        }
        displayy();
        led.setCursor(10,10); 
        led.print("Sending.....");
        led.display();
        delay(600);
        break;
      }       
    }
}
