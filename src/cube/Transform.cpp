#include "Transform.h"
#include "LED_Cube.h"

Transform::Transform(LED_Cube *c) {
  cube = c;

  for (int i=0; i<3; i++) {
    size[i] = cube->getSize(i);
  }
  planeSize[0] = size[1]*size[2];
  planeSize[1] = size[0]*size[2];
  planeSize[2] = size[0]*size[1];

  int maxPlaneSize = max(planeSize[0], max(planeSize[1], planeSize[2]));
  tempLED = new CRGB[maxPlaneSize];
}

void Transform::fwd(bool loop, int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {
  if (maxX < 0 or maxX >= size[0]) {
    maxX = size[0]-1;
  }
  if (maxY < 0 or maxY >= size[1]) {
    maxY = size[1]-1;
  }
  if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }
  
  for(int z=minZ; z<=maxZ; z++) {
    if(loop) {
      for(int x=minX; x<=maxX; x++) {
        tempLED[x] = cube->get(x, minY, z);
      }
    }

    for (int x=minX; x<=maxX; x++) {
      for(int y=minY; y<maxY; y++) {
        cube->get(x, y, z) = cube->get(x, y+1, z);
      }
    }

    if (loop) {
      for (int x=minX; x<=maxX; x++) {
        cube->get(x, maxY, z) = tempLED[x];
      }
    } else {
      for (int x=minX; x<=maxX; x++) {
        cube->get(x, maxY, z) = CRGB::Black;
      }
    }
  }
}

void Transform::back(bool loop, int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {
  if (maxX < 0 or maxX >= size[0]) {
    maxX = size[0]-1;
  }
  if (maxY < 0 or maxY >= size[1]) {
    maxY = size[1]-1;
  }
  if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }
  
  for(int z=minZ; z<=maxZ; z++) {
    if(loop) {
      for(int x=minX; x<=maxX; x++) {
        tempLED[x] = cube->get(x, maxY-1, z);
      }
    }

    for (int x=minX; x<=maxX; x++) {
      for(int y=maxY; y>minY; y--) {
        cube->get(x, y, z) = cube->get(x, y-1, z);
      }
    }

    if (loop) {
      for (int x=minX; x<=maxX; x++) {
        cube->get(x, 0, z) = tempLED[x];
      }
    } else {
      for (int x=minX; x<=maxX; x++) {
        cube->get(x, 0, z) = CRGB::Black;
      }
    }
  }
}

void Transform::up(bool loop, int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {
  if (maxX < 0 or maxX >= size[0]) {
    maxX = size[0]-1;
  }
  if (maxY < 0 or maxY >= size[1]) {
    maxY = size[1]-1;
  }
  if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }
  
  if(loop) {
    for (int x=minX; x<=maxX; x++) {
      for(int y=minY; y<=maxY; y++) {
        tempLED[cube->index(x, y, 0)] = cube->get(x, y, maxZ);
      }
    }
  }

  for(int z=maxZ; z>minZ; z--) {
    for (int x=minX; x<=maxX; x++) {
      for(int y=minY; y<=maxY; y++) {
        cube->get(x, y, z) = cube->get(x, y, z-1);
      }
    }
  }

  for (int x=minX; x<=maxX; x++) {
    for(int y=minY; y<=maxY; y++) {
      if (loop) {
        cube->get(x, y, minZ) = tempLED[cube->index(x, y, 0)];
      } else {
        cube->get(x, y, minZ) = CRGB::Black;
      }
    }
  }
}

void Transform::down(bool loop, int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {
  if (maxX < 0 or maxX >= size[0]) {
    maxX = size[0]-1;
  }
  if (maxY < 0 or maxY >= size[1]) {
    maxY = size[1]-1;
  }
  if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }
  
  if(loop) {
    for (int x=minX; x<=maxX; x++) {
      for(int y=minY; y<=maxY; y++) {
        tempLED[cube->index(x, y, 0)] = cube->get(x, y, minZ);
      }
    }
  }

  for(int z=minZ; z<maxZ; z++) {
    for (int x=minX; x<=maxX; x++) {
      for(int y=minY; y<=maxY; y++) {
        cube->get(x, y, z) = cube->get(x, y, z+1);
      }
    }
  }

  for (int x=minX; x<=maxX; x++) {
    for(int y=minY; y<=maxY; y++) {
      if (loop) {
        cube->get(x, y, maxZ) = tempLED[cube->index(x, y, 0)];
      } else {
        cube->get(x, y, maxZ) = CRGB::Black;
      }
    }
  }
}

