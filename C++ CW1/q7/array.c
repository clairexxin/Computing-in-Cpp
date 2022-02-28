#include "prime.h"

// get input number
int input()
{
    int N; 
    printf("Enter a natural number:");
    scanf("%d", &N);
    return N;
}

// create dynamic array containing integers up to N
int* initializedArray(int n)
{
    int i;
    int* p = (int*)calloc( n, sizeof(int));
    for (i=0; i< n; i++)
        *(p+i) = i;
    *p=0;
    *(p+1)=0;
    return p;
}