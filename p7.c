#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;       // Data to store the character
    struct Node* next; // Pointer to the next node in the stack
};

struct Stack {
    struct Node* top; // Points to the top node of the stack
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push a character onto the stack
void push(struct Stack* stack, char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = stack->top;  // Link the new node to the previous top
    stack->top = newNode;        // Update the top of the stack
}

// Pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';  // Return null character on underflow
    }
    char poppedData = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;  // Move the top to the next node
    free(temp);  // Free the memory of the popped node
    return poppedData;
}

// Function to reverse the string using the stack
void reverseString(char* str) {
    int n = strlen(str);
    struct Stack stack;
    initStack(&stack);

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        push(&stack, str[i]);
    }

    // Pop all characters from the stack and overwrite the original string
    for (int i = 0; i < n; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int size;
    char* arr;
};

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

void push(struct Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

void reverseString(char* str) {
    int n = strlen(str);
    struct Stack stack;
    stack.size = n;
    stack.top = -1;
    stack.arr = (char*)malloc(stack.size * sizeof(char));

    // Push all characters of the string to the stack
    for (int i = 0; i < n; i++) {
        push(&stack, str[i]);
    }

    // Pop all characters and replace them in the string to reverse it
    for (int i = 0; i < n; i++) {
        str[i] = pop(&stack);
    }

    free(stack.arr);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
