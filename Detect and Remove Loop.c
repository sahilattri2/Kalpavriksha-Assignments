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

int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void removeCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast) {
        return;
    }
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
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
    struct Node* temp;
    int n, value, cyclePos;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("List cannot be empty.\n");
        return 0;
    }

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

    printf("Enter the position to create a cycle : ");
    scanf("%d", &cyclePos);
    
    if (cyclePos > 0) {
        struct Node* cycleNode = head;
        for (int i = 1; i < cyclePos; i++) {
            cycleNode = cycleNode->next;
        }
        temp->next = cycleNode;
        printf("Cycle created at node %d.\n", cyclePos);
    }

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
        removeCycle(head);
        printf("Cycle removed.\n");
    } else {
        printf("No cycle detected.\n");
    }

    printf("Updated List after cycle removal:\n");
    printList(head);

    return 0;
}
