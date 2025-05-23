#include <stdio.h>

int countSetBitsLong(long num)
{
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1; //побитовый сдвиг числа num на 1
    }
    return count;
}

int countSetBitsDouble(double num)
{
    int count = 0;
    unsigned long long int *p = (unsigned long long int *)&num;
    unsigned long long int temp = *p;

    while (temp)
    {
        count += temp & 1;
        temp >>= 1;
    }
    return count;
}
int main() {
    long inputLong;
    double inputDouble;
    printf("enter long: ");
    scanf("%ld", &inputLong);
    printf("enter double: ");
    scanf("%lf", &inputDouble);
    int longBits = countSetBitsLong(inputLong);
    int doubleBits = countSetBitsDouble(inputDouble);
    printf("The number of bits set to one in a number of the typelong: %d\n", longBits);
    printf("The number of bits set to one in a number of the type double: %d\n", doubleBits);

    return 0;
}
//link
//https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
//https://www.cyberforum.ru/c-beginners/thread1725665.html
