#include "game.h"
char PLAYER1 = 'X';
char PLAYER2 = 'O';

bool moveIsValid();

int main()
{
    initialBoard();
    printBoard();
    while (moveIsValid())
    {
        move(PLAYER1); 
        printBoard();
        if (!moveIsValid())
            break;

        move(PLAYER2);
        printBoard();
        if (!moveIsValid())
            break;
    }

    return EXIT_SUCCESS;
}

// Check if the input position is a valid move.
bool moveIsValid()
{   
    char winner = checkWinner();

    if ((winner==' ') && ( occupied()!= 9))
        return true;

    else{
        printWinner(winner);
        return false;
    }
}