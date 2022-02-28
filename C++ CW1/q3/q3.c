#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int i, num;
    int highest, lowest, range;

    printf("Input numbers: \n");
    for (i=0; scanf("%d", &num) && num>=0; i++){
        if (i==0){
            highest = num;
            lowest = num;
        }
        else if (num>highest){
            highest = num;
        }
        else if (num<lowest){
            lowest = num;
        }
    }
    range = highest - lowest;
    printf("Before the first negative number entered, number of values read: %d\nThe largest value: %d\nThe smallest value: %d\nRange: %d\n", i, highest, lowest, range);
}
