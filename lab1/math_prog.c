// add a bunch of standard libraries
#include <stdio.h>
#include <stdlib.h>

/**
 * Attempts to add two int arrays a and b elementwise, and store
 * the results in the third array c.
 */
void add_arr(int* a, int* b, int* c) {
  int len = sizeof(a);
  for (int i = 0; i < len; i++) {
    *(c + i) = *(a + i) + *(b + i);
  }
}

/**
 * Attempts to print out the content of the array arr.
 */
void printArray(int* arr) {
  int len = sizeof(arr);
  printf("Array at address %p: ", arr);
  for (int i = 0; i < len; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

int main() {
  int a[6] = {1, 2, 3, 4, 5, 6};
  int b[6] = {3, 2, 7, -1, 3, 4};
  int* c;
  add_arr(a, b, c);
  printArray(a);
  printArray(b);
  printArray(c);
  return 0;
}
