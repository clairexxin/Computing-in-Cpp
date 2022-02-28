#include <stdio.h>
#include <stdlib.h>
#define LENGTH 2

int main()
{
    char ch1, ch2;
    printf("Input two characters: ");
    scanf("%c %c", &ch1, &ch2);
    printf("In reserve order: %c %c\n", ch2, ch1);
}

