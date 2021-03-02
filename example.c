#include <stdio.h>
#include <stdlib.h>

int foo(int x, int op, int *arr, int n) {
  if (x == 0) {
    exit(1);
  }

  int accum = 0;

  if (op == 0) {
    for (int i = 0; i < n; i++) {
      accum += arr[i];
    }
  } else if (op == 1) {
    accum = 1;
    for (int i = 0; i < n; i++) {
      accum *= arr[i];
    }
  } else exit(2);

  return accum;
}

int main(int argc, char *argv[]) {

  if (argc < 4) {
      printf("USAGE: ./example.o <x> <op> <n> <n elts of arr>\n");
      exit(1);
  }
 
  int x = atoi(argv[1]);
  int op = atoi(argv[2]);
  int n = atoi(argv[3]);

  if (argc - n != 4) {
    printf("USAGE: ./example.o <x> <op> <n> <n elts of arr>\n");
    exit(1);
  }
  
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = atoi(argv[2+i]);
  }
 
  int res = foo(x, op, arr, n);
  printf("foo returned %d\n", res);
    
  return 0;
}
