#ifndef __Animation_H__
#define __Animation_H__

#include <Arduino.h>
#include <FastLED.h>

class LED_Cube;

class Animation {
  public:
    Animation(LED_Cube *c);
    void start(uint16_t loops=0);
    bool run();
    void setBrightness(int16_t b);

  protected:
    virtual void animSetup() = 0;
    virtual void anim() = 0;

    LED_Cube *cube;
    uint8_t size[3];
    //Settings
    uint16_t defaultRate = 100;
    uint16_t defaultLoopCount = 1;
    uint16_t updatesPerLoop = 0;
    uint8_t defaultBrightness = 125;
    //Status vars
    uint8_t brightness;
    uint16_t maxUpdates;
    unsigned long nextUpdate;
    uint16_t loopCount = 0;
    uint16_t updateCount = 0;
    uint16_t loopUpdateCount;
};
#endif
