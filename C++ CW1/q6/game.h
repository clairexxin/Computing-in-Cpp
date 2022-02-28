#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];

void initialBoard();
void printBoard();
int occupied();
char checkWinner();
void move(char player);
void printWinner(char x);
