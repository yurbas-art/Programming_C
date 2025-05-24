#include <stdio.h>
#include "calc.h"

int main() {
    int count = 5;
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    printf("Sum: %d\n", calc_sum(count, a, b, c, d, e));
    printf("Max: %d\n", calc_max(count, a, b, c, d, e));
    printf("Min: %d\n", calc_min(count, a, b, c, d, e));
    printf("Avg: %.2f\n", calc_avg(count, a, b, c, d, e));

    return 0;
}
