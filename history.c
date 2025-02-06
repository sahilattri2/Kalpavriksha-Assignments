#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, const char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("No websites in history to remove.\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Removed Website: %s\n", stack->top->url);
    stack->top = stack->top->next;
    free(temp);
}

void viewHistory(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("No websites in history.\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("History (most recent first):\n");
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}

void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("No websites in history.\n");
        return;
    }
    printf("Most recently visited website: %s\n", stack->top->url);
}

void updateUrl(struct Stack* stack, const char* oldUrl, const char* newUrl) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        if (strcmp(temp->url, oldUrl) == 0) {
            strcpy(temp->url, newUrl);
            printf("Updated website: %s to %s\n", oldUrl, newUrl);
            return;
        }
        temp = temp->next;
    }
    printf("Website %s not found in history.\n", oldUrl);
}

void clearHistory(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    printf("Browser history cleared.\n");
}

int main() {
    struct Stack history;
    initializeStack(&history);

    int choice;
    char url[100], oldUrl[100], newUrl[100];

    while (1) {
        printf("\nBrowser History Management System\n");
        printf("1. Add Website (Push)\n");
        printf("2. View History (Read)\n");
        printf("3. Edit URL (Update)\n");
        printf("4. Remove Recent Website (Pop)\n");
        printf("5. Clear History\n");
        printf("6. Peek Most Recent Website\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL to add to history: ");
                scanf(" %[^\n]s", url);
                push(&history, url);
                break;
            case 2:
                viewHistory(&history);
                break;
            case 3:
                printf("Enter the URL to update: ");
                scanf(" %[^\n]s", oldUrl);
                printf("Enter the new URL: ");
                scanf(" %[^\n]s", newUrl);
                updateUrl(&history, oldUrl, newUrl);
                break;
            case 4:
                pop(&history);
                break;
            case 5:
                clearHistory(&history);
                break;
            case 6:
                peek(&history);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
