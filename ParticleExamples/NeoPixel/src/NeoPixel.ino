#include "neopixel.h"

// Let a NeoPixel blink green and red on Pin D6
// Please note that you need a voltage regulator,
// as the particle only support 3,3V output, but the Nepixel needs 5V

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, D6, WS2812B2);

void setup()
{
  pixel.begin();
  pixel.show(); // Initialize all pixels to 'off'
}

void loop()
{
  pixel.setColor(0, 255,0,0);
  pixel.show();
  delay(1000);
  pixel.setColor(0, 0,255,0);
  pixel.show();
  delay(1000);
}
