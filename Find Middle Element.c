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

int findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    if (head == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, value;
    
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

    int middle = findMiddle(head);
    if (middle != -1) {
        printf("Middle element is %d\n", middle);
    }

    return 0;
}
