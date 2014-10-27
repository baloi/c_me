#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN   1080
#define MAXLINES  1080

// lineptr will be a pointer to all the lines read from input
char *lineptr[MAXLINES];

int get_line(char s[], int limit);
int readlines(char *lineptr[], int maxlines);
void write_lines(char *lineptr[], int num_lines);

//==============================================================================
//
//      main()::int 
//          - main function for line_ed.c
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
//  END main

//==============================================================================
//
//      write_lines(char *lineptr[], int num_lines)::void
//          - Prints out lineptr contents
//          - num_lines will be the number of lines printed.
//
//==============================================================================

void write_lines(char *lineptr[], int num_lines)
{
    int i;
    printf("Will now write %d lines...\n", num_lines);

    for (i=0; i < num_lines; i++) {
        printf(">%s", lineptr[i]);
    }
}
//  END write_lines

//==============================================================================
//
//      int readlines(char *lineptr[], int maxlines) 
//          - inputs lines of characters
//          - lines are pointed by lineptr pointer to array
//
//==============================================================================

int readlines(char *lineptr[], int maxlines) 
{
    //int len, nlines;
    int nlines;
    size_t  len;
    //>>>>>> ORIG START >>>>>>>
    //char *line = NULL;
    //<<<<<< ORIG END <<<<<<<<<

    //>>>>>> get_line START >>>>>>>>
    char line[MAXLEN];
    //<<<<<< get_line END <<<<<<<<<

    //>>>>>> ORIG START >>>>>>>
    //ssize_t read;
    //<<<<<< ORIG END <<<<<<<<<
    
    // create a temporary array of characters where the value of line can be 
    // stored
    char *temp_line = NULL; 

    nlines = 0;


    //>>>>>> get_line START >>>>>>>>
    while( (len = get_line(line, MAXLEN)) > 0) {
    //<<<<<< get_line END <<<<<<<<<

    //>>>>>> ORIG START >>>>>>>
    //while( ( read  = getline(&line, &len, stdin)) != -1 && read != EOF) {
    //<<<<<< ORIG END <<<<<<<<<

        if (nlines >= maxlines) {
            return -1;
        }
        else {
            // The value of temp_line will be the value of duplicated string 
            // line. 'line' needs to be passed to strdup to duplicate the string
            // as line will be modified during each call to get_line. Each time
            // we go to this line temp_line is pointing to a new address after
            // strdup().
            temp_line = strdup(line);
            //printf("temp_line now pointing to %zu ", temp_line);

            lineptr[nlines] = temp_line;
            //printf("lineptr[%d] = %s\n", nlines, *temp_line);
            ++nlines;
        }

    }

    //free(line);

    return nlines;

}
//  END readlines 


//==============================================================================
//
//      int get_line(char line[], int limit)
//              - inputs a line of characters, ended by '\n' with limit
//              - characters are written to line[] array
//
//==============================================================================

int get_line(char s[], int limit) 
{
    int i=0;
    int c; // the character inputted

    //printf(": ");

    while(i < limit-1
                && (c = getchar()) != EOF 
                //!ERROR start 
                //&& c != '\0' // end character should not be in 
                // input
                //!ERROR end 
                && c != '\n') {
        s[i] = c;
        ++i;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    //printf("contents of s >>>%s<<<", line);
    //printf("get_line() returning %d\n", i);
    return i;
}
//  END get_line 
