void wifiSettings()
{
  //  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet, dns);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    unsigned long currentMillis5 = millis();
    if (currentMillis5 - previousMillis5 >= interval5)
    {
      previousMillis5 = currentMillis5;
      connects++;
      Serial.println(connects);
    }
    if (connects <= 10)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.clear();
        pixels.setPixelColor(i % NUMPIXELS, pixels.Color(0, 255, 0, 0));
        pixels.setPixelColor((i - 1) % NUMPIXELS, pixels.Color(0, 100, 0, 0));
        pixels.setPixelColor((i - 2) % NUMPIXELS, pixels.Color(0, 20, 0, 0));
        pixels.setPixelColor((i - 3) % NUMPIXELS, pixels.Color(0, 0, 0, 0));
        pixels.show();
        delay(70);
      }
    }
    if (connects > maxConnects)
    {
      restartESP();
      withoutWifi = true;
      Serial.println("Mode without WiFi");
      Serial.println(withoutWifi);
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255, 0));
      pixels.show();
    }
    delay(blinkDelay);
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0));
      pixels.show();
    }
    delay(blinkDelay);
  }

}
