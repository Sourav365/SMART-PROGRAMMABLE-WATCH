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
      notiii = (char *)notifi.lastread;
      if(notiii[0] != ('C'||'A'))
      {
        noti_prev = notiii;
      }
    }
  }
  led.setTextSize(1);
  led.setCursor(0,33);
  led.print(noti_prev);
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
