#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define TABLE_SIZE 26
 
typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;
 
Node* hashTable[TABLE_SIZE];
 
int hash(char* key) {
    int hashValue = 0;
    while (*key) hashValue += *key++;
    return hashValue % TABLE_SIZE;
}
 
void insert(char* key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;
 
    if (!hashTable[index]) {
        hashTable[index] = newNode;
        return;
    }
 
    Node* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            temp->value = value;
            free(newNode);
            return;
        }
        if (!temp->next) break;
        temp = temp->next;
    }
    temp->next = newNode;
}
 
int search(char* key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->key, key) == 0) return temp->value;
        temp = temp->next;
    }
    return -1;
}
 
void delete(char* key) {
    int index = hash(key);
    Node* temp = hashTable[index], *prev = NULL;
 
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
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
            printf(" (%s, %d) ->", temp->key, temp->value);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}
 
int main() {
    int choice, value;
    char key[50];
 
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%s %d", key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                value = search(key);
                if (value != -1) printf("Value: %d\n", value);
                else printf("Key not found\n");
                break;
            case 3:
                printf("Enter key: ");
                scanf("%s", key);
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