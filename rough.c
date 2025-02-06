#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack*ptr)
{
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

int isFULL(struct stack*ptr)
{
    if(ptr->top==ptr->size-1)
        return 1;
    else
        return 0;
}

void push(struct stack*ptr, int value)
{
    if(isFULL(ptr))  // Fixed here: pass ptr to isFULL
    {
        printf("Stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack*ptr)
{
    if(isEmpty(ptr))  // Fixed here: pass ptr to isEmpty
    {
        printf("Stack underflow\n");
        return -1;  // Return a value indicating error (e.g., -1)
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    if(ptr->top - i + 1 < 0)
    {
        printf("Invalid\n");
        return -1;  // Return a value indicating error
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 1);

    printf("Pop element: %d\n", pop(s));  // Pop one element and print

    printf("Peek elements: \n");
    for(int i = 0; i <= s->top; i++)  // Adjusted to print only valid peek elements
    {
        printf("peek element %d: %d\n", i + 1, peek(s, i));
    }

    return 0;
}
