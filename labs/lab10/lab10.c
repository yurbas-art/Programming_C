#include <stdio.h>

#define MAX_NUM(arr, n) ({ \
int max_num = arr[0]; \
for (int i = 1; i < n; i++) { \
if (arr[i] > max_num) { \
max_num = arr[i]; \
} \
} \
max_num; })
#define AVG(array, n) ({ \
int sum = 0; \
for (int i = 0; i < n; i++) { \
sum += array[i]; \
} \
(float)sum / n; \
})
int main()
{
    int n;
    printf("Enter the number of chisel: ");
    scanf("%d", &n);

    int numbers[n];

    printf(" ender number separated by a space: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int max_num = MAX_NUM(numbers, n);

    printf("max nubmer: %d\n", max_num );
    printf("average: %f", AVG(numbers, n));

    return 0;
}
