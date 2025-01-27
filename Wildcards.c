#include <stdio.h>

int check[100][100];

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void initializeCheck(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = -1;
        }
    }
}

int checkWildcard(char *s1, char *s2, int i, int j) {
    if (check[i][j] != -1) {
        return check[i][j];
    }
    if (i == stringLength(s1) && j == stringLength(s2)) {
        return check[i][j] = 1;
    }
    if (i == stringLength(s1)) {
        return check[i][j] = 0;
    }
    if (j == stringLength(s2)) {
        return check[i][j] = (s1[i] == '*' && checkWildcard(s1, s2, i + 1, j));
    }
    if (s1[i] == s2[j] || s1[i] == '?') {
        return check[i][j] = checkWildcard(s1, s2, i + 1, j + 1);
    }
    if (s1[i] == '*') {
        return check[i][j] = checkWildcard(s1, s2, i + 1, j) || checkWildcard(s1, s2, i, j + 1);
    }
    return check[i][j] = 0;
}

int checkWildcardMatch(char *s1, char *s2) {
    initializeCheck(100, 100);
    return checkWildcard(s1, s2, 0, 0);
}

int main() {
    char s1[100], s2[100];
    
    printf("Enter the first string (with wildcards): ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    
    if (checkWildcardMatch(s1, s2)) {
        printf("The strings match.\n");
    } else {
        printf("The strings do not match.\n");
    }
    
    return 0;
}
