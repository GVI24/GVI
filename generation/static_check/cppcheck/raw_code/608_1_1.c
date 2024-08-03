#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    char* username;
    char* password;
    struct User* next;
} User;

User* addUser(User* head, const char* username, const char* password) {
    if (head == NULL) {
        head = (User*)malloc(sizeof(User));
        if (head == NULL) {
            return NULL;  // Memory allocation failed.
        }
        head->username = strdup(username);
        head->password = strdup(password);
        head->next = NULL;
    } else {
        User* current = head;
        while (current->next != NULL) {
            if (strcmp(current->username, username) == 0) {
                // Username already exists.
                return NULL;
            }
            current = current->next;
        }
        // Memory leak: No freeing of allocated memory if username already exists.
        User* newUser = (User*)malloc(sizeof(User));
        newUser->username = strdup(username);
        newUser->password = strdup(password);
        newUser->next = NULL;
        current->next = newUser;
    }
    return head;
}

void freeUsers(User* head) {
    User* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->username);
        free(tmp->password);
        free(tmp);
    }
}

int main() {
    User* users = NULL;
    users = addUser(users, "john_doe", "secure123");

    // Potential memory leak if addUser is called with an existing username.
    addUser(users, "john_doe", "newpassword");

    freeUsers(users);
    return 0;
}