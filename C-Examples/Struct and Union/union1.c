#include <stdio.h>

union unionJob
{
   //defining a union
   char name[32];
   float salary;
   int workerNo;
} uJob;

struct structJob
{
   char name[32];
   float salary;
   int workerNo;
} sJob;

int main()
{
   printf("size of union = %ld bytes\n", sizeof(uJob));
   printf("size of structure = %ld bytes\n", sizeof(sJob));
   return 0;
}
