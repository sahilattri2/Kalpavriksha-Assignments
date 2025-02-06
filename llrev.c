#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* reverse(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("Original List:\n");
    traverse(head);

    head = reverse(head);
    
    printf("Reversed List:\n");
    traverse(head);
    
    return 0;
}
