#include<stdio.h>

void initializematrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void displayMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void flipcell(int n, int matrix[n][n], int row, int col) {
    row--;
    col--;
    if (row >= 0 && row < n && col >= 0 && col < n) {
        matrix[row][col] = 1 - matrix[row][col];
    } else {
        printf("Invalid indices. Please provide valid row and column numbers.\n");
    }
}

void horizontallyInverseRows(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int temp = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = temp;
            start++;
            end--;
        }
    }
}

void rotate90(int n, int matrix[n][n]) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    
    // Step 2: Reverse each column
    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int temp = matrix[start][i];
            matrix[start][i] = matrix[end][i];
            matrix[end][i] = temp;
            start++;
            end--;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    
    // Initialize and display the matrix
    initializematrix(n, matrix);
    displayMatrix(n, matrix);
    
    int row, col;
    scanf("%d %d", &row, &col);
    
    // Perform flip and display the matrix
    flipcell(n, matrix, row, col);
    displayMatrix(n, matrix);
    
    // Perform horizontal inversion and display the matrix
    horizontallyInverseRows(n, matrix);
    displayMatrix(n, matrix);
    
    // Perform 90-degree rotation and display the matrix
    rotate90(n, matrix);
    displayMatrix(n, matrix);
    
    return 0;
}
