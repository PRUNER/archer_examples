/**
 * data-race03.c
 *
 * Description: Data race on variable x, shared by default.
 *
 * Solution: Add private(x) in omp pragma.
 *
 */

#include <stdio.h>
#include <math.h>

#define N 1000

int main (int argc, char **argv)
{
  int i;
  float a[N], b[N], x;

  // Vector initialization
#pragma omp parallel for
  for (i = 0; i < N; ++i) {
    b[i] = i * i;
  }
    
#pragma omp parallel for
  for (i = 1; i < N; i++) {
      x = sqrt(b[i]) - 1;
      a[i] = x * x + 2 * x + 1;
    } /* end of omp parallel for */
}

