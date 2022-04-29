#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MATRIX_SIZE 9

int main() {
    int **matrix = (int **)malloc(MATRIX_SIZE * sizeof(int));
    int diagonal[(int) sqrt(MATRIX_SIZE)];
    int sum;

    srand(time(NULL));
    for(int i = 0; i < (sqrt(MATRIX_SIZE)); i++) {
        for(int j = 0; i < (sqrt(MATRIX_SIZE)); j++) {
            matrix[i][j] = 1 + rand() % 9;
        }
    }
    printf("Matriz original\n");

    for(int i = 0; i < (sqrt(MATRIX_SIZE)); i++) {
        printf("\t");
        for(int j = 0; j < (sqrt(MATRIX_SIZE)); j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < (sqrt(MATRIX_SIZE)); i++) {
        int k = i;
        diagonal[i] = matrix[i][k];
    }
    sum = diagonal[0];

    for(int i = 1; i < (sqrt(MATRIX_SIZE)); i++) {
        sum += diagonal[i];
    }
    printf("Traza de la matriz: %d\n", sum);

    return 0;
}
