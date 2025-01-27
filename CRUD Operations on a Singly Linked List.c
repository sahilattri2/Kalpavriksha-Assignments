#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int value) {
    printf("Inserting %d at the beginning\n", value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    printf("Inserting %d at the end\n", value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int position, int value) {
    printf("Inserting %d at position %d\n", value, position);
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    printf("Displaying linked list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int newValue) {
    printf("Updating position %d to %d\n", position, newValue);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    temp->data = newValue;
}

void deleteAtBeginning() {
    printf("Deleting first element\n");
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    printf("Deleting last element\n");
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position) {
    printf("Deleting element at position %d\n", position);
    if (head == NULL || position < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node* temp = head;
    if (position == 1) {
        head = head->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    int n, operation, value, position;
    printf("Enter the number of operations: ");
    scanf("%d", &n);
    while (n--) {
        printf("Enter operation: ");
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                printf("Enter value to add at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter value to add at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &position, &value);
                insertAtPosition(position, value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter position and new value: ");
                scanf("%d %d", &position, &value);
                updateAtPosition(position, value);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            default:
                printf("Invalid operation\n");
        }
    }
    return 0;
}
