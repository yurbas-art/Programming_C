#include <stdio.h>


#define MAX_NUM(arr, n) ({ \
    int max = arr[0];      \
    for (int i = 1; i < n; i++) { \
        if (arr[i] > max) max = arr[i]; \
    } \
    max; \
})

int main() {
    int n;
    printf("Skolko chisel? ");
    scanf("%d", &n);

    int numbers[n];

    printf("Vvedite chisla cherez probel: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Max number: %d\n", MAX_NUM(numbers, n));

    return 0;
}
