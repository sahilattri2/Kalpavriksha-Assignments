#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    double price;
    struct Product* next;
};

struct Product* createProduct(char* name, double price) {
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->next = NULL;
    return newProduct;
}

void swap(struct Product* a, struct Product* b) {
    char tempName[50];
    double tempPrice;

    strcpy(tempName, a->name);
    tempPrice = a->price;

    strcpy(a->name, b->name);
    a->price = b->price;

    strcpy(b->name, tempName);
    b->price = tempPrice;
}

void selectionSort(struct Product* head) {
    struct Product* current = head;
    struct Product* minNode;
    struct Product* nextNode;

    while (current != NULL) {
        minNode = current;
        nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->price < minNode->price) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current) {
            swap(current, minNode);
        }

        current = current->next;
    }
}

void printProducts(struct Product* head) {
    struct Product* current = head;
    while (current != NULL) {
        printf("Product: %s, Price: %.2f\n", current->name, current->price);
        current = current->next;
    }
    printf("\n");
}

void addProduct(struct Product** head) {
    char name[50];
    double price;
    
    printf("Enter product name: ");
    scanf(" %[^\n]s", name);
    printf("Enter product price: ");
    scanf("%lf", &price);
    
    struct Product* newProduct = createProduct(name, price);
    
    if (*head == NULL) {
        *head = newProduct;
    } else {
        struct Product* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newProduct;
    }
}

int main() {
    struct Product* head = NULL;
    int numProducts, i;

    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    for (i = 0; i < numProducts; i++) {
        addProduct(&head);
    }

    printf("\nBefore sorting:\n");
    printProducts(head);

    selectionSort(head);

    printf("\nAfter sorting:\n");
    printProducts(head);

    while (head != NULL) {
        struct Product* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
