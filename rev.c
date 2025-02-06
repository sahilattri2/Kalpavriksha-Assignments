#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseLinkedList(struct Node* head)
{
    if(head==NULL|| head->next==NULL)
        return head;
    struct Node* rev=reverseLinkedList(head->next);
        head->next->next=head;
    head->next=NULL;
    return rev;
}

void printLinkedList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int value;

    while (scanf("%d", &value) == 1)
    {
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseLinkedList(head);

    printLinkedList(head);

    return 0;
}
