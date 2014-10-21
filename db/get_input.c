#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int get_line(char s[], int limit);

int main(int argc, char **argv)
{
    int i; 

    char line[MAXLINE];

    while( (i = get_line(line, MAXLINE)) > 0) {

        printf(">>%s<< is [%d] characters long, including newline char.\n", 
            line, i);
    }

    return 0;
}


int get_line(char s[], int limit)
{
    int c, i;

    // c is put in s[] unless it is EOF or '\n'
    for (i = 0; i < limit && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
     
    // we should still put '\n' in s[] though
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    // end of line?
    s[i] = '\0';

    return i;
}
