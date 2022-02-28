#include "game.h"

void move(char player) 
{   
    int x,y;
    if (player == 'X'){
        printf("PLAYER1, please enter your row number and column number(withnin range: 1 to 3): \n");
    }
    else if (player == 'O'){
        printf("PLAYER2, please enter your row number and column number(withnin range: 1 to 3): \n");
    }
    
    scanf("%d %d",&x,&y);
    x--;
    y--;

    // if place is already occupied, re-enter.
    while (!((board[x][y] == ' ' && x<3) && (x<3 && y<3)))
    {
        printf("Invalid move, please enter another row and column number(withnin range: 1 to 3): \n");
        scanf ("%d %d",&x,&y);
        x--;
        y--;
        if ((board[x][y] == ' ' && x<3) && (x<3 && y<3))
            break;
    }

    board[x][y] = player;
}
