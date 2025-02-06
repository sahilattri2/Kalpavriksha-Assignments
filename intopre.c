#include <stdio.h>
#include <string.h>

int F(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '^':
            return 6;
        case ')':
            return 0;
        case '#':
            return -1;
        default:
            return 8;
    }
}
int G(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
            return 4;
        case '^':
            return 5;
        case '(':
            return 9;
        case ')':
            return 0;
        case '#':
            return -1;
        default:
            return 7;
    }
}

void reverse_string(char str[]) {
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infix_prefix(char infix[], char prefix[]) {
    int top = -1, j = 0, i;
    char symbol, s[40];
    s[++top] = '#';
    reverse_string(infix);
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        while(F(s[top]) > G(symbol)) {
            prefix[j] = s[top--];
            j++;
        }
        if(F(s[top]) != G(symbol))
            s[++top] = symbol;
        else
            top--;
    }
    while(s[top] != '#') {
        prefix[j++] = s[top--];
    }
    prefix[j] = '\0';
    reverse_string(prefix);
}

int main() {
    char infix[20];
    char prefix[20];
    printf("\nEnter a valid infix expression\n");
    scanf("%s", infix);
    infix_prefix(infix, prefix);
    printf("\nThe prefix expression is\n");
    printf("%s\n", prefix);
    return 0;
}
