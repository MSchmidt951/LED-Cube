#ifndef __Anim_Basic_H__
#define __Anim_Basic_H__

#include "Animation.h"

class Rain : public Animation {
  using Animation::Animation;

  protected:
    void animSetup();
    void anim();

  private:
    //Animation specific settings
    uint16_t defaultRateMin = 80;
    uint16_t defaultRateMax = 101;

    uint16_t rainDelayTime[100];
    uint8_t rainHeight[100];
};

class Wave : public Animation {
  using Animation::Animation;

  public:
    CRGB colour = CRGB::Red;

  protected:
    void animSetup();
    void anim();
};

#endif
