#include "Anim_Basic.h"
#include "LED_Cube.h"
#include "Transform.h"

void Rain::animSetup(){
  //Settings
  defaultLoopCount = 5;
  updatesPerLoop = 50;

  defaultRate = random(defaultRateMin, defaultRateMax);
  for (int x=0; x<size[0]; x++) {
    for(int y=0; y<size[1]; y++) {
      rainHeight[cube->index(x, y, 0)] = random(0, size[2]-1);
      rainDelayTime[cube->index(x, y, 0)] = 0;
    }
  }
}

void Rain::anim(){
  int i;

  for (int x=0; x<size[0]; x++) {
    for(int y=0; y<size[1]; y++) {
      i = cube->index(x, y, 0);
      if (rainHeight[i] > 0) {
        /* Make the rain fall */
        cube->get(x, y, rainHeight[i]-1) = cube->get(x, y, rainHeight[i]);
        cube->get(x, y, rainHeight[i]) = CRGB::Black;
        rainHeight[i]--;
      } else if (rainDelayTime[i] > 0) {
        /* Let the LED wait at the bottom of the cube */
        rainDelayTime[i]--;
      } else {
        /* Reset the LED back at the top */
        cube->get(x, y, 0) = CRGB::Black;
        //random colour
        cube->get(x, y, size[2]-1).g = random(0, 90);
        cube->get(x, y, size[2]-1).r = cube->get(x, y, size[2]-1).g + random(-25, 25);
        if (cube->get(x, y, size[2]-1).r > 100) {
          cube->get(x, y, size[2]-1).r = 0;
        }
        cube->get(x, y, size[2]-1).b = random(180, 255);
        //height
        rainHeight[i] = size[2]-1;
        //Random wait
        rainDelayTime[i] = random(3, 30);
      }
    }
  }
  defaultRate = random(defaultRateMin, defaultRateMax);
}


void Wave::animSetup(){
  //Settings
  defaultRate = 125;
  defaultLoopCount = 2;
  updatesPerLoop = size[0] + size[2] + size[2] - 2;

  for (int x=0; x<size[0]; x++) {
    for(int y=0; y<size[1]; y++) {
      cube->get(x, y, 0) = colour;
    }
  }
  cube->t->up(false, 0,0);
}

void Wave::anim(){
  cube->t->up(false, max(0,loopUpdateCount-size[0]+3), loopUpdateCount+1);
  if (loopUpdateCount >= size[2]) {
    cube->t->down(false, max(0,loopUpdateCount-size[2]-size[2]+2), loopUpdateCount-size[2]);
  }
  if (loopUpdateCount == updatesPerLoop-1 and updateCount != maxUpdates-1) {
    cube->t->up(false, 0,0);
  }
}
