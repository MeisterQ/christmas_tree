void mqttHandle()
{
  if ((!client.connected()) && (alarm == false))
  {
    mqttconnect();
  }
  client.loop();
}

void receivedCallback(char* topic, byte * payload, unsigned int length) {
#ifdef DEBUG
  Serial.print("Message received: ");
  Serial.println(topic);

  Serial.print("payload: ");
#endif
  for (int i = 0; i < length; i++) {
#ifdef DEBUG
    Serial.print((char)payload[i]);
#endif
  }
#ifdef DEBUG
  Serial.println();
#endif

  // Helligkeit LED

  if (strcmp((char*)topic, HELLIGKEIT_TOPIC) == 0)
  {
    ergebnis = 0;
    for (int i = 0; i < length; i++) ergebnis = (ergebnis * 10) + (payload[i] - '0');
    // ergebnis = atoi((const char*)payload);
    helligkeit = ergebnis;
    if (ledMode == 14 && dauerLicht == false)
    {
      pixels.setBrightness(helligkeit);
      pixels.show();
    }
#ifdef DEBUG
    Serial.println(ergebnis);
    Serial.println();
#endif
  }

  // Alarm

  if (strcmp((char*)topic, ALARM_TOPIC) == 0)
  {
    if (strncmp((char*)payload, "An", length) == 0)
    {
      alarmStatus = true;
      mqttFreigabe = 0;
#ifdef DEBUG
      Serial.print("Set AlarmStatus: ");
      Serial.println(alarmStatus);
#endif
    }
    else
    {
      alarmStatus = false;
#ifdef DEBUG
      Serial.print("Set AlarmStatus: ");
      Serial.println(alarmStatus);
#endif
    }
  }

  // Licht

  if (strcmp((char*)topic,  LICHT_TOPIC) == 0)
  {
    if (strncmp((char*)payload, "true", length) == 0)
    {
      licht = true;
    }
    else
    {
      licht = false;
    }
  }

  // Dauerlicht

  if (strcmp((char*)topic,  DAUER_TOPIC) == 0)
  {
    if (strncmp((char*)payload, "true", length) == 0)
    {
      dauerLicht = true;
    }
    else
    {
      dauerLicht = false;
    }
  }

  // Interval

  if (strcmp((char*)topic, MODUS_TOPIC) == 0)
  {
    intervalTemp = 0;
    for (int i = 0; i < length; i++) intervalTemp = (intervalTemp * 10) + (payload[i] - '0');
    ledMode = intervalTemp;
    Serial.println(intervalTemp);
    Serial.println();
  }

  // Onoff

  if (strcmp((char*)topic,  ONOFF_TOPIC) == 0)
  {
    if (strncmp((char*)payload, "true", length) == 0)
    {
      onoff = true;
    }
    else
    {
      onoff = false;
    }
  }

  // Alarm

  if (strcmp((char*)topic,  ALARM_TOPIC2 ) == 0)
  {
    if (strncmp((char*)payload, "true", length) == 0)
    {
      alarm = true;
    }
    else
    {
      alarm = false;
    }
  }
}
