#ifndef __Anim_Rainbow_H__
#define __Anim_Rainbow_H__

#include <FastLED.h>

#include "Animation.h"

class RainbowRnd : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

    //Settings
    uint16_t defaultRate = 200;
    uint16_t defaultLoopCount = 4;
    uint16_t updatesPerLoop = 255/5;
    //Animation specific settings
    static const uint16_t randCount = 256;

  private:
    uint8_t rainbowHues[randCount];
};

class RainbowRows : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

    //Settings
    uint16_t defaultRate = 250;
    uint16_t defaultLoopCount = 4;
    uint16_t updatesPerLoop = 255/4;

  private:
    uint8_t currentHue;
};

class RainbowSolid : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

    //Settings
    uint16_t defaultRate = 250;
    uint16_t defaultLoopCount = 4;
    uint16_t updatesPerLoop = 255/2;
    uint8_t defaultBrightness = 110;

  private:
    uint8_t currentHue;
};
#endif
