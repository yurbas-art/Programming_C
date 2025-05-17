#include <stdio.h>
#include <stdlib.h>

double** sum(int n, double **mat1, double **mat2) {
    double **sum = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        sum[i] = (double *)malloc(n*sizeof(double));}
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return sum;
}

double** diff(int n, double **mat1, double **mat2) {
    double **diff = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        diff[i] = (double *)malloc(n*sizeof(double));}
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return diff;
}
double** product(int n, double **mat1, double **mat2) {
    double **product = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        product[i] = (double *)malloc(n*sizeof(double));}
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            product[i][j] = 0;
            for(int k = 0; k < n; k++) {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return product;
}