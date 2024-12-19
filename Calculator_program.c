#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 

// Function prototypes
int evaluateExpression(const char *expression);
int applyOperator(int leftOperand, int rightOperand, char operator);
int getOperatorPrecedence(char operator);
int isDigit(char character);
int isValidCharacter(char character);
void processOperator(int *values, int *valueTop, char *operators, int *operatorTop);

// Function to evaluate the expression
int evaluateExpression(const char *expression) {
    int values[MAX_LEN];      // Stack for values
    char operators[MAX_LEN];  // Stack for operators
    int valueTop = -1, operatorTop = -1; // Stack pointers
    int index = 0;

    while (expression[index] != '\0') {
        char currentChar = expression[index];

        // Skip spaces
        if (currentChar == ' ') {
            index++;
            continue;
        }

        // Process digits
        if (isDigit(currentChar)) {
            int number = 0;
            while (isDigit(expression[index])) {
                number = number * 10 + (expression[index] - '0');
                index++;
            }
            values[++valueTop] = number; // Push to values stack
            continue;
        }

        // Process operators
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            while (operatorTop >= 0 && getOperatorPrecedence(operators[operatorTop]) >= getOperatorPrecedence(currentChar)) {
                processOperator(values, &valueTop, operators, &operatorTop);
            }
            operators[++operatorTop] = currentChar; // Push current operator
        } else {
            printf("Error: Invalid expression.\n");
            return 0;
        }
        index++;
    }

    // Process remaining operators
    while (operatorTop >= 0) {
        processOperator(values, &valueTop, operators, &operatorTop);
    }

    return values[valueTop]; 
}

// function to process an operator
void processOperator(int *values, int *valueTop, char *operators, int *operatorTop) {
    if (*valueTop < 1) {
        printf("Error: Invalid expression.\n");
        return;
    }
    int rightOperand = values[(*valueTop)--];
    int leftOperand = values[(*valueTop)--];
    char operator = operators[(*operatorTop)--];
    values[++(*valueTop)] = applyOperator(leftOperand, rightOperand, operator);
}

// Function to apply an operator to two operands
int applyOperator(int leftOperand, int rightOperand, char operator) {
    if (operator == '/' && rightOperand == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    switch (operator) {
        case '+': return leftOperand + rightOperand;
        case '-': return leftOperand - rightOperand;
        case '*': return leftOperand * rightOperand;
        case '/': return leftOperand / rightOperand;
        default:
            printf("Error: Unknown operator.\n");
            return 0;
    }
}

// Function to determine operator precedence
int getOperatorPrecedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}

// Function to check if a character is a digit
int isDigit(char character) {
    return character >= '0' && character <= '9';
}

// Function to validate characters in the expression
int isValidCharacter(char character) {
    return isDigit(character) || character == '+' || character == '-' || character == '*' || character == '/' || character == ' ';
}

int main() {
    char inputExpression[MAX_LEN];

    while (1) {
        printf("Enter a mathematical expression (or type 'exit' to quit): ");
        scanf(" %[^\n]", inputExpression);

        // Check for exit condition
        if (strcmp(inputExpression, "exit") == 0) {
            printf("exit!\n");
            break;
        }

        // Validate input
        int isValid = 1;
        for (int i = 0; inputExpression[i] != '\0'; i++) {
            if (!isValidCharacter(inputExpression[i])) {
                printf("Error: Invalid expression.\n");
                isValid = 0;
                break;
            }
        }

        if (!isValid) continue;

        // Evaluate and display result
        int result = evaluateExpression(inputExpression);
        printf("The result is: %d\n", result);
    }

    return 0;
}
