#include <stdio.h>
#include "library.h"

int main() {
  int in;
  printf("Please enter an int: ");
  scanf("%d",&in);
  printf("Double %d is %d\n",in,dub(in));
  printf("Triple %d is %d\n",in,trip(in));
  printMult();
  printf("%d * %d = %d\n",multiplier,in,multiplier*in);
  return 0;
}
