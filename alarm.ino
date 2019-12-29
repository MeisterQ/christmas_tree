void alarmLED()
{
  if ((alarmZyklen < 5) && (alarmZyklen2 <= 5))
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.clear();
      pixels.setPixelColor(i % NUMPIXELS, pixels.Color(255, 0, 0, 0));
      pixels.setPixelColor((i - 1) % NUMPIXELS, pixels.Color(100, 0, 0, 0));
      pixels.setPixelColor((i - 2) % NUMPIXELS, pixels.Color(20, 0, 0, 0));
      pixels.setPixelColor((i - 3) % NUMPIXELS, pixels.Color(0, 0, 0, 0));
      pixels.show();
      delay(70);
    }
    alarmZyklen++;
  }
  if ((alarmZyklen >= 5) && (alarmZyklen2 <= 5))
  {
    for (int j = 0; j < 5; j++)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
        pixels.show();
      }
      delay(50);
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0));
        pixels.show();
      }
      delay(50);
    }
    alarmZyklen = 0;
    alarmZyklen2++;
  }


  if (alarmZyklen2 > 5)
  {
    for (int j = 0; j < 1; j++)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
        pixels.show();
      }
      delay(500);
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 255, 0));
        pixels.show();
      }
      delay(500);
    }
    alarmZyklen2++;
  }



  if (alarmZyklen2 >= 10)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
        pixels.show();
      }
      delay(50);
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0));
        pixels.show();
      }
      delay(500);
    }
    alarmZyklen2 = 0;
  }
}
