# Guide 
Here is a guide for a simple program using the Fast LED library 

1. When setting up a program, a few global variables need to defined first. Use the following syntax to define them,
their purpose is described in a comment next to each variable

```
#include <FastLED.h>

#define LED_PIN     5 //The arduino pin outputting to the LEDs
#define NUM_LEDS    14 //The number of LEDs in use
#define BRIGHTNESS  64 //The brightness of the lights (Optional)
#define LED_TYPE    WS2811 //The type of LEDs in use
#define COLOR_ORDER GRB //The type of color convention in use

```
2. Next, an array must be made in order to store the LED values, and another variable must be defined to set the 
amount of updates that will occur each second within the program
  a. The CRGB is used to intialize an array, with the same size as the amount of lights in your strip
  b. The array is used to control the individual lights, since each array element has a corresponding light

```
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100
```
3. Next is the setup portion of code, which includes 3 lines
  a. First we must delay the system startup in order to protect the system, we will use a 3 second delay to do so
  b. Then, we must use the addLeds function to configure the program to the hardware
  c. Last, we must set the brightness of the LEDs to the brightness value we defined earlier, such is optional
  
```   
delay( 3000 ); // power-up safety delay
FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
FastLED.setBrightness(BRIGHTNESS);
```

4. Now is time for the actual code to run and the LEDs to show. Doing so requires two parts
  a. First, a color much be assigned to a specific LED, or spot on the leds[] array
  b. Then, the FastLED.show()function must be called to physically turn on the lights, doing so will
  display the light assignments we just set

Here is some code that makes the first light on the strip blink red on and off 

``` 
void loop(){
  leds[0] = CRGB::Red; //Sets the first light to red
  FastLED.show();
  delay(750); //750 ms delay
  leds[0] = CRGB::Black; //Sets the first light to black (Off)
  FastLED.show();
  delay(750);
}
```

Now that we have all the working pieces, we can combine them into one complete program, that will
repeatedly flash a red light on and off

Find the full program in the guide.ino file

