#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

void test_copy();
void test_squeeze();

int main(int argc, char **argv) {
    test_copy();
    test_squeeze();
    return 0;
}

void test_copy() {
    printf("\nTEST -- test_copy() -- START\n");
    char orig[] = "dada";
    char *to = malloc(sizeof(orig));

    copy(to, orig);
    
    printf("copied >>%s<< to variable to\n", to);
    printf("TEST -- test_copy() -- END\n");

}

void test_squeeze() {
    char unsqueezed[] = "perxson";
    char to_squeeze = 'x';

    printf("\nTEST -- test_squeeze() -- START\n");
    
    printf("original >>%s<< \n", unsqueezed);
   
    squeeze(unsqueezed, to_squeeze);

    printf("squeezed %c from original string, now %s\n", 
            to_squeeze, unsqueezed);

    printf("\nTEST -- test_squeeze() -- END\n");

}
