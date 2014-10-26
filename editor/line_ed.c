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
    int i;
    printf("Will now write %d lines...\n", num_lines);

    for (i=0; i < num_lines; i++) {
        printf(">%s", lineptr[i]);
    }
}

//      write_lines() end

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
    char *line = NULL;
    ssize_t read;
    // create a temporary array of characters where the value of line can be stored
    //char *temp_line[256]; 
    char *temp_line = NULL; 

    nlines = 0;


    //while( (len = get_line(line, MAXLEN)) > 0) {
    while( ( read  = getline(&line, &len, stdin)) != -1 && read != EOF) {

        if (nlines >= maxlines) {
            return -1;
        }
        else {
            // the value of temp_line will be the value of duplicated string 
            // line. 'line' needs to be passed to strdup to duplicate the 
            // string as line is an address. Each time we go to this line
            // temp_line is pointing to a new address
            temp_line = strdup(line);
            //printf("temp_line now pointing to %d ", &temp_line);

            // lineptr[nlines] value is set to *temp_line
            // We are setting the value and not the address.
            //lineptr[nlines] = *temp_line;
            lineptr[nlines] = temp_line;
            //printf("lineptr[%d] = %s\n", nlines, *temp_line);
            ++nlines;
        }

    }

    free(line);

    //free(p);

    //printf("read %d lines...\n", nlines);
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

int get_line(char s[], int limit) 
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

// get_line function end
