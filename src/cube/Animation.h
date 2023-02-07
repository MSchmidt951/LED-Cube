#ifndef __Animation_H__
#define __Animation_H__

#include <Arduino.h>

class LED_Cube;

class Animation {
  public:
    Animation(LED_Cube *c);
    void start(uint16_t loops=0);
    bool run();
    void setBrightness(int b);

  protected:
    virtual void animSetup() = 0;
    virtual void anim() = 0;

    LED_Cube *cube;
    int size[3];
    //Settings
    uint16_t defaultRate;
    uint16_t defaultLoopCount;
    uint16_t updatesPerLoop;
    uint8_t defaultBrightness = 125;
    //Status vars
    uint8_t brightness;
    uint16_t maxUpdates;
    unsigned long nextUpdate;
    uint16_t loopCount;
    uint16_t updateCount;
    uint16_t loopUpdateCount;
};
#endif
