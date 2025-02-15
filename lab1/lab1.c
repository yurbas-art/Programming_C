#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    double a,b,c;
    double x1,x2,d;
    
    a = 5.2;
    b = 10.1;
    c = 2.9;
    
    d = pow(b,2) - 4 * a * c;
    
    x1 = -b + sqrt(d) / (2 * a);
    x2 = - b - sqrt(d) / (2 * a);
    
    printf("x1 = %lf\n", x1);
    printf("x2 = %lf\n", x2);
    printf("d1 = %lf\n", d);
    return 0;


}