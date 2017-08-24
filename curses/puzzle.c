#include <stdio.h>
#include "sudoku.h"

int main()
{
    int ** puzzle;


    printf("creating array\n");

    puzzle = setup_puzzle();

    printf("created array\n");

    print_puzzle(puzzle);
    return 0;
}


