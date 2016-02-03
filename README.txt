In order to run the following examples set the number of threads >= 2
with the following command:

     export OMP_NUM_THREADS=2

Programs:

* data_race00.c 
  Description: Race on variable var, two threads are accessing var
  without any synchronization mechanism.
  Solution: Use a mutex to syncrhonize the access of the threads to
  var.
  Compile with:
          clang -g -fsanitize=thread data-race00.c -o data-race00 -pthreads

* data_race01.c
  Description: Race on array a, multiple location of the
  array might be accessed by different threads simultaneously.
  Solution: Include accesses to arrays within a critical section.
  Compile with:
          clang-archer -g -fopenmp -fsanitize=thread data-race01.c -o data-race01

* data_race02.c
  Description: Race on array a, the clause nowait in the omp for
  remove the implicit barrier in the parallel for, a thread might
  finish its work on the first for quickly and run the second loop
  while other thread are still runnning the first loop, because of
  this different thread may read/write the same location of array a
  simultaneously.
  Solution: Remove the clause nowait from first loop.
  Compile with:
          clang-archer -g -fopenmp -fsanitize=thread data-race02.c -o data-race02

* data_race03.c
  Description: Data race on variable x, shared by default.
  Solution: Add private(x) in omp pragma.
  Compile with:
          clang-archer -g -fopenmp -fsanitize=thread data-race03.c -o data-race03

* data_race04.c
  Description: Data race on index variable j, shared by default.
  Solution: Add private(j) in omp pragma.
  Compile with:
          clang-archer -g -fopenmp -fsanitize=thread data-race04.c -o data-race04

* data_race05.c
  Description: Race on variable sum, it is shared and not protected,
  multiple thread will write on it simultaneously.
  Solution: Add reduction(+:sum) to omp pragma.
  Compile with:
          clang-archer -g -fopenmp -fsanitize=thread data-race05.c -o data-race05

* data_race06.c
  Description: Race on variable init. The variable is written by the
  master thread and concurrently read by the others.
  Solution: master construct does not have an implicit barrier better
  use single.
  Compile with:
          clang-archer -g -fopenmp -fsanitize=thread data-race06.c -o data-race06
