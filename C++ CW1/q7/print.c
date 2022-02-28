#include "prime.h"

// part-a: print prime (mark multiple directly)
void printPrime(int* p, int N)
{
    int i;
    printf("Primes less than or equal to %d are: \n", N);
    for (i=0; i< N+1; i++){
        if ( *(p+i) != 0) 
            printf("%d ", *(p+i));
    }
}


// part-b: print prime (mark multiple after removing all even numbers)
void printPrime_odd(int* pc, int N, int count)
{
    int i;
    printf("Primes less than or equal to %d are: \n", N);
    printf("2 "); 
    // here, we add back prime 2, since we remove it when removing all even numbers in the array.
    
    for (i=0; i< count+1; i++){
        if ( *(pc+i) != 0) 
            printf("%d ", *(pc+i));
    }
}
