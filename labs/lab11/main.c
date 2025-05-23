#include <stdio.h>
#include "calc.h"

int main() {
    // Вызов функций
    printf("Sum: %d\n", sum(3, 5, 10, 15));          // 5 + 10 + 15 = 30
    printf("Max: %d\n", max(4, 2, 7, 1, 9));         // 9
    printf("Min: %d\n", min(4, 2, 7, 1, 9));         // 1
    printf("Avg: %.2f\n", avg(3, 10, 20, 30));       // (10+20+30)/3 = 20.00

    return 0;
}
