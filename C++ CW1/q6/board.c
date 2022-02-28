#include "game.h"

// Initialize an board with empty character.
void initialBoard()
{   
    int i,j;
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            board[i][j]=' ';
        }
    }
}

// visualize an board.
void printBoard()
{   
    int i;
    for (i=0; i<3; i++){
        printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
        if (i<2)
            printf("--- --- ---\n");
        else if(i==2)
            printf("\n");
    }
}

// Return number of position that is occuped in the board.
int occupied()
{
    int i,j,count=0;
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            if (board[i][j] != ' ')
                count++;
        }
    }
    return count;
}