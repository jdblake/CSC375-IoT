/*
** Program to intentionally leak memory
**
** NOTE 1: Difference between local array and local calloc
** NOTE 2: Use of free
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define MAX_ARR_SIZE 1000000
#define MAX_VAL 1000
#define MAX_ITER 10000

int getLargest() {
  int max;
  int arr[MAX_ARR_SIZE];
/*
  int *arr;
  arr = calloc(MAX_ARR_SIZE,sizeof(int));
*/
  for (int i = 0; i < MAX_ARR_SIZE; i++) {
    arr[i] = rand() % MAX_VAL;
  }
  max = arr[0];
  for (int i = 1; i < MAX_ARR_SIZE; i++)
    if (arr[i] > max)
      max = arr[i];
  //free(arr);
  return max;
}

int main() {

  for (int i = 0; i < MAX_ITER; i++) {
    int n = getLargest();
    printf("Iter: %d; Largest: %d; Mem: 0x%lX\n",++i,
          n,get_avphys_pages()*sysconf(_SC_PAGESIZE));
  }

  return(0);
}
