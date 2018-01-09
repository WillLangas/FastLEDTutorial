#include <FastLED.h>
 
#define LED_PIN     1 //Arduino pin in use
#define NUM_LEDS    15 //Number of leds in array
#define BRIGHTNESS  100 //Brightness value 0-255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; //Initialize array for lights

#define UPDATES_PER_SECOND 20

CRGBPalette16 currentPalette; //Initializes that a palette is in use
TBlendType    currentBlending;

void setup() {
    delay(3000); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //Configures the strip
    FastLED.setBrightness(BRIGHTNESS);
    
    currentPalette = RainbowStripeColors_p; //Sets the starting palette
    currentBlending = LINEARBLEND; 
}

void loop()
{   
    Change();
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */

    Fill(startIndex); //Fills in the LED strip with given palette 
    
    FastLED.show(); //Built in function that displays the LEDS
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void Change()
{
    uint8_t secondHand = (millis() / 1000) % 60; //Internal clock begins in system 
    static uint8_t lastSecond = 99;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand; //Every 20 seconds, the palette and blending in use changes to one of these three
        if( secondHand >  0 && secondHand < 20)  { currentPalette = RainbowColors_p; currentBlending = LINEARBLEND; }
        if( secondHand >= 20 && secondHand < 40)  { currentPalette = RainbowStripeColors_p; currentBlending = NOBLEND;  }
        if( secondHand >= 40 && secondHand < 60)  { currentPalette = RainbowStripeColors_p; currentBlending = LINEARBLEND; }
    }
}

void Fill( uint8_t colorIndex) //Function that loops through and fulls the LED array
{
    uint8_t brightness = 255; 
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 15; // Lower this number if you want a more gradual color change
        //delay(750) Uncomment this line if you want the array to fill up consecutively
    }
}
