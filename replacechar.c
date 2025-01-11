#include <stdio.h>

void createMatrix(char matrix[][100], int rows, int cols) {
    printf("Enter the matrix with characters:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf(" %c", &matrix[i][j]);
        }
    }
}

void printMatrix(char matrix[][100], int rows, int cols) {
    printf("Updated matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void replaceCharacters(char matrix[][100], int rows, int cols, char target, char replacement) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                matrix[i][j] = replacement;
            }
        }
    }
}

int main() {
    int rows, cols;
    char matrix[100][100];
    char target, replacement;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    createMatrix(matrix, rows, cols);

    printf("Enter the character to replace: ");
    scanf(" %c", &target);
    printf("Enter the replacement character: ");
    scanf(" %c", &replacement);

    replaceCharacters(matrix, rows, cols, target, replacement);

    printMatrix(matrix, rows, cols);

    return 0;
}
