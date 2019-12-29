void mqttconnect()
{
  while (!client.connected())
  {
    Serial.print("MQTT connecting ...");
    Serial.println(connectsMQTT);

    String clientId = "ESP8266_Baum";

    if (client.connect(clientId.c_str()))
    {

#ifdef DEBUG
      Serial.println("connected");
#endif

      client.subscribe(HELLIGKEIT_TOPIC);
      client.subscribe(FARBE_TOPIC);
      client.subscribe(ALARM_TOPIC);
      client.subscribe(LICHT_TOPIC);
      client.subscribe(MQTT_TOPIC);
      client.subscribe(DAUER_TOPIC);
      client.subscribe(MODUS_TOPIC);
      client.subscribe(LICHT_TX_TOPIC);
      client.subscribe(ALARM_TOPIC2);
    }
  }
}
