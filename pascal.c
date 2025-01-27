#include <stdio.h>
#include <stdlib.h>

void printPascal(int n) {
    int *row = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        row[0] = 1;

        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

        for (int j = 1; j <= i; j++) {
            row[j] = row[j - 1] * (i - j + 1) / j;
        }

        for (int j = 0; j <= i; j++) {
            printf("%d ", row[j]);
        }

        printf("\n");
    }

    free(row);
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);

    printPascal(n);

    return 0;
}
