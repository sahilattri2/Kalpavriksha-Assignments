#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertSorted(struct Node** head, int data) {
    struct Node* new_node = newNode(data);
    struct Node* current = *head;
    
    if (*head == NULL || (*head)->data >= data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertSorted(&head, value);
    }
    
    printf("Original sorted list:\n");
    printList(head);
    
    int m;
    printf("Enter the number of new elements to insert: ");
    scanf("%d", &m);
    
    printf("Enter the new elements to insert:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertSorted(&head, value);
    }
    
    printf("Updated list after insertion:\n");
    printList(head);
    
    return 0;
}
