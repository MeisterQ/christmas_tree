void restartESP()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0, 0));
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
