#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}node;
node*createnode(int data)
{
    node*newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed");
         }
         else{
            newnode->data=data;
            newnode->next=NULL;
            return newnode;
         }
}
node*insertb(node*head,int data)
{
    node*newnode=createnode(data);
    newnode->next=head;
    head=newnode;
    return head;
}
node*inserte(node*head,int data)
{
    node*newnode=createnode(data);
    if(head==NULL)
    {
        head=newnode;
        return head;
    }

    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    return head;
}
node*insertat(node*head,int prev,int data)
{
    node*temp=head;
    while(temp!=NULL&& temp->data!=prev)
    {
        temp=temp->next;
    }
    if(temp==NULL){

    
    printf("node not found");
    return head;
    }
    node*newnode=createnode(data);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;

}
node*insertP(node*head,int data,int pos)
{
if (pos < 1) {
        printf("Invalid position.\n");
        return head;
    }
    
    if (pos == 1) {
        return insertb(head,data);
    }
    node*temp=head;
    for(int i=1;i<pos-1;i++)
    {
        if (temp == NULL) {
            printf("Position out of range.\n");
            return head;
        }
        temp=temp->next;
    }
    node*newnode=createnode(data);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
void display(node*head)
{
     if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
node*deleteb(node*head)
{
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
    node*temp=head;
    head=head-> next;
    free (temp);
    return head;
}
node*deletee(node*head)
{
    if (head == NULL) {
        printf("The list is already empty.\n");
        return head;
    }
     if (head->next == NULL) { 
        free(head);
        return NULL;
    }
    node*temp=head;
    while(temp->next!=NULL&&temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}
node* deleteNodeByValue(node* head, int value) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    // If the node to delete is the head node
    if (head->data == value) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
     node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", value);
        return head;
    }
    node*del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return head;
}
node* deleteAtPosition(node* head, int pos) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    if (pos == 1) {
        return deleteb(head);  // Delete the head node
    }

    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range.\n");
            return head;
        }
        temp = temp->next;
    }

    node* nodeToDelete = temp->next;
    if (nodeToDelete != NULL) {
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    return head;
}
int main() {
    node* head = NULL;

    // Insert at the beginning
    head = insertb(head, 5);
    head = insertb(head, 10);
    head = insertb(head, 15);
    head = insertb(head, 20);
    printf("List after inserting at the beginning:\n");
    display(head);

    // Insert at the end
    head = inserte(head, 25);
    head = inserte(head, 30);
    printf("List after inserting at the end:\n");
    display(head);

    // Delete from the beginning
    head = deleteb(head);
    printf("List after deleting from the beginning:\n");
    display(head);

    // Delete from the end
    head = deletee(head);
    printf("List after deleting from the end:\n");
    display(head);

    // Delete a node with a specific value (e.g., 15)
    head = deleteNodeByValue(head, 15);
    printf("List after deleting node with value 15:\n");
    display(head);

    // Delete a node at position 2
    head = deleteAtPosition(head, 2);
    printf("List after deleting node at position 2:\n");
    display(head);

    return 0;
}