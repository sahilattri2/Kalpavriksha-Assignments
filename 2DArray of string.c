#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50

char toLowerCase(char ch) 
{
    if (ch >= 'A' && ch <= 'Z') 
    {
        return ch + ('a' - 'A');
    }
    return ch;
}

int isVowel(char ch)
{
    ch = toLowerCase(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int stringLength(const char *str) 
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void stringCopy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0') 
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int getInputInRange(const char *prompt, int min, int max)
{
    int value;
    do {
        printf("%s (%d to %d): ", prompt, min, max);
        scanf("%d", &value);
    }
    while (value < min || value > max);
    return value;
}

void fillArray(char *names[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            names[i][j] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
            if (names[i][j] == NULL)
            {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
}

void printArray(char *names[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
}

void processArray(char *names[MAX_ROWS][MAX_COLS], int rows, int cols, int *vowelCount, char *longestName)
{
    *vowelCount = 0;
    longestName[0] = '\0';

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            if (isVowel(names[i][j][0])) {
                (*vowelCount)++;
            }
            if (stringLength(names[i][j]) > stringLength(longestName)) 
            {
                stringCopy(longestName, names[i][j]);
            }
        }
    }
}

void freeArray(char *names[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(names[i][j]);
        }
    }
}

int main() {
    int rows, cols, vowelCount;
    char *names[MAX_ROWS][MAX_COLS];
    char longestName[MAX_NAME_LENGTH];

    rows = getInputInRange("Enter number of rows", 1, MAX_ROWS);
    cols = getInputInRange("Enter number of columns", 1, MAX_COLS);

    fillArray(names, rows, cols);
    processArray(names, rows, cols, &vowelCount, longestName);
    printArray(names, rows, cols);

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    freeArray(names, rows, cols);

    return 0;
}
