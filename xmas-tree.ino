/*
 * Christmas tree by designer2k2.at
 * Stephan Martin 2016
 * http://www.designer2k2.at
 * https://github.com/designer2k2/xmas-tree
 * 
 * This code is made to run on a Digispark
 * Feeding Neopixel Rings, stacked to a tree.
 * 
 * Brightness is reduced as there is only USB power supply.
 * 
 */


#include <Adafruit_NeoPixel.h>    //needed for the WS2812
#include <avr/pgmspace.h>		      //needed for PROGMEM

#define PIN 2					            //Pin 1 is DATA In on the bottom Ring
#define BRIGHTNESS 10 			      // brightness reduced
#define PIXELCOUNT  93            //Num of LEDs


//Lookups for the X-M-A-S Letters viewed from above:
 const unsigned int charX[] PROGMEM = 
 { 
   4,27,54,61,58,35,16,10,31,56,60,39,22
 };
 const unsigned int charM[] PROGMEM = 
 { 
   4,26,25,40,22,39,60,61,58,35,16,34,33,32,10
 };
  const unsigned int charA[] PROGMEM = 
 { 
   4,27,42,53,60,51,37,19,49,58,57,61,46,31,10
 };
  const unsigned int charS[] PROGMEM = 
 { 
  22,38,37,36,35,34,47,57,61,53,41,26,27,28,29,30,10
 };

 //Lookup for the Candle light
 const unsigned int candles[] PROGMEM = 
 { 
  //15,10,48,45,36,19,59,29,5,43,41,39,24,3,61
  //Ring 1
  0,3,7,11,15,19,23,27,
  //Ring 2
  32,35,38,42,44,47,50,53,
  //Ring 3
  56,58,60,62,64,66,68,70,
  //Ring 4
  72,75,79,82,
  //Ring 5
  84,86,88,90,
  //Star
  92
 };

//Lookup for individual rings
int numOfRings = 6;
int ring6 = 1;
int ring5 = 8;
int ring4 = 12;
int ring3 = 16;
int ring2 = 24;
int ring1 = 32;

int ring1start = 0;
int ring1stop = ring1start + ring1 - 1;

int ring2start = ring1;
int ring2stop = ring2start + ring2 - 1;

int ring3start = ring1 + ring2;
int ring3stop = ring3start + ring3 - 1;

int ring4start = ring1 + ring2 + ring3;
int ring4stop = ring4start + ring4 - 1;

int ring5start = ring1 + ring2 + ring3 + ring4;
int ring5stop = ring5start + ring5 - 1;

int ring6start = ring1 + ring2 + ring3 + ring4 + ring5;
int ring6stop = ring6start + ring6 - 1;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELCOUNT, PIN, NEO_GRB + NEO_KHZ800);

