#ifndef __Anim_Rainbow_H__
#define __Anim_Rainbow_H__

#include <FastLED.h>

#include "Animation.h"

class RainbowRnd : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

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

  private:
    uint8_t currentHue;
};

class RainbowSolid : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

  private:
    uint8_t currentHue;
};
#endif
