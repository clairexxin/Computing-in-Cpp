#include <stdio.h>
#include <stdlib.h>

struct node;
struct node* create(int i, float coef);
struct node multiply2(int i_1[], float coef_1[], int len1, int i_2[], float coef_2[], int len2);
struct node constructPoly(int ind[], float coef[], int len);
void display(struct node a);
void operate(struct node* a, struct node* b, int add);
void changeSign(struct node* a);
void add(struct node* a, struct node* b, int add);
struct node addResult(int i_1[], float coef_1[], int len1, int i_2[], float coef_2[], int len2, int ifadd);
float eval(struct node a0, int i, float x);
struct node unitMulti2(int i_1, float coef_1, int i_2[], float coef_2[], int len2);