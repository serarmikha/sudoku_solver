#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

//char POSSIBLE =  0x1FF;

typedef struct Box{

    struct Box * next;

} Box;

typedef struct Square
{
    int number;

    /* 000000000
       987654321
       
       stores possible nubmers that could go in square
       0 = posiible
       1 = not possible*/
    char code;

    Box * box; //what box the square is in
    int row;
    int column;
} Square;



//returns an array of ints
int ** create_puzzle();

void print_puzzle(int ** puzzle);

Square *** setup_puzzle(int ** puzzle);

#endif