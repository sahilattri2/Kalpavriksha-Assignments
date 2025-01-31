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
    q->rear=q->rear+1;
    q->arr[q->rear] = data;
}
 
int dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    int top = q->arr[q->front];
    if (q->front == q->rear) 
    {
        q->front = -1;
        q->rear = -1;
    } 
    else 
    {
        q->front++;
    }
    return top;
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
    for (i = q->front; i <= q->rear; i++) 
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
 
void pop(Queue* q1, Queue* q2) 
{
    if (isEmpty(q1)) 
    {
        printf("Stack is empty\n");
        return;
    }
    
    int value = dequeue(q1);
    printf("Popped: %d\n", value);
}
 
void push(Queue* q1, Queue* q2, int data) 
{
    while (!isEmpty(q1))
    {
        int temp = dequeue(q1);
        enqueue(q2, temp);
    }
    enqueue(q1, data);
   
    
    while (!isEmpty(q2))
    {
        int temp = dequeue(q2);
        enqueue(q1, temp);

    }
 
    
}
 
int main() 
{
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);
 
    int choice, value;
 
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Print\n4. Front\n5. Size\n6. IsEmpty\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
 
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&q1, &q2, value);
                break;
            case 2:
                pop(&q1, &q2);
                break;
            case 3:
                print(&q1);
                break;
            case 4:
                printf("Top element: %d\n", front(&q1));
                break;
            case 5:
                printf("Queue size: %d\n", size(&q1));
                break;
            case 6:
                printf(isEmpty(&q1) ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}