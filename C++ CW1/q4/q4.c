#include <stdio.h>
#include <stdlib.h>

void reverse();

int main(void)
{
    printf("Enter 200 characters: \n");
    reverse();
    printf("\n");
    return EXIT_SUCCESS;
}

void reverse()
{   
    char ch;
    scanf("%c", &ch);
    if (ch!='\n'){
        reverse();
        printf("%c",ch);
    }
}