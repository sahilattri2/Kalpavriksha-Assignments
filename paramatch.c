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
int match(char a,char b)
{
    if(a=='{'& b=='}')
    return 1;
    if(a=='['& b==']')
    return 1;
    if(a=='('& b==')')
    return 1;

    return 0;
}
int valid(char * exp)
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=80;
    s->top=-1;
    char ch;
    s->arr=(char*)malloc(s->size *sizeof(char));
    for(int i=0;exp[i]!='\0';i++)
{
    if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
    {
        push(s, exp[i]);
    }
    else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
    {
        if(isEmpty(s))
        {
            return 0;
        }
        ch=pop(s);
        if(!match(ch,exp[i]))
        {
            return 0;
        }
    }
}
int result = isEmpty(s);
return result;
}
int main()
{
    char *exp;
    scanf("%s",exp);
    if(valid(exp))
    printf("Balanced");
    else
    printf("Unbalanced");
    return 0;
}