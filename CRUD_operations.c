//CRUD operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

// User structure
typedef struct {
    int id;
    char name[40];
    int age;
} User;

// Let's check whether the file exists or not
void checkFile() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Something's wrong.\n");
        exit(1);
    }
    fclose(file);
}

// Create a new user
void createUser() {
    User user;
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Couldn't open the file. Try again later.\n");
        return;
    }

    printf("Let's add a new user:\n");
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter name : ");
    scanf(" %[^\n]s", user.name);
    printf("Enter age (valid age please!): ");
    scanf("%d", &user.age);

    // Write user details to the file
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);

    printf("User added successfully.\n");
}

// Display all users
void displayUsers() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Let's add some!\n");
        return;
    }

    printf("\n--- User Records ---\n");
    User user;
    int count = 0;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        printf("ID: %d | Name: %s | Age: %d\n", user.id, user.name, user.age);
        count++;
    }

    if (count == 0) {
        printf("No users found. Let's add some new users.\n");
    }

    fclose(file);
}

// Update a user
void updateUser() {
    int id, found = 0;
    User user;
    printf("Enter the ID of the user you want to update: ");
    scanf("%d", &id);

    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Something's off.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("User found! Let's update their details.\n");
            printf("Enter new name: ");
            scanf(" %[^\n]s", user.name);
            printf("Enter new age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Details updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("No user with ID %d found.\n", id);
    }
}

// Delete a user
void deleteUser() {
    int id, found = 0;
    User user;
    printf("Enter the ID of the user you want to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Something's broken.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("Deleting user: %s (ID: %d)\n", user.name, user.id);
        } else {
            fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("The user is gone. Deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Couldn't find a user with ID %d to delete.\n", id);
    }
}

// Main function
int main() {
    checkFile();

    int choice;
    while (1) {
        printf("\n--- User Management System ---\n");
        printf("Okay so what we can do?\n");
        printf("1. Add a New User\n");
        printf("2. View All Users\n");
        printf("3. Update User Information\n");
        printf("4. Remove a User\n");
        printf("5. Exit the Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Bye.\n");
                exit(0);
            default:
                printf("try again.\n");
        }
    }

    return 0;
}
