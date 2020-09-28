ESP8266WebServer server;
bool ota_flag = true;
uint16_t time_elapsed = 0;

void setupOta() {
  ArduinoOTA.setHostname("SmartWatch");
  
  ArduinoOTA.begin();

  server.on("/restart",[](){
    server.send(200,"text/plain", "Restarting...");
    delay(1000);
    ESP.restart();
  });

  server.on("/setflag",[](){
    server.send(200,"text/plain", "\n\nSetting flag...\nNow upload the code within 20 Sec.\nSMART WATCH\n(SOURAV)");
    ota_flag = true;
    time_elapsed = 0;
  });

  server.begin();
}

void loopOta() {
  if(ota_flag)
  {
    uint16_t time_start = millis();
    while(time_elapsed < 20000)
    {
      ArduinoOTA.handle();
      time_elapsed = millis()-time_start;
      delay(10);
    }
    ota_flag = false;
  }
  server.handleClient();
}
