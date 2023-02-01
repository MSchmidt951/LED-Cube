#include "Animation.h"
#include "LED_Cube.h"

Animation::Animation(LED_Cube *c){
  cube = c;
}

void Animation::start(uint16_t loops){
  cube->setAll(0, 0, 0);
  brightness = defaultBrightness;
  animSetup();
  cube->update();

  nextUpdate = 0;
  loopCount = 0;
  updateCount = 0;
  
  if (loops == 0) {
    maxUpdates = updatesPerLoop * defaultLoopCount;
  } else {
    maxUpdates = updatesPerLoop * loops;
  }
}

bool Animation::run(){
  if (nextUpdate < millis()) {
    anim();
    cube->update();

    nextUpdate = millis() + (defaultRate * cube->getUpdateRate());
    updateCount++;
    if (updateCount >= maxUpdates) {
      return false;
    }
  }
  return true;
}

void Animation::setBrightness(int b){
  if (b == -1) {
    brightness = defaultBrightness;
  } else if (b >= 0 and b <= 255) {
    brightness = b;
  }
}
