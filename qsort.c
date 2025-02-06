#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int getListLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;

    while (j != high) {
        if (j->data < pivot) {
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
            i = i->next;
        }
        j = j->next;
    }

    int temp = i->data;
    i->data = high->data;
    high->data = temp;

    return i;
}

void quickSort(Node* low, Node* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}

Node* getLast(Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

int main() {
    Node* head = createNode(3);
    head->next = createNode(1);
    head->next->next = createNode(4);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    Node* last = getLast(head);

    quickSort(head, last);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
