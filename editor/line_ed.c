#include <stdio.h>

#define MAXLEN   1000
#define MAXLINES  1080

int get_line(char s[], int limit);

//==============================================================================
//
//      main() function for line_ed.c
//
//==============================================================================

int main(int argc, char **argv)
{
    int i, num_lines = 0;
    char line[MAXLEN];

    while( (i = get_line(line, MAXLEN)) > 0 && num_lines < MAXLINES) {
        printf(">>> %s", line);
    
        ++num_lines;
    }

    return 0;
}


//==============================================================================
//
//      int get_line(char line[], int limit)
//              - inputs a line of characters, ended by '\n' with limit
//              - characters are written to line[] array
//
//==============================================================================

int get_line(char line[], int limit) 
{
    int i=0;
    int c; // the character inputted

    while(i < limit-1
                && (c = getchar()) != EOF 
                //!ERROR start 
                //&& c != '\0' // end character should not be in 
                // input
                //!ERROR end 
                && c != '\n') {
        line[i] = c;
        ++i;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    //printf("contents of line >>>%s<<<", line);
    //printf("get_line() returning %d\n", i);
    return i;
}

