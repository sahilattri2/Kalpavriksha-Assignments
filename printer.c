#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Job {
    int jobID;
    char documentName[50];
    int pages;
    struct Job* next;
};

struct Queue {
    struct Job* front;
    struct Job* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int jobID, const char* documentName, int pages) {
    struct Job* newJob = (struct Job*)malloc(sizeof(struct Job));
    newJob->jobID = jobID;
    strcpy(newJob->documentName, documentName);
    newJob->pages = pages;
    newJob->next = NULL;
    
    if (isQueueEmpty(q)) {
        q->front = q->rear = newJob;
    } else {
        q->rear->next = newJob;
        q->rear = newJob;
    }
}

void dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("No print jobs to process.\n");
        return;
    }
    struct Job* temp = q->front;
    printf("Processing Job ID: %d, Document: %s, Pages: %d\n", temp->jobID, temp->documentName, temp->pages);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void viewJobs(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("No pending jobs.\n");
        return;
    }
    struct Job* temp = q->front;
    while (temp != NULL) {
        printf("Job ID: %d, Document: %s, Pages: %d\n", temp->jobID, temp->documentName, temp->pages);
        temp = temp->next;
    }
}

void editJob(struct Queue* q, int jobID, const char* newDocumentName, int newPages) {
    struct Job* temp = q->front;
    while (temp != NULL) {
        if (temp->jobID == jobID) {
            strcpy(temp->documentName, newDocumentName);
            temp->pages = newPages;
            printf("Job ID: %d has been updated to Document: %s, Pages: %d\n", jobID, newDocumentName, newPages);
            return;
        }
        temp = temp->next;
    }
    printf("Job ID: %d not found.\n", jobID);
}

void cancelJob(struct Queue* q, int jobID) {
    if (isQueueEmpty(q)) {
        printf("No jobs to cancel.\n");
        return;
    }
    struct Job* temp = q->front;
    struct Job* prev = NULL;

    if (temp != NULL && temp->jobID == jobID) {
        q->front = temp->next;
        free(temp);
        printf("Job ID: %d has been canceled.\n", jobID);
        return;
    }

    while (temp != NULL && temp->jobID != jobID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Job ID: %d not found.\n", jobID);
        return;
    }

    prev->next = temp->next;
    if (temp == q->rear) {
        q->rear = prev;
    }
    free(temp);
    printf("Job ID: %d has been canceled.\n", jobID);
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    
    int choice, jobID, pages;
    char documentName[50];
    
    while (1) {
        printf("\nPrinter Job Queue Management System\n");
        printf("1. Add a Print Job (Enqueue)\n");
        printf("2. View Pending Jobs\n");
        printf("3. Edit a Job (Update)\n");
        printf("4. Process a Job (Dequeue)\n");
        printf("5. Cancel a Job\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &jobID);
                printf("Enter Document Name: ");
                scanf(" %[^\n]s", documentName);
                printf("Enter Number of Pages: ");
                scanf("%d", &pages);
                enqueue(&q, jobID, documentName, pages);
                break;
            case 2:
                viewJobs(&q);
                break;
            case 3:
                printf("Enter Job ID to edit: ");
                scanf("%d", &jobID);
                printf("Enter new Document Name: ");
                scanf(" %[^\n]s", documentName);
                printf("Enter new Number of Pages: ");
                scanf("%d", &pages);
                editJob(&q, jobID, documentName, pages);
                break;
            case 4:
                dequeue(&q);
                break;
            case 5:
                printf("Enter Job ID to cancel: ");
                scanf("%d", &jobID);
                cancelJob(&q, jobID);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
