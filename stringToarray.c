#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int customAtoi(char *str) {
    int num = 0, i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num;
}

void parseStringToArray(char *str, int arr[MAX_ROWS][MAX_COLS], int *rows, int *cols) {
    int i = 0, j = 0;
    char temp[10];
    int tempIndex = 0;
    *rows = *cols = 0;

    while (*str != '\0') {
        if (*str == '(') {
            j = 0;
            tempIndex = 0;
        } else if (*str == ')') {
            temp[tempIndex] = '\0';
            arr[*rows][j] = customAtoi(temp);
            j++;
            tempIndex = 0;
            (*rows)++;
        } else if (*str == ',') {
            temp[tempIndex] = '\0';
            arr[*rows][j] = customAtoi(temp);
            j++;
            tempIndex = 0;
        } else {
            temp[tempIndex] = *str;
            tempIndex++;
        }
        str++;
    }
    *cols = j;
}

void printArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Parsed 2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char input[500];
    int arr[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter a string with parentheses: ");
    scanf(" %[^\n]", input);

    parseStringToArray(input, arr, &rows, &cols);
    printArray(arr, rows, cols);

    return 0;
}
