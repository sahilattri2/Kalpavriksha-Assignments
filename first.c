#include <stdio.h>
#include <ctype.h>
#include <string.h>

int countP(int n) {
    if (n < 2) return 0;  // 0 and 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) 
            return 0;  // If divisible, not a prime
    }
    return 1;  // Prime number
}

int countv(char str[]) {
    int count = 0;
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; str[i] != '\0'; i++) {
        if (countP(i) && strchr(vowels, str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[] = "education";
    printf("Vowels at prime indices: %d\n", countv(str));
    return 0;
}
