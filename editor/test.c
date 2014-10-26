#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXLINES    1080

char *lineptr[MAXLINES];
void test_getline(void);
void test_getlines(void);
void write_lines(char *s[], int num_lines);

// testing getline and getlines
int main(int argc, char **argv)
{
    //test_getline();
    test_getlines();

    return 0;
}

// A test of how to use the standard getline() function to be able to input 
// multiple lines from 'stdin' and print it out. Notice the use of strdup()
// and a temporary variable to copy the value of line into the lineptr array of
// strings.
void test_getlines()
{
    //printf("hello\n");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *temp[1080]; 
    int i = 0;

    while ( (read = getline(&line, &len, stdin) != -1) && read != EOF) {
        //*temp = "hello";
        *temp = strdup(line);
        printf("l = %zu >>%s", read, line);
        printf("temp = %s\n", *temp);

        lineptr[i] = *temp;
        ++i;
    }

    write_lines(lineptr, i);

    free(line);



}

void test_getline()
{
    //printf("hello\n");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ( (read = getline(&line, &len, stdin) != -1) && read != EOF) {
        printf("l = %zu >>%s", read, line);
    }


    free(line);



}

void write_lines(char *lineptr[], int num_lines)
{
    int i;
    printf("Will now write %d lines...\n", num_lines);

    for (i=0; i < num_lines; i++) {
        printf("Got>>%s", lineptr[i]);
    }
}

