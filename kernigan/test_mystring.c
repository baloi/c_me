#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

int main(int argc, char **argv) {
    char orig[] = "dada";
    char *to = malloc(sizeof(orig));

    copy(to, orig);
    
    printf("copied >>%s<< to variable to\n", to);
    return 0;
}
