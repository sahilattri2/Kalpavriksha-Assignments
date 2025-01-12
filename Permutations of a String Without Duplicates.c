#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }

    for (int i = l; i <= r; i++) {
        int skip = 0;
        for (int j = l; j < i; j++) {
            if (str[i] == str[j]) {
                skip = 1;
                break;
            }
        }
        if (skip) continue;

        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]);
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }

    permute(str, 0, n - 1);

    return 0;
}
