#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
typedef struct Node{
    char ch;
    struct Node *next;
}Node;
 
typedef struct Stack{
    Node *top;
}Stack;
 
void init(Stack *st){
    st->top = NULL;
}
 
void push(Stack *st, char ch){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->ch = ch;
    if(st->top == NULL){
        st->top = newNode;
    }else{
        newNode->next = st->top;
        st->top = newNode;
    }
}
 
char pop(Stack *st){
    char ch = st->top->ch;
    st->top = st->top->next;
    return ch;
}
 
void printstack(Stack *st){
    Node *temp = st->top;
    while(temp != NULL){
        // printf("%c ->",temp->ch);
        printf("%c",temp->ch);
        temp = temp->next;
    }
    // printf("NULL\n");
}
Node *reversell(Node *head){
    Node *temp = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
 
char *decode(char str[]){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    Stack *temp = (Stack*)malloc(sizeof(Stack));
    init(st);
    init(temp);
    int i = 0;
    while(str[i]!= '\0'){
        while(str[i] != ']'){
            push(st,str[i]);
            i++;
        }
        char x = pop(st);
        while(x != '['){
            push(temp,x);
            x = pop(st);
        }
        // printf("i:%d\n",i);
        int a = pop(st)-'0';
        for(int k = 0; k < a; k++){
            Node *tp = temp->top;
            while(tp!= NULL){
                push(st,tp->ch);
                tp = tp->next;
            }
        }
        while(temp->top != NULL){
            pop(temp);
        }
 
        // printstack(st);
        // printstack(temp);
        i++;
    }
    st->top = reversell(st->top);
    printstack(st);
}
 
int main() {
   
    char str[] = "3[a2[bc]]";
    char *str2 = decode(str);
    printf("%s\n",str2);
   
 
    return 0;
}