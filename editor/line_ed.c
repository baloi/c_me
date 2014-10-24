#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN   1000
#define MAXLINES  1080

// lineptr will be a pointer to all the lines read from input
char *lineptr[MAXLINES];

int get_line(char s[], int limit);
int readlines(char *lineptr[], int maxlines);
void write_lines(char *lineptr[], int num_lines);

//==============================================================================
//
//      main() function for line_ed.c
//
//==============================================================================

int main(int argc, char **argv)
{
    int num_lines = 0;

    if ( (num_lines = readlines(lineptr, MAXLINES)) >= 0) {
        // something was read....
        //printf( "GOT THIS: \n%s \n", *lineptr);
        write_lines(lineptr, num_lines);
    } else {
        printf("error: input too long or too short\n");
        return 1;
    }

    

    return 0;
}


//==============================================================================
//
//      write_lines()
//
//==============================================================================

void write_lines(char *lineptr[], int num_lines)
{

    int lines_written = 0;
    int i;

    for (i=0; i < num_lines; i++) {
        printf(">>%s", lineptr[i]);
    }

    return lines_written;
}

//      write_lines() end

//==============================================================================
//
//      int readlines(char *lineptr[], int maxlines) 
//          - inputs lines of characters
//          - lines are pointed by lineptr pointer to array
//
int readlines(char *lineptr[], int maxlines) 
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    //p = (char *) malloc(4);

    while( (len = get_line(line, MAXLEN)) > 0) {

        //if (nlines >= maxlines || (p = (char *) realloc(p, len)) == NULL) {
        if (nlines >= maxlines || (p = (char *) malloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len-1] = '\0'; /* delete newline */
        }
        printf(">>> %s", line);
    
        strcpy(p, line);

        lineptr[++nlines] = p;
    }

    free(p);

    return nlines;

}
// readlines function end


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

// get_line function end
