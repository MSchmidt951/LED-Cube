#include "LED_Cube.h"
#include "Animation.h"
#include "Transform.h"

#include "Anim_Rainbow.h"

/* How to run an animation
 * 
 * Include the animation header file
 * Create an instance of the animation
 * Run start() to start the animation
 * Run cube.updateAnim() to update the animation and output it to the cube
 * The animation will run until it is finished or a new animation is chosen
 */

LED_Cube cube(5, 5, 5);
RainbowRows r(&cube);

void setup(){
  delay(3000); //Safety delay
  cube.addPin(50); //BLACK wire
  cube.addPin(25); //BLUE wire
  cube.addPin(50); //GREEN wire

  cube.testLights();
  cube.update();
  delay(4000);

  r.start();
}

void loop(){
  cube.updateAnim();
}
