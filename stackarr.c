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
void push(struct stack*ptr,int value)
{
    if(isFULL(ptr))
    {
        printf("Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
int pop(struct stack*ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr,int i)
{
    if(ptr->top-i<0)
    {
        printf("Invalid");
    }
    else{
        return ptr->arr[ptr->top-i];
    }
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size *sizeof(int));
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,1);
    printf("pop element:%d",pop(s));
    for(int i=0;i<=s->top;i++)
    {
    printf("peek element:%d",peek(s,i));
    }
}