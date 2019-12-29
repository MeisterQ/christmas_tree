void modeWithWifi()
{
  if (alarm == false)
  {
    if (dauerLichtAn == false)      // Wenn Dauerlicht nicht aktiviert dann
    {
      if (ledMode == 2)
      {
        neopixelAus();
      }
      if (ledMode == 4)
      {
        pixels.setBrightness(helligkeit);
        neoPixelAus = false;
        neopixelWeiss();
      }
      if (ledMode == 6)
      {
        pixels.setBrightness(helligkeit);
        neoPixelAus = false;
        neopixelRot();
      }
      if (ledMode == 8)
      {
        pixels.setBrightness(helligkeit);
        neoPixelAus = false;
        neopixelGruen();
      }
      if (ledMode == 10)
      {
        pixels.setBrightness(helligkeit);
        neoPixelAus = false;
        neopixelBlau();
      }
      if (ledMode == 12)
      {
        pixels.setBrightness(helligkeit);
        neoPixelAus = false;
        neopixelGelb();
      }
      if (ledMode == 14)
      {
        neoPixelAus = false;
        whiteOverRainbow(255, 5);
      }
    }
  }
  if (alarm == true)
  {
    alarmLED();
    pixels.clear();
  }
  yield();
}
