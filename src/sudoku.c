//#include "../include/sudoku.h"
#include "sudoku.h"

char POSSIBLE = 0x1FF; //111111111
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;


int main(){

    int ** puzzle;
    Square ** sudoku;


    puzzle = create_puzzle();

    print_puzzle(puzzle);
    
    setup_puzzle(puzzle);

    return 0;
}