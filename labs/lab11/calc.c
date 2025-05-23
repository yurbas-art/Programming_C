#include "calc.h"
#include <limits.h>

// == Сумма чисел == 
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = 0;
    for (int i = 0; i < count; i++) {
        res += va_arg(args, int);
    }
    va_end(args);
    return res;
}

// == Поиск максимума ==
int max(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = INT_MIN;
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        if (num > res) res = num;
    }
    va_end(args);
    return res;
}

// == Поиск минимума ==
int min(int count, ...) {
    va_list args;
    va_start(args, count);
    int res = INT_MAX;
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        if (num < res) res = num;
    }
    va_end(args);
    return res;
}

// == Среднее арифметическое ==
float avg(int count, ...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return (float)sum / count;
}
