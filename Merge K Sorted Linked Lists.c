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

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    struct Node* dummy = newNode(0);
    struct Node* current = dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }
    
    struct Node* merged = dummy->next;
    free(dummy);
    return merged;
}

struct Node* mergeKLists(struct Node* lists[], int k) {
    if (k == 0) return NULL;
    
    while (k > 1) {
        int i = 0, j = k - 1;
        while (i < j) {
            lists[i] = mergeTwoLists(lists[i], lists[j]);
            i++;
            j--;
        }
        k = (k + 1) / 2;
    }
    
    return lists[0];
}

void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    struct Node *mid = *head, *fast = (*head)->next;
    while (fast != NULL && fast->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }
    
    struct Node* left = *head;
    struct Node* right = mid->next;
    mid->next = NULL;
    
    sortList(&left);
    sortList(&right);
    
    *head = mergeTwoLists(left, right);
}

int main() {
    int k, n, value;
    
    printf("Enter the number of linked lists: ");
    scanf("%d", &k);
    
    struct Node* lists[k];
    
    for (int i = 0; i < k; i++) {
        lists[i] = NULL;
        struct Node* temp = NULL;
        
        printf("Enter the number of elements in list %d: ", i + 1);
        scanf("%d", &n);
        
        printf("Enter the elements of list %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &value);
            if (lists[i] == NULL) {
                lists[i] = newNode(value);
                temp = lists[i];
            } else {
                temp->next = newNode(value);
                temp = temp->next;
            }
        }
    }
    
    struct Node* mergedList = mergeKLists(lists, k);
    
    printf("Merged List:\n");
    printList(mergedList);
    
    printf("Sorted Merged List:\n");
    sortList(&mergedList);
    printList(mergedList);
    
    return 0;
}
