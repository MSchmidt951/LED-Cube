#ifndef __Anim_Basic_H__
#define __Anim_Basic_H__

#include <FastLED.h>

#include "Animation.h"

class Rain : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

    //Settings
    uint16_t defaultRateMin = 80;
    uint16_t defaultRateMax = 101;
    uint16_t defaultLoopCount;
    uint16_t updatesPerLoop;
    uint8_t defaultBrightness = 125;
    //Animation specific settings

  private:
    int rainDelayTime[25];
    int rainHeight[25];
};

class Wave : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

    //Settings
    uint16_t defaultRate;
    uint16_t defaultLoopCount;
    uint16_t updatesPerLoop;
    uint8_t defaultBrightness = 125;
};

#endif
