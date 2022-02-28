#include "prime.h"

int main() 
{   
    int N = input();

    int* p = initializedArray(N+1);
    findMultiple(p, N);

    printPrime(p, N);
    printf("\n");
    return EXIT_SUCCESS;
}

// gcc array.c multiple.c print.c main_a.c -o prime_a 