//Lookup for twinkle colors
uint32_t off = strip.Color(0, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t red = strip.Color(255, 0, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t white = strip.Color(127, 127, 127);
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t cyan = strip.Color(0,255,255);
uint32_t twinkle_colors[] = {green, red, blue,magenta,yellow,cyan};


void setup() {
  pinMode(PIN, OUTPUT);
  strip.begin();
  strip.setBrightness(BRIGHTNESS); // set brightness
  strip.show(); // Initialize all pixels to 'off'
  
  //XMAS Letters:
  //xmas();
  //delay(2000);  
}

void loop() {

  colorWipe(twinkle_colors[random(0,5)],50);
  //colorWipe(twinkle_colors[5],50);
  strip.show();
  delay(1000);
    
  //Tree light:
  //tree();
  //delay(1000);

  //Color crazy:
  //colorcrazy();
  //delay(1000);

  //warpdrive();
  //comet();

//  for(int i = 0; i <= 10; i++){
//    ringByRing(strip.Color(0,255,0),50);
  //}
  //delay(1000);
  //twinkles(10);
  
  /*
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127,   0,   0), 50); // Red
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
*/
}

//Sub-----------------------------------------------------------------------

//Comet
void comet(){
  for(uint16_t i=strip.numPixels(); i>0; i--) {
     strip.setPixelColor(i,strip.Color(0, 0, 255));
     fadethemall(10);
     fadethemall(10);
  }
}

//From top down white pulses
void warpdrive(){

  //Top Led
  strip.setPixelColor(PIXELCOUNT - 1,strip.Color(255, 255, 255));
  strip.show();
  //fade a bit
  for (int i = 0; i < 20; i++)
  {
    fadethemall(20);
  } 
  //8 Ring
  for (int i = ring5start; i <= ring5stop; i++)
  {
    strip.setPixelColor(i,strip.Color(255, 255, 255));
  }
  strip.show();
  //fade a bit
  for (int i = 0; i < 20; i++)
  {
    fadethemall(20);
  } 
  //12 Ring
  for (int i = ring4start; i <= ring4stop; i++)
  {
    strip.setPixelColor(i,strip.Color(255, 255, 255));
  }
  strip.show();
  //fade a bit
  for (int i = 0; i < 20; i++)
  {
    fadethemall(20);
  } 
  //16 Ring
  for (int i = ring3start; i <= ring3stop; i++)
  {
    strip.setPixelColor(i,strip.Color(255, 255, 255));
  }
  strip.show();
  //fade a bit
  for (int i = 0; i < 20; i++)
  {
    fadethemall(20);
  }
  //24 Ring
  for (int i = ring2start; i <= ring2stop; i++)
  {
    strip.setPixelColor(i,strip.Color(255, 255, 255));
  }
  strip.show();
  //fade a bit
  for (int i = 0; i < 20; i++)
  {
    fadethemall(20);
  }
  //32 Ring
  for (int i = ring1start; i <= ring1stop; i++)
  {
    strip.setPixelColor(i,strip.Color(255, 255, 255));
  }
  strip.show();
  //fade a bit
  for (int i = 0; i < 20; i++)
  {
    fadethemall(20);
  }
}

//This reduces the brightness of all leds
void fadethemall(uint8_t wait){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      uint32_t color = strip.getPixelColor(i);
      int r;
      int g;
      int b;
      r = (uint8_t)(color >> 16);
      g = (uint8_t)(color >>  8);
      b = (uint8_t)color;

      if(r>0)
      {
        r = r - 1;
      }
      else
      {
        r = 0;
      }

      if(g>0)
      {
        g = g - 1;
      }
      else
      {
        g = 0;
      }

      if(b>0)
      {
        b = b - 1;
      }
      else
      {
        b = 0;
      }
      
      strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
  delay(wait);
}

//This drives the WS2812 in a crazy pattern, fun!
void colorcrazy(){ 
  colorWipe(strip.Color(255, 0, 0), 25); // Red
  colorWipe(strip.Color(0, 255, 0), 25); // Green
  colorWipe(strip.Color(0, 0, 255), 25); // Blue  
  theaterChaseRainbow(5);
}

//This lights up the tree in green, then add the white "candles"
void tree(){

  colorWipe(strip.Color(0, 50, 0), 50); // Green

  //light "candles"
  for (int i = 0; i < 33; i++)
  {
    strip.setPixelColor(pgm_read_word(&candles[i]),strip.Color(255, 255, 255));
    strip.show();
    delay(50);
  }

}

//This shows the X-M-A-S when viewed from above
void xmas(){

  colorWipe(strip.Color(0, 0, 0), 0); // blank

  
  //The size of the PROGMEM is hardcoded, as the sizeof does return crap on the ATtiny.
  
  //Show the X:
  for (int i = 0; i < 13; i++)
  {
    strip.setPixelColor(pgm_read_word(&charX[i])-1,strip.Color(255, 0, 0));
        strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the M:
  for (int i = 0; i < 15; i++)
  {
    strip.setPixelColor(pgm_read_word(&charM[i])-1,strip.Color(0, 255, 0));
    strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the A:
  for (int i = 0; i < 15; i++)
  {
    strip.setPixelColor(pgm_read_word(&charA[i])-1,strip.Color(0, 0, 255));
    strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the S:
  for (int i = 0; i < 17; i++)
  {
    strip.setPixelColor(pgm_read_word(&charS[i])-1,strip.Color(125, 125, 125));
    strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

//Light the rings one by one, and finally the star
//Light the bottom ring green
void ringByRing(uint32_t c, uint8_t wait) {
  for(int i = ring1start; i <= ring1stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring2start; i <= ring2stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring3start; i <= ring3stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring4start; i <= ring4stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring5start; i <= ring5stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring6start; i <= ring6stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  
  //Turn off all pixels
  c = strip.Color(0,0,0);
  for(int i = ring1start; i <= ring1stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring2start; i <= ring2stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring3start; i <= ring3stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring4start; i <= ring4stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring5start; i <= ring5stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  for(int i = ring6start; i <= ring6stop; i++){
    strip.setPixelColor(i,c);
  }
  strip.show();
  delay(wait);
  }

 void twinkles(int loops){
  colorWipe(strip.Color(0,255,0),0);
  strip.setPixelColor(PIXELCOUNT -1, strip.Color(255,255,255));
  strip.show();

  
 }

