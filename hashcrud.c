#include <stdio.h>
#include <stdlib.h>
 
#define TABLE_SIZE 10
 
typedef struct Node {
    int key, value;
    struct Node* next;
} Node;
 
Node* hashTable[TABLE_SIZE];
 
int hash(int key) {
    return key % TABLE_SIZE;
}
 
void insert(int key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
 
    if (!hashTable[index]) {
        hashTable[index] = newNode;
        return;
    }
 
    Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key) {
            temp->value = value;
            free(newNode);
            return;
        }
        if (!temp->next) break;
        temp = temp->next;
    }
    temp->next = newNode;
}
 
int search(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return -1;
}
 
void delete(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;
 
    while (temp) {
        if (temp->key == key) {
            if (prev) prev->next = temp->next;
            else hashTable[index] = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
 
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf(" (%d, %d) ->", temp->key, temp->value);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}
 
int main() {
    int choice, key, value;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(key);
                if (value != -1) printf("Value: %d\n", value);
                else printf("Key not found\n");
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
        }
    }
}