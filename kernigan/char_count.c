#include <stdio.h>

int main(int argc, char **argv)
{
  //long nc;
  double nc;

  nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  
  //printf("%ld\n", nc);
  printf("%.0f\n", nc);
  return 0;
}
