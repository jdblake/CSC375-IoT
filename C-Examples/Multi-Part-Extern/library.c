// Added library include and initialized global variable

#include <stdio.h>
#include "library.h"

int multiplier = 32;

int dub(int n) {
  return 2 * n;
}

int trip(int n) {
  return 3 * n;
}

void printMult() {
  printf("Multiplier is %d\n",multiplier);
}
