void weather(void)
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    {
      http.begin("http://api.openweathermap.org/data/2.5/weather?q=Bhubaneshwar,in&APPID=df22d4e9f4d880d2ddc99c85a95587ff");
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
              data[j] = payload[i + 1];
              j++;
              i++;
            }
            break;
          }
          i++;
        }
        //Serial.println(data);
        led.setTextSize(1);
        led.setCursor(20,25);
        led.print("Weather : ");
        led.print(data);
        //led.display();
      } else {
        //USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    delay(100);
  }
}
