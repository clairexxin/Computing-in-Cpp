#include "prime.h"

int main()
{
    int N = input();
    int* p = initializedArray(N+1);
    initializedArray(N+1); // int array, accessed by p

    int count = countOdd(p,N);
    int* pc = removeEven(p, count) ; // new int array after removing even numbers, accessed by pc

    findMultiple_odd(pc, N, count);
    printPrime_odd(pc, N, count);
    printf("\n");

    return EXIT_SUCCESS;
}

//gcc array.c even.c multiple.c print.c main_b.c -o prime_b 