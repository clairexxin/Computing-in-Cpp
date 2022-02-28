#include "header.h"

int main()
{
    int tSize = 10;
    int dSize = 10;
    int seqSize = 90;
    printf("Fractions with two-digit numerators and denominators for which Sleepy's technique gives the right answer are: \n");
    for (int t = 1; t < tSize; t++) {
        for (int d = 0; d < dSize; d++){
            int numer = t * 10 + d;
            for (int i = 0; i < seqSize; i++) {
                if (isQualify(numer, i + 10)) {
                    printf("%d/%d\n", numer, i + 10);
                }
            }
        }
    }
}

