//Create, print, and display puzzle here

//#include  "../include/sudoku.h"
#include "sudoku.h"

Square *** setup_puzzle(int ** puzzle){

    Square *** sudoku;

    //dynamically allocate memory for square
    sudoku = (Square***)malloc(sizeof(Square**)*9);

    //loop through puzzle and fill in "possible" for each square if it has a non-zero number
    for(int i = 0; i < 9; i++){

        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);
        for (int j = 0; j < 9; j++){
            sudoku[i][j] = (Square*)malloc(sizeof(Square)*9);

            sudoku[i][j]->number = puzzle[i][j];
            
            //if number is not 0, then the square is not empty and has all possibilities
            if(sudoku[i][j]->number != 0){
                sudoku[i][j]->code = POSSIBLE;
            }
            else{
                sudoku[i][j]->code = 0x0;
            }

            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
        }
    }

    // return sudoku;

}


int ** create_puzzle(){
    int ** puzzle;
    int i, j;
    int array[9][9] = {0,1,9,   0,0,2,  0,0,0,
                       4,7,0,   6,9,0,  0,0,1,
                       0,0,0,   4,0,0,  0,9,9,
                       
                       8,9,4,   5,0,7,  0,0,0,
                       0,0,0,   0,0,0,  0,0,0,
                       0,0,0,   2,0,1,  9,5,8,
                       
                       0,5,0,   0,0,6,  0,0,0,
                       6,0,0,   0,2,8,  0,7,9,
                       0,0,0,   1,0,0,  8,6,0};

    //can't return array, because it's not dynamically allocated
    //have to use malloc first

    puzzle = (int**)malloc(sizeof(int*) * 9); //creates 9 arrays

    for(int i = 0; i < 9; i++){

        //create second dimension of each array
        puzzle[i] = (int*)malloc(sizeof(int)*9); 

        for (int j = 0; j < 9; j++){
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

void print_puzzle(int ** puzzle){

    printf("-------------------------------\n");
    for (int i = 0; i< 9; i++){
        
        for(int j=0; j<9; j++){
            if(j==0){
                printf("|");
            }
            printf(" %d ", puzzle[i][j]);
            if ((j+1)%3 == 0){
                printf("|");
            }

        }
        if((i+1)%3 == 0){
            printf("\n-------------------------------");
        }
        printf("\n");
        
    }
}