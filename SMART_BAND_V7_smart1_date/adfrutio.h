#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL

#define AIO_USERNAME    "Sourav1999"
#define AIO_KEY         "e74c04d97cac4962a3b1b1d6deae0570"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Adafruit_MQTT_Publish find_mob = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/mobile");///////////change feeds name////////////
Adafruit_MQTT_Subscribe notifi = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/notification");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MQTT_connect();

void adafruiti(int data) {
   MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {   
  }
////////////////////////////////////////////////////working space/////////////////////////////////////////////
 
  find_mob.publish(data);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void notific()
{
  MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;//Adafruit_MQTT_Subscribe type pointer which will fetch values from feeds
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &notifi) {
      //Serial.print(F("Notification : "));      
      //Serial.println((char *)notifi.lastread);
      notiii = (char *)notifi.lastread;
      //scroll();
    }
  }
  led.setTextSize(1);
  led.setCursor(0,17);
  led.print(notiii);
  //led.display();
}


void MQTT_connect() {
  int8_t ret;
  if (mqtt.connected()) {
    return;
  }

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { 
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         while (1);
       }
  }
}
