#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 // Maximum length

// Function to calculate expressions 
float calculateExpression(char *expr) {
    float values[MAX_LEN]; 
    char operators[MAX_LEN]; 
    int valTop = -1; 
    int opTop = -1; 

    int i = 0;
    //Function to perform operations
    float applyOperation(float a, float b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') {
            if (b == 0) {
                printf("Division by zero is not allowed.\n");
                exit(1);
            }
            return a / b;
        }
        return 0;
    }

    // Function to follow precedence of operators
    int precedence(char op) {
        if (op == '+' || op == '-') return 1; // Lowest precedence
        if (op == '*' || op == '/') return 2; // Higher precedence
        return 0;
    }

    // Function Process the expression
    while (expr[i] != '\0') {
        char c = expr[i];

        // Skip spaces
        if (c == ' ') {
            i++;
            continue;
        }

        // If the character is a number, parse it
        if (isdigit(c) || c == '.') {
            float num = 0.0;
            float fractionDiv = 10.0;
            int isFraction = 0;

            while (isdigit(expr[i]) || expr[i] == '.') {
                if (expr[i] == '.') {
                    if (isFraction) {
                        printf("Multiple decimal points in a number.\n");
                        exit(1);
                    }
                    isFraction = 1;
                } else {
                    if (isFraction) {
                        num += (expr[i] - '0') / fractionDiv;
                        fractionDiv *= 10.0;
                    } else {
                        num = num * 10 + (expr[i] - '0');
                    }
                }
                i++;
            }
            values[++valTop] = num;
            continue;
        }

        // Check character is an operator
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Process operators with higher or equal precedence
            while (opTop >= 0 && precedence(operators[opTop]) >= precedence(c)) {
                float b = values[valTop--];
                float a = values[valTop--];
                char op = operators[opTop--];
                values[++valTop] = applyOperation(a, b, op);
            }

            // Push the current operator to the stack
            operators[++opTop] = c;
        }

        i++;
    }

    // Process the remaining operators in the stack
    while (opTop >= 0) {
        float b = values[valTop--];
        float a = values[valTop--];
        char op = operators[opTop--];
        values[++valTop] = applyOperation(a, b, op);
    }

    return values[valTop];
}

int main() {
    char expression[MAX_LEN];

    printf("Enter a mathematical expression: ");
    fgets(expression, MAX_LEN, stdin);

    expression[strcspn(expression, "\n")] = '\0';

    // Validate the input 
    for (int i = 0; expression[i] != '\0'; i++) {
        if (!isdigit(expression[i]) && expression[i] != '+' &&
            expression[i] != '-' && expression[i] != '*' &&
            expression[i] != '/' && expression[i] != '.' && 
            expression[i] != ' ') {
            printf("Error: Invalid character '%c' in expression.\n", expression[i]);
            return 1;
        }
    }

    // Calculate the expression and display the result
    float result = calculateExpression(expression);
    printf("The result is: %.2f\n", result);

    return 0;
}
