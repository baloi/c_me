#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char * one = "one";
    const char * two = "two";
    const char * one_dup = "one";

    if ( !strcmp(one, two)) {
        printf( "!strcmp(one, two)\n");
    } else {
        printf( "strcmp(one, two) returned a non zero\n");
    }

    if ( !strcmp(one, one_dup)) {
        printf( "!strcmp(one, one)\n");
    } else {
        printf( "strcmp(one, one) returned a non zero\n");
    }

}
