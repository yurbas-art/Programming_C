#include <stdio.h>
#include "triangle.h"

int main(int argc, char argv[]){
    double a, b, c;
    //ввод длин сторон
    printf("Enter sids of the triangle (a,b,c):");
    scanf("%lf %lf %lf", &a, &b, &c);
    //проверка
    if (a+b>c && a+c>b && b+c>a){
        double perim = calculate_perimeter(a, b, c);
        double area = calculate_area(a, b, c);
        printf("Perimeter = %lf\n", perim);
        printf("Area = %lf\n", area);
    }
    else{
        printf("Error. can`t build triangle");
    }
    return 0;
}
