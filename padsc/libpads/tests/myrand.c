#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  int i, tests, times, mul;
  int num[100000], tmp;
  unsigned long r1, r2;

  if (argc < 3) {
    goto usage;
  }
  tests = atoi(argv[1]);
  times = atoi(argv[2]);
  mul = tests*times;

  for (i = 0; i < mul; i++) {
    num[i] = i % tests;
  }
  for (i = 0; i < mul*100; i++) {
    r1 = rand() % mul;
    while ((r2 = rand() % mul) == r1);
    tmp = num[r1]; num[r1] = num[r2]; num[r2] = tmp; 
  }
  for (i = 0; i < mul; i++) {
    printf("%d ", num[i]);
  }
  printf("\n");
  return 0;

 usage:
  fprintf(stderr, "\nUsage: %s <#tests> <#times>\n\n", argv[0]);
  return -1;
}
