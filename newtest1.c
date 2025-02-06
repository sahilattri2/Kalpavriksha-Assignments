#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int marks;
    int rollno;
    struct Node* next;
};

struct Node* initialize(struct Node* head, char name[], int marks, int rollno) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->name, name);
    newnode->marks = marks;
    newnode->rollno = rollno;
    newnode->next = NULL;

    head->next = newnode;
    return newnode;
}

struct Node* sort(struct Node* head) {
    struct Node *current, *nextNode;
    int tempMarks;
    char tempName[50];
    int tempRollno;

    if (head == NULL) return head;

    for (current = head; current != NULL; current = current->next) {
        for (nextNode = current->next; nextNode != NULL; nextNode = nextNode->next) {
            if (current->marks < nextNode->marks || 
                (current->marks == nextNode->marks && current->rollno > nextNode->rollno)) {
                
                tempMarks = current->marks;
                strcpy(tempName, current->name);
                tempRollno = current->rollno;

                current->marks = nextNode->marks;
                strcpy(current->name, nextNode->name);
                current->rollno = nextNode->rollno;

                nextNode->marks = tempMarks;
                strcpy(nextNode->name, tempName);
                nextNode->rollno = tempRollno;
            }
        }
    }
    return head;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%s, %d, %d\n", head->name, head->marks, head->rollno);
        head = head->next;
    }
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    struct Node* temp = head;
    temp = initialize(temp, "Sahil", 50, 1);
    temp = initialize(temp, "shubh", 85, 2);
    temp = initialize(temp, "pandey", 90, 3);
    temp = initialize(temp, "yash", 85, 4);
    display(head);
    head = sort(head);
    display(head);

    return 0;
}
