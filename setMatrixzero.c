#include <stdio.h>

void setZeroMatrix(int matrix[][100], int rows, int cols) {
    int rowFlag[rows], colFlag[cols];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rowFlag[i] = 1;
                colFlag[j] = 1;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowFlag[i] == 1 || colFlag[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

void createMatrix(int matrix[][100], int rows, int cols) {
    printf("Enter the matrix with integers:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    createMatrix(matrix, rows, cols);

    setZeroMatrix(matrix, rows, cols);

    printf("Updated matrix:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
