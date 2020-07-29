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
int i = 0;

void setup() {
FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
FastLED.setBrightness( 200);
}

void loop(){  
i = random( 0 , NUM_WORDS - 1);
for(int pos = 0; pos < MES_LIM; pos++) {
  int cha = mes[ i ][ pos ];
      leds[cha].setRGB( red[cha], green[cha] ,blue[cha] ); //letter light and color
      FastLED.show(); //send 
      delay(500);
      leds[cha].fadeToBlackBy( 128 );
      FastLED.show();
      delay(100); 
      leds[cha].setRGB ( 0, 0, 0 );
      FastLED.show();
      delay(250);
}

delay(random(180000,300000)); //delay between words
}

