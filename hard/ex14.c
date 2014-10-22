#include <stdio.h>

int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
  int i = 0;
  printf("\n");
  for (i = 0; i < argc; i++) {
    //printf(">>%s", argv[i]);
    print_letters(argv[i]);
  }
}

void print_letters(char arg[])
{
  int i = 0;
  //printf("\n>>%s", arg);
  for (i = 0; arg[i] != '\0'; i++) {
    char ch = arg[i];
    
    //printf("'%c' == %d", ch, ch);
    if (can_print_it(ch)) {
      printf("'%c' == %d ", ch, ch);
    }
  }
}

int can_print_it(char ch)
{
  return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
  print_arguments(argc, argv);
  return 0;
}
