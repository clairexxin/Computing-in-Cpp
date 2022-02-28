
#include "header.h"
struct node {
    float coef;
    int i;
    struct node* next;
};

int main()
{
    struct node Result;
    int N, num, count1, count2, count3,i;
    int checkScanf;
    float coef;
    int input1_i[100];
    float input1_coef[100];
    int input2_i[100];
    float input2_coef[100];
    int input3_i[100];
    float input3_coef[100];

    printf("Do you want to 1.add, 2.subtract, 3.multiply or 4.evaluate?\n");
    printf("Please select an option from above (i.e select 1, 2, 3 or 4):\n");
    int operation;
    checkScanf = scanf("%d", &operation);
    

    if (operation != 4) {
        printf("Please enter the maximum exponent N of the first polynomial:\n");

        checkScanf = scanf("%d", &N);
        printf("Please enter the exponents and corresponding coefficients (i, a_i) of the first polynomial: \n");
        printf("(Note that exponent i starts from 0, and should be entered in an ascending order to N, \ne.g. for polynomial (0x^0 + 2x^1 + 3x^2), you should enter: 0,0 1,2 2,3 )\n");

        count1 = 0;
        while (count1 <= N) {
            checkScanf = scanf("%d,%f", &num, &coef);
            input1_i[count1] = num;
            input1_coef[count1] = coef;
            count1 += 1;
        }

        printf("Please enter the maximum exponent N of the second polynomial:\n");
        checkScanf = scanf("%d", &N);
        printf("Please enter the exponents and corresponding coefficients (i, a_i) of the second polynomial: \n");
        printf("(Note that exponent i starts from 0, and should be entered in an ascending order to N, \ne.g. for polynomial (0x^0 + 2x^1 + 3x^2), you should enter: 0,0 1,2 2,3 )\n");

        count2 = 0;

        while (count2 <= N) {
            checkScanf = scanf("%d,%f", &num, &coef);
            input2_i[count2] = num;
            input2_coef[count2] = coef;
            count2 += 1;
        }
        printf("The result is:\n");

        // if add
        if (operation == 1) {
            Result = addResult(input1_i, input1_coef, count1, input2_i, input2_coef, count2, 1);
            display(Result);
            printf("\n");
        }
        else if (operation == 2) {
            Result = addResult(input1_i, input1_coef, count1, input2_i, input2_coef, count2, 0);
            display(Result);
            printf("\n");
        }
        else if (operation == 3) {
            Result = multiply2(input1_i, input1_coef, count1, input2_i, input2_coef, count2);
            display(Result);
            printf("\n");
        }
    }


    else if(operation == 4) {
        printf("Please enter the maximum exponent N of polynomial:\n");
        checkScanf = scanf("%d", &N);
        printf("Please enter the exponents and corresponding coefficients (i, a_i) of polynomial: \n");
        printf("(Note that exponent i starts from 0, and should be entered in an ascending order to N, \ne.g. for polynomial (0x^0 + 2x^1 + 3x^2), you should enter: 0,0 1,2 2,3 )\n");
           
        count3 = 0;

        while (count3 <= N) {
            checkScanf = scanf("%d,%f", &num, &coef);
            input3_i[count3] = num;
            input3_coef[count3] = coef;
            count3 += 1;
        }

        struct node poly = constructPoly(input3_i, input3_coef, count3);
        float x;

        printf("Please enter a number x:\n");
        checkScanf = scanf("%f", &x);
        float evalResult = eval(poly, N, x); 
        printf("The final evaluation is: %f\n", evalResult);
        printf("\n");
    }
}
