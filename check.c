#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
}node;

node*createnode(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
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
node* mid(node* head, int k)
{
    if (head == NULL || k == 1)
    {
        while (head != NULL)
        {
            struct node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }
    
    node* current = head;
    node* prev = NULL;
    int count = 1;
    
    while (current != NULL)
    {
        if (count == k) {
            prev->next = current->next;
            free(current);
            current = prev->next;
            count = 1;
        }
        else {
            prev = current;
            current = current->next;
            count++;
        }
    }
    
    return head;
}
int main()
{
    node*head=NULL;
    node*tail=NULL;
    int n;
    scanf("%d",&n);
    int value;
    while(scanf("%d",&value)==1)
    {
        if (getchar() == '\n') break;
        node*newnode=createnode(value);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        tail->next=newnode;
        tail=newnode;
        

    }
    int k;
    scanf("%d",&k);
    head=mid(head,k);
    display(head);
}