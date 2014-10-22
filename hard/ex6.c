#include <stdio.H>

int
main(int argc, char *argv[])
{
  int distance = 100;
  float power = 2.4262f;
  double super_power = 234234.33454;
  char initial = 'A';
  char first_name[] = "Zed";
  char last_name[] = "Shaw";

  printf("You are %d miles away.\n", distance);
  printf("You have %f levels of power.\n", power);
  printf("You have %f awesome super powers.\n", super_power);
  printf("You have  an initial of %c.\n", initial);
  printf("You have  a last name of of %s.\n", last_name);
  printf("You have  a first_name of %s.\n", first_name);
  printf("Your whole name is %s %c. %s.\n", 
          first_name, initial, last_name);
  return 0;
}
