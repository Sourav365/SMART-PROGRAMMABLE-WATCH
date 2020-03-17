#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define host "e-health-t3.firebaseio.com"
#define auth "76CTSpklGhGtWshWscIdEEVAoUY8iF25eOVc36G5"

String bmi,o2,bp,btemp,pulse,fstep;

void fb() {
  
  bmi = Firebase.getString("BMI");
  o2 = Firebase.getString("BO2");
  bp = Firebase.getString("BP");
  btemp = Firebase.getString("TEMP");
  pulse = Firebase.getString("PR");
  fstep = Firebase.getString("FS");
  
  if(Firebase.failed())
    //Serial.println(Firebase.error());
    
  delay(1000);
}
