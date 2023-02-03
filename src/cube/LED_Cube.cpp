#include "LED_Cube.h"
#include "Animation.h"
#include "Transform.h"

LED_Cube::LED_Cube(int x, int y, int z){
  size[0] = x;
  size[1] = y;
  size[2] = z;
  LEDcount = x*y*z;
  LEDsLeft = LEDcount;

  LEDs = new CRGB[LEDcount];
  t = new Transform(this);
}

int LED_Cube::addPin(int len){
  if (LEDsLeft - len >= 0 and pinCount < MAX_LED_PINS) {
    LEDsLeft -= len;
    ledsOut[pinCount] = new CRGB[len];
    ledsOutLen[pinCount] = len;
    pinCount++;
    switch (pinCount) {
      case 1:
        FastLED.addLeds<LED_CHIPSET, LED_PIN_1>(ledsOut[0], len);
      case 2:
        FastLED.addLeds<LED_CHIPSET, LED_PIN_2>(ledsOut[1], len);
      case 3:
        FastLED.addLeds<LED_CHIPSET, LED_PIN_3>(ledsOut[2], len);
      case 4:
        FastLED.addLeds<LED_CHIPSET, LED_PIN_4>(ledsOut[3], len);
      case 5:
        FastLED.addLeds<LED_CHIPSET, LED_PIN_5>(ledsOut[4], len);
    }
    return 0;
  } else {
    return 1;
  }
}


void LED_Cube::singleLED(int pos, int r, int g, int b, int time){
  LEDs[pos].setRGB(r, g, b);
  delay(time);
}

int LED_Cube::getLEDnum(int xCord, int yCord, int zCord){
  return(xCord + yCord*size[1] + zCord*size[2]);
}

void LED_Cube::update(int delayTime){
  int i = 0;
  for (int p=0; p<pinCount; p++) {
    for (int j=0; j<ledsOutLen[p]; j++) {
      ledsOut[p][j] = LEDs[i];
      i++;
    }
  }
  FastLED.show();
  delay(delayTime);
}

void LED_Cube::setAll(int r, int g, int b){
  fill_solid(LEDs, LEDcount, CRGB(r, g, b));
}

void LED_Cube::setAll(CRGB col){
  fill_solid(LEDs, LEDcount, col);
}

CRGB& LED_Cube::get(int x, int y, int z){
  return LEDs[x + y*size[0] + z*size[0]*size[1]];
}

int LED_Cube::index(int x, int y, int z){
  return x + y*size[0] + z*size[0]*size[1];
}


void LED_Cube::startAnim(Animation *a, bool forceStart){
  if (forceStart or not runningAnim) {
    anim = a;
    anim->start();
  }
}

void LED_Cube::updateAnim(){
  if (anim and runningAnim) {
    runningAnim = anim->run();
  }
}


int LED_Cube::getLEDcount(){
  return LEDcount;
}

int LED_Cube::getSize(int axis){
  if (axis >= 0 and axis < 3) {
    return size[axis];
  } else {
    return -1;
  }
}


void LED_Cube::testLights(){
  setAll(CRGB::Black);
  //Bottom layer
  singleLED(0,  150, 0, 0);
  singleLED(4,  150, 150, 0);
  singleLED(20, 150, 0, 0);
  singleLED(24, 150, 150, 0);
  singleLED(2,  150, 150, 140);
  singleLED(22, 150, 150, 140);
  singleLED(10, 0, 150, 0);
  singleLED(14, 0, 150, 0);
  //Middle layer
  singleLED(50, 0, 0, 150);
  singleLED(54, 0, 0, 150);
  singleLED(70, 0, 0, 150);
  singleLED(74, 0, 0, 150);
  //Middle cross
  singleLED(61, 0, 150, 150);
  singleLED(63, 0, 150, 150);
  singleLED(37, 0, 150, 150);
  singleLED(57, 0, 150, 150);
  singleLED(67, 0, 150, 150);
  singleLED(87, 0, 150, 150);
  singleLED(62, 0, 220, 50);
  //Top layer
  singleLED(100, 200, 0, 100);
  singleLED(104, 200, 0, 100);
  singleLED(120, 150, 0, 150);
  singleLED(124, 150, 0, 150);
  singleLED(110, 0, 150, 0);
  singleLED(114, 0, 150, 0);
  singleLED(102, 150, 150, 140);
  singleLED(122, 150, 150, 140);
}

int LED_Cube::getUpdateRate(){
  return updateRate;
}

int LED_Cube::getBrightness(){
  return brightness;
}

void LED_Cube::debug(unsigned long timeStamp) {
  Serial.print(timeStamp);
  for (int i=0; i<LEDcount; i++) {
    Serial.print(",");
    Serial.printf("%02x", LEDs[i].r);
    Serial.printf("%02x", LEDs[i].g);
    Serial.printf("%02x", LEDs[i].b);
  }
  Serial.println();
}
