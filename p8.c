#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(struct Node** stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *stack;
    *stack = newNode;
}

int pop(struct Node** stack) {
    if (*stack == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *stack;
    int value = (*stack)->data;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

int peek(struct Node* stack) {
    if (stack == NULL) {
        return -1;
    }
    return stack->data;
}

void sortStack() {
    struct Node* tempStack = NULL;

    while (!isEmpty()) {
        int current = pop(&top);
        
        while (tempStack != NULL && peek(tempStack) > current) {
            push(&tempStack, pop(&tempStack));
        }

        push(&tempStack, current);
    }

    top = tempStack;
}

void printStack() {
    while (!isEmpty()) {
        printf("%d ", pop(&top));
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    // Read the elements into the stack
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&top, val);
    }

    sortStack();

    printf("Sorted stack (smallest at top): ");
    printStack();

    return 0;
}
