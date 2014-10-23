#include <stdio.h>

#define MAXLEN   1000
#define MAXLINES  1080

int get_lines(char s[], int limit);

int main(int argc, char **argv)
{
    int i, num_lines = 0;
    char line[MAXLEN];

    while( (i = get_lines(line, MAXLEN) && i > 0)) {
        printf("this shoould be printed\n");
        printf(">>> %s\n", line);
    
        ++num_lines;
    }

    return 0;
}

int get_lines(char line[], int limit) 
{
    int i= 0;

    char c;

    while( (c = getchar()) != EOF 
                && c != '\0' 
                && i != limit 
                && c != '\n') {
        line[i] = c;
        ++i;
    }

    if (c == '\n') {
        line[i] = '\n';
    }

    ++i;
    line[i] = '\0';

    printf("getlines() returning %d\n", i);
    return i;
}

