#include "Letters.h"
#include "LED_Cube.h"
#include "Transform.h"

void TypeLetter::animSetup(){
  //Settings
  defaultRate = 40;
  defaultLoopCount = 1;
  updatesPerLoop += size[0] * size[1];
}

void TypeLetter::anim(){
  cube->t->rotateOutsideAnti(false);
  if (updateCount < 6*totalLetters) {
    if (updateCount%6 != 0) {
      for (int z=0; z<size[2]; z++) {
        if (letters[updateCount/6][size[2]-z-1][5-(updateCount%6)]) {
          cube->get(0, 0, z) = colour;
        }
      }
    }
  }
}

bool TypeLetter::addLetter(const bool l[5][5]) {
  if (updateCount == 0 and totalLetters < MAX_LETTERS) {
    letters[totalLetters] = l;
    totalLetters++;
    updatesPerLoop += 6;
    return true;
  } else {
    return false;
  }
}
