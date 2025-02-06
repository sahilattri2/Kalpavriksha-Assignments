#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*createnode(int value)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    node*head=NULL;
    node*tail=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int value;
    scanf("%d",&value);
        node*newnode=createnode(value);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    display(head);
}