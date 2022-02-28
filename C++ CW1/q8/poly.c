#include "header.h"

struct node {
    float coef;
    int i;
    struct node* next;
};

void operate(struct node* a, struct node* b, int add) {
    if (add) {
        (*a).coef += (*b).coef;
    }
    else {
        (*a).coef -= (*b).coef;
    }
}

void changeSign(struct node* a) {
    while ((*a).next != NULL) {
        (*a).coef = (*a).coef * (-1);
        a = (*a).next;
    }
    if ((*a).next == NULL) {
        (*a).coef = (*a).coef * (-1);
    }
}

// a = a + b
// add two polynomials by their nodes and alter a such that a = a + b

// add two polynomials by looking into their index

struct node addResult(int i_1[], float coef_1[], int len1, int i_2[], float coef_2[], int len2, int ifadd) {

    int result_i[100];
    float result_coef[100];
    int count = 0;
    int j = 0;
    for (int i = 0; i < len1; i++) {

        while (i_2[j] < i_1[i] && j < len2) {
            result_i[count] = i_2[j];
            if (ifadd == 1) {
                result_coef[count] = coef_2[j];
            }
            else {
                result_coef[count] = -coef_2[j];
            }

            j += 1;
            count += 1;
        }
        if (i_2[j] == i_1[i] && j < len2) {
            result_i[count] = i_2[j];
            if (ifadd == 1) {
                result_coef[count] = coef_1[i] + coef_2[j];
            }
            else {
                result_coef[count] = coef_1[i] - coef_2[j];
            }

            j += 1;
            count += 1;
        }
        else if (i_2[j] > i_1[i] && j < len2) {
            result_i[count] = i_1[i];
            result_coef[count] = coef_1[i];
            count += 1;
        }
        else if (i_2[j] < i_1[i] && j == len2) {
            result_i[count] = i_1[i];
            result_coef[count] = coef_1[i];
            count += 1;

        }
    }
    while (j != len2) {
        result_i[count] = i_2[j];
        if (ifadd == 1) {
            result_coef[count] = coef_2[j];
        }
        else {
            result_coef[count] = -coef_2[j];
        }

        j += 1;
        count += 1;
    }

    struct node result = constructPoly(result_i, result_coef, count);
    return result;
}



struct node unitMulti2(int i_1, float coef_1, int i_2[], float coef_2[], int len2) {
    int result_i[1000];
    float result_coef[1000];
    for (int i = 0; i < len2; i++) {
        result_i[i] = i_2[i] + i_1;
        result_coef[i] = coef_2[i] * coef_1;
    }
    struct node result = constructPoly(result_i, result_coef, len2);
    return result;
}

struct node multiply2(int i_1[], float coef_1[], int len1, int i_2[], float coef_2[], int len2) {
    int result_i[1000];
    float result_coef[1000];

    struct node result;
    result.coef = 0;
    result.i = 0;
    result.next = NULL;
    for (int i = 0; i < len1; i++) {
        struct node unitMul = unitMulti2(i_1[i], coef_1[i], i_2, coef_2, len2);
        add(&result, &unitMul, 1);
    }
    return result;
}


float eval(struct node a0, int i, float x) {
    float result = 0;
    if (i == 0) {
        result = a0.coef;
    }
    else if (i == 1) {
        result = a0.coef + (*a0.next).coef * x;
    }
    else {
        result = a0.coef + eval(*a0.next, i - 1, x) * x;
    }
    return result;
}


struct node constructPoly(int ind[], float coef[], int len)
    /* 
    Input: ind[]:list of polynomial's exponential index i.e. {i} s.t. i->x^i
    coef[]:list of polynomial's coeficient i.e. {x} s.t. x->x^i
    Function: represent the polynomial as linked list
    Output: return the first node of the polynomial
    */
{
    struct node start;
    start.i = 0;
    start.coef = 0;
    start.next = NULL;
    struct node* curr = &start;
    int startInd = 0;
    if (ind[0] == 0) {
        start.coef = coef[0];
        startInd += 1;
    }
    int polyInd = 1;
    for (int count = startInd; count < len; count++) {
        while (polyInd != ind[count]) {
            struct node* newNode = create(polyInd, 0);
            curr->next = newNode;
            curr = curr->next;
            polyInd += 1;
        }
        struct node* newNode = create(polyInd, coef[count]);
        curr->next = newNode;
        polyInd += 1;
        curr = curr->next;
    }
    return start;
}
