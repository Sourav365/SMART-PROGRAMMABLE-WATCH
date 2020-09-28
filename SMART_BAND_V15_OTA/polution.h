int PM25(void)
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    {
      http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=NLUQ0VCT2RSN35UT");
      //Serial.print("PM 2.5 in Air : ");
    }

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
        //Serial.print(data);
        //Serial.print("  in μg/m³\n");
      } else {
        //USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
    delay(700);
    int ss = atoi(data);
    return ss;
  }
}

int PM10(void)
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    {
      http.begin("http://api.thingspeak.com/apps/thinghttp/send_request?api_key=KS2PQ0JS6XMK9JTM");
      //Serial.print("PM 10 in Air : ");
    }
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
        //Serial.print(data);
        //Serial.print("  in μg/m³\n");
      } else {
        //USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    delay(700);
    int ss = atoi(data);
    return ss;
  }
}
