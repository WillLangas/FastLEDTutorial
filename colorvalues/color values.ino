#include <FastLED.h>

#define LED_PIN 3
#define NUM_LEDS 15
#define BRIGHTNESS 254
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
  delay(3000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

}
int cR = 20;
void loop() {
  // put your main code here, to run repeatedly
  int veces = 0;
  int purple = 0;
  int subPurp = 0;
  int green = 0;
  while (veces < 52) {
    for (int i = 0; i < NUM_LEDS; i++) {
      if (veces <= 260 / cR) {
        leds[i].setRGB(0, 255 - cR * veces, veces * cR);
        delay(50);
        FastLED.show();
      } else if (260 / cR < veces && 520 / cR >= veces) {
        leds[i].setRGB(purple * cR, 0, 255);
        delay(50);
        purple++;
        FastLED.show();
      } else if (520 / cR < veces && 780 / cR >= veces) {
        leds[i].setRGB(255 - subPurp * cR, 0, 255);
        delay(50);
        FastLED.show();
        subPurp++;
      } else {
        leds[i].setRGB(0, green * cR, 255 - green * cR);
        delay(50);
        FastLED.show();
        green++;
      }
      veces++;
    }
  }
}

