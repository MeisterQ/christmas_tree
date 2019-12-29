void serialAusgabe()
{
  if (withoutWifi == false)
  {
    Serial.print("WiFi Connected");
    Serial.println("Loop fertig");
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
    Serial.print("RSSI: ");
    Serial.println(WiFi.RSSI());
    Serial.print("MAC: ");
    Serial.println(WiFi.macAddress());
  }
}
