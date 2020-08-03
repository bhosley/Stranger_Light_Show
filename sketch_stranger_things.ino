#include <FastLED.h>

#define PIN 4
#define NUM_LEDS 27
#define MES_LIM 16 //limit to length of message presented

CRGB leds[NUM_LEDS];
// These control RGB portions for letters 0,a-z
int red[NUM_LEDS]   = {random(0,255),255,0,200,0,0,255,255,0,0,255,0,255,255,250,0,255,255,0,255,255,0,255,0,255,0,255 };
int green[NUM_LEDS] = {random(0,255),255,0,0,200,255,255,0,0,250,0,250,255,200,0,255,255,0,255,255,255,0,0,0,255,255,0 };
int blue[NUM_LEDS]  = {random(0,255),255,255,255,255,0,0,0,255,255,250,0,255,0,255,0,255,0,255,255,0,255,0,255,0,0,255 };

char messages[][MES_LIM] = {
  "Hello World",
  "we’re all mad here",
  "here’s Johnny",
  "run",
  "hide",
  "too late",
  "beware",
  "goodbye",
  "help me",
  "stay with us",
  "scream for us",
  "trapped",
  "look alive",
  "rest in pieces",
  "die slowly",
  "come and play",
  "see you soon",
  "we’re waiting",
  "always watching you"
};

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
  FastLED.setBrightness( 200 ); 
}

int i = 0;

void loop() {
  // Randomly choose the next message to display
  i = random( 0, (int)sizeof(messages)/MES_LIM - 1);
  
  // Display message, one letter at a time
  for( int c = 0; c < MES_LIM; c++ ) {
    int LED_Address = getAddress(messages[i][c]);
    flashBulb(LED_Address);
  }

  // Random delay of 3 to 5 minutes between displays
  delay(random(180000,300000));
}

int getAddress(char c) {
/* 
 * Conversion of Char c into integer address
 *    Case insensitve, provides an integer corresponding 
 *    to the letter order in the English Alphabet, 
 *    indexed at 1. e.g. A = 1, a = 1.
 *    All other characters return 0.
 */
  if (c >= 'A' && c <= 'Z') {
    return (c - 'A' + 1);
  }
  else if (c >= 'a' && c <= 'z') {
    return (c - 'a' + 1);
  }
  else {
    return 0;
}

void flashBulb(int address) {
    // Set appropriate bulb to the appropriate color 
    // (as defined in the color arrays above)
  leds[address].setRGB( red[address], green[address] ,blue[address] );
  FastLED.show(); 
  delay( 500 );
    // Fade brightness by 128/256ths for 100 ms
    // This is to provide a sort of flicker effect
  leds[address].fadeToBlackBy( 128 );
  FastLED.show();
  delay( 100 ); 
    // Return bulb to black
  leds[address].setRGB ( 0, 0, 0 );
  FastLED.show();
  delay( 250 );
}
