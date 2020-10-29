// ********************************************************************
//
// Don't forget to install the Fastled library for this example to work
//
// ********************************************************************


// Adding the library
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 5

// Define what pins you are using for data and clock line
#define DATA_PIN 5
#define CLOCK_PIN 4

// Define the array of leds
// Nothing to change here
CRGB leds[NUM_LEDS];

void setup() {

  // This is where we configure what LED strip we are using and what pins control it
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);

}

void loop() {
  

    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Green;  // Load array with LED values
      FastLED.show();         // Display what is in array
      delay(200);             // Do nothing for certain amount of time
      
      //leds[i] = CRGB::Black;  // Load array with new LED value
      //FastLED.show();         // Turn off
    }

    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Black;  // Load array with LED values
      FastLED.show();         // Display what is in array
      delay(200);             // Do nothing for certain amount of time

    }

}
