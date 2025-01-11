#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int calculateLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int editDistance(char str1[], char str2[]) {
    int m = calculateLength(str1);
    int n = calculateLength(str2);

    int **distance = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        distance[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else {
                if (str1[i - 1] == str2[j - 1]) {
                    distance[i][j] = distance[i - 1][j - 1];
                } else {
                    distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
                }
            }
        }
    }

    int result = distance[m][n];

    for (int i = 0; i <= m; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    printf("The edit distance is: %d\n", editDistance(str1, str2));
    
    return 0;
}
