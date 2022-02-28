#include "header.h"

int isQualify(int numerator, int denominator)
{
    int nd = numerator % 10;   /* i.e. numerator = 12 -> nd = 2, nt = 1*/
    int dd = denominator % 10;
    int nt = (numerator - nd) / 10; /* i.e. denominator = 24 -> dd = 4, dt = 2*/
    int dt = (denominator - dd) / 10;

    /*printf("nd: %d\ndd: %d\nnt: %d\ndt: %d\n", nd, dd, nt, dt);*/

    int result = 0; /*False*/
    if (nd == dd) {
        if (numerator * dt - denominator * nt == 0) {
            /*printf("n/d == nt/dt\n");*/
            result = 1;
        }
    }
    else if (nd == dt)
    {
        if (numerator * dd - denominator * nt == 0) {
            /*printf("n/d == nt/dd\n");*/
            result = 1;
        }
    }
    else if (nt == dd) {
        if (numerator * dt - denominator * nd == 0) {
            /*printf("n/d == nd/d\n");*/
            result = 1;
        }
    }
    else if (nt == dt) {

        if (numerator * dd - denominator * nd == 0) {
            /*printf("n/d == nd/dd\n");*/
            result = 1;
        }
    }

    return result;

}