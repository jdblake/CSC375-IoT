/* Demonstrate ways to use simple #define
**   gcc -o simple_define simple_define.c
**
** NOTE 1: Use of ternary operator in max
** NOTE 2: Conditional compilation
*/

#include <stdio.h>

#define VALUE 11
#define max(x,y) ((x>y)?x:y)
//#define YES

int main() {
  printf("VALUE: %d\n",VALUE);
  printf("MAX(4,VALUE): %d\n",max(4,VALUE));
  #ifdef YES
    printf("YES!!\n");
  #endif
  return 0;
}
