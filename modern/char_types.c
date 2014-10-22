#include <stdio.h>

int
main(int argc, char **argv)
{
  char ch;

  do {
    scanf(" %c", &ch);
  //} while (ch != '\n');
  } while (ch != 'e');
  return 0;
}
