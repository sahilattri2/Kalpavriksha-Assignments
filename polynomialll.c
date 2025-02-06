#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int c;
    int p;
    struct Node* next;
} Node; 
Node* createNode(int c, int p) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    newNode->p = p;
    newNode->next = NULL;
    return newNode;
} 
void insert(Node** head, int c, int p) {
    Node* newNode = createNode(c, p);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
} 
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;
    Node* temp = NULL;
 
    while (p1 || p2) {
        int c, p;
        if (p1 && (!p2 || p1->p > p2->p)) {
            c = p1->c;
            p = p1->p;
            p1 = p1->next;
        } else if (p2 && (!p1 || p2->p > p1->p)) {
            c = p2->c;
            p = p2->p;
            p2 = p2->next;
        } else {
            c = p1->c + p2->c;
            p = p1->p;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (c != 0) {
            if (result == NULL) {
                result = createNode(c, p);
                temp = result;
            } else {
                temp->next = createNode(c, p);
                temp = temp->next;
            }
        }
    }
    return result;
}
void printPolynomial(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    while (head) {
        printf("%dX^%d", head->c, head->p);
        if (head->next) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}
 
int main() {
    Node *p1 = NULL, *p2 = NULL;
 
    insert(&p1, 2, 2);
    insert(&p1, 3, 1);
    insert(&p1, 4, 0);
 
    insert(&p2, 1, 3);
    insert(&p2, 2, 1);
    insert(&p2, 1, 0);

    printf("Polynomial 1: ");
    printPolynomial(p1);
    printf("Polynomial 2: ");
    printPolynomial(p2);
    Node* result = addPolynomials(p1, p2);
    printf("Sum of Polynomials: ");
    printPolynomial(result); 
    return 0;
}