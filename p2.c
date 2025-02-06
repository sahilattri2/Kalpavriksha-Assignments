// File System Path Navigation 

// Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.
 
// Example:
// Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
// Output: "/usr/bin/"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct stack{
    int size;
    int top;
    char** arr;
 };
 struct stack* createStack(int size)
 {
    struct stack* newStack=(struct stack*)malloc(sizeof(struct stack));
    newStack->size=size;
    newStack->top=-1;
    newStack->arr=(char**)malloc(size*sizeof(char*));
    return newStack;
 }
 int isFull(struct stack* stack)
 {
    return stack->top==stack->size-1;
 }
 int isEmpty(struct stack* stack)
 {
    return stack->top==-1;
 }
 void push(struct stack* stack,char str[])
 {
    if(isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->arr[stack->top]=(char*)malloc(100*sizeof(char));
    strcpy(stack->arr[stack->top],str);
 }
 char* pop(struct stack* stack)
 {
    if(isEmpty(stack))
    {
        return "0";
    }
    char* val=stack->arr[stack->top];
    stack->top--;
    return val;
 }
 void printstack(struct stack* stack)
 {
    for(int i=0;i<=stack->top;i++)
    {
        printf("%s",stack->arr[i]);
    }
 }
 int main()
 {
    struct stack* stack=createStack(200);
    // push(stack,"sahil");
    // push(stack,"attri");
    // push(stack,"ka");
    // push(stack,"bhosda");
    // char *val=pop(stack);
    char input_str[100]="[cd usr/, cd local/, cd ../, cd bin/]";
    push(stack,"/");
    char *token=strtok(input_str,"[],");
    while(token!=NULL)
    {
        while(*token==' ')
        {
            token++;
        }
        // printf("%s\n",token);
        char dir[100];
        if(sscanf(token,"cd %s",dir)==1)
        {
            if(strcmp(dir,"../")==0)
            {
                pop(stack);
            }
            else{
                push(stack,dir);
            }
        }
        token=strtok(NULL,"[],");
    }

    printstack(stack);
 }