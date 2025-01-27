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

int binarySearch(struct Node* head, int key) {
    struct Node* start = head;
    struct Node* end = head;

    if (head == NULL) {
        return -1;
    }

    while (end->next != start) {
        end = end->next;
    }

    while (start != end) {
        struct Node* mid = start;
        while (mid != end && mid->next != end) {
            mid = mid->next;
        }

        if (mid->data == key) {
            return 1;
        } else if (mid->data > key) {
            end = mid;
        } else {
            start = mid->next;
        }
    }

    return -1;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) return;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, value, key;
    
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
    temp->next = head;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binarySearch(head, key);
    if (result != -1) {
        printf("Position: %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
