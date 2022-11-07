#include <stdio.h>

typedef enum week {MON, TUE, WED, THU, FRI, SAT, SUN} week;
//typedef enum week {MON=3, TUE=9, WED=72, THU=11, FRI=8, SAT=44, SUN=6} week;

int main()
{
    week day;
    day = WED;
    printf("%d\n",day);
    return 0;
}
