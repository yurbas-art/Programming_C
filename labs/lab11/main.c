#include <stdio.h>
#include <stdarg.h>

//sum
int calc_sum(int num, ...)
{
    va_list args;
    va_start(args, num);
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
//max
int calc_max(int num, ...)
{
    va_list args;
    va_start(args, num);
    int max = va_arg(args, int);
    for (int i = 1; i < num; i++) {
        int cur = va_arg(args, int);
        if (cur > max) {
            max = cur;
        }
    }

    va_end(args);
    return max;
}

// Функция нахождения минимума
int calc_min(int num, ...)
{
    va_list args;
    va_start(args, num);

    int min = va_arg(args, int);
    for (int i = 1; i < num; i++) {
        int current = va_arg(args, int);
        if (current < min) {
            min = current;
        }
    }

    va_end(args);
    return min;
}

// Функция вычисления среднего
double calc_avg(int num, ...)
{
    va_list args;
    va_start(args, num);

    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return (double)sum / num;
}

int main()
{
    int count =5;
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    printf("Sum: %d\n", calc_sum(count, a, b, c, d, e));
    printf("Max: %d\n", calc_max(count, a, b, c, d, e));
    printf("Min: %d\n", calc_min(count, a, b, c, d, e));
    printf("Avg: %.2f\n", calc_avg(count, a, b, c, d, e));

    return 0;
}
