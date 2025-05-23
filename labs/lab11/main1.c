#include <stdio.h>
#include <stdarg.h>

void calc(int num, ...)
{
    va_list args; // указатель на необязательный параметр
    va_start(args, num); //

    int sum = 0;
    int max = va_arg(args, int); //
    int min = max;

    for (int i = 1; i < num; i++)
    {
        int arg = va_arg(args, int);

        sum += arg;

        if (arg > max)
        {
            max = arg;
        }

        if (arg < min)
        {
            min = arg;
        }
    }

    double avg = (double)sum / num;

    printf("Sum: %d\n", sum);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Avg: %.2f\n", avg);

    va_end(args);
}

int main()
{
    calc(5, 10, 20, 30, 40, 50);// кол-во чисел,число,число...
    return 0;
}

// void calc ( https://metanit.com/c/tutorial/5.13.php )
