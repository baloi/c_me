#include <stdio.h>

int
main(int argc, void *argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  
  printf("The size of an int %ld\n", sizeof(int));
  printf("The size of ares (int[]): %ld\n", sizeof(areas));
  return 0;
}
