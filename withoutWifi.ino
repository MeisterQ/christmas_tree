void modeWithoutWifi()
{
  if (ledMode == 2)
  {
    neopixelAus();
  }
  if (ledMode == 4)
  {
    pixels.setBrightness(100);
    neoPixelAus = false;
    neopixelWeiss();
  }
  if (ledMode == 6)
  {
    pixels.setBrightness(100);
    neoPixelAus = false;
    neopixelRot();
  }
  if (ledMode == 8)
  {
    pixels.setBrightness(100);
    neoPixelAus = false;
    neopixelGruen();
  }
  if (ledMode == 10)
  {
    pixels.setBrightness(100);
    neoPixelAus = false;
    neopixelBlau();
  }
  if (ledMode == 12)
  {
    pixels.setBrightness(100);
    neoPixelAus = false;
    neopixelGelb();
  }
  if (ledMode == 14)
  {
    neoPixelAus = false;
    whiteOverRainbow(255, 5);
  }
}
