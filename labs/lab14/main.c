#include <stdio.h>
#include <setjmp.h>

jmp_buf env; // buffer for save current

//function for calc digit Fibbon sum
void fib_sum(int n, int *sum, int a, int b) {
    if (n <= 0) {
        longjmp(env, 1); // exit from rekurs
    }

    *sum += a; // add curret digit Fibbon to the sum
    fib_sum(n - 1, sum, b, a + b); // rekurs call
}

int main() {
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int sum = 0;

    if (setjmp(env) == 0) {
        //call setjmp, start rekurs
        fib_sum(n, &sum, 1, 1);
    } else {
        // get there after longjmp
        printf("sum first %d digit Fibbonachi: %d\n", n, sum);
    }

    return 0;
}
//link:
//https://metanit.com/c/tutorial/10.2.php
