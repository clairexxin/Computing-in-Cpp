#include "prime.h"

// count number of odds in array
int countOdd(int* p, int N)
{
    int i, count=0;

    for(i=0; i<N+2; i++) 
    {
        if ((*(p+i) %2 !=0) && (i > count))
        {   
            *(p+count) = *(p+i);
            count++;
        }
    }
    return count;
}

// create a new array of odd numbers, which can be accessed by pc.
int* removeEven(int* p, int count) 
{
    int* pc=(int*)realloc(p, count * sizeof(int));
    return pc;
}