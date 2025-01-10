#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "users.txt"
#define MAX_USERS 100

typedef struct {
    int id;
    char name[50];
    int age;
} User;

void ensureFileExists() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error: Unable to create or access the file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

int readUserData(FILE *file, User *user) {
    return fscanf(file, "%d,%49[^,],%d\n", &user->id, user->name, &user->age);
}

int getIntInput(const char *prompt) {
    int value;
    char buffer[20];

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            }
        }
        printf("Error: Invalid input. Please enter a valid integer.\n");
    }
}

int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int isUserIdUnique(User *users, int userCount, int userId) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == userId) {
            return 0;  
        }
    }
    return 1;  
}


void writeUsersToFile(User *users, int userCount) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d,%s,%d\n", users[i].id, users[i].name, users[i].age);
    }
    fclose(file);
}


void displayAllUsers(User *users, int userCount) {
    if (userCount == 0) {
        printf("No users found.\n");
        return;
    }

    printf("\n--- All User Records ---\n");
    for (int i = 0; i < userCount; i++) {
        printf("ID: %d | Name: %s | Age: %d\n", users[i].id, users[i].name, users[i].age);
    }
}

void addUser(User *users, int *userCount) {
    User newUser;
    printf("\nAdd New User:\n");
    newUser.id = getIntInput("Enter User ID: ");

    if (!isUserIdUnique(users, *userCount, newUser.id)) {
        printf("Error: A user with ID %d already exists.\n", newUser.id);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", newUser.name);
    getchar();  

    if (!isValidName(newUser.name)) {
        printf("Error: Name must only contain alphabets and spaces.\n");
        return;
    }

    newUser.age = getIntInput("Enter Age: ");

    if (newUser.age <= 0) {
        printf("Error: Age must be a positive value.\n");
        return;
    }

    users[*userCount] = newUser;
    (*userCount)++;

    writeUsersToFile(users, *userCount);
    printf("User added successfully.\n");
}

void updateUserDetails(User *users, int userCount) {
    int targetId;
    int found = 0;

    printf("\nUpdate User:\n");
    targetId = getIntInput("Enter User ID to Update: ");

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == targetId) {
            found = 1;
            printf("Enter New Name: ");
            scanf(" %[^\n]s", users[i].name);
            getchar();  // Clear the buffer

            users[i].age = getIntInput("Enter New Age: ");
            if (users[i].age <= 0) {
                printf("Error: Age must be a positive value.\n");
                return;
            }
            break;
        }
    }

    if (!found) {
        printf("Error: No user with ID %d found.\n", targetId);
        return;
    }

    
    writeUsersToFile(users, userCount);
    printf("User details updated successfully.\n");
}


void deleteUserById(User *users, int *userCount) {
    int targetId;
    int found = 0;

    printf("\nDelete User:\n");
    targetId = getIntInput("Enter User ID to Delete: ");

    
    for (int i = 0; i < *userCount; i++) {
        if (users[i].id == targetId) {
            found = 1;
            printf("Deleting user: %s (ID: %d)\n", users[i].name, users[i].id);

            for (int j = i; j < *userCount - 1; j++) {
                users[j] = users[j + 1];
            }

            (*userCount)--;  
            break;
        }
    }

    if (!found) {
        printf("Error: No user with ID %d found.\n", targetId);
        return;
    }

    
    writeUsersToFile(users, *userCount);
    printf("User deleted successfully.\n");
}

int main() {
    ensureFileExists();

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file for reading.\n");
        exit(EXIT_FAILURE);
    }

    User users[MAX_USERS];
    int userCount = 0;

    while (readUserData(file, &users[userCount]) != EOF && userCount < MAX_USERS) {
        userCount++;
    }

    fclose(file);

    int userChoice;
    while (1) {
        printf("\n--- User Management System ---\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        userChoice = getIntInput("");

        switch (userChoice) {
            case 1:
                addUser(users, &userCount);
                break;
            case 2:
                displayAllUsers(users, userCount);
                break;
            case 3:
                updateUserDetails(users, userCount);
                break;
            case 4:
                deleteUserById(users, &userCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
