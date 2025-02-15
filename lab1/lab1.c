#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    double a,b,c;
    double x1,x2,d,x0;
    
    printf("Vvedite a:\n");
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    
    char not1[] = "Koren net";
    char one[] = "Est 1 koren";
    char two[] = "Est 2 koren";
    
    
    if (d < 0) printf("%s\n", not1);
    if (d == 0) {
    x0 = -b / 2*a;
    printf("%s\n", one);
    printf("x0 = %lf\n",x0);
    }

    if (d > 0) {
        x1 = -b + sqrt(d) / (2 * a);
        x2 = - b - sqrt(d) / (2 * a);
        printf("%s\n", two);
        printf("x1 = %lf\n", x1);
        printf("x2 = %lf\n", x2);
    }
    d = pow(b,2) - 4 * a * c;
    printf("d1 = %lf\n", d);
    return 0;


}
