/**
 * data-race05.c
 *
 * Description: Race on variable sum, it is shared and not protected,
 * multiple thread will write on it simultaneously.
 *
 * Solution: Add reduction(+:sum) to omp pragma.
 *
 */

#include <stdio.h>
#include <math.h>

#define N 1000

int main (int argc, char **argv)
{
  int i;
  float a[N], sum;

  sum = 0;

  // Vector initialization
#pragma omp parallel for
  for (i = 0; i < N; ++i) {
    a[i] = i;
  }
  
#pragma omp parallel for
  for (i = 1; i < N; i++)
    {
      sum = sum + a[i];
    } /* end of omp parallel for */
}

