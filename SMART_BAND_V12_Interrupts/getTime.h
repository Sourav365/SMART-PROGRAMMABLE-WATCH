unsigned int localPort = 2390;      // local port to listen for UDP packets

IPAddress timeServerIP; 
const char* ntpServerName = "in.pool.ntp.org";////////////////////CAN CHANGE THE SERVER//////////////////////////////

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message

byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;
void sendNTPpacket(IPAddress& address) {
  //Serial.println("sending NTP packet...");
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  udp.beginPacket(address, 123); //NTP requests are to port 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}
void setup_time() {  
  udp.begin(localPort);
}

int get_time() {
  WiFi.hostByName(ntpServerName, timeServerIP);

  sendNTPpacket(timeServerIP); // send an NTP packet to a time server
  delay(1000);

  int cb = udp.parsePacket();
  if (!cb) {
    //Serial.println("no packet yet");
  }
  else {
    //Serial.print("packet received, length=");
    //Serial.println(cb);
    udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

    //the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    
    /////////////// this is NTP time (seconds since Jan 1 1900)://///////////////////////////////////////////////////////
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    
    ////////////// Unix time starts on Jan 1 1970. In seconds, that's 2208988800:.........70 years in sec. = 2208988800///////
    const unsigned long seventyYears = 2208988800UL;
    /////////////Unix time (GMT) = NTP time - (1970-1900)/////////////////////////////////////////////////////////////////////////
    unsigned long epoch = secsSince1900 - seventyYears + 19800;///////19800 = 5 hrs. + 30 mins.//////FOR INDIA TIME = GMT+05:30:00
    /// UTC is the time at Greenwich Meridian (GMT)



    
//.............................................................................................................................
     //Serial.print(epoch);////////////UTC + 5:30:00/////////////////SEND TIME AS SECOND TO SLAVE/////////////////////////////////////
     return epoch;
  }
}
