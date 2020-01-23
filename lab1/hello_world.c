// add a bunch of standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GLOBAL_VAR = 200;
const char const_variable[33] = "Welcome to your first C program!";
int uninitialized_variable;

int main() {
  // print a string (%s) followed by a new line (\n)
  // where the first argument (const_variable) is formatted as the string
  printf("%s\n", const_variable);

  // allocate some variables on the stack and heap
  char* local_var = "hello";

  // heap allocates an integer (malloc returns a pointer to a chunk of memory in
  // the heap)
  int* heap_allocated = (int*)malloc(sizeof(int));
  *heap_allocated = 20;

  printf("%s\n", local_var);

  // %d will format the argument as an integer
  printf("heap_allocated: %d\n", *heap_allocated);

  // free the memory allocated on the heap
  free(heap_allocated);
  return 0;
}
