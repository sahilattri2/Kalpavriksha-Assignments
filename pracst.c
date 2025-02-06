#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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
void push(struct stack*ptr,char value)
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
char pop(struct stack*ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow");
        return -1;
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    
    return 0;
}