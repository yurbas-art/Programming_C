#include <math.h>

//Вычесление периметра треугольника
double calculate_perimeter(double a, double b, double c){
  return a + b + c;
}

//вычисление площади по Герону
double calculate_area(double a, double b, double c){
    double s = (a + b + c)/2; //полупериметр
    return sqrt(s*(s-a)*(s-b)*(s-c));
};
