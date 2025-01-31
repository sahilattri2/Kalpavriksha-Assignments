#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
 
typedef struct Queue 
{
    int arr[MAX];
    int front, rear;
} Queue;
 
void initQueue(Queue* q) 
{
    q->front = -1;
    q->rear = -1;
}
 
int isEmpty(Queue* q) 
{
    int flag=0;
    if(q->front==-1)
    {
        flag=1;
    }
    return flag;
}
 
int isFull(Queue* q) 
{
    int flag=0;
    if(q->rear == MAX - 1)
    {
        flag=1;
    }
    return flag ;
}
 
void enqueue(Queue* q, int data) 
{
    if (isFull(q)) 
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) 
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}
 
void dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
        return;
    }
    if (q->front == q->rear) 
    {
        q->front = -1;
        q->rear = -1;
    } 
    else 
    {
        q->front++;
    }
}
 
int front(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}
 
int size(Queue* q) 
{
    if (isEmpty(q)) 
    {
        return 0;
    }
    return (q->rear - q->front + 1);
}
 
void print(Queue* q) 
{
    int i;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for ( i = q->front; i <= q->rear; i++) 
    {
        printf("%d\n", q->arr[i]);
    }
}
 
int main() 
{
    Queue q;
    initQueue(&q);
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
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                print(&q);
                break;
            case 4:
                printf("Front element: %d\n", front(&q));
                break;
            case 5:
                printf("Queue size: %d\n", size(&q));
                break;
            case 6:
                int flag=isEmpty(&q);
                if(flag==1)
                {
                    printf("stack is empty.");
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