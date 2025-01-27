#include <stdio.h>

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

int editDistance(char str1[], char str2[], int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    
    if (str1[m - 1] == str2[n - 1]) {
        return editDistance(str1, str2, m - 1, n - 1);
    }
    
    int insert = editDistance(str1, str2, m, n - 1);
    int delete = editDistance(str1, str2, m - 1, n);
    int substitute = editDistance(str1, str2, m - 1, n - 1);
    
    return 1 + min(insert, delete, substitute);
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    int m = calculateLength(str1);
    int n = calculateLength(str2);
    
    printf("The edit distance is: %d\n", editDistance(str1, str2, m, n));
    
    return 0;
}
