#include <FastLED.h>

#define LED_PIN     1
#define NUM_LEDS    15
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(750);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(750);
}
