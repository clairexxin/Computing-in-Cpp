#include "prime.h"


// Part-a: find multiple of the all numbers
void findMultiple(int* p, int N)
{
    int n,j;
    for (n=2; (n*n)<=N; n++)
    {
        for (j=n+1; j<N+1; j++)
        {
            if ((*(p+j) !=0) && (*(p+j) % n == 0))
                *(p+j) = 0;
        }
    }
}


// Part-b: find multiple of the remaining odd numbers
void findMultiple_odd(int* pc, int N, int count)
{
    int n,j;
    for (n=3; (n*n)<=N; n+=2)
    {
        for (j=(n-1)/2; j<count+1; j++)
        {
            if ((*(pc+j) !=0) && (*(pc+j) % n == 0))
                *(pc+j) = 0;
        }
    }
}
