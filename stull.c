#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int marks;
    int roll_number;
    struct Student* next;
} Student;

Student* createStudent(char name[], int marks, int roll_number) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->roll_number = roll_number;
    newStudent->next = NULL;
    return newStudent;
}

Student* getMiddle(Student* head) {
    if (head == NULL) return NULL;
    Student* fast = head->next;
    Student* slow = head;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Student* merge(Student* left, Student* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Student* result = NULL;
    
    if (left->marks > right->marks) {
        result = left;
        result->next = merge(left->next, right);
    } else if (left->marks < right->marks) {
        result = right;
        result->next = merge(left, right->next);
    } else {
        if (left->roll_number < right->roll_number) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
    }
    return result;
}

Student* mergeSort(Student* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Student* mid = getMiddle(head);
    Student* left = head;
    Student* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void traverse(Student* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    Student* temp = head;
    while (temp != NULL) {
        printf("%s %d %d\n", temp->name, temp->marks, temp->roll_number);
        temp = temp->next;
    }
}

int main() {
    int n;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    Student* students = NULL;
    Student* tail = NULL;

    printf("Enter student data (name, marks, roll_number):\n");
    for (int i = 0; i < n; i++) {
        char name[50];
        int marks, roll_number;
        scanf("%s %d %d", name, &marks, &roll_number);
        
        Student* newStudent = createStudent(name, marks, roll_number);
        if (students == NULL) {
            students = newStudent;
            tail = students;
        } else {
            tail->next = newStudent;
            tail = tail->next;
        }
    }

    students = mergeSort(students);

    printf("\nSorted list of students:\n");
    traverse(students);

    return 0;
}
