#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 

int evaluateExpression(const char *expression);
int applyOperator(int leftOperand, int rightOperand, char operator);
int getOperatorPrecedence(char operator);
int isDigit(char character);
int isValidCharacter(char character);
void processOperator(int *values, int *valueTop, char *operators, int *operatorTop);


int evaluateExpression(const char *expression) {
    int values[MAX_LEN];      // Stack for values
    char operators[MAX_LEN];  // Stack for operators
    int valueTop = -1, operatorTop = -1; // Stack pointers
    int index = 0;

    while (expression[index] != '\0') {
        char currentChar = expression[index];

        if (currentChar == ' ') {
            index++;
            continue;
        }


        if (isDigit(currentChar)) {
            int number = 0;
            while (isDigit(expression[index])) {
                number = number * 10 + (expression[index] - '0');
                index++;
            }
            values[++valueTop] = number; // Push to values stack
            continue;
        }

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

   
    while (operatorTop >= 0) {
        processOperator(values, &valueTop, operators, &operatorTop);
    }

    return values[valueTop]; 
}

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


int getOperatorPrecedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}


int isDigit(char character) {
    return character >= '0' && character <= '9';
}

int isValidCharacter(char character) {
    return isDigit(character) || character == '+' || character == '-' || character == '*' || character == '/' || character == ' ';
}

int main() {
    char inputExpression[MAX_LEN];

    while (1) {
        printf("Enter a mathematical expression (or type 'exit' to quit): ");
        scanf(" %[^\n]", inputExpression);

        
        if (strcmp(inputExpression, "exit") == 0) {
            printf("exit!\n");
            break;
        }

        int isValid = 1;
        for (int i = 0; inputExpression[i] != '\0'; i++) {
            if (!isValidCharacter(inputExpression[i])) {
                printf("Error: Invalid expression.\n");
                isValid = 0;
                break;
            }
        }

        if (!isValid) continue;

        int result = evaluateExpression(inputExpression);
        printf("The result is: %d\n", result);
    }

    return 0;
}
