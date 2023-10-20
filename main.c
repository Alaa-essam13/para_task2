
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

union Access {
    int intAccess;   // 0 or 1
    bool boolAccess; // true or false
};

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    union Access access;
} User;

User users[MAX_USERS];
int userCount = 0;

void signup() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[userCount].username);

    printf("Enter password: ");
    scanf("%s", users[userCount].password);

    char accessValue;
    printf("Enter access (0 or 1): ");
    scanf("%d", &accessValue);
    if(&accessValue=='1'){
        users[userCount].access.intAccess = 1;
    }else if(&accessValue=='0'){
        users[userCount].access.intAccess = 0;
    }else if(&accessValue=='t'){
        users[userCount].access.boolAccess = true;
    }else if(&accessValue=='f'){
        users[userCount].access.boolAccess = false;
    }

    userCount++;

    printf("User signed up successfully.\n");
}
int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].access.intAccess == 1||users[i].access.boolAccess==true) {
                printf("Login successful.\n");
                return 1;
            } else {
                printf("Access denied. Please try again.\n");
                return 0;
            }
        }
    }

    printf("Invalid username or password. Please try again.\n");
    return 0;
}

int main() {
    int choice;

    while (1) {
        printf("1. Sign Up\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                break;

            case 2:
                if (login()) {
                    // Perform actions after successful login
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
