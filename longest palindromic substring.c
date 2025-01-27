#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

void my_strncpy(char* dest, char* src, int n) {
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int expandAroundCenter(char* s, int left, int right) {
    while (left >= 0 && right < my_strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = my_strlen(s);
    if (n == 0) return "";

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);

        int len = (len1 > len2) ? len1 : len2;
        
        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2;
        }
    }

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    my_strncpy(result, s + start, maxLength);
    result[maxLength] = '\0';

    return result;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    char* result = longestPalindrome(s);
    printf("Longest palindromic substring: %s\n", result);

    free(result);
    return 0;
}
