#include <stdio.h>
#include <stdlib.h>
#include "task5.3.c"

int main() {
    int n, i, j;
    char zn;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    double **arr1 = (double **)malloc(n * sizeof(double));
    double **arr2 = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        arr1[i] = (double *)malloc(n*sizeof(double));
        arr2[i] = (double *)malloc(n*sizeof(double));
    }
    if (arr1 == NULL || arr2 == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    printf("Введите элементы первого массива:\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr1[%d][%d] = ", i, j);
            scanf(" %lf", &arr1[i][j]);
        }
    }
    getchar();
    printf("Введите элементы второго массива:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("arr2[%d][%d] = ", i, j);
            scanf(" %lf", &arr2[i][j]);
        }
    }    
    getchar();
    printf("Элементы массива 1:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf ", arr1[i][j]);
        } printf("\n");
    } 
    
    printf("\nЭлементы массива 2:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf ", arr2[i][j]);
        } printf("\n");
    } 
    printf("Введите знак операции:\n");
    zn = getchar();
    double **res;
    switch (zn){
        case '+': 
            res = sum(n, arr1, arr2); 
            printf("Сумма матриц:\n");
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    printf("%.2lf ", res[i][j]);
                }
                printf("\n");
            }
            break;
        case '-':
            res = diff(n, arr1, arr2);
            printf("Разность матриц:\n");
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    printf("%.2lf ", res[i][j]);
                }
                printf("\n");
            }
            break;
        case '*':
            res = product(n, arr1, arr2);
            printf("Произведение матриц:\n");
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    printf("%.2lf ", res[i][j]);
                }
                printf("\n");
            } break;
        default: 
            printf("Неверный знак.\n"); 
            break;
        }

    for (i = 0; i < n; i++) {
        free(arr1[i]); free(arr2[i]); free(res[i]);
    }    
    free(arr1); free(arr2); free(res);
    
    return 0;
}