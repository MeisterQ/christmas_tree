void neopixelFade()
{
}



void neopixelAus()
{
  if (neoPixelAus == false)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, 0));
      pixels.show();
      delay(50);
    }
    neoPixelAus = true;
    neoPixelRotAn = false;
    neoPixelGruenAn = false;
    neoPixelBlauAn = false;
    neoPixelGelbAn = false;
    yield();
  }
}

void neopixelWeiss()
{
  if (neoPixelWeissAn == false)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0, helligkeit));
      pixels.show();
      delay(50);
    }
    neoPixelWeissAn = true;
    neoPixelRotAn = false;
    neoPixelGruenAn = false;
    neoPixelBlauAn = false;
    neoPixelGelbAn = false;
    yield();
  }
}


void neopixelRot()
{
  if (neoPixelRotAn == false)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(helligkeit, 0, 0, 0));
      pixels.show();
      delay(50);
    }
    neoPixelWeissAn = false;
    neoPixelRotAn = true;
    neoPixelGruenAn = false;
    neoPixelBlauAn = false;
    neoPixelGelbAn = false;
    yield();
  }
}

void neopixelGruen()
{
  if (neoPixelGruenAn == false)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, helligkeit, 0, 0));
      pixels.show();
      delay(50);
    }
    neoPixelWeissAn = false;
    neoPixelRotAn = false;
    neoPixelGruenAn = true;
    neoPixelBlauAn = false;
    neoPixelGelbAn = false;
    yield();
  }
}

void neopixelBlau()
{
  if (neoPixelBlauAn == false)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, helligkeit, 0));
      pixels.show();
      delay(50);
    }
    neoPixelWeissAn = false;
    neoPixelRotAn = false;
    neoPixelGruenAn = false;
    neoPixelBlauAn = true;
    neoPixelGelbAn = false;
    yield();
  }
}

void neopixelGelb()
{
  if (neoPixelGelbAn == false)
  {
    for (int i = 0; i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(helligkeit, helligkeit, 0, 0));
      pixels.show();
      delay(50);
    }
    neoPixelWeissAn = false;
    neoPixelRotAn = false;
    neoPixelGruenAn = false;
    neoPixelBlauAn = false;
    neoPixelGelbAn = true;
    yield();
  }
}



void whiteOverRainbow(int whiteSpeed, int whiteLength) {

  if (whiteLength >= pixels.numPixels()) whiteLength = pixels.numPixels() - 1;

  int      head          = whiteLength - 1;
  int      tail          = 0;
  int      loops         = 3;
  int      loopNum       = 0;
  uint32_t lastTime      = millis();
  uint32_t firstPixelHue = 0;

  for (;;) { // Repeat forever (or until a 'break' or 'return')
    for (int i = 0; i < pixels.numPixels(); i++) { // For each pixel in pixels...
      if (((i >= tail) && (i <= head)) ||     //  If between head & tail...
          ((tail > head) && ((i >= tail) || (i <= head)))) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0, helligkeit + 50)); // Set white
      } else {                                             // else set rainbow
        int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
        pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
      }
    }
    sensor();                       // Sensor einlesen an Digitalpin
    if (withoutWifi == false)
    {
      mqttHandle();                   // Sende Daten an MQTT Server
    }
    yield();
    pixels.show(); // Update pixels with new contents
    // There's no delay here, it just runs full-tilt until the timer and
    // counter combination below runs out.

    firstPixelHue += 40; // Advance just a little along the color wheel

    if ((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
      if (++head >= pixels.numPixels()) {     // Advance head, wrap around
        head = 0;
        if (++loopNum >= loops) return;
      }
      if (++tail >= pixels.numPixels()) {     // Advance tail, wrap around
        tail = 0;
      }
      lastTime = millis();                   // Save time of last movement
    }
    if (ledMode != 14)
    {
      return;
    }
  }
}
