#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "sours.h"

int main(){
    double s;
    int a, b, c, p;

    printf("input:");
    scanf("%d %d %d", &a, &b, &c);

    if (check(a, b, c)){
        p = perimetr(a, b, c);
        s = sqrt(square(a, b, c));
        printf("perimetr: %d\n", p);
        printf("square: %.2lf", s);}
    else {printf("Error");}
    return 0;}
