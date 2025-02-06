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
node*findmiddle(node*head)
{
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node* left, node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
   
    node* result = NULL;
   
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
   
    return result;
}
node* mergesort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
   
    node* middle = findmiddle(head);
    node* leftHalf = head;
    node* rightHalf = middle->next;
   
    middle->next = NULL;
   
    leftHalf = mergesort(leftHalf);
    rightHalf = mergesort(rightHalf);
   
    return merge(leftHalf, rightHalf);
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
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
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
    display(head);
    head=mid(head,k);
    display(head);
}