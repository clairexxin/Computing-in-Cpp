#include "header.h"

struct node {
    float coef;
    int i;
    struct node* next;
};

struct node* create(int i, float coef) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->i = i;
        newNode->coef = coef;
        newNode->next = NULL;
    }
    return newNode;
}

void display(struct node a) {
    while (a.next != NULL) {
        printf("(%f)x^%d", a.coef, a.i);
        printf(" + ");
        a = *a.next;
    }
    if (a.next == NULL) {
        printf("(%f)x^%d", a.coef, a.i);
    }
}

void add(struct node* a, struct node* b, int add) {
    struct node* curr_a = a;
    int proceed = 1;
    while (curr_a != NULL && proceed) {
        int found = 0;
        struct node* curr = b;
        while (curr != NULL && !found) {
            if (curr_a->i == curr->i) {
                operate(curr_a, curr, add);
                found = 1;
            }
            curr = curr->next;
        }

        if (found && curr != NULL) {
            b = curr;
        }

        // if len(b) > len(a) i.e. still some terms left in b
        if (curr_a->next == NULL && curr != NULL) {
            curr_a->next = b;
            if (!add) {
                changeSign(b);
            }
            proceed = 0;
        }
        else if (curr_a->next == NULL && curr == NULL && !found) {
            if (b->i > curr_a->i) {
                curr_a->next = b;
                if (!add) {
                    changeSign(b);
                }
            }
            else if (b->i > curr_a->i) {
                a->next = b;// error: function should return a with new value
            }
        }
        curr_a = curr_a->next;
    }
}

