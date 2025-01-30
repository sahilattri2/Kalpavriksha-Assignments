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
 
struct Node* findMiddle(struct Node* start, struct Node* end) {
    if (start == NULL) return NULL;
    struct Node* slow = start;
    struct Node* fast = start;
 
    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
 
int binarySearch(struct Node* head, int key) {
    if (head == NULL) return -1;
 
    struct Node* start = head;
    struct Node* end = NULL;
 
    do {
        struct Node* mid = findMiddle(start, end);
        if (mid == NULL)
            return -1;
        if (mid->data == key)
            return 1;
        if (mid->data > key) {
            end = mid;
        } else {
            start = mid->next;
        }
    } while (end != start);
 
    return -1;
}
 
void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}
 
int main() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, value, key;
 
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
 
    printf("Enter the elements of the sorted list:\n");
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
 
    printf("The Circular Linked List is: \n");
    printList(head);
 
    printf("Enter the key to search: ");
    scanf("%d", &key);
 
    int result = binarySearch(head, key);
    if (result != -1) {
        printf("Key found in the list.\n");
    } else {
        printf("Key not found.\n");
    }
 
    return 0;
}
has context menu
