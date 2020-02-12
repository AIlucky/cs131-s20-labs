#include <stdio.h>
#include <stdlib.h>
/*
 * Calculates the sum of consecutive numbers from `start`
 * to `end` (not including `end`).
 * Parameters:
 * start - an integer defining the starting value of the series
 * end - an integer defining the stopping point of the series.
 *
 * Return: the total summation
 *
 */
int arithmeticSum(int start, int end) {
  int total = 0;
  for (int i = start; i < end; i++) {
    total += i;
  }
}

/*
 * Takes in two integers as input.
 * Calculates the arithmetic sum between those to integers.
 * Mallocs an integer array, and writes the two integer inputs to the array.
 *
 * If the program doesn't receive exactly 2 arguments as input,
 * the program should print "Invalid number of arguments.\n", and then exit with
 * error code `1`.
 *
 */
int main(int argc, char* argv[]) {
  int arg1 = strtol(argv[1], 0, 0);
  int arg2 = strtol(argv[2], 0, 0);
  int sum = arithmeticSum(arg1, arg2);
  printf("Arithmetic Sum between %d and %d is: %d.\n", arg1, arg2, sum);

  int* arr = malloc(2 * sizeof(int));
  *(arr + 1) = arg1;
  *(arr + 2) = arg2;
  free(arr);
  printf("Malloc'd data for arg1 (%d) and arg2 (%d).\n", arr[0], arr[1]);
  return 0;
}
