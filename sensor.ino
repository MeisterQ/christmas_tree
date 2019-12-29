void sensor()
{
  tasterStatus = digitalRead(16);
  if (tasterStatus == HIGH)
  {
    delay(50);
  }
  if (tasterStatus == HIGH && ledMode == 0)
  {
    ledMode = 1;
  }
  if (tasterStatus == LOW && ledMode == 1)
  {
    ledMode = 2;
  }
  if (tasterStatus == HIGH && ledMode == 2)
  {
    ledMode = 3;
  }
  if (tasterStatus == LOW && ledMode == 3)
  {
    ledMode = 4;
  }
  if (tasterStatus == HIGH && ledMode == 4)
  {
    ledMode = 5;
  }
  if (tasterStatus == LOW && ledMode == 5)
  {
    ledMode = 6;
  }
  if (tasterStatus == HIGH && ledMode == 6)
  {
    ledMode = 7;
  }
  if (tasterStatus == LOW && ledMode == 7)
  {
    ledMode = 8;
  }
  if (tasterStatus == HIGH && ledMode == 8)
  {
    ledMode = 9;
  }
  if (tasterStatus == LOW && ledMode == 9)
  {
    ledMode = 10;
  }
  if (tasterStatus == HIGH && ledMode == 10)
  {
    ledMode = 11;
  }
  if (tasterStatus == LOW && ledMode == 11)
  {
    ledMode = 12;
  }
  if (tasterStatus == HIGH && ledMode == 12)
  {
    ledMode = 13;
  }
  if (tasterStatus == LOW && ledMode == 13)
  {
    ledMode = 14;
  }
  if (tasterStatus == HIGH && ledMode == 14)
  {
    ledMode = 0;
  }

  if (ledMode != old_ledMode)
  {
    snprintf (Mode, 3, "%ld", ledMode);
    old_ledMode = ledMode;
    client.publish(DEBUG_TOPIC, Mode);
  }



  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    Serial.print("LED-Mode: ");
    Serial.println(ledMode);
  }
}
