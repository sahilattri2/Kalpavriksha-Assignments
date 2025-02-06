#include <stdio.h>
#include <stdlib.h>
 
typedef struct Queue 
{
    int data;
    struct Queue* next;
} Queue;
 
Queue* front = NULL;
Queue* rear = NULL;
 
int isEmpty() 
{
    int flag=0;
    if(front == NULL)
    {
        flag=1;
    }
    return flag;
}
 
Queue* createNode(int data) 
{
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
void enqueue(int data) 
{
    Queue* newNode = createNode(data);
    if (isEmpty()) 
    {
        front = rear = newNode;
    } 
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}
 
void dequeue() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return;
    }
    Queue* temp = front;
    front = front->next;
    free(temp);
    if (front == NULL) 
    {
        rear = NULL;
    }
}
 
int frontElement() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}
 
int size() 
{
    int count = 0;
    Queue* temp = front;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}
 
void print() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return;
    }
    Queue* temp = front;
    while (temp != NULL) 
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
 
int main() 
{
    int choice, value;
 
    while (1) 
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print\n4. Front\n5. Size\n6. IsEmpty\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
 
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
                printf("Front element: %d\n", frontElement());
                break;
            case 5:
                printf("Queue size: %d\n", size());
                break;
            case 6:
                int flag=isEmpty();
                if(flag==1)
                {
                    printf("queue is empty.");
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