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
