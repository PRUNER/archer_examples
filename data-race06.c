/**
 * data-race06.c
 *
 * Description: Race on variable init. The variable is written by the
 * master thread and concurrently read by the others.
 *
 * Solution: master construct does not have an implicit barrier better
 * use single.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  int init, local;

#pragma omp parallel shared(init) private(local)
  {
    #pragma omp master
    {
      init = 10;
    }

    local = init;
  }
}
