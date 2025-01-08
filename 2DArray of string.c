#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    int rows, cols, vowelCount = 0;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    char longestName[MAX_NAME_LENGTH] = "";

    do {
        printf("Enter number of rows (1 to 10): ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > 10);

    do {
        printf("Enter number of columns (1 to 101): ");
        scanf("%d", &cols);
    } while (cols < 1 || cols > 101);

    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);

            if (isVowel(names[i][j][0])) {
                vowelCount++;
            }

            if (strlen(names[i][j]) > strlen(longestName)) {
                strcpy(longestName, names[i][j]);
            }
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    return 0;
}
