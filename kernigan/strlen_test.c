#include <stdio.h>

#define MAXLINE  1000

int str_len(char s[]);
int get_line(char s[], int limit);

int main(int argc, char **argv)
{
    int length = 0, i; 
    //char s[] = "hello";
    char line[MAXLINE];

    while( (i = get_line(line, MAXLINE)) > 0) {
        length = str_len(line);

        printf("%s is %d characters long", line, length);

    }

    return 0;

}

int get_line(char s[], int limit)
{
    int c, i;

    for (i = 0; i < limit && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    // end of line?
    s[i] = '\0';

    return i;
}

int str_len(char s[])
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;

}
