/*Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.
 
Example:
Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
Output: "/usr/bin/"*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack {
    char *arr;
    int top;
    int size;
};

void push(struct stack *s, char val) {
    s->top++;
    s->arr[s->top] = val;
}
char pop(struct stack *s) {
    if (s->top == -1) 
    return '\0';
    char val = s->arr[s->top];
    s->top--;
    return val;
}

int  main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->arr = (char*)malloc(sizeof(char) * 100);
    s->top = -1;
    s->size = 100;

    char *input[] = {"cd usr/", "cd local/", "cd ../", "cd bin/"};
    int n = 4;
     for (int i = 0; i < n; i++) {
        char *c = input[i];
        char temp[30];
        int j = 3;
        int k = 0;
    while (c[j] != '/' && c[j] != '\0') {
            temp[k++] = c[j++];
        }
        temp[k] = '\0';
        if(strcmp(temp,"..")==0)
        {
            pop(s);
        }
        else if(strcmp(temp,".")!=0)
        {
            for(int i=0;i<k;i++)
            {
                push(s,temp[i]);
            }
            push(s,'/');
        }
     }
    for (int i = 0; i <= s->top; i++) {
        printf("%c", s->arr[i]);
    }
}