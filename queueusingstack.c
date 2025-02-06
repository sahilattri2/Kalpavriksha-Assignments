#include <stdio.h>
 
#define MAX 100
 
typedef struct Stack 
{
    int arr[MAX];
    int top;
} Stack;
 
void initStack(Stack* s) 
{
    s->top = -1;
}
 
int isEmpty(Stack* s) 
{
    int flag=0;
    if(s->top==-1)
    {
        flag=1;
    }
    return flag;
}
 
int isFull(Stack* s) {
    int flag=0;
    if(s->top == MAX - 1)
    {
        flag=1;
    }
    return flag;
}
 
void push(Stack* s, int data) 
{
    if (isFull(s)) 
    {
        printf("Stack is full\n");
        return;
    }
    s->arr[++(s->top)] = data;
}
 
int pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}
 
int peek(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}
 
void enqueue(Stack* s1, Stack* s2, int data) 
{
    push(s1, data);
}
 
void dequeue(Stack* s1, Stack* s2) 
{
    if(s2->top==-1)
    {
        while (s1->top!=-1) 
        {
            int temp = pop(s1);
            push(s2, temp);
        }

    }
    
 
    int value = pop(s2);
    printf("Dequeued: %d\n", value);

    while (s2->top!=-1) 
        {
            int temp = pop(s2);
            push(s1, temp);
        }

}
 
void printQueue(Stack* s1, Stack* s2) 
{
    if (isEmpty(s1) && isEmpty(s2)) 
    {
        printf("Queue is empty\n");
        return;
    }

    while (!isEmpty(s1)) 
    {
        printf("%d ", peek(s1));
        pop(s1);
    }
 
    
    
}
 
int main() 
{
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
 
    int choice, value;
 
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
 
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&s1, &s2, value);
                break;
            case 2:
                dequeue(&s1, &s2);
                break;
            case 3:
                printQueue(&s1, &s2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}