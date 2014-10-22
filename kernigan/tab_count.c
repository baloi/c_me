#include <stdio.h>

int main(int argc, char **argv)
{
  int c, tc;

  tc = 0;

  while ((c = getchar()) != EOF)
    if (c == '\t')
      ++tc;

  printf("%d\n", tc);
  return 0;
}
