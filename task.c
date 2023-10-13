#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char username[20];
    char password[20];
    int isActive;
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    
    User newUser;
    
    printf("Enter username: ");
    scanf("%s", newUser.username);
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }
    
    printf("Enter password: ");
    scanf("%s", newUser.password);
    
    newUser.isActive = 1;
    
    users[numUsers++] = newUser;
    
    printf("Registration successful.\n");
}

void loginUser() {
    char username[20];
    char password[20];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].isActive) {
                printf("Login successful.\n");
            } else {
                printf("This user is currently inactive.\n");
            }
            
            return;
        }
    }
    
    printf("Invalid username or password.\n");
}

int main() {
    int choice;
    
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}