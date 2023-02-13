#include "LED_Cube.h"
#include "Animation.h"
#include "Transform.h"

#include "Anim_Rainbow.h"
#include "Letters.h"
#include "Anim_Basic.h"

/* How to run an animation
 * 
 * Include the animation header file
 * Pass an instance of the animation into cube.startAnim
 * Run cube.updateAnim() to update the animation and output it to the cube
 * The animation will run until it is finished or a new animation is chosen
 */

LED_Cube cube(5, 5, 5);

void setup(){
  delay(2000); //Safety delay
  cube.addPin(50); //BLACK wire
  cube.addPin(25); //BLUE wire
  cube.addPin(50); //GREEN wire

  cube.testLights();
  delay(4000);

  TypeLetter *hiAnim = new TypeLetter(&cube);
  hiAnim->addLetter(letters_5.H);
  hiAnim->addLetter(letters_5.I);
  hiAnim->addLetter(letters_5.ex);
  cube.queueAnim(hiAnim);

  cube.queueAnim(new Wave(&cube));
  Wave *w = new Wave(&cube);
  w->colour = CRGB::Green;
  cube.queueAnim(w);
  Wave *w2 = new Wave(&cube);
  w2->colour = CRGB::Blue;
  cube.queueAnim(w2);

  cube.queueAnim(new RainbowRows(&cube));
  cube.queueAnim(new RainbowSolid(&cube));
  cube.queueAnim(new RainbowRnd(&cube));
  cube.queueAnim(new Rain(&cube));
}

void loop(){
  cube.updateAnim();
}
