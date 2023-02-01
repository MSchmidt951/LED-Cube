#include "LED_Cube.h"
#include "Animation.h"
#include "Transform.h"

LED_Cube cube(5, 5, 5);

void setup(){
  delay(3000); //Safety delay
  cube.addPin(50); //BLACK wire
  cube.addPin(25); //BLUE wire
  cube.addPin(50); //GREEN wire

  cube.testLights();
  cube.update();
  delay(4000);
}

void loop(){}
