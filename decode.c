#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
void decodeString(const char* s) {
    int n = strlen(s);
    char* strStack = (char*)malloc(n);
    int numStack[100];
    int strTop = -1, numTop = -1;
    char currentStr[100];
    int currentNum = 0, currentLen = 0;
 
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            currentNum = currentNum * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            numStack[++numTop] = currentNum;
            currentNum = 0;
            strStack[++strTop] = '\0';
            currentLen = 0;
        } else if (s[i] == ']') {
            int repeatCount = numStack[numTop--];
            char temp[100] = "";
            for (int j = 0; j < repeatCount; j++) {
                strcat(temp, currentStr);
            }
            strcpy(currentStr, temp);
        } else {
            currentStr[currentLen++] = s[i];
            currentStr[currentLen] = '\0';
        }
    }
 
    printf("%s\n", currentStr);
    free(strStack);
}
 
int main() {
    char s[] = "3[a2[c]]";
    decodeString(s);
    return 0;
}