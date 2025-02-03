#include<stdio.h>
#include<stdlib.h>
#define stacksize 1000
void push(int stack[],int *top,int value)
{
    if(*top==-1)
    {
        *top=*top+1;
        stack[*top]=value;
    }
    else
    {
        *top=*top+1;
        stack[*top]=value;

    }
    
    
}

void pop(int stack[],int *top)
{
    if(*top==-1)
    {
        printf("stack underflow nothing is there to pop out from stack\n");
    }
    else
    {
        
        int poped_value=stack[*top];
        printf("Poped value:%d\n",poped_value);
        *top=*top-1;
    }
}
void peak(int stack[],int *top)
{
    if(*top==-1)
    {
        printf("Stack is empty\n");

    }
    else
    {
        printf("peak element is : %d\n",stack[*top]);
    }
}

void isEmpty(int *top)
{
    if(*top==-1)
    {
        printf("stack is empty.\n");
    }
    else
    {
        printf("stack is not empty.\n");
    }
}

void size(int *top)
{
    if(*top==-1)
    {
        printf("stack is empty.\n");
    }
    else
    {
        printf("number of elements in the stack are : %d\n",*top+1);
    }
}

void print_stack(int stack[],int *top)
{
    int stack_iterator;
    if(*top==-1)
    {
        printf("stack underflow nothing is there to print in the stack\n");
    }
    else
    {
        for(stack_iterator=0;stack_iterator<=*top;stack_iterator++)
        {
            printf("%d\t",stack[stack_iterator]);

        }
        printf("\n");

    }
}

int main()
{
    int stack[stacksize],top=-1,value;
    int *top_pointer=&top;
    int choice;

    while(1)
    {
        printf("Enter 1 for pushing the element.\n");
        printf("Enter 2 for poping the element.\n");
        printf("Enter 3 for getting peak element of stack.\n");
        printf("Enter 4 for getting stack size \n");
        printf("Enter 5 for chicking if the stack is empty.\n");
        printf("Enter 6 for printing the elements.\n");
        printf("Enter 7 for exiting.\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the value to be pushed: ");
                scanf("%d",&value);
                push(stack,top_pointer,value);
                printf("\n");
                break;
            case 2:
                pop(stack,top_pointer);
                printf("\n");
                break;
            case 3:
                peak(stack,top_pointer);
                printf("\n");
                break;
            case 4:
                size(top_pointer);
                printf("\n");
                break;
            case 5:
                isEmpty(top_pointer);
                printf("\n");
                break;
            case 6:
                print_stack(stack,top_pointer);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid entery..!\n");
                printf("\n");
                break;
        }
    }

    

}