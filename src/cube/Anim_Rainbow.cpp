#include "Anim_Rainbow.h"
#include "LED_Cube.h"

void RainbowRnd::animSetup(){
  for(int i=0; i<cube->getLEDcount(); i++){
    rainbowHues[i%randCount] = random(256);
    cube->LEDs[i] = CHSV(rainbowHues[i%randCount], 255, brightness);
  }
}

void RainbowRnd::anim(){
  for(int i=0; i<cube->getLEDcount(); i++){
    if (i<randCount) {
      rainbowHues[i] += 5;
      rainbowHues[i] %= 256;
    }
    cube->LEDs[i] = CHSV(rainbowHues[i%randCount], 255, brightness);
  }
}


void RainbowRows::animSetup(){
  currentHue = random(256);
}
  
void RainbowRows::anim(){
  fill_rainbow(cube->LEDs, cube->getLEDcount(), currentHue);
  currentHue += 4;
  currentHue %= 256;
}


void RainbowSolid::animSetup(){
  currentHue = random(256);
}

void RainbowSolid::anim(){
  fill_solid(cube->LEDs, cube->getLEDcount(), CHSV(currentHue, 255, brightness));
  currentHue += 4;
  currentHue %= 256;
}
