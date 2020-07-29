#include <FastLED.h>

#define PIN 4
#define NUM_LEDS 27
#define MES_LIM 16 //limit to length of message presented
#define NUM_WORDS 19 //number of words in word matrix below

CRGB leds[NUM_LEDS];
int red[NUM_LEDS] = {random(0,255),255,0,200,0,0,255,255,0,0,255,0,255,255,250,0,255,255,0,255,255,0,255,0,255,0,255 };
int green[NUM_LEDS] = {random(0,255),255,0,0,200,255,255,0,0,250,0,250,255,200,0,255,255,0,255,255,255,0,0,0,255,255,0 };
int blue[NUM_LEDS] = {random(0,255),255,255,255,255,0,0,0,255,255,250,0,255,0,255,0,255,0,255,255,0,255,0,255,0,0,255 }; //these control RGB portions for letters 0,a-z
int mes[ ][MES_LIM] = {
  {8,5,12,12,15,0,23,15,18,12,4,0,0,0,0,0 }, //hello world
  {0,23,5,18,5,1,12,12,13,1,4,8,5,18,5,0 }, //we’re all mad here
  {0,8,5,18,5,19,0,10,15,8,14,14,25,0,0,0 }, //here’s Johnny
  {0,0,0,18,21,14,0,0,0,0,0,0,0,0,0,0 }, // run
  {0,0,0,8,9,4,5,0,0,0,0,0,0,0,0,0 }, // hide
  {0,0,20,15,15,0,1,20,5,0,0,0,0,0,0 }, // too late
  {0,0,2,5,23,1,18,5,0,0,0,0,0,0,0,0 }, // beware
  {0,0,7,15,15,4,2,25,5,0,0,0,0,0,0,0 }, // goodbye
  {0,0,8,5,12,16,0,13,5,0,0,0,0,0,0,0 }, // help me
  {0,19,20,1,7,0,23,9,20,8,0,21,19,0,0,0 }, // stay with us
  {0,19,3,18,5,1,13,0,6,15,18,0,21,19,0,0 }, // scream for us
  {0,0,0,20,18,1,16,16,5,4,0,0,0,0,0,0 }, // trapped
  {0,12,15,15,11,0,1,12,9,22,5,0,0,0,0,0}, // look alive
  {0,18,5,19,20,0,9,14,0,16,9,5,2,5,19,0}, //rest in pieces
  {0,0,4,9,5,0,19,12,15,23,12,25,0,0,0,0 }, // die slowly
  {0,3,15,13,5,0,1,14,4,0,16,12,1,25,0,0 }, //come and play
  {0,19,5,5,0,25,15,21,0,19,15,15,14,0,0,0 }, // see you soon
  {0,23,5,18,5,0,23,1,9,20,9,14,7,0,0,0 }, // we’re waiting
  {1,12,23,1,25,19,23,1,20,3,8,9,14,25,15,21 } // always watching you
};

char messages[][MES_LIM] = {
  "hello world",
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

int i = 0;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
  FastLED.setBrightness( 200 );
}

void oldLoop(){  
  i = random( 0 , NUM_WORDS - 1);
  for(int pos = 0; pos < MES_LIM; pos++) {
    int cha = mes[ i ][ pos ];
  }
}

void loop() {
  // Randomly choose the next message to display
  i = random( 0, (int)sizeof(messages)/MES_LIM - 1);
  
  // Display message, one letter at a time
  for(int c = 0; c < MES_LIM; c++) {
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
