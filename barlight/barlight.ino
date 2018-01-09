/* downline
 * Will Langas
 * 1/9/2018
 * Open to public use and modification 
 */

#include <FastLED.h>

#define LED_PIN     1
#define NUM_LEDS    15
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {
 delay( 3000 ); // power-up safety delay
 FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
 FastLED.setBrightness(  BRIGHTNESS );
}

int i = 0; //counter variable
void loop() {
  for(i=0;i<NUM_LEDS;i++){
      leds[i] = CRGB::White; //Sets a light to green
      FastLED.show();
      delay(500);
  }
}
