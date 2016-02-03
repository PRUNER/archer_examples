/**
 * data-race02.c
 *
 * Description: Race on array a, the clause nowait in the omp for
 * remove the implicit barrier in the parallel for, a thread might
 * finish its work on the first for quickly and run the second loop
 * while other thread are still runnning the first loop, because of
 * this different thread may read/write the same location of array a
 * simultaneously.
 *
 * Solution: Remove the clause nowait from first loop.
 *
 */

#include <stdio.h>

#define N 1000

int main (int argc, char **argv)
{
  int i;
  int a[N], b[N];
  
  a[0] = 0;
  
#pragma omp parallel
  { 
#pragma omp for nowait
    for (i = 1; i < N; i++) {
      a[i] = 3.0 * i * (i + 1);
    } /* end of omp for nowait */
#pragma omp for
    for (i = 1; i < N; i++) {
      b[i] = a[i] - a[i - 1];
    } /* end of omp for */
  } /* end of omp parallel */
}

