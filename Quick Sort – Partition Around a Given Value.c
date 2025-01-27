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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* partition(struct Node* head, int x) {
    struct Node *lessHead = NULL, *lessTail = NULL;
    struct Node *greaterHead = NULL, *greaterTail = NULL;
    struct Node *equalHead = NULL, *equalTail = NULL;
    struct Node *current = head;

    while (current != NULL) {
        if (current->data < x) {
            if (lessHead == NULL) {
                lessHead = current;
                lessTail = lessHead;
            } else {
                lessTail->next = current;
                lessTail = lessTail->next;
            }
        } else if (current->data == x) {
            if (equalHead == NULL) {
                equalHead = current;
                equalTail = equalHead;
            } else {
                equalTail->next = current;
                equalTail = equalTail->next;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = current;
                greaterTail = greaterHead;
            } else {
                greaterTail->next = current;
                greaterTail = greaterTail->next;
            }
        }
        current = current->next;
    }

    if (lessTail != NULL) lessTail->next = equalHead;
    if (equalTail != NULL) equalTail->next = greaterHead;

    if (lessHead != NULL) {
        return lessHead;
    } else if (equalHead != NULL) {
        return equalHead;
    } else {
        return greaterHead;
    }
}

struct Node* quickSort(struct Node* head, int x) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct Node* partitionedHead = partition(head, x);
    return partitionedHead;
}

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, value, x;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (head == NULL) {
            head = newNode(value);
            temp = head;
        } else {
            temp->next = newNode(value);
            temp = temp->next;
        }
    }
    
    printf("Enter the partition value (x): ");
    scanf("%d", &x);

    head = quickSort(head, x);
    
    printf("Partitioned List:\n");
    printList(head);

    return 0;
}
