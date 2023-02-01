#include "Anim_Basic.h"
#include "LED_Cube.h"

void Rain::animSetup(){
  defaultRate = random(defaultRateMin, defaultRateMax);
}

void Rain::anim(){
  int currentLayer;
  int topLayer;
  for (int i=0; i<25; i++) {
    if (rainHeight[i] > 0) {
      /* Make the rain fall */
      currentLayer = rainHeight[i] * cube->getSize(0) * cube->getSize(1);
      cube->LEDs[currentLayer-25+i] = cube->LEDs[currentLayer+i];
      cube->LEDs[currentLayer+i] = CRGB::Black;
      rainHeight[i]--;
    } else if (rainDelayTime[i] > 0) {
      /* Let the LED wait at the bottom of the cube */
      rainDelayTime[i]--;
    } else {
      /* Reset the LED back at the top */
      cube->LEDs[i] = CRGB::Black;
      //random colour
      cube->LEDs[i+100].g = random(0, 90);
      cube->LEDs[i+100].r = cube->LEDs[i+100].g + random(-25, 25);
      if (cube->LEDs[i+100].r > 100) {
        cube->LEDs[i+100].r = 0;
      }
      cube->LEDs[i+100].b = random(180, 255);
      //height
      rainHeight[i] = 4;
      //Random wait
      rainDelayTime[i] = random(5, 35);
    }
  }
  defaultRate = random(defaultRateMin, defaultRateMax);
}
