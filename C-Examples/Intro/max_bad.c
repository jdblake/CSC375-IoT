/* max: computes the larger of two int values
**   x: one value
**   y: the other value
**   returns: the larger of x and y
**
** Note 1: single return from max function.
** Note 2: Confirmation that C is call-by-value
*/

#include "stdio.h"

/* main: shows a call to max */
int main() {
    int a, b, res;

    printf("Enter two integer values: ");
    scanf("%d%d", &a, &b);

    res = max(a, b);
    printf("The larger value of %d and %d is %d\n", a, b, res);

    return 0;
}

int max(int x, int y) {
    int bigger;

    bigger = x;
    if (y > x) {
        bigger = y;
        // note: changing the parameter x's value here will not
        //       change the value of its corresponding argument
        x = y;
    }
    printf("  in max, before return x: %d y: %d\n", x, y);

    return bigger;
}
