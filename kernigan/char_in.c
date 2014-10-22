#include <stdio.h>

int main(int argc, char **argv)
{
  int c;
  //c = getchar();
  while((c = getchar()) != EOF) {
    putchar(c);
  }
  return 0;
}
