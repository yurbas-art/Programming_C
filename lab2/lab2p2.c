#include <stdio.h>

int main() {
    int matrix[2][2], result[2][2];


    printf("Введите 4 значения для матрицы 2x2:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &matrix[i][j]);

  
    result[0][0] = matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0];
    result[0][1] = matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1];
    result[1][0] = matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0];
    result[1][1] = matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1];

    printf("Квадрат матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
