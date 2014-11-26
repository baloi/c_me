#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

void test_copy();

int main(int argc, char **argv) {
    test_copy();
    return 0;
}

void test_copy() {
    char orig[] = "dada";
    char *to = malloc(sizeof(orig));

    copy(to, orig);
    
    printf("copied >>%s<< to variable to\n", to);

}
