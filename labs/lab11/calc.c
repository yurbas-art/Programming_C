#include "calc.h"
#include <stdarg.h>

int calc_sum(int num, ...) {
    if (num <= 0) return 0;

    va_list args;
    va_start(args, num);
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int calc_max(int num, ...) {
    if (num <= 0) return 0;

    va_list args;
    va_start(args, num);
    int max = va_arg(args, int);
    for (int i = 1; i < num; i++) {
        int cur = va_arg(args, int);
        if (cur > max) max = cur;
    }
    va_end(args);
    return max;
}

int calc_min(int num, ...) {
    if (num <= 0) return 0;

    va_list args;
    va_start(args, num);
    int min = va_arg(args, int);
    for (int i = 1; i < num; i++) {
        int cur = va_arg(args, int);
        if (cur < min) min = cur;
    }
    va_end(args);
    return min;
}

double calc_avg(int num, ...) {
    if (num <= 0) return 0.0;

    va_list args;
    va_start(args, num);
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return (double)sum / num;
}