#include <stdio.h>

int
main(int argc, char **argv)
{
  int MAXLEN = 255;
  char lastname[MAXLEN];

  printf("lastname: ");
  scanf(" %s", lastname);
  //gets(lastname);

  printf("lastname is %s\n", lastname);

  //@@ this if conditional does not work yet
  if (lastname == "galia") {
    puts("a good lastname");
  }
}
