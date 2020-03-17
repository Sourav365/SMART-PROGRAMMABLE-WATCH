int temp(void)
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=JZHQ7Z448G8RWAN2");
   
    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        int i = 0, j = 0;
        while (payload[i] != NULL)
        {

          if (payload[i] == '>') {
            while (payload[i + 1] != '<') {
              data[j] = payload[i + 1];
              j++;
              i++;
            }
            break;
          }
          i++;
        }
        //Serial.print("Temperature : ");
        //Serial.print(data);
        //Serial.print("  in μg/m³\n");
      } else {
        //USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    delay(500);
    return atoi(data);
  }
}