void Transform::left(bool loop, int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {
  if (maxX < 0 or maxX >= size[0]) {
    maxX = size[0]-1;
  }
  if (maxY < 0 or maxY >= size[1]) {
    maxY = size[1]-1;
  }
  if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }
  
  for(int z=minZ; z<=maxZ; z++) {
    if(loop) {
      for(int y=minY; y<=maxY; y++) {
        tempLED[y] = cube->get(maxX, y, z);
      }
    }

    for (int x=maxX; x>minX; x--) {
      for(int y=0; y<=maxY; y++) {
        cube->get(x, y, z) = cube->get(x-1, y, z);
      }
    }

    if (loop) {
      for (int y=minY; y<=maxY; y++) {
        cube->get(minX, y, z) = tempLED[y];
      }
    } else {
      for (int y=minY; y<=maxY; y++) {
        cube->get(minX, y, z) = CRGB::Black;
      }
    }
  }
}

void Transform::right(bool loop, int minX, int maxX, int minY, int maxY, int minZ, int maxZ) {
  if (maxX < 0 or maxX >= size[0]) {
    maxX = size[0]-1;
  }
  if (maxY < 0 or maxY >= size[1]) {
    maxY = size[1]-1;
  }
  if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }
  
  for(int z=minZ; z<=maxZ; z++) {
    if(loop) {
      for(int y=minY; y<=maxY; y++) {
        tempLED[y] = cube->get(minX, y, z);
      }
    }

    for (int x=minX; x<maxX; x++) {
      for(int y=minY; y<=maxY; y++) {
        cube->get(x, y, z) = cube->get(x+1, y, z);
      }
    }

    if (loop) {
      for (int y=minY; y<=maxY; y++) {
        cube->get(maxX, y, z) = tempLED[y];
      }
    } else {
      for (int y=minY; y<=maxY; y++) {
        cube->get(maxX, y, z) = CRGB::Black;
      }
    }
  }
}

void Transform::rotateOutside(int minZ, int maxZ) {
    if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }

  for(int z=minZ; z<=maxZ; z++) {
    tempLED[0] = cube->get(0, 0, z);

    for (int x=0; x<size[0]-1; x++) {
      cube->get(x, 0, z) = cube->get(x+1, 0, z);
    }
    for (int y=0; y<size[1]-1; y++) {
      cube->get(size[0]-1, y, z) = cube->get(size[0]-1, y+1, z);
    }
    for (int x=size[0]-1; x>0; x--) {
      cube->get(x, size[1]-1, z) = cube->get(x-1, size[1]-1, z);
    }
    for (int y=size[1]-1; y>0; y--) {
      cube->get(0, y, z) = cube->get(0, y-1, z);
    }

    cube->get(0, 1, z) = tempLED[0];
  }
}

void Transform::rotateOutsideAnti(int minZ, int maxZ) {
    if (maxZ < 0 or maxZ >= size[2]) {
    maxZ = size[2]-1;
  }

  for(int z=minZ; z<=maxZ; z++) {
    tempLED[0] = cube->get(0, 0, z);

    for (int y=0; y<size[1]-1; y++) {
      cube->get(0, y, z) = cube->get(0, y+1, z);
    }
    for (int x=0; x<size[0]-1; x++) {
      cube->get(x, size[1]-1, z) = cube->get(x+1, size[1]-1, z);
    }
    for (int y=size[1]-1; y>0; y--) {
      cube->get(size[0]-1, y, z) = cube->get(size[0]-1, y-1, z);
    }
    for (int x=size[0]-1; x>0; x--) {
      cube->get(x, 0, z) = cube->get(x-1, 0, z);
    }

    cube->get(1, 0, z) = tempLED[0];
  }
}
