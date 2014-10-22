#include <stdio.h>

#define MAXLEN  1000

int str_len(char s[]);

int main(int argc, char **argv)
{
    int length = 0; 
    //char s[] = "hello";
    char s[] = "hello";
    char line[MAXLEN];

    length = str_len(s);

    printf("%s is %d characters long", s, length);

    return 0;

}

int str_len(char s[])
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;

}
