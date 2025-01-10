#include <stdio.h>
#include <stdlib.h>

void snakePrint(int **mat, int rows, int cols) {
    printf("Matrix in snake pattern: ");
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", mat[i][j]);
            }
        } else {
            for (int j = cols - 1; j >= 0; j--) {
                printf("%d ", mat[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    snakePrint(mat, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
