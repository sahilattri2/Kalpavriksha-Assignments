#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[10];
    char time[10];
    struct node* next;
} node;

node* createnode(char name[10], char time[10]) {
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    strcpy(newnode->time, time);
    newnode->next = NULL;
    return newnode;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("(%s, %s) -> ", temp->name, temp->time);
        temp = temp->next;
    }
    printf("NULL\n");
}

int convertTimeToMinutes(const char* time) {
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);
    return hours * 60 + minutes;
}

node* parseInput(char* input) {
    node* head = NULL;
    node* tail = NULL;
    char* token = strtok(input, "->");
    while (token != NULL) {
        while (*token == ' ') {
            token++;
        }
        char flight[20];
        char time[20];
        if (sscanf(token, "(%[^,], %[^)])", flight, time) == 2) {
            node* newnode = createnode(flight, time);
            if (head == NULL) {
                head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
        }
        token = strtok(NULL, "->");
    }
    return head;
}

node* find(node* head) {
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    node* result = NULL;
    int leftTime = convertTimeToMinutes(left->time);
    int rightTime = convertTimeToMinutes(right->time);

    if (leftTime <= rightTime) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

node* mergesort(node* head) {
    if (head == NULL || head->next == NULL) return head;
    node* mid = find(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}

node* reverse(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

node* search(node* head, char* flight_name) {
    node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, flight_name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    char input[1000];
    int choice;
    char flight_to_search[10];
    node* head = NULL;

    scanf("%[^\n]s", input);
    head = parseInput(input);

    do {
        printf("\nMenu:\n");
        printf("1. Sort flights by departure time\n");
        printf("2. Search for a flight by name\n");
        printf("3. Reverse the flight schedule\n");
        printf("4. Display flight schedule\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = mergesort(head);
                printf("Flights sorted by departure time:\n");
                display(head);
                break;

            case 2:
                printf("Enter flight name to search: ");
                scanf("%s", flight_to_search);
                node* search_result = search(head, flight_to_search);
                if (search_result != NULL) {
                    printf("Flight found: (%s, %s)\n", search_result->name, search_result->time);
                } else {
                    printf("Flight not found\n");
                }
                break;

            case 3:
                head = reverse(head);
                printf("Reversed flight schedule:\n");
                display(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
