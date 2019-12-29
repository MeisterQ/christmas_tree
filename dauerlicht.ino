void dauerlicht()
{
  if ((dauerLicht == false) && (dauerLichtAus == false))
  {
    dauerLichtAn = false;
    client.publish(DEBUG_TOPIC, "Dauerlicht Aus");
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0));
      pixels.show();
    }
    dauerLichtAus = true;
  }
  if ((dauerLicht == true) && (dauerLichtAn == false))
  {
    pixels.setBrightness(255);
    dauerLichtAn = true;
    client.publish(DEBUG_TOPIC, "Dauerlicht An");
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, 255));
      pixels.show();
    }
    dauerLichtAus = false;
  }
}
