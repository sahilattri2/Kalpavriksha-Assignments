#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void breakCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

void bubbleSort(struct Node* head) {
    if (head == NULL) return;

    struct Node *i, *j;
    int swapped;
    do {
        swapped = 0;
        i = head;
        while (i != NULL && i->next != NULL) {
            j = i->next;
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
                swapped = 1;
            }
            i = i->next;
        }
    } while (swapped);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createCycle(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* cycleNode = NULL;
    int counter = 1;
    
    while (temp->next != NULL) {
        if (counter == position) {
            cycleNode = temp;
        }
        temp = temp->next;
        counter++;
    }

    if (cycleNode != NULL) {
        temp->next = cycleNode;  
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, value, cyclePosition;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("List cannot be empty.\n");
        return 0;
    }

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (head == NULL) {
            head = newNode(value);
            temp = head;
        } else {
            temp->next = newNode(value);
            temp = temp->next;
        }
    }

    printf("Enter the position to create a cycle: ");
    scanf("%d", &cyclePosition);
    if (cyclePosition > 0) {
        createCycle(head, cyclePosition);
        printf("Cycle created at node %d.\n", cyclePosition);
    }

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
        breakCycle(head);
        printf("Cycle broken.\n");
    } else {
        printf("No cycle detected.\n");
    }

    printf("Original List:\n");
    printList(head);
    bubbleSort(head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
