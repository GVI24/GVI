#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
} UserInfo;

void addUser(UserInfo *users, int *userCount, const char *name, int id) {
    // Vulnerable: No bounds checking for userCount against MAX_USERS
    if (*userCount < MAX_USERS) {
        // Unsafe: No check for name length to fit into UserInfo.name
        sprintf(users[*userCount].name, "%s", name);
        users[*userCount].id = id;
        (*userCount)++;
    } else {
        printf("User array is full.\n");
    }
}

int main() {
    UserInfo users[MAX_USERS];
    int userCount = 0;
    // Long name can cause buffer overflow in users[userCount].name
    addUser(users, &userCount, "ExcessivelyLongUserNameThatShouldNotBeAllowed", 1);
    return 0;
}