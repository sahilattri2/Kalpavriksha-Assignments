#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int isEmpty(Node* top) {
    return (top == NULL);
}

int isFull() {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
        return 1;  
    free(p);  
    return 0; 
}

Node* push(Node* top, int x) {
    if (isFull()) {
        printf("Stack overflow\n");
    } else {
        Node* n = (Node*)malloc(sizeof(Node));
        n->data = x;
        n->next = top;
        top = n;
    }
    return top;
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1; 
    }
    Node* n = *top;
    *top = (*top)->next;
    int x = n->data;
    free(n);
    return x;
}

void display(Node* top) {
    while (top != NULL) {
        printf("%d->", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    Node* top = NULL;
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);

    int element = pop(&top);
    printf("Popped element: %d\n", element);

    display(top);
    return 0;
}
