#include "game.h"

// Check if there is a winner
char checkWinner()
{
    int i;
    char winner = ' ';

    for (i=0; i<3; i++){
        // case1: 3 same item on a row.
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
            return board[i][0];

        // case2: 3 same item on a column.
        else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
            return board[0][i];
    }

    // case3: 3 same item on a diagonal.
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
        return board[0][0];

    else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
        return board[0][2];

    // if none of the above cases appear, no winner.
    return ' ';
}

void printWinner(char x)
{
    if (x == 'X')
        printf("Winner is PLAYER1.\n");
    else if (x == 'O')
        printf("Winner is PLAYER2.\n");
    else
        printf("Two players tied.\n");
}
