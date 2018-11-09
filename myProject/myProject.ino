//Will Langas
//November, 2018
//Bedroom Lights V1.5

#include <FastLED.h>

#define LED_PIN     4 //Arduino pin in use
#define NUM_LEDS    300 //Number of leds in array
#define BRIGHTNESS  100 //Brightness value 0-255
#define LED_TYPE    WS2811 
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS]; //Initialize array for lights

#define UPDATES_PER_SECOND 60

CRGBPalette16 currentPalette; //Initializes that a palette is in use
TBlendType    currentBlending;

void setup() {
  delay(3000); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //Configures the strip
  FastLED.setBrightness(BRIGHTNESS); //Set brightness

  pinMode(9,INPUT); //Switch inputs for binary selection
  pinMode(12,INPUT);

  Serial.begin(9600);
  Serial.println("System Initialized");

  currentPalette = RainbowColors_p; //Sets a starting palette, this palette is not used, only for startup
  currentBlending = LINEARBLEND;

  FastLED.setMaxPowerInVoltsAndMilliamps(5,1000); //IMPORTANT SHIT RIGHT HERE. LIMIT POWER THROUGH THIS LINE. COMMENT IF DESIRED.
}

DEFINE_GRADIENT_PALETTE( trove_gp ) { //Rainbowish
    0,  12, 23, 11,
   12,   8, 52, 27,
   25,  32,142, 64,
   38,  55, 68, 30,
   51, 190,135, 45,
   63, 201,175, 59,
   76, 186, 80, 20,
   89, 220, 79, 32,
  101, 184, 33, 14,
  114, 137, 16, 15,
  127, 118, 20, 27,
  140,  79, 16, 35,
  153,  67,  8, 26,
  165,  22,  9, 42,
  178,  11,  3, 34,
  191,  58, 31,109,
  204, 186, 49, 83,
  216, 182, 25, 55,
  229,  39, 90,100,
  242,  15, 81,132,
  255,  68,135, 52};

DEFINE_GRADIENT_PALETTE( aquamarinemermaid_gp ) { //Purple, Blue, Pink
    0,  23,  4, 32,
   63,  98, 31, 52,
  127, 224,138, 24,
  191,   7, 55,164,
  255,  23,  4, 32};

  DEFINE_GRADIENT_PALETTE( friendshipfairy_gp ) { //Yellows
    0,  98,103, 14,
   53, 128,111, 11,
   91, 132,109, 12,
  132, 167, 99,  7,
  160, 157,105, 10,
  193, 159,108, 11,
  247, 184,154, 47,
  255, 184,154, 47};

void loop()
{

  Serial.println("Digital Read 2: "); //For reference to switches
  Serial.println(digitalRead(9));
  Serial.println("Digital Read 3: ");
  Serial.println(digitalRead(12));
  
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  Fill(startIndex); //Fills in the LED strip with given palette

  FastLED.show(); //Built in function that displays the LEDS
  FastLED.delay(1000 / UPDATES_PER_SECOND);

  if(digitalRead(9) == 1 && digitalRead(12) == 1){ //11
    currentPalette = friendshipfairy_gp; currentBlending = LINEARBLEND;
  }else if(digitalRead(9) == 1 && digitalRead(12) == 0){ //10
    currentPalette = trove_gp; currentBlending = LINEARBLEND;
  } else if(digitalRead(9) == 0 && digitalRead(12) == 1){ //01
    currentPalette = aquamarinemermaid_gp; currentBlending = LINEARBLEND;
  } else if(digitalRead(9) == 0 && digitalRead(12) == 0){ //00
    currentPalette = OceanColors_p; currentBlending = LINEARBLEND;
    }
}

void Fill( uint8_t colorIndex) //Function that loops through and fulls the LED array
{
  uint8_t brightness = 100;

  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 15; // Lower this number if you want a more gradual color change
    //delay(750) Uncomment this line if you want the array to fill up consecutively
  }
}
