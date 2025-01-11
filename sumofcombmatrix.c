#include <stdio.h>

int ISdigit(char c) {
    return (c >= '0' && c <= '9');
}

int stringToInt(char *str) {
    int result = 0;
    while (*str) {
        if (!ISdigit(*str)) {
            return 0;
        }
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int isNumber(char *str) {
    while (*str) {
        if (!ISdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void inputMatrix(char matrix[][100][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%s", matrix[i][j]);
        }
    }
}

void printMatrix(char matrix[][100][10], int rows, int cols) {
    printf("\nMatrix Input:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sumIntegers(char matrix[][100][10], int rows, int cols) {
    int intSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isNumber(matrix[i][j])) {
                int num = stringToInt(matrix[i][j]);
                intSum += num;
            }
        }
    }
    return intSum;
}

int sumASCII(char matrix[][100][10], int rows, int cols) {
    int charSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!isNumber(matrix[i][j])) {
                for (int k = 0; matrix[i][j][k] != '\0'; k++) {
                    charSum += (int)matrix[i][j][k];
                }
            }
        }
    }
    return charSum;
}

int main() {
    int rows, cols;
    char matrix[100][100][10];

    scanf("%d", &rows);
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        printf("Invalid dimensions\n");
        return 1;
    }

    inputMatrix(matrix, rows, cols);
    int intSum = sumIntegers(matrix, rows, cols);
    int charSum = sumASCII(matrix, rows, cols);

    printMatrix(matrix, rows, cols);
    printf("\nSum of integers: %d\n", intSum);
    printf("Sum of ASCII values of characters: %d\n", charSum);
    printf("Total sum: %d\n", intSum + charSum);

    return 0;
}