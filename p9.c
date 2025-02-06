#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, const char* str) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = (char*)malloc(strlen(str) + 1);
    strcpy(newNode->data, str);
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

char* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL; // Queue is empty
    }
    struct Node* temp = q->front;
    char* result = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // If the queue is empty, set rear to NULL
    }
    free(temp);
    return result;
}

void generateBinaryNumbers(int N) {
    struct Queue* q = createQueue();
    enqueue(q, "1"); // Start with the first binary number "1"

    for (int i = 1; i <= N; i++) {
        char* current = dequeue(q);
        printf("%s ", current);

        // Append '0' and '1' to the current binary string and enqueue them
        char* zero = (char*)malloc(strlen(current) + 2); // One more for '0' and the null terminator
        strcpy(zero, current);
        strcat(zero, "0");
        enqueue(q, zero);

        char* one = (char*)malloc(strlen(current) + 2);
        strcpy(one, current);
        strcat(one, "1");
        enqueue(q, one);

        free(current); // Free memory for the current string after processing
    }
}

int main() {
    int N;
    scanf("%d", &N);

    generateBinaryNumbers(N);

    return 0;
}
