#ifndef __LED_Cube_H__
#define __LED_Cube_H__

#include <FastLED.h>

#define MAX_LED_PINS 5
#define LED_PIN_1 5
#define LED_PIN_2 6
#define LED_PIN_3 7
#define LED_PIN_4 8
#define LED_PIN_5 9
#define LED_CHIPSET WS2812

class Animation;
class Transform;

class LED_Cube {
  public:
    //Setup
    LED_Cube(int x, int y, int z);
    int addPin(int len);
    //Basic functions
    void singleLED(int pos, int r, int g, int b, int time=0);
    void update(int delayTime=0);
    void setAll(int r, int g, int b);
    void setAll(CRGB col);
    CRGB& get(int x, int y, int z);
    int index(int x, int y, int z);
    //Animations
    bool startAnim(Animation *a, bool forceStart=false);
    bool queueAnim(Animation *a);
    void updateAnim();
    bool isRunningAnim();
    Transform *t;
    //Cube info
    int getLEDcount();
    int getSize(int axis);
    //Misc
    void testLights();
    int getUpdateRate();
    int getBrightness();
    void debug(unsigned long timeStamp);

    CRGB *LEDs;

  private:
    //Cube variables
    int size[3]; //[left/right, fwd/back, vertical]
    int pinCount;
    //LED variables
    int LEDcount;
    int LEDsLeft;
    CRGB *ledsOut[MAX_LED_PINS];
    int ledsOutLen[MAX_LED_PINS];
    //Animations
    Animation *anim;
    Animation *queuedAnims[10];
    int animQueueStart = 0;
    int animQueueEnd = 0;
    bool runningAnim = false;
    //Misc
    uint8_t brightness = 125;
    int updateRate = 1;
};
#endif
