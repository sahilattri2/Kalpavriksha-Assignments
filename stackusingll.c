#include <stdio.h>
#include <stdlib.h>
 
typedef struct node 
{
    int data;
    struct node* next;
} node;
 
node* createnode(int data) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}
 
void push(node** head, int data) 
{
    node* newnode = createnode(data);
    node* temp = *head;
    if (*head == NULL) 
    {
        *head = newnode;
    } 
    else 
    {
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
 
void pop(node** head) 
{
    node* temp = *head;
    node* previous = NULL;
    if (*head == NULL) 
    {
        printf("Stack is empty\n");
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
 
void print(node** head) 
{
    node* temp = *head;
    if (*head == NULL) 
    {
        printf("Stack is empty\n");
    } 
    else
    {
        while (temp != NULL) 
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
 
int isEmpty(node* head) 
{
    int flag=0;
    if(head == NULL)
    {
        flag=1;
    }
    return flag;
}
 
int peek(node* head) 
{
    if (head == NULL) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    while (head->next != NULL) 
    {
        head = head->next;
    }
    return head->data;
}
 
int size(node* head) 
{
    int count = 0;
    while (head != NULL) 
    {
        count++;
        head = head->next;
    }
    return count;
}
 
int main() 
{
    node* head = NULL;
    int choice, value;
 
    while (1) 
    {
        printf("\n1. Push\n2. Pop\n3. Print\n4. Peek\n5. Size\n6. IsEmpty\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
 
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                print(&head);
                break;
            case 4:
                printf("Top element: %d\n", peek(head));
                break;
            case 5:
                printf("Stack size: %d\n", size(head));
                break;
            case 6:
                int flag=isEmpty(head);
                if(flag==1)
                {
                    printf("stack is empty.");
                }
                else
                {
                    printf("stack is not empty");
                }
                
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}