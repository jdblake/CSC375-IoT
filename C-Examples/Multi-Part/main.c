/*
** Main program  using library. Compile library iunto object file first:
**   gcc -c library.c
**
** Then create the executable:
**   gcc -o out library.o main.c
**
** Note 1: You can also create an object file from main:
**   gcc -c main.c
** Then compile the executable from the object files:
**   gcc -o out library.o main.o
**
** Note 2: Difference between <> and "" for included files
*/

#include <stdio.h>
#include "library.h"

int main() {
  int in;
  printf("Please enter an int: ");
  scanf("%d",&in);
  printf("Double %d is %d\n",in,dub(in));
  printf("Triple %d is %d\n",in,trip(in));
  printf("%d * %d = %d\n",multiplier,in,multiplier*in);
  return 0;
}
