#include <stdio.h>

void print_cur_digit(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        print_cur_digit(n / 10);
        printf("%d ", n % 10);
    }
}

void print_rev_digit(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        printf("%d ", n % 10);
        print_rev_digit(n / 10);
    }
}
int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    printf("Digits curret: ");
    print_cur_digit(N);
    printf("\n");

    printf("Digits reverse: ");
    print_rev_digit(N);
    printf("\n");

    return 0;
}
