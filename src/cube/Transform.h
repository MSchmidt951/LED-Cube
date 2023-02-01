#ifndef __Transform_H__
#define __Transform_H__

#include <FastLED.h>

class LED_Cube;

class Transform {
  public:
    Transform(LED_Cube *c);

    void fwd(bool loop=true, int minX=0, int maxX=-1, int minY=0, int maxY=-1, int minZ=0, int maxZ=-1); //back to front
    void back(bool loop=true, int minX=0, int maxX=-1, int minY=0, int maxY=-1, int minZ=0, int maxZ=-1); //front to back
    void up(bool loop=true, int minX=0, int maxX=-1, int minY=0, int maxY=-1, int minZ=0, int maxZ=-1);
    void down(bool loop=true, int minX=0, int maxX=-1, int minY=0, int maxY=-1, int minZ=0, int maxZ=-1);
    void left(bool loop=true, int minX=0, int maxX=-1, int minY=0, int maxY=-1, int minZ=0, int maxZ=-1);
    void right(bool loop=true, int minX=0, int maxX=-1, int minY=0, int maxY=-1, int minZ=0, int maxZ=-1);

  private:
    LED_Cube *cube;
    CRGB *tempLED;
    int size[3]; //[left/right, fwd/back, vertical]
    int planeSize[3]; //[left/right, fwd/back, vertical]
};

#endif
